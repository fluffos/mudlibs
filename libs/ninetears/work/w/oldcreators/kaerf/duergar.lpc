#include "path.h"
inherit "/std/room";

void setup()
{
        set_short("Reino Duergar:   Salon.");

   set_long("\n   Reino Duergar:   Salon.\n\n"
            "     Estas en un salon que tu ya conoces bien porque "
            "este era tu hogar cuando eras mas joven. Puedes ver "
            "un gran banco que ocupa toda una pared de la sala, "
            "tambien hay algunos taburetes y muebles de ese tipo.  "
            "Solo hay una salida, y conduce a la zona de entrenamiento "
            "duergar,donde deberas prepararte para la lucha en los reinos"
            "\n\n");

        add_property("no_undead",1); set_light(50); 

        add_item("banco", "Es un banco simplemente,viejo y gastado. "
                "Lo reconoces,es aquel que casi rompes siendo "
                "mas joven.\n");

        add_item("taburete", "Esto es un taburete de 3 patas ... "
                "tiene la marca de fabricacion drow en una de sus patas.\n");

   add_clone("/baseobs/armours/cloak",1);
   add_clone("/baseobs/weapons/hacha_ma",1);
   //add_clone("/baseobs/weapons/pico",1);
   add_clone(BOOK,1);
  add_exit("fuera","/d/newbie/duergar/rooms/main01","door"); 
   modify_exit("fuera",({"function","do_leave"}));

}

int do_leave()
{
   if(this_player()->query_property("guest"))
   {
      notify_fail("\nAs a welcome guest to the Final Realms you are "
         "being sent to our special guest area. "
         "Enjoy your visit with us.\n\n");
      this_player()->move(NEW_NEWBIE+"guests/rooms/intersec");
      this_player()->look_me();
      return 0;
   }
   return 1;
}


