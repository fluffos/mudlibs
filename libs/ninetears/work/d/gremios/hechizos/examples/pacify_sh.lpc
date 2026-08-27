/*** Pacify shadow ***/
/*** By Wonderflug ***/

#include "tweaks.h"

object my_player;

void destruct_pacify_shadow() 
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
  if ( my_player->query_dead() )
  {
    my_player->remove_extra_look(this_object());
    return 1;
  }
  if ( !(my_player->query_timed_property("pacify_on")) )
  {
    tell_object(my_player,
      "That feeling of goodness surrounding you disappears, and you"
      " feel violent.\n");
    tell_room(environment(my_player), my_player->query_cap_name()+
      " gets a nasty gleam in "+my_player->query_possessive()+
      " eye, and clenches "+my_player->query_possessive()+ " fists "
      "slowly.\n", my_player);
    my_player->remove_extra_look(this_object());
    return 1;
  }
  else return 0;
}

int move( mixed dest, mixed messout, mixed messin )
{
  if ( check_duration() )
    call_out("destruct_pacify_shadow",0,0);
  return my_player->move(dest, messout, messin );
}
  
int adjust_hp(int i, object hp_remover)
{
  int j;

  if ( !previous_object() )
    return my_player->adjust_hp(i, hp_remover);

  if ( interactive( previous_object() ) )
    j = 1;
   else if(environment(previous_object()) && interactive(environment(previous_object())) )
    j = 1;

  if ( j )
  {     
    tell_object(previous_object(), "You cannot bring yourself to harm a "
      "pacified person.\n");
    tell_object(my_player, "Being pacified, you take no damage from a "
      "player.\n");
    previous_object()->stop_fight(my_player);
    my_player->stop_fight(previous_object());
    if ( check_duration() )
      call_out("destruct_pacify_shadow",0,0);
    return my_player->query_hp();
  }

  if ( check_duration() )
    call_out("destruct_pacify_shadow",0,0);
  return my_player->adjust_hp(i, hp_remover);
}

int query_pacify_spell() { return 1; }

object* query_weapons_wielded()
{
  return ({ this_object() });
}

int weapon_attack( object him, object me )
{
  object* ob;
  int i, dam;

  if (interactive(him))
  {
    tell_object(me, "You feel too peaceful to attack and don't.\n");
    tell_room(environment(me), me->query_cap_name()+" cowers and doesn't "
      "attack.\n", me);
    if ( check_duration() )
        call_out("destruct_pacify_shadow",0,0);
    return 0;
  }
  ob = my_player->query_weapons_wielded();
  if (!sizeof(ob))
  {
    if ( check_duration() )
      call_out("destruct_pacify_shadow",0,0);
    return my_player->unarmed_attack(him, me);
  }

  for (i=0;i<sizeof(ob);i++)
    dam += ob[i]->weapon_attack(him,me);

  if ( check_duration() )
    call_out("destruct_pacify_shadow",0,0);
  return dam;
}

int attack_by(object ob) 
{
  if (interactive(ob))
  {
    tell_object(ob, my_player->query_cap_name()+" seems far too harmless "
      "to attack right now.  You just can't \nbring yourself to do it.\n");
    ob->stop_fight(my_player);
    my_player->stop_fight(ob);
  }

  if ( check_duration() )
        call_out("destruct_pacify_shadow",0,0);
  return 0;
}

int attack_ob(object ob) 
{
  if ( interactive(ob) )
  {
    tell_object(my_player, "You don't feel like attacking anything "
      "right now.  Fighting just seems so pointless.  Why can't we all "
      "just be friends?\n");
    ob->stop_fight(my_player);
    my_player->stop_fight(ob);
    if ( check_duration() )
      call_out("destruct_pacify_shadow",0,0);
    return 0;
  }

  if ( check_duration() )
    call_out("destruct_pacify_shadow",0,0);
  return my_player->attack_ob(ob);
}

/* Shouldn't need this with the nocast in place but anyway */
int cast() 
{
  tell_object(my_player, "You don't feel like casting spells.. why not go "
    "sniff a flower instead?\n");
  if (check_duration())
    call_out("destruct_pacify_shadow",0,0);
  return 1;
}

/* for the player's desc. */
string extra_look()
{
  return "Looks incredibly harmless, chasing butterflys.\n";
}

/* for an eventual dispel magic spell */
/* We DON'T want this yet. 
void dispell_me()
{
  
  tell_object(my_player,
    "You feel your mean streak come back as the Pacify spell upon you "
    "is destroyed.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
    " gets a mean gleam in "+my_player->query_possessive()+ " eye "
    "as the magic is destroyed.\n",
    my_player);
  my_player->remove_extra_look(this_object());
  my_player->remove_timed_property("noguild");
  my_player->remove_timed_property("nocast");
  destruct(this_object());
}
*/
