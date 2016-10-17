//
// Created by pankaj on 18/10/16.
//

#ifndef COL333_A4_LIFT_WORLD_H
#define COL333_A4_LIFT_WORLD_H

namespace COL333_A4 {
    /*
     * AS still
     * AU up
     * AD down
     * AOU open with up display
     * AOD open with down display
     */
    enum lift_action{AS=0,AU=1,AD=2,AOU=4,AOD=5};


    class lift {
        int current_floor;
        int *drop_count;
    public:
        lift(int n) : current_floor(0), drop_count(new int[n]) { }

        void update_floor(int delta) {
            current_floor += delta;
        }
    };

    class lift_world {
        int n;
        int k;
        bool *U;
        bool *D;
        lift *lifts;
    public:
        lift_world(int n, int k) : n(n), k(k), U(new bool[n]), D(new bool[n]), lifts(new lift[2](n)) { }
    };
}

#endif //COL333_A4_LIFT_WORLD_H
