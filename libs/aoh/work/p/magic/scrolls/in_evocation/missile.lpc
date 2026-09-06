/* Written by Softbyte 1995 */
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
  if (!wolf->QueryIsNPC() && !wolf->QueryIsPlayer()) {
     write("You can't cast it on that!\n");
     return CAST_FAIL_NOMSG;
  }
  if (wolf->QueryIsPlayer()) LogCast(this_player(),wolf); 
  if (Repulse(wolf, this_player())) return CAST_REPULSE;
  Message(
  ({"You shoot a magic missile at "+wolf->QueryName()+".\n",
    "A ray of energy is shot at "+wolf->QueryName()+".\n"}) );
  dam = random(50) + 1;
  dam=wolf->Defend(ModifyMagic(dam), DT_PSYCHO, 0);
  if (wolf) Message(QueryCastDamage(dam,wolf));
  return CAST_SUCCESS;
}

int MyFail() {
int dam;
  if (Repulse(this_player(),this_player())) return CAST_REPULSE;
  this_player()->SetSmell(this_player()->QueryName()+
        " smells of burned hair.\n");
  Message( ({"You get hit by a magic missile!\n",
    this_player()->QueryName()+" gets hit by a energy bolt.\n"}) );
  dam=random(40)+1;
  dam=this_player()->Defend(ModifyMagic(dam), DT_PSYCHO, 0);
  Message(QueryCastDamage(dam));
  return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("missile",ST_PSYCHO,25,#'MyCast,"magic missile",25);
 SetSpellDesc(
"This spell will shoot a missile of pure magic energy at your opponent\n\
doing up to 50 HP mental damage.\n");
 SetSpellUsage("cast missile <target>\n");
 SetMemoLevel(GC_SORCERER,7);
 SetMemoLevel(GC_ARCHMAGE,7);
 
 SetFailFn( #'MyFail);
}

