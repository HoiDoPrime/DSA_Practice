#include "stm32f4xx_hal.h"

// Định nghĩa địa chỉ của cảm biến nhiệt độ trên bus I2C
#define TEMP_SENSOR_ADDR 0x48 << 1  // Địa chỉ của cảm biến nhiệt độ (được shift sang trái để phù hợp với định dạng của HAL)
#define TEMP_REG 0x00               // Địa chỉ của thanh ghi nhiệt độ

// Khai báo cấu trúc cho giao tiếp I2C
I2C_HandleTypeDef hi2c1;

// Các hàm cấu hình hệ thống và khởi tạo
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);

int main(void) {
    // Khởi tạo HAL Library
    HAL_Init();
    
    // Cấu hình xung hệ thống
    SystemClock_Config();
    
    // Khởi tạo các chân GPIO
    MX_GPIO_Init();
    
    // Khởi tạo giao thức I2C
    MX_I2C1_Init();

    uint8_t temp_data[2];  // Biến lưu trữ dữ liệu nhiệt độ đọc được
    while (1) {
        // Gửi yêu cầu đọc nhiệt độ đến cảm biến
        HAL_I2C_Master_Transmit(&hi2c1, TEMP_SENSOR_ADDR, &TEMP_REG, 1, HAL_MAX_DELAY);
        
        // Đọc dữ liệu nhiệt độ từ cảm biến
        HAL_I2C_Master_Receive(&hi2c1, TEMP_SENSOR_ADDR, temp_data, 2, HAL_MAX_DELAY);
        
        // Chuyển đổi dữ liệu nhiệt độ từ dạng thô sang dạng đọc được
        int16_t raw_temp = (temp_data[0] << 8) | temp_data[1];  // Kết hợp hai byte dữ liệu
        float temperature = raw_temp * 0.0625;  // Đơn vị độ C
        
        // Xử lý hoặc hiển thị nhiệt độ (được thực hiện sau)
        // ...

        HAL_Delay(1000);  // Đợi 1 giây trước khi đọc lại
    }
}

// Cấu hình xung hệ thống (cụ thể cho vi điều khiển STM32)
void SystemClock_Config(void) {
    // Thực hiện các cấu hình liên quan đến xung hệ thống, PLL, v.v.
    // ...
}

// Khởi tạo các chân GPIO
static void MX_GPIO_Init(void) {
    // Thực hiện các cấu hình khởi tạo GPIO
    // ...
}

// Khởi tạo giao tiếp I2C
static void MX_I2C1_Init(void) {
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 100000;  // Tốc độ xung I2C là 100 kHz
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;  // Chu kỳ nhiệm vụ
    hi2c1.Init.OwnAddress1 = 0;  // Địa chỉ của thiết bị chủ
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;  // Địa chỉ 7-bit
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;  // Không sử dụng địa chỉ kép
    hi2c1.Init.OwnAddress2 = 0;  // Địa chỉ thứ hai
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;  // Không sử dụng cuộc gọi chung
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;  // Không sử dụng chế độ không kéo dài
    if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
        // Xử lý lỗi khởi tạo I2C
        // ...
    }
}

// Cấu hình phần cứng cụ thể cho giao tiếp I2C (MSP)
void HAL_I2C_MspInit(I2C_HandleTypeDef* i2cHandle) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if (i2cHandle->Instance == I2C1) {
        // Kích hoạt đồng hồ cho I2C1
        __HAL_RCC_I2C1_CLK_ENABLE();

        // Kích hoạt đồng hồ cho các chân GPIOB
        __HAL_RCC_GPIOB_CLK_ENABLE();
        // Cấu hình các chân GPIO cho I2C1 (PB6 cho SCL, PB7 cho SDA)
        GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    }
}

// Hàm giải phóng tài nguyên của giao tiếp I2C (MSP)
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* i2cHandle) {
    if (i2cHandle->Instance == I2C1) {
        // Tắt đồng hồ cho I2C1
        __HAL_RCC_I2C1_CLK_DISABLE();

        // Giải phóng các chân GPIO được sử dụng bởi I2C1
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6 | GPIO_PIN_7);
    }
}
