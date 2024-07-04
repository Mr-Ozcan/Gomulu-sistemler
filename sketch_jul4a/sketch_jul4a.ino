#include <Servo.h>
#include <Keypad.h>

// Servo motor tanımlamaları
Servo servo360;
Servo continuousServo;

// Keypad ayarları
const byte ROWS = 4; // Satır sayısı
const byte COLS = 3; // Sütun sayısı
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Satır pinleri
byte colPins[COLS] = {5, 4, 3, 2}; // Sütun pinleri

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Servo motor pin atamaları
  servo360.attach(9);
  continuousServo.attach(10);

  // Başlangıç konumu
  servo360.write(0);
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    // Tuş takımından gelen girişe göre servo konumunu belirle
    switch (key) {
      case '1':
        moveServo(50);
        break;
      case '2':
        moveServo(100);
        break;
      case '3':
        moveServo(150);
        break;
      case '4':
        moveServo(200);
        break;
      case '5':
        moveServo(250);
        break;
      case '6':
        moveServo(300);
        break;
    }
  }
}

// Servo motoru hareket ettirme fonksiyonu
void moveServo(int position) {
  servo360.write(position);
  delay(1000); // Servo motorun pozisyon alması için bekleme süresi
  kaldirac();
}

// Kaldıraç fonksiyonu
void kaldirac() {
  // Sürekli dönebilen servo motoru saat yönünde 1.5 saniye döndür
  continuousServo.write(180);
  delay(1500);
  
  // Duraklatma
  continuousServo.write(90);
  delay(3000);

  // Sürekli dönebilen servo motoru saat yönünün tersine 1.5 saniye döndür
  continuousServo.write(0);
  delay(1500);
  
  // Motoru durdur
  continuousServo.write(90);
}
