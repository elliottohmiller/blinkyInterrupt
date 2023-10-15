MAKING EMBEDDED SYSTEMS
Week 3, "Blinky" Homework Assignment Q/A

##What are the hardware registers that cause the LED to turn on and off? (From the processor manual, don’t worry about initialization.)

The LEDs on my STM32F407G-DISC1 are connected to these 4 pins in Port D: PD12:PD15. 

The GPIOxBSRR (Bit Set / Reset Register) allows atomic single bit read / write access to the GPIOxODR (Output Data Register).

##What are the registers that you read in order to find out the state of the button?

The user button is connected to Port A, pin 0, in an "Active HI" configuration. 
HAL_GPIO_ReadPin() reads the status of the GPIOxIDR (Input Data Register) for the corresponding pin.

##Can you read the register directly and see the button change in a debugger or by printing out the value of the memory at the register’s address?

Yes, HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) may perform this function. 

In my project, the Button::debounce() function samples the GPIOxIDR until a set number of consecutive samples (as defined by DEBOUNCE_SAMPLE_MIN in button.hpp) are read. Once the sample data is stable, the Button class member "m_status" is assigned the value of the consecutive sample data and returned to the caller. 
