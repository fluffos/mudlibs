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
  Message( ({"You concentrate your mental forces and a black mage materializes.\n",
     this_player()->QueryName()+" concentrates and a black mage appears.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "blackmage");
  wolf->move(environment(this_player()));
  this_player()->command_me("own mage");
  return 1;
}

int MyFail() {
int dam;
   if (Repulse(this_player(),this_player(),ST_PSYCHO)) return CAST_REPULSE;
   Message( ({"A huge gauntlet appears and hits you down.\n",
       "A huge gauntlet appears and hits "+this_player()->QueryName()+".\n"}) );
   dam=20+random(50);
   dam=this_player()->Defend(ModifyMagic(dam),DT_PSYCHO,0);
   Message(QueryCastDamage(dam));
   return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("mage",ST_SUMMON,125,#'MyCast,"conjure black mage",60);
 SetSpellDesc(
"This spell will allow you to summon a black mage.\n"+
"This mage can not only fight, but also cast some spells.\n"+
"It will cost you some endurance points to keep it alive.\n"+
"You can give it a name with the 'name' command.\n"+
"'hit' it if you don't want it any longer.\n");
 SetSpellUsage("cast mage\n");
 SetMemoLevel(GC_CONJURER,16);
 SetMemoLevel(GC_ARCHMAGE,16);
 
 SetFailFn(#'MyFail);

 NoMemorize();
}

