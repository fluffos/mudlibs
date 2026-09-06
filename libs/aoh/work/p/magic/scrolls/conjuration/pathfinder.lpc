/* Adapted and improved by Softbyte 1995 */
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
  if (present("fellow",environment(this_player()))) {
     write("There is allready one fellow here!\n");
     return CAST_FAIL_NOMSG;
  }
  Message( ({"You summon a small pathfinder imp.\n",
     this_player()->QueryName()+" summons a small imp.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "imp");
  wolf->set_fellow(this_player());
  wolf->move(environment(this_player()));
  return CAST_SUCCESS;
}

create() 
{
 ::create();
 AddSpell("finder",ST_SUMMON,190,#'MyCast,"pathfinder",30);
 SetSpellDesc(
"This spell will allow you to summon a small imp called Pathfinder.\n\
Pathfinder can help you finding the way through difficult mazes.\n\
It will cost you some endurance points to keep him alive.\n");
 SetSpellUsage("cast finder\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,14);
 SetMemoLevel(GC_ARCHMAGE,24);
}

