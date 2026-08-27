/*** Regeneration object ***/
/*** By Wonderflug ***/

#include "tweaks.h"
inherit "/obj/monster";

object my_player;
int my_count;
int my_amount;

void do_death(object ob) { }

void destruct_wither()
{
  tell_object(my_player, "You feel better as your skin stops decaying.\n");
  tell_room(environment(my_player),my_player->query_cap_name()+
	"'s skin stops decaying.\n",
	my_player);
  my_player->remove_extra_look(this_object());
  destruct(this_object());
}

void destruct_curse()
{
  destruct_wither();
}

int check_duration()
{
  if ( !(my_player->query_timed_property("wither_on")) )
	return 1;
  else return 0;
}

void init()
{
  ::init();
  set_heart_beat(1);
}

void set_spell(object ob,int amount)
{
  my_player = ob;
  my_count = 0;
  my_amount = amount;
  init();
}

void setup()
{
  add_property("dead",1);
  set_weight(0);
}

void heart_beat()
{
  int currhp, maxhp, ratio;

  if( !my_player || (int)my_player->query_property("dead") )
	destruct_wither();

  currhp = (int)my_player->query_hp();
  maxhp = (int)my_player->query_max_hp();

  if( my_count++ > WITHER_NUM_HB && 
	currhp < maxhp )
  { 
    switch( (100*currhp)/maxhp )
    {
      case 1..25 : 
        tell_object(my_player, "One of your grievious wounds breaks open "
	  "and starts bleeding everywhere.\n");
	tell_room(environment(my_player), my_player->query_cap_name()+
	  "'s grevious wounds split open and start bleeding.\n", my_player);
	break;
      case 26..50 :
	tell_object(my_player, "One of your worse wounds splits wide open "
	  "and you feel pain.\n");
	tell_room(environment(my_player), "One of "+my_player->query_cap_name()+
	  "'s wounds splits wider and "+my_player->query_pronoun()+" shudders "
	  "in pain.\n");
	break;
      case 51..75 :
	tell_object(my_player, "A painful graze appears on your skin."
	  "\n");
	tell_room(environment(my_player), "A shallow graze suddenly appears "
	  "on "+my_player->query_cap_name()+"'s skin.\n",
	  my_player);
	break;
      default :
	tell_object(my_player, "Some smalls nicks and bruises "
	  "appear on your skin.\n");
	tell_room(environment(my_player), my_player->query_cap_name()+
	  "'s skin is suddenly riddled with small cuts and bruises.\n",
	  my_player);
    }
    my_player->adjust_hp( -my_amount );
    my_count = 0;
  }

  if( check_duration() )
	destruct_wither();

  set_heart_beat(1);
}

string extra_look()
{
  return "Has skin decaying and rotting away before your eyes.\n";
}

