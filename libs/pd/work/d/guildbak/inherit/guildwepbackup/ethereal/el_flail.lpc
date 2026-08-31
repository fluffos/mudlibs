#include <std.h>
#include <rest.h>
#include <ether.h>
inherit ETHERWEP;

void create()
{
  ::create();

  set_id(({"fleshrender","flail"}));
  set_name("a fleshrender");
  set_short("a %^RED%^f%^BOLD%^l%^BLACK%^e%^RESET%^s%^RED%^h%^BOLD%^r%^BLACK%^e%^RESET%^n%^RED%^d%^BOLD%^e%^BLACK%^r%^RESET%^");
  set_long("%^RED%^This is a mighty flail.%^RESET%^");
  set_weight(15);
  set_curr_value("gold", 830);
  set_hit( (: this_object(), "weapon_hit" :) );
  set_wc(13);
  set_type("flail");
}

int query_auto_load()
{
  if (this_player()->query_level() > 50) return 1;
  return 0;
}



int weapon_hit(object attackee)
{
  if(random(5) == 1)
  {
      write("Your flail tangles your opponent's legs leaving him in a "
          "pile on the ground.");
      say(this_player()->query_cap_name()+" trips his opponent with his "
          "flail.", attackee);
      message("info","Your legs are entangled by your opponent's flail "
              "slamming you to the ground.", attackee);
      attackee->set_rest_type(LAY);
      return random(31)+this_player()->query_stats("strength")+this_player()->query_stats("dexterity");
      if(random(4) == 1)
        attackee->set_paralyzed((random(2)+1));
  }
}
