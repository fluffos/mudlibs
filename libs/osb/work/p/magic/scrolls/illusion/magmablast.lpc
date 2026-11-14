/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";


int MyFail() {
int dam;
    if (Repulse(this_player(),this_player())) return CAST_REPULSE;
    Message(({"You get hit by a magma blast.\n",
         "Magma rises from the ground and hurts "+
	    this_player()->QueryName()+".\n"})); 
    dam=random(100)+50;
    dam=this_player()->Defend(ModifyMagic(dam), DT_FIRE, 0);
    Message(QueryCastDamage(dam));
    return CAST_SUCCESS;
}

void DoAttack(object mon) {
  int hit;
  if (mon && living(mon) && mon->QueryIsNPC()) 
  {
     if (Repulse(mon, this_player())) return;
     hit=ModifyMagic(random(200)+100);
     Message(({mon->QueryName()+" gets hit by hot magma.\n",
         "Magma rises from the ground and hurts "+
	    mon->QueryName()+".\n"})); 
     hit=mon->Defend(hit, DT_FIRE, 0);
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
  filter(this_player()->QueryEnemies(),#'DoAttack);
  return CAST_SUCCESS;
}

create() 
{
 ::create();
 AddSpell("blast",ST_FIRE,150,#'MyCast,"magma blast",60);
 SetSpellDesc(
"This spell throw hot magma at all monster that attack you. It\n\
will make a fire damage up to 300 hp.\n");
 SetSpellUsage("cast blast\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,20);
 SetMemoLevel(GC_ARCHMAGE,30);
 SetFailFn(#'MyFail);
}

