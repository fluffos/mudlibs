/*** Bearhugging object ***/
/*** By Wonderflug ***/

#include "tweaks.h"
inherit "/obj/monster";

object my_player;
object my_target;

void do_death(object ob) { }

void destruct_bearhug()
{
  if (my_target)
	my_target->destruct_bearhug();
  if (my_player)
	my_player->destruct_bearhug();
  destruct(this_object());
}

void init()
{
  ::init();
  add_action("do_release","release");
  set_heart_beat(1);
}

void setup_item(object me,object him)
{
  my_player = me;
  my_target = him;
  init();
}

int query_auto_load() { return 1; }

void setup()
{
  add_property("dead",1);
  set_weight(0);
}

int do_release( string str )
{
  if ( this_player() != my_player )
	return 0;

  tell_object(my_player, "You release "+my_target->query_cap_name()+
	" from the bearhug.\n");
  tell_object(my_target, my_player->query_cap_name()+" mercifully "
	"releases you.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
        " releases "+my_target->query_cap_name()+" from the bearhug.\n",
        ({ my_player, my_target }) );
  my_player->remove_static_property("noguild");
  my_player->remove_static_property("nocast");
  my_target->remove_static_property("noguild");
  my_target->remove_static_property("nocast");
  call_out("destruct_bearhug",0,0);
  return 1;
}

void heart_beat()
{
  if( !my_player || (int)my_player->query_property("dead") 
	|| !my_target || (int)my_target->query_property("dead") )
	destruct_bearhug();

  set_heart_beat(1);
}

