/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int QueryCost()
{
  return(130+2*this_player()->QueryLevel());
}

int MyFail() {
int dam;
    if (Repulse(this_player(),this_player())) return CAST_REPULSE;
    Message(({"You see green and red stars.\n",
        this_player()->QueryName()+" looks afraid.\n"}) );
    dam=random(this_player()->QueryLevel()*4)+10;
    dam=this_player()->Defend(ModifyMagic(dam), DT_PSYCHO, 0);
    Message(QueryCastDamage(dam));
    return CAST_SUCCESS;
}
void DoAttack(object mon) {
  int hit;
  if (mon && living(mon) && mon->QueryIsNPC()) 
  {
    if (Repulse(mon, this_player())) return;
    hit=ModifyMagic(random(this_player()->QueryLevel()*8)+
        this_player()->QueryLevel()*2);
    Message(({mon->QueryName()+" gets hit by a mind blade.\n",
        "A mind blade hits "+ mon->QueryName()+".\n"})); 
    hit=mon->Defend(hit, DT_PSYCHO, 0);
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
 AddSpell("mind",ST_PSYCHO,#'QueryCost,#'MyCast,"mind blade",50); 
 SetSpellDesc(
"This spell will produce a concentrated tide of mental energy\n\
that conjures every fear and devastates any opponents brain\n\
doing a mental damage of up to 10 * level HP. It will effect\n\
every monster in your surrounding.\n\
It costs 130 + 2 * level SP to cast it.\n");
 SetSpellUsage("cast mind\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,22);
 SetMemoLevel(GC_ARCHMAGE,32);
 SetFailFn(#'MyFail);
}
