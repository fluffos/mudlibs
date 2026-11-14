/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) {
  int ali;
  object wolf;
  string aliment;
  if (!str) 
  {
    write("Whose level do you want to know?\n");
    return CAST_FAIL_NOMSG;
  }
  wolf=present(str,environment(this_player()));
  if (!wolf) { write("That's not here.\n"); return CAST_FAIL_NOMSG; }
  if (!wolf->QueryIsNPC() && !wolf->QueryIsPlayer()) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }
  ali=wolf->QueryLevel();
  Message("The level of "+wolf->QueryName()+" is "+ali+".\n");
  return CAST_SUCCESS;
}

int MyFail() {
   Message("The level is "+random(30)+".\n");
   return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("level",ST_KNOW,20,#'MyCast,"know level",25);
 SetSpellDesc("This spell will show you the level of someone.\n");
 SetSpellUsage("cast level <target>\n");
 SetMemoLevel("allmage",7);
 SetFailFn(#'MyFail);

 NoMemorize();
}

