/* Adapted and improved by Softbyte 1995 */
/* Multiple slows are allowed, so no check */

#include <magic.h>
#include <guild.h>
#include <moving.h>
inherit "/obj/scroll";
#define TP this_player()

private int cnt;

slowme(object wolf)
{
  cnt--;
  if (cnt<=0 || !wolf)
  {
    if (wolf) tell_room(environment(wolf),
      capitalize(wolf->QueryName()||"it")+" moves faster.\n");
    remove();
  }
  else
  { 
    wolf->SetCombatDelay(3,"You yawn loudly.\n");
    tell_room(environment(wolf),capitalize(wolf->QueryName()||"it")+
          " yawns.\n",({wolf}));
    call_out("slowme",15,wolf);
  }
}

int MyCast(string str) 
{
object wolf;
  if (!str) wolf=GetEnemy(TP);
  else wolf=present(str,environment(TP));
  if (!wolf) {
     write("That is not here!\n"); return CAST_FAIL_NOMSG; }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't make that slower!\n"); 
     return CAST_FAIL_NOMSG;
  }
  if (present("_xslow",TP))
  {
    write("The spell is still active.\n");
    return CAST_FAIL_NOMSG;
  }
 SetIds(({"_slow","_xslow"}));

  if (Repulse(wolf, TP)) return CAST_REPULSE;
  Message( ({wolf->QueryName()+" is a bit slower now!\n",
      wolf->QueryName()+" is a bit slower now!\n"}));
  cnt=TP->QueryAttr("Wis")/2;
  if (cnt<5) cnt=5;
  if (cnt>12) cnt=12;
  call_out("slowme",1,wolf);
  SetWeight(0);
  SetShort(0);
  ForbidCast();
  move(this_player(),M_NOCHECK);
  SetNoDrop();
  return CAST_SUCCESS;
}


int MyFail() {
  Message( ({"You yawn loudly.\n",
      TP->QueryName()+" yawns loudly.\n"}));
  remove();
  return CAST_SUCCESS;
}

create() 
{
 ::create();
 AddSpell("slow",ST_INFLUENCE,30,#'MyCast,"slow monster",15);
 SetSpellDesc(
"This spell will slow down a monster during combat for a short time.\n");
 SetSpellUsage("cast slow <foe>\n");
 SetMemoLevel(GC_CONJURER,10);
 SetMemoLevel(GC_ARCHMAGE,10);
 
 SetFailFn(#'MyFail);

 NoDestruct();
 cnt=0;
}
