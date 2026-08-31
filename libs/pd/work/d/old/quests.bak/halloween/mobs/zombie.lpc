#include <std.h>
#include <halloween.h>

inherit MONSTER;
int zombie_die();

void create()
{
 ::create();
 set_name("zombie");
 switch(random(5))
 {
  default: set_short("A stumpy zombie");
  case  1: set_short("A tall zombie");
  case  2: set_short("A short zombie");
  case  3: set_short("A big zombie");
  case  4: set_short("A small zombie");
}
 set_long("The zombies have come to take over.");
 set_level(10);
 set_id( ({ "zombie", "undead" }) );
 set_race("zombie");
 set_body_type("human");
 set_gender("male");
 set_moving(1);
 set_speed(10);
 set_die( (: zombie_die() :) );
 set_no_clean(1);
}

int zombie_die(object ob)
{
 
 HALLOWEEN_D->report_zombiedeath(query_last_attacker());
 return 1;
}
