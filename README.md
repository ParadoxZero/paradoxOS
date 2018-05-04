# ParadoxOS
This is an hobbyist Operating System Project currently in very early stage. The design has not been finalized yet, hence no formal design docs is available.

At the moment, the aim is to initialize the kernel properly to utilize modern system features.

## Tools

* [Freestanding toolchain](https://wiki.osdev.org/GCC_Cross-Compiler) ( will make an automated script soon)
* GNU Make
* Grub
* qemu
* Linux (Obviously)

## Compiling Freestanding Toolchain
Execute the script `toolchain.sh`

## How to build

Once you have the requried tools.
```
    $ ./setup.sh iso
```
This will build an iso file called `paradoxOS.iso`. This is a binary complaint with multiboot standard, and is compiled using grub. That means, it can be simply booted up.

Though using an emulator is recommended.

```
    $ qemu-system-i686 -cdrom paradoxOS.iso
```
## Contributing

Contributions are always welcome. Please check issues to see any pending task.

Feel free to send a pull request.

## References

* [Osdev Wiki](https://wiki.osdev.org)
* [Building OS from scratch](http://www.cs.bham.ac.uk/%7Eexr/lectures/opsys/10_11/lectures/os-dev.pdf)
* [x86 Assembly](https://en.wikibooks.org/wiki/X86_Assembly)
* Google!
