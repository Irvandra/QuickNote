#include <iostream>
//#include <algorithm>
#include <cstring>

using namespace std;

class MyNote{
public:
    string note[100];
    string judul;
    int totalBarisNote = 0;
    MyNote *nextNote;

    MyNote(string _judul){
        judul = _judul;
    }
    
    void SaveNote(string _text){
        note[totalBarisNote] = _text;
        totalBarisNote++;
	}

    void ShowNote(){
        cout << "------------------------------" << judul << "------------------------------" << endl << endl;

        for (int i = 0; i < totalBarisNote; i++)
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

void HapusNote(MyNote *_myNote){
    MyNote *temp;
    temp = myHeadNote;

    if (temp -> nextNote == NULL)
    {
        delete _myNote;
    
        myHeadNote = NULL;
    }else{    
        while (temp -> nextNote != NULL)
        {
            if(temp -> nextNote -> judul == _myNote -> judul){
                break;
            }

            temp = temp -> nextNote;
        }

        temp -> nextNote = temp -> nextNote -> nextNote;
        delete _myNote;
    }    

    cout << "Note terhapus!" << endl;

    totalMyNote--;
    
    cin.ignore();
    cin.get();
}

void BukaNote(string _judul){
    MyNote *myNote;
    int totalNote, pilihan;

    myNote = myHeadNote;

    while (myNote -> judul != _judul)
    {
        myNote = myNote -> nextNote;
    }
    
    if(myNote -> judul == _judul){
        cout << "------------------------------" << myNote -> judul << "------------------------------" << endl << endl;

        totalNote = myNote -> totalBarisNote;

        for (int i = 0; i < totalNote; i++)
        {
            cout << myNote -> note[i] << endl;
        }
    }
    
    	
    cout << endl;
    cout << "1. Hapus Note" << endl;
    cout << "2. Kembali ke Menu" << endl;
    cout << "Pilihan anda : "; cin >> pilihan;
    
    if(pilihan == 1){
		HapusNote(myNote);
	}
}

void TulisNote(){
    cout << "------------------------------My Note------------------------------" << endl << endl;
    cout << "Maks 100 baris" << endl;
    cout << "Tulis 'END' dibaris terakhir untuk menyimpan!" << endl << endl;

    MyNote *myNote, *findLastNote;
    string note[100];
    string judul, text;
    int pilihan;

    cout << "Judul Note : ";
	cin.ignore();
	getline(cin, judul);
    cout << "My Note : " << endl;
    
    myNote = new MyNote(judul);
    
    for (int i = 0; i < 100; i++)
    {
        getline(cin, text);
        
        note[i] = text;
        myNote -> SaveNote(text);

        if(i == 98){
            note[i + 1] = "END";
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
        HapusNote(myNote);
    }else{
    	totalMyNote++;
	}
}

void BukaNoteList(){
    MyNote *myNote;
	int pilihanNote = 0, pilihan;
	string simpan[totalMyNote];
    string *ptrSimpan[totalMyNote];
    cout << "------------------------------Note List------------------------------" << endl << endl;
    
	if(IsEmpty()){
    	cout << "Belum Ada Note" << endl;
        cin.ignore();
        cin.get();
	}
	else {
		MyNote *bantu;
    	bantu = myHeadNote;
    	
		if(!IsEmpty()){
        	if(bantu -> nextNote == NULL){
            	cout << pilihanNote + 1 << ". " << bantu -> judul << endl;
            	simpan[pilihanNote] = bantu -> judul;
        	}else{
            	while(bantu != NULL){
                	cout << pilihanNote + 1 << ". "<< bantu -> judul << endl;
					simpan[pilihanNote] = bantu -> judul;
					bantu = bantu -> nextNote;
                	pilihanNote++;
            	}
                
                for (int i = 0; i < totalMyNote; i++)
                {
                    ptrSimpan[i] = &simpan[i];
                }
        	}
    	}        

		cout << "\nMasukan Nomor Note untuk Membuka :";
		cin >> pilihanNote;
		system("cls");
	
		BukaNote(*ptrSimpan[pilihanNote - 1]);
	}
}

void CariNote(){
    cout << "------------------------------Find Note------------------------------" << endl << endl;
    MyNote *myNote;
    string judul;
    bool ditemukan = false;

    myNote = myHeadNote;

	cin.ignore();
    getline(cin, judul);

    while (myNote != NULL)
    {
        if (strcmp(judul.c_str(), myNote -> judul.c_str()) == 0)
        {
        	ditemukan = true;
            break;
        }
        

        myNote = myNote -> nextNote;
    }
    
    if(ditemukan){
        system("CLS");
        BukaNote(judul);

        int pilihan;

        cout << endl;
        cout << "1. Hapus Note" << endl;
        cout << "2. Kembali ke Menu" << endl;
        cout << "Pilihan anda : "; cin >> pilihan;

        if(pilihan == 1){
            HapusNote(myNote);
        }
	}else{
		cout << "Judul tidak ditemukan!" << endl;
    
        cin.get();
	}
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
