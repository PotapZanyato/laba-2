#include <iostream>
#include <string> 
#include <fstream> 
#include <iomanip>

using namespace std; 

string Getgeneration(string s, string s1, string s2);
string GetName(string s, string s2, string s3);
string GetSurname(string s, string s3,string s4);
string GetState(string s, string s4, string s5);
string GetBirth(string s, string s5);

int main() 
{
    setlocale(LC_ALL, "ru");
    string s[8]; 
    ifstream file("treeee.xml"); 
    int k = 0;
    while (getline(file, s[k])) { 
        k++;
    }
    

    file.close(); 
    string s1, s2, s3, s4,s5;
    s1 = "<generation>";
    s2 = "<Name>";
    s3 = "<Surname>";
    s4 = "<State>";
    s5 = "<Birth>";
    
    string generation[8];
    string name[8];
    string surname[8];
    string state[8];
    string birth[8];
    for (int n = 0; n < 7; n++)
    {

    generation[n] = Getgeneration(s[n], s1,s2);
    name[n] = GetName(s[n], s2, s3);
    surname[n] = GetSurname(s[n], s3,s4);
    state[n] = GetState(s[n], s4, s5);
    birth[n] = GetBirth(s[n], s5);
    }
    
    for (int  y = 0; y < 7; y++)
    {
    cout << generation[y]<<"\t" << name[y] << "\t" << surname[y] << "\t" << state[y] << "\t" << birth[y]<<"\n";
    }
   
  
}

string Getgeneration(string s, string s1, string s2)
{
    string generation;
    for (int i = s.find(s1) + 12; i < s.find(s2); i++)
    {
        generation += s[i];
    }
    return generation;
}

string GetName(string s, string s2, string s3)
{
    string Name;
    for (int i = s.find(s2) + 6; i < s.find(s3); i++)
    {
        Name += s[i];
    }
    return Name;
}

string GetSurname(string s, string s3,string s4)
{
    string Surname;
    for (int i = s.find(s3) + 9; i < s.find(s4); i++)
    {
        Surname += s[i];
    }
    return Surname;
}

string GetState(string s, string s4, string s5)
{
    string State;
    for (int i = s.find(s4) + 7; i < s.find(s5); i++)
    {
        State += s[i];
    }
    return State;
}

string GetBirth(string s, string s5)
{
    string birth;
    for (int i = s.find(s5) + 7; i < s.size(); i++)
    {
        birth += s[i];
    }
    return birth;
}
