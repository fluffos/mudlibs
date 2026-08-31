#include <std.h>
#include "unalom.h"
inherit MONSTER;

void create()
{
  object key;
 ::create();

        set_name("bandicoot");
        set_id(({"black bandicoot", "shadowy bandicoot" }));
        set_short("a %^BOLD%^BLACK%^black%^RED%^ bandicoot");
        set_long("A common rainforest marsupial, this bandicoot "
        "forages through the woods looking for bits of food.  Its "
        "fur seems to have been dyed jet black, almost unnaturally. ");
        set_alignment(-200);
        set_race("bandicoot");
        if(random(10) < 5) {
        set_gender("male");
        } else {
        set_gender("female");
        }
        set_body_type("feline");
        set_level(40+random(8));
        set_swarm(1);
 
}
