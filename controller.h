//
// Created by pankaj on 18/10/16.
//

#ifndef COL333_A4_CONTROLLER_H
#define COL333_A4_CONTROLLER_H

#include "lift_world.h"

namespace COL333_A4 {
    class controller {
        int n;
        int k;
        lift_world *world;
        lift_action *actions;
    public:
        controller(lift_world &l) : n(l.get_floor_count()), k(l.get_lift_count()), world(&l),
                                    actions(new lift_action[k]) { }

        lift_action getAction(int lift) {
            return actions[lift];
        }

        void computeActions(int tl);
    };
}
#endif //COL333_A4_CONTROLLER_H
