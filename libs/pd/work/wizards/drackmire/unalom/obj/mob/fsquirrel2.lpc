#include <std.h>
#include "unalom.h"
inherit MONSTER;
int help();

void create()
{
  object key;
 ::create();

        set_name("squirrel");
        set_id(({"fearsome squirrel", "rodent" }));
        set_short("a fearsome squirrel");
        set_long("One of the mythical black squirrels of Unalom. These "
        "squirrels are known for their jet black fur and glowing red "
        "eyes and this squirrel is no exception.  Its fangs glisten "
        "with blood, probably from a fresh kill in the forest.");
        set_alignment(-200);
        set_race("squirrel");
        if(random(10) < 5) {
        set_gender("male");
        } else {
        set_gender("female");
        }
        set_body_type("feline");
        set_level(28);
        set_swarm(1);
        set_die((: help :));
 
}

int help(){
  object ob;
  message("sq","More squirrels come to the aid of their brethren!",environment(this_object()));
  new(UNAMON"hsquirrel")->move(environment(this_object()));
    new(UNAMON"hsquirrel")->move(environment(this_object()));
  
  return 1;
  }
