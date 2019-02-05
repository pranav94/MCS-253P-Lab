#include <iostream>
#include <stack>
#include <string.h>
#include <stdio.h>
using namespace std;
#define STRMAX 1000

bool isOperator(char *c)
{
    return (strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "/") == 0 || strcmp(c, "*") == 0);
}

long evaluate(long operand1, long operand2, char opr)
{
    switch (opr)
    {
    case '+':
        return operand1 + operand2;
        break;
    case '-':
        return operand1 - operand2;
        break;
    case '*':
        return operand1 * operand2;
        break;
    case '/':
        return operand1 / operand2;
        break;
    }
    return 0;
}

bool isCommand(char *c)
{
    return strcmp(c, "p") == 0 || strcmp(c, "s") == 0 || strcmp(c, "d") == 0;
}

void printResult(long s)
{
    cout << "The result is: " << s << endl;
}

void swapStack(stack<long> &s)
{
    long s1 = s.top();
    s.pop();
    long s2 = s.top();
    s.pop();
    s.push(s1);
    s.push(s2);
}

void evaluateCommand(char *token, stack<long> &s)
{
    switch (token[0])
    {
    case 'p':
        cout << "Top of the stack is: " << s.top() << endl;
        break;
    case 's':
        swapStack(s);
        break;
    case 'd':
        s.push(s.top());
        break;
    }
}

long makeOperation(stack<long> &s, char *token)
{
    long op2 = s.top();
    s.pop();
    long op1 = s.top();
    s.pop();
    return evaluate(op1, op2, token[0]);
}

void evaluatePolish(char *expression)
{
    stack<long> s;
    char *token = strtok(expression, " ");
    while (token)
    {
        if (isOperator(token))
        {
            s.push(makeOperation(s, token));
        }
        else if (isCommand(token))
            evaluateCommand(token, s);
        else
            s.push(atoi(token));
        token = strtok(nullptr, " ");
    }
    printResult(s.top());
}

void readLine()
{
    char str[STRMAX];
    cin.getline(str, STRMAX);
    if (strlen(str) > 1)
        evaluatePolish(str);
}

int main()
{
    for (; !cin.eof();)
        readLine();
    return 0;
}
