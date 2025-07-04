
# 🗑️ Smart Trash Bin: Pemilah Sampah Basah dan Kering

Proyek ini merupakan sistem tempat sampah otomatis yang mampu **mendeteksi keberadaan sampah**, **menganalisis kelembaban**, serta **memilahnya** ke dalam kategori basah atau kering menggunakan sensor dan mikrokontroler Arduino Uno.

## 🚀 Fitur Utama

- 🚶 Deteksi otomatis keberadaan sampah menggunakan sensor ultrasonik
- ⚙️ Penutup tempat sampah terbuka otomatis saat ada sampah
- 💧 Pengukuran kelembaban sampah dengan sensor soil moisture
- 🔄 Pemilahan sampah ke kompartemen basah atau kering menggunakan servo motor
- 🔁 Sistem berulang dan siap mendeteksi sampah baru setelah siklus selesai

## 🧰 Teknologi dan Komponen

| Komponen            | Fungsi                                                                 |
|---------------------|------------------------------------------------------------------------|
| Arduino Uno         | Mikrokontroler utama untuk menjalankan seluruh logika sistem           |
| Sensor Ultrasonik   | Mendeteksi keberadaan sampah dalam jarak ≤ 10 cm                       |
| Sensor Soil Moisture| Mengukur kelembaban sampah untuk klasifikasi basah/kering             |
| Servo Motor (x2)    | Mengatur penutup tempat sampah dan menggerakkan papan pemilah          |

## ⚙️ Cara Kerja Sistem

1. **Deteksi Sampah**: Sensor ultrasonik membaca jarak benda, jika jarak ≤ 10 cm maka sistem aktif.
2. **Buka Penutup**: Servo 1 membuka penutup tempat sampah selama beberapa detik.
3. **Pembacaan Kelembaban**: Sensor kelembaban membaca nilai resistansi sampah.
4. **Klasifikasi**:
   - Jika nilai kelembaban rendah → sampah diklasifikasikan sebagai **kering**
   - Jika nilai kelembaban tinggi → sampah diklasifikasikan sebagai **basah**
5. **Pemisahan**: Servo 2 menggerakkan papan pemilah ke arah kompartemen yang sesuai.
6. **Reset Sistem**: Papan pemilah kembali ke posisi awal dan sistem siap menerima sampah baru.

## 📂 Struktur Kode

Semua kode utama ditulis dalam Arduino IDE dan menggunakan library `Servo.h`. Berikut adalah bagian penting:
- `setup()` → Inisialisasi pin dan servo
- `loop()` → Loop utama pendeteksi sampah dan pemilah berdasarkan kelembaban
- Fungsi `masukKeBasah()` dan `masukKeKering()` untuk mengatur arah pemilah

## 📌 Spesifikasi Tambahan

- **Sensor Ultrasonik**: Jarak 2–400 cm, akurasi ±3 mm
- **Sensor Soil Moisture**: Output analog (0–1023), membaca resistansi tanah
- **Servo SG90**: Rotasi 0–180°, kecepatan ±0.1s/60°, torsi hingga 1.8 kgf/cm

## 🛠️ Instalasi dan Upload

1. Buka Arduino IDE
2. Unggah kode dari file `main.ino` (pastikan library `Servo.h` telah terinstall)
3. Hubungkan Arduino Uno sesuai pin pada proyek
4. Jalankan sistem dan uji dengan berbagai jenis sampah

## 📷 Dokumentasi

(Tambahkan gambar diagram sistem, wiring, atau foto prototipe di sini)

## 🤝 Kontribusi

Proyek ini dikembangkan sebagai bagian dari eksperimen sistem otomatisasi berbasis mikrokontroler. Siapa pun dipersilakan untuk mengembangkan lebih lanjut, misalnya dengan:
- Menambahkan sensor suhu atau gas
- Integrasi dengan IoT / ESP32
- Penambahan display status
