#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    //cout << "Hello Worlds" << "\n";
    ifstream myfile ("problemA_input.txt");
    if ( myfile.is_open() == false )
    {
        cout << "Error open file!!!" << '\n';
    }
    string mydata;
    // while(getline(myfile,mydata))
    // {
    //     cout << mydata << '\n';
    // }

    //assing array in vector
    vector<string> myLines;
    
    int hitNo;
    while(getline(myfile,mydata))
    {
        myLines.push_back(mydata);
    }

    for(int i = 0;i < myLines.size(); i++)
    {
        cout<< myLines[i] << '\n' ;
        string tmp;
        stringstream ss(myLines[i]);
        vector<string> myLines2;
        vector<string> myLines3;
        vector<string>::iterator it;
        bool mybool = true;
        while(getline(ss,tmp,' '))
        {
            myLines2.push_back(tmp);
        }
        //find the HIT
        hitNo = 1;
        while(mybool)
        {
            for(int a = 0;a < myLines2.size();a++)
            {
                if(hitNo == stoi(myLines2[a]))
                {
                    it = find(myLines3.begin(),myLines3.end(),myLines2[a]);
                    if(it != myLines3.end())
                    {
                        mybool = false;
                        break;
                    }
                    else
                    {
                        //cout << "Group " + to_string(i) + " HIT " + myLines2[a] << '\n';
                        cout << "HIT " + myLines2[a] << '\n';
                        hitNo = 1;
                        myLines3.push_back(myLines2[a]);
                    }
                }
                else
                {
                    hitNo = hitNo + 1;
                    if(hitNo == 9)
                    {
                        mybool = false;
                        break;
                    }
                }
            }

        }

    }
    cout << "end" << '\n';
    return 0;
}