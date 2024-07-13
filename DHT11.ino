#include <dht11.h> // DHT11 kütüphanesini dahil edin
#include <LiquidCrystal.h> // LCD kütüphanesini dahil edin

#define DHT11_PIN 7 // DHT11 sensörünün bağlı olduğu pini tanımlayın

LiquidCrystal lcd(12, 11, 5, 6, 3, 2); // LCD ekran pinlerini tanımlayın
dht11 DHT; // DHT11 nesnesini oluşturun

void setup() {
  lcd.begin(16, 2); // LCD ekranı başlatın
  Serial.begin(9600); // Seri iletişimi başlatıyoruz
}

void loop() {
  int chk = DHT.read(DHT11_PIN); // DHT11 sensörünü okuyun

  // Nem Oranını Seri Monitörde Yazdırın
  Serial.print("Nem Orani (%): ");
  Serial.println((float)DHT.humidity, 2);

  // Sıcaklık Değerlerini Seri Monitörde Yazdırın
  Serial.print("Sicaklik (Celsius): ");
  Serial.println((float)DHT.temperature, 2);

  // LCD Ekrana Yazdırma
  lcd.setCursor(0, 0); // LCD ekranın ilk satırının başına geçin
  lcd.print("Temp: "); // "Temp: " yazısını yazdırın
  lcd.print(DHT.temperature); // Sıcaklık değerini yazdırın
  lcd.print("C"); // "C" yazısını yazdırın
  lcd.setCursor(0, 1); // LCD ekranın ikinci satırının başına geçin
  lcd.print("Humidity: "); // "Humidity: " yazısını yazdırın
  lcd.print(DHT.humidity); // Nem değerini yazdırın

  delay(2000); // 2 saniye bekleyin (Tepki süresi 1s'den fazla olmalı)
  lcd.clear(); // LCD ekranı temizleyin
}
