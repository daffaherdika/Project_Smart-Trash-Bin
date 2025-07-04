#include <Servo.h> 
Servo myservo1;  // Membuat objek Servo 
Servo myservo2;  // Membuat objek Servo 
int pos = 0;    // Variabel untuk menyimpan posisi servo 
int nBasah = 1023; 
const int soilMoisturePin = A0;  // Definisikan pin yang digunakan untuk sensor kelembaban 
tanah 
const int pirSensorPin = 2;  // Definisikan pin yang digunakan untuk sensor PIR 
const int TRIGPIN = 8;           
const int ECHOPIN = 9; 
long timer; 
int jarak; 
bool is_wet() 
{ 
  // int soilMoistureValue = analogRead(soilMoisturePin);  // Membaca nilai analog dari sensor 
  if(nBasah > 1000) 
  { 
    return false; 
  } 
  return true; 
} 
 
void masukKeBasah() { 
  for (pos = 90; pos <= 160; pos += 1) { 
      myservo2.write(pos);              // Menggerakkan servo ke posisi 
      delay(15);                       // Tunggu sebentar untuk pergerakan 
    } 
    delay(5000);  // Tunggu 1 detik di posisi 180 derajat 
 
    // Gerakkan servo dari posisi 180 derajat ke 0 derajat 
    for (pos = 160; pos >= 90; pos -= 1) { 
      myservo2.write(pos);              // Menggerakkan servo ke posisi 
      delay(15);                       // Tunggu sebentar untuk pergerakan 
    } 
} 
 
void masukKeKering() { 
  for (pos = 90; pos >= 40; pos -= 1) { 
      myservo2.write(pos);              // Menggerakkan servo ke posisi 
      delay(15);                       // Tunggu sebentar untuk pergerakan 
    } 
    delay(5000);  // Tunggu 1 detik di posisi 180 derajat 
 
    // Gerakkan servo dari posisi 180 derajat ke 0 derajat 
    for (pos = 40; pos <= 90; pos += 1) { 
      myservo2.write(pos);              // Menggerakkan servo ke posisi 
      delay(15);                       // Tunggu sebentar untuk pergerakan 
    } 
    delay(100);  // Tunggu 1 detik di posisi 0 derajat 
} 
 
void setup() { 
  Serial.begin(9600);  // Inisialisasi komunikasi Serial dengan kecepatan 9600 bps 
 
  pinMode(pirSensorPin, INPUT);  // Set pin sensor PIR sebagai input 
 
  pinMode(ECHOPIN, INPUT); 
  pinMode(TRIGPIN, OUTPUT); 
  myservo1.attach(10);  // Menghubungkan servo ke pin 10 
  myservo2.attach(11);  // Menghubungkan servo ke pin 11 
} 
 
void loop() { 
  nBasah = 1023; 
  int soilMoistureValue = analogRead(soilMoisturePin);  // Membaca nilai analog dari sensor 
 
  Serial.print("Nilai Kelembaban Tanah: "); 
  Serial.println(soilMoistureValue); 
 
  delay(100);  // Tunggu 1 detik sebelum membaca ulang nilai kelembaban 
 
  digitalWrite(TRIGPIN, LOW);                    
  delayMicroseconds(2); 
  digitalWrite(TRIGPIN, HIGH);                   
  delayMicroseconds(10); 
  digitalWrite(TRIGPIN, LOW);                    
 
  timer = pulseIn(ECHOPIN, HIGH); 
  jarak = timer/58; 
  delay(100); 
 
  Serial.print("Jarak = "); 
  Serial.print(jarak); 
  Serial.print(" cm"); 
  Serial.println(); 
 
//-----------------------ada sampah 
  if (jarak <= 10) { 
  // Gerakkan servo dari posisi 0 derajat ke  derajat----------------------- buka 
  for (pos = 100; pos >= 0; pos -= 1) { 
    myservo1.write(pos);              // Menggerakkan servo ke posisi 
    delay(15);                       // Tunggu sebentar untuk pergerakan 
  } 
  delay(5000);  // Tunggu 5 detik setelah dibuka 
 
  for(int i = 0; i <= 5; i++){ 
  int soilMoistureValue = analogRead(soilMoisturePin);  // Membaca nilai analog dari sensor 
 
  Serial.print("Nilai Kelembaban Tanah: "); 
  Serial.println(soilMoistureValue); 
  delay(100);  // Tunggu 1 detik sebelum membaca ulang nilai kelembaban 
  } 
 
  // Gerakkan servo dari posisi 180 derajat ke 0 derajat--------------------- tutup 
  for (pos = 0; pos <= 100; pos += 1) { 
    myservo1.write(pos);              // Menggerakkan servo ke posisi 
    delay(15);                       // Tunggu sebentar untuk pergerakan 
  } 
  delay(100);  // Tunggu 1 detik di posisi 0 derajat 
 
  for(int i = 0; i <= 50; i++){ 
  int soilMoistureValue = analogRead(soilMoisturePin);  // Membaca nilai analog dari sensor 
 
  Serial.print("Nilai Kelembaban Tanah: "); 
  Serial.println(soilMoistureValue); 
  delay(100);  // Tunggu 1 detik sebelum membaca ulang nilai kelembaban 
 
if (soilMoistureValue < 1000) 
nBasah = soilMoistureValue; 
} 
} 
if (is_wet()) { 
masukKeBasah(); 
else { 
masukKeKering(); 
} 
delay(5000); 
} 
}