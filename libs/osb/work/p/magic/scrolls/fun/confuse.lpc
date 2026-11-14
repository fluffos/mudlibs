/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str)
{
object ice, wolf;
  if (!str)
  {
    write("Who should be confused?\n");
    return CAST_FAIL_NOMSG;
  }
  wolf=present(str,environment(this_player()));
  if (!wolf) { write("That's not here.\n"); return CAST_FAIL_NOMSG; }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }
  if (Repulse(wolf, this_player())) return CAST_REPULSE;
  Message(({"You confuse "+capitalize(wolf->QueryName())+"!\n",
      capitalize(wolf->QueryName())+" is confused.\n",
      ({wolf}),({"You feel confused.\n"}) }) );
  seteuid(getuid(this_object()));
  ice = clone_object(MAGIC_OBJ_DIR "confuser");
  ice->move(wolf);
  return CAST_SUCCESS;
}

int MyFail() 
{
   return MyCast(this_player()->QueryRealName());
}
create()
{
 ::create();
 AddSpell("confuse",ST_INFLUENCE,55,#'MyCast,"confusion",35);
 SetSpellDesc(
"This spell will confuse a player. He/she will run in other directions\n\
as he/she has typed for a few minutes.\n");
 SetSpellUsage("cast confuse <target>\n");
 SetMemoLevel(GC_SORCERER,6);
 SetMemoLevel(GC_ARCHMAGE,6);
 SetFailFn(#'MyFail);

 NoMemorize();
}

