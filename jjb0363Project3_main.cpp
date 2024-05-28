#include "jjb0363Project3_header.h"

int main()
{
    Menu MenuChoice;
    int Choice;
    int Id;

    while ((Choice != Quit))
    {
        // Displaying menu
        cout << "1.Add" << endl;
        cout << "2.Remove" << endl;
        cout << "3.Display" << endl;
        cout << "4.Search" << endl;
        cout << "5.Results" << endl;
        cout << "6.Quit" << endl;

        // Asking user to select one option from above menu.
        cout << "Enter choice: ";
        cin >> Choice;

        MenuChoice = static_cast<Menu>(Choice);

        // Switch case
        switch (MenuChoice)
        {
        case Add:

            // Calling addStudent
            addStudent();
            break;

        case Remove:
            // Asking user to enter Id they want to remove
            cout << "Enter ID of student to remove: ";
            cin >> Id;

            // Calling removeStudent
            removeStudent(Id);
            break;

        case Display:
            // Calling display function
            display();
            break;
            
        case Search:
            // Asking user to enter Id they want to remove
            cout << "Enter ID of student to search: ";
            cin >> Id;

            // Calling search 
            search(Id);
            break;

        case Results:
            // Calling exportResults 
            exportResults();
            break;

        case Quit:
            cout << "Bye !!!";
            break;

        default:
            cout << "Incorrect choice. Please enter again." << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}