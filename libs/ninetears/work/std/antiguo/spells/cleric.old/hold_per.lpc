#include "tweaks.h"

object my_player;

void destruct_hold_person_shadow() 
{
  destruct(this_object());
}

void setup_shadow(object ob) 
{
  shadow(ob,1);
  my_player = ob;
}

int check_duration()
{
    if ( my_player->query_property("dead") )
    {
      my_player->remove_extra_look(this_object());
      return 1;
    }
  if ( !(my_player->query_timed_property("hold_person_on")) )
  {
        tell_object(my_player,
          "The invisible bonds surrounding you disappear and you can "
          "move again.\n");
        tell_room(environment(my_player), my_player->query_cap_name()+
          " breaks out of the hold spell.\n",
          my_player);
        my_player->remove_extra_look(this_object());
	return 1;
  }
  else return 0;
}

move( mixed dest, mixed messout, mixed messin )
{
  if ( check_duration() )
	call_out("destruct_hold_person_shadow",0,0);
  return my_player->move(dest, messout, messin );
}

varargs mixed move_player(string dir, string dest, mixed message, object
				followee, mixed enter)
{
  if ( random((int)my_player->query_str()) < 20 )
  {
  	tell_object(my_player, "You cannot escape the bonds holding you.\n");
  	if ( check_duration() )
          call_out("destruct_hold_person_shadow",0,0);
	return 0;
  }
  tell_room(environment(my_player),my_player->query_cap_name()+" struggles "
	"against the invisible bonds holding "+my_player->query_objective()+
	" and manages \nto stagger away!\n", my_player);
  tell_object(my_player, "You manage to stagger away, straining against your "
	"bonds.\n");
  if ( check_duration() )
        call_out("destruct_hold_person_shadow",0,0);

  return my_player->move_player(dir, dest, message, followee, enter);
}
  
int query_hold_spell() { return 1; }

/* Given the next two, we shouldn't need this, but anyway */
int unarmed_attack(object him, object me)
{
  tell_object(me, "You are held and cannot attack!\n");
  if ( check_duration() )
        call_out("destruct_hold_person_shadow",0,0);
  return 0;
}

object* query_weapons_wielded()
{
  if ( check_duration() )
        call_out("destruct_hold_person_shadow",0,0);
  return ({ this_object() });
}

int weapon_attack( object him, object me )
{
  tell_object(me, "You are held and cannot attack!\n");
  tell_room(environment(me), me->query_cap_name()+" struggles against "
	"invisible bonds.\n", me);
  if ( check_duration() )
        call_out("destruct_hold_person_shadow",0,0);
  return 0;
}

attack_ob(object ob) 
{
  tell_object(my_player, "You are held in invisible bonds, and cannot "
	"attack anything.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
	" struggles against invisible bonds.\n", my_player);
  if ( check_duration() )
  	call_out("destruct_hold_person_shadow",0,0);
  return 0;
}

int cast() 
{
  tell_object(my_player, "You cannot cast spells while you are held.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
        " struggles against invisible bonds.\n", my_player);
  if (check_duration())
	call_out("destruct_hold_person_shadow",0,0);
  return 1;
}

/* for the player's desc. */
string extra_look()
{
  return "Is struggling against invisible bonds.\n";
}

/* for an eventual dispel magic spell */
void dispell_me()
{
  
  tell_object(my_player,
	"You can move again as the bonds holding you are destroyed.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
	" collapses in a heap as the bonds holding "+
	my_player->query_objective()+" are destroyed.\n",
	my_player);
  my_player->remove_timed_property("noguild");
  my_player->remove_timed_property("nocast");
  my_player->remove_extra_look(this_object());
  destruct(this_object());
}
