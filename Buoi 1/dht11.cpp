#include <Arduino.h>
#include "DHT.h"

// Khai báo chân DATA và loại cảm biến
#define DHTPIN 12         // Chân DATA của DHT11 nối với GPIO15
#define DHTTYPE DHT11     // Loại cảm biến: DHT11

DHT dht(12, DHT11);

void setup() {
    Serial.begin(115200); // Khởi động Serial Monitor
    dht.begin();          // Khởi động cảm biến DHT11
}

void loop() {
    // Đọc nhiệt độ và độ ẩm
    float humidity = dht.readHumidity();      // Đọc độ ẩm
    float temperature = dht.readTemperature(); // Đọc nhiệt độ theo độ C
    
    // Kiểm tra nếu cảm biến hoạt động bình thường
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Không đọc được dữ liệu từ cảm biến DHT11!");
        return;
    }

    // In giá trị nhiệt độ và độ ẩm
    Serial.print("Độ ẩm: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("Nhiệt độ: ");
    Serial.print(temperature);
    Serial.println(" °C");

    delay(2000); // Chờ 2 giây trước khi đọc lại dữ liệu
}
