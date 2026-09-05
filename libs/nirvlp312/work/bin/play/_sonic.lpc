#include <ansi.h>

/* coded by mal & verte */

int cmd_sonic(string str)
{
  object victim, me;
  int cost, damage;
  string vn, mn, sm1, sm2;

  if((int)(me=this_player())->query_extra_level() < 5) return 0;
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
      return (write("Sonic who?\n"), 1);
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
      return (write("You cannot cast sonic on yourself!\n"), 1);
  }

  damage = random(33) + 12;
  cost = 25;
        
  switch(damage)
  {
    case 42..44: sm1 = HIC+"DEMOLISHED"+NORM;  break;
    case 38..41: sm1 = HIC+"Disrupted"+NORM;   break;
    case 32..37: sm1 = CYN+"Pummeled"+NORM;    break;
    case 20..31: sm1 = "struck";               break;
    case 14..19: sm1 = "hit";                  break;
    case 12..13: sm1 = "grazed";               break;
    }
  switch(random(4))
  {
    case 0:
      sm2="a cone of destructive sound";
      break;
    case 1:
      sm2="waves of sound";
      break;
    case 2:
      sm2="rippling force";
      break;
    case 3:
      sm2="destructive sonic waves";
      break;
  }
  me->spell_object(victim, "sonic", damage, cost,
   "You "+sm1+" "+(vn=(string)victim->query_name())+" with "+sm2+".\n",
   (mn=(string)me->query_name())+" "+sm1+" you with "+sm2+".\n",
   mn+" "+sm1+" "+vn+" with "+sm2+".\n");
  me->set_spell_dtype("other|sonic");
  return 1;     
}
