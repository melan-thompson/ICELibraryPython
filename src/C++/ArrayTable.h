#ifndef ARRAYTABLE_H
#define ARRAYTABLE_H
#include <iostream>
#include <vector>

template <class Type>
class PhysicalVarList
{
public:
    std::string ColName;
    std::string ColUnit;
    std::vector<Type> data;

    PhysicalVarList(int row = 0);

    //�����<<����
    friend std::ostream& operator<<(std::ostream& out, PhysicalVarList L);

    bool add(Type num);

    bool Multiply(double num, std::string new_unit = "EmptyUnit");
};

class ArrayTable
{
public:
    unsigned int col, row;
    std::vector<PhysicalVarList<double>> table;
    std::string table_name;

    ArrayTable() {};
    ~ArrayTable() {};
    ArrayTable(int _col, int _row = 0, std::string _tablename = "");
    ArrayTable(std::string _filename, std::string _start = "");

    ////////////////////////���뵽�����/////////////////////////////////
    bool readInFile(std::string _filename, std::string _start="",char delimiter=',');
    //�����ļ�����������ȡ����������ʼ�ַ������ʼ�ַ�Start��ʼ��ȡ�����û����Ӷ�ȡ���ĵ�һ����Ϊ�յ��п�ʼ��ȡ��
    //ӦҪ���Զ��ж϶�ȡ����
    ////////////////////////����Ϊ����ȡ���ݲ���////////////////////////


    ////////////////����Ϊ�������//////////////////
    void show();//�������д�ӡ�������
    void show(int column);//չʾ��column�е�����
    enum class write_to_file_type { append2file, truncate2file };
    bool writeToFile(std::string filename, write_to_file_type mode= write_to_file_type::truncate2file);//������ļ�
    void openWithProgram();
    std::vector<double> selectRowValue(int _row);//��ȡ��row��һ����¼
    bool plot(int _coly=1,int _colx=0);
    ///////////////�����չʾ����////////////////////

    ///////////////////////////////////////////////
    ///////////////����Ϊ�޸Ĳ���////////////////////
    ///////////////////////////////////////////////
    void setUnit2SI();//����λ����ΪSI��λ
    bool setRowValue(int _row, std::vector<double> _arr);//�޸ĵ�row�еļ�¼
    bool exchageRowValue(int _row1, int _row2);//����row1��row2��ֵ
    bool append(std::vector<double> arr);
    bool setParaName(std::vector < std::string> _arr);
    bool setParaUnit(std::vector < std::string> _arr);
    void pop();

    ////////////////���������ݲ���////////////////////
    void Clear();

    ////////////////////////////////////////////////
    ///////////////����Ϊ�޸Ĳ���//////////////////////
    ///////////////////////////////////////////////



    ///////////////////��ѯ����///////////////////////
    ////////////��ĳһ�����ֵ���Ӧ����///////////////
    int findMaxDataIndex(int _col);

    int findMinDataIndex(int _col);

    ///////////////�ҳ����еļ���ֵ���Ӧ���У�Ĭ�ϴ���ǰ���������ֵ/////////////////
    std::vector<int> findMaximumDataIndex(int _col, int _order = 2);

    int findMaxDataIndex(int _col) const;

    int findMinDataIndex(int _col) const;

    double findMaxData(int _col) const;

    double findMinData(int _col) const;

    ////////////////////////////////////////////////
    ///////////////����Ϊͳ�Ʋ���/////////////////////
    ////////////////////////////////////////////////
    double sumAll(int column) const;

    double quasierror(int _col, double mean = 0) const;

    void doQuickSort(int _col);//�Ա���������

    ////////////////////////////////////////////////////////
    ///////////////����Ϊ��ֵ�����֡�΢�ֲ���////////////////////
    ////////////////////////////////////////////////////////
    double linearInterpolate(double x, int columny = 1,int columnx=0,int type=0);//�Ե�column�����Բ�ֵ�����ز�ֵ���
                                                                  //type=0,ѭ����ֵ��type=1��ѭ��,������Χ��Ϊ0;
    
    //////////////////////FFT��ֵ���������������ԣ�����Ҫ���Ա��������ǵȼ���ģ�����׼///////////////
    /////////////////x��ֵ�㣬x_col��ֵ��x��column y������//////////////////////////
    //////////////////////��ֵЧ��������///////////////////////////////////////////
    double triInterpolate(double _x, int _coly = 1, int _colx = 0);
    double Integrate(int _coly, int _start, int _end,int _colx=0);//column�У���start��end�л���
    void diff(int _coly, int _colx = 0);

private:
    void QuickSort(int _col, ArrayTable point[], int low, int high);
};



#endif // !PARAMETERTABLE_H
