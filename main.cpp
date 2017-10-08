#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

using namespace std;

string words[3][10] = {{"job","jam","jaw","jug","jog","joy","max","cat","bat","sat"},
                       {"jazz","buzz","fizz","quiz","jump","joke","java","fuji","bowl","fowl"},
                       {"pizza","jumpy","quick","taxes","juices","zombi","unzip","crazy","field","video"}} ;

void printString(int , int );
void displayResult(int , int , string );


class User{

    string name;
    int rollNo,score;
public:
    User(){
        score = 0;
        rollNo = -1;
    }
    void getDet(){

        cout << "\t\t\t\tPlease enter your name: ";
        getline(cin,name);
        cout << "\t\t\t\tPlease enter your roll no: ";
        cin >> rollNo;
    }
    string putName(){
        return name;
    }
    int putRoll(){
        return rollNo;
    }
    void calcScore(int n){

        switch(n){
            case 1: score += 2;
                    break;
            case 2: score += 1;
                    break;
            case 3: score -= 1;
                    break;
            case 4: score -= 2;
                    break;
            default : "\n Wrong code";
        }
    }

    int retScore(){
        return score;
    }

};


int main()
{
    int level = 1,x = 0, flag = 0,n = 0;
    string inpString, actString;
    User u1;

    cout << "\n\n\n\n\n\n\n\t\t\t\t-----------Welcome---------" << endl;
    u1.getDet();
    system("cls");
    for(int i = 0; i<10; i++){
        srand(time(NULL));
        n = rand() %10;
        cout << "Q" << i+1 << ". ";
        printString(level,n);
        cout<<endl;
        cin >> actString;
        if(words[level-1][n] == actString)
            x = 1;
        else
            x = 0;

            if(x)
            cout<<"\t\tcorrect\n";
            else
            cout<<"\t\tincorrect\n";
        if(x){

            if(flag < 2){
                flag++;
                u1.calcScore(2);
            }
            else{

                if(level != 3){
                    level++;
                    u1.calcScore(1);
                }

            }

        }

        else{

            flag = 0;
            if(level != 1){
                level--;
                u1.calcScore(3);
            }
            else{
                u1.calcScore(4);
            }

        }

    }
    displayResult(u1.retScore(),level,u1.putName());
    cout << endl << endl;
    system("pause");
    return 0;
}

void displayResult(int s, int l, string n){

    system("cls");
    cout << "\t";
    cout << "\t\t\t\t\n -------------- REPORT ---------------\n"
         << n << " has successfully completed the test with a score of: " << s
         << " with level: " << l << endl;
    switch(l){

        case 1: cout << "\n You need to improve. We strongly recommend to attend all the next classes of this topic.";
                break;
        case 2: cout << "\n Good. You should take the quiz again to improve your level";
                break;
        case 3: cout <<"\n Well Done. You are well versed with the topic. You may skip all the next classes of this topic, and don't worry about the attendance. :P";
                break;
        default: cout << "\nError. This level does not exist!.";

    }
    cout << "\n\n\t\t\t\tThank You for taking the quiz";
}

void printString(int l, int n){
   string s = words[l-1][n];
    random_shuffle(s.begin(),s.end());
    cout << s;
}
