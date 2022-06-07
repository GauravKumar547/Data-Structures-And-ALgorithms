/*
    NAME = GAURAV KUMAR
    COURSE = BSC(H) COMPUTER SCIENCE (IIIrd SEM)
    ROLL NO. = 19HCS4017
    SUBJECT = DATA STRUCTURES
    PROGRAM = Conversion of infix expression to postfix and evaluation of postfix expression using stack
*/

#include "Stacklist4017.h" 
using namespace std; 

int precedence(char c) 
{ 
    switch (c)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return -1;
    }	 
} 

string infixToPostfix(string s) 
{ 
	StackList<float> stk;  
	string postfixExp=""; 
	for(int i = 0; i < s.length(); i++) 
	{  
		if(isdigit(s[i])) 
		{
            postfixExp+=s[i]; 
        }
		else if(s[i] == '(') 
		{
            stk.push('('); 
        }
		else if(s[i] == ')') 
		{ 
            
			while( !stk.empty() && stk.top() != '(') 
			{ 
                char c =stk.pop(); 
                postfixExp += c; 
			} 
			if(stk.top() == '(') 
			{ 
				char c = stk.pop();  
			} 
		} 
		else
        { 
			while(!stk.empty() && precedence(s[i]) <= precedence(stk.top())) 
			{ 
				char c = stk.pop(); 
				postfixExp += c; 
			} 
			stk.push(s[i]); 
		} 

	} 

	while(!stk.empty()) 
	{ 
		char c = stk.pop(); 
		postfixExp += c; 
	} 
	return postfixExp; 
} 

float evaluatePostExp(string exp)  
{  
    StackList<float> stk;
    int i;  
    for (i = 0; exp[i]; i++)  
    {  
        if (isdigit(exp[i]))  
        {
            stk.push(exp[i] - '0');  
        }
        else
        {  
            float val1 = stk.pop();  
            float val2 = stk.pop();  
            switch (exp[i])  
            {  
            case '+': 
                stk.push( val2 + val1);
                break;  
            case '-': 
                stk.push(val2 - val1); 
                break;  
            case '*': 
                stk.push(val2 * val1); 
                break;  
            case '/': 
                stk.push(val2/val1); 
                break;  
            }  
        }  
    }  
    return stk.pop();  
}  


int main() 
{ 
	string exp;

    cout<<"\nEnter the infix expression: ";
    getline(cin,exp);
    cout<<"\nYour entered infix expression: "<<exp<<endl; 

    string postExp = infixToPostfix(exp);
    cout<<"The postfix for entered infix expression: "<<postExp<<endl; 
    
    float evalExp = evaluatePostExp(postExp);
    cout<<"The result of evaluation of the entered expression: "<<evalExp<<endl;

	return 0; 
} 

