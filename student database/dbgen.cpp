#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> names = {"Харитон","Артемий","Елисей","Александр","Дмитрий","Виктор","Изяслав","Ярослав","Ростислав","Фадей","Богдан","Сергей",
                        "Пахом","Вадим","Макар","Марк","Митофан","Остап","Потап","Прохор","Радислав","Андрей","Артем","Олег","Валерий","Виталий","Владимир","Влас",
                        "Вячеслав","Геннадий","Георгий","Герман","Глеб","Григорий","Давид","Данила","Дементий","Дмитрий","Денис","Евгений","Евдоким","Егор","Евстафий",
                        "Елисей","Емельян","Игорь","Игнатий","Захар","Измаил","Илья","Иннокентий","Иосиф","Карл","Кирилл","Константин","Ян","Якуб","Юрий","Фома",
                        "Тимофей","Тимур","Тимур","Тихон","Ульян","Федор"};
vector<string> surnames = {"Харитонов","Артемин","Елисеев","Александров","Дмитриенко","Викторов","Фадеев","Богданов","Сергееев",
                           "Пахомов","Вадаев","Макаренко","Марков","Митеев","Остапов","Потапов","Прохоров","Раденко","Андреев","Артеменко","Олеев","Валерьев","Витальев","Власов",
                           "Вяткин","Геннадьев","Гет","Германский","Гленн","Григорьев","Давыденко","Даниленко","Дементьев","Дмитриев","Динаев","Евгеньев","Евдеев","Егерь","Евстафьев",
                           "Елисеев","Емельяненко","Игорев","Игнатьев","Захаренко","Измайлов","Ильяненко","Иннокентьев","Сталин","Карлеев","Кириленко","Константинов","Янь","Якубов","Юрьев","Фомеенко",
                           "Тимофеев","Тамилев","Темеев","Тихий","Ульяненко","Федоров"};
vector<string> patnames = {"Харитонович","Артемьевич","Елисеевич","Александрович","Дмитриевич","Викторович","Изяславич","Ярославич","Ростиславич","Фадеевич","Богданович","Сергеевич",
                        "Пахомович","Вадимович","Макарович","Маркович","Митофанович","Остапович","Потапович","Прохорович","Радиславич","Андрееевич","Артемович","Олегович","Валерьевич","Витальевич","Владимирович","Власович",
                        "Вячеславич","Геннадьевич","Георгиевич","Германович","Глебович","Григорьевич","Давидович","Данилович","Дементьевич","Дмитриевич","Денисович","Евгеньевич","Евдокимович","Егорович","Евстафьевич",
                        "Елисеевич","Емельянович","Игоревич","Игнатьевич","Захарович","Измаилович","Ильич","Иннокентьевич","Иосифович","Карлович","Кириллович","Константинович","Янович","Якубович","Юрьевич","Фомич",
                        "Тимофееевич","Тимурович","Тихонович","Ульянович","Федорович"};
vector<string> faculties = {"amcp", "mathmech", "physfac", "chemfac"};

string RandomName(){
    int namesize = static_cast<int>(names.size());
    int surnamesize = static_cast<int>(surnames.size());
    int patnamesize = static_cast<int>(patnames.size());
    int ra = rand() % namesize;
    int rb = rand() % surnamesize;
    int rc = rand() % patnamesize;
    string randname = surnames[rb]+' '+names[ra]+' '+patnames[rc];
    return randname;
}

string RandomDate(){
    return (to_string((rand()%28)+1))+ "." +(to_string((rand()%12)+1))+ "." +(to_string((rand()%6)+2000));
}

string RandomRoom(){
    return (to_string((rand()%1400)+100))+"_"+(to_string((rand()%14)+10));
}

string RandomCourse(){
    return (to_string((rand()%4)+1))+"_"+(faculties[rand()%4]);
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
//    setlocale(LC_ALL, "Russian");
    SetConsoleCP(65001);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(65001); // установка кодовой страницы win-cp 1251 в поток вывода

    unsigned seed = time(0);
    srand(seed);

    int size; // Размер массива объектов класса
    cout << "Enter desired amount of students ";
    cin >> size;
    cout << "\n";

    vector<Student> stdb;
    stdb.reserve(size);
    for (int i = 0; i < size; ++i) {
        string pname, pnum, pdate, proom, pcou_fac;
//        cout << "Name: ";
        pname = RandomName();
//        cout << "Number: ";
        pnum = to_string(i+1);
//        cout << "Date of birth: ";
        pdate = RandomDate();
//        cout << "Room_Dormitory: ";
        proom = RandomRoom();
//        cout << "Course_Faculty: ";
        pcou_fac = RandomCourse();

        Student p; // объявление объекта
        p.setName(pname);
        p.setNumber(pnum);
        p.setDate(pdate);
        p.setRoom(proom);
        p.setCourseAndFaculty(pcou_fac);

        stdb.push_back(p);

        cout << stdb[i].getName() << "\n";
        cout << stdb[i].getNumber() << "\n";
        cout << stdb[i].getDate() << "\n";
        cout << stdb[i].getRoom() << "\n";
        cout << stdb[i].getCourseAndFaculty() << "\n";
        cout << "\n";
    }
    
    int n;
    cin >> n;
    cout << stdb[n-1].getName() << "\n";
    cout << stdb[n-1].getNumber() << "\n";
    cout << stdb[n-1].getDate() << "\n";
    cout << stdb[n-1].getRoom() << "\n";
    cout << stdb[n-1].getCourseAndFaculty() << "\n";
    cout << "\n";

    system("pause");

    return 0;
}