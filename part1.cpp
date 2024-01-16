//
// Created by Jun chi Zhu on 1/11/24.
//

#include <iostream>
#include <vector>
#include <random>
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

vector<vector<int> > matrix_multiplication(int num){
    vector<vector<int> > result(num, vector<int>(num, 0));

    vector<vector<int> > matrix_one = matrix_generator(num);
    cout<<"matrix one: "<<endl;
    matrix_pinter(matrix_one);
    vector<vector<int> > matrix_two = matrix_generator(num);
    cout<<"matrix two: "<<endl;
    matrix_pinter(matrix_two);

    for(int i=0;i<num;++i){
        for(int j=0;j<num;++j){
            for(int k=0;k<num;++k){
                result[i][j] += matrix_one[i][k] * matrix_two[k][j];
            }
        }
    }
    return result;
}

int main(){
    double time_begin, time_end;
    get_walltime(&time_begin);
    vector<vector<int> > matrix = matrix_multiplication(100);
    cout<<"result: "<<endl;
    matrix_pinter(matrix);
    get_walltime(&time_end);

    cout<<"Performance: "<<(time_end-time_begin)<<endl;
}
