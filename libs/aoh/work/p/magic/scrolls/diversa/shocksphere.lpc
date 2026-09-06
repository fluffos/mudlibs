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
  Message( ({"A shock sphere hits "+wolf->QueryName()+"!\n",
       capitalize(wolf->QueryName())+" is shocked.\n"}) );
  dam = random(10) + 12;
  dam=wolf->Defend(ModifyMagic(dam), DT_PSYCHO, 0);
  if (wolf) Message(QueryCastDamage(dam,wolf));
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
  if (Repulse(this_player(),this_player())) return CAST_REPULSE;
  Message(({"You are shocked!\n",
      this_player()->QueryName()+" is shocked.\n"}) );
  dam=random(15)+2;
  dam=this_player()->Defend(ModifyMagic(dam), DT_PSYCHO, 0);
  Message(QueryCastDamage(dam));
  return CAST_SUCCESS;
}

create() 
{
 ::create();
 AddSpell("shock",ST_PSYCHO,20,#'MyCast,"shock shere",5);
 SetSpellDesc(
"This spell will deliver a mental shock to your opponent doing a damage\n\
of up to 20 HP mental damage.\n");
 SetSpellUsage("cast shock <target>\n");
 SetMemoLevel(GC_SORCERER,3);
 SetMemoLevel(GC_ARCHMAGE,3);
 
 SetFailFn(#'MyFail);
}

