//lấy dữ liệu thời gian từ NTP( Network Time Protocol) dùng wifi
#include <Arduino.h>
#include <WiFi.h>
#include <NTPClient.h> // Thư viện lấy thời gian từ internet
#include <WiFiUdp.h>

const char* ssid = "Xdev2.4Ghz";
const char* password = "Token2024@";

// Cấu hình NTP
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 7*3600, 60000); // 7*3600 là múi giờ của Việt Nam

void setup(){
  Serial.begin(9600);
  Serial.println("Connecting to wifi..."); // Kết nối wifi
  WiFi.begin(ssid, password); //Khởi tạo wifi với tên và mật khẩu
  while(WiFi.status() != WL_CONNECTED){ //hàm đợi kết nối đến wifi
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to wifi");
  Serial.println("\n");
  timeClient.begin(); // Bắt đầu lấy thời gian
}

void loop(){
  timeClient.update(); // Cập nhật thời gian từ NTP
  Serial.println(timeClient.getFormattedTime()); // In thời gian getFormattedTime là hàm lấy thời gian dạng hh:mm:ss
  delay(1000); //oke ông cứ hỏi đi:v nhà có chuyện xíu
}

// Làm thế nào để lấy thời gian thực chính xác (cho phép sai số nhỏ), mà không dùng thư viện thời gian thực?