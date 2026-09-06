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
  if (present("wolf", environment(this_player()))) {
     write("There is allready one wolf here!\n");
     return CAST_FAIL_NOMSG; 
  }
  Message( ({"You concentrate your mental forces and a wolf materializes.\n",
     this_player()->QueryName()+" concentrates and a wolf appears.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "wolf");
  wolf->move(environment(this_player()));
  this_player()->command_me("own wolf");
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
    if (Repulse(this_player(),this_player(),ST_PSYCHO)) return CAST_REPULSE;
    Message(({"A huge wolf appears and bites you into your leg.\n",
        "A huge wolf appears and bites "+this_player()->QueryName()+
	" in "+this_player()->QueryPossessive()+" leg.\n"}));
    dam=20;
    dam=this_player()->Defend(ModifyMagic(dam),DT_PSYCHO,0);
    Message(QueryCastDamage(dam));
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("wolf",ST_SUMMON,148,#'MyCast,"instant wolf",20); 
 SetSpellDesc(
"This spell will allow you to summon a huge wolf.\n"+
"It will cost you some endurance points to keep it alive.\n"+
"You can give it a name with the 'name' command.\n"+
"'hit' it if you don't want it any longer.\n");
 SetSpellUsage("cast wolf\n");
 ForbidMemo("all"); 
 SetFailFn(#'MyFail);

 NoSell();
 NoMemorize();
}

