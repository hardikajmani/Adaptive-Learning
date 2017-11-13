#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <windows.h>

using namespace std;

string words[30][2] = {{"job","work"},{"jam","traffic"},{"jaw","Teeth"},{"jug","Water Container"},{"jog","Exercise"},{"joy","Happiness"},{"max","Full"},{"cat","Pet"},{"bat","Cricket"},{"sat","Sit"},
                       {"jazz","Music"},{"buzz","Bees"},{"fizz","Soda"},{"quiz","Test"},{"jump","Height"},{"joke","Laugh"},{"java","language"},{"fuji","Mountain"},{"bowl","Rice"},{"wolf","Animal"},
                       {"pizza","Dominos"},{"jumpy","Bounce"},{"quick","Fast"},{"taxes","GST"},{"juices","Fruits"},{"zombi","Walking Dead"},{"unzip","Zip"},{"crazy","Mad"},{"field","Crops"},{"video","Movie"}} ;

void printString(int , int );
void displayResult(int , int , string );
void welcomePage();


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
            case 4: score -= 4;
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
    int level = 1,x = 0, flag = 0,n = 0,arr[30] = {-1};
    string inpString, actString;
    User u1;

    welcomePage();
    cout << "\n\n\n\n\n\n\n\t\t\t\t-----------Welcome-----------" << endl;
    u1.getDet();
    system("cls");
    for(int i = 0; i<10; i++){
        start:
        n = 0;
        srand(time(NULL) + (rand()%100));
        n = rand() %10;
        if(level != 1)
                n += ((level-1)*10);
        for(int j = 0; j<=i; j++){
            if(arr[j] == n)
                goto start;
        }
        arr[i] = n;
        cout << "\t\tQ" << i+1 << ". ";

        printString(level,n);
        cout << "\t\t(" << words[n][1] << ")";
        cout<<endl;
        cout << "\t\t->";
        cin >> actString;
        if(words[n][0] == actString)
            x = 1;
        else
            x = 0;

        if(x){
            cout<<"\t\t\t\tcorrect\n\n";
            if(flag < 1){
                flag++;
                u1.calcScore(2);
            }
            else{

                if(level != 3){
                    level++;
                    cout<<"\n\t\t\t\tKeep Going.\n\n";
                    u1.calcScore(1);
                    flag = 0;
                }

            }

        }

        else{
            cout<<"\t\t\t\tincorrect\n\n";
            flag = 0;
            if(level != 1){
                level--;
                cout<<"\n\t\t\t\tAnswer Carefully.\n\n";
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
    cout << "\n\t\t\t\t -------------- REPORT ---------------\n\t\t"
         << "\n\n\t"<< n << " has successfully completed the test with a score of: " << s
         << " with level: " << l << endl;
    switch(l){

        case 1: cout << "\n\n\n\t\t You need to improve.\n\t\t We strongly recommend to attend all the next classes of this topic.";
                break;
        case 2: cout << "\n\n\n\t\t Good.\n\t\t You should take the quiz again to improve your level";
                break;
        case 3: cout <<"\n\n\n\t\t Well Done.\n\t\t You are well versed with the topic. You may skip all the next classes of this topic, and don't worry about the attendance. :P";
                break;
        default: cout << "\nError. This level does not exist!.";

    }
    cout << "\n\n\t\t\t\tThank You for taking the quiz";
}

void printString(int l, int n){
    string s = words[n][0];
    st:
    random_shuffle(s.begin(),s.end());
    if(s == words[n][0])
        goto st;
    for(int i = 0; i<s.length(); i++)
        cout << s[i] << "  ";
}

void welcomePage(){

    string s1 = "ADAPTIVE LEARNING", s2 = "  JUMBLED WORDS", s3 = "- Handcrafted  By ", s4 = "  Hardik Ajmani ;)";
    cout << "\n\n\n\n\t\t\t\t";
    for(int i = 0; i < s1.length(); i++){
        Sleep(100);
        cout << " " << s1[i];
    }
    Sleep(500);
    cout << "\n\t\t\t\t";
    for(int i = 0; i < s2.length(); i++){
        Sleep(100);
        cout << " " << s2[i];
    }
    Sleep(500);
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t";
    for(int i = 0; i < s3.length(); i++){
        Sleep(50);
        cout << s3[i];
    }
    Sleep(1000);
    cout << "\n\n\t\t\t\t\t\t\t\t\t";
    for(int i = 0; i < s4.length(); i++){
        Sleep(70);
        cout << s4[i];
    }
    Sleep(1500);
    cout << "\n\n\n";
    system("pause");
    system("cls");
}
