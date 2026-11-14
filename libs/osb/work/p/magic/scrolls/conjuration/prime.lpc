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
  Message( ({"You concentrate your mental forces and a strom elemental materializes.\n",
     this_player()->QueryName()+" concentrates and a strom elemental appears.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "elemental");
  wolf->SetRaceAndName("elemental", "elemental");
  wolf->SetLevelAndHPs(25,250,200);
  wolf->SetWCAndAC(18,5);
  wolf->SetShort("a storm elemental");
  wolf->SetLong("A very dangerous storm elemental.\n");
  wolf->move(environment(this_player()));
  this_player()->command_me("own elemental");
  return CAST_SUCCESS;
}

int MyFail()
{
     Message(({"It starts to rain dead fish!\n",
         "It starts to rain dead fish!\n"}) );
     this_player()->SetSmell(this_player()->QuerySmell()+
         " smells of dead fish.\n");
     return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("prime",ST_SUMMON,200,#'MyCast,"prime summoning",80);
 SetSpellDesc(
"This spell will allow you to summon a dangerous elemental.\n"+
"It will cost you some endurance points to keep it alive.\n"+
"You can give it a name with the 'name' command.\n"+
"'hit' it if you don't want it any longer.\n");
 SetSpellUsage("cast prime\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,15);
 SetMemoLevel(GC_ARCHMAGE,25);
 SetFailFn(#'MyFail);
}

