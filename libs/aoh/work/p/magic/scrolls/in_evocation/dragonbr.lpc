/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyFail() {
int dam;
    if (Repulse(this_player(),this_player())) return CAST_REPULSE;
    Message(({"You get hit by a hot fire.\n",
        this_player()->QueryName()+" gets hit by a dragon fire.\n"}) );
    dam=random(90)+70;
    dam=this_player()->Defend(ModifyMagic(dam), DT_FIRE, 0);
    Message(QueryCastDamage(dam));
    return CAST_SUCCESS;
}
void DoAttack(object mon) {
  int hit;
  string name;
  if (mon && living(mon) && mon->QueryIsNPC()) {
        if (Repulse(mon, this_player())) return;
	hit=ModifyMagic(random(90)+70);
	name=capitalize(mon->QueryName());
	Message(({name+" gets hit by a dragon fire ("+hit+").\n",
	    this_player()->QueryName()+
	    " breathes dragon fire at "+name+".\n"})); 
        hit=mon->Defend(hit, DT_FIRE, 0);
  }
}

int MyCast(string str) {
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
 AddSpell("breath",ST_FIRE,100,#'MyCast,"dragon's breath",60);
 SetSpellDesc(
"This spell will blow a cloud of dragon fire at your opponents\n\
making a damage up to 160 HP fire damage. It effects every monster\n\
around you.\n");
 SetSpellUsage("cast breath\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,13);
 SetMemoLevel(GC_ARCHMAGE,23);
 SetFailFn(#'MyFail);
}

