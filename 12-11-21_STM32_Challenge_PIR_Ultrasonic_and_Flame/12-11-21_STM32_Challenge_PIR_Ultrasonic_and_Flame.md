// Logika 12-11-21_STM32_Challenge_PIR_Ultrasonic_and_Flame

1. Apabila Sensor Flame atau Sensor Infrared aktif, maka akan mengaktifkan sensor Ultrasonik.
2. Setelah Sensor Ultrasonik aktif, ada 3 kemungkinan :
    a. Apabila jarak jauh, LED menyala secara flip-flop (merah, kuning, hijau, kuning, merah).
    b. Apabila jarak sedang, LED menyala bersamaan delay 1 detik.
    c. Apabila jarak sedang, LED menyala bersamaan delay 0.1 detik.
3. Kemudian apabila Sensor Flame atau Sensor Infrared aktif lagi, semua lampu akan mati.
    
Catatan :
* Gunakan sistem pengunci, yang mana apabila LED dinyalakan oleh sensor flame, maka HARUS dimatikan oleh sensor flame juga.
* Gunakan sistem count untuk menghitung jumlah gerakan.
