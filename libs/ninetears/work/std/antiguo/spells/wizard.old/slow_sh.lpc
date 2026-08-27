/*** Slow shadow ***/
/*** By Wonderflug ***/

#include "tweaks.h"

int counter;
int noweaps;
object my_player;

void destruct_slow_shadow() 
{
  destruct(this_object());
}

void setup_shadow(object ob) 
{
  shadow(ob,1);
  my_player = ob;
  counter = 0;
}

int check_duration()
{
  if ( !(my_player->query_timed_property("slow_on")) )
  {
        tell_object(my_player,
          "Time seems to resume its normal speed as the spell wears "
          "off.\n");
        tell_room(environment(my_player), my_player->query_cap_name()+
          " doesn't seem to be moving so slow anymore.\n",
          my_player);
	return 1;
  }
  else return 0;
}

move( mixed dest, mixed messout, mixed messin )
{
  if ( check_duration() )
	call_out("destruct_slow_shadow",0,0);
  return my_player->move(dest, messout, messin );
}

varargs mixed move_player(string dir, string dest, mixed message, object
				followee, mixed enter)
{
  if ( check_duration() )
        call_out("destruct_slow_shadow",0,0);
  return my_player->move_player(dir, dest, message, followee, enter);
}
  
int query_time_spell() { return 1; }
int query_slow_spell() { return 1; }

/* This is rather obfuscated.  Ask me to explain how it works and I will tho
 * :) -- wonderflug.
 */

int weapon_attack(object him, object me)
{
  int ret;
  if ( noweaps )
  {
    if ( counter++ == 1 )
    {
	counter == 0;
	ret = my_player->unarmed_attack(him, me);
    }
    else ret = 0;
    if ( check_duration() )
        call_out("destruct_slow_shadow",0,0);
    return ret;
  }
  else return 0;
}

object* query_weapons_wielded()
{
  object* ret;

  ret = (object*)my_player->query_weapons_wielded();
  /* Case:  No weapons.  Set noweaps = 1 and return. */
  if ( sizeof(ret) == 0 || (ret[0]==0 && ret[1]==0) )
  {
	if ( counter++ >= 1 )
	{
	  counter = 0;
	  ret = ({ });
	}
	else ret = ({ this_object() });
    	if ( check_duration() )
          call_out("destruct_slow_shadow",0,0);
	return ret;
  }
  /* Case: Two weapons.  Return one weapon.  No need to set 
   * noweaps cause unarmed_attack won't get called this round
   * But I do it anyway. :)
   */
  noweaps = 0;
  if ( sizeof(ret)==2 && ret[0] && ret[1] )
  {
    	if ( check_duration() )
           	call_out("destruct_slow_shadow",0,0);
	return ({ ret[random(1)] });
  }
  /* Case: One weapon.  Check the counter and return the one weapon
   * or zero.  In either case noweaps is 0.
   */
  if ( counter++ >= 1 )
  {
  	counter = 0;
  	if ( check_duration() )
		call_out("destruct_slow_shadow",0,0);
  	return ret;
  }
  return ({ this_object() });
}


/* for an eventual dispel magic spell */
void dispell_me()
{
  
  tell_object(my_player,
	"You can move quickly again as time resumes its normal flow "
	"for you.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
	" moves normally again as the magic is destroyed.\n",
	my_player);
  destruct(this_object());
}

void dispell_time_spell()
{
  my_player->remove_timed_property("slow_on");
  dispell_me();
}
