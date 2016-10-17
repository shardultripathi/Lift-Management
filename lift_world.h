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
    enum lift_action {
        AS = 0, AU = 1, AD = 2, AOU = 3, AOD = 4
    };


    class lift {
        int current_floor;
        bool *drop;
        int total;
    public:
        lift(int n) : current_floor(0), drop(new bool[n]), total(0) { }

        void update_floor(int delta) {
            current_floor += delta;
        }

        void add_person(int floor) {
            if (!drop[floor])
                total++;
            drop[floor] = true;
        }

        void drop_all(int floor = current_floor) {
            if (drop[floor])
                total--;
            drop[floor] = false;
        }

        bool empty() {
            return total == 0;
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

        void press_button(int floor, bool up) {
            (up ? U : D)[floor] = true;
        }

        void press_lift_button(int lift, int floor) {
            lifts[lift].add_person(floor);
        }
    };
}

#endif //COL333_A4_LIFT_WORLD_H
