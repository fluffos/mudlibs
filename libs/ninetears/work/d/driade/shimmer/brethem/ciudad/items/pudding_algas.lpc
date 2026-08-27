/* By Shimmer */

#define CREATOR "shimmer"

#include "../../../path.h"

inherit "/std/object";

void setup()
{
   set_name("pudding");
   set_short("%^GREEN%^Pudding de algas%^RESET%^");
   add_alias("tarta de algas");
   set_long("Es una suculenta tarta de fresa. Seguro que te la quieres "
            "'comer'.\n");
   set_main_plural("%^GREEN%^Puddings de algas%^RESET%^");
   add_plural("puddings");
   add_plural("puddings de algas");
   add_alias("algas");
   add_plural("algas");
   set_weight(25);
   set_value(3750);

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
   
   write("Te zampas el pudding de dos bocados. Estaba delicioso.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se zampa de dos bocados un delicioso pudding.\n",
             ({this_player()}));
   this_player()->adjust_hp(25);
   this_object()->dest_me();
   return 1;
}
