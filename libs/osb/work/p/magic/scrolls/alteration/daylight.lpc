/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <properties.h>
inherit "obj/scroll";

MyCast(str) 
{
object lig;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  Message(({"You conjure some daylight.\n",
      "Suddenly there seems to be some daylight.\n"}));
  lig = clone_object(MAGIC_OBJ_DIR "bright");
  lig->move(environment(this_player()));
  return CAST_SUCCESS;
}

MyFail() {
   object dark;
   Message(({"Suddenly it's getting very dark!\n",
       "Suddenly it's getting very dark!\n"}) );
   dark=clone_object(MAGIC_OBJ_DIR "dark");
   dark->move(environment(this_player()));
   return CAST_SUCCESS;
}


create() 
{
 ::create();
 AddSpell("daylight",ST_LIGHT,30,#'MyCast,"daylight",25); 
 SetSpellDesc(
"With this spell you can create a magical aura around your\n\
current location, which shines light.\n");
 SetSpellUsage("cast daylight\n");
 SetMemoLevel(GC_CONJURER,6);
 SetMemoLevel(GC_SORCERER,6);
 SetFailFn(#'MyFail);
 seteuid(getuid());
}

