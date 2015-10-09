// Задание повышенной сложности.

// Определен следующий класс (он также приведен в комментарии в шаблоне кода):

// struct Cls {
//     Cls(char c, double d, int i);
// private:
//     char c;
//     double d;
//     int i;
// };
// Как видно, все поля этого класса закрытые, ваша задача реализовать несколько функций, которые дают полный доступ к этим полям (см. шаблон кода), не смотря на то, что они закрытые.

// Внимание: предполагаемое решение этого задания существенно опирается на Undefined Behaviour и является исключительно учебным, но полезно для лучшего понимания того, как работают модификаторы доступа. Решение было проверено на различных компиляторах (g++/clang++/icc/msvc), но мы настоятельно не рекомендуем использовать подобные трюки в боевом коде.

// Требования к реализации: при решении этого задания вам разрешается заводить любые вспомогательные функции и классы, но не изменять определение класса Cls. Не нужно вводить или выводить что-либо, также не нужно определять функцию main.

#include <iostream>
using namespace std;

struct Cls {
    Cls(char c, double d, int i):c(c),d(d),i(i){}
private:
    char c;
    double d;
    int i;
};

/*
 * Класс Cls определен точно таким образом:
 *
 * struct Cls {
 * Cls(char c, double d, int i);
 * private:
 *     char c;
 *     double d;
 *     int i;
 * };
 *
 */

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    struct Cls2 {
    public:
        char c;
        double d;
        int i;
    };

    void *p=&cls;
    Cls2 *p1=new (p) Cls2;
    return p1->c;
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
    struct Cls2 {
    public:
        char c;
        double d;
        int i;
    };

    void *p=&cls;
    Cls2 *p1=new (p) Cls2;
    return p1->d;
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
    struct Cls2 {
    public:
        char c;
        double d;
        int i;
    };

    void *p=&cls;
    Cls2 *p1=new (p) Cls2;
    return p1->i;
}

int main() {
    Cls c('a', 2.3, 3);

    cout<<get_c(c)<<' '<<get_d(c)<<' '<<get_i(c)<<endl;

    return 0;
}


// Compilation error
// main.cpp: In function ‘char& get_c(Cls&)’:
// main.cpp:24:22: error: no matching function for call to ‘operator new(sizetype, void*&)’
// main.cpp:24:22: note: candidate is:
// :0:0: note: void* operator new(long unsigned int)
// :0:0: note:   candidate expects 1 argument, 2 provided
// main.cpp: In function ‘double& get_d(Cls&)’:
// main.cpp:40:22: error: no matching function for call to ‘operator new(sizetype, void*&)’
// main.cpp:40:22: note: candidate is:
// :0:0: note: void* operator new(long unsigned int)
// :0:0: note:   candidate expects 1 argument, 2 provided
// main.cpp: In function ‘int& get_i(Cls&)’:
// main.cpp:56:22: error: no matching function for call to ‘operator new(sizetype, void*&)’
// main.cpp:56:22: note: candidate is:
// :0:0: note: void* operator new(long unsigned int)
// :0:0: note:   candidate expects 1 argument, 2 provided
