/*#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"driver/gpio.h"
#include "esp_log.h"


#define LED_PIN GPIO_NUM_2
static const char *TAG = "LED_Control";


void app_main() {
    esp_log_level_set(TAG, ESP_LOG_INFO);

    esp_rom_gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1)
    {
        
        gpio_set_level(LED_PIN,1);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
        ESP_LOGI(TAG, "LED ON");

        
        gpio_set_level(LED_PIN,0);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
        ESP_LOGI(TAG, "LED OFF");

    }
    
}*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/uart.h"

#define LED_PIN GPIO_NUM_2

void app_main() {
    // Configure UART for printing to the serial monitor
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_param_config(UART_NUM_0, &uart_config);
    uart_set_pin(UART_NUM_0, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM_0, 256, 0, 0, NULL, 0);

    // Set up the LED GPIO
    esp_rom_gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(LED_PIN, 1);
        printf("LED ON\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        gpio_set_level(LED_PIN, 0);
        printf("LED OFF\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
