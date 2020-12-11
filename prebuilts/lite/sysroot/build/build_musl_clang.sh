#!/bin/bash
# This script is used to create musl's libc.so.
# Copyright ? Huawei Technologies Co., Ltd. 2010-2018. All rights reserved.

set -e

readonly MUSL_DIR="$PWD/musl"
readonly MUSL_SOURCE="$PWD/../../../../third_party/musl/*"
#readonly MUSL_PATCH="$PWD/../../../../build/lite/patches/0000-musl-liteos.patch"
readonly LITEOSTOPDIR="$PWD/../../../../kernel/liteos_a"
readonly SYSROOT="$PWD/usr"

BUILD=`gcc -dumpmachine`
HOST=`gcc -dumpmachine`
TARGET=arm-liteos
CROSS_COMPILE=llvm-
CFLAGS_FOR_TARGET="--target=${TARGET} -mfloat-abi=soft -march=armv7-a -Wall -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack"
CFLAGS_FOR_TARGET1="--target=${TARGET} -mfloat-abi=soft -mcpu=cortex-a7 -Wall -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack"
CFLAGS_FOR_TARGET2="--target=${TARGET} -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4 -Wall -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack"
CFLAGS_FOR_TARGET3="--target=${TARGET} -mfloat-abi=hard -mcpu=cortex-a7 -mfpu=neon-vfpv4 -Wall -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack"

PARALLEL=`grep ^processor /proc/cpuinfo|wc -l`
LITEOS_COMPILER_PATH=`${LITEOSTOPDIR}/tools/build/mk/get_llvm_compiler_path.sh ${CROSS_COMPILE} ${LITEOSTOPDIR}`
LDFLAG="-L${LITEOS_COMPILER_PATH}/lib/clang/9.0.0/lib/${TARGET} -L${LITEOS_COMPILER_PATH}/lib/${TARGET}/c++ --rtlib=compiler-rt -lclang_rt.builtins -lunwind -fuse-ld=lld -Wl,--build-id=sha1"

export PATH="${LITEOS_COMPILER_PATH}/bin:$PATH"

#prepare to build musl
mkdir -p $MUSL_DIR
mkdir -p $SYSROOT
cp -r $MUSL_SOURCE $MUSL_DIR

# prepare linux compat headers
sh thirdparty_headers.sh

#build musl
pushd $MUSL_DIR
#patch -p1 < $MUSL_PATCH

HEADERDIR="${SYSROOT}/include/${TARGET}"
LIBDIR="${SYSROOT}/lib/${TARGET}"
BINDIR="${SYSROOT}/bin/${TARGET}"
SYSDIR="${SYSROOT}/sys/${TARGET}"
mkdir -p $LIBDIR $BINDIR $SYSDIR $HEADERDIR
CC="${LITEOS_COMPILER_PATH}/bin/clang $CFLAGS_FOR_TARGET" CROSS_COMPILE="${CROSS_COMPILE}" LDFLAGS="${LDFLAG}" ./configure --prefix=$SYSROOT --libdir=$LIBDIR --bindir=$BINDIR --syslibdir=$SYSDIR --includedir=$HEADERDIR --build=$BUILD --host=$TARGET
make -j $PARALLEL
make install
make clean

HEADERDIR="${SYSROOT}/include/${TARGET}"
LIBDIR="${SYSROOT}/lib/${TARGET}/a7_soft"
BINDIR="${SYSROOT}/bin/${TARGET}/a7_soft"
SYSDIR="${SYSROOT}/sys/a7_soft"
mkdir -p $LIBDIR $BINDIR $SYSDIR $HEADERDIR
CC="${LITEOS_COMPILER_PATH}/bin/clang $CFLAGS_FOR_TARGET1" CROSS_COMPILE="${CROSS_COMPILE}" LDFLAGS="${LDFLAG}" ./configure --prefix=$SYSROOT --libdir=$LIBDIR --bindir=$BINDIR --syslibdir=$SYSDIR  --includedir=$HEADERDIR --build=$BUILD --host=$TARGET
make -j $PARALLEL
make install
make clean

HEADERDIR="${SYSROOT}/include/${TARGET}"
LIBDIR="${SYSROOT}/lib/${TARGET}/a7_softfp_neon-vfpv4"
BINDIR="${SYSROOT}/bin/${TARGET}/a7_softfp_neon-vfpv4"
SYSDIR="${SYSROOT}/sys/${TARGET}/a7_softfp_neon-vfpv4"
mkdir -p $LIBDIR $BINDIR $SYSDIR $HEADERDIR
CC="${LITEOS_COMPILER_PATH}/bin/clang $CFLAGS_FOR_TARGET2" CROSS_COMPILE="${CROSS_COMPILE}" LDFLAGS="${LDFLAG}" ./configure --prefix=$SYSROOT --libdir=$LIBDIR --bindir=$BINDIR --syslibdir=$SYSDIR  --includedir=$HEADERDIR --build=$BUILD --host=$TARGET
make -j $PARALLEL
make install
make clean

HEADERDIR="${SYSROOT}/include/${TARGET}"
LIBDIR="${SYSROOT}/lib/${TARGET}/a7_hard_neon-vfpv4"
BINDIR="${SYSROOT}/bin/${TARGET}/a7_hard_neon-vfpv4"
SYSDIR="${SYSROOT}/sys/${TARGET}/a7_hard_neon-vfpv4"
mkdir -p $LIBDIR $BINDIR $SYSDIR $HEADERDIR
CC="${LITEOS_COMPILER_PATH}/bin/clang $CFLAGS_FOR_TARGET3" CROSS_COMPILE="${CROSS_COMPILE}" LDFLAGS="${LDFLAG}" ./configure --prefix=$SYSROOT --libdir=$LIBDIR --bindir=$BINDIR --syslibdir=$SYSDIR  --includedir=$HEADERDIR --build=$BUILD --host=$TARGET
make -j $PARALLEL
make install
popd
