/*** Regeneration object ***/
/*** By Wonderflug ***/

#include "tweaks.h"
inherit "/std/object";

object my_player;
int my_count;
int my_amount;

void destruct_regen()
{
   if(my_player)
   {
  tell_object(my_player, "You feel tired and weak as your regeneration "
    "spell wears off.\n");
  tell_room(environment(my_player),my_player->query_cap_name()+
    " slumps somewhat as "+my_player->query_possessive()+" skin "
    "stops glowing.\n", my_player);
  my_player->remove_extra_look(this_object());
   }
  destruct(this_object());
}

int check_duration()
{
  if ( !(my_player->query_timed_property("regen_on")) )
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
  set_heart_beat(1);
}

void setup()
{
  add_static_property("dead",1);
  set_weight(0);
}

void heart_beat()
{
  int currhp, maxhp, ratio;

  if( !my_player || (int)my_player->query_dead() )
    destruct_regen();

  currhp = (int)my_player->query_hp();
  maxhp = (int)my_player->query_max_hp();

  if( my_count++ > REGEN_NUM_HB && currhp < maxhp )
  { 
    switch( (100*currhp)/maxhp )
    {
      case 100:
        break;
      case 1..25 : 
        tell_object(my_player, "The bleeding in your grevious wounds "
          "stops.\n");
        tell_room(environment(my_player), my_player->query_cap_name()+
          "'s grevious wounds magically close themselves up.\n", my_player);
        break;
      case 26..50 :
        tell_object(my_player, "One of your worse wounds closes itself "
          "up and you feel better.\n");
        tell_room(environment(my_player), "One of "+my_player->query_cap_name()+
          "'s wounds seals up and disappears.\n", my_player);
        break;
      case 51..75 :
        tell_object(my_player, "A painful graze fades away, bringing "
          "a feeling of relief.\n");
        tell_room(environment(my_player), "A shallow graze on "+
          my_player->query_cap_name()+"'s skin heals up completely.\n",
          my_player);
        break;
      default :
        tell_object(my_player, "Some of your smalls nicks and bruises "
          "disappear as if they never were.\n");
        tell_room(environment(my_player), my_player->query_cap_name()+
          "'s nicks and bruises disappear like magic.\n", my_player);
    }
    my_player->adjust_hp( my_amount,this_object() );
    my_count = 0;
  }

  if( check_duration() )
    destruct_regen();

  set_heart_beat(1);
}

string extra_look()
{
  return "Has skin glowing with vitality and health.\n";
}

