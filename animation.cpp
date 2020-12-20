#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"
using namespace std;

int main(){
    const int left_border = 100;
    const int right_border = 500;

    int x = 200, y = 300;
    const int rectangle_size = 50;
    int delta = 10;
    bool moveright = true;

    gip_white_background();
    while (gip_window_not_closed())
    {
        gip_draw_rectangle(left_border, 100, right_border, 500, blue);
        gip_draw_rectangle(x,y, x + rectangle_size, y + rectangle_size, white);

        if (moveright){
            if (x < right_border - rectangle_size){
                x += delta;
            } else {
                x -= delta;
                moveright = false;
            }
        if (!moveright){
            if (x > left_border - rectangle_size){
                x -= delta;
            } else {
                x += delta;
                moveright = true;
            }
        }
        gip_wait(100);
    }
    return 0;
}