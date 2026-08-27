/*** General Stun Shadow ***/
/*** Used for Power Word Stun and Mug, currently ***/
/*** By Wonderflug ***/

/* Lasts as long as stun_on is a property on the player.
 * To be used in conjunction with 'passed out' on the player too.
 * Since this only stops combat -- passed out will block all commands.
 */


object my_player;

void destruct_stun_shadow() 
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
  if ( !(my_player->query_timed_property("stun_on")) )
  {
	my_player->remove_extra_look(this_object());
	return 1;
  }
  else return 0;
}

move( mixed dest, mixed messout, mixed messin )
{
  if ( check_duration() )
	call_out("destruct_stun_shadow",0,0);
  return my_player->move(dest, messout, messin );
}

int query_hold_spell() { return 1; }

object* query_weapons_wielded()
{
  if ( check_duration() )
        call_out("destruct_stun_shadow",0,0);
  return ({ this_object() });
}

int weapon_attack( object him, object me )
{
  tell_object(me, "You are stunned and cannot attack!\n");
  tell_room(environment(me), me->query_cap_name()+" shifts groggily.\n", me);
  if ( check_duration() )
        call_out("destruct_stun_shadow",0,0);
  return 0;
}

attack_ob(object ob) 
{
  tell_object(my_player, "You are stunned and cannot attack!\n");
  if ( check_duration() )
  	call_out("destruct_stun_shadow",0,0);
  return 0;
}

/* for the player's desc. */
string extra_look()
{
  return "Is stunned.\n";
}

/* No dispell_me for this since more than just magic stuff uses it.. and
 * a power word stun is a one-time hit more than an enchantment. :)
 */
