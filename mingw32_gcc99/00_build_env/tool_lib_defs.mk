# Define the compiler and compilation flags
CC = C:\Software\mingw32\bin\gcc
CFLAGS = -m32 -I"C:\Software\OpenSSL-Win32\include"
LDFLAGS = -L"C:\Software\OpenSSL-Win32" -lssl-1_1 -lcrypto-1_1
