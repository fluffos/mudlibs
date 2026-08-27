/* By Shimmer */

#define CREATOR "shimmer"

#include "../../../path.h"

inherit "/std/object";

void setup()
{
   set_name("tarta");
   set_short("%^ORANGE%^Kitche%^RESET%^");
   add_alias("kitche");
   set_long("Es un kitche. Un pastel de fina masa que parece delicioso.\n");
   set_main_plural("%^ORANGE%^Kitches%^RESET%^");
   add_plural("kitches");
   add_alias("pastel");
   add_plural("pasteles");
   set_weight(25);
   set_value(4500);

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
   
   write("Te comes tu Kitche sin pensartelo dos veces. Estaba muy delicioso.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se zampa de forma avariciosa un delicioso kitche.\n",
             ({this_player()}));
   this_player()->adjust_hp(25 + random (10));
   this_object()->dest_me();
   return 1;
}
