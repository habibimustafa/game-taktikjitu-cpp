/* Program Tugas Akhir (Game Kuis Taktik Jitu)
 * Creator	: Habibi Mustafa
 * Date		: 27/12/2013
 * Updated	: 4/1/2014
 */

// My Own Header
#include </home/habibi/Desktop/CPlus/9/hd-main.h>

// acak urutan soal dari tiap tipe
int * urutan(int urut[5]){
    srand(time(0)); int s = 5;
    for (int i=0; i<(s-1); i++) {
        int r = i + (rand() % (s-i));
        int temp = urut[i];
        urut[i]  = urut[r];
        urut[r]  = temp;
    }

    return urut;
}

int main(){
	const int s = 5;
    string banksoal[s][2][6] = {
    	{
	        { "Penambahan nilai mata uang untuk mengembalikan daya beli masyarakat disebut …", 
	          "Deflasi", "Inflasi", "Defisit", "Resesi", "Devaluasi" },
	        { "Organisasi PBB yang bergerak dalam bidang kemanusiaan adalah …", 
	          "UNHCR", "WHO", "ILO", "UNESCO", "UNICEF" }
    	},
    	{
	        { "Candi Muara Takus merupakan peninggalan kerajaan …", 
	          "Sriwijaya", "Majapahit", "Singosari", "Samudera Pasai", "Mataram" },
	        { "Hari Pramuka diperingati setiap tanggal …", 
	          "14 Agustus", "26 Juni", "10 November", "2 Mei", "28 Oktober" }
    	},
    	{
	        { "Pemerintah darurat RI pernah memindahkan ibukota Indonesia ke kota …", 
	          "Yogyakarta", "Bukittinggi", "Bandung", "Jakarta", "Surabaya" },
	        { "Terusan Suez terdapat di negara …", 
	          "Mesir", "Arab Saudi", "Kanada", "Perancis", "Palestina" }
    	},
    	{
	        { "Suku Samin terdapat di daerah …", 
	          "Blora", "Pacitan", "Banten", "Cirebon", "Brebes" },
	        { "Konferensi Meja Bundar diadakan di Kota …", 
	          "Den Hag", "Jakarta", "Berlin", "Washington", "Perth" }
    	},
    	{
	        { "Konferensi Meja Bundar diadakan di Kota …", 
	          "Den Hag", "Jakarta", "Berlin", "Washington", "Perth" },
	        { "Nama penghargaan di bidang perdamaian adalah …", 
	          "Nobel", "Oscar", "Norbert", "Emmy", "Pulitzer" }
    	},
    };

    int t[s]; for(int i=0;i<s;i++){t[i]=i;}
    int *u = urutan(t);

    srand(time(0));
    string persoalan[9][6];
    for(int i=0;i<9;i++){
    	int k = (i>(s-1))?(i-(s-1)):i;
    	int m = u[k];
    	int n = rand() % 2;

    	for(int j=0;j<6;j++){
    		persoalan[i][j] = banksoal[m][n][j];
    	}
    }

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
	cin.ignore();
	taktik(persoalan);
	gantibaris(); ucp("---\n");
	ucp("Menu Permainan:\n");
	ucp("1. Main Lagi\n");
	ucp("2. Menu Utama\n");
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
