#include<vector>
#ifndef FLOWCOMPONENT
#define FLOWCOMPONENT


class volComponent;

class flowLink
{
public:
	double DMDT;

	// ���Ӽ����κ�����ֻ��һ��Ԫ��
	volComponent* comNext;
	volComponent* comLast;

	flowLink() { comNext = nullptr; comLast = nullptr; };

	//������������
	virtual bool connect(volComponent* connectFrom, volComponent* connectTo)=0;

	/*virtual double get_DMDT() = 0;*/

};


class volComponent
{
public:
	//�����ж����������
	std::vector<flowLink*> flowNext;
	std::vector<flowLink*> flowLast;

	
	/*flowLink** flowNext;
	flowLink** flowLast;*/

	//�麯���������ݻ��ڵ�״̬
	//virtual bool update() = 0;

	//�����νڵ�������νڵ��ȡ�ýڵ����ֵ���߹����������ϵ��
	virtual double get_h() const = 0;

	virtual double get_AFA() const = 0;

	virtual double get_p() const= 0;

	virtual double get_T() const= 0;

	virtual double get_R() const= 0;

	virtual double get_k() const = 0;

};

#endif // !FLOWCOMPONENT


