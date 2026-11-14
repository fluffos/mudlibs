/* Rust weapon - rewritten by Softbyte 4.6.95 */
/* Adapted and improved by Softbyte 1995 */

#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";
#define TP this_player()


int MyCast(string str) 
{
  object *wps,weapon;
  object whom;
  int howmuch;

  if (!str) whom=GetEnemy(TP);
  whom=present(str,environment(TP));
  if (!whom) 
    {write("I can't see that monster here!\n"); return CAST_FAIL_NOMSG; }
  if (!whom->QueryIsNPC() && !whom->QueryIsPlayer() )
  {
    write("You cannot cast the spell on that.\n");
    return CAST_FAIL_NOMSG;
  }
  wps=whom->QueryWeapons();
  if (!wps || !sizeof(wps)) 
  {
     write(capitalize(whom->QueryShort())+" has no weapons.\n");
     return CAST_FAIL_NOMSG;
  }
  weapon=wps[random(sizeof(wps))];
  if (!weapon) {write("Try again !\n");return CAST_FAIL_NOMSG; }
  if ( weapon->QueryWC()<1 )
  {
    write("You cannot make "+weapon->QueryShort()+" rusty.\n");
    return CAST_FAIL_NOMSG;
  } 
  if (Repulse(whom,TP)) return CAST_REPULSE;
  howmuch=20+TP->QueryInt()+random(15);
  weapon->SetQuality(weapon->QueryQuality()-howmuch);
  weapon->Set("rusting");
  Message(({"You let "+weapon->QueryShort()+" rust.\n",
      TP->QueryName()+" has let "+weapon->QueryShort()+" of "+
       whom->QueryShort()+" rust.\n"}));
  return CAST_SUCCESS;
}

MyFail() 
{
int dam;
    if (Repulse(TP,TP,ST_FIRE)) return CAST_REPULSE;
    Message(({"Your weapons starts to glow. You get burned.\n",
        add_gen(TP->QueryName())+" weapons starts to burn.\n"}));
    dam=10+random(15);
    dam=TP->Defend(ModifyMagic(dam),DT_FIRE,0);
    TP->SetSmell(TP->QueryName()+ " smells of burned flesh.\n");
    Message(QueryCastDamage(dam));
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("wrust",ST_CHANGE,55,#'MyCast,"rust weapon",25);
 SetSpellDesc(
"This spell will make a monsters weapon rust by decreasing the\n\
quality of their weapons depending on your INT.\n");
 SetSpellUsage("cast wrust <monster>\n");
 SetMemoLevel(GC_NECROMANCER,13);
 SetMemoLevel(GC_ARCHMAGE,13);
 
 SetFailFn(#'MyFail);
}

