# libcrazy
Libcrazy is a library that implements the [crazy operator](https://en.wikipedia.org/wiki/Malbolge#Crazy_operation) from Malbolge in C.
It includes both a function for converting numbers to ternary and a function that does the crazy.

## Building

### Dependencies
- A standard C library.
- ANSI C compiler or later.
- Probably a POSIX-compliant environment idk i didn't test this on Windows.

### Build configuration
You can configure your libcrazy build to use a different compiler or ar, or a cross-compiler:
- AR: Defaults to `ar`, specifies which ar the build should use.
- CC: Defaults to `cc`, specifies which compiler the build should use.
- CFLAGS: Defaults to `-g -O2`, specifies C compiler arguments.
- CROSS\_COMPILE: Defaults to nothing, specifies cross-compiler prefix.
- LDFLAGS: Defaults to nothing, specifies linker flags.
- PREFIX: Defaults to `/usr/local`, specifies installation prefix for libcrazy.

Examples:

- Regular build:
```
make
```
- Cross-compiling for GNU/Linux on ARMv7-A with -O3 optimizations:
```
make CROSS_COMPILE=arm-linux-gnueabihf- CC=arm-linux-gnueabihf-gcc CFLAGS="-O3"
```

## Functions

- `long int dectotern(long int tobeterned)`:
Converts `tobeterned` (long int) from decimal to ternary. Returns the result of the conversion (long int).

- `long int crazy(long int tobecrazied1, long int tobecrazied2, bool areintstern, bool returntern)`:
Performs the crazy operation on `tobecrazied1` (long int) and `tobecrazied2` (long int). `areintstern` (bool) specifies if `tobecrazied1` and `tobecrazied2`
are in ternary already, if not they get converted with `dectotern`. `returntern` (bool) specifies if `crazy` should return the result in ternary or
decimal.
