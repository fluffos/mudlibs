/* By Shimmer */

#define CREATOR "shimmer"

#include "../../../path.h"

#include "unarmed_combat.h"

inherit "/std/object";

void setup() {
  set_name("Arbol Milenario");
  add_alias("arbol");
  add_plural("Arboles Milenarios");
  set_short("%^BOLD%^GREEN%^Arbol %^BOLD%^WHITE%^Milenario%^RESET%^");
  set_long("Un enorme arbol custodia la plaza desde el centro de la misma. Sus ramas son fuertes y "
             "anchas y su corteza esta muy arrugada debido a su edad milenaria. Es uno de los simbolos "
             "mas importantes y queridos de la ciudad, ya que lleva ahi desde el nacimiento de la misma, "
             "creciendo a la par que esta. No creo que te gustase saber lo que le hacen a los que lo maltratan.\n");


   set_weight(100000);
   reset_get();
   reset_drop();
}

void init()
{
   ::init();
   add_action("danyo", "kill");
   add_action("danyo", "matar"); 
   add_action("danyo", "golpear");
   add_action("danyo", "romper");
   add_action("danyo", "maltratar");
   add_action("danyo", "danyar");
}

void danyo(string arbol)
{
   if (!arbol || arbol!="arbol")
   {
      this_player()->notify_fail(query_verb()+" que?\n");
      return 0;
   }

      switch (random(4))
      {
         case 0:    
            write("\nGolpeas fuertemente el arbol y una brechita se abre en su corteza dejando salir "
                  "un poco de savia y resina.\n");
            say(this_player()->query_cap_name()+" golpea con fuerza el arbol y abre una brechita en su corteza.\n");
         break;
         case 1: 
            write("\nRozas el arbol levemente y un cacho de corteza se desprende, creo que a los guardias no le "
                  "va a gustar lo que acabas de hacer.\n");
            say(this_player()->query_cap_name()+" roza el arbol levemente y un trozo de corteza se drespende.\n");

         break;
         case 2: 
            write("\nGolpeas una de las ramas bajas del arbol y unas cuantas hojas caen al suelo. "
                  "un poco de savia y resina.\n");
            say(this_player()->query_cap_name()+" golpea una rama y uans cuantas hojas caen al suelo.\n");                 
         break;
         case 3: 
            write("\nRajas el tronco del arbol y abres una brecha por la que emana un poco de savia.\n");
            say(this_player()->query_cap_name()+" raja el tronco del arbo y comienza a salir un poco de savia.\n");                 
         break;
      }


   /* COMO SE TE OCURRA TAN SIQUIERA ROZAR EL ARBOL, TE VAN A DAR PALOS XD */
   
   this_player()->add_timed_property("arbol_milenario", 1, 200); 
   return 1;
}




