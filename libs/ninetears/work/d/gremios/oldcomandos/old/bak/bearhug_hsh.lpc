/*** Bearhug 'hugger' shadow ***/
/*** By Wonderflug ***/

#include "tweaks.h"
#define BEARHUG_GP_ROUND 2

object my_player, my_target;
object my_item;

void destruct_bearhug_shadow() 
{
  if (my_target) my_target->destruct_bearhug();
  my_item->dest_me();
  destruct(this_object());
}

void dispell_bearhug()
{
  destruct_bearhug_shadow();
}

void destruct_bearhug()
{
  my_player->remove_static_property("noguild");
  my_player->remove_static_property("nocast");
  destruct(this_object());
}

void setup_shadow(object me, object him, object it) 
{
  shadow(me,1);
  my_player = me;
  my_target = him;
  my_item = it;
}

int check_duration()
{
  if ( (int)my_player->query_gp() <= 0 
	|| !my_player || !my_target )
  {
    if ( my_player && my_target )
    {
        tell_object(my_player,
	  "Your arms tire and you release "+my_target->query_cap_name()+".\n");
	if (my_player && my_target )
        tell_room(environment(my_player), my_player->query_cap_name()+
          " strains and drops "+my_target->query_cap_name()+" out of the "
	  "bearhug.\n",
          ({ my_target, my_player}) );
	tell_object(my_target,
	  "You struggle out of "+my_player->query_cap_name()+"'s arms at "
	  "long last.\n");
    }
    if ( my_player )
    {
	my_player->remove_static_property("noguild");
	my_player->remove_static_property("nocast");
    }
    if ( my_target )
    {
	my_target->remove_static_property("noguild");
        my_target->remove_static_property("nocast");
    }
    return 1;
  }
  return 0;
}

varargs mixed move_player(string dir, string dest, mixed message, object
				followee, mixed enter)
{

  tell_object(my_player, "You cannot move while you are bearhugging "
	"someone!\n");
  if ( check_duration() )
	call_out("destruct_bearhug_shadow",0,0);
  return 0;
}
  
int query_hold_spell() { return 1; }

/* Given the next two, we shouldn't need this, but anyway */
int unarmed_attack(object him, object me)
{
  tell_object(me, "You are bearhugging and cannot attack!\n");
  if ( check_duration() )
        call_out("destruct_bearhug_shadow",0,0);
  return 0;
}

object* query_weapons_wielded()
{
  return ({ this_object() });
}

int weapon_attack( object him, object me )
{
  tell_object(my_player, "You squeeze "+my_target->query_cap_name()+
	" and "+my_target->query_pronoun()+" winces in pain.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+" tightens "+
	me->query_possessive()+" grip on "+my_target->query_cap_name()+".\n",
	({ my_player, my_target }) );
  tell_object(my_target, my_player->query_cap_name()+" tightens "+
	my_player->query_possessive()+" grip on you and you hurt.\n");
  my_target->adjust_hp(-random((int)my_player->query_damage_bonus()), 
			my_player);
  my_player->adjust_gp(-BEARHUG_GP_ROUND);
  if ( check_duration() )
        call_out("destruct_bearhug_shadow",0,0);
  return 0;
}

attack_ob(object ob) 
{
  tell_object(my_player, "You cannot attack anything while you bearhug "
	"someone.\n");
  if ( check_duration() )
        call_out("destruct_bearhug_shadow",0,0);
  return 0;
}

