/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object cloak;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  Message( ({"You materialize a Hammer of Thunder.\n",
     this_player()->QueryName()+" materializes a weapon out of thin air.\n"}) );
  seteuid(getuid(this_object()));
  cloak=clone_object(MAGIC_OBJ_DIR "thunderhammer");
  cloak->move(this_player());
  this_player()->command_me("wield hammer");
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
create() 
{
 ::create();
 AddSpell("thunder",ST_CREATE,60,#'MyCast,"Hammer of Thunder",25);
 SetSpellDesc(
"This spell creates the Hammer of Thunder with which you can fire up\n\
to five lightningbolts by typing 'fire'.\n");
 SetSpellUsage("cast thunder\n");
 SetMemoLevel(GC_CONJURER,3);
 SetMemoLevel(GC_ARCHMAGE,3);
 
 SetFailFn(#'MyFail);
}

