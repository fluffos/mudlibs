/*** By Wonderflug, shall I admit to it though? ***/

#include "tweaks.h"

object my_player;

void destruct_wraithform_shadow() 
{
  destruct(this_object());
}

void setup_shadow(object ob) 
{
  shadow(ob,1);
  my_player = ob;
}

move( mixed dest, mixed messout, mixed messin )
{
  if ( !(my_player->query_timed_property(WRAITH_PROPERTY)) )
  {
    tell_object(my_player,
      "You solidify to your usual self as your Wraithform spell "
      "wears off.\n");
    tell_room(environment(my_player), my_player->query_cap_name()+
      " returns to "+my_player->query_objective()+" normal self from "
      "being a misty, shadowy wraith.\n",
      my_player);
    my_player->remove_extra_look(this_object());
    my_player->remove_static_property("dead");
    call_out("destruct_wraithform_shadow",0,0);
  }
  return my_player->move(dest, messout, messin );
}
  

int query_wraith_spell()
{
  if ( my_player ) return 1;
  else return 0;
}

int test_add() { return 0; }

void attack() { }

void adjust_hp() 
{
  tell_object(my_player, "You are unaffected, being only a wraith.\n");
}

void set_hp() 
{
  tell_object(my_player, "You are unaffected, being only a wraith.\n");
}
 
void do_death() 
{
/* can't be killed while a wraith */
}
 
int query_alive() { return 0; }
int query_dead() { return 1; }

attack_by(object ob) 
{
  tell_object(ob, my_player->query_cap_name()+" is just so much vapour "
	"floating around.. how can you attack "+my_player->query_objective()+
	"?\n");
  ob->stop_fight(my_player);

  if ( !(my_player->query_timed_property(WRAITH_PROPERTY)) )
  {
    tell_object(my_player,
      "You solidify to your usual self as your Wraithform spell "
      "wears off.\n");
    tell_room(environment(my_player), my_player->query_cap_name()+
      " returns to "+my_player->query_objective()+" normal self from "
      "being a misty, shadowy wraith.\n",
      my_player);
    my_player->remove_extra_look(this_object());
    my_player->remove_static_property("dead");
    call_out("destruct_wraithform_shadow",0,0);
  }

  return 1;
}

attack_ob(object ob) 
{
  write("Your hand passes right through it! You are just mist!\n");
  return 0;
}

int cast() 
{
  write("You may not cast spells when you have no substance.\n");
  return 1;
}

int do_shout() 
{
  write("You try to shout but vapour usually isn't too loud.\n");
  return 1;
}

string extra_look()
{
  return "Is just a pale, shadowy wraith.\n";
}

void dispell_me()
{
  
  tell_object(my_player,
    "You solidify to your usual self as your Wraithform spell "
    "is destroyed.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
    " returns to "+my_player->query_objective()+" normal self from "
    "being a misty, shadowy wraith.\n",
    my_player);
  my_player->remove_extra_look(this_object());
  my_player->remove_static_property("dead");
  destruct(this_object());
}

