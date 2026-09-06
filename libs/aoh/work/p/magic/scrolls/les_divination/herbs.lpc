/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
  object wolf;
  if (!str)
  {
     write("What do you want to know?\n");
     return CAST_FAIL_NOMSG;
  }
  wolf=present(str,environment(this_player()));
  if (!wolf) wolf=present(str,this_player());
  if (!wolf) { write("That's not here.\n"); return CAST_FAIL_NOMSG; }
  if ((wolf->QueryIsNPC()) || (wolf->QueryIsPlayer())) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }
  Message(({"This is "+wolf->QueryHerb()+".\n",
      this_player()->QueryName()+" examines a herb.\n"}) );
  return CAST_SUCCESS;
}

int MyFail() {
     Message("This is a strong magic herb.\n");
     return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("herb",ST_KNOW,20,#'MyCast,"idendify herb",25);
 SetSpellDesc("This spell will show you the class of a herb.\n");
 SetSpellUsage("cast herb <target>\n");
 SetMemoLevel(GC_SORCERER,6);
 SetMemoLevel(GC_ARCHMAGE,6);
 
 SetFailFn(#'MyFail);
}

