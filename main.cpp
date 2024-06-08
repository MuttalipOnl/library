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
        cout << "Dosya açýlamadý!" << endl;
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
    cout << "\nBaþka Kitap Eklemek Ýçin 1'e Basýn.\nMenüye Dönmek Ýçin 2'e Basýn\n";
    cout << "\n\t\t\tSeçiminiz : ";
    cin >> s;
    if (s == 1) {
        kitapEkle();
    } else if (s == 2) {
        mains();
    } else {
        cout << "\nLütfen Listeden Seçim Yapýnýz. Menüye Yönleniriliyorsunuz";
        Sleep(1500);
        mains();
    }
}

void kitapSil() {
    string silinecekKitapAdi;
    system("cls");

    cout << "Silmek Ýstediðiniz Kitap Adýný Girin : ";
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
        cout << "\nBöyle Bir Kitap Yok.";
    }

    cout << "\nMenüye Dönmek Ýçin Herhangi Bir Tuþa Basýn.";
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

    cout << "Menüye Dönmek Ýçin Herhangi Bir Tuþa Basýn.";
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

    cout << "Menüye Dönmek Ýçin Herhangi Bir Tuþa Basýn.";
    getch();
    mains();
}

void kitapSayi() {
    system("cls");
    cout << endl << "Kütüphanemizde " << kitaplar.size() << " Tane Kitap Vardýr.\n\n";
    cout << "Menüye Dönmek Ýçin Herhangi Bir Tuþa Basýn.";
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
	cout<<  "\t\t\t                    Giriþ Ekraný                     \n\n\n";
	cout<<  "\t\t\t------------------------Menü-------------------------\n\n\n";
	cout<<  "\n\n";	
	cout<<  "\t| Giriþ Ýçin 1'e Basýn                      |"<<endl;
	cout<<  "\t| Kayýt Ýçin 2'e Basýn                      |"<<endl;
	cout<<  "\t| Þifre Bulmak Ýçin 3'e Basýn               |"<<endl;
	cout<<  "\t| Çýkýþ Ýçin 4'e Basýn                      |"<<endl;
	cout<<  "\n\t\t\t Lütfen Seçim Yapýn : ";
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
			cout<<"\t\t\t  Teþekkürler! \n\n\n";
			exit(0);
			break ; 
			
		default:
			system("cls");
			cout<<"\t\t\t  Lütfen Listeden Bir Seçim Yapýn..! \n\n\n";
			main();
	}
		
}


void giris(){
	int s = 0;
	string kadi,sifre,id,pass;
	system("cls");
	cout<<"\t\t\t  Lütfen Kullanýcý Adý ve Þifrenizi Girin : "<<endl;
	cout<<"\t\t\t  Kullanýcý Adý : ";
	cin>>kadi;
	
	cout<<"\t\t\t  Þifre : ";
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
		cout<<"\t\t\t\t\tBaþarýlý Bir Þekilde Giriþ Yapýldý. \n\n";
 
		 mains();
 	 
  
	}else{
		cout<<"\t\t\t\n\nGiriþ Yapýlamadaý... Lütfen Kullanýcý Adý ve Þifrenizi Kontrol Ediniz. \n\n";
		cout<<"Menüye Dönmek Ýçin Herhangi Bir Tuþa Basýn.";
		getch();
		main();
	}


	
}
void kayit(){
	int s=0,ss;
	string kkadi,ksifre,kid,kpass;
	system("cls");
	cout<<"\t\t\t  Kullanýcý Adý : ";
	cin>>kkadi;
		
	cout<<"\t\t\t  Þifre : ";
	cin>>ksifre;
	
	
	ifstream f3("giris.txt");
	while(f3>>kid>>kpass){
		if(kid==kkadi){
			s=1;
		}
	}
	f3.close();
	if(s==1){
		cout<<"\nBu Kullanýcý Adý Kullanýlmakta\nBaþka Bir Kullanýcý Adý Denemek için 1'e basýn\nMenüye Dönmek Ýçin 2'e Basýn\n";
		cout<<"\n\t\t\tSeçiminiz : ";
		cin>>ss;
		if(ss==1){
			kayit();
		}else if (ss==2){
			system("cls");
 			 main();
		}else{
			cout<<"Lütfen Listeden Seçim Yapýnýz. Kayýt Formuna Yönlendiriliyorsunuz.";
			Sleep(4000);
			kayit();
		}
	

}
else{

	ofstream f1("giris.txt", ios::app); //(Veri ekleme modu)
	f1<<kkadi<<' '<<ksifre<<endl;
	system("cls");
	
	cout<<"\n\t\t\t\t Baþarýlý Bir Þekilde Kayýt Yapýldý. \n";
	main();
	}
}

void degis(){
	
	int secenek;
	system("cls");
	cout<<"Kullanýcý Adý Ýle Bulmak Ýçin 1'e Basýn"<<endl;
	cout<<"Menüye Dönmek Ýçin 2'e Basýn"<<endl;	
	cout<<"\t\t\t  Seçiminiz : ";
	cin>>secenek;
	switch(secenek){
		
		case 1:
			{
			
			int s=0;
			string dkadi,dsifre,did,dpass;
			cout<<"\t\t\t  Kullanýcý Adýnýzý Girin : ";
			cin>>dkadi;
			
			
			ifstream f2("giris.txt");
			while(f2>>did>>dpass){
				if(did==dkadi){
					s=1;
				}
			}
			f2.close();
			if(s==1){
			cout<<"\n Hesabýnýz Bulundu \n";
			cout<<"\n Þifreniz : "<<dpass<<endl;
			Sleep(4000);
			main();
			}else{
				cout<<"\n\t Hesabýnýz Bulunamadý \n";
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
				cout<<"\t\t\t Lütfen Tekrar Deneyin"<<endl;
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
			"\t\t\t5-Kitap Sayýsý \n"<<
			"\t\t\t6-Kullanýcý Deðiþtir \n"<< 
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
 			cout<<"\nLütfen Listeden Seçim Yapýnýz \n";
		 } 
 	} 
  
  
 	system("pause");
 }

