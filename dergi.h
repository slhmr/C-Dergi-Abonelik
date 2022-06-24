#ifndef DERGI_h
#define DERGI_h

class dergi{													//dergi isminde bir class oluþturduk
     public:														
         string dadi;
         string dko;

		 void dekle(){   //Ýstenilen derginin kaydedildiði fonksiyondur.
		 	  int mev=0;   //fonksiyon içindeki deðiþkenleri tanýmladýk
		 	  string adi,konu;
    	 	  ofstream d_ekle("kayitli_dergiler.txt",ios::app); //çýkýþ dosyasý oluþtur ve çýkýþýn tamamýný dosyaya ekle
    		  if(!d_ekle){       //dergi ekleme iþleminde dosya açýlamassa hata raporu ver.
        	  			  cout<<"Ýslem basarisiz..."<<endl;
        				  exit(1);
    					  }
	          ifstream kontrol1("kayitli_dergiler.txt",ios::in);   //in deðeri dosyanýn giriþe uygun olduðunu belirler
	          if(!kontrol1){
              				cerr<<"Ýslem basarisiz..."<<endl;
                            exit(1);
							}
              system("cls");
   			  cout<<"Ekleyeceginiz Derginin Adini Giriniz."<<endl;
   			  getline(cin,adi);   //girilen karakterleri büyültmekiçin kullandýðým kod satýrý
    		  getline(cin,adi);   //while döngüsünün sonuna kadar girilen adý büyütür.
    		  int s=0;			 
     		  while(adi[s]){
              				 adi[s]=toupper(adi[s]);
            				 s++;
     						 }
              cout<<"Ekleyeceginiz Derginin Konusunu Giriniz."<<endl;
              getline(cin,konu); //girilen karakterleri büyültmekiçin kullandýðým kod satýrý
     		  int a=0;			 //while döngüsünün sonuna kadar girilen adý büyütür.
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
    		 if(mev==0){		// mev 0'a eþitse dergi adý ve konusu txt dosyasýna aktarýlýr.
        	 			dadi=adi;
        				dko=konu;       
        				d_ekle<<dadi<<' '<<dko<<endl;
        				cout<<endl<<"Girmis Oldugunuz Dergi Sisteme Basariyla Eklendi..\n\n\n";
        				}       
           if(mev!=0){	//eþit deðilse dergi sistemde mevcut olduðu için hata raporu verir.
           				  system("cls");
        				  cout<<"Girmis Olduðunuz Dergi Sisteme Onceden Kayýtlýdýr...\a\n\n\n";
     					 }                                      
              }

      void dliste(){						//dergi listeleme fonksiyonumuz
  	  	   ifstream d_liste("kayitli_dergiler.txt",ios::in);			//kayýtlý_dergiler.txt dosyasýný aç
    	   if(!d_liste){			//dergiler txt dosyasýnda veri bulamazsa hata raporu gelir.
						cout<<"Ýslem basarisiz..."<<endl;
        				exit(1);
    					}
          system("cls");			//ekraný temizler.
    	  cout<<endl<<left<<setw(22)<<"Dergi Adi"<<setw(22)<<"Dergi Konusu"<<endl<<fixed<<showpoint;		//derginin adý için sola 20 karakter dergi konusu için sola 20 karakterlik boþluk býrakýr 
    	  while(d_liste>>dadi>>dko)
		  cout<<left<<setw(22)<<dadi<<setw(22)<<dko<<right<<endl<<fixed<<showpoint;	//kayýtlý dergileri belirtilen aralýklarda yazar
				} 
      void dara(){	//dergi arama iþleminin gercekleþtirdiðimiz fonksýyonumuz
		   system("cls");			//ekraný temizler.
   	   	   string kn;   //fonksiyon için de kullanacaðýmýz deðiþkenleri tanýmladýk.
		   cout<<"Hangi Konudaki Dergileri Gormek Istiyorsunuz.?"<<endl;  
	 	   getline(cin,kn);	//girilen karakterleri büyültmekiçin kullandýðým kod satýrý
		   getline(cin,kn);	//while döngüsünün sonuna kadar girilen adergi konusunu büyütür.
   		   int i=0;
   		   while(kn[i]){
  						kn[i]=toupper(kn[i]);
   						i++;
    					}    
	 	   ifstream d_ara("kayitli_dergiler.txt",ios::in);	//kayýtlý_dergiler.txt dosyasýný aç ve in deðeri dosyanýn giriþe uygun olduðunu belirler
    	   if(!d_ara){
				   	  cout<<"Ýslem basarisiz..."<<endl;
           			  exit(1);
    	   		   	  } 
		  cout<<endl<<endl<<left<<setw(22)<<"Dergi Adi"<<setw(22)<<"Dergi Konusu"<<endl<<fixed<<showpoint;
    	  while(d_ara>>dadi>>dko) {   
		  						  if(kn==dko){   //kn dergi konusuna eþitse listelemyi yapar dergi adý için 20 karakter dergi konusu için 20 karakter býrakara
  				  			                 cout<<left<<setw(22)<<dadi<<setw(22)<<dko<<right<<endl<<fixed<<showpoint;
										      }
				                  }  
	      d_ara.close();   
	      cin.get();   

}          
void dsil(){		//dergi silme fonksiyonumuz
    string dg;
	int w=0;  		//fonksiyon içindeki deðiþkenleri tanýmladýk
	system("cls");  	//ekraný temizleyip
	dliste();
	cout<<"Silmek istediginiz dergi adini giriniz...."<<endl;
	getline(cin,dg);// kod satýrý girilen karakterleri buyuk harfe donustürme 
    getline(cin,dg);	//iþlemi için kullanýlýr,While döngüsünün sonuna kadar silinecek dergi adýný büyütür .
    int i=0;
    while(dg[i]){  
				   dg[i]=toupper(dg[i]);
            	   i++;
    			   }   
    ifstream d_sil("kayitli_dergiler.txt.txt",ios::in); //kayýtlý_dergiler.txt dosyasýný aç ve in deðeri dosyanýn giriþe uygun olduðunu belirler
    if(!d_sil){
        	   cout<<"Ýslem basarisiz..."<<endl;
        	   exit(1);
    			}
	ofstream y_dergi("yedek.txt",ios::out); //çýkýþ dosyasý oluþtur ve çýkýþýn tamamýný dosyaya ekle
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
