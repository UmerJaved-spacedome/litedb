#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, string> person = {{"Umer" , "Dev"}, {"Ali" , "Dev"}, {"Ahsan", "Dev"}};

        person["Jack"] = "HR";
        person.insert({"John","IT"});

        for (auto bnda:person)
        {
            cout<<bnda.first<<" has the role of "<<bnda.second<<endl;
        }
        

}