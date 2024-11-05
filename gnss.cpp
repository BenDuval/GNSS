#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <cstring>

int main() {
    int serial_port = open("/dev/serial0", O_RDWR | O_NOCTTY);

    if (serial_port < 0) {
        std::cerr << "Error opening serial port\n";
        return 1;
    }

    struct termios tty;
    tcgetattr(serial_port, &tty);

    tty.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    tty.c_iflag = IGNPAR;
    tcsetattr(serial_port, TCSANOW, &tty);

    char buf[256];
    int n = read(serial_port, buf, sizeof(buf) - 1);
    if (n > 0) {
        buf[n] = '\0';
        std::cout << buf << std::endl;
    }

    close(serial_port);
    return 0;
}
