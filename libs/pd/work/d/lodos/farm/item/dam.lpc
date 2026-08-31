#include <std.h>
#include <farm.h>
inherit OBJECT;


void create() {
 ::create();
set_id(({"dam", "water hole"}));
set_name("dam");
set_long("A small dam for the farm animals to drink out of, it is murky brown in colour, and does not look very healthy.");
set_short("%^BOLD%^BLUE%^a small dam%^RESET%^");
set_prevent_get("You cannot pick up water");
}
int init()
{
 ::init();
 add_action("goDrink", "drink");
}
int goDrink(string str)
{
 if (str!="dam" && str!="water") return 0;
 if (this_player()->query_disable())
   {
    write("Why drink it again?.");
    return 1;
   }
 this_player()->set_disable();
 write("You spit the water out in disgust.");
 return 1;

}
int get() { return 0; }
