/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
  object wolf;
  int ali;
  string aliment;
  if (!str) 
  {
    write("Whose alignement ?\n");
    return CAST_FAIL_NOMSG; 
  }
  wolf=present(str,environment(this_player()));
  if (!wolf) { write("That's not here.\n"); return CAST_FAIL_NOMSG; }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }
  ali=wolf->QueryAlign();
  aliment=this_player()->QueryAlignString(ali);
  Message("The alignment of "+wolf->QueryName()+" is "+aliment+".\n");
  return CAST_SUCCESS;
}

int MyFail() {
     Message("Its alignment is somewhat nasty.\n");
     return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("align",ST_KNOW,5,#'MyCast,"know alignment",15);
 SetSpellDesc("This spell will show you the alignment of someone.\n");
 SetSpellUsage("cast align <target>\n");
 SetMemoLevel("allmage",5);
 SetFailFn(#'MyFail);

 NoMemorize();
}

