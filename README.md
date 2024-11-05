# GNSS

How to Compile and Run the GNSS Code  
Requirements  

Raspberry Pi with UART enabled  
GNSS Module connected to the Pi
C++ Compiler (g++)  

Compiling the Code  

To compile the code, navigate to the directory containing gnss.cpp and run:  
```bash  
g++ -o gnss gnss.cpp  
```

This will create an executable file named 
```bash  
gnss  
```

Running the Code  

Run the executable with sudo to ensure it has permissions to access the serial port:  
```bash  
sudo ./gnss  
```

