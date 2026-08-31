#include <daemons.h>
#include <std.h>
#include <guild.h>
inherit OBJECT;
void create()
{
::create();
set_id(({"portal2", "arch", "golden arch", "archway", "golden archway", "ilarchgate"}));
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
    notify_fail("%^BOLD%^%^WHITE%^This portal only leads to The Tower of Light.%^RESET%^\n");
    return 0;
  }
  if(str != "to tower") {
    notify_fail("You can't go there!\n");
    return 0;
  }
  else {
   if(GUILD_D->query_guild(this_player()->query_name()) != "illuminati"){
       say(this_player()->query_cap_name()+" is an idiot.",this_player());
       notify_fail("You step through the arch but nothing happens!\n");
       this_player()->add_hp(-50);
       return 0;}
    else {
    this_player()->move_player(ROOMS"illuminati/new/mainportal", " steps through the arch.");
    write("%^BOLD%^%^WHITE%^Stepping through the arch find yourself in the Tower of Light.%^RESET%^");
    return 1;}
  }

}
