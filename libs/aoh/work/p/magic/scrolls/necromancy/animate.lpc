/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include "/d/woodland/sys/woodland.h"
inherit "/obj/scroll";

int MyCast(string str) 
{
  object wolf, corp;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  if (present("zombie", environment(this_player()))) {
     write("There is already one zombie here!\n");
     return CAST_FAIL_NOMSG; 
  }
  if (!present("corpse", environment(this_player()))) {
     write("You'll need a corpse!\n"); 
     return CAST_FAIL_NOMSG;
  }
  Message( ({"You revive a corpse.\n",
             this_player()->QueryName()+" revives a corpse.\n"}) );
  corp=present("corpse", environment(this_player()));
  corp->remove();
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "zombie");
  call_other(wolf,"move",environment(this_player()));
  this_player()->command_me("own zombie");
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

create() 
{
 ::create();
 AddSpell("animate",ST_SUMMON,130,#'MyCast,"animate dead",80);
 SetSpellDesc(
"This spell will allow you to make a zombie out of a corpse.\n"+
"You'll need a dead corpse to cast this spell.\n"+
"It will cost you some endurance points to keep it alive.\n"+
"You can give it a name with the 'name' command.\n"+
"'hit' it if you don't want it any longer.\n");
 SetSpellUsage("cast animate\n");
 SetMemoLevel(GC_CONJURER,19);
 SetMemoLevel(GC_ARCHMAGE,19);
 SetMemoLevel(GC_NECROMANCER,17);
 SetFailFn(#'MyFail);
}

