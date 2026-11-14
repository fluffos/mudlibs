/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "obj/scroll";

int MyCast(string str) 
{
object wolf;
int dam;
  if (!str) wolf=GetEnemy(this_player());
  else wolf=present(str, environment(this_player()));
  if (!wolf) { write("That's not here.\n"); return CAST_FAIL_NOMSG; }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }
  if (wolf->QueryIsPlayer()) LogCast(this_player(),wolf);
  if (Repulse(wolf, this_player())) return CAST_REPULSE;
  Message( ({"An icestorm blows at "+wolf->QueryName()+"!\n",
          "An icestorm blows at "+wolf->QueryName()+".\n"}) );
  dam = random(50) + 2;
  dam=wolf->Defend(ModifyMagic(dam), DT_COLD, 0);
  if (wolf) Message(QueryCastDamage(dam,wolf));
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
  if (Repulse(this_player(),this_player())) return CAST_REPULSE;
  this_player()->SetSmell(this_player()->QueryName()+
        " smells of a fresh spring breeze.\n");
  Message(({"An icestorm blows you down to the ground.\n",
       "An icestorm blows at "+this_player()->QueryName()+".\n"}) );
  dam=random(50);
  dam=this_player()->Defend(ModifyMagic(dam), DT_COLD, 0);
  Message(QueryCastDamage(dam));
  return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("ice",ST_COLD,60,#'MyCast,"ice storm",15);
 SetSpellDesc(
"This spell will produce a freezing blast of cold which is shot at your\n\
opponent. It does a damage of up to 50 HP.\n");
 SetSpellUsage("cast ice <target>\n");
 SetMemoLevel(GC_SORCERER,9);
 SetMemoLevel(GC_ARCHMAGE,9);
 
 SetFailFn(#'MyFail);

 NoMemorize();
}

