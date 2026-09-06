/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object wolf;
int dam;
  if (!str) wolf=GetEnemy(this_player());
  else wolf=present(str,environment(this_player()));
  if (!wolf) { write("That's not here.\n"); return CAST_FAIL_NOMSG; }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }
  if (wolf->QueryIsPlayer()) LogCast(this_player(),wolf);
  if (Repulse(wolf, this_player())) return CAST_REPULSE;
  Message( ({ "Death seems to touch "+wolf->QueryName()+"!\n",
     "Death seems to touch "+wolf->QueryName()+".\n"}) );
  dam = random(20) + 80;
  dam=wolf->Defend(ModifyMagic(dam), DT_ZAP, 0);
  if (wolf) Message(QueryCastDamage(dam,wolf));
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
  if (Repulse(this_player(),this_player())) return CAST_REPULSE;
  Message( ({"Death appears and touches you.\n",
      "Death appears and touches "+this_player()->QueryName()+".\n"}) );
  dam=50;
  this_player()->Defend(ModifyMagic(dam), DT_ZAP, 0);
  Message(QueryCastDamage(dam));
  return CAST_SUCCESS;
}
void create()
{
 ::create();
 AddSpell("touch",ST_ZAP,65,#'MyCast,"spectre touch",45);
 SetSpellDesc(
"This spell will try to kill an enemy by doing a damage of 80-100 hp.\n");
 SetSpellUsage("cast touch <target>\n");
 SetMemoLevel(GC_SORCERER,17);
 SetMemoLevel(GC_NECROMANCER,17);
 SetMemoLevel(GC_ARCHMAGE,17);
 
 SetFailFn(#'MyFail);
}

