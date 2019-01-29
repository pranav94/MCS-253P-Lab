#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define STRMAX 500

char *printSchema(char *url)
{
    char schema[10] = "\0";
    int i = 0;
    for (char *temp = url; (isalpha(*temp) || *temp == ':') && *temp; temp++)
    {
        if (*temp == ':')
        {
            cout << "scheme: " << schema << endl;
            return temp + 1;
        }
        schema[i++] = *temp;
    }
    return url;
}

char *stripLeadingBackslash(char *url)
{
    for (; *url && *url == '/'; url++);
    return url;
}

char *printPort(char *url)
{
    if (*url != ':')
        return url;
    char port[4] = "\0";
    int i = 0;
    for (url++; *url && *url != '/' && i < 4; url++, i++)
        port[i] = *url;

    if(*port)
        cout << "port: " << port << endl;

    return url;
}

char *printPath(char *url)
{
    char path[200] = "\0";
    int i = 0;
    for (; *url && *url != '#' && *url != '?'; url++, i++)
        path[i] = *url;

    if (*path)
        cout << "path: " << path << endl;
    return url;
}

char *printQueryString(char *url)
{
    if (*url != '?')
        return url;
    char query[100] = "\0";
    int i = 0;
    for (url++; *url; url++, i++)
    {
        if (*url == '#')
            break;
        query[i] = *url;
    }
    if (*query)
        cout << "query_string: " << query << endl;
    return url;
}

char *printFragments(char *url)
{
    if (*url != '#')
        return url;
    char fragment[100] = "\0";
    int i = 0;
    for (url++; *url; url++, i++)
        fragment[i] = *url;
    if (*fragment)
        cout << "fragment: " << fragment << endl;
    return url;
}

char *printDomain(char *url)
{
    char domain[100] = "\0";
    for (int i = 0; *url; url++, i++)
    {
        if (*url == '/')
        {
            cout << "domain: " << domain << endl;
            return url + 1;
        }
        if (!isalpha(*url) && !isdigit(*url) && *url != '.' && *url != '-')
        {
            cout << "domain: " << domain << endl;
            return url;
        }
        domain[i] = *url;
    }
    return url;
}

void parseURL(char *url)
{
    url = printSchema(url);
    url = stripLeadingBackslash(url);
    url = printDomain(url);
    url = printPort(url);
    url = printPath(url);
    url = printQueryString(url);
    url = printFragments(url);
    cout << endl;
}

void readLine()
{
    char url[STRMAX];
    cin.getline(url, STRMAX);
    if (strlen(url) > 1)
        parseURL(url);
}

int main()
{
    for (;;)
        readLine();
    return 0;
}