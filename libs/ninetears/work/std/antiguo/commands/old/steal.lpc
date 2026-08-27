#include "tweaks.h"
#define CAUGHT "caught_stealing"
#define STOLEN "stolen"
#define WRISK 100  // XP weighting for weight
#define VDIV 1000 // XP divider on value
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
 * Added STOLEN propety to items nicked and award XP based on weight and risk
 *
 */
// Taniwha 1995. Odds of stealing an item, and the XP for it.
// Factors to consider. Weight loss on victim.
// Value
// Relative level and dex
// For XP calcs. Take relative level, weight and value into account
//
#define VMOD 1000

int steal_succeed(object me, object her,object it)
{
    int tl,bl,xp,diff,v,xpc;
   int j;
   if(it->query_property("nosteal")) return 0;
    tl = her->query_max_weight();
    bl = it->query_weight();
    v = it->query_value()/VMOD;
   xp = (v*bl)/tl+1;
    bl += v;
    tl *= ( (me->query_level() + me->query_dex()));
    bl *= her->query_level();
    if(bl == 0) return 0;  // L0 or something stupid :)
// Gives DEDICATED thieves roughly a 2:1 advantage over other guilds.
   if(me->query_guild_name() != "thief") bl *= 2; 
   if(me->query_creator()) write("Rolling against "+bl+" for "+tl+".\n");

   j = random(tl);
   j -= random(bl);
   if(me->query_creator()) write("result "+j+".\n");
   if(j > 0)
    {
        if(it->query_property("stolen")) return 1;
      if(xp > 150) xp = 50+random(150);
        xp *= ((her->query_level() - me->query_level())/3);
        if(xp < 0) return 1;
      if( xp > (100* her->query_level())) xp = 100* her->query_level();
      if(me->query_creator()) write("Xp = "+xp+".\n");
    }
    else xp = 0;
    return xp;
}

void fail(object me,object who, int cost);
int steal(string str,object thief)
{
  object me,*vat,*hoo;
  int cost, vic_lev,diff, thief_lev,xp;
   int i,v;
  string what, who;
  mixed thwap;
   if(thief) me = thief;
   else me = this_player();
  if (me->query_level()<=2) {
    tell_object(me,"You must be over level 2 to steal.\n");
    return 1;
  }
  if(me->query_dead())
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
  if (!sizeof(hoo))
  {
    tell_object(me,"I don't see a "+who+" in here.\n");
    return 1;
  }
  if( !hoo[0]->query_alive())
  {
    tell_object(me,"It's not alive.\n");
    return 1;
  }
  if(sizeof(me->query_attacker_list()) || (member_array(me,hoo[0]->query_attacker_list()) != -1))
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
       tell_object(me,"You so embarassed by your previous failure that you "
                      "can't work up the courage to steal again yet.\n");
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
  if (hoo[0]->query_creator()) /* are we currently in a creator char :)*/
  {
    tell_object(me,"You wouldn't want to steal anything from an immortal, "
                   "would you?\n");
    return 1;
  }
  /* this may be a bit cheesy due to diffs */
  vic_lev=(int)hoo[0]->query_level();
  /* in guilds levels....sigh  */
  thief_lev = me->query_level() + me->query_dex();
  diff=vic_lev-thief_lev;
  if (diff<1) diff=2;
  /* Here is the calculation on the cost: */
  cost = ((STEAL_COST * diff)/10)+1;
  if ((int)me->query_gp() < cost)
  {
    tell_object(me,"You seem to be too worn out to do that.\n");
    return 1;
  }
  if ( hoo[0]->query_property("nosteal") || 
        environment(hoo[0])->query_property("nosteal") )
  {
    tell_object(me,"Hmm. Can't do that now.\n");
        return 1;
  }
// Objects, risk /XP based on weight
  if ((string)vat[0]->query_name() != "coin")
  {
   if(! (xp = steal_succeed(me,hoo[0],vat[0])))
    {
        fail(me,hoo[0],cost);
        return 1;
    }
    tell_object(me,"Ok.\n");
    vat[0]->move(me);
    vat[0]->add_property(STOLEN,1);
    me->adjust_xp(xp);
    return 1;
  }
// Steal coins
  /* The calculation, just a method..:=) */
  if ( !(hoo[0]->query_property("steal at will")) )
  {
    /* always a chance of success, and a chance of failure
       odds increase with level and dex
       decrease with target level and level diff
    */
    if(random((int)me->query_level()+(int)me->query_dex())  <
        random((int)hoo[0]->query_level() + diff) )
    {
        fail(me,hoo[0], cost);
        return 1;
    }
  }

  /* Here is the code for stealing money, not easy to implement a good
   * method for this. But the one here now doesen't work.. trying to fix it.
   * Baldrick oct '94.
   * Taniwha 1995, they can steal their level in coins 
   */
  thwap = (mixed)hoo[0]->query_money_array();

  diff = thief_lev+1;
   if(me->query_guild_name() != "thief") diff /= 2;
  if(!sizeof(thwap))
  {
      tell_object(me,"Hmm he's broke, nothing but moths, oh well, live and learn.\n");
      me->adjust_gp(-cost);
      return 1;
  }
  tell_object(me,"You snag ");
  for(i = sizeof(thwap) -1;diff > 0 && i > 0; i -= 2)
  {
    v = random(diff);
    if( v > thwap[i] ) v = thwap[i];
    if(v)
    {
      me->adjust_money(v,thwap[i-1]);
        tell_object(me,sprintf("%i %s, ",v,thwap[i-1]));
      hoo[0]->adjust_money(-v,thwap[i-1]);
        diff -= v;
    }
  }
  tell_object(me,"coins.\n");
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
            "in pocket picking.  "+bing+" doesn't look too happy.\n",
            ({who,me}));
  /* fair either way, get caught by someone lower level, it the embarasment */
  /* higher and he's likely to kill you */
   who->add_timed_property("nosteal",1,1000);
  if(! me->query_creator() ) // Taniwha, so I don't waste time testing this
  {
    ldiff = (int)who->query_level() - (int)me->query_level();
    if (!interactive(who))
        who->attack_by(me);  /*  mean and nasty :) */
    else  /* since players won't auto-attack */
    {
      if(ldiff > 0) me->add_timed_property(CAUGHT,1,ldiff * CAUGHT_LOCK);
      else if(ldiff < 0) me->add_timed_property(CAUGHT,2,-(ldiff * CAUGHT_LOCK));
    }
  }
  me->adjust_gp(- ((cost/3)+1));
}
