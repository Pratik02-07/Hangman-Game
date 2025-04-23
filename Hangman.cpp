    #include <iostream>
    #include <cstdlib>
    #include <ctime>
    #include <string>

    using namespace std;

    int NUM_TRY = 6; 
    int checkGuess(char, string, string &);
    void main_menu();
    void drawHangman(int);
    string message = "Play!";

    int main(int argc, char *argv[])
    {
        char letter;
        string word;
        int choice;

        string months[] =
        {
            "january",
            "february",
            "march",
            "april",
            "may",
            "june",
            "july",
            "august",
            "september",
            "october",
            "november",
            "december"
        };

        string animals[] =
        {
            "lion",
            "elephant",
            "tiger",
            "giraffe",
            "zebra",
            "monkey",
            "hippopotamus",
            "crocodile",
            "rhinoceros",
            "kangaroo"
        };

        string countries[] =
        {
            "usa",
            "canada",
            "mexico",
            "brazil",
            "france",
            "germany",
            "italy",
            "india",
            "china",
            "japan"
        };

        string fruits[] =
        {
            "apple",
            "banana",
            "orange",
            "grape",
            "strawberry",
            "watermelon",
            "pineapple",
            "mango",
            "kiwi",
            "peach"
        };

        string colors[] =
        {
            "red",
            "orange",
            "yellow",
            "green",
            "blue",
            "purple",
            "pink",
            "brown",
            "black",
            "white"
        };

        string professions[] =
        {
            "doctor",
            "teacher",
            "engineer",
            "lawyer",
            "chef",
            "artist",
            "pilot",
            "scientist",
            "firefighter",
            "police"
        };

        string sports[] =
        {
            "soccer",
            "basketball",
            "tennis",
            "baseball",
            "volleyball",
            "swimming",
            "golf",
            "boxing",
            "football",
            "cricket"
        };

        string vehicles[] =
        {
            "car",
            "bicycle",
            "motorcycle",
            "bus",
            "truck",
            "train",
            "boat",
            "airplane",
            "helicopter",
            "submarine"
        };


        system("color 4");
        system("cls");
        cout << "Welcome to Hangman!" << endl;
        cout << "Choose a category:" << endl;
        cout << "1. Months" << endl;
        cout << "2. Animals" << endl;
        cout << "3. Countries" << endl;
        cout << "4. Fruits" << endl;
        cout << "5. Colors" << endl;
        cout << "6. Professions" << endl;
        cout << "7. Sports" << endl;
        cout << "8. Vehicles" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        srand(time(NULL));
        switch (choice)
        {
            case 1:
            {
                int n = rand() % 12;
                word = months[n];
                break;
            }
            case 2:
            {
                int n = rand() % 10;
                word = animals[n];
                break;
            }
            case 3:
            {
                int n = rand() % 10;
                word = countries[n];
                break;
            }
            case 4:
            {
                int n = rand() % 10;
                word = fruits[n];
                break;
            }
            case 5:
            {
                int n = rand() % 10;
                word = colors[n];
                break;
            }
            case 6:
            {
                int n = rand() % 10;
                word = professions[n];
                break;
            }
            case 7:
            {
                int n = rand() % 10;
                word = sports[n];
                break;
            }
            case 8:
            {
                int n = rand() % 10;
                word = vehicles[n];
                break;
            }

            default:
            {
                cout << "Invalid choice! Exiting..." << endl;
                return 1;
            }
        }

        string hide_word(word.length(), '_');

        while (NUM_TRY != 0)
        {
            main_menu();
            drawHangman(NUM_TRY);
            cout << "\n\n\t\t\t\t" << hide_word;
            cout << "\n\n\t\t\t\tGuess a letter: ";
            cin >> letter;

            if (checkGuess(letter, word, hide_word) == 0)
            {
                message = "Incorrect letter.";
                NUM_TRY = NUM_TRY - 1;
            }
            else
            {
                message = "NICE! You guessed a letter";
            }

            if (word == hide_word)
            {
                message = "\033[1;32mCongratulations! You got it!\033[0m";
                main_menu();
                cout << "\n\t\t\t\tThe word is : " << word << endl;
                break;
            }
        }
        if (NUM_TRY == 0)
        {
            message = "\033[0;31mNOOOOOOO!...you've been hanged.";
            main_menu();
            drawHangman(NUM_TRY);
            cout << "\n\t\t\t\tThe word was : " << word << endl;
        }
        cin.ignore();
        cin.get();
        return 0;
    }

    int checkGuess(char guess, string secret_word, string &guess_word)
    {
        int i;
        int matches = 0;
        int len = secret_word.length();
        for (i = 0; i < len; i++)
        {
            if (guess == guess_word[i])
                return 0;

            if (guess == secret_word[i])
            {
                guess_word[i] = guess;
                matches++;
            }
        }
        return matches;
    }

    void main_menu()
    {
        system("color 03");
        system("cls");
        cout << "\n\t\t\t\tHangman Game!";
        cout << "\n\t\tYou have " << NUM_TRY << " tries to try and guess the word.";
        cout << "\n\n\t\t\t\t" + message;
    }

    void drawHangman(int attempt)
    {
        switch (attempt)
        {
            case 0:
                cout << "\n\n\t\t\t\t\t  +----+";
                cout << "\n\t\t\t\t\t  |    |";
                cout << "\n\t\t\t\t\t  |    O";
                cout << "\n\t\t\t\t\t  |   /|\\";
                cout << "\n\t\t\t\t\t  |   / \\";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t__|__";
                break;
            case 1:
                cout << "\n\n\t\t\t\t\t  +----+";
                cout << "\n\t\t\t\t\t  |    |";
                cout << "\n\t\t\t\t\t  |    O";
                cout << "\n\t\t\t\t\t  |   /|\\";
                cout << "\n\t\t\t\t\t  |   /";
                cout << "\n\t\t\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t__|__";
                break;
            case 2:
                cout << "\n\n\t\t\t\t\t  +----+";
                cout << "\n\t\t\t\t\t  |    |";
                cout << "\n\t\t\t\t\t  |    O";
                cout << "\n\t\t\t\t\t  |   /|\\";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t__|__";
                break;
            case 3:
                cout << "\n\n\t\t\t\t\t  +----+";
                cout << "\n\t\t\t\t\t  |    |";
                cout << "\n\t\t\t\t\t  |    O";
                cout << "\n\t\t\t\t\t  |   /|";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t__|__";
                break;
            case 4:
                cout << "\n\n\t\t\t\t\t  +----+";
                cout << "\n\t\t\t\t\t  |    |";
                cout << "\n\t\t\t\t\t  |    O";
                cout << "\n\t\t\t\t\t  |    |";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t__|__";
                break;
            case 5:
                cout << "\n\n\t\t\t\t\t  +----+";
                cout << "\n\t\t\t\t";
                cout << "\t\t  |    |";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t__|__";
                break;
            case 6:
                cout << "\n\n\t\t\t\t\t  +----+";
                cout << "\n\t\t\t\t\t  |    |";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t__|__";
                break;
        }
    }



