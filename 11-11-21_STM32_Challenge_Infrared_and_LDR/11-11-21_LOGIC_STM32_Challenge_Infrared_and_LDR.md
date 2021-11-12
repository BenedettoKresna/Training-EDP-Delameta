// Logika 11-11-21_STM32_Challenge_Infrared_and_LDR.ino

1. Apabila Infrared aktif, maka akan mengaktifkan sensor LDR.
2. Setelah Sensor LDR aktif, ada 3 kemungkinan : 
a. Apabila kondisi cahaya terang, LED hijau menyala, lain mati.
b. Apabila kondisi cahaya sedang, LED kuning menyala, lain mati.
c. Apabila kondisi cahaya gelap, LED merah menyala, lain mati.
3. Kemudian apabila Sensor Infrared aktif lagi, semua lampu akan mati.

Catatan :
- Gunakan sistem count untuk menghitung jumlah gerakan.

PENTING!!!!!
- Apabila Sensor Infrared dalam kondisi ada gerakan, maka nilai yang ditampilkan 0, 
sebaliknya apabila Sensor Infrared dalam kondisi tidak ada gerakan, maka nilai yang ditampilkan 1. (ACTIVE LOW)
- Apabila Sensor LDR dalam kondisi terang (diberi senter), maka nilai yang ditampilkan akan semakin kecil, 
sebaliknya apabila Sensor LDR dalam kondisi gelap (tidak diberi senter), maka nilai yang ditampilkan akan semakin besar. (ACTIVE LOW)
