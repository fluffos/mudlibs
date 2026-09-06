/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyCast(string str)
{
object ice, wolf, *enem;
  if (!str) wolf=GetEnemy(this_player());
  else wolf=present(str,environment(this_player()));
  if (!wolf) { write("That's not here.\n"); return CAST_FAIL_NOMSG; }
  if (wolf->id("shopkeeper")) {
     write("You can't cast it on a shopkeeper.\n");
     return CAST_FAIL_NOMSG;
  }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }
  Message(({"You freeze "+capitalize(wolf->QueryName())+"!\n",
      capitalize(wolf->QueryName())+" is frozen.\n"}));
  seteuid(getuid(this_object()));
  ice=clone_object(MAGIC_OBJ_DIR "icecube");
  ice->move(environment(this_player()));
  wolf->move(ice);
  ice->SelfDestruct(this_player()->QueryAttr("Sta")*30, wolf);
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
   if (Repulse(this_player(),this_player())) return CAST_REPULSE;
   Message("A strong cold wind blows in your face and hurts you.\n");
   dam=10+random(10);
   dam=this_player()->Defend(ModifyMagic(dam), DT_COLD, 0);
   Message(QueryCastDamage(dam));
   return CAST_SUCCESS;
}
void create() {
 ::create();
 AddSpell("icecube",ST_COLD,60,#'MyCast,"icecube",40);
 SetSpellDesc(
"This spell will create a huge icecube around your foe.\n");
 SetSpellUsage("cast icecube <target>\n");
 SetMemoLevel(GC_CONJURER,9);
 SetMemoLevel(GC_ARCHMAGE,9);
 SetFailFn(#'MyFail);
}

