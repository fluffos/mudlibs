/*** General Stun Shadow ***/
/*** Used for Power Word Stun and Mug, currently ***/
/*** By Wonderflug ***/


object my_player;

void destruct_stun_shadow() 
{
  if ( my_player )
  {
    tell_object(my_player, "You shake off the effects of the stun.\n");
    tell_room(environment(my_player), my_player->query_cap_name()+
      " shakes off the effects of the stun.\n", my_player);
  }
  destruct(this_object());
}

void setup_shadow(object ob) 
{
  shadow(ob,1);
  my_player = ob;
}

int check_duration()
{
  if ( !my_player || !(my_player->query_timed_property("stun_on")) )
  {
    if ( my_player )
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

varargs mixed move_player(string dir, string dest, mixed message, object
                                followee, mixed enter)
{
  if ( this_player(1) && this_player(1)->query_creator() )
    return my_player->move_player(dir, dest, message, followee, enter);

  tell_object(my_player, "You're really in no condition to attempt that.\n");

  if ( check_duration() )
    call_out("destruct_stun_shadow",0,0);

  return 0;
}
