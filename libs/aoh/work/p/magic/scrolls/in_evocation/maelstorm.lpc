/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyFail() {
int dam;
   if (Repulse(this_player(),this_player())) return CAST_REPULSE;
   Message(({"A mealstorm blows you down to the ground.\n",
       "A maelstorm blows at "+this_player()->QueryName()+".\n"}));
   dam=random(100)+50;
   dam=this_player()->Defend(ModifyMagic(dam), DT_COLD, 0);
   Message(QueryCastDamage(dam));
   return CAST_SUCCESS;
}
void DoAttack(object mon) {
  int hit;
  if (mon && living(mon) && mon->QueryIsNPC()) 
  {
    if (Repulse(mon, this_player())) return;
    hit=ModifyMagic(random(230)+20);
    Message(({mon->QueryName()+
       " is torn into pieces by a maelstorm.\n",
        this_player()->QueryName()+
	    " breathes a maelstorm at "+mon->QueryName()+".\n"})); 
    hit=mon->Defend(hit, DT_COLD, 0);
    if (mon) Message(QueryCastDamage(hit,mon));
  }
}

int MyCast(string str) 
{
  if (str)
  {
   if (str!=this_player()->QueryName())
   {
      write("You cannot use an argument with this spell.\n");
      return CAST_FAIL_NOMSG;
   }
   else
   {
     MyFail();
     return CAST_SUCCESS;
   }
  }
  filter(all_inventory(environment(this_player())),#'DoAttack);
  return CAST_SUCCESS;
}

create()
{
 ::create();
 AddSpell("storm",ST_WATER,140,#'MyCast,"maelstorm",30); 
 SetSpellDesc(
"This spell will create a minature thunderstorm which is whipping\n\
and blasting all monsters around you. It does a water damage of up\n\
to 250 HP.\n");
 SetSpellUsage("cast storm\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,14);
 SetMemoLevel(GC_ARCHMAGE,24);
 SetFailFn(#'MyFail);
}

