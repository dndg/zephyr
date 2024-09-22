.. zephyr:code-sample:: opta_boot_m4
   :name: Boot the M4

   Boot M4 then just blink a LED while M4 goes on executing a different sample.

Overview
********
Opta hardware does not start the M4 CPU at boot but keeps it disabled. This
example shows how to boot the M4 and let it execute any other sample that
uses shared devices (for example GPIOs) or has been configured to run on M4.

This example uses ``0x08180000`` as the M4 boot address (this is compatible
with the Arduino IDE 75%-25% flash split).

Building and Running
********************

Build for ``arduino_opta/stm32h747xx/m7``:

.. zephyr-app-commands::
   :zephyr-app: samples/boards/opta/boot_m4
   :board: stm32h747i_disco/stm32h747xx/m7
   :goals: build

For the ``arduino_opta/stm32h747xx/m4`` just build any other sample, e.g.:

.. zephyr-app-commands::
   :zephyr-app: samples/basic/blinky
   :board: stm32h747i_disco/stm32h747xx/m4
   :goals: build

Or something a bit more complex, using the builtin RS485:

.. zephyr-app-commands::
   :zephyr-app: samples/basic/button
   :board: stm32h747i_disco/stm32h747xx/m4
   :goals: build
