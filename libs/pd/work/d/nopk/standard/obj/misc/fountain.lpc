// - syphon -

#include <std.h>
inherit OBJECT;

void create() {
    ::create();

    set_id( ({"fountain"}) );
   set_name("fountain");
   set_short("%^BOLD%^%^BLUE%^A magnificent fountain%^RESET%^");
    set_long("This fountain is filled with a cool water that " 
             "heals you");
    
}

int get() { return 0; }

int init()
{
 ::init();
 add_action("goDrink", "drink");
}
int goDrink(string str)
{
 if (str!="fountain") return 0;
 if (this_player()->query_disable())
   {
    write("You cant drink that fast.");
    return 1;
   }
 this_player()->set_disable();
/* this_player()->add_mp(10);
 this_player()->add_sp(10);
 this_player()->add_hp(10);
*/
  this_player()->heal(10);
 write("%^BOLD%^%^BLUE%^The fountain water refreshes you.");
 return 1;
}
