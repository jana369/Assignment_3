#include<iostream>
#include<map>
#include<vector>
#include<fstream>
#include<cctype>
using namespace std;
vector< string > vec;
void store_file(string fileName){
    ifstream file;
    file.open("Bonus.txt",ios::in);
    string word = "", str = "";
    while(file >> word){
        for(int i = 0 ; i < word.size(); i++){
            if(isalnum(word[i]) || word[i] == '-'){
                str += word[i];
            }
        }
        vec.push_back(str);
        str = "";
    }
}
int main(){
    store_file("Bonus.txt");
    map<string, int>repeated_word{{}};
    int num;
    num = vec.size();
    for(int j = 0; j < num; j++){
        if(repeated_word.find(vec[j]) == repeated_word.end() ){
            string str;
            str = vec[j];
            repeated_word.insert({str , 1});
        }else{
            repeated_word[vec[j]]++;
        }
    }

    for(auto it = repeated_word.begin() ; it != repeated_word.end() ; it++){
        cout << "The word of " << it->first << " repeated " << it->second << " times" << endl;
    }
    cout << repeated_word.size();

}
