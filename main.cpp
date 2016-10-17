#include <iostream>
#include "lift_world.h"
#include "parsing.h"
using namespace std;
using namespace COL333_A4;
void assignment(int n,int k,double p,double q,double r,int tl) {
    string obs;
    cout << "0\n";

}

int main(int argc,char*argv[]) {
    int tl = int(atof(argv[6]) * 1000);
    assignment(atoi(argv[1]), atoi(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]), tl);
    return 0;
}