#include <concat_mat.h>

#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <fstream>
#include <ostream>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//ostream& operator<<(ostream& os,const  data_chunk  &A)
//{
//    os.precision(3);
//    os << "[";

//    os <<"R="<< A.r <<"G="<<A.g<<"B="<<A.b<<"A="<<A.a;

//    os << "]";
//    return os;
//}

ostream& operator<<(std::ostream& os,const mat  &A)
{

    for (int i = 0; i < A.h; ++i)
    {
        os.precision(6);
        os << "[";
        for (int j = 0; j < A.w; ++j)
        {
            os << A.at_value_float(i,j) <<std::setw(10);
        }
        os << "]"<<endl;
    }

    return os;
}

concat_mat::concat_mat():ind(rect_t(0,0,2,2))
{

}

void concat_mat::multiply_mat(mat  &in_matrix,
                              mat  &convol_core,
                              mat  &out,
                              TYPE_BOUNDARY_CONDITION type)
{

    cout<<in_matrix<< endl;
    cout<<convol_core<< endl;




    cout<<"core"<<endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {

            // cout<< in_matrix.at_value_float(0,i)<<endl;
            cout<<convol_core.at_value_float(i,j)<<endl;

        }
    }



    if(type==SYMMETRY)
    {

    }
    else if(type==NULLS_BOUNDARY)
    {

    }
    else if(type==NO_BOUNDARY)
    {



        float res11=    in_matrix.at_value_float(0,0) * convol_core.at_value_float(0,0)+
                in_matrix.at_value_float(0,1) * convol_core.at_value_float(0,1)+
                in_matrix.at_value_float(1,0) * convol_core.at_value_float(1,0)+
                in_matrix.at_value_float(0,1) * convol_core.at_value_float(0,1);

        float res12=    in_matrix.at_value_float(0,1) * convol_core.at_value_float(0,0)+
                in_matrix.at_value_float(0,2) * convol_core.at_value_float(0,1)+
                in_matrix.at_value_float(1,1) * convol_core.at_value_float(1,0)+
                in_matrix.at_value_float(1,2) * convol_core.at_value_float(0,1);
        //

        float res21=    in_matrix.at_value_float(1,0) * convol_core.at_value_float(0,0)+
                in_matrix.at_value_float(1,1) * convol_core.at_value_float(0,1)+
                in_matrix.at_value_float(2,0) * convol_core.at_value_float(1,0)+
                in_matrix.at_value_float(2,1) * convol_core.at_value_float(0,1);

        float res22=    in_matrix.at_value_float(1,1) * convol_core.at_value_float(0,0)+
                in_matrix.at_value_float(1,2) * convol_core.at_value_float(0,1)+
                in_matrix.at_value_float(2,1) * convol_core.at_value_float(1,0)+
                in_matrix.at_value_float(2,2) * convol_core.at_value_float(0,1);
        cout<<res11<<" "<<res12<<" "<<res21<<" "<<res22<<endl;


        out=mat(2,2);
        out.push_back_float(res11);
        out.push_back_float(res12);
        out.push_back_float(res21);
        out.push_back_float(res22);

        cout<<out;
    }


}



void concat_mat::add_mirror(mat &mat,int n)
{
    for (int i = 0; i < mat.w; ++i)
    {
        //     mat.data.insert(0,mat.at(1,i));
        //   std::cout<<" "<<;
    }
}

void concat_mat::load_matrix(const char *filepath,  mat &A)
{
    auto f=std::fstream(filepath);
    if (!f)
    {
        std::cout << "\nФайл не открыт\n\n";

    }
    else
    {
        std::cout << "\nФайл открыт:\n"<<filepath<<"\n";
    }
    char separator;
    f>>A.h;
    f>>separator;

    f>>A.w;
    f>>separator;
    while( !f.eof() )
    {

        data_chunk s;
        char separator;
        float d;
        f >>d;

        f >> separator;
        A.push_back_float(d);


    }
    A.data.pop_back();

    f.close();
}

data_chunk* mat_t::at(int x, int y)
{
    return &this->data.at(x*this->w+y);
}

int mat_t::at_value_int(int x, int y)
{
    data_chunk* t=  &this->data.at(x*this->w+y);
    int res;
    int * res_int_ptr=&res;

    char *res_ptr= (char*)res_int_ptr ;
    res_ptr[0]=t->r;
    res_ptr[1]=t->g;
    res_ptr[2]=t->b;
    res_ptr[3]=t->a;


    return res;
}

float mat_t::at_value_float(int x, int y)const
{
    const data_chunk* t=  &this->data.at(x*this->w+y);
    float res;
    float * res_int_ptr=&res;

    char *res_ptr= (char*)res_int_ptr ;
    res_ptr[0]=t->r;
    res_ptr[1]=t->g;
    res_ptr[2]=t->b;
    res_ptr[3]=t->a;


    return res;
}

void mat_t::push_back_float(float val)
{




    data_chunk t;

     memcpy(&t,&val,sizeof (float));


    this->data.push_back(t);
}

void mat_t::push_back_int(int val)
{
    data_chunk d;

    int * res_int_ptr=&val;

    char *res_ptr= (char*)res_int_ptr ;
    d.r=res_ptr[0];
    d.g=res_ptr[1];
    d.b=res_ptr[2];
    d.a=res_ptr[3];

    this->data.push_back(d);
}

