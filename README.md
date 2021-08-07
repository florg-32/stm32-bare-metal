# STM32 Makefile template project

This Makefile project can be used as starting point for any bare metal stm32 development.
It comes equipped with CMSIS for the *STM32F103C8TB*, used on the blue pill. Any platform specific files
need to be exchanged for the correct ones. The toolchain paths are set at the beginning of the Makefile.

---

**Platform specific files**
- *lib/startup_stm32f[...].s* Contains the vector table and reset handler  
- *lib/stm32\*.h* CMSIS platform files
- *STM32\*.ld* Linker script
- *STM32\*.svd* Maps peripherals for Clions debugger [optional]
- *stm32\*.cfg* OpenOCD config file [optional]  

**Required toolchain**
- [GNU ARM embedded toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
- [stlink tools](https://github.com/stlink-org/stlink)