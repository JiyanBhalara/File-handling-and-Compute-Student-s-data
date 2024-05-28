#include "getNumber.cpp"
#include "jjb0363Project3_header.h"

/*
function: addStudent
Description: This function ask user to enter details of student to be added
*/
int addStudent()
{
    Student student;

    // Prompt for last name of student
    cout << "Enter last name of the student:";
    cin >> student.Name;

    string FirstName;

    // Prompt for first name of student
    cout << "Enter first name of the student:";
    cin.ignore();
    getline(cin, FirstName);

    // Prompt for ID of student
    cout << "Enter student ID: ";
    cin >> student.Id;

    // Prompt for number of test taken by student
    cout << "How many tests did this student take? ";
    cin >> student.TestTaken;

    if (student.TestTaken > 5 || student.TestTaken < 0)
    {
        cout << "Please enter correct number of Test." << endl;
    }

    student.TestScore = new int[student.TestTaken];

    for (int i = 0; i < student.TestTaken; i++)
    {
        // Prompt for score of student
        cout << "Enter score#" << i + 1 << " : ";
        cin >> *(student.TestScore + i);
    }

    // opening student.dat file for writing
    ofstream WriteFile;
    WriteFile.open("student.dat", ios::app);

    if (!WriteFile.is_open())
    {
        cout << "Unable to open student.dat" << endl;
        return 1;
    }

    // Writing the new student details in file
    WriteFile << endl << student.Name << "," << FirstName << ",";
    WriteFile << student.Id << "," << student.TestTaken << ",";

    for (int i = 0; i < student.TestTaken; i++)
    {
        WriteFile << student.TestScore[i] << ",";
    }

    // Appending first name to student's name
    student.Name = student.Name + "," + FirstName;

    WriteFile.close();
    return 0;
}

/*
function: removeStudent
Description: This function ask user to enter the Id of student to be removed and removes the entry with the provided Id;
*/
int removeStudent(int StudId)
{
    int StudentCount;
    StudentCount = getNumber();
    string LastName, FirstName;
    bool FoundId = false;
    char Skip;
    int i = 0;

    // Opening file for reading
    ifstream ReadFile;
    ReadFile.open("student.dat");

    if (!ReadFile.is_open())
    {
        cout << "Unable to open student.dat" << endl;
        return 1;
    }

    Student *students = new Student[StudentCount];

    // Reading content of file using while and for loop
    while (!ReadFile.eof() && i < StudentCount)
    {
        // Reads lastname
        getline(ReadFile, LastName, ',');

        // Reads firstname
        getline(ReadFile, FirstName, ',');

        students[i].Name = LastName+ " " +FirstName;

        // Reads Id
        ReadFile >> students[i].Id >> Skip;

        //// Reads Number of test taken
        ReadFile >> students[i].TestTaken >> Skip;

        students[i].TestScore = new int[students[i].TestTaken];

        for (int j = 0; j < students[i].TestTaken; j++)
        {
            // Reads Testscore of student
            ReadFile >> students[i].TestScore[j] >> Skip;
        }
        
        if (StudId == students[i].Id)
        {
            FoundId = true;
        }
        // updating i;
        i++;
    }

    // Closing file after reading
    ReadFile.close();

    if (FoundId)
    {
        // Opening file for writing
        ofstream WriteFile;
        WriteFile.open("student.dat");

        if (!WriteFile.is_open())
        {
            cout << "Unable to open student.dat" << endl;
            return 1;
        }

        // if Id is found and matches with inputted id, then removing the entry

        for (int i = 0; i < StudentCount; i++)
        {
            if (StudId != students[i].Id)
            {
                // Writing contents to the student.dat
                WriteFile << students[i].Name.substr(0, students[i].Name.find(' ')) << ",";
                WriteFile << students[i].Name.substr(students[i].Name.find(' ')+1) << ",";
                WriteFile << students[i].Id << "," << students[i].TestTaken << ",";

                for (int j = 0; j < students[i].TestTaken; j++)
                {
                    WriteFile << students[i].TestScore[j] << ",";
                }
                delete[] students[i].TestScore;
            }
            
        }
        cout << "Entry removed successfully." << endl;

        delete[] students;

        // Closing the file
        WriteFile.close();
    }else{
        //if Id is not found
        cout << "Student does not exit" << endl;
    }

    return 0;
}

/*
function: display
Description: This function displays details of students
*/
int display(){
    //Declaring required variables
    int StudentCount = getNumber();
    Student *Students = new Student [StudentCount];
    int count = 0;
    string FirstName;
    char Skip;

    // Opening file for reading
    ifstream ReadFile;
    ReadFile.open("student.dat");
    
    //If file is not open, return 1
    if (!ReadFile.is_open())
    {
        cout << "Unable to open student.dat" << endl;
        return 1;
    }

    // Reading content of file using while and for loop
    while (!ReadFile.eof() && count < StudentCount)
    {
        getline(ReadFile, Students[count].Name, ',');
        
        getline(ReadFile, FirstName, ',');
        
        Students[count].Name =  Students[count].Name + "," + FirstName;
        

        ReadFile >>  Students[count].Id >> Skip;

        ReadFile >>  Students[count].TestTaken >> Skip;

        Students[count].TestScore = new int [ Students[count].TestTaken];

        
        for (int i = 0; i <  (*(Students+count)).TestTaken; i++)
        {
            ReadFile >>  Students[count].TestScore[i] >> Skip;
        }
        count++;
    }
    ReadFile.close();

    //Displaying content of File
    for (int i = 0; i < StudentCount; i++)
    { 
        cout << left;
        cout << setw(30) << Students[i].Name << setw(15) << Students[i].Id;
        for (int j = 0; j < Students[i].TestTaken; j++)
        {
            cout << setw(5) << Students[i].TestScore[j];      
        }
    }

    //Deleting allocated memory for following arrays
    delete [] Students->TestScore;
    delete [] Students;
    return 0;

}

/*
function: search
Description: This function ask user to enter the Id of student to searched and displays the output if it exists.
*/
int search(int SearchStudId){
    //Declaring required variables
    Student *SearchStudent = new Student;
    string FirstName;
    char Skip;
    bool MatchId = false;
    int count = 0;

    // Opening file for reading
    ifstream ReadFile;
    ReadFile.open("student.dat");
    
    //If file is not open, return 1
    if (!ReadFile.is_open())
    {
        cout << "Unable to open student.dat" << endl;
        return 1;
    }
    
    
    // Reading content of file using while and for loop
    while (!ReadFile.eof())
    {
        
        getline(ReadFile, (*SearchStudent).Name, ',');
        
        getline(ReadFile, FirstName, ',');
        
        (*SearchStudent).Name = (*SearchStudent).Name + "," + FirstName;
        

        ReadFile >> (*SearchStudent).Id >> Skip;

        ReadFile >> (*SearchStudent).TestTaken >> Skip;

        (*SearchStudent).TestScore = new int [(*SearchStudent).TestTaken];

        
        for (int i = 0; i < (*SearchStudent).TestTaken; i++)
        {
            ReadFile >> (*SearchStudent).TestScore[i] >> Skip;
        }
        count++;
        
        // If id is found seeting MatchId to true for further search
        if ((*SearchStudent).Id == SearchStudId)
        {
            MatchId = true;
            break;
        }
        
    }
    ReadFile.close();

    // if MatchId is true then displaying the details of that particular student
    if (MatchId)
    {
        cout << setw(30)  << (*SearchStudent).Name;
        cout << setw(15) << (*SearchStudent).Id;
        
        for (int i = 0; i <(*SearchStudent).TestTaken; i++)
        {
            cout << setw(5) << (*SearchStudent).TestScore[i];
        }
        delete [] SearchStudent->TestScore;
        cout << endl;
    }else{
        //If no such student exist
        cout << "Student does not exist." << endl;
    }

    //Deleting allocated memory
    delete SearchStudent;

    return 0;
}

/*
function: exportResults
Description: This function writes Id and average of Tests into average.dat
*/
int exportResults(){
    //Declaring variables required
    int StudentCount = getNumber();
    double average;
    int count = 0;
    char Skip;
    int TotalScore = 0;
    string FirstName;
    Student *Students = new Student [StudentCount];
    double *Average = new double [StudentCount];

    //Opening file for reading
    ifstream ReadFile;
    ReadFile.open("student.dat");

    //If file is not open, return 1
    if (!ReadFile.is_open())
    {
        cout << "Unable to open student.dat" << endl;
        return 1;
    }

    // Reading content of file using while and for loop
    while (!ReadFile.eof() && count < StudentCount)
    {
        getline(ReadFile, Students[count].Name, ',');
        
        getline(ReadFile, FirstName, ',');
        
         Students[count].Name =  Students[count].Name + "," + FirstName;
        

        ReadFile >>  Students[count].Id >> Skip;

        ReadFile >>  Students[count].TestTaken >> Skip;

        Students[count].TestScore = new int [ Students[count].TestTaken];

        
        for (int i = 0; i <  Students[count].TestTaken; i++)
        {
            ReadFile >>  Students[count].TestScore[i] >> Skip;
        }
        count++;
    }
    ReadFile.close();

    //opening average.dat for writing
    ofstream WriteFile;
    WriteFile.open("average.dat");

    //If file is not opening
    if (!WriteFile.is_open())
    {
        cout << "Unable to open average.dat" << endl;
        return 1;
    }
    
    //Writing content to average.dat using for loop
    for (int i = 0; i < StudentCount ; i++)
    {
        
        for (int j = 0; j < Students[i].TestTaken; j++)
        {
            TotalScore += Students[i].TestScore[j];
        }
        
        //Calculates total score
        TotalScore = TotalScore - findMinimum(Students[i].TestScore, Students[i].TestTaken );
        
        if (Students[i].TestTaken < 5)
        {
            //Calculates average if test taken is less than 5
            average = static_cast<double>(TotalScore) / (Students[i].TestTaken);
        }else{
            //Calculates average if test taken is equal to 5
            average = static_cast<double>(TotalScore) / (Students[i].TestTaken -1);
        }

        //Assigining average to i th index of array Average
        Average[i] = average;
    
        WriteFile << left << setw(15) << Students[i].Id;
        WriteFile << left << setw(15) << setprecision(3) << showpoint << Average[i];
        WriteFile << endl;

        //Intializing to zero
        TotalScore = 0;
        average = 0;
    }

    // Deletinh allocated memory
    delete [] Students->TestScore;
    delete [] Students;
    delete [] Average;

    //Displaying message
    cout << "Results exported to file." << endl;

    //Closing the file
    WriteFile.close();
    return 0;
}

/*
function: findMinimum
Description: This function return minimum of test scores
*/
int findMinimum(int Scores[], int TestTaken){
    //Declaring variable needed to store minimum
    int temp;

    // Returning minimum as directed
    if (TestTaken < 5)
    {
        temp = 0;
    }else{
        temp = Scores[0];
        for (int i = 0; i < TestTaken; i++)
        {
            if (temp > Scores[i])
            {
                temp = Scores[i];
            }
        }
    }
    return temp;
}