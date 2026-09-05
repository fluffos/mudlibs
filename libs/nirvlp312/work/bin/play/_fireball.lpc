#include <ansi.h>

/* coded by mal & verte */

int cmd_fireball(string str)
{
  object victim, me;
  int cost, damage;
  string vn, mn, sm1, sm2;

  if((int)(me=this_player())->query_level() < 15) return 0;
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
      return (write("Fireball who?\n"), 1);
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
      return (write("You cannot cast fireball on yourself!\n"), 1);
  }

  damage = random(40);
  cost = 20;
        
  switch(damage)
  {
    case 39:     sm1 = HIR+"INCINERATED"+NORM; break;
    case 37..38: sm1 = HIR+"Devastated"+NORM;  break;
    case 33..36: sm1 = RED+"Blasted"+NORM;     break;
    case 24..32: sm1 = "struck";               break;
    case 9..23:  sm1 = "hit";                  break;
    case 5..8:   sm1 = "grazed";               break;
    case 1..4:   sm1 = "singed";               break;
    default:     sm1 = "missed";               break;
  }
  switch(random(4))
  {
    case 0:
      sm2="fiery bolt of destruction";
      break;
    case 1:
      sm2="sizzling blast of fire";
      break;
    case 2:
      sm2="bolt of fire";
      break;
    case 3:
      sm2="large ball of flame";
      break;
  }
  me->spell_object(victim, "fireball", damage, cost,
   "You "+sm1+" "+(vn=(string)victim->query_name())+" with a "+sm2+".\n",
   (mn=(string)me->query_name())+" "+sm1+" you with a "+sm2+".\n",
   mn+" "+sm1+" "+vn+" with a "+sm2+".\n");
  me->set_spell_dtype("other|fire");
  return 1;     
}
