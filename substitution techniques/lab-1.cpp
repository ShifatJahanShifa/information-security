#include <bits/stdc++.h>
using namespace std;

void monoalphabeticEncryption(string s)
{
    string alphabetic = "abcdefghijklmnopqrstuvwxyz";
    string key = "pyfgcrlaoeuidhtnsqjkxbmwvz";
    map<char, char> hash;
    for (int i = 0; i < alphabetic.size(); i++)
    {
        hash[alphabetic[i]] = key[i];
    }
    string cipherText = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            cipherText += ' ';
        else
            cipherText += hash[s[i]];
    }
    cout << "cipher text: " << cipherText << "\n";
}

void polyalphabeticEncryption(string s, string key)
{
    string helper = "", mainKey = key;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        helper += s[i];
    }
    if (key.size() < helper.size())
    {
        int size = helper.size() - key.size();
        int add = size / key.size();
        for (int i = 0; i < add; i++)
        {
            mainKey += key;
        }
        size = size % key.size();
        for (int i = 0; i < size; i++)
        {
            mainKey.push_back(key[i]);
        }
    }
    string cipherText = "";
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            cipherText += ' ';
        }
        else
        {
            cipherText += 'a' + (((helper[j] - 'a') + (mainKey[j] - 'a'))) % 26;
            j++;
        }
    }
    cout << "cipher text: " << cipherText << "\n";
}

void monoalphabeticDecryption(string s)
{
    string alphabetic = "abcdefghijklmnopqrstuvwxyz";
    string key = "pyfgcrlaoeuidhtnsqjkxbmwvz";
    map<char, char> hash;
    for (int i = 0; i < key.size(); i++)
    {
        hash[key[i]] = alphabetic[i];
    }
    string plainText = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            plainText += ' ';
        else
            plainText += hash[s[i]];
    }
    cout << "cipher text: " << plainText << "\n";
}

void polyalphabeticDecryption(string s, string key)
{
    string helper = "", mainKey = key;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        helper += s[i];
    }
    if (key.size() < helper.size())
    {
        int size = helper.size() - key.size();
        int add = size / key.size();
        for (int i = 0; i < add; i++)
        {
            mainKey += key;
        }
        size = size % key.size();
        for (int i = 0; i < size; i++)
        {
            mainKey.push_back(key[i]);
        }
    }
    cout << mainKey << "\n";
    string plainText = "";
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            plainText += ' ';
        }
        else
        {
            int value=((helper[j] - 'a') - (mainKey[j] - 'a'));
            if(value<0) 
            plainText += 'a' + (value+ 26);
            else plainText += 'a' + (value);
            j++;
        }
    }
    cout << "plain text: " << plainText << "\n";
}

int main()
{
    cout << "Press 1 to encrypt your message.\n";
    cout << "Press 2 to decrypt your message.\n";
    int pressValue;
    cin >> pressValue;
    if (pressValue == 1)
    {
        cout << "Press 1 for monoalphabetic cipher encryption\n";
        cout << "Press 2 for polyalphabetic cipher encryption\n";
        int option;
        cin >> option;
        getchar();
        cout << "Enter your message: \n";
        string plainText;
        getline(cin, plainText);
        if (option == 1) // monoalp. encrypt
        {
            monoalphabeticEncryption(plainText);
        }
        else if (option == 2) // polyalpha. encrypt
        {
            cout << "Enter your key\n";
            string key;
            cin >> key;
            polyalphabeticEncryption(plainText, key);
        }
        else
            cout << "invalid input\n";
    }
    else if (pressValue == 2)
    {
        cout << "Press 1 for monoalphabetic cipher decryption\n";
        cout << "Press 2 for polyalphabetic cipher decryption\n";
        int option;
        cin >> option;
        getchar();
        cout << "Enter your message: \n";
        string cipherText;
        getline(cin, cipherText);
        if (option == 1) // monoalp. encrypt
        {
            monoalphabeticDecryption(cipherText);
        }
        else if (option == 2) // polyalpha. encrypt
        {
            cout << "Enter your key\n";
            string key;
            cin >> key;
            polyalphabeticDecryption(cipherText, key);
        }
        else
            cout << "invalid input\n";
    }
    else
        cout << "Invalid input\n";
}