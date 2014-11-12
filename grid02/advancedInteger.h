#ifndef __advancedInteger__ 
#define __advancedInteger__ 
#include "algorithm.h"

template <class T>
class advInt{
private:
	T i, temp;
public:
	advInt(){
		i = temp = 0;
	};
	advInt(T val){
		i = val;
		temp = 0;
	};
	~advInt(){};

	//�l�����Z
	T operator+ (advInt param){
		return param.getNum() + i;
	};
	T operator+ (T param){
		return param + i;
	};
	T operator- (advInt param){
		return param.getNum() - i;
	};
	T operator- (T param){
		return param - i;
	};
	T operator* (advInt param){
		return param.getNum() * i;
	};
	T operator* (T param){
		return param * i;
	};
	T operator/ (advInt param){
		return param.getNum() / i;
	};
	T operator/ (T param){
		return param / i;
	};
	T operator% (advInt param){
		return param.getNum() % i;
	};
	T operator% (T param){
		return param % i;
	};

	//�ݏ�
	T operator^ (advInt param){
		return power<T>(i,param.getNum());
	};
	T operator^ (T param){
		return power<T>(i,param);
	};
	T operator^= (advInt param){
		return (i = power<T>(i,param.getNum()));
	};
	T operator^= (T param){
		return (i = power<T>(i,param));
	};

	//���
	advInt* operator= (advInt param){
		i = param.getNum();
		return *this;
	};

	advInt* operator= (T param){
		i = param;
		return *this;
	};

	//�C���N�������g
	T operator++ (){
		return ++i;
	};

	T operator++ (int){
		return i++;
	};

	//�f�N�������g
	T operator--(){
		return --i;
	};

	T operator-- (int){
		return i--;
	};

	//���l�Ăяo��(�Q�Ɠn��)
	T& operator() (){
		return i;
	};

	//���l�Ăяo��(�L���X�g)
	operator T(){
		return i;
	};

	//�X���b�v
	T operator<<= (advInt& param){
		temp = param.getNum();
		param = i;
		i = temp;
		return temp;
	}
	T operator>>= (advInt& param){
		temp = param.getNum();
		param = i;
		i = temp;
		return param.getNum();
	}
	
	//��r���Z�q
	bool operator>(T param){
		return (i > param);
	};
	bool operator>(advInt param){
		return (i > param.getNum());
	};
	bool operator< (T param){
		return (i < param);
	};
	bool operator< (advInt param){
		return (i < param.getNum());
	};
	bool operator>= (T param){
		return (i >= param);
	};
	bool operator>= (advInt param){
		return (i >= param.getNum());
	};
	bool operator<= (T param){
		return (i <= param);
	};
	bool operator<= (advInt param){
		return (i <= param.getNum());
	};

	//���l�Ăяo��(���̓n��)
	T getNum(){
		return i;
	};
};

#endif
