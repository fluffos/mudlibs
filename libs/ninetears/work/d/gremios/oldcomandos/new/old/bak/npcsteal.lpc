#include "tweaks.h"
/*
 * Steal.c, one more try.
 * Will be a colc on the cost.
 * Baldrick, sept '4.
 * Fixed a 100 times by different people.
 * added some XP dec '94
 */

void fail(object me,object who, int cost);


int steal(string str,object x) 
{
  object me,*vat,*hoo;
  int cost, vic_lev,diff, thief_lev;
  string what, who;
  mixed thwap;

  /* I do not like this one! Baldrick. */
// L0 and L1 players get infinite lives or near to
// too much abuse by players logging on a thief or three to collect
// gear for them, Taniwha

  if(x) me = x;
  else me = this_player();

  if (me->query_level()<=2) {
    tell_object(me,"You must be over level 2 to steal.\n");
    return 1;
  }

/*  This seemed like it makes sense, added it 2-12-95 in response
    to a complaint from a Mortal being stolen from by a dead 
    thief.       Grimbrand.
*/

  if(me->query_property("dead"))
  {
      tell_object(me,"You are dead! It is not possible to steal.\n");
      return 1;
  }


  if (!str || sscanf(str,"%s from %s",what,who)!=2)
  {
    tell_object(me,"Usage: steal <object> from <person/monster>\n");
    return 1;
  } 
  hoo=find_match(who,environment(me));

  if (!sizeof(hoo)) {
    tell_object(me,"I don't see a "+who+" in here.\n");
    return 1;
  }
   if(sizeof(me->query_attacker_list())
      || (member_array(me,hoo[0]->query_attacker_list()) != -1))
   {
      tell_object(me,"you can't steal while fighting something.\n");
      return 1;
   }

  vat=find_match(what,hoo[0]);

  if (!sizeof(vat)) 
  {
    tell_object(me,"Can not find "+what+" on "+capitalize(who)+".\n");
    return 1;
  }

  if (vat[0]->query_in_use())
  {
    tell_object(me,"You can't steal equipment in use.\n");
    return 1;
  }

  if (hoo[0]->query_creator())    /* are we currently in a creator char :) */
  {
    tell_object(me,"You wouldn't want to steal anything from an immortal, would you?\n");
    return 1;
  }
  
  vic_lev=(int)hoo[0]->query_level();/* this may be a bit cheesy due to diffs */
                                     /* in guilds levels....sigh  */
  
  thief_lev = me->query_level() + me->query_dex(); 

  diff=vic_lev-thief_lev;
  
  if (diff<1)
    diff=2;

  /* Here is the calculation on the cost: */
  
   cost = (STEAL_COST * diff)/10;

  if ((int)me->query_gp() < cost) 
  {
    tell_object(me,"You seem to be too worn out to do that.\n");
    return 1;
  }


  if ((diff<0)&&random(100)>2) 
  {
    fail(me,hoo[0], 0);
    return 1;
  }

  /* The calculation, just a method..:=) */
  if (random(diff) < diff/2)
  {
    fail(me,hoo[0], cost);
    return 1;
  }

  if ((string)vat[0]->query_name()!="coin") 
  {
    tell_object(me,"Ok.\n");
    vat[0]->move(me);
    return 1;
  }

  /* Here is the code for stealing money, not easy to implement a good
   * method for this. But the one here now doesen't work.. trying to fix it.
   * Baldrick oct '94.
   */

  diff=roll(1, (thief_lev*100))+2;

  if (diff>(int)hoo[0]->query_value())
    diff=(int)hoo[0]->query_value();

  thwap=(mixed)"/obj/handlers/money_handler"->create_money_array(diff);
  tell_object(me,"You snag "+(string)"/obj/handlers/money_handler"->money_string(thwap)+
        ".\n");

  hoo[0]->pay_money(thwap); /* this also smells of cheese - not only do we */
                            /* rob them, but we give them change - oh boy */

  me->adjust_money(thwap);
  me->adjust_gp(-cost);
  return 1;
}


void fail(object me,object who, int cost) 
{
  string bing,sme;

  bing=(string)who->query_cap_name();
  sme=(string)me->query_cap_name();

  tell_object(me,"Oh bugger - "+bing+" seems to have noticed your activities.\n");
  tell_object(who,"You suddenly notice "+sme+" groping around in your pockets.\n");
  tell_room(environment(me),sme+" suddenly has an embarrasing moment "
            "in pocket picking.  "+bing+" doesn't look to happy.\n",
            ({who,me}));

  who->attack_by(me);  /*  mean and nasty :) */
  me->adjust_gp(- (cost/3));
}
