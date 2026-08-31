#include <std.h>
#include <rest.h>

inherit WEAPON;

int weapon_hit(object atk);
int can_wield();
int query_auto_load();

void create() {
  ::create();
  set_name("mystic mace");
  set_short("Mystic Mace");
  set_long("The mystic mace is made of pure magic, it glitters with many different colors. It looks like it jumps in and out of existence every few seconds.");
  set_weight(25);
  set_id( ({ "mace", "mystic mace" }) );
  set_curr_value("gold", (50 + random(50)));
  set_wc(10);
  set_type("blunt");
  set_hands(1);
  set_decay_rate(1000);
  set_wield("The handle of the mace makes your hand tingle");
  set_hit( (: weapon_hit :) );
  set_wield((:can_wield:));
}

int can_wield()
{
  if (this_player()->query_class() != "fighter"  || this_player()->query_skill("blunt") < 110)
  {
    write("You barely know which end to grab");

  }
  return 1;
}

int weapon_hit(object atk) 
{
  int result;
  int num;
  int attack;
  if (this_player()->query_class() != "fighter"  || this_player()->query_skill("blunt") < 110)
  {
    /*
    write("You fumble the mace and drop it!");
    say((string)this_player()->query_cap_name() + " fumbles their mace and drops it!");
    this_player()->force_me("drop mace");
    */
    return 0;
  }
  num = random(100);
  if (num < 8)
  {
    write("Your mace explodes with color, your opponent seems to be stunned from the display!");
    say((string)this_player()->query_cap_name()+"'s mace explodes in color after hitting "+atk->query_cap_name());

    atk->set_rest_type(SIT);

    atk->set_paralyzed(1 + random(5));

    attack = (int)(atk->query_stats("constitution") * (2/3));	
    attack = (10 + this_player()->query_skill("blunt") - attack);
    if (attack < 30)
    {
      attack = 30;
    }
    return attack;
  }

  return 0;   

}	

int query_auto_load(){
  if (this_player()->query_level() > 40) return 1;
  return 0;
}
