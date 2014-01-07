/* Program Tugas Akhir (Game Kuis Taktik Jitu)
 * Creator	: Habibi Mustafa
 * Date		: 27/12/2013
 * Updated	: 6/1/2014
 */

// My Own Header
#include </home/habibi/Desktop/CPlus/9/hd-main.h>

int main()
{
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
	aturan(); cin.ignore();
	tny("Tekan 'enter' untuk kembali ke menu utama!");
	goto mulai;

	// mulai bermain
	play:
	cin.ignore();
	permainan();
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
