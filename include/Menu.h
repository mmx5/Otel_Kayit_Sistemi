#ifndef MENU_H
#define MENU_H
#include "Odaislem.h"
#include "Musteriislem.h"
#include "OdaKayitIslem.h"

class Menu
{
private:
public:
    void Yonet(Odaislem, Musteriislem, OdaKayitIslem);
    void OdaIslemMenu(Odaislem);
    void MusteriIslemMenu(Musteriislem);
    void OdaKayitIslemMenu(OdaKayitIslem);
};

#endif