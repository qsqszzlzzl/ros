#include <stdio.h>

// 假设的GPIO控制函数，您需要根据您的微控制器进行实现
// 例如：
// #include "stm32f4xx_hal.h" // STM32 HAL库
// #define LED_GPIO_PORT GPIOD
// #define LED_GPIO_PIN GPIO_PIN_12

void GPIO_Init() {
    // 在这里初始化您的GPIO引脚，设置为输出模式
    // 例如：
    // __HAL_RCC_GPIOD_CLK_ENABLE();
    // GPIO_InitTypeDef GPIO_InitStruct = {0};
    // GPIO_InitStruct.Pin = LED_GPIO_PIN;
    // GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    // GPIO_InitStruct.Pull = GPIO_NOPULL;
    // GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    // HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
}

void LED_On() {
    // 在这里设置LED引脚为高电平，点亮LED
    // 例如：
    // HAL_GPIO_WritePin(LED_GPIO_PORT, LED_GPIO_PIN, GPIO_PIN_SET);
}

void LED_Off() {
    // 在这里设置LED引脚为低电平，熄灭LED
    // 例如：
    // HAL_GPIO_WritePin(LED_GPIO_PORT, LED_GPIO_PIN, GPIO_PIN_RESET);
}

void Delay_ms(unsigned int ms) {
    // 在这里实现毫秒级延时函数
    // 例如，对于简单的延时，可以使用循环，但更精确的延时通常需要定时器或RTOS
    // for (unsigned int i = 0; i < ms; i++) {
    //     for (unsigned int j = 0; j < 1000; j++); // 粗略的延时
    // }
}

int main() {
    // 初始化GPIO
    GPIO_Init();

    while (1) {
        LED_On();         // 点亮LED
        Delay_ms(500);    // 延时500毫秒
        LED_Off();        // 熄灭LED
        Delay_ms(500);    // 延时500毫秒
    }

    return 0;
}
