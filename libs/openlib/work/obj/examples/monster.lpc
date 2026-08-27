/*  -*- LPC -*-  */
// example monster...really just testing for Tim right now :)
#include <mudlib.h>
#include <gender.h>

inherit MONSTER;

void
setup()
{
  object ob;

  init_race("/obj/daemon/race_d"->query_raceinfo("human"));
  init_combat();
  
  set_name("beavis");
  add_ids(({ "kid" }));
  set_short("Beavis");
  set_long("A scrawny, stupid looking high school kid.\n");
  set_gender(GENDER_MALE);
  set_move_around(15);
  set_talk(5, ({"This sucks!",
	     "Hey Butthead!  You suck!",
	     "FIRE...FIRE...FIRE",
	     "Fire's cool.",
	     "Shutup Butthead!!",
	     "I gotta go to the bathroom.",
	   }));
  ob = new("/obj/examples/weapon");
  ob->move(this_object());
  do_wield(ob, 1, 0);

  ob = new("/obj/examples/armour");
  ob->move(this_object());
  do_wear(ob, 1, 0);

  ob = new("/obj/examples/container");
  ob->move(this_object());
}
