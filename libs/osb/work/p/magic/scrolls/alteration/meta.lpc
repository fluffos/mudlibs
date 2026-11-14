/* Adapted and improved by Softbyte 1995 */
#include <moving.h>
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object wolf;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  Message( ({"You morph into a bird.\n",
      "There is a loud shriek. You can't see "+
      this_player()->QueryName()+" anymore.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "bat");
  wolf->move(environment(this_player()));
  this_player()->move(wolf,M_SILENT);
  return CAST_SUCCESS;
}

int MyFail() 
{
  tell_room(environment(this_player()),"There is a loud >>>POOOF<<<\n");
  return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("morph",ST_CHANGE,85,#'MyCast,"metamorphosis",40);
 SetSpellDesc(
"This spell will allow you to morph into a bird. Type land, if you\n"+
"don't want to fly anymore.\n");
 SetSpellUsage("cast morph\n");
 SetMemoLevel(GC_CONJURER,12);
 SetMemoLevel(GC_ARCHMAGE,12);
 
 SetFailFn(#'MyFail);
}

