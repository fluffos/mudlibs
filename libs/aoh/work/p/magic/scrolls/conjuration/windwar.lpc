/* Adapted and improved by Softbyte 1995 */
#include <properties.h>
#include <magic.h>
#include <guild.h>
inherit "obj/scroll";
object wolf;

MyCast(str) 
{
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  if (present("warrior",environment(this_player()))) {
     write("There is allready one warrior here!\n");
     return CAST_FAIL_NOMSG;
   }
  Message( ({"You concentrate your mental forces and a wind warrior materializes.\n",
     this_player()->QueryName()+" concentrates and a wind warriro appears.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR+"warrior");
  call_other(wolf,"move",environment(this_player()));
  this_player()->command_me("own warrior");
  return CAST_SUCCESS;
}


create() 
{
::create();
 AddSpell("wind",ST_SUMMON,158,#'MyCast,"wind warrior",20);
 SetSpellDesc(
"This spell will allow you to summon a dangerous wind warrior.\n\
It will cost you some endurance points to keep it alive.\n\
You can give it a name with the 'name' command.\n");

 SetSpellUsage("cast wind\n");
 ForbidMemo("all");
 NoMemorize();
 NoSell();
}

