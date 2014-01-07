/* Fungsi Pertanyaan
 * Creator  : Habibi Mustafa
 * Date     : 3/1/2014
 * Updated  : 4/1/2014
 */

#include </home/habibi/Desktop/CPlus/9/hd-kuis.h>

// tampilin kotak permainan
void kotak(char sq[10]){
	string a = "        |     |     \n";
	string b = "   _____|_____|_____\n";

	gantibaris();
	ucp(a); cout<<"     "<<sq[1]<<"  |  "<<sq[2]<<"  |  "<<sq[3]<<"  \n"; ucp(b);
	ucp(a); cout<<"     "<<sq[4]<<"  |  "<<sq[5]<<"  |  "<<sq[6]<<"  \n"; ucp(b);
	ucp(a); cout<<"     "<<sq[7]<<"  |  "<<sq[8]<<"  |  "<<sq[9]<<"  \n"; ucp(a);
	gantibaris();
}

// cek baris horizontal
bool cekhorizontal(char sq[10]){
	if (sq[1] == sq[2] && sq[2] == sq[3])
		return true;
	else if (sq[4] == sq[5] && sq[5] == sq[6])
		return true;
	else if (sq[7] == sq[8] && sq[8] == sq[9])
		return true;
	else
		return false;
}

// cek baris vertikal
bool cekvertikal(char sq[10]){
	if (sq[1] == sq[4] && sq[4] == sq[7])
		return true;
	else if (sq[2] == sq[5] && sq[5] == sq[8])
		return true;
	else if (sq[3] == sq[6] && sq[6] == sq[9])
		return true;
	else
		return false;
}

// cek baris diagonal
bool cekdiagonal(char sq[10]){
	if (sq[1] == sq[5] && sq[5] == sq[9])
		return true;
	else if (sq[3] == sq[5] && sq[5] == sq[7])
		return true;
	else
		return false;
}

// cek apakah imbang
bool cekimbang(char sq[10]){
	if ( sq[1]!='1' && sq[2]!='2' && sq[3]!='3' && 
		 sq[4]!='4' && sq[5]!='5' && sq[6]!='6' && 
		 sq[7]!='7' && sq[8]!='8' && sq[9]!='9' )
		return true;
	else
		return false;
}

// cek baris
int cekbaris(char sq[10]){
	// cek baris horizontal
	bool a = cekhorizontal(sq);
	//cek baris vertikal
	bool b = cekvertikal(sq);
	//cek baris diagonal
	bool c = cekdiagonal(sq);
	//cek apakah imbang
	bool d = cekimbang(sq);

	// kondisi return
	// 1 untuk menang
	// 0 untuk imbang
	//-1 masih main
	if (a) return 1;
	else if (b) return 1;
	else if (c) return 1;
	else if (d) return 0;
	else return -1;
}

// inisialisasi pemain
string * setpemain(){
	static string pemain[2];
	ucp("Pemain #1\n");
	pemain[0] = tny("Nama Pemain:");
	ucp("X", "Simbol kamu: ", "\n---\n");
	ucp("Pemain #2\n");
	pemain[1] = tny("Nama Pemain:");
	ucp("O", "Simbol kamu: ", "\n---\n");
	gantibaris();

	// basa-basi aja.
	tny("Ok, bisa dilanjut? Tekan 'enter' donk!");
	bersih();

	return pemain;
}

// set giliran
int setgiliran(int g){
	return (g==1)?2:1;	
}

// set simbol
int setsimbol(int g){
	return (g==1)?'X':'O';	
}

// cek nomor kotak yang dipilih
// apakah sudah dipilih sebelumnya
bool cekpilihan(int pil, char sq[10]){
	if ( (pil==1 && sq[1]=='1') or (pil==2 && sq[2]=='2') or (pil==3 && sq[3]=='3') or 
	     (pil==4 && sq[4]=='4') or (pil==5 && sq[5]=='5') or (pil==6 && sq[6]=='6') or 
	     (pil==7 && sq[7]=='7') or (pil==8 && sq[8]=='8') or (pil==9 && sq[9]=='9')
	)
		return true; // belum dipilih
	else
		return false; // sudah dipilih
}

void taktik(string s[9][6]){
	// persiapan
	bersih();

	// inisialisasi permainan
	string *pemain = setpemain(); // tanya nama pemain
	char nomer[10] = {'-','1','2','3','4','5','6','7','8','9'};
	char sim; int pil, gil, p, i = cekbaris(nomer);

	// ulangi selama belum ada yang menang / belum imbang
	while(i==-1){
		//perisapan layar
		bersih();

		// atur giliran dan simbol
		gil = setgiliran(gil);
		sim = setsimbol(gil);
		p   = gil - 1;

		// pemberitahuan giliran. perintah memilih nomor
		ucp(", sekarang giliranmu!\n", pemain[p]); kotak(nomer);
		setpil: pil = brp("Kamu mau pilih nomer berapa?");
		
		// cek pilihan
		bool cp = cekpilihan(pil, nomer);
		if(!cp){
			ucp("Ga bisa kk, pilih nomer yang laen donk!\n");
			goto setpil;
		}else{
			gantibaris(); cin.ignore();
			bool ty  = soal( s[pil-1] );
			if(ty) nomer[pil] = sim;
		}

		// cek apa sudah ada yang menang
		i = cekbaris(nomer);
	}

	// tampilkan isi kotak
	// setelah permainan
	bersih();
	kotak(nomer);
	
	//  ucapan selamat aja
	if(i==1){ ucp(", selamat ya. Kamu menang!", pemain[p]); }
	else{ ucp("Wah, kalian berdua emang hebat. Kalian imbang!"); }
	gantibaris();
}

void permainan(){
	const int s = 5;
	const int w = 5;
    string banksoal[s][w][6] = {
    	{ // Jaringan Komputer
	        { "192.168.0.10 merupakan contoh pemberian alamat pada sebuah komputer \nyang akan dihubungkan dalam sebuah jaringan. Angka-angka tersebut dikenal dengan istilah …", 
	          "IP Address", "Protokol", "Domain", "TCP/IP", "Konfigurasi" },
	        { "Suatu aturan dimana pemilik program tetap memegang haknya tetapi orang lain \ndimungkinkan untuk menyebarkan dan memodifikasi, dengan syarat source code asli \nharus diikutsertakan dalam distribusinya disebut …", 
	          "GPL (General Public License)", "OEM (Original Equipment Manufacturer)", "TTL (Time to Live)", "OEP (Overseas Employment promoters)", "RTO (Request Time Out" },
	        { "Domain dengan ekstensi .go.id berarti …", 
	          "domain tersebut milik pemerintahan", "domain tersebut milik suatu perkumpulan", "domain tersebut milik pribadi / perorangan", "domain tersebut milik suatu perusahaan", "domain tersebut milik suatu kampus" },
	        { "Nama domain host / server www.asus.co.tw berlokasi di …", 
	          "Taiwan", "Singapura", "Thailand", "Swiss", "China" },
	        { "Suatu protocol yang berfungsi untuk tukar-menukar file dalam suatu network \nyang menggunakan TCP adalah …", 
	          "File Transfer Protocol", "Domain Name System", "Hyper Text Transfer Protocol", "Transmission Control Protocol", "General Public Control Protocol" },
    	},
    	{ // Sistem Operasi Linux
	        { "Sistem operasi LINUX pertama kali diciptakan oleh …", 
	          "Linus Torvalds", "Bill Gates", "Tim Berners Lee", "Mark Zuckerberg", "Sergey Brin" },
	        { "Sistem operasi Linux menyediakan dua mode yaitu …", 
	          "Mode Grafik dan Mode Text", "Unix dan Mode Grafik", "Unix dan Linux", "Unix dan Mode Text", "Mode text dan Linux" },
	        { "Tanda bahwa shell prompt masuk sebagai root adalah …", 
	          "#", "@", "$", ">", "~" },
	        { "Sistem operasi Linux merupakan turunan dari …", 
	          "Unix", "Minix", "Ugos", "Linus", "Inux" },
	        { "File system yang digunakan linux yaitu …", 
	          "Extended", "NTFS", "FAT32", "HFS", "XFS" },
    	},
    	{ //Pengetahuan Umum
	        { "Kepanjangan dari BPUPKI adalah …", 
	          "Badan Penyelidik Usaha Persiapan Kemerdekaan Indonesia", 
	          "Badan Persiapan Usaha Persiapan Kemerdekaan Indonesia", 
	          "Badan Penyelidik Urusan Persiapan Kemerdekaan Indonesia", 
	          "Badan Persiapan Usaha Penyelidik Kemerdekaan Indonesia", 
	          "Badan Penyidik Usaha Persiapan Kemerdekaan Indonesia" },
	        { "Jales Veva Jaya Mahe merupakan semboyan dari …", 
	          "Angkatan Laut RI", "Angkatan Darat RI", "Angkatan Udara RI", "Angkatan Bersenjata RI", "Polisi RI" },
	        { "Bapak Koperasi Indonesia adalah …", 
	          "Moh. Hatta", "Soekarno", "Soeharto", "Agus Salim", "Moh. Yamin" },
	        { "Kalpataru adalah penghargaan yang diberikan kepada …", 
	          "Penyelamat Lingkungan Hidup", "Pengamat Sejarah", "Pahlawan Perjuangan", "Penyelamat Binatang", "Pejuang Pendidikan" },
	        { "Penulis Comic Naruto adalah …", 
	          "Masashi Kishimoto", "Masashi Matsuyama", "Masashi Kimomoto", "Masashi Yuriko", "Masashi Matsunaga" },
    	},
    	{ // KKPI / ICT
	        { "Salah satu cara yang bisa kita lakukan untuk menyimpan dokumen adalah \ndengan menekan tombol …", 
	          "CTRL + S", "CTRL + O", "CTRL + C", "CTRL + N", "CTRL + P" },
	        { "Jika pada sel A3 nilai 8 dan sel B3 nilainya 9, kemudian dikalikan, \nmaka penulisan yang benar adalah …", 
	          "= A3 * B3", "A3 * B3", "8 x 9", "8 * 9", "= A3 x B3" },
	        { "Perintah yang digunakan untuk mencari nilai rata-rata pada aplikasi Ms. Excel ialah …", 
	          "AVERAGE", "MAX", "MIN", "SUM", "IF" },
	        { "Baris yang digunakan untuk meletakkan rumus pada aplikasi Ms. Excel disebut …", 
	          "Formula Bar", "Function Bar", "Toolbar", "Function Row", "Field" },
	        { "Tipe data yang berisi angka urut yang sudah ditetapkan oleh Ms. Access \nyang muncul secara otomatis adalah …", 
	          "Auto Number", "Date/Time", "Currency", "Text", "Number" },
    	},
    	{ // Elektronika Dasar
	        { "Resistor adalah komponen dasar elektronika yang berfungsi untuk …", 
	          "membatasi jumlah arus yang mengalir", "membatasi jumlah tegangan yang mengalir", 
	          "membatasi jumlah daya yang mengalir", "membatasi jumlah frekuensi yang mengalir", 
	          "membatasi jumlah tahanan yang mengalir" },
	        { "SCR singkatan dari …", 
	          "Silicon Controled Rectifier", "System Controlled Rectifier", "System Controlled Resistor", "Silicon Controlled Resistor", "Silicon Controlled Resistant" },
	        { "Alat ukur yang di gunakan untuk mengukur bentuk gelombang dari sebuah rangkaian adalah …", 
	          "Osciloskop", "Multitester", "AFG", "Sinyal Injektor", "SWR Meter" },
	        { "Dibawah ini adalah jenis resistor non linear, kecuali …", 
	          "SCR ( Silicon Controlled Rectifier )", "PTC ( Positive Temperature Coefitien )", "LDR ( Light Dependent Resistor )", "NTC ( Negative Temperature Coefisien )", "Semua jawaban salah" },
	        { "Waktu yang dibutuhkan kapasitor untuk mencapai pengisian optimal \ntergantung pada besarnya nilai …", 
	          "kapasitansi dan resistansi", "kapasitansi dan impedansi", "reaktansi dan kapasitansi", "resistansi dan impedansi", "admitansi dan resistansi" }
    	},
    };

    int t[s]; for(int i=0;i<s;i++){t[i]=i;}
    int *u = urutan(t);

    srand(time(0));
    static string persoalan[9][6];
    for(int i=0;i<9;i++){
    	int k = (i>(s-1))?(i-(s-1)):i;
    	int m = u[k];
    	int n = rand() % w;

    	for(int j=0;j<6;j++){
    		persoalan[i][j] = banksoal[m][n][j];
    	}
    }

    taktik(persoalan);
}

void aturan(){
	const int b=9;
	string a[b] = {
		"Permainan ini terdiri dari 2 orang pemain",
		"Masing-masing pemain memiliki simbol 'X' dan 'O'",
		"Para pemain akan disuguhkan 9 kotak yang harus dipilih",
		"Masing-masing kotak memiliki sebuah pertanyaan yang harus dijawab",
		"Jika pertanyaan dapat dijawab dengan benar maka nomor kotak akan menjadi simbol pemain",
		"Jika pertanyaan tidak dapat dijawab dengan benar maka nomor pada kotak tidak akan berubah",
		"Kotak yang sudah berubah menjadi simbol tidak dapat dipilih kembali oleh pemain",
		"Untuk memenangkan permainan ini pemain diharuskan membentuk pola simbol horizontal, vertikal ataupun diagonal",
		"Pemain yang lebih dahulu membentuk pola tersebut dinyatakan sebagai pemenang"
	};

	gantibaris();
	for(int c=0;c<b;c++) ucp(a[c],"# ","\n");
	gantibaris();
}