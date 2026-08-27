/* By Shimmer */

#define CREATOR "shimmer"

#include "../../../path.h"

inherit "/std/object";

void setup()
{
   set_name("gran pan");
   add_alias("pan");
   set_short("Gran Pan de viaje");
   set_long("Es un gran pan de viaje utilizado, como su nombre indica, "
   "por lo viajeros. Esto es debido a su larga durabilidad y resistencia "
   "al frio y humedad.\n");
   set_main_plural("Grandes Panes de viaje");
   add_plural("panes");
   add_plural("grandes panes");
   set_weight(40);
//   set_gender(1);
   set_value(3500);
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
   
   write("Te empiezas a comer el Gran Pan. Hubiera estado mejor con "
         "algo dentro y un vinillo.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se come una barra de pan a palo seco.\n",
             ({this_player()}));
   this_player()->adjust_hp(14);
   this_object()->dest_me();
   return 1;
}
