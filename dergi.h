#ifndef DERGI_h
#define DERGI_h

class dergi{													//dergi isminde bir class olu�turduk
     public:														
         string dadi;
         string dko;

		 void dekle(){   //�stenilen derginin kaydedildi�i fonksiyondur.
		 	  int mev=0;   //fonksiyon i�indeki de�i�kenleri tan�mlad�k
		 	  string adi,konu;
    	 	  ofstream d_ekle("kayitli_dergiler.txt",ios::app); //��k�� dosyas� olu�tur ve ��k���n tamam�n� dosyaya ekle
    		  if(!d_ekle){       //dergi ekleme i�leminde dosya a��lamassa hata raporu ver.
        	  			  cout<<"�slem basarisiz..."<<endl;
        				  exit(1);
    					  }
	          ifstream kontrol1("kayitli_dergiler.txt",ios::in);   //in de�eri dosyan�n giri�e uygun oldu�unu belirler
	          if(!kontrol1){
              				cerr<<"�slem basarisiz..."<<endl;
                            exit(1);
							}
              system("cls");
   			  cout<<"Ekleyeceginiz Derginin Adini Giriniz."<<endl;
   			  getline(cin,adi);   //girilen karakterleri b�y�ltmeki�in kulland���m kod sat�r�
    		  getline(cin,adi);   //while d�ng�s�n�n sonuna kadar girilen ad� b�y�t�r.
    		  int s=0;			 
     		  while(adi[s]){
              				 adi[s]=toupper(adi[s]);
            				 s++;
     						 }
              cout<<"Ekleyeceginiz Derginin Konusunu Giriniz."<<endl;
              getline(cin,konu); //girilen karakterleri b�y�ltmeki�in kulland���m kod sat�r�
     		  int a=0;			 //while d�ng�s�n�n sonuna kadar girilen ad� b�y�t�r.
     		  while(konu[a]){
              					 konu[a]=toupper(konu[a]);
            					 a++;
        						 }   
             for(int i=0;i<10;i++){
        	 		 while(kontrol1>>dadi>>dko){
            		 									   if(adi==dadi){
              											    mev+=1;
           															   }
                                                          }
                                  }
    		 if(mev==0){		// mev 0'a e�itse dergi ad� ve konusu txt dosyas�na aktar�l�r.
        	 			dadi=adi;
        				dko=konu;       
        				d_ekle<<dadi<<' '<<dko<<endl;
        				cout<<endl<<"Girmis Oldugunuz Dergi Sisteme Basariyla Eklendi..\n\n\n";
        				}       
           if(mev!=0){	//e�it de�ilse dergi sistemde mevcut oldu�u i�in hata raporu verir.
           				  system("cls");
        				  cout<<"Girmis Oldu�unuz Dergi Sisteme Onceden Kay�tl�d�r...\a\n\n\n";
     					 }                                      
              }

      void dliste(){						//dergi listeleme fonksiyonumuz
  	  	   ifstream d_liste("kayitli_dergiler.txt",ios::in);			//kay�tl�_dergiler.txt dosyas�n� a�
    	   if(!d_liste){			//dergiler txt dosyas�nda veri bulamazsa hata raporu gelir.
						cout<<"�slem basarisiz..."<<endl;
        				exit(1);
    					}
          system("cls");			//ekran� temizler.
    	  cout<<endl<<left<<setw(22)<<"Dergi Adi"<<setw(22)<<"Dergi Konusu"<<endl<<fixed<<showpoint;		//derginin ad� i�in sola 20 karakter dergi konusu i�in sola 20 karakterlik bo�luk b�rak�r 
    	  while(d_liste>>dadi>>dko)
		  cout<<left<<setw(22)<<dadi<<setw(22)<<dko<<right<<endl<<fixed<<showpoint;	//kay�tl� dergileri belirtilen aral�klarda yazar
				} 
      void dara(){	//dergi arama i�leminin gercekle�tirdi�imiz fonks�yonumuz
		   system("cls");			//ekran� temizler.
   	   	   string kn;   //fonksiyon i�in de kullanaca��m�z de�i�kenleri tan�mlad�k.
		   cout<<"Hangi Konudaki Dergileri Gormek Istiyorsunuz.?"<<endl;  
	 	   getline(cin,kn);	//girilen karakterleri b�y�ltmeki�in kulland���m kod sat�r�
		   getline(cin,kn);	//while d�ng�s�n�n sonuna kadar girilen adergi konusunu b�y�t�r.
   		   int i=0;
   		   while(kn[i]){
  						kn[i]=toupper(kn[i]);
   						i++;
    					}    
	 	   ifstream d_ara("kayitli_dergiler.txt",ios::in);	//kay�tl�_dergiler.txt dosyas�n� a� ve in de�eri dosyan�n giri�e uygun oldu�unu belirler
    	   if(!d_ara){
				   	  cout<<"�slem basarisiz..."<<endl;
           			  exit(1);
    	   		   	  } 
		  cout<<endl<<endl<<left<<setw(22)<<"Dergi Adi"<<setw(22)<<"Dergi Konusu"<<endl<<fixed<<showpoint;
    	  while(d_ara>>dadi>>dko) {   
		  						  if(kn==dko){   //kn dergi konusuna e�itse listelemyi yapar dergi ad� i�in 20 karakter dergi konusu i�in 20 karakter b�rakara
  				  			                 cout<<left<<setw(22)<<dadi<<setw(22)<<dko<<right<<endl<<fixed<<showpoint;
										      }
				                  }  
	      d_ara.close();   
	      cin.get();   

}          
void dsil(){		//dergi silme fonksiyonumuz
    string dg;
	int w=0;  		//fonksiyon i�indeki de�i�kenleri tan�mlad�k
	system("cls");  	//ekran� temizleyip
	dliste();
	cout<<"Silmek istediginiz dergi adini giriniz...."<<endl;
	getline(cin,dg);// kod sat�r� girilen karakterleri buyuk harfe donust�rme 
    getline(cin,dg);	//i�lemi i�in kullan�l�r,While d�ng�s�n�n sonuna kadar silinecek dergi ad�n� b�y�t�r .
    int i=0;
    while(dg[i]){  
				   dg[i]=toupper(dg[i]);
            	   i++;
    			   }   
    ifstream d_sil("kayitli_dergiler.txt.txt",ios::in); //kay�tl�_dergiler.txt dosyas�n� a� ve in de�eri dosyan�n giri�e uygun oldu�unu belirler
    if(!d_sil){
        	   cout<<"�slem basarisiz..."<<endl;
        	   exit(1);
    			}
	ofstream y_dergi("yedek.txt",ios::out); //��k�� dosyas� olu�tur ve ��k���n tamam�n� dosyaya ekle
   for(int i=0;i<20;i++){
	  					  while(d_sil>>dadi>>dko){  
							    					if(dg==dadi){  
						   				  	 					   w++;    
	      														 }  
	                                               }  
                            }
    if(w==0){
       system("cls");
       cout<<endl<<endl;
       cout<<"Eksik ya da yanlis dergi adi girdiniz..!\a"<<endl<<endl<<endl;
       system("pause");
    }
    if(w!=0){
       while(d_sil>>dadi>>dko){
         if(dg!=dadi){
            y_dergi<<dadi<<' '<<dko<<endl;
       }
    }
    d_sil.close();  
    y_dergi.close(); 
    ifstream devam("yedek.txt");  
    ofstream dur("kayitli_dergiler.txt");  
    dur<<devam.rdbuf();  
    cout<<endl<<"Dergi sistemden basariyla silindi..!"<<endl<<endl<<endl;
     system("pause");
	 }
}
};
#endif
