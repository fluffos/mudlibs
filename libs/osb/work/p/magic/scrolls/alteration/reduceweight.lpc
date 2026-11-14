/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";
#define TP this_player()

int MyCast(string str) 
{
   object weap;
   string a,b,name;
   int w;
   if (!str) 
   {
     write("What item?\n");
     return CAST_FAIL_NOMSG;
   }
   weap=present(str,TP);
   if (!weap) { write("You don't have that!\n"); return CAST_FAIL_NOMSG; }
   if (weap->QueryWeight()<1500 || weap->Query("reduceweight")) {
      write("The weight of that thing can't be reduced!\n");
      return CAST_FAIL_NOMSG;
   }
   w = weap->QueryWeight();
   weap->SetShort(weap->QueryShort()+" (light)");
   weap->SetWeight(w - w / 5);
   weap->Set("reduceweight",1);
   Message(({"You have reduced the weight of "+weap->QueryShort()+" by 20%.\n",
       TP->QueryName()+" reduced the weight of "+
       weap->QueryShort()+"\n"}));
   return CAST_SUCCESS;
}

int doit(object ob)
{
  if (ob->QueryAutoObject()) return 0;
  if (ob->QueryNoDrop()) return 0;
  if (!ob->QueryShort()) return 0;
  return 1;
}
int MyFail() {
object *obp;
object weap;
int w;
   if (Repulse(TP,TP)) return CAST_REPULSE;
   obp=TP->QueryWeapons();
   if (!obp || !sizeof(obp) ) obp=TP->QueryArmours();
   if (!obp || !sizeof(obp) ) obp=filter(all_inventory(TP),#'doit);
   if (!obp || !sizeof(obp) ) return CAST_REPULSE;
   weap=obp[random(sizeof(obp))];
   w=weap->QueryWeight();
   weap->SetWeight(w + w / 5);
   Message(({"You have increased the weight of "+weap->QueryShort()+" by 20%.\n",
       TP->QueryName()+" increases the weight of "+
       weap->QueryShort()+"\n"}));
   return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("reduce",ST_CHANGE,110,#'MyCast,"reduce weight",80);
 SetSpellDesc("This spell will reduce the weight of a heavy thing by 20%.\n");
 SetSpellUsage("cast reduce <target>\n");
 SetMemoLevel(GC_SORCERER,16);
 SetMemoLevel(GC_ARCHMAGE,16);
 
 SetFailFn(#'MyFail);

 NoMemorize();
}

