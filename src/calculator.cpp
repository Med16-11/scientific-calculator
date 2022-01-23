#include<iostream>
#include<sstream>
#include<string>
#include<stack>
using namespace std;

bool isOperator(const string& input){
    string ops[] = {"-", "+", "*", "/"};
    
    for(int i = 0; i < 4; i++){
        
        if(input == ops[i]){
            return true;
        }
    }
    return false;
}

void performOperation(const string& input, stack<double>&calcStack){
    double lval, rval, res;
    
    rval = calcStack.top();
    calcStack.pop();
    
    lval = calcStack.top();
    calcStack.pop();
    
    if(input == "-"){
        res = lval-rval;
    }
    else if ( input == "+"){
        res = lval + rval;
    }
    else if ( input == "*"){
        res = lval * rval;
    }
    else{
        res = lval/rval;
    }
    
    cout<<res<<endl;
    calcStack.push(res);
}

int main()
{
    cout<<"Welcome to the calculator"<<endl;
    stack<double>calcStack;
    string input;
    
    while(true){
        
        //display prompt
        cout<<">>";
        
        //get input
        cin>>input;
        
        //checking numeric value 
        double num;
        if(istringstream(input) >> num){
            calcStack.push(num);
        }
        //checking operator
        else if(isOperator(input)){
            performOperation(input, calcStack);
        }
        //quit case
        else if (input == "q"){
            return 0;
        }
        
        //invalid input
        else{
            cout<<"Invalid Input"<<endl;
        }
        
    }
}
