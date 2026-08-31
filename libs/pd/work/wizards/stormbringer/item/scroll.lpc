#include <std.h>

inherit OBJECT;
void recite(string str);

void init()
{
 ::init();
 add_action("cmd_recite", "recite");
}
void create()
{
 set_name("The scroll of Illusionists");
 set_short("The scroll of Illusionists");
 set_id( ({ "scroll", "scroll_of_illusionists" }) );
 set_long("The scroll reads:\n"
   "	Recite this to fufil your dreams.\n"
   "	To make everybody look at you and gleam.\n"
   "	The secret society of Illusionists is here\n"
   "	Everybody run away because we will make you fear.");

 set_mass(10);
 set_value(0);

}

int cmd_recite(string str)
{
 if (!str || str=="") return 0;
 if (str!="scroll") return 0;
 write("You recite the scroll of Illusionists, and feel a strange urge to "
       "bring this to your leader.");
 return 1;
}
