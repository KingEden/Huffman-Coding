// i202392
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include"Node.cpp"
using namespace std;
class Huff
{
public:
    Node* root;
    Node* top;
    Node* newNode(int Fre,char data)
    {
        Node* node = new Node;
        node->data=data;
        node->left = NULL;
        node->right = NULL;
        node->freq = Fre;
        return node;

    }
    string str;
    Node* insert(int Fre,char data ,Node* node)
    {
        priority_queue<Node*>Q;
       
        if (node == NULL)
        {
            Q.push(node);
            return	(newNode(Fre,data));//NEW NODE
        }
        if (Fre < node->freq)
        {
            Q.push(node);
            node->left = insert(Fre,data ,node->left);//Right insertion
        }
        else if (Fre > node->freq)
        {
            Q.push(node);
            node->right = insert(Fre,data ,node->right);//Left insertion
        }
        else
        {
            return node;
        }
       
            return node;
      
        
    }
    void Encode(Node* node,string encode)
    {
 
        if (node == NULL)
            return;
        if (node->data)
            cout << node->freq << " " << node->data << " " << encode << endl;
        Encode(node->left,encode+"0");
        Encode(node->right,encode+"1");
    }
    void compress_rate(Node* node)
    {
        float Fre = 0;
        string Text;
        fstream File;
        float C_C;
        File.open("Huffmancode.txt");
        cout << ">Calculating Compression Rate..........\n";

        getline(File, Text);
        for (int i = 0; i < 26; i++)
        {
            if (calcute_freq(char(i + 'A'), Text) == 0)
            {

            }
            else
            {
                Fre += calcute_freq(char(i + 'A'), Text);
            }


        }
        for (int i = 0; i < 26; i++)
        {
            if (calcute_freq(char(i + 'a'), Text) == 0)
            {

            }
            else
            {
                Fre += calcute_freq(char(i + 'a'), Text);

            }

        }
        Fre = Fre * 8; // Frequncey of each character added
        //cout << Fre;
        //Optimal
        float ABR = 0;
        float T_ABR = 0;
        float L = 0;
        string str = "";
        if (node == NULL)
            return;
        priority_queue<Node*>Q;
        Q.push(node);
        Node* curr = NULL;

        while (!Q.empty())
        {
            curr = Q.top();
            Q.pop();
            L = str.length();
            ABR = curr->freq * L;
            T_ABR += ABR;

            if (curr->left)
            {
                str += "0";
                Q.push(curr->left);
            }
            if (curr->right)
            {
                str += "1";
                Q.push(curr->right);
            }
            //cout << T_ABR << endl;

        }
        C_C = Fre / T_ABR;
        cout << ">Compression Rate = " << C_C << " ";


    }
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
    void optimal_code(Node* node) 
    {
        priority_queue<Node*>Q;
        Q.push(node);
        Node* curr = NULL;

        while (!Q.empty())
        {
            curr = Q.top();
            Q.pop();

            if (curr->left)
            {
                str += "0";
                Q.push(curr->left);
            }
            if (curr->right)
            {
                str += "1";
                Q.push(curr->right);
            }
        }

    }
};