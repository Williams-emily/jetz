#include <iostream>
#include <string>

using namespace std;

void HelloWorld();
int Addition(int num1, int num2);
void die();
int randomEvent();
void userInput();

bool deathFlag = 0;
const char fate[5][5] = {   {'d','d','d','d','d'},
                            {'d','d','d','d','d'},
                            {'d','l','l','l','d'},
                            {'d','d','l','d','d'},
                            {'d','d','d','d','d'},
                        };

string description[5][5] = {    {"","you ","","",""},
                                {"","left test straight","straight","","you died"},
                                {"left test left","left","This is where you started","right","you died"},
                                {"","left test backward","backward","","you died"},
                                {"","","","",""},
                            };

int location[2] = {2,2};

int main() {

    int j = location[0];
    int i = location[1];

    char choice = 'a';
    HelloWorld();

    while (!deathFlag) {

        cout << "" << description[i][j-1] <<  "\n" << description[i-1][j] <<  "\n" << description[i][j+1] << "\n" << description[i+1][j]<< "\n";

        cout << "\n\nWhich way do you want to go? (l/s/r/b)\n";

        userInput();

        j = location[0];
        i = location[1];
        if (fate[i][j] == 'd') {
            die();
        }
    }
    return 0;
}

void HelloWorld() {
    cout << "This is a Zork game. Test your bravery in this adventure!\n\n";
    cout << "************************************************************\n\n";
    return;
}

void die() {
    cout << "Uh oh! you died!\n";
    deathFlag = 1;
    return;
}

void userInput() {
    bool inputFlag = 0;
    char input = 'q';
    while(!inputFlag) {
        cin >> input;
        cout <<"\n";
        if (input == 'l') {
                location[0] = location[0] - 1;
                inputFlag = 1;
        }
        if (input == 'r') {
                location[0] = location[0] + 1;
                inputFlag = 1;
        }
        if (input == 's') {
                location[1] = location[1] - 1;
                inputFlag = 1;
        }
        if (input == 'b') {
                location[1] = location[1] + 1;
                inputFlag = 1;
        }
    }
    return;
}
