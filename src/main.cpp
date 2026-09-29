#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;


int main()
{

    int nx = 321;         //Total grid points on [0,2], including both ends
    double courant_number = 0.5;    // courant number = c*(dt/dx)
    double distance = 0.625;    // Total distance travelled by wave pattern
    double c = 1.0;      //wavespeed

    double dx = 2.0/(nx-1);     //Difference between the points 
    double dt = (dx*courant_number)/c;    //Difference between each time steps
    int nt = round(distance/(c*dt));    //Number of time steps
    
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

    vector<double> u_old = u;
    vector<double> u_initial = u;

    for(int time_stamp=0;time_stamp<nt;time_stamp++){
        for(int i=1;i<nx;i++){
            u[i] = u_old[i] - c*(dt/dx)*(u_old[i]-u_old[i-1]);
        }
        u_old = u;
    }

    string filename = "output/convection_nx" + to_string(nx) + ".csv";

    ofstream outf {filename};

    if(!outf){
        cerr << filename << " could not be opened for writing!\n";
        return 1;
    }

    outf << "x,u_initial,u\n";

    for(int i=0;i<nx;i++){
        outf << points[i] << "," << u_initial[i] << "," << u[i] << '\n';
    }

    return 0;
}