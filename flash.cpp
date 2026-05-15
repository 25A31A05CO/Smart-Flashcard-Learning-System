#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Flashcard
{
private:
    int id;
    string subject;
    string question;
    string answer;
    int difficulty;

public:

    Flashcard() {}

    Flashcard(int i, string s, string q, string a, int d)
    {
        id = i;
        subject = s;
        question = q;
        answer = a;
        difficulty = d;
    }

    int getID() { return id; }
    string getSubject() { return subject; }
    string getQuestion() { return question; }
    string getAnswer() { return answer; }
    int getDifficulty() { return difficulty; }

    void setSubject(string s) { subject = s; }
    void setQuestion(string q) { question = q; }
    void setAnswer(string a) { answer = a; }
    void setDifficulty(int d) { difficulty = d; }

    void display()
    {
        cout << "\nFlashcard ID : " << id << endl;
        cout << "Subject      : " << subject << endl;
        cout << "Question     : " << question << endl;
        cout << "Answer       : " << answer << endl;
        cout << "Difficulty   : " << difficulty << endl;
        cout << "-------------------------------------\n";
    }

    void saveToFile(ofstream &file)
    {
        file << id << endl;
        file << subject << endl;
        file << question << endl;
        file << answer << endl;
        file << difficulty << endl;
    }

    void loadFromFile(ifstream &file)
    {
        file >> id;
        file.ignore();
        getline(file, subject);
        getline(file, question);
        getline(file, answer);
        file >> difficulty;
        file.ignore();
    }
};

vector<Flashcard> flashcards;

void loadFlashcards();
void saveFlashcards();
void addFlashcard();
void viewFlashcards();
void studyFlashcards();
void searchFlashcard();
void modifyFlashcard();
void deleteFlashcard();
void showStatistics();
int generateID();

int main()
{
    int choice;

    loadFlashcards();

    do
    {
        cout << "\n====================================================";
        cout << "\n        SMART FLASHCARD LEARNING SYSTEM";
        cout << "\n====================================================\n";
        cout << "1. Add Flashcard\n";
        cout << "2. View Flashcards\n";
        cout << "3. Study Flashcards\n";
        cout << "4. Search Flashcard\n";
        cout << "5. Modify Flashcard\n";
        cout << "6. Delete Flashcard\n";
        cout << "7. Show Statistics\n";
        cout << "8. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1: addFlashcard(); break;
            case 2: viewFlashcards(); break;
            case 3: studyFlashcards(); break;
            case 4: searchFlashcard(); break;
            case 5: modifyFlashcard(); break;
            case 6: deleteFlashcard(); break;
            case 7: showStatistics(); break;
            case 8:
                saveFlashcards();
                cout << "\nThank You for Using the System!\n";
                system("pause");
                break;
            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 8);

    return 0;
}

void loadFlashcards()
{
    ifstream file("flashcards.txt");
    if(!file) return;

    while(file.peek() != EOF)
    {
        Flashcard temp;
        temp.loadFromFile(file);
        flashcards.push_back(temp);
    }

    file.close();
}

void saveFlashcards()
{
    ofstream file("flashcards.txt");
    for(int i = 0; i < flashcards.size(); i++)
        flashcards[i].saveToFile(file);
    file.close();
}

int generateID()
{
    if(flashcards.empty()) return 1;
    return flashcards.back().getID() + 1;
}

void addFlashcard()
{
    string subject, question, answer;
    int difficulty;

    cout << "\nEnter Subject: ";
    getline(cin, subject);
    cout << "Enter Question: ";
    getline(cin, question);
    cout << "Enter Answer: ";
    getline(cin, answer);
    cout << "Enter Difficulty Level (1-5): ";
    cin >> difficulty;
    cin.ignore();

    Flashcard temp(generateID(), subject, question, answer, difficulty);
    flashcards.push_back(temp);
    saveFlashcards();
    cout << "\nFlashcard Added Successfully!\n";
}

void viewFlashcards()
{
    if(flashcards.empty()) { cout << "\nNo Flashcards Available!\n"; return; }
    cout << "\n============= FLASHCARDS =============\n";
    for(int i = 0; i < flashcards.size(); i++)
        flashcards[i].display();
}

void studyFlashcards()
{
    if(flashcards.empty()) { cout << "\nNo Flashcards Available!\n"; return; }

    int correct = 0;
    cout << "\n============= STUDY MODE =============\n";

    for(int i = 0; i < flashcards.size(); i++)
    {
        cout << "\nSubject : " << flashcards[i].getSubject() << endl;
        cout << "Question: " << flashcards[i].getQuestion() << endl;
        cout << "\nPress Enter to View Answer...";
        cin.get();
        cout << "Answer : " << flashcards[i].getAnswer() << endl;

        int choice;
        cout << "\nDid you answer correctly?\n1. Yes\n2. No\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) correct++;
    }

    float accuracy = ((float)correct / flashcards.size()) * 100;
    cout << fixed << setprecision(2);
    cout << "\n============= RESULT =============\n";
    cout << "Total Flashcards : " << flashcards.size() << endl;
    cout << "Correct Answers  : " << correct << endl;
    cout << "Accuracy         : " << accuracy << "%\n";

    if(accuracy >= 80)       cout << "Performance      : Excellent!\n";
    else if(accuracy >= 50)  cout << "Performance      : Good!\n";
    else                     cout << "Performance      : Needs Improvement!\n";
}

void searchFlashcard()
{
    if(flashcards.empty()) { cout << "\nNo Flashcards Available!\n"; return; }

    string keyword;
    bool found = false;

    cout << "\nEnter Subject or Keyword: ";
    getline(cin, keyword);
    cout << "\n============= SEARCH RESULT =============\n";

    for(int i = 0; i < flashcards.size(); i++)
    {
        if(flashcards[i].getSubject().find(keyword) != string::npos ||
           flashcards[i].getQuestion().find(keyword) != string::npos)
        {
            flashcards[i].display();
            found = true;
        }
    }

    if(!found) cout << "\nNo Matching Flashcards Found!\n";
}

void modifyFlashcard()
{
    if(flashcards.empty()) { cout << "\nNo Flashcards Available!\n"; return; }

    int id;
    bool found = false;

    cout << "\nEnter Flashcard ID to Modify: ";
    cin >> id;
    cin.ignore();

    for(int i = 0; i < flashcards.size(); i++)
    {
        if(flashcards[i].getID() == id)
        {
            string subject, question, answer;
            int difficulty;

            cout << "\nEnter New Subject: ";        getline(cin, subject);
            cout << "Enter New Question: ";         getline(cin, question);
            cout << "Enter New Answer: ";           getline(cin, answer);
            cout << "Enter New Difficulty Level: "; cin >> difficulty; cin.ignore();

            flashcards[i].setSubject(subject);
            flashcards[i].setQuestion(question);
            flashcards[i].setAnswer(answer);
            flashcards[i].setDifficulty(difficulty);

            saveFlashcards();
            cout << "\nFlashcard Modified Successfully!\n";
            found = true;
            break;
        }
    }

    if(!found) cout << "\nFlashcard ID Not Found!\n";
}

void deleteFlashcard()
{
    if(flashcards.empty()) { cout << "\nNo Flashcards Available!\n"; return; }

    int id;
    bool found = false;

    cout << "\nEnter Flashcard ID to Delete: ";
    cin >> id;
    cin.ignore();

    for(int i = 0; i < flashcards.size(); i++)
    {
        if(flashcards[i].getID() == id)
        {
            flashcards.erase(flashcards.begin() + i);
            saveFlashcards();
            cout << "\nFlashcard Deleted Successfully!\n";
            found = true;
            break;
        }
    }

    if(!found) cout << "\nFlashcard ID Not Found!\n";
}

void showStatistics()
{
    if(flashcards.empty()) { cout << "\nNo Flashcards Available!\n"; return; }

    int easy = 0, medium = 0, hard = 0;

    for(int i = 0; i < flashcards.size(); i++)
    {
        if(flashcards[i].getDifficulty() <= 2)       easy++;
        else if(flashcards[i].getDifficulty() == 3)  medium++;
        else                                          hard++;
    }

    cout << "\n============= STATISTICS =============\n";
    cout << "Total Flashcards : " << flashcards.size() << endl;
    cout << "Easy Level       : " << easy << endl;
    cout << "Medium Level     : " << medium << endl;
    cout << "Hard Level       : " << hard << endl;
}