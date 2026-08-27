/*** Silence Shadow ***/
/*** by Wonderflug ***/

#include "tweaks.h"

object my_player;

void destruct_silence_shadow() 
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
  if ( !(my_player->query_timed_property("silence_on")) )
  {
        tell_object(my_player,
	  "The tightness around your neck disappears, and you can "
	  "speak again.\n");
        tell_room(environment(my_player), my_player->query_cap_name()+
	  " coughs loudly in surprise as the Silence spell wears off.\n",
	  my_player);
        my_player->remove_extra_look(this_object());
	return 1;
  }
  else return 0;
}

move( mixed dest, mixed messout, mixed messin )
{
/* this only works if they try to get something, not move themselves, for
 * some reason.  May as well though, another way to check duration
 */
  if ( check_duration() )
	call_out("destruct_silence_shadow",0,0);
  return my_player->move(dest, messout, messin );
}
  
int query_silence_spell() { return 1; }

int cast() 
{
  tell_object(my_player,"You cannot cast spells while you are silenced.\n");
  if (check_duration())
	call_out("destruct_silence_shadow",0,0);
  return 1;
}

int do_say(string str)
{
  tell_object(my_player,"You are silenced and can't say anything.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
        "'s mouth moves but no sound comes out.\n",
	my_player);
  if (check_duration())
        call_out("destruct_silence_shadow",0,0);
  return 1;
}

int do_loud_say(string str)
{
  tell_object(my_player,"You are silenced and can't say anything.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
	"'s mouth moves but no sound comes out.\n",
	my_player);
  if (check_duration())
        call_out("destruct_silence_shadow",0,0);
  return 1;
}

int do_shout(string str)
{
  tell_object(my_player,"You cannot shout while you are silenced.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
	" shouts a silent shout.\n",
	my_player);
  if (check_duration())
        call_out("destruct_silence_shadow",0,0);
  return 1;
}

int do_whisper(string str)
{
  tell_object(my_player, "You cannot even manage a whisper while silenced.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
	" moves "+my_player->query_possessive()+" lips but makes no sound.\n",
	my_player);
  if (check_duration())
        call_out("destruct_silence_shadow",0,0);
  return 1;
}

/* for the player's desc. */
string extra_look()
{
  if (check_duration())
        call_out("destruct_silence_shadow",0,0);
  return "Cannot make a sound.\n";
}

/* for an eventual dispel magic spell */
void dispell_me()
{
  
  tell_object(my_player,
	"You feel your voice come back as the Silence spell upon you "
	"is destroyed.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
	" coughs loudly in surprise as the magic is destroyed.\n",
	my_player);
  my_player->remove_extra_look(this_object());
  destruct(this_object());
}

