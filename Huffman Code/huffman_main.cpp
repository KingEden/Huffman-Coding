// i202392_i200602.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "Huffman.cpp"

int calcute_freq(char A, string B)
{
    int count = 0;

    for (int i = 0; i < B.length(); i++)
    {

        if (A == B[i])
        {
            count++;
        }


    }
    return count;

}
string ReadFile(string A)
{
    string Text;
    ifstream File;
    File.open(A.c_str());
    cout << ">Reading..........\n";
    if (File.is_open())
    {
        cout << ">Text File Loaded\n";
    }
    else
    {
        cout << ">Text File Failed To Read\n";
    }

    getline(File, Text);
    return Text;


}

int main()

{
    string textfile_name;
    Huff H;
    Node* root = NULL;
    cout << ">Enter Text File Name\n>";
    cin >> textfile_name; cout << endl;
    string A = ReadFile(textfile_name);
    cout << ">text : " << A;
    cout << "\nFrequency :\n";
    for (int i = 0; i < 26; i++)
    {
        if (calcute_freq(char(i + 'A'), A) == 0)
        {

        }
        else
        {
            cout << char(i + 'A') << " : " << calcute_freq(char(i + 'A'), A);
            cout << endl;
            int j = calcute_freq(char(i + 'A'), A);
            root = H.insert(j, char(i + 'A'), root);
        }


    }
    for (int i = 0; i < 26; i++)
    {
        if (calcute_freq(char(i + 'a'), A) == 0)
        {

        }
        else
        {
            cout << char(i + 'a') << " : " << calcute_freq(char(i + 'a'), A);
            int j = calcute_freq(char(i + 'a'), A);
            root = H.insert(j, char(i + 'a'), root);
            cout << endl;
        }

    }
    cout << endl;
    cout << endl;
    H.Encode(root, "0");
    H.compress_rate(root);

    return 0;
}