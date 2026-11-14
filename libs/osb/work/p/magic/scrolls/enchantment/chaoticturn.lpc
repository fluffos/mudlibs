/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyCast(string str)
{
object wolf;
int dam;
string s1,s2;
  if (!str) wolf = this_player();
  if (!wolf) wolf = present(str,environment(this_player()));
  if (!wolf) {
     write("That's not here.\n");
     return CAST_FAIL_NOMSG;
  }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't cast it on that!\n");
     return CAST_FAIL_MSG;
  }
  if (Repulse(wolf, this_player())) return CAST_REPULSE;
  dam=random(100) - 50;
  if (dam>0)
  {
    write("It took a turn for the worse.\n");
    if (wolf==this_player()) 
      s1="Your lifeforce is drained away.\n";
    else 
    {
      if (wolf->QueryIsPlayer()==1) LogCast(this_player(),wolf);
      s1=add_gen(capitalize((wolf->QueryName()||"someone")))+
         " lifeforce is drained away.\n";
    }
    s2=add_gen(capitalize((wolf->QueryName()||"someone")))+
         " lifeforce is drained away.\n";
    Message(({s1,s2}));
    dam=wolf->Defend(ModifyMagic(dam),DT_WATER,0);
    if (wolf) Message(QueryCastDamage(dam,wolf));
  }
  else
  {
    write("It took a turn for the better.\n");
    if (wolf==this_player()) 
      s1="Your lifeforce returns.\n";
    else 
      s1=capitalize((wolf->QueryName()||"someone"))+
         " is healed.\n";
    s2=capitalize((wolf->QueryName()||"someone"))+
         " is healed.\n";
    Message(({s1,s2}));
    wolf->HealHP(-dam+1);
  }
  return CAST_SUCCESS;
}

void create() 
{
 ::create();
 AddSpell("chaos",ST_HEAL,20,#'MyCast,"chaotic turn",0);
 SetSpellDesc(
"This spell will either heal or harm the target it is casted on.\n\
If you don't specify a target it will be casted on you.\n\
This spell has been invented by Don Juan.\n");
 SetSpellUsage("cast chaos <target>\n");
 SetMemoLevel(GC_SORCERER,12);
 SetMemoLevel(GC_ARCHMAGE,12);

 NoMemorize();
}

