/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyCast(string str) {
  object ob;
  if (str)
  { 
    write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  ob=present("spellbook", this_player());
  if (!ob) {write("You don't have a spellbook.\n"); return CAST_FAIL_NOMSG;}
  /* message is in spellbook */
  ob->darkness(this_player()->QueryLevel()*50);
  return CAST_SUCCESS;
}

int MyFail() {
int dam;
   if (Repulse(this_player(),this_player(),ST_FIRE)) return CAST_REPULSE;
   this_player()->SetSmell(this_player()->QueryName()+
          " smells of burned flesh.\n");
   Message( ({"You get hit by an arcfire!\n",
     "An arcfire hits "+this_player()->QueryName()+".\n"}) );
   dam=1+random(3);
   dam=this_player()->Defend(ModifyMagic(dam), DT_FIRE, 0);
   Message(QueryCastDamage(dam));
   return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("orb",ST_LIGHT,5,#'MyCast,"orb of darkness",15);
 SetSpellDesc("This spell will make your spellbook shed darkness.\n");
 SetSpellUsage("cast orb\n");
 SetMemoLevel("allmage",1);
 SetFailFn(#'MyFail);
}

