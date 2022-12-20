[ `uname` = Linux ] && { export X=x86_64-w64-mingw32-; }
P=mingw64 C="-DPSAPI_VERSION=1 -fPIC" L="-s -static-libgcc -lpsapi -lmpr ../../bin/$P/luajit.a" \
    D=winapi.dll A=winapi.a ./build.sh
