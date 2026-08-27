/* By Shimmer */

#define CREATOR "shimmer"

#include "../../../path.h"

inherit "/std/object";

void setup()
{
   set_name("tarta");
   set_short("%^ORANGE%^Tarta al ron%^RESET%^");
   add_alias("tarta al ron");
   set_long("Es una suculenta tarta al ron. Seguro que te la quieres "
            "'comer'.\n");
   set_main_plural("%^ORANGE%^Tartas al ron%^RESET%^");
   add_plural("tartas");
   add_plural("tartas al ron");
   add_alias("ron");
   add_plural("rons");
   add_plural("rones");
   set_weight(25);
   set_value(4500);
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
   
   write("Te zampas la tarta entera a mordiscos. Estaba *hips* muy buena.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se zampa de forma avariciosa una suculenta tarta.\n",
             ({this_player()}));
   this_player()->adjust_hp(18);
   this_player()->adjust_volume(0, 50); /* 0=alcohol */
   this_object()->dest_me();
   return 1;
}
