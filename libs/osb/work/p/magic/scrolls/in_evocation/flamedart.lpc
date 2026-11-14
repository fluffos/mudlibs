/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

#define TP this_player()


int MyCast(string str) 
{
object wolf;
int dam;
  if (!str) wolf=GetEnemy(TP);
  else wolf=present(str,environment(TP));
  if (!wolf) { write("That's not here.\n"); return CAST_FAIL_NOMSG; }
  if (!wolf->QueryIsNPC() && !wolf->QueryIsPlayer()) {
     write("You can't "+QueryCastVerb()+" it on that!\n");
     return CAST_FAIL_NOMSG;
  }
  if (wolf->QueryIsPlayer()) LogCast(TP,wolf); 
  if (Repulse(wolf, TP)) return CAST_REPULSE;
Message( ({
"You free your mind of fear and concentrate. Slowly you raise your arm\n"+
"and stretch out your index finger towards "+wolf->QueryName()+".\n"+
"You take a deep breath and bellow: 'BURN MONSTER!!!'\n"+
"Instantly a red hot missile shoots off at your opponent. A stench of\n"+
"burnt flesh fills the air.\n",
TP->QueryName()+" raises "+TP->QueryPossessive()+" arm towards "+
wolf->QueryName()+".\n"+
"Instantly a red hot missile shoots off at "+wolf->QueryName()+".\n" }) );
  dam = random(11) + 10;
  dam=wolf->Defend(ModifyMagic(dam), DT_FIRE, 0);
  if (wolf) Message(QueryCastDamage(dam,wolf));
  return CAST_SUCCESS;
}

int MyFail() {
int dam;
  if (Repulse(TP,TP)) return CAST_REPULSE;
Message( ({
"You free your mind of fear and concentrate. Slowly you raise your arm\n"+
"and stretch out your index finger towards your enemy.\n"+
"You take a deep breath and bellow: 'BURN MONSTER!!!'\n"+
"A stench of burning flesh fills the air. Suddenly you realize that the\n"+
"burning flesh is yours. Yelling and hopping you shake your hand.\n",
TP->QueryName()+" raises "+TP->QueryPossessive()+" arm and mumbles: "+
"'Burn monster'.\n"+TP->QueryName()+" is hit by a flame dart.\n" }) );
  TP->SetSmell(TP->QueryName()+
        " smells of burned flesh.\n");
  dam=random(18);
  dam=TP->Defend(ModifyMagic(dam), DT_FIRE, 0);
  Message(QueryCastDamage(dam));
  return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("flame",ST_FIRE,15,#'MyCast,"flame dart",20);
 SetSpellDesc(
"This spell will shoot a flame dart at your opponent doing up to 20 HP\n\
fire damage.\n");
 SetSpellUsage("cast flame <target>\n");
 SetMemoLevel(GC_SORCERER,2);
 SetMemoLevel(GC_ARCHMAGE,2);
 SetFailFn( #'MyFail);
}

