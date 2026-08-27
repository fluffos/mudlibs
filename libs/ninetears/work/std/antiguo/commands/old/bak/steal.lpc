#include "tweaks.h"
#define CAUGHT "caught_stealing"
/*
 * Steal.c, one more try.
 * Will be a calc on the cost.
 * Baldrick, sept '4.
 * Fixed a 100 times by different people.
 * added some XP dec '94
 *
 * Added steal at will and nosteal checks -- Wonderflug, apr 95
 *
 * Fixed random chance of detection, always suceeded before
 *    and made it level dependant
 *    Failed attempts on players lock out steal, since
 *    players auto-attack
 *
 */
void fail(object me,object who, int cost);
int steal(string str,object thief)
{
  object me,*vat,*hoo;
  int cost, vic_lev,diff, thief_lev;
  string what, who;
  mixed thwap;
   if(thief) me = thief;
   else me = this_player();
  /* I do not like this one! Baldrick. */
// L0 and L1 players get infinite lives or near to
// too much abuse by players logging on a theif or three to collect
// gear for them, Taniwha
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
    notify_fail("Usage: steal <object> from <person/monster>.\n");
  if (!str)
    return 0;
  if (sscanf(str,"%s from %s",what,who)!=2)
    return 0;
  hoo=find_match(who,environment(me));
  if (!sizeof(hoo)) {
    tell_object(me,"I don't see a "+who+" in here.\n");
    return 1;
  }
  if(sizeof(me->query_attacker_list()))
  {
      tell_object(me,"You can't steal while fighting something.\n");
      return 1;
  }
  if(member_array(me,hoo[0]->query_attacker_list()) != -1)
  {
      tell_object(me,"You can't steal while fighting something.\n");
      return 1;
  }
  if( (int)me->query_property(CAUGHT) == 1 )
  {
      tell_object(me,"Your hands are shaking from your previous near death experience.\n");
      return 1;
  }
  if( (int)me->query_property(CAUGHT) == 2 )
  {
       tell_object(me,"You so embarassed by your previous failure that you can't work up the courage to steal again yet.\n");
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
  if (hoo[0]->query_creator())    /* are we currently in a creator char :)
*/
   {
    tell_object(me,"You wouldn't want to steal anything from an immortal,would you?\n");
    return 1;
  }
  /* this may be a bit cheesy due to diffs */
  vic_lev=(int)hoo[0]->query_level();
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
  if ( hoo[0]->query_property("nosteal") || 
        environment(hoo[0])->query_property("nosteal") )
  {
	tell_object(me,"Hmm.  Can't do that now.\n");
        return 1;
  }
  /* The calculation, just a method..:=) */
  if ( !(hoo[0]->query_property("steal at will")) )
  {
    /* always a chance of success, and a chance of failure
       odds increase with level and dex
       decrease with target level and level diff
    */
    if(random((int)me->query_level()+(int)me->query_dex()) < random((int)hoo[0]->query_level() + diff) )
    {
        fail(me,hoo[0], cost);
        return 1;
    }
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
  if (diff>=(int)hoo[0]->query_value())
    diff=(int)hoo[0]->query_value()-1;
   if(diff <= 0)
   {
      tell_object(me,"Hmm he's broke, nothing but moths, oh well, live and learn.\n");
      me->adjust_gp(-cost);
      return 1;
   }
  thwap=(mixed)"/obj/handlers/money_handler"->create_money_array(diff);
  tell_object(me,"You snag
  "+(string)"/obj/handlers/money_handler"->money_string(thwap)+
        ".\n");
  hoo[0]->pay_money(thwap); /* this also smells of cheese - not only do we
*/
                            /* rob them, but we give them change - oh boy
*/
  me->adjust_money(thwap);
  me->adjust_gp(-cost);
  return 1;
}
void fail(object me,object who, int cost)
{
  string bing,sme;
  int ldiff;
  bing=(string)who->query_cap_name();
  sme=(string)me->query_cap_name();
  tell_object(me,"Oh bugger - "+bing+" seems to have noticed your activities.\n");
  tell_object(who,"You suddenly notice "+sme+" groping around in your pockets.\n");
  tell_room(environment(me),sme+" suddenly has an embarrasing moment "
            "in pocket picking.  "+bing+" doesn't look to happy.\n",
            ({who,me}));
  /* fair either way, get caught by someone lower level, it the embarasment */
  /* higher and he's likely to kill you */
  ldiff = (int)who->query_level() - (int)me->query_level();
  if (!interactive(who))
    who->attack_by(me);  /*  mean and nasty :) */
  else  /* since players won't auto-attack */
  {
      if(ldiff > 0) me->add_timed_property(CAUGHT,1,ldiff * CAUGHT_LOCK);
      else if(ldiff < 0) me->add_timed_property(CAUGHT,2,-(ldiff * CAUGHT_LOCK));
  }
  me->adjust_gp(- (cost/3));
}


