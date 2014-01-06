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