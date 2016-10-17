//
// Created by pankaj on 18/10/16.
//

#ifndef COL333_A4_PARSING_H
#define COL333_A4_PARSING_H

#include <iostream>
#include "lift_world.h"

namespace COL333_A4 {

    void read_observatins(std::istream &observations, lift_world &world);

    void perform_actions(std::istream &actions, lift_world &world);
}

#endif //COL333_A4_PARSING_H
