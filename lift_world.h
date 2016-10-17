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
        int total_buttons_pressed;
    public:
        lift(int n) : current_floor(0), drop(new bool[n]), total_buttons_pressed(0) { }

        void update_floor(int delta) {
            current_floor += delta;
        }

        void press_button(int floor) {
            drop[floor] = true;
        }

        void drop_all(int floor = current_floor) {
            if (drop[floor])
                total_buttons_pressed--;
            drop[floor] = false;
        }

        bool empty() {
            return total_buttons_pressed == 0;
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
            lifts[lift].press_button(floor);
        }
    };
}

#endif //COL333_A4_LIFT_WORLD_H
