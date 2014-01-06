/* Fungsi Bantuan
 * Creator      : Habibi Mustafa
 * Date         : 3/1/2014
 */

#include <iostream> // untuk cin() dan cout()
#include <stdlib.h> // untuk system()
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
