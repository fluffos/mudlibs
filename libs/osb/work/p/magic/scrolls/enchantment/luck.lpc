/* Adapted and improved by Softbyte 1995 */
#include <moving.h>
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";
#define TP this_player()

int MyCast(string str) {
  object wolf;
  string name;
  if (!str) { write("Cast it on whom?\n"); return CAST_FAIL_NOMSG;}
  wolf=present(str,environment(TP));
  if (!wolf) { write("Cast it on whom?\n");  return CAST_FAIL_NOMSG;}
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
      write("You can't increase the luck of that!\n");
      return CAST_FAIL_NOMSG;
  }
  name=wolf->QueryName()||"someone";
  name=capitalize(name);
  Message(({"You increase "+add_gen(name)+" luck!\n",
     TP->QueryName()+" increases "+add_gen(name)+" luck.\n",
     ({wolf}),({TP->QueryName()+" increases your luck!\n"}) }) );
  wolf->ModifyAttr("Luk",90);
  return CAST_SUCCESS;
}
int MyFail()
{
  if (Repulse(TP,TP)) return CAST_REPULSE;
  Message(({"You decrease your luck!",
     TP->QueryName()+" decreases "+TP->QueryPossessive()+" luck.\n"}) );
  TP->ModifyAttr("Luk",-30);
  return CAST_SUCCESS;

}
create()
 {
 ::create();
 AddSpell("luck",ST_CHANGE,30,#'MyCast,"enchant luck",10);
 SetSpellDesc("This spell will increase someones luck.\n");
 SetSpellUsage("cast luck <person>\n");
 SetMemoLevel(GC_SORCERER,4);
 SetMemoLevel(GC_ARCHMAGE,4);
 
 SetFailFn(#'MyFail);
}

