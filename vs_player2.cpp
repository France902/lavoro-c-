#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

#define R 11
#define C 31

using namespace std;

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
    system("color 2F");
    bool running = true;
    char matrice[R][C];
    char scelta = ' ', scelta2 = ' ';
    int si = 5, sj = 1;
    int si2 = 5, sj2 = 28;
    int pi = R / 2, pj = C / 2; // palla al centro
    int possesso = 0; // 0 = nessuno, 1 = player1, 2 = player2
    int gol1 = 0, gol2 = 0; // Contatori per i goal
    int n, n2;

    vedimatrice(matrice, false, si, sj, si2, sj2, pi, pj);

    while (running)
    {
        system("CLS");
        vedimatrice(matrice, true, si, sj, si2, sj2, pi, pj);

        cout << "Gol Giocatore 1: " << gol1 << "   Gol Giocatore 2: " << gol2 << endl;
        cout << "w-sopra  s-sotto  a-sinistra  d-destra  q-alto-sinistra  e-alto-destra  x-basso-destra  z-basso-sinistra" << endl;
        cout << "i-sopra  k-sotto  j-sinistra  l-destra  u-alto-sinistra  o-alto-destra  n-basso-destra  m-basso-sinistra" << endl;
        cout << "f-fine" << endl;
        cout << endl << "Scelta : ";

        scelta = ' ';
        scelta2 = ' ';
        
        char tasto = getch();
            if (tasto == 'f')
            {
                running = false;
            }
            else if (strchr("wasdqexz", tasto))
            {
                scelta = tasto;
            }
            else if (strchr("ijkluonm", tasto))
            {
                scelta2 = tasto;
            }
        

        // Giocatore 1 (stesso meccanismo)
        switch (scelta)
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
		    if (sj > 0 && (sj2 != sj-1 or si != si2)) 
		        sj--; 
                                                                                                                                   
		    break;                                                                                                                                    
		
		case 'd':                                                                                                                                     
		    if (sj < C - 1 && (sj2 != sj+1 or si != si2))                                                                                                                                     
		        sj++;                                                                                                                                                 
		    break;
            case 'q':
                if (si > 0 && sj > 0) { si--; sj--; }
                else { n = si; n2 = sj; si = R - n2 - 1; sj = C - n - 1; }
                break;
            case 'e':
                if (si > 0 && sj < C - 1) { si--; sj++; }
                else { n = sj; sj = si; si = n; }
                break;
            case 'x':
                if (si < R - 1 && sj < C - 1) { si++; sj++; }
                else { n = si; n2 = sj; si = R - n2 - 1; sj = C - n - 1; }
                break;
            case 'z':
                if (si < R - 1 && sj > 0) { si++; sj--; }
                else { n = si; si = sj; sj = n; }
                break;
        }

        // Giocatore 2
        switch (scelta2)
        {
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
			    if (sj2 > 0 && (sj != sj2-1 or si2 != si)) 
			        sj2--; 
 
			    break;
			
			case 'l': 
			    if (sj2 < C - 2 && (sj != sj2+1 or si2 != si))
			        sj2++; 
			    break;
			    
            case 'u':
                if (si2 > 0 && sj2 > 0) { si2--; sj2--; }
                else { n = si2; n2 = sj2; si2 = R - n2 - 1; sj2 = C - n - 1; }
                break;
            case 'o':
                if (si2 > 0 && sj2 < C - 1) { si2--; sj2++; }
                else { n = sj2; sj2 = si2; si2 = n; }
                break;
            case 'm':
                if (si2 < R - 1 && sj2 < C - 1) { si2++; sj2++; }
                else { n = si2; n2 = sj2; si2 = R - n2 - 1; sj2 = C - n - 1; }
                break;
            case 'n':
                if (si2 < R - 1 && sj2 > 0) { si2++; sj2--; }
                else { n = si2; si2 = sj2; sj2 = n; }
                break;
        }

        // Cambio possesso se toccano la palla
        if (possesso == 0)
        {
            if (si == pi && sj == pj)
                possesso = 1;
            // Modifica: controllo con coordinate logiche per il Giocatore 2
            else if (si2 == pi && sj2 == pj)
                possesso = 2;
        }
        else if (possesso == 1 && si2 == pi && (sj2==pj+1))
        {
            possesso = 2;
        }
        else if (possesso == 2 && si == pi && (sj==pj+1))
        {
            possesso = 1;
        }

        // Movimento palla con il giocatore in possesso
        if (possesso == 1 && si2!=pj+1 )
        {
            pi = si;
            pj = sj + 1; // la palla esce verso destra, attaccando la porta destra (Giocatore 1)
        }
        // Modifica: la palla per Giocatore 2 viene impostata lasciando l'offset a sinistra 
        else if (possesso == 2 && si!=pj+1)
        {
            pi = si2;
            pj = sj2; // ora la palla esce verso sinistra, attaccando la porta sinistra (Giocatore 2)
        }

        // Controllo dei goal
        if (pj == 0 && pi >= R / 2 - 1 && pi <= R / 2 + 1)  // Giocatore 2 segna (porta di sinistra)
        {
            gol2++;
            cout << "GOAL del GIOCATORE 2!" << endl;
            pi = R / 2; pj = C / 2; // Posiziona la palla al centro
            si = 5; sj = 1;         // Posiziona Giocatore 1
            si2 = 5; sj2 = 28;      // Posiziona Giocatore 2
            
        }

        if (pj == C - 1 && pi >= R / 2 - 1 && pi <= R / 2 + 1)  // Giocatore 1 segna (porta di destra)
        {
            gol1++;
            cout << "GOAL del GIOCATORE 1!" << endl;
            pi = R / 2; pj = C / 2; // Posiziona la palla al centro
            si = 5; sj = 1;         // Posiziona Giocatore 1
            si2 = 5; sj2 = 28;      // Posiziona Giocatore 2
            
        }

        
    }
    return 0;
}
