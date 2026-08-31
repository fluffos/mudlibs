#include <std.h>
inherit ARMOUR;
int rubs;

void create() {
   ::create();
     set_property("magic item", "rub");
     set_name("ring");
     set_short("%^BOLD%^BLUE%^Frosted %^WHITE%^Ring%^RESET%^");
     set_long("%^BOLD%^WHITE%^A frosted metallic blue ring. Etched into the face of the ring is the picture of a dragon.%^RESET%^");
     set_id(({"ring", "frosted ring", "frosted", "frost ring"}));
     set_ac(1);
     set_weight(2);
     set_curr_value("gold", 186);
     set_type("ring");
     set_limbs(({"left hand", "right hand"}));
     rubs=0;
}

int query_auto_load() {
    if(this_player()->query_guild() != "illuminati") return 0;
    return 1;
}

void init() {
   ::init();
}

int my_rub(string str) {
    if(str!="ring") {
      return 0;
      }
 if (rubs >= 10)
   {
   write("The ring seems to be out of magic.");
    return 1;
   }
    if (this_player()->query_disable()){
      notify_fail("You are busy.\n");
    return 0;
}
 rubs++;
 write("%^BOLD%^WHITE%^You feel a surge of energy rush through you.%^RESET%^");
 this_player()->add_sp(random(25));
 this_player()->set_disable();
 return 1;
}
