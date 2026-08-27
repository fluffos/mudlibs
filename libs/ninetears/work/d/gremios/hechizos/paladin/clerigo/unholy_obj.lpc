
#include "tweaks.h"
inherit "/std/object";

object my_player;
int my_count;

int query_spell() { return 1; }


void adjust_hp() { }
void set_hp() { }

void destruct_unholy()
{
  tell_object(my_player, "At last, the incredible pain of the Unholy Word"
		" fades, as the symbol disappears from your skin.\n");
  tell_room(environment(my_player),my_player->query_cap_name()+
   " looks healthier, as an evil looking mark on"
		" "+my_player->query_possessive()+" skin"
		" fades away.\n", my_player);
  my_player->remove_extra_look(this_object());
  my_player->set_heal();
  my_player->remove_property("noregen");
  destruct(this_object());
}

void destruct_curse()
{
   destruct_unholy();
}

int check_duration()
{
   if ( !(my_player->query_timed_property("unholy_on")) )
    return 1;
  else return 0;
}

void init()
{
  ::init();
  set_heart_beat(1);
  my_player = this_player();
}


void setup()
{
	set_name("unholy symbol");
  set_short("");
  set_long("");
  add_static_property("dead",1);
  set_weight(0);
}

void heart_beat()
{
  int currhp, maxhp, ratio;


  if ( !my_player )
    my_player = environment(this_object());

  if ( !living(my_player) || (int)my_player->query_dead() )
    destruct(this_object());

  currhp = (int)my_player->query_hp();
  maxhp = (int)my_player->query_max_hp();


  if( check_duration() )
	destruct_unholy();

  set_heart_beat(1);
}

string extra_look()
{
  return "Shudders as if pained by some inner torment.\n";
}
