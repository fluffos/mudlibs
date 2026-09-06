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
  Message( ({"You materialize a plate mail.\n",
     this_player()->QueryName()+" materializes a plate mail out of thin air.\n"}) );
  seteuid(getuid(this_object()));
  cloak=clone_object(MAGIC_OBJ_DIR "wizarmour");
  cloak->move(this_player());
  this_player()->command_me("wear mail");
  return CAST_SUCCESS;
}

int MyFail() 
{
object cloak;
  seteuid(getuid(this_object()));
  cloak=clone_object("/d/woodland/common/obj/rose");
  cloak->move(this_player());
  Message( ({"A flower appears in your hands.\n",
     this_player()->QueryName()+" materializes a rose out of thin air.\n"}) );
  return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("wizplate",ST_CREATE,60,#'MyCast,"wizard's plate mail",40);
 SetSpellDesc(
"This spell create a wizard's plate mail for you.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast wizplate\n");
 SetMemoLevel(GC_CONJURER,6);
 SetMemoLevel(GC_ARCHMAGE,6);
 
 SetFailFn(#'MyFail);
}

