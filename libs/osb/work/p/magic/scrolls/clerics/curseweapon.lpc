/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#define CURSER "/d/woodland/joern/masters/curser"
inherit "/obj/scroll";

int MyCast(string str) {
   object weap;
   string a, b, name;
   if (!str) 
   { 
     write("Curse what?\n");
     return CAST_FAIL_NOMSG;
   }
   weap=present(str,this_player());
   if (!weap) { write("You don't have that!\n"); return CAST_FAIL_NOMSG; }
   if (weap->QueryWC()<1) {
      write("That 'weapon' can't be cursed!\n");
      return CAST_FAIL_NOMSG;
   }
   if (weap->Query("cursed"))
   {
      write("It is already cursed!\n");
      return CAST_FAIL_NOMSG;
   }
   if (weap->Query("blessed"))
   {
      write("You cannot curse a blessed weapon!\n");
      return CAST_FAIL_NOMSG;
   }
   seteuid(getuid(this_object()));
   CURSER->CurseWeapon(weap, weap->QueryWC()/2); /* ??? */
   Message( ({"You have cursed "+weap->QueryShort()+"\n",
      this_player()->QueryName()+" has cursed "+weap->QueryShort()+"\n"}));
   weap->SetShort(weap->QueryShort()+" (cursed)");
   return CAST_SUCCESS;
}

MyFail() 
{
int dam;
    if (Repulse(this_player(),this_player(),ST_FIRE)) return CAST_REPULSE;
    Message( ({"The weapon starts to glow. You get burned.\n",
       add_gen(this_player()->QueryName())+" weapon starts to burn.\n"}) );
    dam=10+random(10);
    this_player()->Defend(ModifyMagic(dam),ST_FIRE,0);
    this_player()->SetSmell(this_player()->QueryName()+
                   " smells of burned flesh.\n");
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("wcurse",ST_CHANGE,40,#'MyCast,"curse weapon",15);
 SetSpellDesc(
"This spell will curse a weapon and reduce its WC.\n");
 SetSpellUsage("cast wcurse <weapon>\n");
 SetMemoLevel(GC_SORCERER,11);
 SetMemoLevel(GC_ARCHMAGE,11);
 SetFailFn(#'MyFail);

 NoMemorize();
}

