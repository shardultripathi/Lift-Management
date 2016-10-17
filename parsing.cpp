//
// Created by pankaj on 18/10/16.
//

#include <cstring>
#include "parsing.h"
//BD_ln_fn
//

void COL333_A4::read_observatins(std::istream &observations, lift_world &world) {
    char action[20];
    while (observations >> action) if(action[0]){
        if (action[1] == '_') {//inside lift button press
            char *floor = std::strtok(action, "_");//floor
            *floor++ = 0;
            char *lift_no = std::strtok(floor, "_");//
            *lift_no++ = 0;
            int fl = std::atoi(floor);
            int ln = std::atoi(lift_no);
            world.press_lift_button(ln, fl);
        } else {
            char *floor = std::strtok(action, "_") + 1;
            bool up = action[1] == 'U';
            world.press_button(atoi(floor), up);
        }
    }
}