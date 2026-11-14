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
  Message( ({"You materialize a sword.\n",
     this_player()->QueryName()+" materializes a sword out of thin air.\n"}) );
  seteuid(getuid(this_object()));
  cloak=clone_object(MAGIC_OBJ_DIR "hellsword");
  cloak->move(this_player());
  this_player()->command_me("wield sword");
  return CAST_SUCCESS;
}

int MyFail() 
{
    Message(({"It starts to rain dead cats.\n",
        "It starts to rain dead cats.\n"}));
    this_player()->SetSmell(this_player()->QueryName()+
        " smells as if he slept next to a dead cat.\n");
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("hellsword",ST_CREATE,65,#'MyCast,"sword of hell",40);
 SetSpellDesc(
"This spell creates a sword of hell which is good against good foes.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast hellsword\n");
 SetMemoLevel(GC_CONJURER,11);
 SetMemoLevel(GC_ARCHMAGE,11);
 
 SetFailFn(#'MyFail);
}

