#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Перевірка наявності всіх букв зі слова "while"
bool IncludeAll(const char* str)
{
    bool has_w = false, has_h = false, has_i = false, has_l = false, has_e = false;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'w') has_w = true;
        if (str[i] == 'h') has_h = true;
        if (str[i] == 'i') has_i = true;
        if (str[i] == 'l') has_l = true;
        if (str[i] == 'e') has_e = true;
    }
    return has_w && has_h && has_i && has_l && has_e;
}

char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 5)
        return str;

    char* tmp = new char[len + 1];
    char* t = tmp;
    *t = '\0';

    size_t i = 0;
    while (i < len)
    {
        if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' &&
            str[i + 3] == 'l' && str[i + 4] == 'e')
        {
            strcat(t, "**");
            t += 2;
            i += 5;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    strcpy(str, tmp);
    delete[] tmp;
    return str;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (IncludeAll(str))
        cout << "String contains ALL letters from 'while'" << endl;
    else
        cout << "String DOES NOT contain all letters from 'while'" << endl;

    char* dest = Change(str);
    cout << "Modified string: " << dest << endl;

    return 0;
}