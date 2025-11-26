# === Percobaan 1: Identitas & Navigasi ===
whoami
hostname
pwd
sudo hwclock
ls -l
ls -a

# === Percobaan 2: Operasi Direktori ===
mkdir latihan1
mkdir latihan2
mkdir -p latihan3/bab1/pilihan_ganda
ls -R latihan3
rmdir latihan1
rm -r latihan3
cd latihan4
cd ..

# === Operasi File ===
touch soal_ujian
echo "kumpulan soal" > latihan_ujian
cat latihan_ujian
cp latihan_ujian copy_ujian
mv copy_ujian file_baru
rm file_baru

# === Percobaan 3: Pencarian & Text ===
cat /etc/passwd
head -5 /etc/passwd
tail -5 /etc/passwd
grep 'root' /etc/passwd
find / -name "*.txt" 2>/dev/null

