/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";
#define TP this_player()

int MyCast(string str) 
{
object weap,mon;
object *arm;
int howmuch;
   if (!str) mon=GetEnemy(TP);
   else mon=present(str,environment(TP));
   if (!mon)
   {
     write("I can't find that.\n");
     return CAST_FAIL_NOMSG;
   }
   if (!mon->QueryIsNPC() && !mon->QueryIsPlayer() )
   {
     write("You cannot cast the spell on that.\n");
     return CAST_FAIL_NOMSG;
   }
   arm=mon->QueryArmours();
   if (!arm || !sizeof(arm) )
   {
     write(capitalize(mon->QueryName())+" has no armour.\n");
     return CAST_FAIL_NOMSG;
   }
   weap=arm[random(sizeof(arm))];
   if (!weap) { 
      write("Your attacker doesn't have a any armour!\n"); 
      return CAST_FAIL_NOMSG; 
   }
   if ( weap->QueryAC()<1 )
   {
     write("You cannot make "+weap->QueryShort()+" rusty.\n");
     return CAST_FAIL_NOMSG;
   }
   if (Repulse(mon,TP)) return CAST_REPULSE;
   howmuch=20+TP->QueryInt()+random(15);
   weap->SetQuality(weap->QueryQuality()-howmuch);
   weap->Set("rusting");
   Message(({"You let "+weap->QueryShort()+" rust.\n",
      TP->QueryName()+" has let "+weap->QueryShort()+" of "+
      mon->QueryShort()+" rust.\n"}));
  return CAST_SUCCESS;
}

MyFail() {
int dam;
    if (Repulse(TP,TP,ST_FIRE)) return CAST_REPULSE;
    Message(({"The armour starts to glow. You get burned.\n",
        TP->QueryName()+"'s armour starts to burn.\n"}) );
    dam=10+random(15);
    dam=TP->Defend(ModifyMagic(dam),DT_FIRE,0);
    TP->SetSmell(TP->QueryName()+ " smells of burned flesh.\n");
    Message(QueryCastDamage(dam));
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("arust",ST_CHANGE,45,#'MyCast,"rust armour",30);
 SetSpellDesc(
"This spell will make a monsters armour rust by decreasing the\n\
quality of their armour depending on your INT.\n");
 SetSpellUsage("cast arust <monster>\n");
 SetMemoLevel(GC_NECROMANCER,14);
 SetMemoLevel(GC_ARCHMAGE,14);
 
 SetFailFn(#'MyFail);
}

