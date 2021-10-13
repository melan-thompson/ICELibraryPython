#pragma once
#ifndef PARAMETERTABLE_H
#define PARAMETERTABLE_H
#include <iostream>
#include <vector>



class para
{
public:
    std::string parameter_name;
    std::string parameter_unit;
    double parameter_value;
    para() 
    {
        parameter_name = "EmptyName";
        parameter_unit = "EmptyUnit";
        parameter_value = -INFINITY;
    };
    para(std::string paraName, std::string paraUnit, double value)
        :parameter_name(paraName),parameter_unit(paraUnit),parameter_value(value)
    {

    }
    
};

class ParameterTable
{
public:
    std::vector<para> table;
    int num_of_row;
    std::string table_name;

    ParameterTable(int row=0, std::string name="");
    ParameterTable(std::string filename, std::string start = "", int row = 0);
    ~ParameterTable(){};
    ////////////////////////////////////////////////////////////////////////
    /////////////////////////����Ϊ�ļ���ȡ����///////////////////////////////
    //Ĭ�ϱ��ʼ����Ϊ�գ����ӵ�һ����Ϊ�յ��п�ʼ��ȡһֱ����������
    //Ĭ�ϲ�֪������������Զ��ж�������Ҳ�����Լ�ѡȡ��ȡ������
    bool readInFile(std::string filename, std::string start = "", int row = 0);


    //////////////////////////����Ϊ�������//////////////////////////////
    bool writeToFile(std::string filename, int mode = 0, std::string title = "");
    void show();

    /////////////////////////����Ϊ�޸Ĳ���//////////////////////////////////
    /////////////////////////////////////////////////////////////////////
    template <class T> bool setParasName(T& str);
    template <class T> bool setParasUnit(T& str);
    template <class T> bool setParasValue(T& arr);
    bool append(std::string paraName, std::string paraUnit, double value);

    /////////////////////////����Ϊ�����Ҳ���////////////////////////////////
    double searchValue(std::string index);
    std::string searchUnit(std::string index);  

    ///////////////////////// ����Ϊͳ�Ʋ���////////////////////////////////////
    double sum(int start, int end);
    

private:
    void setUnit2SI();        
};

#endif // !PARAMETERTABLE_H
