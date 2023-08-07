#include <iostream>
#include <string>
using namespace std;
bool tie=false;
string n1="",n2="";
char token='X';
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,col;

void functionOne()//tic tac toe board display
{
    cout<<"    |     |    "<<endl;
    cout<<"  "<<space[0][0]<<" |  "<<space[0][1]<<"  | "<<space[0][2]<<"  "<<endl;
    cout<<"____|_____|____"<<endl;
    cout<<"    |     |    "<<endl;
    cout<<"  "<<space[1][0]<<" |  "<<space[1][1]<<"  | "<<space[1][2]<<"  "<<endl;
    cout<<"____|_____|____"<<endl;
    cout<<"    |     |    "<<endl;
    cout<<"  "<<space[2][0]<<" |  "<<space[2][1]<<"  | "<<space[2][2]<<"  "<<endl;

}

void functionTwo()//filling the board if entered correctly
{
    int digit;
    if(token == 'X')
    {
        cout<<n1<<" please enter"<<endl;
        cin>>digit;
    }
    if(token == '0')
    {
        cout<<n2<<" please enter"<<endl;
        cin>>digit;
    }
    if(digit == 1)
    {
        row=0;
        col=0;
    }
    if(digit == 2)
    {
        row=0;
        col=1;
    }
    if(digit == 3)
    {
        row=0;
        col=2;
    }
    if(digit == 4)
    {
        row=1;
        col=0;
    }
    if(digit == 5)
    {
        row=1;
        col=1;
    }
    if(digit == 6)
    {
        row=1;
        col=2;
    }
    if(digit == 7)
    {
        row=2;
        col=0;
    }
    if(digit == 8)
    {
        row=2;
        col=1;
    }
    if(digit == 9)
    {
        row=2;
        col=2;
    }
    else if(digit<0 || digit>9)
    {
        cout<<"INVALID!!"<<endl;
        functionTwo();
    }
    if(token == 'X' && space[row][col] != 'X' && space[row][col] != '0')
    {
        space[row][col]='X';
        token='0';
    }
    else if(token == '0' && space[row][col] != 'X' && space[row][col] != '0')
    {
        space[row][col]='0';
        token='X';
    }
    else
    {
        cout<<"No Empty Space"<<endl;
        functionTwo();
    }
    //functionOne();

}

bool functionThree()
{
    for (int i=0;i<3;i++)
    {
        if((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || (space[0][i] == space[1][i] && space[0][i] == space[2][i]))
        {
            return true;
        }
    }
    if((space[0][0] == space[1][1] && space[0][0] == space[2][2]) || (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
    {
        return true;
    }
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if(space[i][j] != 'X' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    tie=true;
    return true;
}

int main()
{
    cout<<"Enter name of 1st player"<<endl;
    getline(cin,n1);
    cout<<"Enter name of 2nd player"<<endl;
    getline(cin,n2);
    cout<<n1<<" is player 1 so he/she will play first"<<endl;
    cout<<n2<<" is player 2 so he/she will play second"<<endl;

    while(!functionThree())
    {
        functionOne();
        functionTwo();
        functionThree();
    }
    if(token == 'X' && tie==false)
    {
        cout<<"congratulations \n"<<n2<<" wins!!"<<endl;
    }
    else if(token == '0' && tie==false)
    {
        cout<<"congratulations \n"<<n1<<" wins!!"<<endl;
    }
    else
    {
        cout<<"It's a draw"<<endl;
    }
}
