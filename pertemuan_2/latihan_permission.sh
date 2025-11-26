# === Percobaan 1: Ijin Akses (Chmod) ===
touch f1 f2 f3
ls -l f1
chmod u+x f1
chmod g-w f1
chmod o-r f1
ls -l f1

# Menggunakan Angka Octal
chmod 751 f1
chmod 624 f2
chmod 430 f3

# === Percobaan 2: Umask ===
umask 027
touch newfile
mkdir mydir
ls -l newfile
# Reset umask
umask 002

# === Percobaan 3: Link ===
echo "Halo apa kabar" > halo.txt
# Hard Link
ln halo.txt hardlink
ls -li halo.txt hardlink
# Soft Link
ln -s halo.txt softlink
ls -l softlink

