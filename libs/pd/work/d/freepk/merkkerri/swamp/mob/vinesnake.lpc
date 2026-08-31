#include <swamp.h>
#include <std.h>
inherit MONSTER;
  
void create() {
::create();
set_name("snake");
set_short("vine snake");
set_long("Vine snakes are named so due to their skin which looks just like the surrounding vines.  They are often very difficult to see and usually strike first.");
set_id(({"snake", "vine snake"}));
set("aggressive", 99);
set_level(40);
set_race("snake");
set_body_type("snake");
if(random(10) > 5) set_gender("female"); else set_gender("male");
add_limb("mouth", "", 100, 0, 4);
set_wielding_limbs(({"mouth"}));

} 
