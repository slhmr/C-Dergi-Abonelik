#ifndef MUSTERI_h
#define MUSTERI_h 

#include "dergi.h"
class musteri:public dergi{ //m�steri clas� tan�mlayrak dergi clas� include ettik
    public:
       string adi1;                 //class i�indeki de�i�kenlerimizi tan�mlad�k                                             
       string soyadi1;                                                           
       string tel1;                                                         
       string adresi1;                                                             
                                           
	   void mekle(){    //m�steri ekleme i�leminin yap�ld��� fonksiyondur.
  		  string ad_k,konu_k,adi4,soyadi2,tel2,adresi2;  //fonks�yon de�i�kenlerini tan�mlad�k 
  		  int vr=0,br=0;   
  		  ofstream m_ekle("m_bilgi.txt",ios::app); //��k�� dosyas� olu�tur ve ��k���n tamam�n� dosyaya ekle
      	  if(!m_ekle){		//olmazsa hata mesaj�n� ver
   						cerr<<"Islem Basarisiz..."<<endl;
          				exit(1);
        				}
         ifstream dergi_k("kayitli_dergiler.txt",ios::in); //kay�tl�_dergiler.txt dosyas�n� a� ve (in) de�eri dosyan�n giri�e uygun oldu�unu belirler
         if(!dergi_k){    //uygun de�ilse hata mesaj�n� ver
      					cerr<<"Islem Basarisiz..."<<endl;  
          				exit(1); 
        				} 
         ifstream m_k("m_bilgi.txt",ios::in); //m_bilgi.txt dosyas�n� a� ve (in) de�eri dosyan�n giri�e uygun oldu�unu belirler
         if(!m_k){	//uygun de�ilse hata mesaj�n� ver
          			cerr<<"Islem Basarisiz..."<<endl;
        			exit(1);
     				} 
         system("cls");
         cout<<"\n\tYeni Musteri Ekleme Islemi \n\n";
         cout<<endl<<endl<<"Kaydedilecek Musterinin Adini Giriniz......: ";  //m��terinin ad�n� al�r    
         getline(cin,adi4);		//karakter b�y�ltme sat�r�m�z
     	 getline(cin,adi4);
     	 int m=0;
     	 while(adi4[m]){
         				adi4[m]=toupper(adi4[m]);
            			m++;
     					}
        cout<<"Kaydedilecek Musterinin Soyadini Giriniz...: ";    //m��terinin syad�n� al�r   
     	getline(cin,soyadi2);	//karakter b�y�ltme sat�r�m�z
		int r=0;
     	while(soyadi2[r]){
        				  soyadi2[r]=toupper(soyadi2[r]);
           				  r++;
     					  } 
	    cout<<"Kaydedilecek Musterinin Tel No Giriniz.....: ";  //m��terinin tel no al�r     
        getline(cin,tel2);	//karakter b�y�ltme sat�r�m�z
        int k=0;
        while(tel2[k]){
        			   tel2[k]=toupper(tel2[k]);
            		   k++; 
					   }
       cout<<"Kaydedilecek Musterinin Adresini Giriniz...: ";      //m��terinin adresini al�r 
       getline(cin,adresi2);	//karakter b�y�ltme sat�r�m�z
       int u=0;
       while(adresi2[u]){
        				 adresi2[u]=toupper(adresi2[u]);
            			 u++;
     					 } 
	   cout<<"Kaydedilecek Derginin Adini Giriniz........: ";   //kaydedilec derginin ad�n� al�r   
       getline(cin,ad_k);//karakter b�y�ltme sat�r�m�z
       int l=0;
       while(ad_k[l]){
        			  ad_k[l]=toupper(ad_k[l]);
            		  l++; 
					  } 
       cout<<"Kaydedilecek Derginin Konusunu Giriniz.....:";      //kaydedilec derginin konusunu al�r
       getline(cin,konu_k);//karakter b�y�ltme sat�r�m�z
       int i=0;
       while(konu_k[i]){ 
        				 konu_k[i]=toupper(konu_k[i]);
            			 i++;
     					 } 
       for(int i=0;i<40;i++){ //girilen dergi ad�n� ve konusunu dong�ye sokarak kay�tl� dergi olup olmad�klar�na 
               				  while(dergi_k>>dadi>>dko){	//dosyadan dadi ve dko okunuyor  
                			  								if((ad_k==dadi)&&(konu_k==dko)){ //e�er e�itlik bulursa vr'yi 1 art�r�r
                  																			  vr++;
           																					  }
					                                      }
                                }
       if (vr==0){ //bulamassa vr 0'a e�it olaca��ndan alttaki hata mesaj�n� verir
          		   cout<<endl<<endl<<"Yalnis Dergi Girdiniz...\n\n\n";
         		   }
       if(vr!=0){ //yukardaki d�ng�de e�itli�i bulursa vr artaca��ndan bu if ko�ulu gercekle�ir
   	   			  for(int z=0;z<5;z++){  //bu d�ng�de ise girilen m��teri ismi ile soyad�n� kontrolederek ki�inin daha �nceki abonelik say�s�n�
                  		  				 while(m_k>>adi1>>soyadi1>>tel1>>adresi1>>dadi>>dko){  //kontrol ederek hakk�n�n bitip bitmedi�ini belirlemek i�in
                    					 													   if((adi4==adi1)&&(soyadi2==soyadi1)){ //bu e�itlik varsa br'yi 1artt�r
                        																	   br++;
          																					   										 }
                                                                                            }
                                       }
       adi1=adi4;
       soyadi1=soyadi2;
       if(br==5){  //br 5'e e�it ��karsa alttaki uyar� mesaj�n� verir
          		   cout<<""<<endl<<endl<<endl;
          		   cout<<"Bu musterinin abonelik hakki dolmustur..!\a"<<endl<<endl<<endl;
            	   } 
 
       if(br!=5){ //br 5'e e�it de�ilse ekleme i�lemini gercekle�tirir
        		  dadi=ad_k;           
        		  dko=konu_k;  
        		  tel1=tel2;
        		  adresi1=adresi2;
        		  m_ekle<<adi1<<' '<<soyadi1<<' '<<tel1<<' '<<adresi1<<' '<<dadi<<' '<<dko<<endl;
        		  cout<<endl<<"Musteri Ekleme Islemi Basriyla Gerceklesti...\n\n";
           		  }   
     }
     dergi_k.close();
     m_k.close();
     m_ekle.close();
     cin.get();
}
void aekle(){  //abone ekleme  fonksiyonumuz.
    string adi2,soyadi2; 	//fonksiyon de�i�kenleri
    string adi3,konu1;
    int a=0,b=0;   
	cout<<"Abonenin Adini Ve Soyismini Giriniz...";  
    getline(cin,adi2);
    getline(cin,adi2);
    int i=0;
   	while (adi2[i]){	//adi2 while d�ng�s�ne sokularak b�y�k harfe �evrilir
         		   adi2[i]=toupper(adi2[i]); 
         		   i++;                     
        		   }                           
   ifstream ara("m_bilgi.txt",ios::in);	//m_bilgi.txt dosyas�n� a� ve (in) de�eri dosyan�n giri�e uygun oldu�unu belirler
   if(!ara){							//uygun de�ilse hata raporunu ver
        	cerr<<"Islem Basarisiz...";
        	exit(1);
    		} 
   ifstream d_ara("kayitli_dergiler.txt",ios::in);//kay�tl�_dergiler.txt dosyas�n� a� ve (in) de�eri dosyan�n giri�e uygun oldu�unu belirler
   if(!d_ara){
        	  cerr<<"Islem Basarisiz...";
        	  exit(1);
    		  } 
   ofstream a_ekle("m_bilgi.txt",ios::app);	//��k�� dosyas� olu�tur ve ��k���n tamam�n� dosyaya ekle
   if(!a_ekle){							//ekleme ba�ar�lamazsa hata raporunu ver
			cerr<<"Islem Basarisiz...";
        	exit(1);
     		}
   for(int i=0;i<5;i++){        //i=0'dan i'yi 1 artt�rarak 5 den k�c�k oluncaya kadar  alttaki i�lemleri yap.      
			            while(ara>>adi1>>soyadi1>>tel1>>adresi1>>dadi>>dko) {   //dosyadan adi1,soyadi1,tel1,adresi,dadi ve dko okunuyor  
     																		if((adi2==adi1)&&(soyadi2==soyadi1)){
             																									 a+=1;                                   
     																											 } 
                                                                                }
                           }         
   adi1=adi2;	//ad abone ad�na e�itle
   soyadi1=soyadi2;	//soyad da abone soyad�na e�itle
   system("cls");
   cout<<"\n\tYeni Abone Ekleme Islemi \n\n";
   if((a==1)||(a==2)||(a==3)||(a==4)){	//e�er x 1'e 2'ye 3'e veya 4'e e�itse alttaki kodlar �al���r.
        								cout<<endl<<"Abone Olunacak Derginin Adini Ve Konusunu Giriniz...:";
  	    								cin>>adi3>>konu1; //adi3 ve konu1 de�i�kenlerini al�r. 
  	    
     									for(int i=0;i<10;i++){ //i=0'dan i'yi 1 artt�rarak 10 den k�c�k oluncaya kadar  alttaki i�lemleri yap.
        													   while(d_ara>>dadi>>dko) {     
			        										   						   if(adi3==dadi){	// adi3 dadi e�itken a�a��daki i�lemleri yap.
               																		   					b+=1;
            																							}
                                                                                          }
                                                                    }        
   dadi=adi3; //adi3 dadi ata
   dko=konu1; //konu1 i dko ata
   if(b==0){ //b 0'e�itse hata mesaj�n� ver
           cout<<endl<<"Kayitli Olmayan Dergi Giremessiniz...";                     
     	   }
   if(b!=0){     //de�ilse ekleme i�lemini yap     
   			a_ekle<<adi1<<' '<<soyadi1<<' '<<tel1<<' '<<adresi1<<' '<<dadi<<' '<<dko<<endl;
   			cout<<endl<<"Abone Ekleme Islemi Basariyla Gerceklesti...";
        	system("pause"); 
        	}
     }        
     if(a==0){ //a 0'a e�itse hata mesaj�n� ver
         	   cout<<"Girilen Abone Kayitli Degil Ekleyiniz..."<<endl;
         	   mekle();
 			   }
     if(a==5){   //a 5'e e�itse hata mesaj�n� ver
              cout<<"Musterinin Abonelik Hakki Bitmistir...";
			  }                            
    ara.close();   
	a_ekle.close();
	cin.get();       
}

void mlistele(){   //musteri listeleme  fonksiyonumuz
       ifstream m_listele("m_bilgi.txt",ios::in); //m_bilgi.txt dosyas�ndan bilgi okuyarak dosyan�n giri�ine uygun olup olmad���n� belirler.
       if(!m_listele){       //uygun de�ilse hata raporu gelir.
 					 cerr<<"Islem Basarisiz..."<<endl;
             		 exit(1);                                                           
          			 }
       system("cls");  //ekran� temizler.
       cout<<left<<setw(10)<<"Adi"<<setw(12)<<"Soyadi"<<setw(13)<<"Telefon"<<setw(15) //ba�l�klar� sat�r uzunluklar�n� belirleyerek sa�a kayacak �ekilde yazd�k.
       <<"Adresi"<<setw(13)<<"Derginin Adi"<<setw(15)<<"Derginin Konusu"<<endl<<fixed<<showpoint;

  	   while(m_listele>>adi1>>soyadi1>>tel1>>adresi1>>dadi>>dko)  //dosyadan adi1,soyadi1,tel1,adresi,dadi ve dko okunuyor  
       cout<<left<<setw(10)<<adi1<<setw(12)<<soyadi1<<setw(13)<<tel1<<setw(15)<<adresi1<<setw(13)
       <<dadi<<setw(15)<<dko<<right<<endl<<fixed<<showpoint;  //m�sterinin girdi�i bilgileri belirtilen say�daki karakter bo�luguna yazd�r�l�r.
  }  
void alistele(){  //abone listeleme  fonksiyonumuz.
	 string a_bul;   //fonksiyon de�i�kenlerini tan�mlad�m
     cout<<"Aranan Abonenin Adini Giriniz....:"<<endl;  
     getline(cin,a_bul);  // kod sat�r� girilen karakterleri buyuk
     getline(cin,a_bul); //harfe donust�r�r.
     int i=0;
     while (a_bul[i]){
       	  			 a_bul[i]=toupper(a_bul[i]); 
				 	 i++;                       
  				 	 }                           
     ifstream a_listele("m_bilgi.txt",ios::in);//m_bilgi.txt dosyas�ndan bilgi okur ve in de�eri dosyan�n giri�e uygun oldu�unu belirler.
     if(!a_listele){				//uygun de�ilse hata mesaj�n� verir
					cerr<<"Dosya Acilamadi...";
          			exit(1);
        			}  
     system("cls");    //ekran� temizler
     cout<<endl<<endl<<left<<setw(10)<<"Adi"<<setw(12)<<"Soyadi"<<setw(13)<<"Derginin Adi"<<setw(15)<<"Derginin Konusu"<<endl<<fixed<<showpoint;
     while(a_listele>>adi1>>soyadi1>>tel1>>adresi1>>dadi>>dko) {   //dosyadan adi1,soyadi1,tel1,adresi,dadi ve dko okunuyor
	 														   if(a_bul==adi1){                     
						   										         cout<<left<<setw(10)<<adi1<<setw(12)<<soyadi1<<setw(13)<<dadi<<setw(15)<<dko<<right<<endl<<fixed<<showpoint;  
     																	       }         
                                                                 }  
	 a_listele.close();   
	 cin.get();   
}
void mara(){  //musteri arama  fonksiyonumuz.
        string kim;     //fonksiyon de�i�kenlerini tan�mlad�m
        char son;       
        int res=0;
		system("cls");      
        cout<<"Bulmak istediginiz musterinin ismini giriniz..:"<<endl;  
        getline(cin,kim); //kim de�i�kenini alarak alttaki kod sat�r� ile buyuk harflere d�n��t�rd�k.
        getline(cin,kim);
        int i=0;
   		while (kim[i]){
           	  		   kim[i]=toupper(kim[i]);   //Kelimedeki her karakter b�y�k harfe d�n��t�r�l�r.
           			   i++;            
           			   } 
        ifstream m_ara("m_bilgir.txt",ios::in);	//m_bilgi.txt dosyas�ndan bilgi okuyarak dosyan�n giri�ine uygun olup olmad���n� belirler.
   		if(!m_ara){   //uygun de�ilse hata raporunu verir
          			  cerr<<"Islem Basarisiz..."<<endl;
          			  exit(1);                                                              
         			  }  
        for(int i=0;i<50;i++){         //i=0'dan i'yi 1 artt�rarak 50 den k�c�k oluncaya kadar  alttaki i�lemleri yap.
 				              while(m_ara>>adi1>>soyadi1>>tel1>>adresi1>>dadi>>dko) {      //dosyadan adi1,soyadi1,tel1,adresi,dadi ve dko okunuyor      
        					  														if(kim==adi1){     //kim de�iskeni adi1 e e�itse..
    																						   res+=1;   //res'i 1 art�r                                                     
           																					   if(res!=0){     //res 0 dan farkl�ysa alttaki kod sat�rlar� �al���r.
     																				   				   cout<<endl<<endl<<left<<setw(10)<<"Adi"<<setw(12)<<"Soyadi"<<setw(13)<<"Telefon"<<setw(15)
             																						   <<"Adresi"<<setw(13)<<"Derginin Adi"<<setw(15)<<"Derginin Konusu"<<endl<<fixed<<showpoint; 
      	     																						   cout<<left<<setw(10)<<adi1<<setw(12)<<soyadi1<<setw(13)<<tel1<<setw(15)<<adresi1
             																						   <<setw(13)<<dadi<<setw(15)<<dko<<right<<endl<<fixed<<showpoint;  //yandaki bilgiler sa�a kayd�r�larak ekrana yaz�l�r.
           																							   }   
                  																    if(res==0){    //res 0 a e�itse bu c�kt�y� ver
             																					   cout<<"Aradiginiz Musteri Kayitli Degil..."<<endl; 
			 																					   cout<<"Eklemek istiyorsaniz 'E'ye eklemeden devam etmek 'H'ye basiniz (E/H)"<<endl;        
             																					   cin>>son;      //son de�i�kenini kullan�c�dan al�r.
             																					   son=toupper(son);   //buyuk harf d�n���m� yapar.
           																						   if(son=='E')    //musterinin girecegi secenek E ise musteri ekleme fonksiyonu cal���r.
																 	    			   			   mekle();                               
										  					   					                  }       
        																	          } 
                                     }
							 }
                               
        
	m_ara.close();                                                            
	cin.get();                                                                
}  
void asil(){    //abone silme fonksiyonumuz  
         string absil;	//fonksiyon i�indeki de�i�kenlerimiz
         string dersil;                                                     
   	     system("cls");    //ekran� temizler.
	     cout<<"Lutfen silmek istediginiz abonenin adini ve silinecek derginin adini giriniz....:"<<endl;
         getline(cin,absil);    //silinecek abone ad�n� harfleri buy�k olarak almas� i�in uygulanan kod sat�r�     
         getline(cin,absil);
         int i=0;          
    	 while (absil[i]){
	         		 	  absil[i]=toupper(absil[i]);  // Kelimedeki her karakter b�y�k harfe d�n��t�r�l�r.
         	 		 	  i++;         //i de�i�keninin degerini 1 artt�r�r.
		  				  }
        ifstream a_sil("m_bilgi.txt",ios::in);  //m_bilgi.txt dosyas�ndan bilgi okur ve in de�eri dosyan�n giri�e uygun oldu�unu belirler.
    	if(!a_sil){         //in de�eri dosyan�n giri�e uygun oldu�unu belirler
					cerr<<"Islem Basarisiz..."<<endl;   //uygun de�ilse hata mesaj�n� verir
         			exit(1);                                                              
    				}
        ofstream y_abone("y_abonelik.txt",ios::out); //��k�� dosyas� olu�tur ve ��k���n tamam�n� dosyaya ekle
    	if(!y_abone){         //yine y_abone'de null degeri varsa i�lem yap�lamad� hata raporu gelir.                 
			         cerr<<"Islem Basarisiz..."<<endl;
         			 exit(1);                                                               
     				 }
        while(a_sil>>adi1>>soyadi1>>tel1>>adresi1>>dadi>>dko) {  //dosyadan adi1,soyadi1,tel1,adresi,dadi ve dko okunuyor
       														  if((absil!=adi1) || (dersil!=dadi)){   //silinecek abone ad�n� ve silinecek derginin ad�n� kay�tlarla kar��la�t�r�r. 
         													  				   	  				y_abone<<adi1<<' '<<soyadi1<<' '<<tel1<<' '<<adresi1<<' '<<dadi<<' '<<dko<<endl;  
        																	   					  } 
						                                          }  
        cout<<endl<<"Abone Silme Islemi Basariyla Gerceklesti..";  //silme i�leminin tamamland��� raporu gelir.
     	a_sil.close();       //ab_sil kapat�l�r.
     	y_abone.close();      //yedek2 kapat�l�r.
     	ifstream atla_abn("y_abone.txt");  
     	ofstream bekle_abn("m_bilgi.txt");  
     	bekle_abn<<atla_abn.rdbuf();  
    }
};
#endif
