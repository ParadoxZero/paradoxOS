# ParadoxOS
Unix unlike operating system. 

This is an hobbyst Operating System Project.

## Tools

* [Freestanding GCC](https://wiki.osdev.org/GCC_Cross-Compiler) ( will make an automated script soon)
* GNU Make
* Grub
* qemu
* Linux (Obviously)

## How to build

Once you have the requried tools. Simply fo to the project root and
```
    $ ./setup.sh iso
```

Then run the iso using qemu

```
    $ qemu-system-i686 -cdrom paradoxOS.iso
```
