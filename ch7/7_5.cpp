#include <iostream>
using namespace std;
//online book reader
 class onlineReader{
public:
userManger = new UserManager();
library = new Library();
display = new Display();

private:
  Library library;
  UserManger usermanager;
  Display display;
  Book activeBook;
  User activeUser;

};
int main() {
  std::cout << "Hello World!\n";
}
