/* Written by Softbyte 1995 */
/* one of few conjurer attack spells, therefore low HP/SP ratio !!! */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
int dam;
object wolf;
  if (!str) wolf=GetEnemy(this_player());
  else wolf=present(str,environment(this_player()));
  if (!wolf) { write("That's not here.\n"); return CAST_FAIL_NOMSG; }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }
  if (wolf->QueryIsPlayer()) LogCast(this_player(),wolf); /* Aggressor */
  if (Repulse(wolf, this_player())) return CAST_REPULSE;
  Message(({"Some bubbling acid is splashed on "+wolf->QueryName()+"!\n",
    "Some bubbling acid is splashed on "+wolf->QueryName()+".\n"}));
  dam = random(50) + 20;
  dam=wolf->Defend(ModifyMagic(dam), DT_ACID, 0);
  if (wolf) Message(QueryCastDamage(dam,wolf));
  return CAST_SUCCESS;
}

int MyFail() {
int dam;
  if (Repulse(this_player(),this_player())) return CAST_REPULSE;
  Message( ({"You are burned by some acid.\n",
      this_player()->QueryName()+" splashes some acid onto "+
      this_player()->QueryPossessive()+" head.\n"}) );
  dam=20+random(20);
  dam=this_player()->Defend(ModifyMagic(dam), DT_ACID, 0);
  Message(QueryCastDamage(dam)); 
  return CAST_SUCCESS;
}

void create() {
 ::create();
 AddSpell("acid",ST_ACID,70,#'MyCast,"acid splash",40);
 SetSpellDesc(
"This spell will splash bubbling acid onto your opponent doing a damage of\n\
up to 70 HP acid damage.\n");
 SetSpellUsage("cast acid <target>\n");
 SetMemoLevel(GC_CONJURER,10);
 SetMemoLevel(GC_ARCHMAGE,10);
 SetFailFn(#'MyFail);
}

