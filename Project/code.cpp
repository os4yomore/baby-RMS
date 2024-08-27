#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <iterator>
#include <cstdlib>
#include <iomanip> 
#include <limits>

using namespace std;
void navigate();
void LOGIN();
void updaterecord();
void newrecord();
void broadsheet();

double cgpa;
int choice;
void LOGIN() {
    ifstream loginfile("Login.csv");
    if (!loginfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string head, line;
    getline(loginfile, head);

    vector<vector<string>> loginInfo;
    while (getline(loginfile, line)) {
    vector<string> row;
    stringstream ss(line);
    string cell;

    while (getline(ss, cell, ',')) {
        row.push_back(cell);
    }

    loginInfo.push_back(row);
}

    

    loginfile.close();

    bool isAuthenticated = false;
    int attempts = 0;

    while (!isAuthenticated && attempts < 3) {
        string password;
        string username;

        cout << "Enter username: ";
        cin >> ws >> username;
        cout << "Enter password: ";
        cin >> ws >> password;

        for (size_t i = 0; i < loginInfo.size(); ++i) {
            if (loginInfo[i].size() >= 2 && loginInfo[i][0] == username && loginInfo[i][1] == password) {
                isAuthenticated = true;
                cout << "ACCESS GRANTED." << endl;
                break;

                
            }

        }
        navigate();

        if (!isAuthenticated) {
            cout << "Invalid username or password. Please try again." << endl;
            attempts++;
        }
    }

    if (!isAuthenticated) {
        cout << "Access denied after 3 attempts. Exiting." << endl;
        exit(1);
    }
}

void viewrecord()
{

  ifstream recordsfile("records.csv");
    if (!recordsfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string head, line;
    getline(recordsfile, head);

    vector<vector<string>> records;
    while (getline(recordsfile, line)) {
    vector<string> row;
    stringstream ss(line);
    string cell;

    while (getline(ss, cell, ',')) {
        row.push_back(cell);
    }

    records.push_back(row);
}



int attempts = 0;
bool isAuthenticated = false;
while (!isAuthenticated && attempts < 100){
string matric;
cout<<"Student Matriculation Number: "<<endl;
cin>> matric;
  for (size_t i = 0; i < records.size(); ++i) {
            if (records[i].size() >= 7 && records[i][1] == matric) {
 isAuthenticated = true;
 cout << "Student name:" << records[i][0] << endl;
 cout << "Matriculation number:" << records[i][1] << endl;
 cout << "MTH101:" << records[i][2] << endl;
 cout << "CSC101:" << records[i][3] << endl;
 cout << "PHY107:" << records[i][4] << endl;
 cout << "SEN224:" << records[i][5] << endl;
 cout << "ENT201:" << records[i][6] << endl;
 cout << "CGPA: " << records[i][7] << endl;
          
 break;         
}
int a;
cout << "Do you want to save this to your computer? (1 = yes, 2 = no)"<< endl;
cin >> a;
while (a != 1 || a != 2) 
{
 cout << "Invalid input, please select either 1 or 2."<<endl;
}
if (a == 1)
{
ofstream grades("result.txt");
    if (!grades.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

 grades << "STUDENT NAME: "<< records[i][0] << endl;
 grades << "Matriculation number:" << records[i][1] << endl;
 grades << "MTH101:" << records[i][2] << endl;
 grades << "CSC101:" << records[i][3] << endl;
 grades << "PHY107:" << records[i][4] << endl;
 grades << "SEN224:" << records[i][5] << endl;
 grades << "ENT201:" << records[i][6] << endl;
 grades << "CGPA: " <<  records[i][7] << endl;

   
    }
else 
{
  cout << "To go to the main menu, click 1, otherwise click 0 to terminate the program" << endl;
  int option;
  cin >> option;
  if (option == 1)
  {
    navigate();
  }
  if (option == 0)
  {
    exit(1);
  }
}
    }
if (!isAuthenticated)
{
cout << "Invalid Matriculation number, try again." << endl;
attempts ++;
}

} 
if (!isAuthenticated)
            {
cout << "Invalid matric ID.\n";
            } 
}





void broadsheet()
{
    ifstream recordsfile("records.csv");
    if (!recordsfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string head, line;
    getline(recordsfile, head);

    vector<vector<string>> records;
    while (getline(recordsfile, line)) {
        vector<string> row;
        stringstream ss(line);
        string cell;

        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        records.push_back(row);
    }

    
    cout << setw(35) << left << "Student Name" << setw(15) << left << "Matric Number";
    cout << setw(10) << left << "MTH101" << setw(10) << left << "CSC101";
    cout << setw(10) << left << "PHY107" << setw(10) << left << "SEN224";
    cout << setw(10) << left << "ENT201" << setw(10) << left << "CGPA" << endl;

    
    for (size_t i = 0; i < records.size(); ++i)
    {
        for (size_t j = 0; j < records[i].size(); ++j)
        {
            cout << setw(20) << left << records[i][j];
        }
        cout << endl;
    }

    cout << "To go to the main menu, click 1, otherwise click 0 to terminate the program" << endl;
  int option;
  cin >> option;
  if (option == 1)
  {
    navigate();
  }
  if (option == 0)
  {
    exit(1);
  }
}








void newrecord()
{

  ifstream recordsfile("records.csv");
    if (!recordsfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string head, line;
    getline(recordsfile, head);

    vector<vector<string>> records;
    while (getline(recordsfile, line)) {
    vector<string> row;
    stringstream ss(line);
    string cell;

    while (getline(ss, cell, ',')) {
        row.push_back(cell);
    }

    records.push_back(row);
}



cout << "How many new student records do you want to add?"<<endl;
int students;
while (!(cin >> students) || cin.fail()) {
        cout << "Invalid input. Please enter a valid integer." << endl;

        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    
int f = 0;
while (f < students ){
string matric;
string name, first_name, last_name;
int grade1;
int grade2;
int grade3;
int grade4;
int grade5;
cout << "Enter the student " << f + 1<< "s full name\n";
cin.ignore();
getline(cin, name);
istringstream iss(name);
iss >> first_name >> last_name;
cout << "Enter the student's matriculation number\n";
cin>> matric;
cout << "Enter MTH101 score: \n";
while (!(cin >> grade1)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');   
        cout << "Invalid input. Please enter an integer: ";
    }

cout << "Enter CSC101 score: \n";
while (!(cin >> grade2)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');   
        cout << "Invalid input. Please enter an integer: ";
    }


cout << "Enter PHY107 score: \n";
while (!(cin >> grade3)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        cout << "Invalid input. Please enter an integer: ";
    }


cout << "Enter SEN224 score: \n";
while (!(cin >> grade4)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        cout << "Invalid input. Please enter an integer: ";
    }


cout << "Enter ENT201 score: \n";
while (!(cin >> grade5)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
        cout << "Invalid input. Please enter an integer: ";
    }



vector <string> new1;
new1.push_back(first_name  + " " + last_name);
new1.push_back(matric);
new1.push_back(to_string(grade1));
new1.push_back(to_string(grade2));
new1.push_back(to_string(grade3));
new1.push_back(to_string(grade4));
new1.push_back(to_string(grade5));
{
 cout << "Student name:" << new1[0] << endl;
 cout << "Matriculation number:" << new1[1] << endl;
 cout << "MTH101:" << new1[2] << endl;
 cout << "CSC101:" << new1[3] << endl;
 cout << "PHY107:" << new1[4] << endl;
 cout << "SEN224:" << new1[5] << endl;
 cout << "ENT201:" << new1[6] << endl;

double gpa = 0.00;
  for (int j =2; j<=6; j++){
  if ((stoi(new1[j]))>= 70) 
  {
    gpa = gpa + 5.0;
  }
  else if ( (stoi(new1[j])) >= 60 && (stoi(new1[j])) <= 69) 
  {
    gpa = gpa+ 4.0;
  } 
  else if ((stoi(new1[j])) >= 50 && (stoi(new1[j])) <= 59)
  {
    gpa = gpa+ 3.0;
  } 
  else if ((stoi(new1[j])) >= 40 && (stoi(new1[j])) <= 49) 
  {
    gpa = gpa+ 2.0;
  } else if ((stoi(new1[j])) < 40)
  {
    gpa = gpa+ 0.0;
  }
cgpa = gpa/5.0;
}

new1.push_back(to_string(cgpa));
 cout << "CGPA:" <<cgpa <<endl;
records.push_back(new1);
}
f++;
}
 cout << "Updated Broadsheet: \n";
    for (const auto &record : records) {
        for (const auto &value : record) {
            cout << value << "\t";
        }
        cout << endl;
    }
    
    recordsfile.close();

    
    ofstream recordsfile_out("records.csv");
    

    
    recordsfile_out << head << endl;

    
    for (const auto &record : records) {
        for (size_t i = 0; i < record.size(); ++i) {
            recordsfile_out << record[i];
            if (i < record.size() - 1) {
                recordsfile_out << ',';
            }
        }
        recordsfile_out << endl;
    }

   
    recordsfile_out.close();

    cout << "To go to the main menu, click 1, otherwise click 0 to terminate the program" << endl;
  int option;
  cin >> option;
  if (option == 1)
  {
    navigate();
  }
  if (option == 0)
  {
    exit(1);
  }
}





void updaterecord()
{

  ifstream recordsfile("records.csv");
    if (!recordsfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string head, line;
    getline(recordsfile, head);

    vector<vector<string>> records;
    while (getline(recordsfile, line)) {
    vector<string> row;
    stringstream ss(line);
    string cell;

    while (getline(ss, cell, ',')) {
        row.push_back(cell);
    }

    records.push_back(row);
}
int attempts = 0;
bool isAuthenticated = false;
while (!isAuthenticated && attempts < 100){
string matric;
cout<<"Student Matriculation Number: "<<endl;
cin>> matric;
  for (size_t i = 0; i < records.size(); ++i) {
            if (records[i].size() == 8 && records[i][1] == matric) {
 isAuthenticated = true;
 cout << "Insert Updated data"<< endl;

 cout << "Student name:" << records[i][0] << endl;





cout << "Matriculation number:" << records[i][1] << endl;
 


 cout << "MTH101 current grade :" << records[i][2] << endl;
 cout << "Insert Updated grade: "<< endl;
 string input1;
 while (!(cin >> input1 && all_of(input1.begin(), input1.end(), ::isdigit))) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        cout << "Invalid input. Please enter an integer: ";
    }

    istringstream(input1) >> records[i][2];
 


 cout << "CSC101 current grade:" << records[i][3] << endl;
 cout << "Insert Updated grade: "<< endl;
 string input2;
while (!(cin >> input2 && all_of(input2.begin(), input2.end(), ::isdigit))) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        cout << "Invalid input. Please enter an integer: ";
    }

    istringstream(input2) >> records[i][3];
 
 

 cout << "PHY107 current grade:" << records[i][4] << endl;
 cout << "Insert Updated grade: "<< endl;
 string input3;
 while (!(cin >> input3 && all_of(input3.begin(), input3.end(), ::isdigit))) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        cout << "Invalid input. Please enter an integer: ";
    }

    istringstream(input3) >> records[i][4];
 
 

 cout << "SEN224 current grade:" << records[i][5] << endl;
 cout << "Insert Updated grade: "<< endl;
 string input4;
 while (!(cin >> input4 && all_of(input4.begin(), input4.end(), ::isdigit))) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        cout << "Invalid input. Please enter an integer: ";
    }

    istringstream(input4) >> records[i][5];


 cout << "ENT201 current grade:" << records[i][6] << endl;
 cout << "Insert Updated grade: "<< endl;
 string input5;
 while (!(cin >> input4 && all_of(input5.begin(), input5.end(), ::isdigit))) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        cout << "Invalid input. Please enter an integer: ";
    }

    istringstream(input4) >> records[i][6];

  double gpa = 0.00;
  for (int j =2; j<=6; j++){
  if (stoi(records[i][j]) >= 70) 
  {
    gpa = gpa + 5.0;
  }
  else if (stoi(records[i][j]) >= 60 && stoi(records[i][j]) <= 69) 
  {
    gpa = gpa+ 4.0;
  } 
  else if (stoi(records[i][j]) >= 50 && stoi(records[i][j]) <= 59)
  {
    gpa = gpa+ 3.0;
  } 
  else if (stoi(records[i][j]) >= 40 && stoi(records[i][j]) <= 49) 
  {
    gpa = gpa+ 2.0;
  } else if (stoi(records[i][j]) < 40)
  {
    gpa = gpa+ 0.0;
  }
cgpa = gpa/5.0;
}

records[i][7] = to_string(cgpa);
recordsfile.close();
cout << " Old CGPA: " << records[i][7]  << endl;
cout << "New CGPA:" <<cgpa <<endl;
cout << "Data Updated in CSV file" << endl;


}

}

recordsfile.close();

 ofstream recordsfile_out("records.csv");
    if (!recordsfile_out.is_open()) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    recordsfile_out << head << endl;

    for (const auto &record : records) {
        for (size_t i = 0; i < record.size(); ++i) {
            recordsfile_out << record[i];
            if (i < record.size() - 1) {
                recordsfile_out << ',';
            }
        }
        recordsfile_out << endl;


} 

cout << "To go to the main menu, click 1, otherwise click 0 to terminate the program" << endl;
  int option;
  cin >> option;
  if (option == 1)
  {
    navigate();
  }
  if (option == 0)
  {
    exit(0);
  }
  
if (!isAuthenticated)
{
cout << "Invalid Matriculation number, try again." << endl;
attempts ++;
}
}
if (!isAuthenticated)
            {
cout << "Invalid matric ID.\n";
            } 

}







void  navigate()
{
  
  cout << "Welcome to The PAU Result Mangament System"<< endl;
  cout<< "To view a Student's Records, Click 1" << endl;
  cout<< "To update a Student's Records, Click 2" << endl;
  cout<< "To add a new Student's Records, Click 3" << endl;
  cout<< "To view the General Student Broadsheet, Click 4" << endl;

  cin >> choice;
  
   while (choice != 1 && choice != 2  && choice != 3  && choice != 4  )
   {
    cout << "Invalid input. Please enter 1, 2, 3 or 4.\n";
    cin >> ws >> choice;
   }
  
  if (choice == 1)
  { 
    viewrecord();
  }

   if (choice == 2)
  {
    updaterecord();
  }

   if (choice == 3)
  {
    newrecord();
  }

   if (choice == 4)
  {
    broadsheet();
  }

  


}

int main()
{
  cout << "Welcome to The PAU Result Mangament System"<< endl;
  cout << "Enter your login details"<< endl;
  LOGIN();
  
  return 0;
}