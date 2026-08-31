#include <std.h>;
#include <rest.h>;

inherit WEAPON;

void create()
{
    ::create();

    set("id",({"nunchucks","nunchaku","weapon","flail"}));
    set_name("nunchaku");
    set("short","Nunchaku");
    set("long","The nunchaku has long been used ");
    set_weight(10);
    set_curr_value("gold", 320);
    set_hit( (: this_object(), "weapon_hit" :) );
    set_wc(11);
    set_type("flail");
}

int query_auto_load()
{
    if (this_player()->query_level() > 35 && this_player()->query_guild() ==
      "AoD")
	return 1;
}



int weapon_hit(object attackee)
{
    if(random(5) == 0)
    {
	write("Your nunchaku tangles your opponent's legs leaving him in a pile on
the ground.");
      say(this_player()->query_cap_name()+" trips his opponent with his
nunchaku.", attackee);
      message("info","Your legs are entangled by your opponent's nunchaku
slamming you to the ground.", attackee);
      attackee->set_rest_type(LAY);
      if(random(5) == 0)
        attackee->set_paralyzed(1);
      return random(10)+11;
  }
    else return 0;
}
