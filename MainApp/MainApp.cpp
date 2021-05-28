#include "../Treasury/Treasury.h"
#include <iostream>

int main()
{
    Person szary("Lukasz", "Szarejko", 20);
    Contract biedaKontrakt(zlecenie, 280000);
    //std::cout << szary.getName() << std::endl;
    //std::cout << biedaKontrakt.value << std::endl;
    Treasury treasury;
    Person* ptr = new Person("Marcin", "Grabysz", 20);
    treasury.addPerson(ptr);
    treasury.editPerson(1, biedaKontrakt);
    //std::cout << treasury.generateListPayment();
    //std::cout << treasury.showPeople();
    return 0;
}
