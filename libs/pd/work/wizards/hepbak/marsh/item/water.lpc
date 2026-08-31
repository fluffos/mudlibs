#include <std.h>
#include <marsh.h>
inherit OBJECT;
void create() {
    ::create();
    set_id( ({"water"}) );
   set_name("water");
   set_short("water");
    set_long("It sparkles under the light of the " 
             "torch.");
    
}
int get() { return 0; }
int init()
{
 ::init();
 add_action("goDrink", "drink");
}
int goDrink(string str)
{
 if (str!="water") return 0;
 if (this_player()->query_disable())
   {
    write("You cant drink that fast.");
    return 1;
   }
 this_player()->set_disable();
/* this_player()->add_mp(100);
 this_player()->add_sp(100);
 this_player()->add_hp(100);
*/
  this_player()->heal(100);
 write("The pure stream water refreshes you.");
 return 1;
}
