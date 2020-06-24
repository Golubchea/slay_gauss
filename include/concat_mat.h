#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <ostream>
#include <iomanip>
typedef struct rect_t
{
    rect_t(int _x,int _y,int _w,int _h){x=_x;y=_y;w=_w;h=_h;};
    int x;
    int y;
    int w;
    int h;
}rect;

typedef struct data_chunk
{


    friend data_chunk operator*(const data_chunk  & lhs, data_chunk & rhs)
    {
        data_chunk t;

        t.a=lhs.a*rhs.a;
        t.r=lhs.r*rhs.r;
        t.g=lhs.g*rhs.g;
        t.b=lhs.b*rhs.b;
        return t;
    }

    friend data_chunk operator/(const data_chunk  & lhs, data_chunk & rhs)
    {
        data_chunk t;

        t.a=lhs.a/rhs.a;
        t.r=lhs.r/rhs.r;
        t.g=lhs.g/rhs.g;
        t.b=lhs.b/rhs.b;
        return t;
    }

    friend data_chunk operator+(const data_chunk  & lhs, data_chunk & rhs)
    {
        data_chunk t;

        t.a=lhs.a+rhs.a;
        t.r=lhs.r+rhs.r;
        t.g=lhs.g+rhs.g;
        t.b=lhs.b+rhs.b;
        return t;
    }

    friend data_chunk operator-(const data_chunk  & lhs, data_chunk & rhs)
    {
        data_chunk t;

        t.a=lhs.a-rhs.a;
        t.r=lhs.r-rhs.r;
        t.g=lhs.g-rhs.g;
        t.b=lhs.b-rhs.b;
        return t;
    }
    char r;
    char g;
    char b;
    char a;
}data_chunk ;




typedef struct mat_t
{


    std::vector<data_chunk>data;
    int w;
    int h;
     data_chunk * at(int x,int y);
     int at_value_int(int x, int y);
     float at_value_float(int x, int y) const;
     void push_back_float(float val);
     void push_back_int(int val);
     mat_t(int _w,int _h):w(_w),h(_h)
     {
     this->data.resize(w*h);
     };
     mat_t():w(0),h(0)
     {

     };

}mat;

enum TYPE_BOUNDARY_CONDITION{
    SYMMETRY,
    NULLS_BOUNDARY,
    NO_BOUNDARY
};





class concat_mat
{
public:
    concat_mat();
    void multiply_mat(    mat &mat_in,
                          mat &core,
                          mat &out,TYPE_BOUNDARY_CONDITION NULLS_BOUNDARY);

    void add_mirror( mat &mat,int n);

    void load_matrix(const char * filepath,mat &A);

private:
    rect ind;
};




