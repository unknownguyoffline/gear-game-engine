#!/bin/bash

cd build
cmake ..
make -j8
cd project


if [ $1 == "gdb" ]; then
	gtk-launch code.desktop
else
	./app
fi

