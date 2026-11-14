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
  if (present("seeker", environment(this_player()))) {
     write("There is allready one seeker here!\n");
     return CAST_FAIL_NOMSG; 
  }
  Message( ({"You concentrate your mental forces and a seeker spirit materializes.\n",
     this_player()->QueryName()+" concentrates and a spirit appears.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "seeker");
  wolf->move(environment(this_player()));
  this_player()->command_me("own seeker");
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
    if (Repulse(this_player(),this_player(),ST_ZAP)) return 1;
    Message(({"A huge fist appears and smashes you to the ground.\n",
        "A huge fist appears and smashes " +
    this_player()->QueryName()+" to the ground.\n"}));
    dam=30+random(20);
    dam=this_player()->Defend(ModifyMagic(dam),DT_ZAP,0);
    Message(QueryCastDamage(dam));
    return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("seeker",ST_SUMMON,135,#'MyCast,"conjure seeker",50);
 SetSpellDesc(
"This spell will allow you to summon so called 'seeker'.\n"+
"You can ask the seeker to look for invisible objects and people.\n"+
"The commands are 'ask seeker' and 'quiet seeker'.\n"+
"It will cost you some endurance points to keep it alive.\n"+
"Type 'hit seeker' it if you don't want it any longer.\n");
 SetSpellUsage("cast seeker\n");
 SetMemoLevel(GC_CONJURER,13);
 SetMemoLevel(GC_ARCHMAGE,13);
 
 SetFailFn(#'MyFail);
}

