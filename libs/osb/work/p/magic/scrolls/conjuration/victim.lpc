/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include "/d/woodland/sys/woodland.h"
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
  if (present("fellow", environment(this_player()))) {
     write("There is allready one fellow here!\n");
     return CAST_FAIL_NOMSG; 
  }
  Message( ({"You concentrate your mental forces and a small spirit materializes.\n",
     this_player()->QueryName()+" concentrates and a small spirit appears.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "victim");
  wolf->move(environment(this_player()));
  this_player()->command_me("own victim");
  return CAST_SUCCESS;
}

int MyFail() {
  object troll;
  if (Repulse(this_player(),this_player())) return CAST_REPULSE;
  seteuid(getuid(this_object()));
  troll=clone_object(MONSTER("troll"));
  troll->move(environment(this_player()));
  Message( ({"A troll appears in a puff of smoke.\n",
        "A troll appears in a puff of smoke.\n"}) );
  return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("victim",ST_SUMMON,80,#'MyCast,"conjure victim",50);
 SetSpellDesc(
"This spell will allow you to summon a 'victim'.\n"+
"Every enemy will stop attacking you and will attack the victim.\n"+
"It will cost you some endurance points to keep it alive.\n"+
"'hit' it if you don't want it any longer.\n");
 SetSpellUsage("cast victim\n");
 SetMemoLevel(GC_CONJURER,11);
 SetMemoLevel(GC_ARCHMAGE,11);
 
 SetFailFn(#'MyFail);
}

