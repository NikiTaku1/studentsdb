#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "AVLTree.h"

using namespace std;

vector<string> faculties = {"appliedmath", "mathmech", "physics", "chemistry", "programming"};
vector<string> university = {"SPBU", "MSU", "PolyTech", "MIPT", "BaumanSU", "MISAA", "SPBSEU"};

string RandomName(){
    int namesize = 735;
    int surnamesize = 14651;
    int patnamesize = 94;
    int random1 = rand() % namesize + 1;

    ifstream in1("names.txt");
    string result1;

    for (int i = 0; i < random1; i++) {
        getline(in1, result1);
    }
    int random2 = rand() % surnamesize + 1;

    ifstream in2("surnames.txt");
    string result2;

    for (int i = 0; i < random2; i++) {
        getline(in2, result2);
    }
    int random3 = rand() % patnamesize + 1;

    ifstream in3("paternals.txt");
    string result3;

    for (int i = 0; i < random3; i++) {
        getline(in3, result3);
    }
    return result2+' '+result1+' '+result3;
}

string RandomNumber(int a, int msize){
    string a_str = to_string(a);
    int l = (to_string(a).size());
    int lmax = (to_string(msize).size());
    for (a=1; a<(lmax-l+1); ++a){
        a_str.insert (a_str.begin(), '0');
    }
    return a_str;
}

string RandomDate(){
    int a = ((rand()%4)+2001);
    return (to_string((rand()%28)+1))+ "." +(to_string((rand()%12)+1))+ "." + to_string(a);
}

string RandomRoom(){
    return (to_string((rand()%1400)+100))+"_"+(to_string((rand()%14)+10));
}

string RandomCourse(string a){
    string asub = a.substr(a.size()-4, 4);

    return to_string(2005-stoi(asub)) + '_' + (faculties[rand()%5]) + '_' + (university[rand()%7]);
}
class Student {
private:
    string fullname, number, dateofbirth, room_dormitory, course_faculty;
public:

    void setName(string name) {fullname = name;};
    void setNumber(string num) {number = num;};
    void setDate(string date) {dateofbirth = date;}
    void setRoom(string room) {room_dormitory = room;};
    void setCourseAndFaculty(string cou_fac) {course_faculty = cou_fac;};
    string getName() {return fullname;}
    string getNumber() const {return number;}
    string getDate() const {return dateofbirth;}
    string getRoom() const {return room_dormitory;}
    string getCourseAndFaculty() const {return course_faculty;}
};

int main() {
//    setlocale(LC_ALL, "Russian") у меня почему-то не работает
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    unsigned seed = time(0);
    srand(seed);

    int size;
    cout << "Enter desired amount of students ";
    cin >> size;
    cout << "\n";

    vector<Student> stdb;
    stdb.reserve(size);
    for (int i = 0; i < size; ++i) {
        string pname, pnum, pdate, proom, pcou_fac;
        pname = RandomName();
        pnum = RandomNumber(i+1, size);
        string a;
        a = RandomDate();
        pdate = a;
        proom = RandomRoom();
        pcou_fac = RandomCourse(a);

        Student p;
        p.setName(pname);
        p.setNumber(pnum);
        p.setDate(pdate);
        p.setRoom(proom);
        p.setCourseAndFaculty(pcou_fac);

        stdb.push_back(p);
        cout << stdb[i].getName() << "\n"; //вывод каждой карточки
//        cout << stdb[i].getNumber() << "\n";
//        cout << stdb[i].getDate() << "\n";
//        cout << stdb[i].getRoom() << "\n";
//        cout << stdb[i].getCourseAndFaculty() << "\n";
//        cout << "\n";
    }


    int choice;
    cout << "Choose search criteria" << "\n";
    cout << "1: Full Name, 2: Id Number" << "\n";
    cin >> choice;
    if (choice == 1){
        AVL<string, Student*> tree1([](string a, string b) -> bool {
            return a < b;
        });

        for (int i=0; i<size; ++i){
            tree1.push(stdb[i].getName(), &stdb[i]);
        }
        string entername11;
        cout << "Enter Surname:";
        cin >> entername11;
        string entername12;
        cout << "Enter Name:";
        cin >> entername12;
        string entername13;
        cout << "Enter Paternal:";
        cin >> entername13;
        string entername1 = entername11+' '+entername12+' '+entername13;
        auto ans1 = tree1.find(entername1);
        for (int j = 0; j < (ans1.size()); j++) {
            cout << (*ans1[j]).getName() << "\n"; //вывод каждой карточки
            cout << (*ans1[j]).getNumber() << "\n";
            cout << (*ans1[j]).getDate() << "\n";
            cout << (*ans1[j]).getRoom() << "\n";
            cout << (*ans1[j]).getCourseAndFaculty() << "\n";
        }
        cout << '\n';
    }

    if (choice == 2){
        AVL<string, Student*> tree2([](string a, string b) -> bool {
            return a < b;
        });

        for (int i=0; i<size; ++i){
            tree2.push(stdb[i].getNumber(), &stdb[i]);
        }
        string entername2;
        cout << "Enter ID Number:";
        cin >> entername2;
        auto ans2 = tree2.find(entername2);
        for (int j = 0; j < (ans2.size()); j++) {
            cout << (*ans2[j]).getName() << "\n"; //вывод каждой карточки
            cout << (*ans2[j]).getNumber() << "\n";
            cout << (*ans2[j]).getDate() << "\n";
            cout << (*ans2[j]).getRoom() << "\n";
            cout << (*ans2[j]).getCourseAndFaculty() << "\n";
        }
        cout << '\n';
    }

    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    system("pause");

    return 0;
}