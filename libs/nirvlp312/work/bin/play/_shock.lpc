#include <ansi.h>

/* coded by mal & verte */

int cmd_shock(string str)
{
  object victim, me;
  int cost, damage;
  string vn, mn, sm1, sm2;

  if((int)(me=this_player())->query_level() < 10) return 0;
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
      return (write("Shock who?\n"), 1);
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
      return (write("You cannot cast shock on yourself!\n"), 1);
  }

  damage = random(30);
  cost = 15;
        
  switch(damage)
  {
    case 29:     sm1 = HIY+"DESTROYED"+NORM;   break;
    case 27..28: sm1 = HIY+"Blasted"+NORM;     break;
    case 23..26: sm1 = YEL+"Fried"+NORM;       break;
    case 19..22: sm1 = "struck";               break;
    case 9..18:  sm1 = "hit";                  break;
    case 5..8:   sm1 = "grazed";               break;
    case 1..4:   sm1 = "numbed";               break;
    default:     sm1 = "missed";               break;
  }
  switch(random(4))
  {
    case 0:
      sm2="tracers of electricity";
      break;
    case 1:
      sm2="tendrils of energy";
      break;
    case 2:
      sm2="scorching tendrils of energy";
      break;
    case 3:
      sm2="searing white energy";
      break;
  }
  me->spell_object(victim, "shock", damage, cost,
   "You "+sm1+" "+(vn=(string)victim->query_name())+" with "+sm2+".\n",
   (mn=(string)me->query_name())+" "+sm1+" you with "+sm2+".\n",
   mn+" "+sm1+" "+vn+" with "+sm2+".\n");
  me->set_spell_dtype("other|electric");
  return 1;     
}
