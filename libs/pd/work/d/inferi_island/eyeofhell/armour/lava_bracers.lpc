#include <std.h>
#include <amun.h>
inherit ARMOUR; 
void create() {
         ::create();
         set_name("lava bracers");
         set_id( ({ "bracers" }) );
         set_short("%^RESET%^%^ORANGE%^L%^RED%^a%^ORANGE%^va B%^RED%^r%^ORANGE%^acers%^RESET%^");
         set_long("%^RESET%^%^ORANGE%^The bracer made of lava can ooze across any arm." );
         set_type("bracers");
         set_ac(3);
         set_limbs( ({ "right arm", "left arm" }) );
         set_weight(15);
         set_curr_value("gold", 100);
         set_wear("%^RESET%^%^RED%^The lava oozes over your arm, offering you protection.%^RESET%^");
         set_remove("%^RESET%^%^RED%^The lava drys and forms back into a regular bracer.%^RESET%^");
     }
     int query_auto_load() {
         if (this_player()->query_level() >= 30)
             return 1;
     }
