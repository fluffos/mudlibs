/* Adapted and improved by Softbyte 1995 */
#include <combat.h>
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
  Message(({"You fetch a pipe from another dimension and light it.\n",
      this_player()->QueryName() + 
  " fetches something from another dimenstion.\n"}));
  Message(({"You take a deep drag from the pipe.\n",
      this_player()->QueryName()+" takes a deep drag from the pipe.\n"}));
  Message(({"The pipe vanishes.\n",
      "The pipe vanishes.\n"}));
  this_player()->SetAlcohol(
      this_player()->QueryAlcohol() + this_player()->QueryLevel());
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
    if (Repulse(this_player(),this_player(),DT_ZAP)) return CAST_REPULSE;
    Message(({"A huge fist appears and smashes you to the ground.\n",
        "A huge fist appears and smashes "+
    this_player()->QueryName()+" to the ground.\n"}) );
    dam=10+random(30);
    dam=this_player()->Defend(ModifyMagic(dam), DT_ZAP, 0);
    Message(QueryCastDamage(dam));
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("weed",ST_HEAL,50,#'MyCast,"Arfin's excellent pipe weed",70);
 SetSpellDesc(
"This spell will fetch a pipe and some pipe weed from another dimension.\n\
When you smoke the pipe you get intoxicated and your wounds heal faster.\n");
 SetSpellUsage("cast weed\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,4);
 SetMemoLevel(GC_ARCHMAGE,14);
 SetFailFn(#'MyFail);
}

