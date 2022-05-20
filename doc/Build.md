
## Dependencies

Required tools:

- gcc
- make

The objective is to build a cross-compiler.

## Build cross compiler

To install the GCC cross compiler you can follow this steps :
https://wiki.osdev.org/GCC_Cross-Compiler

## Export

```bash
export PREFIX="/usr/local/i386elfgcc"
export TARGET=i386-elf
export PATH="$PREFIX/bin:$PATH"
```

## Build

### Build for the OS

`make build`

### Build for the CPU

`make build_i386`


## License

JackLang is licensed under a MIT license.
