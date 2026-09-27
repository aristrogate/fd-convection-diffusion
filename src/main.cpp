#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

int nx = 41;
double dx = 2.0/(nx-1);
int main()
{
    cout << setprecision(17);
    vector<double> points;
    vector<double> u;

    for(int i=0;i<nx;i++){
        double x = i*dx;
        points.push_back(x);
    }

    for(auto x_val: points){
        if(x_val>=0.5 && x_val<=1){
            u.push_back(2);
        }

        else{
            u.push_back(1);
        }
    }

    ofstream outf {"output/initial.csv"};

    if(!outf){
        cerr << "output/initial.csv could not be opened for writing!\n";
        return 1;
    }

    outf << "x,u\n";

    for(int i=0;i<nx;i++){
        outf << points[i] << "," << u[i] << '\n';
    }

    return 0;
}