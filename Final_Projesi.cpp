/*********************************/
/* Ad� Soyad�   : Salih Emre KUL */
/* No           :  0403030050    */
/*********************************/
 
//kullanaca��m�z k�t�phaneler tan�mlan�r dosyaya yazd�rma okuma gibi
#include<iostream>	
#include<fstream>	
#include<iomanip>	
#include<string>    
#include<cstdlib>	
#include<cctype>   

using namespace std;

#include "musteri.h"	// musteri clas�n� ca��rmak i�in
#include "dergi.h"	// dergi clas�n� ca��rmak i�in 
      
      
main(){	//ana ekran c�kt�m�z
 char sec,sec1,sec2,sec3;
 musteri s; 
 dergi e; 
 cout<<"    ******************************************************************"<<endl;
 cout<<"    *                                                                *"<<endl;
 cout<<"    *          ______________ SEK PAZARLAMA ______________           *"<<endl;
 cout<<"    *                                                                *"<<endl;
 cout<<"    ******************************************************************"<<endl;
 cout<<"    *                                                                *"<<endl;
 cout<<"    *___________ ANA MENU ___________                                *"<<endl;
 cout<<"    *     *                                                          *"<<endl;
 cout<<"    *     *                                                          *"<<endl;
 cout<<"    *  1  *  DERGI ISLEMLERI                                         *"<<endl;
 cout<<"    *     *                                                          *"<<endl;
 cout<<"    *     *                                                          *"<<endl;
 cout<<"    *  2  *  MUSTERI ISLEMLERI                                       *"<<endl;
 cout<<"    *     *                                                          *"<<endl;
 cout<<"    *     *                                                          *"<<endl;
 cout<<"    *  3  *  ABONELIK ISLEMLERI                                      *"<<endl;
 cout<<"    *     *                                                          *"<<endl;
 cout<<"    *     *                                                          *"<<endl;
 cout<<"    *  4  *  CIKIS                                                   *"<<endl;
 cout<<"    *     *                                                          *"<<endl;
 cout<<"    *     *                                                          *"<<endl;
 cout<<"    ******************************************************************"<<endl;
 cout<<"    Bir Islem Seciniz..=> ";cin>>sec;      //se�im i�lemi i�in
     switch(sec){	//men�ler aras�nda ge�i� i�lemi i�in	
                 case '1':{ 
                           system("cls");
                           cout<<"                                                                      "<<endl;
                           cout<<"                                                                      "<<endl;
                           cout<<"    ___________ DERGI ISLEMLERI ______________________________________"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    *  1  *  Yeni Dergi                                              *"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    *  2  *  Dergileri Listele                                       *"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    *  3  *  Konuya Gore Dergi Listele                               *"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    *  4  *  Dergi Sil                                               *"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    *  5  *  Ana menu                                                *"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    *     *                                                          *"<<endl;
                           cout<<"    ******************************************************************"<<endl;    
                           cout<<"    Bir Islem Seciniz..=> "; 
                           cin>>sec1;
                         switch(sec1){//dergi men�s�n�n alt i�lemleri aras�nda ge�i� i�in
                                      case '1':  
                                           e.dekle();system("pause");break;	//e.dekle fonksiyonunu class i�inden �a��rma i�lmi i�in
                                           case '2':
                                                 e.dliste();system("pause");break;	//e.dlistele fonksiyonunu class i�inden �a��rma i�lmi i�in
                                                 case '3':
                                                      e.dara();system("pause");break;  //e.dara fonksiyonunu class i�inden �a��rma i�lmi i�in
                                                      case '4':
                                                           e.dsil();system("pause");break;	//e.dsil fonksiyonunu class i�inden �a��rma i�lmi i�in
                                                           case '5':
                                                                system("cls"); break;	//ekran� temizleyerek ana men�ye d�nmek i�in
                                                                default : // se�im i�lemi hatal� yap�l�rsa verilecek uyar� i�in
                                                                      cout<<"\aSeciminizi Yanlis Yaptiniz    Lutfen Tekrar Deneyin..."<<endl;system("pause");system("cls");
                                       }
                                       cout<<" "<<endl<<endl<<endl;   
                                       system("cls");                               
                                       return main();                                                               
                      }   
                                                                     
                      case '2': {	//m��teri i�lemleri aras�nda gezinmek i�in
                      system("cls");
                      cout<<"                                                                      "<<endl;
                      cout<<"                                                                      "<<endl;
                      cout<<"    ___________ MUSTERI ISLEMLERI ____________________________________"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *  1  *  Yeni Musteri                                            *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *  2  *  Musteri Bilgilerini Listele                             *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *  3  *  Musterileri Listele                                     *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *  4  *  Ana menu                                                *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    ******************************************************************"<<endl;
                      cout<<"    Bir Islem Seciniz..=> "; cin>>sec2;
                      switch(sec2){
                                  case '1':
                                       s.mekle();break;	//s.mekle fonksiyonunu class i�inden �a��rma i�lmi i�in
                                       case '2': 
                                            s.mara();system("pause");break;	//s.mara fonksiyonunu class i�inden �a��rma i�lmi i�in
                                            case '3':                          
                                                 s.mlistele();system("pause");break;	//s.mlistele fonksiyonunu class i�inden �a��rma i�lmi i�in
                                                 case '4':
                                                      system("cls");break;	//ekran� temizleyerek ana men�ye d�nmek i�in
                                                      default:	// se�im i�lemi hatal� yap�l�rsa verilecek uyar� i�in
                                                              cout<<"\aSeciminizi Yanlis Yaptiniz Lutfen Tekrar Deneyin..."<<endl;system("pause"); system("cls");
                                     }                          
                                     cout<<" "<<endl<<endl<<endl;
                                     system("cls");
                                     return main();
                 }                                    
                          
                 case '3':{	//abone i�lemlerinde gezinme i�lemimi�in 
                      system("cls");
                      cout<<"                                                                      "<<endl;
                      cout<<"                                                                      "<<endl;
                      cout<<"    ___________ ABONELIK ISLEMLERI ___________________________________"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *  1  *  Yeni Abone                                              *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *  2  *  Aboneleri Listele                                       *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *  3  *  Abone Sil                                               *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *  4  *  Ana menu                                                *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    *     *                                                          *"<<endl;
                      cout<<"    ******************************************************************"<<endl;
                      cout<<"    Bir Islem Seciniz..=> "; cin>>sec3;
                      switch(sec3){
                                  case '1':
                                       s.aekle();break;	//s.aekle fonksiyonunu class i�inden �a��rma i�lmi i�in
                                       case '2':
                                            s.alistele();system("pause");break;	//s.alistele fonksiyonunu class i�inden �a��rma i�lmi i�in
                                            case '3':
                                                 s.asil();system("pause");break;	//s.asil fonksiyonunu class i�inden �a��rma i�lmi i�in
                                                 case '4':
                                                      system("cls");break;	//ekran� temizleyerek ana men�ye d�nmek i�in
                                                      default:	// se�im i�lemi hatal� yap�l�rsa verilecek uyar� i�in
                                                              cout<<"\aSeciminizi Yanlis Yaptiniz Lutfen Tekrar Deneyin..."<<endl;system("pause");system("cls"); 
                                     }
                                     cout<<" "<<endl<<endl<<endl;
                                     system("cls"); 
                                     return main();     
                                             
                  }                     
                  case '4':{	//��k�� i�lemi i�in 
                       return 0;
                       default:	// se�im i�lemi hatal� yap�l�rsa verilecek uyar� i�in
                               system("cls");
                               cout<<"\aSeciminizi Yanlis Yaptiniz Lutfen Tekrar Deneyin..."<<endl;system("pause");system("cls");
                               return main();
                       }
     
                 } 
}   
              
    
  

