#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
fstream dictionary("dictionary.txt" , ios:: out);

bool CheckStr(vector<string> Dict, string str){
    bool res = false;
    for(int i = 0; i<Dict.size(); i++){
        if(Dict[i].compare(str) == 0){
            res = true;
        }
    }
    return res;
}
void SpaceAdder(string str, int n, string& result, vector<string> Dictionary)
{
    for (int i=1; i<=n; i++)
    {
        string prefix = str.substr(0, i);

        if (CheckStr(Dictionary, prefix))
        {

            if (i == n)
            {
                result += prefix;
                return;
            }
            result+= prefix + " ";
            SpaceAdder(str.substr(i, n-i), n-i, result, Dictionary);
        }
    }
}



int main(){
    vector<string>vec;
    while(!dictionary.eof()){
        string name;
        dictionary >> name;
        vec.push_back(name);
    }
    string input = "Iwearmyshoes";
    string res = "";
    SpaceAdder(input, input.size(), res, vec);
    cout << res;
    return 0;
}
