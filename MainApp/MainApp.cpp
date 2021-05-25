#include "Payments.h"
#include <iostream>

int main()
{
    Person szary("Lukasz", "Szarejko", 20);
    Contract biedaKontrakt(zlecenie, 280000);
    std::cout << szary.getName() << std::endl;
    std::cout << biedaKontrakt.value << std::endl;
}

// UWAGA
// Mo¿ecie spróbowaæ to uruchomiæ tak o ale
// prawdopodobnie wam to nie zadzia³a tak od razu
// Musicie wejœæ w MainApp -> Properties -> C/C++ -> General -> Addictional Include Directories
// I tam jak wejdziecie, to musicie ustawiæ œcie¿kê do folderu Treasury
// aby MainApp móg³ siê do niego odwo³ywaæ
// W razie problemów nie wahajcie siê pisaæ
// choæ powinna wystarczyæ wiedza z artyku³u, który jest pod linkiem:
// https://docs.microsoft.com/pl-pl/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-160
// Essa
