/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#define CURSER "/d/woodland/joern/masters/curser"
inherit "/obj/scroll";

int MyCast(string str) 
{
 object weap;
 string a, b, name, *class;
   if (!str)
   {
     write("What item do you mean?\n");
     return CAST_FAIL_NOMSG;
   } 
   weap=present(str,this_player());
   if (!weap) weap=present(str,environment(this_player()));
   if (!weap) { write("You don't have that!\n"); return CAST_FAIL_NOMSG; }
   if (!weap->Query("cursed")) 
   {write("It is not cursed!\n"); return CAST_FAIL_NOMSG; }
   class = weap->QueryClassIds();
   if (!class) class = ({});
   if (member(class, "armour") > -1) CURSER->RemoveCurseArmour(weap);
   if (member(class, "weapon") > -1) CURSER->RemoveCurseWeapon(weap);
   if (1==sscanf(weap->QueryShort()||"","%s (cursed)",a))
        weap->SetShort(a);
   Message( ({"You have removed a curse from " + weap->QueryShort() + ".\n",
       this_player()->QueryName()+" has removed a curse from " +
         weap->QueryShort()+".\n"}));
   if (weap->Query("cursed")) weap->Set("cursed",0);

   return CAST_SUCCESS;
}

MyFail() {
int dam;
    if (Repulse(this_player(),this_player())) return CAST_REPULSE;
    Message( ({"The item starts to glow. You get burned.\n",
        add_gen(this_player()->QueryName())+" item starts to burn.\n"}) );
    dam=10+random(20);
    dam=this_player()->Defend(ModifyMagic(dam),DT_FIRE,0);
    this_player()->SetSmell(this_player()->QueryName()+
                   " smells of burned flesh.\n");
    Message(QueryCastDAmage(dam));
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("rmcurse",ST_CHANGE,70,#'MyCast,"remove curse",30);
 SetSpellDesc(
"This spell will remove a curse from an object when it is not living.\n");
 SetSpellUsage("cast rmcurse <target>\n");
 SetMemoLevel("allmage",15);
 SetFailFn(#'MyFail);
}

