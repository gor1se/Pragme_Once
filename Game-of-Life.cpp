#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"
#include "Spielstein.h"
#include <vector>
using namespace std;
using namespace cimg_library;

const int grid_size = 10; // Anzahl an Kaestchen in x- und y-Richtung
const int box_size = 30;  // size der einzelnen Kaestchen (in Pixel)
const int border = 20;    // Rand links und oben bis zu den ersten Kaestchen (in Pixel)

// Prototyp der Funktionen zum Vorbelegen des Grids ...
void grid_init(int grid[][grid_size]);

int main()
{
    int grid[grid_size][grid_size] = { 0 };
    int next_grid[grid_size][grid_size] = { 0 };

    // Erstes Grid vorbelegen ...
    grid_init(grid);

    Spielstein s1(0,0,0,0);
    s1.setze_Spielstein(grid);

    while (gip_window_not_closed())
    {
        // Spielfeld anzeigen ...
        int laufx = border;
        int laufy = border;
        for (int i = 0; i <= grid_size - 1; i++) {
            for (int j = 0; j <= grid_size - 1; j++) {
                if (grid[i][j] == 0) {
                    if (laufx > 300) {
                        laufy += 30;
                        laufx = border;
                    }
                    gip_draw_rectangle(laufx, laufy, laufx + box_size, laufy + box_size, white);
                    laufx += 30;
                }
                else if (grid[i][j] == 1) {
                    if (laufx > 300) {
                        laufy += 30;
                        laufx = border;
                    }
                    gip_draw_rectangle(laufx, laufy, laufx + box_size, laufy + box_size, green);
                    laufx += 30;
                }
                else if (grid[i][j] == 2) {
                    if (laufx > 300) {
                        laufy += 30;
                        laufx = border;
                    }
                    gip_draw_rectangle(laufx, laufy, laufx + box_size, laufy + box_size, red);
                    laufx += 30;
                }
                else if (grid[i][j] == 3) {
                    if (laufx > 300) {
                        laufy += 30;
                        laufx = border;
                    }
                    gip_draw_rectangle(laufx, laufy, laufx + box_size, laufy + box_size, red);
                    laufx += 30;
                }
            }
        }
        //gip_stop_updates(); // ... schaltet das Neuzeichnen nach jeder Bildschirm�nderung aus

        // TO DO

        // gip_start_updates(); // ... alle Bildschirm�nderungen (auch die nach dem gip_stop_updates() ) wieder anzeigen
        gip_sleep(3);

        // Berechne das naechste Spielfeld ...

        //Idee: Erstelle eine Kopie des Spielfeldes und berechne dann anhand der Kopie das neue Spielfeld.
        //Erkenne, wenn ein Feld sich am Rand befindet...
        //Kopiere Grid
        int grid_copy[grid_size][grid_size] = { 0 };
        for (int i = 0; i <= grid_size - 1; i++) {
            for (int j = 0; j <= grid_size - 1; j++) {
                grid_copy[i][j] = grid[i][j];
            }
        }
        // Durchlaufe das kopierte Grid und setze das neue Grid
        for (int i = 0; i <= grid_size - 1; i++) {
            for (int j = 0; j <= grid_size - 1; j++) {
                int count = 0;
                // I = X
                // J = Y

                // �berpr�fe Nachbarn auf G�ltigkeit und Wert

                if ((i-1 >= 0 && i-1 <= grid_size-1) && (j-1 >= 0 && j-1 <= grid_size-1)) {
                    if (grid_copy[i-1][j-1] == 1)
                        count++;
                }

                if ((i+1 >= 0 && i+1 <= grid_size - 1) && (j >= 0 && j <= grid_size - 1)) {
                    if (grid_copy[i+1][j] == 1)
                        count++;
                }

                if ((i-1 >= 0 && i-1 <= grid_size - 1) && (j >= 0 && j <= grid_size - 1)) {
                    if (grid_copy[i-1][j] == 1)
                        count++;
                }

                if ((i >= 0 && i <= grid_size - 1) && (j+1 >= 0 && j+1 <= grid_size - 1)) {
                    if (grid_copy[i][j+1] == 1)
                        count++;
                }

                if ((i >= 0 && i <= grid_size - 1) && (j-1 >= 0 && j-1 <= grid_size - 1)) {
                    if (grid_copy[i][j-1] == 1)
                        count++;
                }

                if ((i+1 >= 0 && i+1 <= grid_size - 1) && (j+1 >= 0 && j+1 <= grid_size - 1)) {
                    if (grid_copy[i+1][j+1] == 1)
                        count++;
                }

                if ((i-1 >= 0 && i-1 <= grid_size - 1) && (j+1 >= 0 && j+1 <= grid_size - 1)) {
                    if (grid_copy[i-1][j+1] == 1)
                        count++;
                }

                if ((i+1 >= 0 && i+1 <= grid_size - 1) && (j-1 >= 0 && j-1 <= grid_size - 1)) {
                    if (grid_copy[i+1][j-1] == 1)
                        count++;
                }

                //Ausz�hlung


            }
            s1.setze_Spielstein(grid);


            //Regeln: 1. Eine Zelle bleibt in einem Feld am Leben, wenn im vorigen Grid zwei oder drei der umgebenden Nachbarzellen belebt waren.
            //        2. Eine Zelle wird in einem leeren Feld neu geboren, wenn im vorigen Grid drei der umgebenden Nachbarzellen belebt waren.
            //        3. In allen anderen F�llen wird keine Zelle geboren bzw. eine dort lebende Zelle stirbt wegen zu vieler oder zu weniger Nachbarn, d.h. das Feld wird im n�chsten Spielfeld unbewohnt sein.

            // Achtung; F�r die Zelle (x,y) darf die Position (x,y) selbst *nicht*
            // mit in die Betrachtungen einbezogen werden.
            // Ausserdem darf bei zellen am rand nicht �ber den Rand hinausgegriffen
            // werden (diese Zellen haben entsprechend weniger Nachbarn) ...

            // TO DO


            // Kopiere das naechste Spielfeld in das aktuelle Spielfeld ...

            // TO DO
        }
    }
    return 0;
}

void grid_init(int grid[][grid_size])
{
    int eingabe = 0;

    if (eingabe == 0)
    {
        // Erstes Grid vorbelegen (per Zufallszahlen) ...
        // F�r jede Zeile
            // F�r jede Spalte
                // setze Wert auf gip_random(0,1);
        for (int i = 0; i <= grid_size-1; i++) {
            for (int j = 0; j <= grid_size-1; j++) {
                grid[i][j] = gip_random(0, 2);
            }
        }
        // TO DO

    }
}
