/* Written by Softbyte August 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";
#define TP this_player()

int MyCast(string str) 
{
int amount;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  if (sizeof(TP->QueryEnemies())>0) {
     write("You have to concentrate on the fight.\n");
     return CAST_FAIL_NOMSG;
  }
  Message(({"You concentrate very hard and increase your astral energy.\n",
      TP->QueryName()+" looks exhausted.\n"}));
  amount=50;
  TP->DoDamage(amount);
  TP->HealSP(amount-5);
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
   if (Repulse(TP,TP,ST_PSYCHO)) return CAST_REPULSE;
   Message(({"You cannot concentrate and loose some life energy.\n",
      TP->QueryName()+" looks exhausted.\n"}));
   dam=20;
   dam=TP->Defend(ModifyMagic(dam),DT_PSYCHO,0);
   return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("concentration",ST_HEAL,5,#'MyCast,"astral concentration",50);
 SetSpellDesc(
"When casting this spell you concentrate very hard and you\n\
will transfer life energy (50 HP) into astral energy (45 SP).\n\
You can't cast that spell when fighting.\n");
 SetSpellUsage("cast concentration\n");
 SetMemoLevel("allmage",11);
 SetFailFn(#'MyFail);
}

