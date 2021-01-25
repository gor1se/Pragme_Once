#include "Spielstein.h"
#include "CImgGIP05.h"
#include <stdlib.h>

void Spielstein::draw_Spielstein(int x1, int y2, int size) {
	gip_draw_rectangle(x1, y2, x1 + size, y1 + size, black);
}

void Spielstein::setze_Spielstein(int grid[][10], int size1, int size2) {
	bool set = false;
	while (!set) {
		int i = rand() % 9 + 0;
		int j = rand() % 9 + 0;
		if (grid[i][j] == 0) {
			grid[i][j] = 3;
			set = true;
		}
	}
}