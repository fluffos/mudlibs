/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#define CURSER "/d/woodland/joern/masters/curser"
inherit "/obj/scroll";

int MyCast(string str) 
{
 object weap;
 string a, b, name;
   if (!str) 
   {
     write("Curse what?\n");
     return CAST_FAIL_NOMSG;
   }
   weap=present(str,this_player());
   if (!weap) { write("You don't have that!\n"); return CAST_FAIL_NOMSG; }
   if (weap->QueryAC()<1) {
      write("That 'armour' can't be cursed!\n");
      return CAST_FAIL_NOMSG;
   }
   if (weap->Query("cursed"))
   {
      write("It is already cursed!\n");
      return CAST_FAIL_NOMSG;
   }
   if (weap->Query("blessed"))
   {
      write("You cannot curse a blessed armour!\n");
      return CAST_FAIL_NOMSG;
   }
   seteuid(getuid(this_object()));   
   CURSER->CurseArmour(weap, weap->QueryAC()-1);
   Message( ({"You have cursed "+weap->QueryShort()+"\n",
       this_player()->QueryName()+" has cursed "+weap->QueryShort()+"\n"}) );
   weap->SetShort(weap->QueryShort()+" (cursed)");
   return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
    if (Repulse(this_player(),this_player(),ST_FIRE)) return CAST_REPULSE;
    Message( ({"The armour starts to glow. You get burned.\n",
        add_gen(this_player()->QueryName())+" armour starts to burn.\n"}) );
    this_player()->SetSmell(this_player()->QueryName()+
                   " smells of burned flesh.\n");
    dam=10+random(10);
    this_player()->Defend(ModifyMagic(dam),ST_FIRE,0);
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("carmour",ST_CHANGE,40,#'MyCast,"curse armour",15);
 SetSpellDesc("This spell will curse an armour and reduce its AC.\n");
 SetSpellUsage("cast carmour <armour>\n");
 SetMemoLevel(GC_SORCERER,11);
 SetMemoLevel(GC_ARCHMAGE,11);
 SetFailFn(#'MyFail);

 NoMemorize();
}

