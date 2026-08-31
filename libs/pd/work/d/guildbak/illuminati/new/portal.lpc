#include <std.h>
#include <guild.h>
inherit OBJECT;
void create()
{
::create();
set_id(({"arch", "golden arch", "archway", "golden archway", "ilarchgate"}));
set_name("Illuminati archway");
set_long("%^BOLD%^%^WHITE%^The %^YELLOW%^Illuminati%^WHITE%^ archway. It links all the halls of the %^YELLOW%^Illuminati%^WHITE%^ together.\n\nYou may <travel to [hall]>");
set_short("%^BOLD%^%^YELLOW%^Golden %^WHITE%^archway%^RESET%^");
set_weight(1000000000000);
set_prevent_get("%^BOLD%^%^WHITE%^The arch is ethereal and cannot be touched, only passed through.");
}

void init() {
  ::init();
  add_action("enter_portal","travel");
}

int enter_portal(string str) {
  if(!str) {
    notify_fail("This portal only leads to Helgrath.\n");
    return 0;
  }
  if(str != "to helgrath") {
    notify_fail("You can't go there!\n");
    return 0;
  }
  else {
    if(this_player()->query_guild() != "illuminati"){
       say(this_player()->query_cap_name()+" is an idiot.",this_player());
       notify_fail("You step through the arch but nothing happens!\n");
       this_player()->add_hp(-50);
       return 0;}
    else {
    this_player()->move_player(ROOMS"illuminati/new/helhall", " steps through the arch.");
    return 1;}
  }

}
