#include <iostream>
#include <string>
using namespace std;

class person {
private: 
	string name;
	int age;
public:
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	person();
	person(string a) : name(a), age(18) {};
	person(int g) : name("default"), age(g) {};
	person(string a, int g) : name(a), age(g) {};
};
person::person() {
		name = "default";
		age = 18;
	}

class worker : public person{
	
	
public:
	worker() : person() {};
	worker(string a) : person(a) {};
	worker(int g) : person(g) {};
	worker(string a, int g) : person(a, g) {};

	virtual void working() {
		cout << "I do something\n";
	}
};
class programmer :public worker{
	//using worker::worker;
public:
	programmer() : worker() {};
	programmer(string a) : worker(a) {};
	programmer(int g) : worker(g) {};
	programmer(string a, int g) : worker(a, g) {};
	void working() override {
		cout << "I do programms\n";
	}
	
};
class professor : public programmer, public worker{



public:
	professor() : programmer(), worker() {};
	professor(string a) : programmer(a), worker(a) {};
	professor(int g) : programmer(g), worker(g) {};
	professor(string a, int g) : programmer(a, g), worker(a, g) {};
	void working() override{
		cout << "I teach undergraduates\n";
	}
};
class taxist: public worker {
	using worker::worker;
public:
	void working() {
		cout << "I drive passengers\n";
	}
};
class banker : public worker {
	using worker::worker;
	
public:
	void working() {
		cout << "I count money\n";
	}
};



int main() {

	/*person gfox("maksim", 18);
	worker gwolf("nick");
	banker name("maksim", 32);
	programmer gcarr("fill",26);

	cout << gcarr.getName() << endl;
	gcarr.working();
	

	worker * csens = new taxist;

	cout << csens->getAge() << endl;
	csens->working();

	worker * arr[5];
	worker * ptr[5];
	ptr[0] = new programmer ("Vasilij");
	arr[0] = ptr[0];

	ptr[1] = new taxist ("Anatolij");
	arr[1] = ptr[1];

	ptr[2] = new banker("Anna");
	arr[2] = ptr[2];

	ptr[3] = new programmer ("Alice");
	arr[3] = ptr[3];

	for (int i = 0; i < 4; i++) {
		cout << ptr[i]->getName() << endl;
		ptr[i]->working();
		cout << endl;
	}

	banker newBanker;
	cout << newBanker.getName();*/
	

	professor mm("Maksim");
	cout << mm.programmer::getName() << endl;
	cout << mm.worker::getName() << endl;
	//cout << mm->professor::getName() << endl;

	mm.worker::working();
	mm.programmer::working();
	mm.professor::working();
	



	system("pause");
	return 0;
}