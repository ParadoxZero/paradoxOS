set -o xtrace
echo "Installing required libraries"
apt-get -y install libgmp3-dev libmpfr-dev libisl-dev libcloog-isl-dev libmpc-dev texinfo

BINUTILS_URL="ftp://ftp.gnu.org/gnu/binutils/binutils-2.30.tar.gz"
GCC_URL="ftp://ftp.gnu.org/gnu/gcc/gcc-7.3.0/gcc-7.3.0.tar.gz"


SOURCE=$HOME/toolchaintest
mkdir -p $SOURCE

cd $SOURCE

wget $BINUTILS_URL 
wget $GCC_URL

tar -xvf binutils-2.30.tar.gz
tar -xvf gcc-7.3.0.tar.gz

export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

###########################
#	Binutils				
###########################
mkdir -p build/binutils
cd build/binutils
../../binutils-2.30/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install

######################
# GCC
######################

cd $SOURCE
mkdir -p build/gcc
cd build/gcc
../../gcc-7.3.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc


