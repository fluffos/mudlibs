#include <ansi.h>

status cmd_consider(string str) {
  object ob, me;
  int    x, cost;
  string mess;

  if((int)(me=this_player())->query_level() <= 5)
    cost=5;
  else
    cost=10;
  me->spell_block();
  if((int)me->query_spell_block())
    return (write("You are unable to do that.\n"), 1);
  if(!str)
    return (write("Usage: 'consider <who>'\n"), 1);
  if(!(ob=present(str, environment(me))))
    return (write("You don't see "+str+" here.\n"), 1);
  if(!living(ob))
    return (write(capitalize(str) + " is not alive.\n"), 1);

  if(ob==this_player())
    return (write("You can't cast this spell upon yourself.\n"), 1);
  if((int)this_player()->query_sp() < cost)
    return (write("You don't have enough spell points to cast this.\n"), 1);
  this_player()->add_spell_point(-cost);
  write("You cast the spell of "+HIC+"Consider"+NORM+"...\n");
  say((string)this_player()->query_name() + " casts the spell of " +
   HIC+"Consider"+NORM+"...\n");
  write("\n");
  
  x=(int)ob->query_ac();
  switch(x)
  {
    case 13..16:
      mess="Highly Protected";
      break;
    case 10..12:
      mess="Well Protected";
      break;
    case 7..9:
      mess="Moderately Protected";
      break;
    case 4..6:
      mess="Lightly Protected";
      break;
    case 1..3:
      mess="Very Lightly Protected";
      break;
    case -10000..0:
      mess="Unprotected";
      break;
    default:
      mess="Extremely Well Protected";
      break;
  }
  write("\t"+capitalize(subjective(ob)) + " is "+HIB+mess+NORM
       +" from Physical attack.\n");
  x=(int)ob->query_wc();
  switch(x)
  {
    case 24..27:
      mess="Incredibly Powerful";
      break;
    case 20..23:
      mess="Extremely Powerful";
      break;
    case 16..19:
      mess="Highly Powerful";
      break;
    case 12..15:
      mess="Moderately Powerful";
      break;
    case 8..11:
      mess="Weak";
      break;
    case 5..7:
      mess="Very Weak";
      break;
    case 1..4:
      mess="Incredibly Weak";
      break;
    case -10000..0:
      mess="Incapable of Inflicting Serious Wounds";
      break;
    default:
      mess="Amazingly Powerful";
      break;
  }
  write("\tPhysically, "+subjective(ob) + " is "+HIR+mess+NORM
       +".\n");
  x=(int)ob->query_hp();
  switch(x)
  {
    case 0:
      mess = "Zero";
      break;
    case 1..50:
      mess = "Extremely Small";
      break;
    case 51..100:
      mess = "Very Small";
      break;
    case 101..150:
      mess = "Small";
      break;
    case 201..250:
      mess = "Small-to-Moderate";
      break;
    case 251..300:
      mess = "Moderate";
      break;
    case 301..350:
      mess = "Moderate-to-Large";
      break;
    case 351..400:
      mess = "Slightly Large";
      break;
    case 401..450:
      mess = "Large";
      break;
    case 451..500:
      mess = "Very Large";
      break;
    case 501..600:
      mess = "Extreme";
      break;
    case 601..700:
      mess = "Stunning";
      break;
    case 701..800:
      mess = "Tremendous";
      break;
    case 801..1000:
      mess = "Unbelievable";
      break;
    default:
      mess = "Godlike";
      break;
  }
  write("\t"+capitalize(subjective(ob)) + " has the capacity to take " + 
         HIG + mess + NORM + " amounts of damage.\n");
  write("\n");
  return 1;
}

