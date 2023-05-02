#include <bits/stdc++.h>
#include "student.h"

map < string, student > students_map;
vector < student > students_list;

bool eq(student a, student b) {
    if (a.getName() == b.getName() && a.getSurname() == b.getSurname() && a.getAge() == b.getAge() && a.getAvgGrade() == b.getAvgGrade()) return true;
    return false;
}

void eraseFromList(student x) {
    vector < student > new_students_list;
    for (auto i : students_list)
        if (!eq(i, x)) new_students_list.push_back(i);
    students_list = new_students_list;
}

void manageStudents() {
    int q = 1;
    while (q) {
        cout << "Select option: " << endl;
        cout << "1. Add student" << endl;
        cout << "2. Delete student" << endl;
        cout << "0. Exit" << endl;
        cin >> q;

        if (q == 1) {
            cout << "Enter name: " << endl;
            string name; cin >> name;
            cout << "Enter surname: " << endl;
            string surname; cin >> surname;
            cout << "Enter age: " << endl;
            int age; cin >> age;
            cout << "Enter average grade: " << endl;
            int avg_grade; cin >> avg_grade;
            cout << "Enter student's id: " << endl;
            string id; cin >> id;

            student x = student();
            x.setName(name);
            x.setSurname(surname);
            x.setAge(age);
            x.setAvgGrade(avg_grade);

            students_map[id] = x;
            students_list.push_back(x);
            cout << "New student was added" << endl;
        }
        else if (q == 2) {
            cout << "Enter student's id to delete: " << endl;
            for (auto i : students_map)
                cout << i.first << ' ' << i.second.getName() << ' ' << i.second.getSurname() << endl;
            string id; cin >> id;
            eraseFromList(students_map[id]);
            students_map.erase(id);
            cout << "The student was deleted" << endl;
        }
        else break;
    }
}

bool cmp_name(student a, student b) {
    if (a.getName() == b.getName()) return a.getSurname() < b.getSurname();
    return a.getName() < b.getName();
}

bool cmp_surname(student a, student b) {
    if (a.getSurname() == b.getSurname()) return a.getName() < b.getName();
    return a.getSurname() < b.getSurname();
}

bool cmp_age(student a, student b) {
    if (a.getAge() == b.getAge()) {
        if (a.getSurname() == b.getSurname()) return a.getName() < b.getName();
        return a.getSurname() < b.getSurname();
    }
    return a.getAge() < b.getAge();
}

bool cmp_avg(student a, student b) {
    if (a.getAvgGrade() == b.getAvgGrade()) {
        if (a.getSurname() == b.getSurname()) return a.getName() < b.getName();
        return a.getSurname() < b.getSurname();
    }
    return a.getAvgGrade() < b.getAvgGrade();
}

string idByValue(student value) {
    for (auto i : students_map)
        if (eq(i.second, value)) return i.first;
}

bool cmp_id(student a, student b) {
    return idByValue(a) < idByValue(b);
}

void sortStudents() {
    int q = 1;
    while (q) {
        cout << "Sort students by: " << endl;
        cout << "1. Name" << endl;
        cout << "2. Surname" << endl;
        cout << "3. Age" << endl;
        cout << "4. Average grade" << endl;
        cout << "5. ID" << endl;
        cout << "0. Exit" << endl;
        cin >> q;

        if (q == 1) sort(students_list.begin(), students_list.end(), cmp_name);
        else if (q == 2) sort(students_list.begin(), students_list.end(), cmp_surname);
        else if (q == 3) sort(students_list.begin(), students_list.end(), cmp_age);
        else if (q == 4) sort(students_list.begin(), students_list.end(), cmp_avg);
        else if (q == 5) sort(students_list.begin(), students_list.end(), cmp_id);
        else break;

        for (auto i : students_list) {
            i.showDetails();
            cout << endl;
        }
    }
}

void searchByName() {
    int q = 1;
    while (q) {
        cout << "Enter name to search or \"0\" to exit: " << endl;
        string s; cin >> s;

        if (s == "0") break;

        vector < student > v = students_list;
        sort(students_list.begin(), students_list.end(), cmp_name);

        cout << "Select option: " << endl;
        cout << "1. Fast (binary) search" << endl;
        cout << "2. Slow (linear) search" << endl;
        cout << "0. Exit" << endl;
        cin >> q;

        vector < student > ans;
        if (q == 1) {
            int l = 0, r = (int)v.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (v[mid].getName() < s) l = mid + 1;
                else r = mid;
            }
            for (int i = l; i < (int)v.size() && v[i].getName() == s; ++i)
                ans.push_back(v[i]);
        }
        else if (q == 2) {
            for (auto i : v)
                if (i.getName() == s) ans.push_back(i);
        }
        else break;

        cout << ans.size() << " entries were found" << ((int)ans.size() == 0 ? "." : ": ") << endl;
        for (auto i : ans) {
            i.showDetails();
            cout << endl;
        }
    }
}

void searchBySurname() {
    int q = 1;
    while (q) {
        cout << "Enter surname to search or \"0\" to exit: " << endl;
        string s; cin >> s;

        if (s == "0") break;

        vector < student > v = students_list;
        sort(students_list.begin(), students_list.end(), cmp_surname);

        cout << "Select option: " << endl;
        cout << "1. Fast (binary) search" << endl;
        cout << "2. Slow (linear) search" << endl;
        cout << "0. Exit" << endl;
        cin >> q;

        vector < student > ans;
        if (q == 1) {
            int l = 0, r = (int)v.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (v[mid].getSurname() < s) l = mid + 1;
                else r = mid;
            }
            for (int i = l; i < (int)v.size() && v[i].getSurname() == s; ++i)
                ans.push_back(v[i]);
        }
        else if (q == 2) {
            for (auto i : v)
                if (i.getSurname() == s) ans.push_back(i);
        }
        else break;

        cout << ans.size() << " entries were found" << ((int)ans.size() == 0 ? "." : ": ") << endl;
        for (auto i : ans) {
            i.showDetails();
            cout << endl;
        }
    }
}

void searchByAge() {
    int q = 1;
    while (q) {
        cout << "Enter age to search or \"0\" to exit: " << endl;
        int s; cin >> s;

        if (s == 0) break;

        vector < student > v = students_list;
        sort(students_list.begin(), students_list.end(), cmp_age);

        cout << "Select option: " << endl;
        cout << "1. Fast (binary) search" << endl;
        cout << "2. Slow (linear) search" << endl;
        cout << "0. Exit" << endl;
        cin >> q;

        vector < student > ans;
        if (q == 1) {
            int l = 0, r = (int)v.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (v[mid].getAge() < s) l = mid + 1;
                else r = mid;
            }
            for (int i = l; i < (int)v.size() && v[i].getAge() == s; ++i)
                ans.push_back(v[i]);
        }
        else if (q == 2) {
            for (auto i : v)
                if (i.getAge() == s) ans.push_back(i);
        }
        else break;

        cout << ans.size() << " entries were found" << ((int)ans.size() == 0 ? "." : ": ") << endl;
        for (auto i : ans) {
            i.showDetails();
            cout << endl;
        }
    }
}

void searchByAvgGrade() {
    int q = 1;
    while (q) {
        cout << "Enter average grade to search or \"0\" to exit: " << endl;
        int s; cin >> s;

        if (s == 0) break;

        vector < student > v = students_list;
        sort(students_list.begin(), students_list.end(), cmp_avg);

        cout << "Select option: " << endl;
        cout << "1. Fast (binary) search" << endl;
        cout << "2. Slow (linear) search" << endl;
        cout << "0. Exit" << endl;
        cin >> q;

        vector < student > ans;
        if (q == 1) {
            int l = 0, r = (int)v.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (v[mid].getAvgGrade() < s) l = mid + 1;
                else r = mid;
            }
            for (int i = l; i < (int)v.size() && v[i].getAvgGrade() == s; ++i)
                ans.push_back(v[i]);
        }
        else if (q == 2) {
            for (auto i : v)
                if (i.getAvgGrade() == s) ans.push_back(i);
        }
        else break;

        cout << ans.size() << " entries were found" << ((int)ans.size() == 0 ? "." : ": ") << endl;
        for (auto i : ans) {
            i.showDetails();
            cout << endl;
        }
    }
}

void searchById() {
    cout << "Enter ID: " << endl;
    string s; cin >> s;

    if (students_map.find(s) == students_map.end()) cout << "0 entries were found" << endl;
    else cout << "1 entry was found" << endl;
    students_map[s].showDetails();
    cout << endl;
}

void searchStudents() {
    int q = 1;
    while (q) {
        cout << "Search students by: " << endl;
        cout << "1. Name" << endl;
        cout << "2. Surname" << endl;
        cout << "3. Age" << endl;
        cout << "4. Average grade" << endl;
        cout << "5. ID" << endl;
        cout << "0. Exit" << endl;
        cin >> q;

        if (q == 1) searchByName();
        else if (q == 2) searchBySurname();
        else if (q == 3) searchByAge();
        else if (q == 4) searchByAvgGrade();
        else if (q == 5) searchById();
        else break;
    }
}

int main() {
    int q = 1;
    while (q) {
        cout << "Select option: " << endl;
        cout << "1. Manage students" << endl;
        cout << "2. Search for a student" << endl;
        cout << "3. Sort students" << endl;
        cout << "0. Exit" << endl;
        cin >> q;

        if (q == 1) manageStudents();
        else if (q == 2) searchStudents();
        else if (q == 3) sortStudents();
        else break;
    }
    return 0;
}
