#include<conio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct SinhVien {
	string mssv;
	string Name;
	string Class;
	string Address;
	float Algebra;
	float Analytics;
	float Gpa;
	float Cpa;
};

typedef struct SinhVien sinhvien;
struct node {
	sinhvien *data;
	struct  node* next;
};
typedef struct node Node;
struct list {
	Node* pHead;
	Node* pTail;
};


typedef struct list List;
void Input_SinhVien(sinhvien *sv);//ham nhap cua danh sach
Node *CreateNode();
void CreateList(List &l);
void ThemVaoDauMotSinhVien(List &l, Node *p);
void Output_SinhVien();
void ChucNang(List &l);
void QuickSort(List &l );
void search(List l );
void showNode(Node *k);
void upgrade(List& l);
void DelStudent(List& l);
void DanhSachSinhVienChuaXepLop(List l);

int main() {
	List l;
	CreateList(l);
	ChucNang(l);
	system("pause");
	return 0;
}

void CreateList(List &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
void QuickSort(List &l ){
	List l1, l2;
	Node *pivot, *p;
	if(l.pHead == l.pTail ) return;
	CreateList(l1); CreateList(l2);
	pivot = l.pHead;
	l.pHead = l.pHead->next; // cap nhat lai l.head
	pivot->next = NULL;// co lap pivot
	while( l.pHead!= NULL ){
		p = l.pHead;
		l.pHead = l.pHead->next;
		p->next = NULL;
		if(p->data->Cpa <= pivot->data->Cpa ) ThemVaoDauMotSinhVien(l1,p);
		else ThemVaoDauMotSinhVien(l2,p);
	}
	QuickSort(l1); // goi de qui sap xep l1, l2
	QuickSort(l2);
	if(l1.pHead != NULL ){ // l1 k rong
		l.pHead = l1.pHead; // lay head cua l1 gan cho head cua l;
		l1.pTail->next = pivot;
	} // l1 rong 
	else l.pHead = pivot;
	pivot->next = l2.pHead;
	if(l2.pHead!= NULL ) l.pTail = l2.pTail;
	else l.pTail = pivot;
}

void Input_SinhVien( sinhvien *sv )//ham nhap cua danh sach
{
	cin.ignore();
	cout << "Please enter your name student : ";
	fflush(stdin);
	getline(cin,sv->Name);
	cout << "Please enter your student code : ";
	fflush(stdin);
	getline(cin,sv->mssv);
	cout << "Please enter your address student : ";
	fflush(stdin);
	getline(cin,sv->Address);
	cout << "Please enter your class student : ";
	getline(cin,sv->Class);
	fflush(stdin);
	cout << "Please enter your analysis point student : ";
	cin >>sv->Analytics;
	cout << "Please enter your algebra point student : ";
	cin >>sv->Algebra;
	cout << "Please enter your gpa point student : ";
	cin >>sv->Gpa;
	cout << "Please enter your cpa point student : ";
	cin >>sv->Cpa;
}
Node *CreateNode(){
	sinhvien* sv = new sinhvien;
	Input_SinhVien(sv);
	Node* p = new Node;
	if (p == NULL){
		cout << "full memory not create\n";
		return 0;
	}
	p->data = sv;
	p->next = NULL;
	return p;
}
void ThemVaoDauMotSinhVien(List &l, Node *p){
	if (l.pHead == NULL){
		l.pHead = p;
	}
	else{
		p->next = l.pHead;
		l.pHead = p;	
		
		}
}
void Output_SinhVien(List l){
	for (Node* k = l.pHead; k != NULL; k = k->next){
		cout << "Mssv : "<< k->data->mssv << endl;
		cout << "Name : "<< k->data->Name << endl;
		cout << "Address : "<< k->data->Address << endl;
		cout << "class : "<< k->data->Class << endl;
		cout << "Analytics : "<< k->data->Analytics << endl;
		cout << "Algebra : "<< k->data->Algebra << endl;
		cout << "Gpa Point : "<< k->data->Gpa << endl;
		cout << "Cpa Point : "<< k->data->Cpa << endl;
		cout << "==============================SV================\n";

		
	}
}

void ChucNang(List &l){
	int n;
	while(1){
	cout << "\t\t\t\t==================================================================||\n";
	cout << "\t\t\t\t=======  function list  ==========================================||\n";
	cout << "\t\t\t\t||1=> Enter a new student .                                       ||\n";
	cout << "\t\t\t\t||2=> Print student list .                                        ||\n";
	cout << "\t\t\t\t||3=> Search for students by student ID .                         ||\n";
	cout << "\t\t\t\t||4=> Edit student information .                                  ||\n";
	cout << "\t\t\t\t||5=> Remove students from the list .                             ||\n";
	cout << "\t\t\t\t||6=> Get a list of students not yet classified class .           ||\n";
	cout << "\t\t\t\t||7=> Arrange students according to Cpa score gradually .	  ||\n";
	cout << "\t\t\t\t||0=> Exit programme .                                            ||\n";
	cout << "\t\t\t\t==================================================================||\n";
	cout << "Enter the function of your choice: ";
		cin >> n;
		if(n == 1){
			cout << "Please enter the information students need to add : \n";
			Node* p=CreateNode();
			ThemVaoDauMotSinhVien(l, p);
		}
		if(n == 2){
			cout << "show list student :\n";
			Output_SinhVien(l);	
			}
			if(n == 3){
			search(l);
		}
		if(n == 4){
			upgrade(l);
		}
		if(n == 5){
			DelStudent(l);
		}
		if(n == 6){
			DanhSachSinhVienChuaXepLop(l);
		}
		if(n == 7){
		QuickSort(l);
		}
		if(n == 0) break;
	}
	}
	void showNode(Node *k) {
	cout << "Mssv : "<< k->data->mssv << endl;
	cout << "Name : "<< k->data->Name << endl;
	cout << "Address : "<< k->data->Address << endl;
	cout << "class : "<< k->data->Class << endl;
	cout << "Analytics : "<< k->data->Analytics << endl;
	cout << "Algebra : "<< k->data->Algebra << endl;
	cout << "Gpa Point : "<< k->data->Gpa << endl;
	cout << "Cpa Point : "<< k->data->Cpa << endl;
}
bool SoSanh(string s1, string s2)
{

	for (unsigned int i = 0; i < s1.size(); i++){

		if(s1[i] >= 'a' && s1[i] <= 'z'){

			s1[i] -= 32;
		}
	}

	for (unsigned int i = 0; i < s2.size(); i++){

		if(s2[i] >= 'a' && s2[i] <= 'z'){

			s2[i] -= 32;
		}
	}

	if (s1.compare(s2) == 0)
	{
		return 1;
	}


}
void DelStudent(List& l) {
	string del;
	cin.ignore();
	cout << "Enter the student number to be deleted or the student's name : \n";
	fflush(stdin);
	getline(cin, del);
	Node* g = new Node;
	if (del.compare(l.pHead->data->mssv) == 0 && l.pHead->next == NULL) {
		l.pHead = NULL;
	}
	else{
		for (Node* k = l.pHead; k != NULL; k = k->next) {
			if (del.compare(k->data->Name) == 0) {
				g->next = k->next;
				k = g;
			}
			g = k;
		}
}
}

void search(List l ) {
	string  Mssv;
	cout << "Enter the student code to search : ";
	cin >> Mssv;
	for (Node* k = l.pHead; k != NULL; k = k->next) {
		if (SoSanh(Mssv,l.pHead->data->mssv)) {
			showNode(k);
		}
	}
	cout<<"There is no such student .\n";
}

void upgrade(List& l) {
	string Mssv;
	cout << "Enter the student code to edit : ";
	cin >> Mssv;
	for (Node* k = l.pHead; k != NULL; k = k->next) {
		if (SoSanh(Mssv,l.pHead->data->mssv)) {
			cout << "Invite you to enter student code: " << Mssv << endl;
			Input_SinhVien(k->data);
}
	}

}

void DanhSachSinhVienChuaXepLop(List l) {
	for (Node* k = l.pHead; k != NULL; k = k->next) {
		if (k->data->Class == "") {
			cout << "The list of unclassified students: " << endl;
			showNode(k);
		}
	}
}






