# baby-RMS
A simple Result Management System written in C++
The provided C++ program is a simple student records management system designed to perform the following tasks:

LOGIN:

The program authenticates a user by reading a CSV file (Login.csv) containing usernames and passwords.
It allows three attempts for the user to input the correct username and password combination.
Upon successful login, it grants access and calls the navigate() function to allow further actions.
Navigation Menu (navigate):

After logging in, the user is presented with a menu that allows them to:
View a student's record.
Update a student's record.
Add a new student's record.
View the general student broadsheet.
Based on the user's input, the program calls the appropriate function to perform the selected task.
View a Student's Record (viewrecord):

This function reads a CSV file (records.csv) containing student records and allows the user to search for a student by their matriculation number.
If a matching record is found, the student's details (name, matriculation number, grades, and CGPA) are displayed.
The user can choose to save the record to a text file (result.txt).
Update a Student's Record (updaterecord):

This function allows the user to update the grades of an existing student in the records.csv file.
The CGPA is recalculated based on the updated grades, and the file is saved with the updated information.
Add a New Student's Record (newrecord):

This function allows the user to add new student records to the records.csv file.
The user inputs the student's details and grades, which are then stored in the file.
The CGPA for the new student is calculated and included in the records.
View General Student Broadsheet (broadsheet):

This function displays the entire student records file (records.csv) in a tabular format.
The broadsheet includes the names, matriculation numbers, grades for each course, and CGPAs of all students.
General Structure:

The program uses standard input/output streams for interacting with the user.
It handles file operations to read and write student and login data.
The program employs vectors to store and manage records internally before saving them back to the CSV file.
The CGPA is calculated by mapping grades to a point system and averaging them.
Overall, the program serves as a basic command-line interface (CLI) application for managing student academic records.






