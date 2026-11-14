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
  if (present("fellow", environment(this_player()))) {
     write("There is allready one fellow here!\n");
     return CAST_FAIL_NOMSG; 
  }

  Message( ({"You concentrate your mental forces and a fire elemental materializes.\n",
     this_player()->QueryName()+" concentrates and a fire elemental appears.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "elemental");
  wolf->move(environment(this_player()));
  wolf->SetDex(20);
  wolf->SetStr(20);
  this_player()->command_me("own elemental");
  return CAST_SUCCESS;
}

int MyFail() {
    Message( ({"A butterfly appears and lands on your nose.\n",
        "A butterfly appears and lands on "+this_player()->QueryName()+
	"'s nose.\n"}) );
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("elemental",ST_SUMMON,160,#'MyCast,"conjure elemental",60);
 SetSpellDesc(
"This spell will allow you to summon a fire elemental.\n"+
"It will cost you some endurance points to keep it alive.\n"+
"You can give it a name with the 'name' command.\n"+
"'hit' it if you don't want it any longer.\n");
 SetSpellUsage("cast elemental\n");
 SetMemoLevel(GC_CONJURER,17);
 SetMemoLevel(GC_ARCHMAGE,17);
 SetFailFn(#'MyFail);
}

