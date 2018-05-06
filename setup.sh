#!/bin/bash

# 
# This file is part of the ParadoxOS (https://github.com/ParadoxZero/paradoxOS).
# Copyright (c) 2018 Sidhin S Thomas.
# 
# This program is free software: you can redistribute it and/or modify  
# it under the terms of the GNU General Public License as published by  
# the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License 
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#
set -o xtrace

PROJECTS="libc kernel"

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
	mkdir -p $SYSROOT/usr/include
	cp -r $CONFIGDIR/* $SYSROOT/
	cp -r kernel/include/* $SYSROOT/usr/include/
}

function clean(){
	rm -rf sysroot
	rm -rf paradoxOS.iso
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
	build
	iso
	;;
setup)
	setup
	;;
*)
	echo "Please specify an Option"
	;;
esac

