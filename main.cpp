#include <iostream>
#include <sstream>
#include "lift_world.h"
#include "parsing.h"
#include "controller.h"

using namespace std;
using namespace COL333_A4;
void assignment(int n,int k,double p,double q,double r,int tl) {
    string obs;
    lift_world world(n, k);
    controller c(world);
    cout << "0\n";
    while (cin >> obs) {
        stringstream observations(obs);
        read_observatins(observations, world);
        c.computeActions(tl);
        for (int i = 0; i < k; i++)
            cout << c.getAction(i) << i + 1 << ' ';
        for (int i = 0; i < k; i++)
            if (c.getAction(i) == AU)
                world.getLift(i)->update_floor(1);
            else if (c.getAction(i) == AD)
                world.getLift(i)->update_floor(-1);
        /*for (int i = 0; i < k; i++)
            cerr << world.getLift(i)->getFloor() + 1 << ' ';
        cerr << '\n';*/
        cout << '\n';
        cout.flush();
    }
}

int main(int argc,char*argv[]) {
    if (argc > 1) {
        int tl = int(atof(argv[6]) * 1000);
        assignment(atoi(argv[1]), atoi(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]), tl);
    }
    else {
        std::cout << "enter N K p q r t\n";
        int n, k;
        double p, q, r, t;
        cin >> n >> k >> p >> q >> r >> t;
        assignment(n, k, p, q, r, int(t * 1000));
    }
    return 0;
}