/*** Bearhug 'target' shadow ***/
/*** By Wonderflug ***/

#include "tweaks.h"

object my_player, my_hugger, my_item;

void destruct_bearhug_shadow() 
{
  if (my_hugger) 
    my_hugger->destruct_bearhug();
  if (my_item) 
    my_item->dest_me();
  my_player->remove_static_property("nocast");
  my_player->remove_static_property("noguild");
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
  my_hugger = him;
  my_item = it;
}

int check_duration()
{
  int t_roll, h_roll;

/* Target gets random(level)+random(str)+random(dex).  Hugger gets
 * random(level)+str+random(20).  Should skew things toward the fighter
 * which I think is how it should be.  Still a good chance to break out
 * cause of the random's tho.
 */
  t_roll = random((int)my_player->query_level());
  t_roll += random((int)my_player->query_str());
  t_roll += random((int)my_player->query_dex());
  h_roll = random((int)my_hugger->query_level());
  h_roll += (int)my_hugger->query_str();
  h_roll += random(20);
  if ( t_roll > h_roll )
  {
    tell_object(my_player,
      "You break free of "+my_hugger->query_cap_name()+" grasp!\n");
    tell_room(environment(my_player), my_player->query_cap_name()+
      " struggles and breaks free of "+my_hugger->query_cap_name()+"!\n",
      ({ my_hugger, my_player}) );
    tell_object(my_hugger, my_player->query_cap_name()+
      " breaks out of your grip!\n");
    my_player->remove_static_property("noguild");
    my_hugger->remove_static_property("nocast");
    my_player->remove_static_property("nocast");
    my_hugger->remove_static_property("noguild");
    return 1;
  }
  else return 0;
}

varargs mixed move_player(string dir, string dest, mixed message, object
				followee, mixed enter)
{
  tell_object(my_player, "You cannot move out of "+my_hugger->query_cap_name()+
    "'s grip!\n");
  return 0;
}
  
int query_hold_spell() { return 1; }

int unarmed_attack(object him, object me)
{
  tell_object(me, "You cannot attack!\n");
  return 0;
}

object* query_weapons_wielded()
{
  return ({ this_object() });
}

int weapon_attack( object him, object me )
{
  tell_object(my_player, "You struggle to break free of "+
    my_hugger->query_cap_name()+"'s grasp.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+" struggles"
    " against "+my_hugger->query_cap_name()+".\n",
    ({ me, him }) );
  tell_object(my_hugger, my_player->query_cap_name()+" struggles against "
    "you.\n");
  if ( check_duration() )
    call_out("destruct_bearhug_shadow",0,0);
  return 0;
}

attack_ob(object ob) 
{
  tell_object(my_player, "You are in no position to attack anyone.\n");
  return 0;
}


int cast()
{
  tell_object(my_player, "You're hardly in a position to do that.\n");
  return 1;

}

int adjust_hp(int amount, object doer)
{
  int thres;

  if ( !doer || doer == my_player || doer == my_hugger || amount >= 0 )
    return my_player->adjust_hp(amount, doer);
  thres = 50 + (int)my_hugger->query_level();
  thres = (thres>75)? 75 : thres;
  if ( random(100) > thres )
  {
    tell_object(my_hugger, "You are grazed by the attack!\n");
    tell_room(environment(my_player), my_hugger->query_cap_name()+
      " winces as the attack hits "+my_hugger->query_objective()+" too!\n",
      my_hugger);
    my_hugger->adjust_hp(amount/(random(3)+1), doer);
  }

  return my_player->adjust_hp(amount, doer);
}
