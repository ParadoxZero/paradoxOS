#!/bin/bash
PROJECTS="kernel"

#####################
# Important Folders #
#####################
CONFIGDIR="config"
INCLUDE_DIR="/usr/include"
SYSROOT="$(pwd)/sysroot"

########################
# The Target Toolchain #
########################
if [ -z "$TARGET" ]
then
	TARGET="i686-elf"
fi

HOST_SUFFIX="-elf"
HOST=${TARGET%$HOST_SUFFIX}

echo "Building for target host is "$HOST"."

###############
# Tool Chains #
###############
OCC=$TARGET"-gcc --sysroot=$SYSROOT -isystem=$INCLUDE_DIR"
OAS=$TARGET"-as"
MAKE="make"

########################################
# Exporting Values neccessary to build
########################################
export SYSROOT
export OCC
export OAS
export HOST

function setup(){
	mkdir -p $SYSROOT
	cp -r $CONFIGDIR/* $SYSROOT/
}

function clean(){
	rm -rf sysroot
	for PROJECT in $PROJECTS; do
		(cd $PROJECT && make clean)
	done
}

function build(){
	setup
	for PROJECT in $PROJECTS; do
		(cd $PROJECT && $MAKE install)
	done
}

function iso(){
	clean
	setup
	build
	grub-mkrescue $SYSROOT -o paradoxOS.iso
}

case $1 in
build) 
	build
	;;
clean)
	clean
	;;
rebuild)
	clean
	build
	;;
iso)
	iso
	;;
*)
	echo "Please specify an Option"
	;;
esac

