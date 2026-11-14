/* Written by Softbyte August 1995 */

#include <properties.h>
#include <combat.h>
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";
#define TP this_player()
int QueryCost()
{
  int i;
  i= 200+10*TP->QueryLevel();
  if (i>400) i=400;
  return i;
}
int MyCast(string str) 
{
object mon;
string name;
int hp,value;
  if (!str) 
  {
    write("Which monster should be killed?\n");
    return CAST_FAIL_NOMSG;
  }
  mon=present(str, environment(TP));
  if (!mon) { write("Cast it on whom?\n"); return CAST_FAIL_NOMSG; }
  if (member(TP->QueryEnemies(), mon)==-1)
  {
    write(capitalize(mon->QueryName())+" is not attacking you.\n");
    return CAST_FAIL_NOMSG;
  }
  if (!mon->QueryIsNPC() )
  {
     write("You cannot cast this spell on that.\n");
     return CAST_FAIL_NOMSG;
  }
  if (Repulse(mon,TP)) return CAST_REPULSE;
  name=mon->QueryName()||mon->QueryShort()||"someone";
  name=capitalize(name);

  value=TP->QueryAttr("Wis");
  value+=TP->QueryAttr("Sta");
  value+=TP->QueryAttr("Int");
  value=(value*2)/3;
  if (random(2)!=0 || random(value)<mon->QueryLevel()) /* failed */
  {
    Message( ({name+" can't stop laughing at you.\n",
         name+" can't stop laughing at "+TP->QueryName()+".\n"}) );
    return CAST_SUCCESS;
  }
  Message( ({"You suck the lifeforce out of "+name+".\n",
    TP->QueryName()+" sucks the lifeforce out of "+name+".\n"}) );
  hp=mon->QueryHP();
  hp=hp/3;
  mon->Die();
  TP->HealHP(hp);
  Message( ({"You feel better now.\n",
           TP->QueryName()+" licks his mouth.\n"}) );
  return CAST_SUCCESS;
}
int MyFail()
{
int dam;
  /* it is not possible to repulse this spell ! */
  Message( ({"You can see how your lifeforce flows away.\n",
    TP->QueryName()+" is touched by death.\n"}) );
  dam=5+random(100);
  dam=TP->Defend(ModifyMagic(dam),DT_ZAP,0);
  Message(QueryCastDamage(dam));
  dam=5+random(100);
  dam=TP->Defend(ModifyMagic(dam),DT_PSYCHO,0);
  Message(QueryCastDamage(dam));
  dam=5+random(100);
  dam=TP->Defend(ModifyMagic(dam),DT_FIRE,0);
  Message(QueryCastDamage(dam));
  dam=5+random(100);
  dam=TP->Defend(ModifyMagic(dam),DT_WATER,0);
  Message(QueryCastDamage(dam));
  return CAST_SUCCESS; 
}

create()
{
 ::create();
 AddSpell("ikill",ST_ZAP,#'QueryCost,#'MyCast,"instant kill",95);
 SetSpellDesc(
"This spell tries to kill a creature outright by draining its lifeforce.\n\
A part of its lifeforce will be channelled back to you.\n\
There is only success or no success with this spell. Success depends\n\
on your magic abilities versus the monsters level.\n\
The monster has to fight against you to invoke this spell!\n\
It costs you 200 + 10 * level SP to cast it.\n\
But not more than 400 SP.\n\
For low level players it is extremely dangerous to use this spell!\n");
 SetSpellUsage("cast ikill <enemy>\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,26);
 SetMemoLevel(GC_ARCHMAGE,36);
 SetFailFn(#'MyFail);
 NoSell();
}

