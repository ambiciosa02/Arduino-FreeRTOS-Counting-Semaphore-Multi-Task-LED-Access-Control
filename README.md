# Arduino-FreeRTOS-Counting-Semaphore-Multi-Task-LED-Access-Control
This Arduino project demonstrates the use of a counting semaphore in FreeRTOS to control access to limited hardware resources. Five tasks attempt to use three LEDs simultaneously. The counting semaphore ensures that at most three tasks can turn on the LEDs at the same time, while others wait their turn.
