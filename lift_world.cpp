//
// Created by pankaj on 18/10/16.
//

#include "lift_world.h"
#include <iostream>
namespace COL333_A4 {
    std::ostream &operator<<(std::ostream &o, COL333_A4::lift_action action) {
        switch (action) {
            case AS:
                o << "AS";
                break;
            case AD:
                o << "AD";
                break;
            case AU:
                o << "AU";
                break;
            case AOD:
                o << "AOD";
                break;
            case AOU:
                o << "AOD";
                break;
        }
        return o;
    }
}