/*
 * Copyright (c) 2016 Intel Corporation
 * Copyright (c) 2024 DNDG srl
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <stm32h7xx_ll_rcc.h>
#include <stm32h7xx_ll_system.h>

/* The devicetree node identifier for the green led over reset button. */
#define LED_RESET_NODE DT_NODELABEL(led_reset)

/* Unfortunately we cannot use the M4 device tree from M7 code and we need
 * to hardcode the M4 boot address here. */
#define M4_BOOT_ADDRESS 0x08180000

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_RESET_NODE, gpios);

int main(void)
{
	int ret;

	if (!gpio_is_ready_dt(&led)) {
		return 0;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

	// Boot the M4.
	LL_SYSCFG_SetCM4BootAddress0(M4_BOOT_ADDRESS >> 16);
	LL_RCC_ForceCM4Boot();

	while (1) {
		ret = gpio_pin_toggle_dt(&led);
		if (ret < 0) {
			return 0;
		}
		k_msleep(1000);
	}
	return 0;
}
