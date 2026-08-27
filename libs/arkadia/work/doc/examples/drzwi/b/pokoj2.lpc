inherit "/std/room";

#include <stdproperties.h>
#include "definicje.h"

void
create_room()
{
    set_short("Przykladowy pokoj 2.\n");
    set_long("Stoisz w drugiej lokacji, ktora istnieje tylko po to, bys mogl "+
       "podziwiac przykladowe drzwi. Rzeczone sa jedynym sposobem "+
       "na wyjscie z tej lokacji.\n");

/* Klonujemy obiekt drzrwi */       
   clone_object(SCIEZKA + "drzwi2")->move(this_object());
       
   add_prop(ROOM_I_INSIDE, 1);
}