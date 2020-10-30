## C++ 引用练习

```C++
//firstref.cpp  -- defining and using a reference
#include <iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    int rats = 101;
    int & rodents = rats;               //rodents is a reference
    cout << "rats = " << rats;
    cout << ",rodents = " << rodents << endl;
    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    //some implementions require type casting the following
    //address to type unsigned
    cout << "rats address = " << &rats;
    cout << ", rodents  address " << &rodents << endl;
    return 0;
}
```
#### 输出：

```
rats = 101,rodents = 101
rats = 102, rodents = 102
rats address = 012FFC38, rodents  address 012FFC38
```
