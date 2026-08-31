#include <std.h>
inherit ARMOUR;
int rubs;
void create() {
    ::create();
set_name("ring");
set_short("%^BOLD%^%^BLUE%^H%^WHITE%^ol%^BLUE%^y F%^WHITE%^ros%^BLUE%^t R%^WHITE%^in%^BLUE%^g%^RESET%^");
set_long("%^BOLD%^%^BLUE%^A frosted metalic blue ring. Etched into the face of the ring is the "
"picture of a dragon.%^RESET%^");
set_id(({"ring", "holy ring", "frost ring", "holy frost ring"}));
set_ac(2);
set_weight(2);
set_curr_value("gold", 186);
set_type("ring");
set_limbs(({"left hand", "right hand"}));
rubs=0;
}
int query_auto_load() {
if(this_player()->query_guild() != "illuminati") return 0;
return 1; }

void init() {
 ::init();
 add_action("my_rub", "rub");
}

int my_rub(string str) {
 if (str!="ring")
   {
    notify_fail("Rub what?");
    return 0;
   }
 if (rubs >= 10)
   {
   write("%^RESET%^%^ORANGE%^The ring seems to be out of magic.%^RESET%^");
    return 1;
   }
    if (this_player()->query_disable()){
      notify_fail("You are busy.\n");
    return 0;
}
 rubs++;
 write("%^BOLD%^%^BLUE%^The dragon glows brightly, as you feel a surge of energy rush through you.%^RESET%^");
 this_player()->add_sp(random(50));
 this_player()->set_disable();
 return 1;
}

