/*** Bearhug 'hugger' shadow ***/
/*** By Wonderflug ***/

#include "tweaks.h"
#define BEARHUG_GP_ROUND 2

object my_player, my_target;
object my_item;

void destruct_bearhug_shadow() 
{
  if (my_target) 
    my_target->destruct_bearhug();
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
  if ( (int)my_player->query_gp() <= BEARHUG_GP_ROUND || 
       !my_player || !my_target )
  {
    if ( my_player && my_target )
    {
      tell_object(my_player,
        "Tus brazos se cansan y liberas a "+my_target->query_cap_name()+".\n");
      if (my_player && my_target )
        tell_room(environment(my_player), my_player->query_cap_name()+
          " se cansa y deja libre a "+my_target->query_cap_name()+" de su "
          "abrazo mortal.\n",
          ({ my_target, my_player}) );
      tell_object(my_target,
        "Te esfuerzas para liberarte de los brazos de"+my_player->query_cap_name()+
        " y este cede.\n");
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
  tell_object(my_player, "No puedes moverte mientras hagas el abrazo del "
    "oso a alguien!\n");
  if ( check_duration() )
    call_out("destruct_bearhug_shadow",0,0);
  return "";
}
  
int query_hold_spell() { return 1; }

/* Given the next two, we shouldn't need this, but anyway */
int unarmed_attack(object him, object me)
{
  tell_object(me, "Tu estas en un abrazo de oso y no puedes atacar!\n");
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
  tell_object(my_player, "Oprimes fuertemente a "+my_target->query_cap_name()+
    " y su cara comienza a ponerse de colores.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+" oprime a "+
    my_target->query_cap_name()+" y su cara comienza a ponerse azul.\n",
    ({ my_player, my_target }) );
  tell_object(my_target, my_player->query_cap_name()+" te oprime "
    "y tu cara empieza a ponerse azul.\n");

  my_target->adjust_hp( -random((int)my_player->query_damage_bonus()), 
    my_player);
  my_player->adjust_gp(-BEARHUG_GP_ROUND);

  if ( check_duration() )
    call_out("destruct_bearhug_shadow",0,0);
  return 0;
}

attack_ob(object ob) 
{
  tell_object(my_player, "No puedes atacar a alguien mientras hagas "
    "un abrazo de oso.\n");
  if ( check_duration() )
    call_out("destruct_bearhug_shadow",0,0);
  return 0;
}
