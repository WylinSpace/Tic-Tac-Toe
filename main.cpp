#include <iostream>
#include <chrono>
#include <thread>
#include <regex>
#include <cstdlib>
#include <ctime>
using namespace std;

//COLOR DEFINIITION
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

//TEXT STYLE
#define BOLD            "\033[1m"
#define ITALIC          "\033[3m"
#define UNDERLINE       "\033[4m"
#define STRIKETHROUGH   "\033[9m"

//CURSOR MOVEMENT
#define MOVE_CURSOR(row, col) "\033[" #row ";" #col "H"
#define CLEAR_SCREEN "\033[2J"
#define CLEAR_TO_END "\033[0J"
#define SAVE_CURSOR "\033[s"
#define RESTORE_CURSOR "\033[u"
#define HIDE_CURSOR "\033[?25l"
#define SHOW_CURSOR "\033[?25h"

class TicTacToe{
    private:
    int row = -1;
    int column = -1;
    int movementCount = 0;
    bool ComputerMoveSuccessfully = false;
    string positionSet;
    string diagram[3][3]{
        {" "," "," "},
        {" "," "," "},
        {" "," "," "}
    };

    public:
    void versusMode(){
        cout<<MOVE_CURSOR(0,0)<<CLEAR_SCREEN<<BOLD<<BLUE<<"TIC TAC TOE - Versus Mode\n"<<RESET<<endl;
        do{
            regex pattern("^[0-9]$");
            printInterface();
            if(WinCheck()) break;
            if(EmptyCheck()) break;
            cout<<"\nEnter Your Coordinate > ";
            cin>>positionSet;
            if(positionSet=="0") break;
            if (regex_match(positionSet, pattern)) {
                int position = stoi(positionSet);
                enterTheOption(position);
            } else {
                cout << "Invalid input! Please enter a number between 1 and 9.\n";
            }
            cout<<MOVE_CURSOR(2,0)<<CLEAR_TO_END<<endl;
        }while(true);
    }

    void computerMode(){
        cout<<MOVE_CURSOR(0,0)<<CLEAR_SCREEN<<BOLD<<BLUE<<"TIC TAC TOE - Computer Mode\n"<<RESET<<endl;
        do{
            regex pattern("^[0-9]$");
            printInterface();
            if(WinCheck()) break;
            if(EmptyCheck()) break;
            cout<<"\nEnter Your Coordinate > ";
            cin>>positionSet;
            if (regex_match(positionSet, pattern)) {
                if(positionSet=="0") break;
                int position = stoi(positionSet);
                enterTheOption(position);
            } else {
                cout << "Invalid input! Please enter a number between 1 and 9.\n";
            }
            cout<<MOVE_CURSOR(2,0)<<CLEAR_TO_END<<endl;
            printInterface();
            ComputerMoveSuccessfully = false;
            if(WinCheck()) break;
            if(EmptyCheck()) break;
            ComputerMove();
            cout<<MOVE_CURSOR(2,0)<<CLEAR_TO_END<<endl;
        }while(true);
    }

    void printInterface(){
        cout<<"┌───────┐"<<endl;
        for(row=0;row<3;row++){
            cout<<"│ ";
            for(column=0;column<3;column++){
                if(diagram[row][column]==" "){
                    cout<<diagram[row][column]<<" ";
                } else if(diagram[row][column]=="X"){
                    cout<<RED<<BOLD<<diagram[row][column]<<RESET<<" ";
                } else if(diagram[row][column]=="O"){
                    cout<<GREEN<<BOLD<<diagram[row][column]<<RESET<<" ";
                }
            }
            cout<<"│"<<endl;
        }
        cout<<"└───────┘"<<endl;
    }

    void enterTheOption(int position){
        string InputSymbol;
        if((movementCount%2)!=0){
            InputSymbol = "O";
        } else if((movementCount%2)==0){
            InputSymbol = "X";
        }
        do{
            if(position==7){
                row=0;column=0;
            } else if(position==8) {
                row=0;column=1;
            } else if(position==9) {
                row=0;column=2;
            } else if(position==4){
                row=1;column=0;
            } else if(position==5) {
                row=1;column=1;
            } else if(position==6) {
                row=1;column=2;
            } else if(position==1){
                row=2;column=0;
            } else if(position==2) {
                row=2;column=1;
            } else if(position==3) {
                row=2;column=2;
            } else {
                cout<<HIDE_CURSOR<<RED<<BOLD<<"Option Invalid as it is not in the range offered."<<RESET<<endl;
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            bool IfEmpty = Emptyness(row,column);
            if(IfEmpty){
                diagram[row][column] = InputSymbol;
                movementCount++;
                break;
            } else {
                cout<<HIDE_CURSOR<<RED<<BOLD<<"Option Invalid as the position had been taken!"<<RESET<<endl;
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
        } while(true);
    }

    void ComputerEnterTheOption(int position){
        string InputSymbol;
        if((movementCount%2)!=0){
            InputSymbol = "O";
        } else if((movementCount%2)==0){
            InputSymbol = "X";
        }
        do{
            if(position==7){
                row=0;column=0;
            } else if(position==8) {
                row=0;column=1;
            } else if(position==9) {
                row=0;column=2;
            } else if(position==4){
                row=1;column=0;
            } else if(position==5) {
                row=1;column=1;
            } else if(position==6) {
                row=1;column=2;
            } else if(position==1){
                row=2;column=0;
            } else if(position==2) {
                row=2;column=1;
            } else if(position==3) {
                row=2;column=2;
            } else {
                cout<<HIDE_CURSOR<<RED<<BOLD<<"Option Invalid as it is not in the range offered."<<RESET<<endl;
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            bool IfEmpty = Emptyness(row,column);
            if(IfEmpty){
                ComputerMoveSuccessfully = true;
                diagram[row][column] = InputSymbol;
                movementCount++;
                break;
            } else {
                break;
            }
        } while(true);
    }

    bool Emptyness(int r,int c){
        if(diagram[r][c]==" "){
            return true;
        } else {
            return false;
        }
    }

    bool EmptyCheck(){
        int emptyboxCount = 0;
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                if(diagram[r][c] != " "){
                    emptyboxCount++;
                }
            }
        }
        if(emptyboxCount>=9){
            cout<<"Round End!"<<endl;
            this_thread::sleep_for(chrono::seconds(1));
            return true;
        } else {
            return false;
        }
    }

    bool WinCheck(){
        for(int i=0;i<3;i++){
            if((diagram[i][0]==diagram[i][1])&&(diagram[i][0]==diagram[i][2])&&(diagram[i][0]!=" ")){
                cout<<BOLD<<GREEN<<"You Win!"<<RESET<<endl;
                this_thread::sleep_for(chrono::seconds(1));
                return true;
            }
            if((diagram[0][i]==diagram[1][i])&&(diagram[0][i]==diagram[2][i])&&(diagram[0][i]!=" ")){
                cout<<BOLD<<GREEN<<"You Win!"<<RESET<<endl;
                this_thread::sleep_for(chrono::seconds(1));
                return true;
            }
            if((diagram[0][0]==diagram[1][1])&&(diagram[0][0]==diagram[2][2])&&(diagram[0][0]!=" ")){
                cout<<BOLD<<GREEN<<"You Win!"<<RESET<<endl;
                this_thread::sleep_for(chrono::seconds(1));
                return true;
            }
            if((diagram[0][2]==diagram[1][1])&&(diagram[0][2]==diagram[2][0])&&(diagram[0][2]!=" ")){
                cout<<BOLD<<GREEN<<"You Win!"<<RESET<<endl;
                this_thread::sleep_for(chrono::seconds(1));
                return true;
            }
        }
        return false;
    }

    void ComputerMove(){
        do{
            srand(time(0));
            int randomNumber = rand() % 9 + 1;
            ComputerEnterTheOption(randomNumber);
        } while(!ComputerMoveSuccessfully);
    }
};

int main(){
    do{
        TicTacToe TTT;
        cout<<MOVE_CURSOR(0,0)<<CLEAR_SCREEN<<BOLD<<BLUE<<"TIC TAC TOE (Press ctrl+c to quit!)\n"<<RESET<<endl;
        string Gamemode;
        int mode;
        cout << "Choose 1 for Versus Mode \nChoose 2 for Computer Mode"<<endl;
        do{
            cout<<"\nPlease Choose Your Game Mode > ";
            cin >> Gamemode;
            regex pattern("^[1-2]$");
            if (regex_match(Gamemode, pattern)) {
                mode = stoi(Gamemode);
                break;
            } else {
                cout<<HIDE_CURSOR<<RED<<BOLD<<"Invalid Input."<<RESET<<endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            cout<<MOVE_CURSOR(4,33)<<CLEAR_TO_END<<endl;
        }while(true);
        if(mode==1){
            TTT.versusMode();
        } else if(mode==2){
            TTT.computerMode();
        }
    }while(true);
}