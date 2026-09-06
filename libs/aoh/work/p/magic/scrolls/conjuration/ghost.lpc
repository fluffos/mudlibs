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
      write("You cannot use this spell with an argument.\n");
    return CAST_FAIL_NOMSG;
  }
  if (present("fellow",environment(this_player()))) {
     write("There is allready one fellow here!\n");
     return CAST_FAIL_NOMSG; 
  }
  Message( ({"You concentrate your mental forces and a small ghost materializes.\n",
     this_player()->QueryName()+" concentrates and a small ghost appears.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "elemental");
  wolf->SetRaceAndName("ghost", "ghost");
  wolf->SetLevelAndHPs(4,25,20);
  wolf->SetWCAndAC(5,10);
  wolf->SetHands(({ ({"left hand",0,5}),({"right hand",0,5}) }));
  wolf->SetStr(16);
  wolf->SetDex(16);
  wolf->SetShort("a ghost");
  wolf->SetLong("A small ghost that doesn't look too dangerous.\n");
  wolf->SetEPCost(4);
  call_other(wolf,"move",environment(this_player()));
  this_player()->command_me("own ghost");
  return CAST_SUCCESS;
}

int MyFail() {
     Message( ({"It starts to rain dead fish!\n",
         "It starts to rain dead fish!\n"}) );
     this_player()->SetSmell(this_player()->QueryName()+
          " smells of dead fish.\n");
     return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("ghost",ST_SUMMON,60,#'MyCast,"conjure ghost",30);
 SetSpellDesc(
"This spell will allow you to summon a small ghost.\n"+
"It will cost you some endurance points to keep it alive.\n"+
"You can give it a name with the 'name' command.\n"+
"'hit' it if you don't want it any longer.\n");
 SetSpellUsage("cast ghost\n");
 SetMemoLevel(GC_CONJURER,5);
 SetMemoLevel(GC_ARCHMAGE,5);
 
 SetFailFn(#'MyFail);
}

