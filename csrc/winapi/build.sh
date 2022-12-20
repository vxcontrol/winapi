[ "$CC" ] || CC=gcc
mkdir -p ../../bin/$P
${X}${CC} -c -O2 $C *.c -Wall -I. -I../lua-headers
${X}${CC} *.o -shared -o ../../bin/$P/$D $L
rm -f      ../../bin/$P/$A
${X}ar rcs ../../bin/$P/$A *.o
rm *.o
