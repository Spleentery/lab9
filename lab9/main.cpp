#include <iostream>
using namespace std;


string::iterator it;

void print(string &a){
    it = a.begin();
    while(it != a.end()){
       cout << *it;
       it++;
     }
    cout << "\n";
}
void stringToUpper(string &str, string &upper){
      it = str.begin();
      while(it !=str.end()) {
          char c = toupper(*it);
          upper.push_back(c);
          it++;
      }
}
int main(){

      string abs;
      abs.reserve(35);
      abs = "Mundus vult decipi, ergo decipiatur";
      abs.shrink_to_fit();
      print(abs);

      string absUpper;
      absUpper.reserve(35);

      stringToUpper(abs,absUpper);
      print(absUpper);



    return 0;
}
