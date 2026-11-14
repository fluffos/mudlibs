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
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_OBJ_DIR "carp");
  if (!wolf) return CAST_FAIL_MSG;
  call_other(wolf,"move",environment(this_player()));
  if (environment(wolf)!=environment(this_player())) return CAST_FAIL_MSG;
  this_player()->move(wolf,M_GO);
  Message(({"You sit down on the flying carpet.\n",
      this_player()->QueryName()+" sits down on a flying carpet.\n"}));
  return CAST_SUCCESS;
}

int MyFail() 
{
  tell_room(environment(this_player()),"There is a loud >>>POOOF<<<");
  return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("levi",ST_CREATE,90,#'MyCast,"Major Levitation",80);
 SetSpellDesc(
"This spell will fetch a flying carpet from another dimension. As long as\n\
you sit on the carpet no monster can attack you. You can also fly over traps\n\
or cross an abyss with this spell.\n");
 SetSpellUsage("cast levi\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,19);
 SetMemoLevel(GC_ARCHMAGE,29);
 SetFailFn(#'MyFail);
}

