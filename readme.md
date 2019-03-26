HW04
===
This is the hw04 sample. Please follow the steps below.

# Build the Sample Program

1. Fork this repo to your own github account.

2. Clone the repo that you just forked.

3. Under the hw04 dir, use:

	* `make` to build.

	* `make flash` to flash the binary file into your STM32F4 device.

	* `make clean` to clean the ouput files.

# Build Your Own Program

1. Edit or add files if you need to.

2. Make and run like the steps above.

3. Please avoid using hardware dependent C standard library functions like `printf`, `malloc`, etc.

# HW04 Requirements

1. Please practice to reference the user manuals mentioned in [Lecture 04], and try to use the user button (the blue one on the STM32F4DISCOVERY board).

2. After reset, the device starts to wait until the user button has been pressed, and then starts to blink the blue led forever.

3. Try to define a macro function `READ_BIT(addr, bit)` in reg.h for reading the value of the user button.

4. Push your repo to your github. (Use .gitignore to exclude the output files like object files, executable files, or binary files)

5. The TAs will clone your repo, build from your source code, and flash to see the result.

[Lecture 04]: http://www.nc.es.ncku.edu.tw/course/embedded/04/

--------------------

- [x] **If you volunteer to give the presentation (demo) next week, check this.**

--------------------

Take your note here if you want. (Optional)


### Manual 
+ As stated in the following chapters of Discovery kit with STM32F407VG MCU User Manual
	+ §6.4 Push buttons
		```
		B1 USER: User and Wake-Up buttons are connected to the I/O PA0 of the STM32F407VG.
		```
+ In RM0090 Reference manual
	+ §8.4.5 GPIO port input data register (GPIOx_IDR) (x = A..I/J/K)
		```
		Address offset: 0x10
		Bits 15:0 IDRy: Port input data (y = 0..15)
				These bits are read-only and can be accessed in word mode only.
		```

### Define macro and function
+ Define offset and bits(in `reg.h`)
	```c
	#define GPIOx_IDR_OFFSET 0x10
	#define IDRy_BIT(y) (y)
	```
+ Read bit
	+ Define `READ_BIT`(in `reg.h`)
		```c
		#define READ_BIT(addr, bit) (REG(addr) &= UINT32_1 << (bit))
		```
	+ Read button(`PA0`)(in `blink.c`)
		```c
		READ_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_IDR_OFFSET, IDRy_BIT(button));
		```
