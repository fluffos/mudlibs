#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
int can_wield();
int query_auto_load();

void create() {
  ::create();
  set_name("desert spear");
  set_short("Desert Spear");
  set_long("A long sharp spear used for hunting desert creatures.");
  set_weight(12);
  set_id( ({ "spear", "projectile", "desert spear" }) );
  set_curr_value("gold", 50 + random(15));
  set_wc(9);
  set_type("projectile");
  set_hands(2);
  set_decay_rate(5000);
  set_wield("The spear feels the hunt is near!");
  set_hit( (: weapon_hit :) );
  set_wield((:can_wield:));
}

int can_wield()
{
  if (this_player()->query_class() != "fighter"  || this_player()->query_skill("projectile") < 100)
  {
    write("You barely know how to handle the spear.");

  }
  return 1;
}

int weapon_hit(object atk) 
{
  int result;
  int num;
  if (this_player()->query_class() != "fighter"  || this_player()->query_skill("projectile") < 100)
  {
    /*
	      write("You fumble the spear and drop it!");
	      say((string)this_player()->query_cap_name() + " fumbles their spear and drops it!");
	      this_player()->force_me("drop spear");
    */
    return 0;
  }
  num = random(100);
  if(num > 90)
  {
    write("Your spear stabs into " + atk->query_cap_name() + " and begins to glow!");
    say((string)this_player()->query_cap_name() + " stabs into " + atk->query_cap_name());
    result = 10 +random(30);
    this_player()->add_sp(result);
    return result;
  }
  return 0;   

}       

int query_auto_load()
{
  if (this_player()->query_level() > 22) return 1;
  return 0;
}
