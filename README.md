<div align="center">
  <img height="140" src="https://github.com/SirGhazian/manajemen-hotel/assets/142916107/388696cc-dd30-4e08-a4f1-5b6e6d5fede3"  />
</div>

</a>
<hr/> 

Repo ini berisi implementasi sederhana dari Sistem Manajemen Kamar Hotel menggunakan bahasa pemrograman C. Program ini dikembangkan sebagai bagian dari tugas akhir mata kuliah praktikum Struktur Data. Dalam program ini, pengguna dapat melakukan berbagai operasi seperti menambahkan kamar baru, menampilkan daftar kamar, mencari kamar berdasarkan kode, mengurutkan kamar berdasarkan kode atau harga, memfilter kamar berdasarkan kategori (Ekonomi/VIP), mengedit detail kamar, dan menghapus kamar. Program ini menggunakan linked list untuk menyimpan dan mengelola data kamar.

## 【 Fitur 】
- Tambah kamar baru
- Tambah kamar default
- Tampilkan semua kamar
- Cari kamar berdasarkan kode
- Urutkan kamar berdasarkan kode atau harga (ascending/descending)
- Filter kamar berdasarkan kategori (Ekonomi/VIP)
- Edit detail kamar
- Hapus kamar dari list

## 【 Persyaratan 】
- Bahasa yang digunakan: C
- Kompiler C (misalnya, GCC)
- conio.h (spesifik untuk Windows)

## 【 Tinjauan Kode 】

### Algoritma
- Menggunakan linked list dalam membuat list.
- Menggunakan algoritma Bubble Sort untuk menyortir list.
- Menggunakan algoritma Linear Search untuk mencari data dalam list.

### Struktur
- `Kamar`: Mendefinisikan struktur untuk data kamar.

### Fungsi-Fungsi
- `Kamar *buatKamar(char *kode, int harga, int kategori);`
- `void tambahKamar(Kamar **head, char *kode, int harga, int kategori);`
- `void tampilkanKamar(Kamar *head);`
- `Kamar *cariKamar(Kamar *head, char *kode);`
- `void urutkanKode(Kamar **head);`
- `void urutkanTermurah(Kamar **head);`
- `void urutkanTermahal(Kamar **head);`
- `void tampilkanKategori(Kamar *head, int kategori);`
- `void editKamar(Kamar *head, char *kode, int harga, int kategori);`
- `void hapusKamar(Kamar **head, char *kode);`
- `int clearScreen();`

### Penambahan Kamar Default
Beberapa kamar default ditambahkan ke dalam linked list untuk tujuan demonstrasi.

## 【 Screenshot 】
Untuk screenshot lebih lengkap, [lihat disini](/Screenshot%20Output).

<img src="https://github.com/SirGhazian/manajemen-hotel/assets/142916107/1a359842-b05f-4f10-af19-da813f30b467" width="400">
<img src="https://github.com/SirGhazian/manajemen-hotel/assets/142916107/e60a3e1a-6ce7-470c-a3c7-c19644626c97" width="400">
<img src="https://github.com/SirGhazian/manajemen-hotel/assets/142916107/640b7d79-9128-453f-aff3-77229a912d28" width="400">
<img src="https://github.com/SirGhazian/manajemen-hotel/assets/142916107/75997f93-a1a7-42f8-b64b-d05096a15780" width="400">
<img src="https://github.com/SirGhazian/manajemen-hotel/assets/142916107/c7dc161d-421b-427d-9e0d-d980ceae0cc5" width="400">
<img src="https://github.com/SirGhazian/manajemen-hotel/assets/142916107/fc2cf7b1-70d5-4097-8c2b-17c79e8fb954" width="400">

## 【 About and Help 】

Untuk bantuan dan pertanyaan, silahkan hubungi sosial media saya:
<img align="right" width="100" src="https://github.com/SirGhazian/praktikum-struktur-data-UNP/assets/142916107/b140fe43-3a57-4295-8493-79d929a5e3b0">

-   [![Instagram](https://img.shields.io/badge/Instagram-%23E4405F.svg?logo=Instagram&logoColor=white)](https://instagram.com/ghazian_tza)
-   [![YouTube](https://img.shields.io/badge/YouTube-%23FF0000.svg?logo=YouTube&logoColor=white)](https://www.youtube.com/channel/UCIp_064wQ8RqNSEy1asx_4w)

