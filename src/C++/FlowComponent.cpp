#include "FlowComponent.h"

//bool flowLink::connect(volComponent* connectFrom, volComponent* connectTo)
//{
//	//���ε����νڵ�Ϊ���ڵ�
//	connectFrom->flowNext.push_back(*this);
//
//	//���ε����νڵ�Ϊ���ڵ�
//	connectTo->flowLast.push_back(*this);
//
//	return true;
//}

//template<class T>
//bool flowLink::connect(T* connectFrom, T* connectTo)
//{
//	//������������
//	volComponent* connectFrom1 = (volComponent*)connectFrom;
//
//	volComponent* connectTo1 = (volComponent*)connectTo;
//
//	//���ε����νڵ�Ϊ���ڵ�,���ӵ����νڵ�Ϊ
//	connectFrom1->flowNext.push_back(*this);
//	comLast = connectFrom1;
//
//	//���ε����νڵ�Ϊ���ڵ�
//	connectTo1->flowLast.push_back(*this);
//	comNext = connectTo1;
//	return true;
//}
