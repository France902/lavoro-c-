#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

#define R 11
#define C 31

using namespace std;
void guida();
int controllo_vittoria(int si, int sj){
	if(sj==0 && si<=6 && si>=4) return 1;
	else{
		if(sj==30 && si<=6 && si>=4) return 2;
		else{
			return 0;
		}
	}
}
void vedimatrice(char mat[R][C], bool cosa, int r, int c, int rand1, int rand2, int r2, int c2, int si_palla, int sj_palla)
{
   int i,j;  
   for(i=0;i<R;i++)
   {
      for(j=0;j<C;j++)
      {
         if(cosa)
         { 
            if((i==r && j==c) || (i==r2 && j==c2))
            {                  
               cout << '@' << " ";                         
            }
            else
            {
            if(i==rand1 && j==rand2){
         		cout<<'P'<<" ";
			 }
			 else{
			 	if(i==si_palla && j==sj_palla){
			 		cout<<"0"<<" ";
				 }
				 else{
				 	cout << mat[i][j] << " ";  
				 }
			 	
			 }                         
            }       
         }
         else
         {
         	if(j==0 || j==C-1){
         		 mat[i][j] = '|';
         		if(i==R/2-2 || i==R/2+2) mat[i][j] = '-';
         		if(i==R/2-1 || i==R/2 ||i==R/2+1) mat[i][j] = ' ';
         		
			 }
			else{
			 	if((i==0 && j>0) or(i==R-1 && j>0)) mat[i][j] = '-';
				else{
					if(j==C/2 && i>0 && i<R-1) 	mat[i][j] = '|';
					else{
						mat[i][j] = ' ';
					}
					
				}
			}
		
         }       
      }               
      if(cosa)
      {             
         cout << endl;   
      }   
   }                  
   
}

int main()
{
	system("color 2F");
	system("CLS");
	bool running = true;
    char mosse[1000]; 
    int cont = 0, punto_g=0, punto_c=0, vitt=0;
	srand(time(0));
    char matrice[R][C]; 
    int si=5,sj=1, n, n2, si2=5, sj2=28, si_palla = R/2, sj_palla = C/2;
    int conta=0, conta2=0, rand1, rand2;
    char mod;
    do{
        rand1 = rand()%10;
    	rand2 = rand()%20;	
	}while(rand1 == 4 && rand2 == 4);
    vedimatrice(matrice,false,si,sj, rand1, rand2, si2, sj2, si_palla, sj_palla);
    char scelta='v';
	cout<<"Benvenuto in FIFA++! ";
	cout<<"Scegliere la modalita': "<<endl<<"1- Giocatore vs computer "<<endl<<"2- Giocatore contro Giocatore"<<endl<<"3- Comandi"<<endl;
	do{
		mod = getch();
	} while(mod!= '1' && mod!='2' && mod != '3');
	if(mod == '3') guida();
	if(mod=='1'){
    while(running)
    {
       system("CLS");

       vedimatrice(matrice,true,si,sj, rand1, rand2, si2, sj2, si_palla, sj_palla);              
       scelta = 'b';
           cout<<"Giocatore: "<<punto_g<<"         Computer: "<<punto_c;
       
        if (_kbhit()) {
			scelta = getch();
            if (scelta == 'f') {
                running = false;
            }
        }

        if (cont < 1000 && cont%4==0) {
        	/*
            int r = rand() % 8; 
			
            switch (r) {
                case 0: mosse[cont] = 'i'; break;
                case 1: mosse[cont] = 'j'; break;
                case 2: mosse[cont] = 'k'; break;
                case 3: mosse[cont] = 'l'; break;
                case 4: mosse[cont] = 'u'; break;
                case 5: mosse[cont] = 'o'; break;
                case 6: mosse[cont] = 'n'; break;
                case 7: mosse[cont] = 'm'; break;
            }
            
            if(si2 == si_palla && sj2>sj_palla) mosse[cont] = 'j';
            else{
            	if(si2 == si_palla && sj2<sj_palla) mosse[cont] = 'l';
            	else{
            		if(sj2 == sj_palla && si2>si_palla) mosse[cont] = 'i';
            		else{
            			if(sj2 == sj_palla && si2<si_palla) mosse[cont] = 'k';
            			else{
            				if(si2 > si_palla && sj2>sj_palla) mosse[cont] = 'u';
            				else{
            					if(si2 < si_palla && sj2>sj_palla) mosse[cont] = 'n';
								else{
									if(si2 > si_palla && sj2<sj_palla) mosse[cont] = 'o';
									else{
										if(si2 < si_palla && sj2<sj_palla) mosse[cont] = 'm';
									}
								}	
							}
						}
					}
				}
			}
			
            switch(mosse[cont])
            {
            	case 'i':
          {
             if(si2>1 && (si2!=si+1 || sj2!=sj))
             {  
                si2--;  
                conta2++;
             }
             if(si2 == si_palla && sj2 == sj_palla){
             if(si_palla != si+1 || sj2!=sj){
             	if(si_palla>1) si_palla--;
             	 else si_palla++;
             	 } else si2++;
			 }
			 
             break;
          }                           
          case 'k':
          {
             if(si2<R-2 && (si2!=si-1 || sj2!=sj))
             {  
                si2++;  
                conta2++;
             }
			  if(si2 == si_palla && sj2 == sj_palla ){
			  if(si_palla != si-1 || sj2!=sj){
			  	if(si_palla<R-2) si_palla++;
             	 else si_palla--;
             	 } else si2--;
			  }       
             break;
          }                           
          case 'j':
          {
             if(sj2>1 && (sj2!=sj+1 || si2!=si))
             {  
                sj2--;  
                conta2++;
             }
			  if(si2 == si_palla && sj2 == sj_palla ){
			  	if(sj_palla != sj+1 || si2!=si) {
					if(sj_palla>1 || (si_palla <=6 && si_palla>=4)) sj_palla--;
             	 	else sj_palla++;
             	 	} else sj2++;
				}  
             break;
          }                           
          case 'l':
          {
             if(sj2<C-2  && (sj2!=sj-1 || si2!=si))
             {  
                sj2++;  
                conta2++;
             }
			 if(si2 == si_palla && sj2 == sj_palla ){
			 if(sj_palla != sj-1 || si2!=si){
			    	if(sj_palla<C-2 || (si_palla <=6 && si_palla>=4)) sj_palla++;
             	 	else sj_palla--;
             	 	} else sj2--;
				}     
             break;
          }
		  case 'u':
          {
             if(si2>1 && sj2>1 && (si2!=si+1 && sj2!=sj+1))
             {  
                si2--;  
                sj2--;
                conta2++;
             }
			  if(si2 == si_palla && sj2 == sj_palla){
			  if(si_palla != si+1 || sj_palla != sj+1){
			  	if(si_palla>1 && sj_palla>1 || (si_palla <=6 && si_palla>=4)){
			  		si_palla--;
			  		sj_palla--;
				  } 
             	else{
             		si2++;
             		sj2++;
				 }
			  } 
			  } else{
					si2++;
					sj2++;
				}
             break;
          }
		  case 'o':
          {
             if(si2>1 && sj2<C-2 && (si2!=si+1 && sj2!=sj-1))
             {  
                si2--; 
				sj2++; 
                conta2++;
             }
             if(si2 == si_palla && sj2 == sj_palla){
             	if(si_palla != si+1 || sj_palla != sj-1){
			  	if(si_palla>1 && sj_palla<C-2 || (si_palla <=6 && si_palla>=4)){
			  		si_palla--;
			  		sj_palla++;
				  } 
             	else{
             		si2++;
             		sj2--;
				 }
				 
			  }  
			   } else{
					si2++;
					sj2--;
				}   
             break;
          }
          
		  case 'm':
          {
             if(sj2<C-2 && si2<R-2 && (si2!=si-1 && sj2!=sj-1))
             {  
             	si2++;
                sj2++;  
                conta2++;
             }   
              if(si2 == si_palla && sj2 == sj_palla){
              if(si_palla != si-1 || sj_palla != sj-1){
			  	if(si_palla<R-2 && sj_palla<C-2 || (si_palla <=6 && si_palla>=4)){
			  		si_palla++;
			  		sj_palla++;
				  } 
             	else{
             		si2--;
             		sj2--;
				 }
			
			  }
			  	 } else{
					si2--;
					sj2--;
				}
             break;
          }
		  case 'n':
          {
             if(sj2>1 && si2<R-2 && (si2!=si2-1 && sj2!=sj2+1))
             {  
             	si2++;
                sj2--;  
                conta2++;
             }   
              if(si2 == si_palla && sj2 == sj_palla){
              if(si_palla != si-1 || sj_palla != sj+1){
			  	if(si_palla<R-2 && sj_palla>1 || (si_palla <=6 && si_palla>=4)){
			  		si_palla++;
			  		sj_palla--;
				  } 
             	else{
             		si2--;
             		sj2++;
				 }
				 } else{
					si--;
					sj++;
				}
			  }
             break;
          }           
			}
            cont++;
        } else{
        	cont++;
        	*/
		}
		
		switch(scelta)
       		{
          case 'w':
          {	 
             if(si>1 && (si!=si2+1 || sj!=sj2))
             {  
                si--;  
                conta++;
             }
             if(si == si_palla && sj == sj_palla){
             	if(si_palla != si2+1 || sj!=sj2){
             		if(si_palla>1) si_palla--;
             	 	else si_palla++;
				 } else si++;
             	
			 }
			 
             break;
          }                           
          case 's':
          {
             if(si<R-2 && (si!=si2-1 || sj!=sj2))
             {  
                si++;  
                conta++;
             }
			  if(si == si_palla && sj == sj_palla ){
			  	if(si_palla != si2-1 || sj!=sj2){
			  	if(si_palla<R-2) si_palla++;
             	 else si_palla--;
             	 } else si--;
			  }   
             break;
          }                           
          case 'a':
          {
             if(sj>1 && (sj!=sj2+1 || si!=si2))
             {  
                sj--;  
                conta++;
             }
				if(si == si_palla && sj == sj_palla ){
					if(sj_palla != sj2+1 || si!=si2) {
					if(sj_palla>1 || (si_palla <=6 && si_palla>=4)) sj_palla--;
             	 	else sj_palla++;
             	 	} else sj++;
				}  
             break;
          }                           
          case 'd':
          {
             if(sj<C-2 && (sj!=sj2-1 || si!=si2))
             {  
                sj++;  
                conta++;
             }
			    if(si == si_palla && sj == sj_palla ){
			    	if(sj_palla != sj2-1 || si!=si2){
			    	if(sj_palla<C-2 || (si_palla <=6 && si_palla>=4)) sj_palla++;
             	 	else sj_palla--;
             	 	} else sj--;
				} 
             break;
          }
		  case 'q':
          {
             if(si>1 && sj>1 && (si!=si2+1 || sj!=sj2+1))
             {  
                si--;  
                sj--;
                conta++;
             }
			  if(si == si_palla && sj == sj_palla){
			  	if(si_palla != si2+1 || sj_palla != sj2+1){
			  		if(si_palla>1 && sj_palla>1 || (si_palla <=6 && si_palla>=4)){
			  		si_palla--;
			  		sj_palla--;
				  } 
             	else{
             		si++;
             		sj++;
				 }
				} else{
					si++;
					sj++;
				}
			  }
             break;
          }
		  case 'e':
          {
             if(si>1 && sj<C-2 && (si!=si2+1 || sj!=sj2-1))
             {  
                si--; 
				sj++; 
                conta++;
             }
			  if(si == si_palla && sj == sj_palla){
			  	if(si_palla != si2+1 || sj_palla != sj2-1 ){
			  	if(si_palla>1 && sj_palla<C-2 || (si_palla <=6 && si_palla>=4)){
			  		si_palla--;
			  		sj_palla++;
				  } 
             	else{
             		si++;
             		sj--;
				 }
			}else{
					si++;
					sj--;
				}
			}    
             break;
          }
		  case 'x':
          {
             if(sj<C-2 && si<R-2 && (si!=si2-1 || sj!=sj2-1))
             {  
             	si++;
                sj++;  
                conta++;
             }   
              if(si == si_palla && sj == sj_palla){
              	if(si_palla != si2-1 || sj_palla != sj2-1){
			  	if(si_palla<R-2 && sj_palla<C-2 || (si_palla <=6 && si_palla>=4)){
			  		si_palla++;
			  		sj_palla++;
				  } 
             	else{
             		si--;
             		sj--;
				 }
			} else{
					si--;
					sj--;
				}
			  }
             break;
          }
		  case 'z':
          {
             if(sj>1 && si<R-2 && (si!=si2-1 || sj!=sj2+1))
             {  
             	si++;
                sj--;  
                conta++;
             }   
              if(si == si_palla && sj == sj_palla){
              	if(si_palla != si2-1 || sj_palla != sj2+1){
			  	if(si_palla<R-2 && sj_palla>1 || (si_palla <=6 && si_palla>=4)){
			  		si_palla++;
			  		sj_palla--;
				  } 
             	else{
             		si--;
             		sj++;
				 }
			} else{
					si--;
					sj++;
				}
			  }
             break;
          } 
		                     
       }
       vitt = controllo_vittoria(si_palla, sj_palla);
       if(vitt==1) {
       	si=5;
		sj=1;
		si2=5;
		sj2=28; 
		si_palla = R/2; 
		sj_palla = C/2;
		punto_c++;
	   }
       else if(vitt==2) {
       	si=5;
		sj=1;
		si2=5;
		sj2=28; 
		si_palla = R/2; 
		sj_palla = C/2;
		 punto_g++;
	   }
        Sleep(250); 
    }
}
       
       
                        
    cout << endl;
        
    system("PAUSE");
    return EXIT_SUCCESS;
}
void guida(){
	system("CLS");
	cout<<"Giocatore 1 (sinistra): "<<endl<<"W: Spostamento in alto     S: Spostamento in basso     D: Spostamento a destra      A: Spostamento a sinistra"<<endl;
	cout<<"Q: Spostamento obliquo a sinistra in alto     E: Spostamento obliquo a destra in alto     Z: Spostamento obliquo a sinistra in basso     X: Spostamento obliquo a destra in basso"<<endl;
	cout<<"Giocatore 2 (destra): "<<endl<<"I: Spostamento in alto     K: Spostamento in basso     L: Spostamento a destra      J: Spostamento a sinistra"<<endl;
	cout<<"U: Spostamento obliquo a sinistra in alto     O: Spostamento obliquo a destra in alto     N: Spostamento obliquo a sinistra in basso     M: Spostamento obliquo a destra in basso"<<endl;
	system("PAUSE");
	main();
}
