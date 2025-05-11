//Importazioni librerie
#include <iostream>
#include <conio.h> //Libreria per la funzione getch(), che non prevede il premere invio per compilare un input (char) e kbhit(), che controlla se un tasto è stato premuto senza fermare il programma
#include <windows.h> //Libreria per strchr(), che ricerca una lettera in una variabile, restituendo un valore booleano

//Dichiarazioni delle costanti, per la dimensione del campo
#define R 11
#define C 31

using namespace std;
//Dichiarazione della variabile booleana vittoria
bool vittoria = false;

//Firma delle due funzioni che attribuiscono la vittoria a uno dei due giocatori
void vittoria_1();

void vittoria_2();

//Funzione vedi matrice, che ricevendo la matrice(campo), le coordinate dei due giocatori e della palla costruisce il campo da gioco
void vedimatrice(char mat[R][C], bool cosa, int r, int c, int r2, int c2, int pi, int pj)
{
    int i, j;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (cosa)
            {
                if (i == r && j == c)
                    cout << 'A' << " "; // Giocatore 1
                else if (i == r2 && j == c2 + 1)
                    cout << 'B' << " "; // Giocatore 2
                else if (i == pi && j == pj)
                    cout << 'o' << " "; // Palla
                else
                    cout << mat[i][j] << " ";
            }
            else
            {
                if (j == 0 || j == C - 1)
                {
                    mat[i][j] = '|';
                    if (i == R / 2 - 1 || i == R / 2 + 1)
                        mat[i][j] = '-';
                    if (i == R / 2)
                        mat[i][j] = ' ';
                }
                else
                {
                    if ((i == 0 && j > 0) || (i == R - 1 && j > 0))
                        mat[i][j] = '-';
                    else
                    {
                        if (j == C / 2 && i > 0 && i < R - 1)
                            mat[i][j] = '|';
                        else
                            mat[i][j] = ' ';
                    }
                }
            }
        }
        if (cosa)
            cout << endl;
    }
    cout << endl;
}

int main()
{
	//Cambio colore della console in verde
    system("color 2F");
    bool running = true, cond, cond2;
    char matrice[R][C];
    char scelta = ' ', scelta2 = ' ';
    int si = 5, sj = 1;
    int si2 = 5, sj2 = 28;
    int pi = R / 2, pj = C / 2; // palla al centro
    int possesso = 0; // 0 = nessuno, 1 = player1, 2 = player2
    int gol1 = 0, gol2 = 0; // Contatori per i goal
    int n, n2;
	if(vittoria == false){
		//Inizio gioco
    	cout<<"Benvenuti in FIFA++ "<<endl;
    	cout<<"Chiama un amico e premi un tasto per iniziare!"<<endl;
    	system("PAUSE");
	}
    vedimatrice(matrice, false, si, sj, si2, sj2, pi, pj);

	//Ciclo while che termina alla fine della partita
    while (running)
    {
    	
        system("CLS");
        vedimatrice(matrice, true, si, sj, si2, sj2, pi, pj);
        cout << "w-sopra  s-sotto  a-sinistra  d-destra  q-alto-sinistra  e-alto-destra  x-basso-destra  z-basso-sinistra r-tira " << endl;
        cout << "i-sopra  k-sotto  j-sinistra  l-destra  u-alto-sinistra  o-alto-destra  n-basso-destra  m-basso-sinistra p-tira " << endl;
        cout << "f-fine" << endl;
        cout<<"Fai 5 gol prima del tuo avversario! "<<endl;
        cout << "Gol Giocatore 1: " << gol1 << "   Gol Giocatore 2: " << gol2 << endl;
        cout << endl << "Scelta : ";

        scelta = ' ';
        scelta2 = ' ';
        //Dichirazione di tasto come input usando getch
        char tasto = getch();
            if (tasto == 'f')
            {
                running = false;
            }
            else if (strchr("wasdqexzr", tasto))
            {
                scelta = tasto;
            }
            else if (strchr("ijkluonmp", tasto))
            {
                scelta2 = tasto;
            }
        

        // Movimento e tiro del Giocatore 1 
        switch (scelta)
        {
        case 'r':
        	if(possesso == 1){
        		possesso = 0;
            	pj = pj + 3;
            	
            	if((sj2 == pj || sj2 == pj-1 || sj2 == pj-2 || sj2 == pj-3) && si2 == pi){
            		possesso = 2;
            		pj = sj2;
				}
			}
            break;
        case 'w': 
		    if (si > 0){
		    	cond = true;
		        si--; 
			} 	
		    else{
		    	cond = true;
			}
		    
		    break;
		
		case 's': 
		    if (si < R - 1){
		    	cond = true;
		        si++; 
			} 
		    else {
		    	cond = true;
			}
		    break;
		
		case 'a': 
		    if (sj > 0 && (sj2 != sj-1 or si != si2)){
		    	cond = false;
		        sj--;      
			}                                                                                                            
		    break;                                                                                                                                    
		case 'd':     
			if(possesso == 1){
				if (sj < C - 2 && (sj2 != sj+1 or si != si2)){
		    	cond = false;                                                                                                                                  
		        sj++;
			}   
			}
			else if (sj < C - 1 && (sj2 != sj+1 or si != si2)){
		    	cond = false;                                                                                                                                  
		        sj++;
			}                                                                                                                                                                                                                                                                         
		    break;
            case 'q':
                if (si > 0 && sj > 0) { 
					cond = false; 
					si--; 
					sj--; 
				}
                break;
            case 'e':
                if (si > 0 && sj < C - 1) {
					cond = false; 
					si--; 
					sj++; 
				}
                break;
            case 'x':
                if (si < R - 1 && sj < C - 1) {
					cond = false; 
					si++; 
					sj++; 
				}
                break;
            case 'z':
                if (si < R - 1 && sj > 0) {
					cond = false; 
					si++; 
					sj--; 
				}
                
                break;
            
        }

        // Movimento e tiro del Giocatore 2
        switch (scelta2)
        {
        	 case 'p':
             	if(possesso == 2){
             		possesso = 0;
	            	pj = pj - 3;
	            	if((sj == pj || sj == pj+1 || sj == pj+2 || sj == pj+3) && si == pi){
            		possesso = 1;
            		pj = sj;
				}
				 }
            case 'i': 
			    if (si2 > 0) {
			    	 si2--; 
			        cond2 = true;
				}
			    else{
			        cond2 = true;
				}
			    break;
			case 'k': 
			    if (si2 < R - 1) {
			    	 si2++; 
			        cond2 = true;
				}
			    else{
			    	cond2 = true;
				}
			    break;
			case 'j': 
			if(possesso == 2){
				if (sj2 > 1 && (sj != sj2-1 or si2 != si)){
			    	cond2 = false;
			        sj2--; 
				} 
			}
			else  if (sj2 > 0 && (sj != sj2-1 or si2 != si)){
			    	cond2 = false;
			        sj2--; 
				} 
			    break;
			case 'l': 
			    if (sj2 < C - 2 && (sj != sj2+1 or si2 != si)){
			    	cond2 = false;
			        sj2++; 	
				}
			    break;
            case 'u':
                if (si2 > 0 && sj2 > 0) {
					cond2 = false; 
					si2--; 
					sj2--; 
				}
                break;
            case 'o':
                if (si2 > 0 && sj2 < C - 1) {
					cond2 = false;
					si2--; 
					sj2++; 
				}
                break;
            case 'm':
                if (si2 < R - 1 && sj2 < C - 1) {
					cond2 = false; 
					si2++; 
					sj2++; 
				}
                break;
            case 'n':
                if (si2 < R - 1 && sj2 > 0) {
					cond2 = false; 
					si2++; 
					sj2--; 
				}
                break;
        }

        // Cambio possesso se toccano la palla
        if (possesso == 0)
        {
        	// controllo con coordinate logiche per il Giocatore 1
            if (si == pi && sj == pj)
                possesso = 1;
            // controllo con coordinate logiche per il Giocatore 2
            else if (si2 == pi && sj2 == pj)
                possesso = 2;  
        }
        //Controllo coordinate quando il giocatore avversario ha la palla
        if(possesso == 1 && si2 == pi && sj2 +1 == pj && cond2 == true){
        	possesso = 2;
		}
		else if(possesso == 2 && si == pi && sj == pj && cond == true){
			possesso = 1;
		}
        

        // Movimento palla con il giocatore in possesso
        if (possesso == 1 && si2!=pj+1 )
        {
            pi = si;
            pj = sj +1 ; // la palla esce verso destra, attaccando la porta destra (Giocatore 1)
        }
        else if (possesso == 2 && si!=pj+1)
        {
            pi = si2;
            pj = sj2; // la palla esce verso sinistra, attaccando la porta sinistra (Giocatore 2)
        }
        

        // Controllo dei goal
        if (pj <= 0 && pi >= R / 2 - 1 && pi <= R / 2 + 1)  // Giocatore 2 segna (porta di sinistra)
        {
            gol2++;
            cout << "GOAL del GIOCATORE 2!" << endl;
            pi = R / 2; pj = C / 2; // Posiziona la palla al centro
            si = 5; sj = 1;         // Posiziona Giocatore 1
            si2 = 5; sj2 = 28;      // Posiziona Giocatore 2
            possesso = 0;
            //Controllo vittoria
            if(gol2 == 5){
            	running = false;
            	vittoria_2();
			}
        }

        if (pj >= C - 1 && pi >= R / 2 - 1 && pi <= R / 2 + 1)  // Giocatore 1 segna (porta di destra)
        {
            gol1++;
            cout << "GOAL del GIOCATORE 1!" << endl;
            pi = R / 2; pj = C / 2; // Posiziona la palla al centro
            si = 5; sj = 1;         // Posiziona Giocatore 1
            si2 = 5; sj2 = 28;      // Posiziona Giocatore 2
            possesso = 0;
            //controllo vittoria
            if(gol1 == 5){
            	running = false;
            	vittoria_1();
			}
        }

        
    }
    return 0;
}
//Vittoria giocatore 1
void vittoria_1(){
	vittoria = true;
	system("CLS");
	cout<<"Ha vinto il giocatore 1!"<<endl;
	cout<<"Premere per riniziare"<<endl;
	system("PAUSE");
	main();
}
//Vittoria giocatore 2
void vittoria_2(){
	vittoria = true;
	system("CLS");
	cout<<"Ha vinto il giocatore 2!"<<endl;
	cout<<"Premere per riniziare"<<endl;
	system("PAUSE");
	main();
}
