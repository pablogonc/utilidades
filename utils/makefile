all:
	-cd Debug && make all

install: all
	cp -u Debug/libutils.so /usr/lib
	cd src && cp --parents -u utils/connection/connection.h /usr/include 
	cd src && cp --parents -u utils/globals.h /usr/include 

uninstall:
	rm -f /usr/lib/libutils.so
	rm -rf /usr/include/utils

reinstall: uninstall install
	rm -f /usr/lib/libutils.so
	rm -rf /usr/include/utils