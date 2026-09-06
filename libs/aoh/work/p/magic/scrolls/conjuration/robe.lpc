/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object cloak;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  Message( ({"You materialize a wizrobe.\n",
     this_player()->QueryName()+" materializes a wizrobe out of thin air.\n"}) );
  seteuid(getuid(this_object()));
  cloak=clone_object(MAGIC_OBJ_DIR "wizrobe");
  cloak->move(this_player());
  this_player()->command_me("wear robe");
  return CAST_SUCCESS;
}

int MyFail() {
  object cloak;
  seteuid(getuid(this_object()));
  cloak=clone_object("/d/woodland/common/obj/shit1");
  cloak->move(this_player());
  Message( ({"Something very different appears in your hand!\n",
      "A piece of shit appears in "+add_gen(this_player()->QueryName())+
      " hand.\n"}) );
  this_player()->SetSmell(this_player()->QueryName()+
      " smells of shit.\n");
  return CAST_SUCCESS;
}
create()
 {
 ::create();
 AddSpell("wizrobe",ST_CREATE,40,#'MyCast,"wizard's robe",15);
 SetSpellDesc(
"This spell creates a wizards' robe for you.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast wizrobe\n");
 SetMemoLevel(GC_CONJURER,3);
 SetMemoLevel(GC_ARCHMAGE,3);
 
 SetFailFn(#'MyFail);
}

