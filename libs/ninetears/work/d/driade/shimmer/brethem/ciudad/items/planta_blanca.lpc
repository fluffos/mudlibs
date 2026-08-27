/* By Shimmer */

#define CREATOR "shimmer"

#include "../../../path.h"

inherit "/std/object";

void setup()
{
   set_name("planta blanca");
   set_short("Planta %^BOLD%^Blanca%^RESET%^");
   add_alias("planta blanca");
   set_long("Una pequenya planta de fino tallo con varias hojas grandes y blancas. No tienes ni idea de para que carajo puede valerte.\n");
   set_main_plural("Plantas %^BOLD%^Blancas%^RESET%^");
   add_plural("plantas");
   add_plural("plantas blancas");
   add_alias("planta");
   add_plural("blancas");
   set_weight(5);
   set_value(30000);

}



void init()
{
   ::init();
   add_action("do_pakevale", "lalala");
}

void do_pakevale(string str)
{
   if (!str) return 0;
   if (str!=this_object()->query_name()) return 0;
   
   write("Te zampas la tarta entera a mordiscos. Estaba muy buena.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se zampa de forma avariciosa una suculenta tarta.\n",
             ({this_player()}));
//   this_player()->adjust_hp(15);
   this_object()->dest_me();
   return 1;
}
