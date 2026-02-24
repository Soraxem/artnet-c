# artnet-c
Very simple Artnet Packet parser and Constructor

## Project State

Curently packet objects are beeing built, serialisatzion and parsing is beeing implemented for packet types.

## Compile the Library

To Compile all the needed Files for the Library.

```bash
gcc -o binary tests/test.c src/packets.h src/common.h src/common.c src/packets/*
```