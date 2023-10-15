##What are the hardware registers that cause the LED to turn on and off? (From the processor manual, don’t worry about initialization.)

LEDs are connected to 4 pins in Port D: PD12:PD15
GPIOD->BSRR (Bit set / reset), atomic single bit access
Writes to GPIOD->ODR (Output Data Register)

##What are the registers that you read in order to find out the state of the button?

Button is connected to Port A, pin 0
HAL_GPIO_ReadPin() reads the status of the GPIOxODR for the corresponding pin

##Can you read the register directly and see the button change in a debugger or by printing out the value of the memory at the register’s address?

Yes, HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) performs this function in my timer ISR. 
