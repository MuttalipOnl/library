#include <iostream> 
#include <fstream> 
#include <string> 
#include <iomanip> 
#include <conio.h>
#include <windows.h>
#include <ctime>
  
 using namespace std; 
 
void mains();
  
struct Kitap {
    string kitapAdi;
    string yazarAdi;
    string yayinTarihi;
};

vector<Kitap> kitaplar;

void kitaplariDosyayaYaz() {
    ofstream dosya("kitaplik.txt", ios::out);
    if (dosya.is_open()) {
        for (const auto& kitap : kitaplar) {
            dosya << kitap.kitapAdi << " " << kitap.yazarAdi << " " << kitap.yayinTarihi << endl;
        }
        dosya.close();
    } else {
        cout << "Dosya a��lamad�!" << endl;
    }
}

void kitapEkle() {
    int s;
    Kitap yeniKitap;
    system("cls");

    cout << endl << "-----------------------------------------------------" << endl;
    cout << endl << "---------'Kitap_Adi, Yazar_Adi, 01.01.2001'----------" << endl;
    cout << endl << "-----------------------------------------------------" << endl;
    fflush(stdin);
    cout << "Kitap Adi : ";
    getline(cin, yeniKitap.kitapAdi);
    fflush(stdin);

    cout << "Yazar Adi : ";
    getline(cin, yeniKitap.yazarAdi);
    fflush(stdin);

    cout << "Yayin Tarihi : ";
    getline(cin, yeniKitap.yayinTarihi);
    fflush(stdin);

    kitaplar.push_back(yeniKitap);
    kitaplariDosyayaYaz();

    cout << endl << "--------------------Kitap Eklendi--------------------" << endl << endl;
    cout << "\nBa�ka Kitap Eklemek ��in 1'e Bas�n.\nMen�ye D�nmek ��in 2'e Bas�n\n";
    cout << "\n\t\t\tSe�iminiz : ";
    cin >> s;
    if (s == 1) {
        kitapEkle();
    } else if (s == 2) {
        mains();
    } else {
        cout << "\nL�tfen Listeden Se�im Yap�n�z. Men�ye Y�nleniriliyorsunuz";
        Sleep(1500);
        mains();
    }
}

void kitapSil() {
    string silinecekKitapAdi;
    system("cls");

    cout << "Silmek �stedi�iniz Kitap Ad�n� Girin : ";
    cin.ignore();
    getline(cin, silinecekKitapAdi);
    
    auto it = remove_if(kitaplar.begin(), kitaplar.end(), [&](Kitap& kitap) {
        return kitap.kitapAdi == silinecekKitapAdi;
    });

    if (it != kitaplar.end()) {
        kitaplar.erase(it, kitaplar.end());
        kitaplariDosyayaYaz();
        cout << "\nKitap Silindi.";
    } else {
        cout << "\nB�yle Bir Kitap Yok.";
    }

    cout << "\nMen�ye D�nmek ��in Herhangi Bir Tu�a Bas�n.";
    getch();
    mains();
}


void kitapAra() {
    string kitapAdi;
    system("cls");
    cout << "Aranacak Kitap Adini Girin : ";
    cin >> kitapAdi;
    fflush(stdin);

    bool kitapBulundu = false;

    for (const auto& kitap : kitaplar) {
        if (kitap.kitapAdi == kitapAdi) {
            cout << "--------------------------------------------------------------------------------------------------" << endl;
            cout << "Kitap Adi : " << setw(25) << left << kitap.kitapAdi;
            cout << "Yazar Adi : " << setw(25) << left << kitap.yazarAdi;
            cout << "Yayin Tarihi : " << setw(25) << left << kitap.yayinTarihi;
            cout << endl;
            cout << "--------------------------------------------------------------------------------------------------" << endl << endl;
            kitapBulundu = true;
            break;
        }
    }

    if (!kitapBulundu) {
        cout << endl << "Aranan kitap bulunamadi!" << endl << endl;
    }

    cout << "Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n.";
    getch();
    mains();
}

void kitaplariListele() {
    int m = 1;
    system("cls");

    cout << endl << "--------------------------------------------------------------------------------------------------" << endl;
    for (const auto& kitap : kitaplar) {
        cout << m << ". Kitap Adi : " << setw(25) << left << kitap.kitapAdi;
        cout << "Yazar Adi : " << setw(25) << left << kitap.yazarAdi;
        cout << "Yayin Tarihi : " << setw(25) << left << kitap.yayinTarihi;
        cout << endl;
        m++;
    }
    cout << "--------------------------------------------------------------------------------------------------" << endl << endl;

    cout << "Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n.";
    getch();
    mains();
}

void kitapSayi() {
    system("cls");
    cout << endl << "K�t�phanemizde " << kitaplar.size() << " Tane Kitap Vard�r.\n\n";
    cout << "Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n.";
    getch();
    mains();
}

void dosyadanKitaplariOku() {
    ifstream dosya("kitaplik.txt", ios::in);
    if (dosya.is_open()) {
        Kitap kitap;
        while (dosya >> kitap.kitapAdi >> kitap.yazarAdi >> kitap.yayinTarihi) {
            kitaplar.push_back(kitap);
        }
        dosya.close();
    }
}

 
void giris();
void kayit();
void degis();

  
 int main() {
	
	setlocale(LC_ALL, "Turkish");
	dosyadanKitaplariOku();
	system("CLS");
	time_t now = time(NULL);
    struct tm *now_detay = localtime(&now);
    char zaman[100];
    strftime(zaman, sizeof(zaman), "%a %d/%m/%Y %H:%M:%S", now_detay);
    cout<<zaman<<endl;
	

	
	int c;
	cout<< 	"\t\t\t-----------------------------------------------------\n\n\n";
	cout<<  "\t\t\t                    Giri� Ekran�                     \n\n\n";
	cout<<  "\t\t\t------------------------Men�-------------------------\n\n\n";
	cout<<  "\n\n";	
	cout<<  "\t| Giri� ��in 1'e Bas�n                      |"<<endl;
	cout<<  "\t| Kay�t ��in 2'e Bas�n                      |"<<endl;
	cout<<  "\t| �ifre Bulmak ��in 3'e Bas�n               |"<<endl;
	cout<<  "\t| ��k�� ��in 4'e Bas�n                      |"<<endl;
	cout<<  "\n\t\t\t L�tfen Se�im Yap�n : ";
	cin>>c;
	cout<<endl;
	
	switch(c){
		case 1:
			giris();
			break;	
		
		case 2:
			kayit();
			break;
			
		case 3:
			degis();
			break;
		
		case 4:
			cout<<"\t\t\t  Te�ekk�rler! \n\n\n";
			exit(0);
			break ; 
			
		default:
			system("cls");
			cout<<"\t\t\t  L�tfen Listeden Bir Se�im Yap�n..! \n\n\n";
			main();
	}
		
}


void giris(){
	int s = 0;
	string kadi,sifre,id,pass;
	system("cls");
	cout<<"\t\t\t  L�tfen Kullan�c� Ad� ve �ifrenizi Girin : "<<endl;
	cout<<"\t\t\t  Kullan�c� Ad� : ";
	cin>>kadi;
	
	cout<<"\t\t\t  �ifre : ";
	cin>>sifre;
	
	
	ifstream input("giris.txt");
	
	while(input>>id>>pass){
		if(id==kadi && pass==sifre){
			s=1;
			system("cls");
		}
		
	}
	input.close();
	
	if(s==1){
		cout<<"\t\t\t\t\tBa�ar�l� Bir �ekilde Giri� Yap�ld�. \n\n";
 
		 mains();
 	 
  
	}else{
		cout<<"\t\t\t\n\nGiri� Yap�lamada�... L�tfen Kullan�c� Ad� ve �ifrenizi Kontrol Ediniz. \n\n";
		cout<<"Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n.";
		getch();
		main();
	}


	
}
void kayit(){
	int s=0,ss;
	string kkadi,ksifre,kid,kpass;
	system("cls");
	cout<<"\t\t\t  Kullan�c� Ad� : ";
	cin>>kkadi;
		
	cout<<"\t\t\t  �ifre : ";
	cin>>ksifre;
	
	
	ifstream f3("giris.txt");
	while(f3>>kid>>kpass){
		if(kid==kkadi){
			s=1;
		}
	}
	f3.close();
	if(s==1){
		cout<<"\nBu Kullan�c� Ad� Kullan�lmakta\nBa�ka Bir Kullan�c� Ad� Denemek i�in 1'e bas�n\nMen�ye D�nmek ��in 2'e Bas�n\n";
		cout<<"\n\t\t\tSe�iminiz : ";
		cin>>ss;
		if(ss==1){
			kayit();
		}else if (ss==2){
			system("cls");
 			 main();
		}else{
			cout<<"L�tfen Listeden Se�im Yap�n�z. Kay�t Formuna Y�nlendiriliyorsunuz.";
			Sleep(4000);
			kayit();
		}
	

}
else{

	ofstream f1("giris.txt", ios::app); //(Veri ekleme modu)
	f1<<kkadi<<' '<<ksifre<<endl;
	system("cls");
	
	cout<<"\n\t\t\t\t Ba�ar�l� Bir �ekilde Kay�t Yap�ld�. \n";
	main();
	}
}

void degis(){
	
	int secenek;
	system("cls");
	cout<<"Kullan�c� Ad� �le Bulmak ��in 1'e Bas�n"<<endl;
	cout<<"Men�ye D�nmek ��in 2'e Bas�n"<<endl;	
	cout<<"\t\t\t  Se�iminiz : ";
	cin>>secenek;
	switch(secenek){
		
		case 1:
			{
			
			int s=0;
			string dkadi,dsifre,did,dpass;
			cout<<"\t\t\t  Kullan�c� Ad�n�z� Girin : ";
			cin>>dkadi;
			
			
			ifstream f2("giris.txt");
			while(f2>>did>>dpass){
				if(did==dkadi){
					s=1;
				}
			}
			f2.close();
			if(s==1){
			cout<<"\n Hesab�n�z Bulundu \n";
			cout<<"\n �ifreniz : "<<dpass<<endl;
			Sleep(4000);
			main();
			}else{
				cout<<"\n\t Hesab�n�z Bulunamad� \n";
				main();
			}
			break;
		}
	
		case 2:
			{
                Sleep(4000);
				main();
				break;
		}
				
		default:
				cout<<"\t\t\t L�tfen Tekrar Deneyin"<<endl;
				Sleep(1500);
				degis();
	}	
}
void mains(){
 			int secim;
 		while (1) 
 	{ 
 	setlocale(LC_ALL, "Turkish");
 	dosyadanKitaplariOku();
	system("CLS");
	time_t now = time(NULL);
    struct tm *now_detay = localtime(&now);
    char zaman[100];
    strftime(zaman, sizeof(zaman), "%a %d/%m/%Y %H:%M:%S", now_detay);
    cout<<zaman<<endl<<endl;
    
    
 		cout <<   
 			"\t\t\t-----------------------------------------------------\n\n"<<
 			"\t\t\t1-Kitap Ekle \n" << 
 			"\t\t\t2-Kitap Sil \n" << 
 			"\t\t\t3-Kitaplari Ara \n" <<
			"\t\t\t4-Kitap Listele \n"<<
			"\t\t\t5-Kitap Say�s� \n"<<
			"\t\t\t6-Kullan�c� De�i�tir \n"<< 
 			"\n\t\t\t-----------------------------------------------------\n"<<
			"\t\t\tLutfen seciminizi girin : ";
 		cin >> secim; 

 		if (secim == 1) 
 		{ 
 			 kitapEkle(); 
 		} 
 		else if (secim == 2) 
 		{ 
 			 kitapSil();
 		} 
 		else if (secim == 3) 
 		{ 
 			 kitapAra(); 
 		}
 		else if (secim == 4) 
 		{ 
 			 kitaplariListele();
 		}
 		else if (secim == 5) 
 		{ 
 			 kitapSayi();
 		}
 		else if (secim == 6) 
 		{ 
 			 system("cls");
 			 main();
 		}
		 else{
 			cout<<"\nL�tfen Listeden Se�im Yap�n�z \n";
		 } 
 	} 
  
  
 	system("pause");
 }

