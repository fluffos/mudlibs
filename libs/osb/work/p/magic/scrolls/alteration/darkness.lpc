/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
  object dark;
  if (str)
  {
    write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  Message( ({"Suddenly it's getting very dark!\n",
      "Suddenly it's getting very dark!\n"}) );
  seteuid(getuid(this_object()));
  dark=clone_object(MAGIC_OBJ_DIR "dark");
  dark->move(environment(this_player()));
  return CAST_SUCCESS;
}

int MyFail() {
   object lig;
   Message( ({"Suddenly it's getting very bright!\n",
       "Suddenly it's getting very bright!\n"}) );
   lig = clone_object(MAGIC_OBJ_DIR "bright");
   lig->move(environment(this_player()));
   return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("darkness",ST_LIGHT,30,#'MyCast,"darkness",25);
 SetSpellDesc(
"With this spell you can create a dark magical aura around your\n"+
"current location, which prevents light from entering the room.\n");
 SetSpellUsage("cast darkness\n");
 SetMemoLevel(GC_CONJURER,4);
 SetMemoLevel(GC_ARCHMAGE,4);
 SetFailFn(#'MyFail);
}

