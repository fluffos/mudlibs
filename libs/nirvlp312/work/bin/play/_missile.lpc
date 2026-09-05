#include <ansi.h>

/* coded by mal & verte */

int cmd_missile(string str)
{
  object victim, me;
  int cost, damage;
  string vn, mn, sm1, sm2;

  if((int)(me=this_player())->query_level() < 5) return 0;
  me->spell_block();
  if((int)me->query_spell_block())
    return (write("You are unable to do that.\n"), 1);
  if((int)me->query_spell_dam())
    return (write(
     "Your magical energy has already been used " +
     "in an attack spell this round.\n"), 1);

  if(!str)
  {
    if(!(victim = (object)me->query_attack()))
      return (write("Missile who?\n"), 1);
    if(!present(victim, environment(me)))
      return (write((string)victim->query_name() + " isn't here.\n"), 1);
  }
  else
  {
    if(!(victim = present(str, environment(me))))
      return (write("You don't see " + str + " here.\n"), 1);
    if(!living(victim))
    {
      write("You cannot attack that!\n");
      say((string)me->query_name() + 
        " foolishly tries to attack " + str + ".\n");
      return 1;
    }
    if(!me->valid_attack(victim))
      return 1;
    if(victim == me)
      return (write("You cannot cast missile on yourself!\n"), 1);
  }

  damage = random(20);
  cost = 10;
        
  switch(damage)
  {
    case 19:     sm1 = HIW+"BLASTED"+NORM;     break;
    case 17..18: sm1 = HIW+"Devastated"+NORM;  break;
    case 13..16: sm1 = HIW+"blasted"+NORM;     break;
    case 9..12:  sm1 = "struck";               break;
    case 3..8:   sm1 = "hit";                  break;
    case 2:      sm1 = "grazed";               break;
    case 1:      sm1 = "singed";               break;
    default:     sm1 = "missed";               break;
  }
  switch(random(4))
  {
    case 0:
      sm2="magic bolt";
      break;
    case 1:
      sm2="crackling bolt of magic";
      break;
    case 2:
      sm2="missile of energy";
      break;
    case 3:
      sm2="magic missile";
      break;
  }

  me->spell_object(victim, "missile", damage, cost,
   "You "+sm1+" "+(vn=(string)victim->query_name())+" with a "+sm2+".\n",
   (mn=(string)me->query_name())+" "+sm1+" you with a "+sm2+".\n",
   mn+" "+sm1+" "+vn+" with a "+sm2+".\n");
  me->set_spell_dtype("magical");

  return 1;     
}
