/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";


int MyFail() {
int dam;
    if (Repulse(this_player(),this_player())) return CAST_REPULSE;
    Message(({"You get hit by a huge iceball.\n",
        this_player()->QueryName()+" gets hit by a huge iceball.\n"}) );
    dam=random(40)+10;
    dam=this_player()->Defend(ModifyMagic(dam), DT_COLD, 0);
    Message(QueryCastDamage(dam));
    return CAST_SUCCESS;
}
void DoAttack(object mon) {
  int hit;
  if (mon && living(mon) && mon->QueryIsNPC()) 
  {
    if (Repulse(mon, this_player())) return;
    hit=ModifyMagic(random(60)+50);
    Message(mon->QueryName()+" gets hit by a frostforce ("+hit+").\n",
        "A cold blue light shoots from "+add_gen(this_player()->QueryName())+
        " fingers and hits "+mon->QueryName()+".\n"); 
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
 AddSpell("frost",ST_COLD,85,#'MyCast,"frost force",40);
 SetSpellDesc(
"This spell will shoot rays of cold blue light at all monsters in\n\
your environment doing a cold damage of up to 80 HP.\n"); 
 SetSpellUsage("cast frost\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,11);
 SetMemoLevel(GC_ARCHMAGE,21);
 SetFailFn(#'MyFail);
}

