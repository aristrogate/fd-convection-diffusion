#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int main()
{

    int nx = 41;         //Total gird points on [0,2], including both ends
    double dx = 2.0/(nx-1);     //Difference between the points 
    
    int nt = 25;    //Number of time steps
    double dt = 0.025;    //Difference between each time steps
    
    double c = 1.0;      //wavespeed
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

    ofstream outf {"output/linear-convection.csv"};

    if(!outf){
        cerr << "output/linear-convection.csv could not be opened for writing!\n";
        return 1;
    }

    outf << "x,u_initial,u\n";

    for(int i=0;i<nx;i++){
        outf << points[i] << "," << u_initial[i] << "," << u[i] << '\n';
    }

    return 0;
}