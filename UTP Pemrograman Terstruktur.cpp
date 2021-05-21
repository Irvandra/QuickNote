#include <iostream>
#include <algorithm>

using namespace std;

class MyNote{
public:
    string note[100];
    string judul;
    int totalNote = 0;
    MyNote *nextNote;

    MyNote(string _judul){
        judul = _judul;
    }
    
    void SaveNote(string _text){
        note[totalNote] = _text;
        totalNote++;
	}

    void ShowNote(){
        cout << "------------------------------" << judul << "------------------------------" << endl << endl;

        for (int i = 0; i < totalNote; i++)
        {
            cout << note[i] << endl;
        }        
    }
};

MyNote *myHeadNote;
int totalMyNote;

void init(){
    myHeadNote = NULL;
    totalMyNote = 0;
}

bool IsEmpty(){
    if(myHeadNote == NULL){
        return true;
    }

    return false;
}

void BukaNote(string _judul){
    MyNote *myNote;
    int totalNote;

    myNote = myHeadNote;

    while (myNote -> judul != _judul)
    {
        myNote = myNote -> nextNote;
    }
    
    if(myNote -> judul == _judul){
        cout << "------------------------------" << myNote -> judul << "------------------------------" << endl << endl;

        totalNote = myNote -> totalNote;

        for (int i = 0; i < totalNote; i++)
        {
            cout << myNote -> note[i] << endl;
        }
    }
}

void HapusNote(){
    cout << "Terhapus" << endl;
}

void TulisNote(){
    cout << "------------------------------My Note------------------------------" << endl << endl;
    cout << "Maks 100 baris" << endl;
    cout << "Tulis 'END' dibaris terakhir untuk menyimpan!" << endl << endl;

    MyNote *myNote, *findLastNote;
    string note[100];
    string judul, text;
    int totalNote = 0;
    int pilihan;

    cout << "Judul Note : "; cin >> judul;
    cout << "My Note : " << endl;
    
    cin.ignore();
    myNote = new MyNote(judul);
    
    for (int i = 0; i < 100; i++)
    {
        getline(cin, text);
        
        note[i] = text;
        myNote -> SaveNote(text);
        totalNote = i;

        if(i == 98){
            note[i] = "END";
            cout << "END" << endl;
        }else if(text == "END"){
            i = 100;
        }
    }
    
    myNote -> nextNote = NULL;

    if(IsEmpty()){
        myHeadNote = myNote;
        myHeadNote -> nextNote = NULL;    
    }else{
        findLastNote = myHeadNote;

        while (findLastNote -> nextNote != NULL)
        {
            findLastNote = findLastNote -> nextNote;
        }
        
        findLastNote -> nextNote = myNote;    
    }

    cout << "Note tersimpan!" << endl;
    cin.get();
    system("CLS");
    
    myNote -> ShowNote();

    cout << endl;
    cout << "1. Hapus Note" << endl;
    cout << "2. Kembali ke Menu" << endl;
    cout << "Pilihan anda : "; cin >> pilihan;

    if(pilihan == 1){
        HapusNote();
    }else{
    	totalMyNote++;
	}
}

void BukaNoteList(){
    MyNote *myNote;
	int pilihanNote = 0;
	string simpan[totalMyNote];
    cout << "------------------------------Note List------------------------------" << endl << endl;
    if(IsEmpty()){
    	cout << "Belum Ada Note";
	}
	else {
		MyNote *bantu;
    
    bantu = myHeadNote;

    if(!IsEmpty()){
        if(bantu -> nextNote == NULL){
            cout << pilihanNote + 1 << ". " <<bantu -> judul << endl;
            cout << "Pass" << endl;
            simpan[pilihanNote] = bantu -> judul;
        }else{
            while(bantu != NULL){
                cout << pilihanNote + 1 << ". "<< bantu -> judul << endl;
                cout << "Pass2" << endl;
				simpan[pilihanNote] = bantu -> judul;
				bantu = bantu -> nextNote;
                pilihanNote++;
            }
            
        }
    }
//		while(myNote -> judul != NULL){
//			i++;
//    		cout << i << ". " << myNote -> judul << endl;
//    		myNote = myNote -> nextNote;
//		}
		cout << "Masukan Nomor Note untuk Membuka :";
		cin >> pilihanNote;
		BukaNote(simpan[pilihanNote - 1]);
//		for(int i = 0; i < myNote -> totalNote; i++){
//    		myNote = myNote -> nextNote;
//    		if(i == pilihan){
//    			cout << myNote -> note;
//			}
//		}
		
	}
}

void CariNote(){
    cout << "------------------------------Find Note------------------------------" << endl << endl;
}

int main(){
    int pilihan;

    do
    {
        system("CLS");

	    cout << "------------------------------Quick Note------------------------------" << endl << endl;
        cout << "0. Keluar" << endl;
        cout << "1. Tulis Note" << endl;
        cout << "2. Buka Note List" << endl;
        cout << "3. Cari Note" << endl;

        cout << "Pilihan anda : "; cin >> pilihan;
        system("CLS");

        switch (pilihan)
        {
            case 1:
                TulisNote();
                break;
            
            case 2:
                BukaNoteList();
                break;
                
            case 3:
                CariNote();
                break;
                
            default:
                return 0;
                break;
        }
    } while (pilihan == 1 || pilihan == 2 || pilihan == 3);    
}
