SOAL ADA DI .PDF

Penjelasan Kode:
Kelas Robot:

Menyimpan posisi robot (x, y), apakah robot bisa melewati dinding (canPassWalls), kecepatan (speed), dan waktu perjalanan (time).
Metode move(char direction, const vector<vector<char>>& map) digunakan untuk menggerakkan robot sesuai dengan arah (U, D, L, R) dan memeriksa kondisi di peta.
Peta:

Disimpan dalam bentuk matriks 2D (vector<vector<char>>), di mana setiap elemen mewakili kondisi di peta (S, F, x, M, E, P, O).
Gerakan:

Setiap gerakan robot diperiksa apakah valid, apakah bertemu dinding, atau bertemu dengan tim tertentu yang mempengaruhi kemampuan robot (misalnya mekanik untuk melewati dinding, electrical untuk meningkatkan kecepatan, dll.).
Output:

Output berdasarkan kondisi yang terjadi setelah setiap gerakan.
Jika robot mencapai tujuan (F), tampilkan "Robot berhasil mencapai tujuan". Jika gagal, tampilkan "Robot gagal dalam mencapai tujuan :(".
Pada akhir perjalanan, tampilkan total waktu yang ditempuh robot.
