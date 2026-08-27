//Traducido por Lummen '98
/*****************************************************************************
*									     *	
*                Hold person shadow. Touched by Khelben for let a            *                     
*                   saving throw every round every round	     	     *
*									     *
******************************************************************************/

#include "tweaks.h"

object target;
object caster;
int basetarget,basecaster;

void setup_shadow(object ob, object him) 
{
  shadow(ob,1);
  target = ob;
  caster = him;
  basecaster = him->query_level()+him->query_wis(); 
      if( caster->query_guild_name() == "Cleriga de Astaroth" )
         basecaster = basecaster + 10;
      if( caster->query_guild_name() == "Clerigo de Lummen" )
         basecaster = basecaster + 5;
  if ( target->query_int() > target->query_wis() )
     basetarget = target->query_level()+target->query_int();
  else
     basetarget = target->query_level()+target->query_wis();  
}

int check_duration()
{
  if ( target->query_dead() )
  {
    target->remove_extra_look(this_object());   
    call_out("dispell_me",0);   // I touched this for dispell the shadow
                                // when the player dies. If you know any reason            
   				// for not to do it erase the line.
    return 1;
  }
  if ( !(target->query_timed_property("hold_person_on")) )
    return 1;
  else return 0;
}

move( mixed dest, mixed messout, mixed messin )
{
  if ( check_duration() )
    call_out("dispell_me",0,0);
  return target->move(dest, messout, messin );
}

varargs mixed move_player(string dir, string dest, mixed message, object
                                followee, mixed enter)
{
   int resist;
// Changed to use "mental" rather than physical strength
   if(target->query_int() > target->query_wis()) resist = target->query_int();
   else resist = target->query_wis();
   if( random(resist) < random(40)+6)
  {
    tell_object(target, "No puedes escapar de una fuerza mental que te paraliza.\n");
    if ( !target || check_duration() )
      call_out("dispell_me",0,0);
    return 1;
  }
  tell_room(environment(target),target->query_cap_name()+" intenta escapar  "
    "de una fuerza invisible que lo paraliza, pero no lo consigue.\n", target);
  tell_object(target, "Intentas moverte pero una fuerza invisible te paraliza.\n");
  if ( !target || check_duration() )
   {
   call_out("dispell_me",0,0);
   return 0;
   }

  return target->move_player(dir, dest, message, followee, enter);
}
  
int query_hold_spell() { return 1; }


object* query_weapons_wielded()
{
  if ( check_duration() )
    call_out("dispell_me",0,0);
  return ({ this_object() });
}

int weapon_attack( object him, object me )
{
  int x;
   
  if ( basetarget > basecaster)   
  {				     // target is more powerfull than caster
     if ( random(150) < basetarget)  // so if he has level 40 and int 14 he
        call_out("dispell_me",0);    // has a 43.2 % of possibilities for
                                     // free every round.
  }
  else if (random(200) < basetarget )  //caster more powerfull than target  
     call_out("dispell_me",0);         // with int 14 we have per round:
     				       //  level 20: 17 %
      				       //  level 30: 22 %
     				       //  level 40: 27 %
     
  tell_object(me, "No puedes atacar porque estas paralizado!\n");
  tell_room(environment(me), me->query_cap_name()+" no puede atacar a nadie ya que algo le paraliza.\n", me);
  if ( check_duration() )
    call_out("dispell_me",0,0);
  return 0;
}

attack_ob(object ob) 
{
  tell_object(target, "Estas paralizado por una fuerza invisible, y no puedes atacar "
  "a nadie.\n");
  tell_room(environment(target), target->query_cap_name()+
    " forcejea contra una fuerza invisible.\n", target);
  if ( check_duration() )
    call_out("dispell_me",0,0);
  return 0;
}

int cast() 
{
  tell_object(target, "No puedes formular hechizos ya que estas paralizado.\n");
  tell_room(environment(target), target->query_cap_name()+
    " forcejea contra una fuerza invisible.\n", target);
  if (check_duration())
    call_out("dispell_me",0,0);
  return 1;
}

// for the player's desc. 
string extra_look()
{
  return "Esta paralizado por una fuerza invisible.\n";
}

// for an eventual dispel magic spell 
void dispell_me()
{
  tell_object(target,
    "Puedes moverte de nuevo ya que la fuerza que te paralizaba "
    "ha sido destruida.\n");
  tell_room(environment(target), target->query_cap_name()+
  " queda liberado de la fuerza que le paralizaba.\n",
    target);
  target->remove_timed_property("noguild");
  target->remove_timed_property("nocast");
  target->remove_extra_look(this_object());
  destruct(this_object());
}





