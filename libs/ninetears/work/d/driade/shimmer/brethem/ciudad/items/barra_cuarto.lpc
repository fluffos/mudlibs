/* By Shimmer */

#define CREATOR "shimmer"

#include "../../../path.h"

inherit "/std/object";

void setup()
{
   set_name("pan");
   set_short("Pan de viaje");
   set_long("Es un pan de viaje de dimensiones reducidas, apto para viajes "
   "cortos.\n");
   set_main_plural("Panes de viaje");
   add_plural("panes");
   add_alias("pan de viaje");
   add_plural("panes de viaje");
   set_weight(20);
   set_value(1750);
//   set_gender(1);
}

void init()
{
   ::init();
   add_action("do_comer", "com*er");
}

void do_comer(string str)
{
   if (!str) return 0;
   if (str!=this_object()->query_name()) return 0;
   
   write("Te empiezas a comer la barra de pan. Hubiera estado mejor con "
         "algo dentro y un vinillo.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se come una barra de pan a palo seco.\n",
             ({this_player()}));
   this_player()->adjust_hp(7);
   this_object()->dest_me();
   return 1;
}
