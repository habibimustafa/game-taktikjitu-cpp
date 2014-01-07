/* Fungsi Pertanyaan
 * Creator  : Habibi Mustafa
 * Date     : 3/1/2014
 * Updated  : 4/1/2014
 */

#include </home/habibi/Desktop/CPlus/9/hd-tool.h>
#include <cstdlib>  // untuk srand() dan rand()
#include <ctime>    // untuk time()

// acak pilihan jawaban
string * acakpilihan(string opsi[5]){
    srand(time(0)); int s = 5;
    for (int i=0; i<(s-1); i++) {
        int r = i + (rand() % (s-i));
        string temp = opsi[i];
        opsi[i] = opsi[r];
        opsi[r] = temp;
    }

    return opsi;
}

// cetak pertanyaan dan pilihan
void cetaksoal(string pertanyaan, string opsi[5]){
    string abcd[5] = { "A. ", "B. ", "C. ", "D. ", "E. " };
    ucp("\n\n", pertanyaan);
    for (int c=0; c<5; c++) {
        ucp(opsi[c], abcd[c], "\n");
    }
    gantibaris();
}

// minta jawaban
int mintajawaban(){
    int p; string jwb;
    tn: jwb = tny("Jawaban (A/B/C/D/E):");
    if ( (jwb=="A") || (jwb=="a") ) { p = 0; }
    else if ( (jwb=="B") || (jwb=="b") ) { p=1; }
    else if ( (jwb=="C") || (jwb=="c") ) { p=2; }
    else if ( (jwb=="D") || (jwb=="d") ) { p=3; }
    else if ( (jwb=="E") || (jwb=="e") ) { p=4; }
    else { goto tn; }

    return p;
}

// tampilkan soal
// data[0] = pertanyaan; data[1] = jawaban benar
// data[2] s/d data[5] = jawaban salah
bool soal(string data[6]){
    string pertanyaan  = data[0];
    string jawaban[5]  = { data[1], data[2], data[3], data[4], data[5] };

    string *opsi = acakpilihan(jawaban);
    cetaksoal(pertanyaan, opsi);
    int p = mintajawaban();

	if(opsi[p] == data[1]) return true;
	else return false;
}

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