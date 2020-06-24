#include <iostream>
#include <iomanip>
#include <vector>

#include <slay_gauss.h>
#include <concat_mat.h>


#include <chrono>
ostream& operator<<(ostream& os,const  vector <double>  &A);


using namespace std;
int main()
{

    setlocale(LC_ALL, "Russian");
    vector<vector <double> >A;

    vector <double> answer;

    slay_gauss solver;
    vector <double> sustainability_row;
    double sustainability_diag;

    solver.load_matrix("data.csv",A);


    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();


    solver.solve(A,answer,sustainability_row,sustainability_diag);
    end = std::chrono::system_clock::now();

    long elapsed_seconds = std::chrono::duration_cast<std::chrono::microseconds>
            (end-start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);

    std::cout << "Вычисления начаты в " << std::ctime(&start_time)<<
                 "Вычисления закончены в " << std::ctime(&end_time)
              << "Время выполнения: " << elapsed_seconds << " micro секунд\n"<<"ответ:";

    cout<<"\n устойчивость решения по строке: "<<sustainability_row;
    cout<<"\n устойчивость решения по диагонали: "<<sustainability_diag;
    for (int i = 0; i < answer.size(); ++i)
    {
        cout<<"\n ответ:"<<answer.at(i);

    }


concat_mat conc;
mat A_in;
conc.load_matrix("A.csv",A_in);
mat B_in;
conc.load_matrix("B.csv",B_in);


mat res;
//cout<<A_in.at(0,3);
 conc.multiply_mat(A_in,B_in,res,NO_BOUNDARY);

    return 0;
}
