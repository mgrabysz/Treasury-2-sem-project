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
// Mo�ecie spr�bowa� to uruchomi� tak o ale
// prawdopodobnie wam to nie zadzia�a tak od razu
// Musicie wej�� w MainApp -> Properties -> C/C++ -> General -> Addictional Include Directories
// I tam jak wejdziecie, to musicie ustawi� �cie�k� do folderu Treasury
// aby MainApp m�g� si� do niego odwo�ywa�
// W razie problem�w nie wahajcie si� pisa�
// cho� powinna wystarczy� wiedza z artyku�u, kt�ry jest pod linkiem:
// https://docs.microsoft.com/pl-pl/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-160
// Essa
