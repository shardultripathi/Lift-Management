//
// Created by pankaj on 18/10/16.
//

#include <cstring>
#include "parsing.h"
//BD_ln_fn
//

void COL333_A4::read_observatins(std::istream &observations, lift_world &world) {
    char action[20];
    while (observations >> action)
        if (action[0] != '0') {
            if (action[1] == '_') {//inside lift button press
                char *floor = action + 2;//floor
                char *lift_no = std::strchr(floor, '_');//
                *lift_no++ = 0;
                int fl = std::atoi(floor);
                int ln = std::atoi(lift_no);
                std::cerr << fl << ' ' << ln << " pressed\n";
                world.press_lift_button(ln, fl);
            } else {
                char *floor = action + 3;
                bool up = action[1] == 'U';
                std::cerr << atoi(floor) << ' ' << up << " pressed\n";
                world.press_button(atoi(floor), up);
            }
        }
}