//
// Created by pankaj on 18/10/16.
//

#include <cmath>
#include "controller.h"
void COL333_A4::controller::computeActions(int tl) {
    bool answered[n][2];
    for (int i = 0; i < n; i++)
        answered[i][0] = answered[i][1] = false;
    for (int l = 0; l < k; l++) {
        int mind = n;
        int mini = -1;
        for (int i = 0; i < n; i++)
            if (!answered[i][0] && world->getPressed(i, true) ||
                !answered[i][1] && world->getPressed(i, false) && std::abs(i - world->getLift(l)->getFloor())) {
                mini = i;
                mind = (int)std::abs(i - world->getLift(l)->getFloor());
            }
        if (mini == -1)
            actions[l] = AS;
        else {
            if (world->getPressed(mini, true))
                answered[mini][0] = true;
            else answered[mini][1] = true;
            if (mind == 0) {
                if (world->getPressed(mini, true))
                    actions[l] = AOU;
                else if (world->getPressed(mini, false))
                    actions[l] = AOD;
            }
            else {
                if (mini > world->getLift(l)->getFloor())
                    actions[l] = AU;
                else actions[l] = AD;
            }
        }
    }
}