#include <std.h>
#include <rest.h>
#include <ether.h>
inherit ETHERWEP;

void create()
{
  ::create();

  set_id( ({"gabul","flail"}) );
  set_name("gabul");
  set_short("%^ORANGE%^gabul%^RESET%^");
  set_long("This is an old forked stick. Although it is very old, and not very attractive, it has been enchanted to actually be quite powerful.");
  set_weight(10);
  set_curr_value("gold", 220);
  set_hit( (: this_object(), "weapon_hit" :) );
  set_wc(8);
  set_type("flail");
}

int query_auto_load()
{
  if (this_player()->query_level() > 20) return 1;
  return 0;
}



int weapon_hit(object attackee)
{
  if(random(11) == 1)
  {
      write("Your flail tangles your opponent's legs leaving him in a "
          "pile on the ground.");
      say(this_player()->query_cap_name()+" trips his opponent with his "
          "flail.", attackee);
      message("info","Your legs are entangled by your opponent's flail "
                "slamming you to the ground.", attackee);
      attackee->set_rest_type(LAY);
      if(random(5) == 1)
      attackee->set_paralyzed(1);
      return random(35)+16;
  }
}
