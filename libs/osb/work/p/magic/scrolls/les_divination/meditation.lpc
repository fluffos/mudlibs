/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";
#define TP this_player()

int MyCast(string str) 
{
int ep,mep;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  ep = TP->QueryAttr("EP");
  mep = TP->QueryAttr("MEP");
  if (sizeof(TP->QueryEnemies())>0) {
     write("You have to concentrate on the fight.\n");
     return CAST_FAIL_NOMSG;
  }
  Message(({"You meditate for a while.\n",
      TP->QueryName()+" meditates for a while.\n"}));
  ep += 50 +random(30);
  if (ep>mep) ep = mep;
  TP->SetAttr("EP", ep);  /* SetAttr is okay here */
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
   if (Repulse(TP,TP,ST_ZAP)) return CAST_REPULSE;
   Message(({"A big club appears and hits you hard!\n",
       "A big club appears and hits "+TP->QueryName()+
   " hard.\n"}) );
   dam=20;
   TP->Defend(ModifyMagic(dam),DT_ZAP,0);
   return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("meditation",ST_HEAL,40,#'MyCast,"meditation",10);
 SetSpellDesc(
"If you meditate it is like if you rest for a long while and you will\n\
restore up to 80 endurance points.\n\
You can't meditate while you fight.\n");
 SetSpellUsage("cast meditation\n");
 SetMemoLevel("allmage",8);
 SetFailFn(#'MyFail);
}

