#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

#define R 11
#define C 31

using namespace std;

void vedimatrice(char mat[R][C], bool cosa, int r, int c, int r2, int c2)
{
   int i,j;  
   for(i=0;i<R;i++)
   {
      for(j=0;j<C;j++)
      {
         if(cosa)
         {
            if((i==r && j==c) || (i==r2 && j==c2+1))
            {                  
               cout << '@' << " ";
            }
            else
            {
			 	if(i==R/2 && j==C/2){
			 		cout<<"0"<<" ";
				 }
				 else{
				 	cout << mat[i][j] << " ";
				 }
			 
            }       
         }
         else
         {
         	if(j==0 || j==C-1){
         		 mat[i][j] = '|';
         		if(i==R/2-1 || i==R/2+1) mat[i][j] = '-';
         		if(i==R/2) mat[i][j] = ' ';
         		
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
   cout << endl;   
}

int main(int argc, char *argv[])
{
	system("color 2F");
	bool running = true;
    char mosse[100]; 
    int cont = 0;
	srand(time(0));
    char matrice[R][C]; 
    int si=5,sj=1, n, n2, si2=5, sj2=28;
    int rand1, rand2;
    do{
        rand1 = rand()%10;
    	rand2 = rand()%20;	
	}while(rand1 == 4 && rand2 == 4);

    
    vedimatrice(matrice, false, si, sj, si2, sj2);

    char scelta='v';
	char scelta2='g';
	
    while(running)
    {
       system("CLS");

       vedimatrice(matrice, true, si, sj, si2, sj2);
       
       cout << "w-sopra  s-sotto  a-sinistra  d-destra  q-alto-sinistra  e-alto-destra  x-basso-destra  z-basso-sinistra" << endl;
       cout << "i-sopra  k-sotto  j-sinistra  l-destra  u-alto-sinistra  o-alto-destra  n-basso-destra  m-basso-sinistra" << endl;
       cout << "f-fine" << endl;
       cout << endl << "Scelta :";
        scelta = ' ';
       scelta2 = ' ';
       if (_kbhit()) {
            char tasto = getch();
            if (tasto == 'f') {
                running = false;
            } else if (tasto == 'w' || tasto == 'a' || tasto == 's' || tasto == 'd' || tasto == 'q' || tasto == 'e' || tasto == 'x' || tasto == 'z') {
                scelta = tasto;
            } else if (tasto == 'i' || tasto == 'j' || tasto == 'k' || tasto == 'l' || tasto == 'u' || tasto == 'o' || tasto == 'n' || tasto == 'm') {
                scelta2 = tasto;
            }
       }

       //  Giocatore 1
       switch(scelta)
       {
		case 'w': 
		    if (si > 0) 
		        si--; 
		    else 
		        si = R - 1; 
		    break;
		
		case 's': 
		    if (si < R - 1) 
		        si++; 
		    else 
		        si = 0; 
		    break;
		
		case 'a': 
		    if (sj > 0) 
		        sj--; 
		    else 
		        sj = C - 1; 
		    break;
		
		case 'd': 
		    if (sj < C - 1) 
		        sj++; 
		    else 
		        sj = 0; 
		    break;

          case 'q':
             if(si > 0 && sj > 0){ 
				 si--; 
				 sj--; 
				 }
             else { n = si; 
				 n2 = sj; 
				 si = R - n2 - 1; 
				 sj = C - n - 1; 
				 }
             break;
             
          case 'e':
             if(si > 0 && sj < C - 1){ 
			 	si--; 
				sj++; 
				}
             else{ 
				 n = sj; 
				 sj = si; 
				 si = n; 
			 }
             break;
             
          case 'x':
             if(si < R - 1 && sj < C - 1){ 
			 si++; 
			 sj++;
			}
             else{ n = si;
			  n2 = sj; 
			  si = R - n2 - 1; 
			  sj = C - n - 1;
			}
             break;
             
          case 'z':
             if(si < R - 1 && sj > 0){ 
			 si++; 
			 sj--; 
			 }
             else{ 
			 n = si; 
			 si = sj; 
			 sj = n; 
			 }
             break;
       }

       // Giocatore 2
       switch(scelta2){
		   case 'i': 
			    if (si2 > 0) 
			        si2--; 
			    else 
			        si2 = R - 1; 
			    break;
			
			case 'k': 
			    if (si2 < R - 1) 
			        si2++; 
			    else 
			        si2 = 0; 
			    break;
			
			case 'j': 
			    if (sj2 > 0) 
			        sj2--; 
			    else 
			        sj2 = C - 1; 
			    break;
			
			case 'l': 
			    if (sj2 < C - 1) 
			        sj2++; 
			    else 
			        sj2 = 0; 
			    break;
			    
			case 'u':
		      if(si2 > 0 && sj2 > 0){ 
		         si2--; 
		         sj2--; 
		      } else { 
		         n = si2; 
		         n2 = sj2; 
		         si2 = R - n2 - 1; 
		         sj2 = C - n - 1; 
		      }
		      break;
		      
		   case 'o':
		      if(si2 > 0 && sj2 < C - 1){ 
		         si2--; 
		         sj2++; 
		      } else { 
		         n = sj2; 
		         sj2 = si2; 
		         si2 = n; 
		      }
		      break;
		      
		   case 'm':
		      if(si2 < R - 1 && sj2 < C - 1){ 
		         si2++; 
		         sj2++; 
		      } else { 
		         n = si2; 
		         n2 = sj2; 
		         si2 = R - n2 - 1; 
		         sj2 = C - n - 1; 
		      }
		      break;
		      
		   case 'n':
		      if(si2 < R - 1 && sj2 > 0){ 
		         si2++; 
		         sj2--; 
		      } else { 
		         n = si2; 
		         si2 = sj2; 
		         sj2 = n; 
		      }
		      break;
		}
       Sleep(200);
    }

    cout << endl;
        
    system("PAUSE");
    return EXIT_SUCCESS;
}
