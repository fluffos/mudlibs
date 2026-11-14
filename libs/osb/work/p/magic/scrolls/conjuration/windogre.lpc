/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) {
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
  Message( ({"You concentrate your mental forces and a wind ogre materializes.\n",
     this_player()->QueryName()+" concentrates and a wind ogre appears.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "elemental");
  wolf->SetRaceAndName("wind ogre", "ogre");
  wolf->SetLevelAndHPs(8,80,80);
  wolf->SetWCAndAC(12,12);
  wolf->SetDex(15);
  wolf->SetStr(15);
  wolf->SetHands(({ ({"left hand",0,12}),({"right hand",0,12}) }));
  wolf->SetShort("an ogre");
  wolf->SetLong("A wind ogre that looks not too dangerous.\n");
  wolf->SetEPCost(5);
  wolf->move(environment(this_player()));
  this_player()->command_me("own ogre");
  return CAST_SUCCESS;
}

int MyFail() {
   object dragon;
  seteuid(getuid(this_object()));
   Message( ({"A huge dragon appears in a puff of smoke.\n",
       "A huge dragon appears in a puff of smoke.\n"}) );
   dragon=clone_object("/d/woodland/common/monster/joern/dragon");
   dragon->move(environment(this_player()));
   return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("ogre",ST_SUMMON,65,#'MyCast,"conjure wind ogre",35);
 SetSpellDesc(
"This spell will allow you to summon a small wind ogre.\n"+
"It will cost you some endurance points to keep it alive.\n"+
"You can give it a name with the 'name' command.\n"+
"'hit' it if you don't want it any longer.\n");
 SetSpellUsage("cast ogre\n");
 SetMemoLevel(GC_CONJURER,7);
 SetMemoLevel(GC_ARCHMAGE,7);
 
 SetFailFn(#'MyFail);

 NoMemorize();
}

