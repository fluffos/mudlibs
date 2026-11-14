/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <moving.h>
inherit "obj/scroll";

int MyCast(string str) 
{
object cloak;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  Message( ({"You materialize Barill's Holy Avenger.\n",
     this_player()->QueryName()+" materializes a sword out of thin air.\n"}) );
  seteuid(getuid(this_object()));
  cloak=clone_object(MAGIC_OBJ_DIR "holyavenger");
  cloak->move(this_player(),M_SILENT);
  this_player()->command_me("wield avenger");
  return CAST_SUCCESS;
}

int MyFail()
{
  Message( ({"It starts to rain dead fish! Urrgh! That fish seems to have died\n"+
      "some days ago!\n",
      "It starts to rain dead fish! Urrgh! That fish seems to have died\n"+
      "some days ago!\n"}) );
  this_player()->SetSmell(this_player()->QueryName()+" smells of dead fish.\n");
  return CAST_SUCCESS;
}

create() {
 ::create();
 AddSpell("avenger",ST_CREATE,200,#'MyCast,"Barill's Holy Avenger",65);
 SetSpellDesc(
"This spell fetches Barill's Holy Avenger from another dimension. That sword\n\
may hit an evil opponent critically if you're lucky.\n");
 SetSpellUsage("cast avenger\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,1);
 SetMemoLevel(GC_ARCHMAGE,16);
 SetFailFn(#'MyFail);
}

