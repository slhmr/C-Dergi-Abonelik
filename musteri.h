#ifndef MUSTERI_h
#define MUSTERI_h 

#include "dergi.h"
class musteri:public dergi{ //müsteri clasý tanýmlayrak dergi clasý include ettik
    public:
       string adi1;                 //class içindeki deðiþkenlerimizi tanýmladýk                                             
       string soyadi1;                                                           
       string tel1;                                                         
       string adresi1;                                                             
                                           
	   void mekle(){    //müsteri ekleme iþleminin yapýldýðý fonksiyondur.
  		  string ad_k,konu_k,adi4,soyadi2,tel2,adresi2;  //fonksýyon deðiþkenlerini tanýmladýk 
  		  int vr=0,br=0;   
  		  ofstream m_ekle("m_bilgi.txt",ios::app); //çýkýþ dosyasý oluþtur ve çýkýþýn tamamýný dosyaya ekle
      	  if(!m_ekle){		//olmazsa hata mesajýný ver
   						cerr<<"Islem Basarisiz..."<<endl;
          				exit(1);
        				}
         ifstream dergi_k("kayitli_dergiler.txt",ios::in); //kayýtlý_dergiler.txt dosyasýný aç ve (in) deðeri dosyanýn giriþe uygun olduðunu belirler
         if(!dergi_k){    //uygun deðilse hata mesajýný ver
      					cerr<<"Islem Basarisiz..."<<endl;  
          				exit(1); 
        				} 
         ifstream m_k("m_bilgi.txt",ios::in); //m_bilgi.txt dosyasýný aç ve (in) deðeri dosyanýn giriþe uygun olduðunu belirler
         if(!m_k){	//uygun deðilse hata mesajýný ver
          			cerr<<"Islem Basarisiz..."<<endl;
        			exit(1);
     				} 
         system("cls");
         cout<<"\n\tYeni Musteri Ekleme Islemi \n\n";
         cout<<endl<<endl<<"Kaydedilecek Musterinin Adini Giriniz......: ";  //müþterinin adýný alýr    
         getline(cin,adi4);		//karakter büyültme satýrýmýz
     	 getline(cin,adi4);
     	 int m=0;
     	 while(adi4[m]){
         				adi4[m]=toupper(adi4[m]);
            			m++;
     					}
        cout<<"Kaydedilecek Musterinin Soyadini Giriniz...: ";    //müþterinin syadýný alýr   
     	getline(cin,soyadi2);	//karakter büyültme satýrýmýz
		int r=0;
     	while(soyadi2[r]){
        				  soyadi2[r]=toupper(soyadi2[r]);
           				  r++;
     					  } 
	    cout<<"Kaydedilecek Musterinin Tel No Giriniz.....: ";  //müþterinin tel no alýr     
        getline(cin,tel2);	//karakter büyültme satýrýmýz
        int k=0;
        while(tel2[k]){
        			   tel2[k]=toupper(tel2[k]);
            		   k++; 
					   }
       cout<<"Kaydedilecek Musterinin Adresini Giriniz...: ";      //müþterinin adresini alýr 
       getline(cin,adresi2);	//karakter büyültme satýrýmýz
       int u=0;
       while(adresi2[u]){
        				 adresi2[u]=toupper(adresi2[u]);
            			 u++;
     					 } 
	   cout<<"Kaydedilecek Derginin Adini Giriniz........: ";   //kaydedilec derginin adýný alýr   
       getline(cin,ad_k);//karakter büyültme satýrýmýz
       int l=0;
       while(ad_k[l]){
        			  ad_k[l]=toupper(ad_k[l]);
            		  l++; 
					  } 
       cout<<"Kaydedilecek Derginin Konusunu Giriniz.....:";      //kaydedilec derginin konusunu alýr
       getline(cin,konu_k);//karakter büyültme satýrýmýz
       int i=0;
       while(konu_k[i]){ 
        				 konu_k[i]=toupper(konu_k[i]);
            			 i++;
     					 } 
       for(int i=0;i<40;i++){ //girilen dergi adýný ve konusunu dongüye sokarak kayýtlý dergi olup olmadýklarýna 
               				  while(dergi_k>>dadi>>dko){	//dosyadan dadi ve dko okunuyor  
                			  								if((ad_k==dadi)&&(konu_k==dko)){ //eðer eþitlik bulursa vr'yi 1 artýrýr
                  																			  vr++;
           																					  }
					                                      }
                                }
       if (vr==0){ //bulamassa vr 0'a eþit olacaðýndan alttaki hata mesajýný verir
          		   cout<<endl<<endl<<"Yalnis Dergi Girdiniz...\n\n\n";
         		   }
       if(vr!=0){ //yukardaki döngüde eþitliði bulursa vr artacaðýndan bu if koþulu gercekleþir
   	   			  for(int z=0;z<5;z++){  //bu döngüde ise girilen müþteri ismi ile soyadýný kontrolederek kiþinin daha önceki abonelik sayýsýný
                  		  				 while(m_k>>adi1>>soyadi1>>tel1>>adresi1>>dadi>>dko){  //kontrol ederek hakkýnýn bitip bitmediðini belirlemek için
                    					 													   if((adi4==adi1)&&(soyadi2==soyadi1)){ //bu eþitlik varsa br'yi 1arttýr
                        																	   br++;
          																					   										 }
                                                                                            }
                                       }
       adi1=adi4;
       soyadi1=soyadi2;
       if(br==5){  //br 5'e eþit çýkarsa alttaki uyarý mesajýný verir
          		   cout<<""<<endl<<endl<<endl;
          		   cout<<"Bu musterinin abonelik hakki dolmustur..!\a"<<endl<<endl<<endl;
            	   } 
 
       if(br!=5){ //br 5'e eþit deðilse ekleme iþlemini gercekleçtirir
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
    string adi2,soyadi2; 	//fonksiyon deðiþkenleri
    string adi3,konu1;
    int a=0,b=0;   
	cout<<"Abonenin Adini Ve Soyismini Giriniz...";  
    getline(cin,adi2);
    getline(cin,adi2);
    int i=0;
   	while (adi2[i]){	//adi2 while döngüsüne sokularak büyük harfe çevrilir
         		   adi2[i]=toupper(adi2[i]); 
         		   i++;                     
        		   }                           
   ifstream ara("m_bilgi.txt",ios::in);	//m_bilgi.txt dosyasýný aç ve (in) deðeri dosyanýn giriþe uygun olduðunu belirler
   if(!ara){							//uygun deðilse hata raporunu ver
        	cerr<<"Islem Basarisiz...";
        	exit(1);
    		} 
   ifstream d_ara("kayitli_dergiler.txt",ios::in);//kayýtlý_dergiler.txt dosyasýný aç ve (in) deðeri dosyanýn giriþe uygun olduðunu belirler
   if(!d_ara){
        	  cerr<<"Islem Basarisiz...";
        	  exit(1);
    		  } 
   ofstream a_ekle("m_bilgi.txt",ios::app);	//çýkýþ dosyasý oluþtur ve çýkýþýn tamamýný dosyaya ekle
   if(!a_ekle){							//ekleme baþarýlamazsa hata raporunu ver
			cerr<<"Islem Basarisiz...";
        	exit(1);
     		}
   for(int i=0;i<5;i++){        //i=0'dan i'yi 1 arttýrarak 5 den kücük oluncaya kadar  alttaki iþlemleri yap.      
			            while(ara>>adi1>>soyadi1>>tel1>>adresi1>>dadi>>dko) {   //dosyadan adi1,soyadi1,tel1,adresi,dadi ve dko okunuyor  
     																		if((adi2==adi1)&&(soyadi2==soyadi1)){
             																									 a+=1;                                   
     																											 } 
                                                                                }
                           }         
   adi1=adi2;	//ad abone adýna eþitle
   soyadi1=soyadi2;	//soyad da abone soyadýna eþitle
   system("cls");
   cout<<"\n\tYeni Abone Ekleme Islemi \n\n";
   if((a==1)||(a==2)||(a==3)||(a==4)){	//eðer x 1'e 2'ye 3'e veya 4'e eþitse alttaki kodlar çalýþýr.
        								cout<<endl<<"Abone Olunacak Derginin Adini Ve Konusunu Giriniz...:";
  	    								cin>>adi3>>konu1; //adi3 ve konu1 deðiþkenlerini alýr. 
  	    
     									for(int i=0;i<10;i++){ //i=0'dan i'yi 1 arttýrarak 10 den kücük oluncaya kadar  alttaki iþlemleri yap.
        													   while(d_ara>>dadi>>dko) {     
			        										   						   if(adi3==dadi){	// adi3 dadi eþitken aþaðýdaki iþlemleri yap.
               																		   					b+=1;
            																							}
                                                                                          }
                                                                    }        
   dadi=adi3; //adi3 dadi ata
   dko=konu1; //konu1 i dko ata
   if(b==0){ //b 0'eþitse hata mesajýný ver
           cout<<endl<<"Kayitli Olmayan Dergi Giremessiniz...";                     
     	   }
   if(b!=0){     //deðilse ekleme iþlemini yap     
   			a_ekle<<adi1<<' '<<soyadi1<<' '<<tel1<<' '<<adresi1<<' '<<dadi<<' '<<dko<<endl;
   			cout<<endl<<"Abone Ekleme Islemi Basariyla Gerceklesti...";
        	system("pause"); 
        	}
     }        
     if(a==0){ //a 0'a eþitse hata mesajýný ver
         	   cout<<"Girilen Abone Kayitli Degil Ekleyiniz..."<<endl;
         	   mekle();
 			   }
     if(a==5){   //a 5'e eþitse hata mesajýný ver
              cout<<"Musterinin Abonelik Hakki Bitmistir...";
			  }                            
    ara.close();   
	a_ekle.close();
	cin.get();       
}

void mlistele(){   //musteri listeleme  fonksiyonumuz
       ifstream m_listele("m_bilgi.txt",ios::in); //m_bilgi.txt dosyasýndan bilgi okuyarak dosyanýn giriþine uygun olup olmadýðýný belirler.
       if(!m_listele){       //uygun deðilse hata raporu gelir.
 					 cerr<<"Islem Basarisiz..."<<endl;
             		 exit(1);                                                           
          			 }
       system("cls");  //ekraný temizler.
       cout<<left<<setw(10)<<"Adi"<<setw(12)<<"Soyadi"<<setw(13)<<"Telefon"<<setw(15) //baþlýklarý satýr uzunluklarýný belirleyerek saða kayacak þekilde yazdýk.
       <<"Adresi"<<setw(13)<<"Derginin Adi"<<setw(15)<<"Derginin Konusu"<<endl<<fixed<<showpoint;

  	   while(m_listele>>adi1>>soyadi1>>tel1>>adresi1>>dadi>>dko)  //dosyadan adi1,soyadi1,tel1,adresi,dadi ve dko okunuyor  
       cout<<left<<setw(10)<<adi1<<setw(12)<<soyadi1<<setw(13)<<tel1<<setw(15)<<adresi1<<setw(13)
       <<dadi<<setw(15)<<dko<<right<<endl<<fixed<<showpoint;  //müsterinin girdiði bilgileri belirtilen sayýdaki karakter boþluguna yazdýrýlýr.
  }  
void alistele(){  //abone listeleme  fonksiyonumuz.
	 string a_bul;   //fonksiyon deðiþkenlerini tanýmladým
     cout<<"Aranan Abonenin Adini Giriniz....:"<<endl;  
     getline(cin,a_bul);  // kod satýrý girilen karakterleri buyuk
     getline(cin,a_bul); //harfe donustürür.
     int i=0;
     while (a_bul[i]){
       	  			 a_bul[i]=toupper(a_bul[i]); 
				 	 i++;                       
  				 	 }                           
     ifstream a_listele("m_bilgi.txt",ios::in);//m_bilgi.txt dosyasýndan bilgi okur ve in deðeri dosyanýn giriþe uygun olduðunu belirler.
     if(!a_listele){				//uygun deðilse hata mesajýný verir
					cerr<<"Dosya Acilamadi...";
          			exit(1);
        			}  
     system("cls");    //ekraný temizler
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
        string kim;     //fonksiyon deðiþkenlerini tanýmladým
        char son;       
        int res=0;
		system("cls");      
        cout<<"Bulmak istediginiz musterinin ismini giriniz..:"<<endl;  
        getline(cin,kim); //kim deðiþkenini alarak alttaki kod satýrý ile buyuk harflere dönüþtürdük.
        getline(cin,kim);
        int i=0;
   		while (kim[i]){
           	  		   kim[i]=toupper(kim[i]);   //Kelimedeki her karakter büyük harfe dönüþtürülür.
           			   i++;            
           			   } 
        ifstream m_ara("m_bilgir.txt",ios::in);	//m_bilgi.txt dosyasýndan bilgi okuyarak dosyanýn giriþine uygun olup olmadýðýný belirler.
   		if(!m_ara){   //uygun deðilse hata raporunu verir
          			  cerr<<"Islem Basarisiz..."<<endl;
          			  exit(1);                                                              
         			  }  
        for(int i=0;i<50;i++){         //i=0'dan i'yi 1 arttýrarak 50 den kücük oluncaya kadar  alttaki iþlemleri yap.
 				              while(m_ara>>adi1>>soyadi1>>tel1>>adresi1>>dadi>>dko) {      //dosyadan adi1,soyadi1,tel1,adresi,dadi ve dko okunuyor      
        					  														if(kim==adi1){     //kim deðiskeni adi1 e eþitse..
    																						   res+=1;   //res'i 1 artýr                                                     
           																					   if(res!=0){     //res 0 dan farklýysa alttaki kod satýrlarý çalýþýr.
     																				   				   cout<<endl<<endl<<left<<setw(10)<<"Adi"<<setw(12)<<"Soyadi"<<setw(13)<<"Telefon"<<setw(15)
             																						   <<"Adresi"<<setw(13)<<"Derginin Adi"<<setw(15)<<"Derginin Konusu"<<endl<<fixed<<showpoint; 
      	     																						   cout<<left<<setw(10)<<adi1<<setw(12)<<soyadi1<<setw(13)<<tel1<<setw(15)<<adresi1
             																						   <<setw(13)<<dadi<<setw(15)<<dko<<right<<endl<<fixed<<showpoint;  //yandaki bilgiler saða kaydýrýlarak ekrana yazýlýr.
           																							   }   
                  																    if(res==0){    //res 0 a eþitse bu cýktýyý ver
             																					   cout<<"Aradiginiz Musteri Kayitli Degil..."<<endl; 
			 																					   cout<<"Eklemek istiyorsaniz 'E'ye eklemeden devam etmek 'H'ye basiniz (E/H)"<<endl;        
             																					   cin>>son;      //son deðiþkenini kullanýcýdan alýr.
             																					   son=toupper(son);   //buyuk harf dönüþümü yapar.
           																						   if(son=='E')    //musterinin girecegi secenek E ise musteri ekleme fonksiyonu calýþýr.
																 	    			   			   mekle();                               
										  					   					                  }       
        																	          } 
                                     }
							 }
                               
        
	m_ara.close();                                                            
	cin.get();                                                                
}  
void asil(){    //abone silme fonksiyonumuz  
         string absil;	//fonksiyon içindeki deðiþkenlerimiz
         string dersil;                                                     
   	     system("cls");    //ekraný temizler.
	     cout<<"Lutfen silmek istediginiz abonenin adini ve silinecek derginin adini giriniz....:"<<endl;
         getline(cin,absil);    //silinecek abone adýný harfleri buyük olarak almasý için uygulanan kod satýrý     
         getline(cin,absil);
         int i=0;          
    	 while (absil[i]){
	         		 	  absil[i]=toupper(absil[i]);  // Kelimedeki her karakter büyük harfe dönüþtürülür.
         	 		 	  i++;         //i deðiþkeninin degerini 1 arttýrýr.
		  				  }
        ifstream a_sil("m_bilgi.txt",ios::in);  //m_bilgi.txt dosyasýndan bilgi okur ve in deðeri dosyanýn giriþe uygun olduðunu belirler.
    	if(!a_sil){         //in deðeri dosyanýn giriþe uygun olduðunu belirler
					cerr<<"Islem Basarisiz..."<<endl;   //uygun deðilse hata mesajýný verir
         			exit(1);                                                              
    				}
        ofstream y_abone("y_abonelik.txt",ios::out); //çýkýþ dosyasý oluþtur ve çýkýþýn tamamýný dosyaya ekle
    	if(!y_abone){         //yine y_abone'de null degeri varsa iþlem yapýlamadý hata raporu gelir.                 
			         cerr<<"Islem Basarisiz..."<<endl;
         			 exit(1);                                                               
     				 }
        while(a_sil>>adi1>>soyadi1>>tel1>>adresi1>>dadi>>dko) {  //dosyadan adi1,soyadi1,tel1,adresi,dadi ve dko okunuyor
       														  if((absil!=adi1) || (dersil!=dadi)){   //silinecek abone adýný ve silinecek derginin adýný kayýtlarla karþýlaþtýrýr. 
         													  				   	  				y_abone<<adi1<<' '<<soyadi1<<' '<<tel1<<' '<<adresi1<<' '<<dadi<<' '<<dko<<endl;  
        																	   					  } 
						                                          }  
        cout<<endl<<"Abone Silme Islemi Basariyla Gerceklesti..";  //silme iþleminin tamamlandýðý raporu gelir.
     	a_sil.close();       //ab_sil kapatýlýr.
     	y_abone.close();      //yedek2 kapatýlýr.
     	ifstream atla_abn("y_abone.txt");  
     	ofstream bekle_abn("m_bilgi.txt");  
     	bekle_abn<<atla_abn.rdbuf();  
    }
};
#endif
