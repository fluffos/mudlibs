/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyFail() 
{
int dam;
    if (Repulse(this_player(),this_player())) return CAST_REPULSE;
    Message(({"You get hit by an glacier.\n",
        this_player()->QueryName()+" gets hit by a blue ray.\n"}) );
    dam=random(50)+30;
    dam=this_player()->Defend(ModifyMagic(dam), DT_COLD, 0);
    Message(QueryCastDamage(dam));
    return CAST_SUCCESS;
}
void DoAttack(object mon) {
  int hit;
  if (!mon) return;
  if ( mon && living(mon) && mon->QueryIsNPC()) 
  {
    if (Repulse(mon, this_player())) return;
    hit = ModifyMagic(random(48) + 203);
    Message( ({mon->QueryName() + " gets hit by a glacier strike ("+hit+").\n",
        "A cold blue light shoots from "+add_gen(this_player()->QueryName())+
	" fingers and hits "+mon->QueryName()+".\n"}) ); 
    hit=mon->Defend(hit, DT_COLD, 0);
  }
}

int MyCast(string str) {
  if (sizeof(this_player()->QueryEnemies()||({}))==0)
  {
    write("You have no enemies!\n");
    return CAST_FAIL_NOMSG;
  }
  filter(this_player()->QueryEnemies()||({}),#'DoAttack);
  return CAST_SUCCESS;
}

create() {
 ::create();
 AddSpell("glacier",ST_COLD,190,#'MyCast,"glacier strike",55);
 SetSpellDesc(
"This spell will make a cold damage up to 270 HP. It effects every\n\
monster that attackes you.\n");
 SetSpellUsage("cast glacier\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,16);
 SetMemoLevel(GC_ARCHMAGE,26);
 SetFailFn(#'MyFail);

 NoMemorize();
}

