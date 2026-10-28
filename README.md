# libcrazy
Libcrazy is a library that implements the
[crazy operator](https://en.wikipedia.org/wiki/Malbolge#Crazy_operation)
from Malbolge in C. It includes both a function for converting numbers from
decimal to ternary and vice versa, and a function that does the crazy.

## Building

### Dependencies
- A standard C library.
- ANSI C compiler or later.
- Probably a POSIX-compliant environment idk i didn't test this on Windows.

### Build configuration
You can configure your libcrazy build to use a different compiler or ar, or a cross-compiler:
- AR: Defaults to `${CROSS_COMPILE}ar`, specifies which ar the build should use.
- CC: Defaults to `${CROSS_COMPILE}cc`, specifies which compiler the build should use.
- CFLAGS: Defaults to `-g -O2`, specifies C compiler arguments.
- CROSS\_COMPILE: Defaults to nothing, specifies cross-compiler prefix.
- LDFLAGS: Defaults to nothing, specifies linker flags.
- PREFIX: Defaults to `/usr/local`, specifies installation prefix for libcrazy.

Examples:

- Regular build:
```
$ make
```
- Cross-compiling for GNU/Linux on ARMv7-A with -O3 optimizations:
```
$ make CROSS_COMPILE=arm-linux-gnueabihf- CC=arm-linux-gnueabihf-gcc CFLAGS="-O3"
```

### Installation
Examples:

- Regular installation (to /usr/local):
```
# make install
```

- Installation to /usr:
```
# make PREFIX=/usr install
```

## API reference

```
long dectotern(long tobeterned)
```
Converts `tobeterned` from decimal to ternary and returns the result of the
conversion.

```
long terntodec(long tobedecimaled)
```
Converts `tobedecimaled` from ternary to decimal and returns the result of the
conversion.

```
long crazy(long tobecrazied1, long tobecrazied2, bool areintstern)
```
Performs the crazy operation on `tobecrazied1` and `tobecrazied2` and returns
the result. `areintstern` (bool) specifies if `tobecrazied1` and `tobecrazied2`
are in ternary already, if they are, they get converted to decimal with `terntodec`.

```
int LIBCRAZY_VER[3]
```
Contains the version of libcrazy that's currently installed (currently 1.3.2).
`LIBCRAZY_VER[0]` is the major version, `LIBCRAZY_VER[1]` is the minor version,
and `LIBCRAZY_VER[2]` is the patch version.
