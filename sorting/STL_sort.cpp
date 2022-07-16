// source code from https://m.blog.naver.com/ndb796/221227975229?referrerCode=1 and modified

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
/*
bool compare(int a, int b){
	return a > b;
}

int main(void){
	int N;
	int* num_array;
	cin >> N;
	num_array = new int[N];
	for (int i = 0; i < N; i++) cin >> num_array[i];
	
	sort(num_array, num_array + N, compare); // first element address, last element address + 1, compare function 
	
	for (int i = 0; i < N; i++) cout << num_array[i];
	
	delete[] num_array;
}
*/

class Student{
public:
	string name;
	int score;
	Student(string name, int score){
		this->name = name;
		this->score = score;
	}
	
	bool operator <(Student &student){ // if student1 < student2 , then return student1.score < student2.score
		return this->score < student.score;
	}
	
	bool operator >(Student &student){ // if student1 > student2 , then return student1.score > student2.score
		return this->score > student.score;
	}
	
};

bool compare(Student a, Student b){
	return a > b;
}

int main(void){
	Student students[] = {
		Student("Paul", 90),
		Student("Amy", 93),
		Student("Ben", 97),
		Student("Caroline", 87),
		Student("David", 92)
	};
	sort(students, students + 5, compare);
	for(int i = 0; i < 5; i++){
		cout << students[i].name << ' ';
	}
	cout << endl;
}
