#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int isValid(char guess, string word) {
    string::size_type index = word.find(guess, 0);
    if(index != string::npos) { 
        return index;
    } 
    return -1; 
}

void loadGame(char *p, int n) {
    for(int i=0; i<n; i++) {
        p[i] = '*';
    }
    cout << endl;
}

void updateGame(char *p,  string word, char guess) {
   int pos = 0;
   int index;
   while((index = word.find(guess, pos)) != string::npos) {
        p[index] = guess;
        pos = index + 1; //new position is from next element of index
   }
}

void printGame(char *p, int n) {
    for(int i=0; i<n; i++) {
        cout << p[i];
    }
    cout << endl;
}

bool containsAll(string s1, string s2) {
    for(int i=0; i<s2.length(); i++) {
       if(s1.find(s2[i]) == -1) {
           return false;
       }
    }
    return true;
}


void drawing(int life)
{
     
     switch(life)
     {
     case 6:
            cout << " ______________"<<endl;
            cout << " |         |"<<endl;
            cout << " |           " <<endl;
            cout << "_|______________"<<endl;
     break;      
     case 5:       
            cout << " ______________"<<endl;
            cout << " |         |   "<<endl;
            cout << " |         0   "<<endl;
            cout << "_|_____________"<<endl;     
     break;
     case 4:       
            cout << " ______________"<<endl;
            cout << " |         |   "<<endl;
            cout << " |         0   " <<endl;
            cout << " |         |   " <<endl;
            cout << "_|______________"<<endl;     
     break;
     case 3:       
            cout << " ______________"<<endl;
            cout << " |         |   "<<endl;
            cout << " |         0/  " <<endl;
            cout << "_|______________"<<endl;
     break;      
     case 2:
            cout << " ______________"<<endl;
            cout << " |          |"<<endl;
            cout << " |        \\0/  " <<endl;
            cout << " |          |    "<<endl;
            cout << "_|______________ "<<endl;
     break;       
     case 1:
            cout << " _____________"<<endl;
            cout << " |          |"<<endl;
            cout << " |        \\0/" <<endl;
            cout << " |          |"<<endl;
            cout << " |         /  "<<endl;
            cout << "_|______________"<<endl;
     break;       
     case 0:  
            cout << " ______________ "<<endl;
            cout << " |          |   "<<endl;
            cout << " |        \\0/" <<endl;
            cout << " |          |   "<<endl;
            cout << " |         / \\ "<<endl;
            cout << "_|______________"<<endl;
             
     }    
}     

int main() {
    //calling srand with the current time generates diff nummber each time
     srand((unsigned) time(0));
    string words[15] = { "abruptly","absurd","abyss","affix","askew","avenue","awkward","axiom","azure","bagpipes","bandwagon","banjo","bayou","beekeeper", "buchubasnet" };

    int randomNo =  rand() % 15;
    string secret_word = words[randomNo];

    
    bool gameOver = false;
    bool win = false;

    int lives = 6;

    char guess;
    string incorrectGuesses;
    string correctGuesses;
    char *guessedWords = new char[secret_word.length()];
    loadGame(guessedWords, secret_word.length());

    cout <<" ------HANGMAN--------" << endl <<endl ;
  
    while(!gameOver && lives > 0) {
        updateGame(guessedWords, secret_word, guess);
        printGame(guessedWords, secret_word.length());
        
        if(incorrectGuesses.length() > 0) {
            cout <<"Wrong guesses: " <<incorrectGuesses <<endl ;
        }
        
        cout <<endl;
        drawing(lives);
        cout << endl; 
        cout << "Enter a guess: ";
        cin >> guess ;


        if(isValid(guess, secret_word) != -1) {
            correctGuesses += guess;
            if(containsAll(correctGuesses, secret_word)) {
                gameOver = true;
                win = true;
            }
            
        } else {
            incorrectGuesses += guess;
            cout << endl;
            
            if(lives == 0) {
                gameOver = true;
            }
            lives--;
        }
        cout <<endl;
    }
    if(win && gameOver) {
        cout << "Bravo, you saved your life" << endl;
        
    } else {
        drawing(lives);
        cout << "OOps, You got hanged till death" <<endl;
        cout << "The secret word is " << secret_word << endl;
    }
    
    return 0;
}