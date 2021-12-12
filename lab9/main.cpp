#include <iostream>
#include <list>
using namespace std;

class oeuvre{
    int m_num;
    string m_name;
public:
    explicit oeuvre(int num, string name = "default"): m_num(num), m_name(name){
    }
    oeuvre(){
        int num;
        cout << "num: ";
        cin >> num;
        m_num = num;
        string line;
        cout << "name: ";
        cin >> line;
        m_name = line;

    }

    friend ostream& operator<<(ostream &out, const oeuvre &oe){
        out << oe.m_num << ". " << oe.m_name;
        return out;
    }
    void setnum(int n){
        m_num = n;
    }
    void setname(string str){
        m_name = str;
    }
     int getnum(){
        return m_num;
    }
    string getname(){
        return m_name;
    }
};

list<oeuvre>::iterator it;
void printAll(list<oeuvre> &list){
    it = list.begin();
    while(it != list.end()) {
        cout << *it << endl;
        it++;
    }
}
void erase(list<oeuvre> &list,int n){
    it = list.begin();
    auto AA = next(it,n);
    list.erase(AA);
}
list<oeuvre>::iterator a;
list<oeuvre>::iterator b;
void Next(list<oeuvre> &list){

     a++;
      if(a!= list.end()) {
          auto AA = next(a, 0);
          cout << *AA;
      }
      else{
          a = list.begin();
          cout << *a << endl;
      }


}

void Previous(list<oeuvre> &list){

     if(a!=list.begin()) {
         a--;
         auto BB = next(a, 0);
         cout << *BB;
     } else{
         a = list.end();
         a--;

         cout << *a << endl;
     }
}
void addTrack(list<oeuvre> &list){
      int n;
      cout << "number: ";
      cin >> n;
    string str;
    cout << "name: ";
    cin >> str;
    list.push_back(oeuvre(n,str));
}

int main(){
    oeuvre null(0,"Your Playlist");
    oeuvre Beethoven(1, "Beethoven - Sonata Moonlight");
    oeuvre Eminem(2,"Eminem - Rap God");
    oeuvre Placebo(3,"Placebo - Every You Every Me");
    oeuvre asd(4);
    list<oeuvre> l;
    l.push_back(Eminem);
    l.push_back(Placebo);
    l.push_front(Beethoven);
    l.push_back(asd);
    l.push_front(null);


a = l.begin();
int choice;
bool gameOn = true;
while (gameOn != false) {
    cout << "*******************************\n";
    cout << "Boombox 3000\n";
    cout << " 1 - Show the next piece.\n";
    cout << " 2 - Show the previous pice.\n";
    cout << " 3 - Show all music.\n";
    cout << " 4 - Add track.\n";
    cout << " 5 - Delete track.\n";
    cout << " 6 - Exit.\n";
    cout << " Enter your choice and press return: ";

    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Next piece is:\n";
                Next(l);
            break;
        case 2:
            cout << "Previous...\n";
            Previous(l);
            break;
        case 3:
            cout << "Your collection so far...\n";
            printAll(l);
            system("pause");
            break;
        case 4:
            cout << "Your track: \n";
            addTrack(l);
            break;
         case 5:
             cout << "Delete track number?\n";
             int n;
             cin >> n;
             erase(l,n);
             break;
         case 6:
             cout << "End of Program.\n";
             gameOn = false;
             break;
        default:
            cout << "Not a Valid Choice. \n";
            cout << "Choose again.\n";
            cin >> choice;
            break;
    }
}
    return 0;
}
