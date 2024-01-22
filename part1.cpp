//
// Created by Jun chi Zhu on 1/11/24.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <cmath>
#include <iomanip>
#include "get_walltime.c"

using namespace std;

vector<vector<int> >matrix_generator(int num) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> number(1, 10);
    vector<vector<int> > matrix(num, vector<int>(num, 0));
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            matrix[i][j] = number(gen);
        }
    }
    return matrix;
}

void matrix_pinter(const vector<vector<int> >& matrix_temp){
    for (vector<int> row: matrix_temp) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

double matrix_multiplication(int num){
    double time_begin, time_end;
    vector<vector<int> > result(num, vector<int>(num, 0));

    vector<vector<int> > matrix_one = matrix_generator(num);

    vector<vector<int> > matrix_two = matrix_generator(num);

    get_walltime(&time_begin);

    for(int i=0;i<num;++i){
        for(int j=0;j<num;++j){
            for(int k=0;k<num;++k){
                result[i][j] += matrix_one[i][k] * matrix_two[k][j];
            }
        }
    }

    get_walltime(&time_end);

    //cout<<"Performance: "<<(time_end-time_begin)<<endl;
    return time_end-time_begin;
}

double getMflops(int num) {
    double average_time = 0.0;
    /// reduce noise by taking avg of 100 tries
    for(int i=0;i<100;++i){
       average_time += matrix_multiplication(num);
    }
    average_time/=100;

    cout<<"Average Time Computing: " << average_time<<endl;
    double Mflop_s = (pow(num,3)*2)/average_time/pow(10,6);
    cout << scientific << setprecision(2);
    cout<<"Performance in Mflop/s(scientific format): " << Mflop_s<<endl;
    cout << fixed << setprecision(2);
    cout<<"Performance in Mflop/s: " << Mflop_s<<endl;
    return Mflop_s;
}

double getGflops(int num) {
    double average_time = 0.0;
    /// reduce noise by taking avg of 100 tries
    for(int i=0;i<100;++i){
       average_time += matrix_multiplication(num);
    }
    average_time/=100;
    
    cout<<"Average Time Computing: " << average_time<<endl;
    double Gflop_s = (pow(num,3)*2)/average_time/pow(10,9);
    cout << scientific << setprecision(2);
    cout<<"Performance in Gflop/s(scientific format): " << Gflop_s<<endl;
    cout << fixed << setprecision(2);
    cout<<"Performance in Gflop/s: " << Gflop_s<<endl;
    return Gflop_s;
}

int main(){
    ///q3
    //getMflops(100);

    ///q5
    std::vector<int> Ns ={0, 10, 30, 80, 160, 280, 420, 610, 830, 1100, 1420, 1780, 2200, 2670, 3190, 3770, 
    4410, 5110, 5870, 6700, 7590, 8560, 9590, 10690, 11860, 13110, 14440, 15840, 17320, 18880, 20530, 22250, 24060, 
    25960, 27940, 30010, 32170, 34420, 36760, 39200, 41730, 44350, 47070, 49890, 52810, 55830, 58950, 62170, 65490, 68920, 
    72460, 76100, 79850, 83710, 87670, 91750, 95940, 100250, 104660, 109190, 113840, 118600, 123490, 128490, 133610, 138850, 
    144210, 149690, 155300, 161030, 166880, 172870, 178980, 185210, 191580, 198070, 204700, 211450, 218340, 225360, 232520, 239810, 247230, 
    254790, 262490, 270330, 278300, 286420, 294670, 303070, 311610, 320290, 329110, 338080, 347190, 356450, 365860, 375410, 385110, 394960, 494960, 
    594960, 694960, 794960, 894960, 994960, 1094960, 1194960, 1294960, 1394960, 1494960, 1594960, 1694960, 1794960, 1894960, 1994960, 2094960, 2194960, 
    2294960, 2394960, 2494960, 2594960, 2694960, 2794960, 2894960, 2994960, 3094960, 3194960, 3294960, 3394960, 3494960, 3594960, 3694960, 3794960, 3894960, 
    3994960, 4094960, 4194960, 4294960, 4394960, 4494960, 4594960, 4694960, 4794960, 4894960, 4994960, 5094960, 5194960, 5294960, 5394960, 5494960, 5594960, 5694960, 
    5794960, 5894960, 5994960, 6094960, 6194960, 6294960, 6394960, 6494960, 6594960, 6694960, 6794960, 6894960, 6994960, 7094960, 7194960, 7294960, 7394960, 7494960, 7594960, 
    7694960, 7794960, 7894960, 7994960, 8094960, 8194960, 8294960, 8394960, 8494960, 8594960, 8694960, 8794960, 8894960, 8994960, 9094960, 9194960, 9294960, 9394960, 9494960, 
    9594960, 9694960, 9794960, 9894960, 9994960, 10000000};
    
    std::vector<double> Gflops;

    for (int n : Ns) {
        cout << "Current n: " << n << endl;
        double gflop = getGflops(n);
        Gflops.push_back(gflop);
    }

    std::ofstream outFile("gflops.txt");
    if (outFile.is_open()) {
        for (size_t i = 0; i < Gflops.size(); ++i) {
            outFile << Gflops[i] << ",";
        }
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }

    return 0;
}
