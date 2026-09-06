/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include "/d/woodland/sys/woodland.h"
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
  Message( ({"You materialize a conjurer staff out.\n",
     this_player()->QueryName()+" materializes a staff out of thin air.\n"}) );
  seteuid(getuid(this_object()));
  cloak=clone_object(MAGIC_OBJ_DIR "conjurerstaff");
  cloak->move(this_player());
  this_player()->command_me("wield staff");
  return CAST_SUCCESS;
}

int MyFail() 
{
object cloak;
  Message(({"Something very different appears in your hands.\n",
      "A piece of shit appears in "+this_player()->QueryName()+"'s hands.\n"}));
  seteuid(getuid(this_object()));
  cloak=clone_object(OBJ("shit2"));
  cloak->move(this_player());
  this_player()->SetSmell(this_player()->QueryName()+
        " smells of shit.\n");
  return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("staff",ST_CREATE,75,#'MyCast,"conjurer staff",55);
 SetSpellDesc(
"This spell creates a conjurer staff.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast staff\n");
 SetMemoLevel(GC_CONJURER,12);
 SetMemoLevel(GC_ARCHMAGE,12);
 
 SetFailFn(#'MyFail);
}

