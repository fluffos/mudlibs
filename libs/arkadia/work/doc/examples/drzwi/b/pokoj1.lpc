inherit "/std/room";

#include <stdproperties.h>
#include "definicje.h"

void
create_room()
{
    set_short("Przykladowy pokoj.\n");
    set_long("Stoisz w lokacji, ktora istnieje tylko po to, bys mogl "+
       "podziwiac przykladowe drzwi. Rzeczone sa jedynym sposobem "+
       "na wyjscie z tej lokacji.\n");

/* Klonujemy obiekt drzwi */       
   clone_object(SCIEZKA + "drzwi1")->move(this_object());
   
   add_prop(ROOM_I_INSIDE, 1);
}