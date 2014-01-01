/* Program Tugas Akhir (Game Kuis Taktik Jitu)
 * Creator	: Habibi Mustafa
 * Date		: 27/12/2013
 */

#include <iostream>	// untuk cin() dan cout()
#include <stdlib.h>	// untuk system()
#include <cstdlib>	// untuk srand() dan rand()
#include <ctime>	// untuk time()
using namespace std;


// nyetak kata. improvisasi cout ^_^
template <class SIJI>
void ucp(SIJI kata="", string prefix="", string sufix=""){
    cout<<prefix<<kata<<sufix;
}

// nanya
string tny(string kata){
    string inp;
    ucp(kata,""," ");
    getline(cin, inp);
    return inp;
}

// berapa
int brp(string kata){
    int inp; 
    ucp(kata,""," ");
    cin>>inp;
    return inp;
}

// bersihin layar
void bersih(){
	system("clear");
}

// buat ganti baris
void gantibaris(int ulang=1){
	for(int i=0; i<ulang; i++){
		ucp("\n");		
	}
}

// ngacak urutan
// int* acak(int s=1){
//     int urut[s];
//     for (int n=0; n<s; n++){
//     	urut[n] = n;
//     }
//     srand(time(0));
//     for (int i=0; i<(s-1); i++) {
//     	int r = i + (rand() % (s-i));
//     	int temp = urut[i]; 
//     	urut[i]  = urut[r]; 
//     	urut[r] = temp;
//     }

//     int *ret = urut;
//     return ret;
// }

// tampilkan soal
bool soal(string soal="", string pilb="", string pil1="", string pil2="", string pil3="", string pil4=""){
    // inisialisasi dan persiapan
    int		s = 5;
    string	abcd[s];
    string	jawab[s];
    abcd[0] = "A. ";	jawab[0] = pilb;
    abcd[1] = "B. ";	jawab[1] = pil1;
    abcd[2] = "C. ";	jawab[2] = pil2;
    abcd[3] = "D. ";	jawab[3] = pil3;
    abcd[4] = "E. ";	jawab[4] = pil4;

    // Sstt, lagi ngacak jawaban.
    srand(time(0));
    for (int i=0; i<(s-1); i++) {
    	int r = i + (rand() % (s-i));
    	string temp = jawab[i]; 
    	jawab[i] = jawab[r]; 
    	jawab[r] = temp;
    }

    // cetak soal dan jawab ke layar
    ucp(soal,"","\n\n");
    for (int c=0; c<s; c++) {
    	ucp(jawab[c], abcd[c], "\n");
    }
	gantibaris();

	// minta jawaban
	tn: string jwb = tny("Jawaban (A/B/C/D/E):"); int p;
	if ( (jwb=="A") || (jwb=="a") ) { p = 0; }
	else if ( (jwb=="B") || (jwb=="b") ) { p=1; }
	else if ( (jwb=="C") || (jwb=="c") ) { p=2; }
	else if ( (jwb=="D") || (jwb=="d") ) { p=3; }
	else if ( (jwb=="E") || (jwb=="e") ) { p=4; }
	else { goto tn; }

	// ucapin selamat + balikin hasil jawaban
	if(jawab[p] == pilb){
		ucp("Mantap, jawaban kamu benar!","","\n");
		return true;
	}else{
		ucp("Oops, jawaban kamu salah!","","\n");
		return false;		
	}
}

int kuis(){
	// kumpulan soal
	// [tipe][jumlah][isi:soal,jwb-bnr,opsi1,opsi2,opsi3,opsi4]
	string banksoal[2][10][6] = {
		// Pengetahuan Umum
		 {
			{ "Penambahan nilai mata uang untuk mengembalikan daya beli masyarakat disebut …", 
			  "Deflasi", "Inflasi", "Defisit", "Resesi", "Devaluasi" },
			{ "Organisasi PBB yang bergerak dalam bidang kemanusiaan adalah …", 
			  "UNHCR", "WHO", "ILO", "UNESCO", "UNICEF" },
			{ "Candi Muara Takus merupakan peninggalan kerajaan …", 
			  "Sriwijaya", "Majapahit", "Singosari", "Samudera Pasai", "Mataram" },
			{ "Hari Pramuka diperingati setiap tanggal …", 
			  "14 Agustus", "26 Juni", "10 November", "2 Mei", "28 Oktober" },
			{ "Pemerintah darurat RI pernah memindahkan ibukota Indonesia ke kota …", 
			  "Yogyakarta", "Bukittinggi", "Bandung", "Jakarta", "Surabaya" },
			{ "Terusan Suez terdapat di negara …", 
			  "Mesir", "Arab Saudi", "Kanada", "Perancis", "Palestina" },
			{ "Suku Samin terdapat di daerah …", 
			  "Blora", "Pacitan", "Banten", "Cirebon", "Brebes" },
			{ "Konferensi Meja Bundar diadakan di Kota …", 
			  "Den Hag", "Jakarta", "Berlin", "Washington", "Perth" },
			{ "Nama penghargaan di bidang perdamaian adalah …", 
			  "Nobel", "Oscar", "Norbert Winner", "Emmy", "Pulitzer" },
			{ "Nama maskot piala dunia di Afrika Selatan tahun 2010 adalah …", 
			  "Zakumi", "Striker", "Ciao", "Willy", "Footix" }
		},
	};

    // acak urutan pertanyaan
    int s=5, urut[s];
    for (int n=0; n<s; n++){
    	urut[n] = n;
    }
    srand(time(0));
    for (int i=0; i<(s-1); i++) {
    	int r = i + (rand() % (s-i));
    	int temp = urut[i]; 
    	urut[i]  = urut[r]; 
    	urut[r] = temp;
    }

    // tampilkan soal
    bersih(); cin.ignore();
	bool q; int x=0, y=0, z=0, skor=0;
	while(x<s){
		z = urut[x];
		ucp("Pertanyan ke-"); ucp(x+1, "", "\n");
		string a = banksoal[y][z][0];
		string b = banksoal[y][z][1];
		string c = banksoal[y][z][2];
		string d = banksoal[y][z][3];
		string e = banksoal[y][z][4];
		string f = banksoal[y][z][5];
		q=soal(a,b,c,d,e,f);
		if(q) skor++;
		gantibaris();
		x++;
	}
	
	return skor;
}

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

// ganti simbol
char ganti(char asl, char sim){
	int ku = kuis();
	return (ku>=3)?sim:asl;
}

void taktik(){
	// persiapan
	bersih();
	cin.ignore();

	// inisialisasi pemain
	string pemain[2];
	ucp("Pemain #1\n");
	pemain[0] = tny("Nama Pemain:");
	ucp("X", "Simbol kamu: ", "\n---\n");
	ucp("Pemain #2\n");
	pemain[1] = tny("Nama Pemain:");
	ucp("O", "Simbol kamu: ", "\n---\n");
	gantibaris();

	// basa-basi aja. konfirmasi permaian mau dimulai
	tny("Ok, bisa dilanjut? Tekan 'enter' donk!");
	bersih();

	// inisialisasi kotak permainan
	char nomer[10] = {'o','1','2','3','4','5','6','7','8','9'};
	char simbol; int pilihan, giliran, p, i = cekbaris(nomer);

	// selama belum ada yang menang
	while(i==-1){
		//perisapan layar
		bersih();

		// atur giliran dan simbol
		giliran = (giliran==1)?2:1;
		simbol = (giliran==1)?'X':'O';
		p = giliran - 1;

		// pemberitahuan giliran. perintah memilih nomor
		ucp(", sekarang giliranmu!", pemain[p], "\n"); kotak(nomer);
		pil: pilihan = brp("Kamu mau pilih nomer berapa? ");

		// cek nomor pilihan. set simbol ke nomor yang dipilih
		if(pilihan==1 && nomer[1]=='1'){ nomer[1] = ganti(nomer[1], simbol); }
		else if(pilihan==2 && nomer[2]=='2'){ nomer[2] = ganti(nomer[2], simbol); }
		else if(pilihan==3 && nomer[3]=='3'){ nomer[3] = ganti(nomer[3], simbol); }
		else if(pilihan==4 && nomer[4]=='4'){ nomer[4] = ganti(nomer[4], simbol); }
		else if(pilihan==5 && nomer[5]=='5'){ nomer[5] = ganti(nomer[5], simbol); }
		else if(pilihan==6 && nomer[6]=='6'){ nomer[6] = ganti(nomer[6], simbol); }
		else if(pilihan==7 && nomer[7]=='7'){ nomer[7] = ganti(nomer[7], simbol); }
		else if(pilihan==8 && nomer[8]=='8'){ nomer[8] = ganti(nomer[8], simbol); }
		else if(pilihan==9 && nomer[9]=='9'){ nomer[9] = ganti(nomer[9], simbol); }
		else { ucp("Ga bisa kk, pilih nomer yang laen donk!\n"); goto pil; }

		// cek apa sudah ada yang menang
		i = cekbaris(nomer);
	}

	// tampilkan isi kotak
	// setelah permainan
	kotak(nomer);
	
	//  ucapan selamat aja
	if(i==1){ ucp(", selamat ya. Kamu menang!", pemain[p]); }
	else{ ucp("Wah, kalian berdua emang hebat. Kalian imbang!"); }
	gantibaris();
}

int main(){
	mulai: bersih(); 
	ucp("++++++++++++++++++++++++++++++++++++++\n");
	ucp("++++++++++++ Tak Tik Jitu ++++++++++++\n");
	ucp("++++++++++++++++++++++++++++++++++++++\n");
	gantibaris();

	// menu utama
	ucp("Menu Utama:\n");
	ucp("1. Aturan Main\n");
	ucp("2. Mulai Bermain\n");
	ucp("3. Keluar\n");
	gantibaris();
	menu: int a = brp("Pilihan (1-3):");
	switch(a){
		default: goto menu;  break;
		case 1:	 goto rules; break;
		case 2:  goto play;  break;
		case 3:  return(0);  break;
	}

	// aturan main
	rules:
	goto mulai;

	// mulai bermain
	play:
	taktik();
	gantibaris(); ucp("---\n");
	ucp("Menu Permainan:\n");
	ucp("1. Main Lagi\n");
	ucp("2. Ke Menu Utama\n");
	ucp("3. Keluar\n");
	gantibaris();
	submenu: int b = brp("Pilihan (1-3):");	
	switch(b){
		default: goto submenu;	break;
		case 1:	 goto play;		break;
		case 2:  goto mulai;	break;
		case 3:  return(0);		break;
	}
}