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
  Message( ({"You materialize a heavenly blade.\n",
     this_player()->QueryName()+" materializes a sword out of thin air.\n"}) );
  seteuid(getuid(this_object()));
  cloak=clone_object(MAGIC_OBJ_DIR "heavensword");
  cloak->move(this_player());
  this_player()->command_me("wield sword");
  return CAST_SUCCESS;
}

int MyFail() 
{
  Message(({"It starts to rain dead fish! Urrgh! That fish seems to have died\n"+
      "some days ago!\n",
      "It starts to rain dead fish! Urrgh! That fish seems to have died\n"+
      "some days ago!\n"}) );
  this_player()->SetSmell(this_player()->QueryName()+
                 " smells of dead fish.\n");
  return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("blade",ST_CREATE,60,#'MyCast,"heavenly blade",20);
 SetSpellDesc(
"This spell creates a heavenly blade which is good against evil foes.\n");
 SetSpellUsage("cast blade\n");
 SetMemoLevel(GC_CONJURER,9);
 SetMemoLevel(GC_ARCHMAGE,9);
 SetFailFn(#'MyFail);
}

