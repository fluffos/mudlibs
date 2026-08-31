#include <std.h>
inherit OBJECT;
int rubs;
void create() {
    ::create();
set_name("gem");
set_short("%^BOLD%^BLUE%^blue%^RESET%^ gem");
set_long("Nothing seems special about this gem");
set_id(({"gem", "blue gem"}));
set_weight(1);
set_curr_value("gold",1);
rubs=0;
}
int query_auto_load() {
if(this_player()->query_class() != "fighter") return 0;
return 1; }
void init()
{
 ::init();
 add_action("my_rub", "rub");
}
int my_rub(string str)
{
 if (str!="gem")
   {
    notify_fail("Rub what?");
    return 0;
   }
 if (rubs >= 10)
   {
   write("The gem seems to be out of magic.");
    return 1;
   }
    if (this_player()->query_disable()){
      notify_fail("You are busy.\n");
    return 0;
}
 rubs++;
 write("You feel a rush of energy flow through you.");
this_player()->add_sp(random(100));
this_player()->set_disable();
 return 1;
}
