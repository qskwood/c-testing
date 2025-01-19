x86_64-elf-as -o src/tinyshell_as.o src/tinyshell.S
x86_64-elf-gcc -static -c -o src/tinyshell_c.o -I/System/Volumes/Data/Library/Developer/CommandLineTools/SDKs/MacOSX15.2.sdk/usr/include/ src/tinyshell.c
x86_64-elf-ld -o bin/tinyshell src/tinyshell_c.o src/tinyshell_as.o --entry main -z noexecstack
