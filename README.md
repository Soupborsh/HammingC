## (WIP) Hamming codes implementation in C.

Currently can only generate valid blocks with random data. 16(15,11) and 256 bits block sizes were tested.

## Building:
```bash
make
```
### Cross compiling and/or static linking
Cross compiling requires ```zig``` package to use ```zig cc``` C compiler

```bash
make TARGET_ARCH=target
```
#### Example compiling for arm(32bit) with static linking to create portable executable:
```bash
make TARGET_ARCH=arm-linux-musleabihf
```