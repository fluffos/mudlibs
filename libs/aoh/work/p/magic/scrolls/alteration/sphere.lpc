/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str)
{
   object weap;
   string a,b,name;
   int w;
   if (!str) 
   {
     write("What exactely do you want to destruct?\n");
     return CAST_FAIL_NOMSG;
   }
   weap=present(str,this_player());
   if (!weap) { write("You don't have that!\n"); return CAST_FAIL_NOMSG; }
   if (weap->QueryAutoObject() || weap->QueryNoDrop() || living(weap) ) {
      write("This thing can't be destructed!\n");
      return CAST_FAIL_NOMSG;
   }
   Message(({"You have destructed "+weap->QueryShort()+".\n",
       this_player()->QueryName()+" destructed "+weap->QueryShort()+"\n"}));
   weap->remove();
   return CAST_SUCCESS;
}

int MyFail() {
int dam;
    if (Repulse(this_player(),this_player(),ST_FIRE)) return CAST_REPULSE;
    Message(({"The weapon starts to burn. Your hands get burned.\n",
        add_gen(this_player()->QueryName())+" weapon starts to burn.\n"}));
    dam=15+random(15);
    dam=this_player()->Defend(ModifyMagic(dam),DT_FIRE,0);
    Message(QueryCastDamage(dam));
    this_player()->SetSmell(this_player()->QueryName()+
        " smells of burned flesh.\n");
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("sphere",ST_DESTRUCT,130,#'MyCast,"sphere of nihilation",60);
 SetSpellDesc("This spell will try to destruct something.\n");
 SetSpellUsage("cast sphere <target>\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,8);
 SetMemoLevel(GC_ARCHMAGE,18);
 SetFailFn(#'MyFail);
}

