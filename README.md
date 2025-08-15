# Arduino-FreeRTOS-Counting-Semaphore-Multi-Task-LED-Access-Control
This Arduino project demonstrates the use of a counting semaphore in FreeRTOS to control access to limited hardware resources. Five tasks attempt to use three LEDs simultaneously. The counting semaphore ensures that at most three tasks can turn on the LEDs at the same time, while others wait their turn.

How it Works:
This project demonstrates a counting semaphore in FreeRTOS. A counting semaphore allows a limited number of tasks to access a finite set of resources concurrently. Here, the 3 LEDs represent the shared resources.

5 tasks are created, each simulating a user trying to access an LED.

The semaphore is initialized with a count of 3, meaning 3 LEDs can be used simultaneously.

Each task waits for a free resource by taking the semaphore. If available, the task turns on its assigned LED, simulates some work, and then releases the semaphore.

Program Flow:

Initialize LED pins as outputs.

Create a counting semaphore with 3 resources.

Create 5 tasks (userTask) that attempt to use an LED.

Inside each task:

Take the semaphore (xSemaphoreTake).

Turn on the corresponding LED and print a message.

Wait for 1 second to simulate work.

Turn off the LED and give the semaphore (xSemaphoreGive).

Delay for 2 seconds before attempting to use a LED again.

FreeRTOS handles task scheduling, ensuring no more than 3 tasks use LEDs simultaneously.

Notes:

Counting semaphores are useful for managing limited shared resources like LEDs, sensors, or motors.

The tasks are independent and automatically wait if no resource is available.

This example can be scaled to more resources or tasks.
