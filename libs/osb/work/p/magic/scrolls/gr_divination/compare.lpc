/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
   object weap1, weap2;
   string a, b, name;
   if (!str || sscanf(str,"%s with %s",a,b)!=2) 
   {
      write("Wrong usage!\n"); 
      return CAST_FAIL_NOMSG;
   }
   weap1=present(a,this_player());
   weap2=present(b,this_player());
   if (!weap1 || !weap2) { write("You don't have that!\n"); return 1; }
   if (weap1->QueryHitObj()) write("There seems to be something special about "+
       weap1->QueryShort()+".\n");
   if (weap2->QueryHitObj()) write("There seems to be something special about "+
       weap2->QueryShort()+".\n");
   if (weap1->QueryWC()>weap2->QueryWC()) { write(
       capitalize(weap1->QueryShort())+" is better than "+weap2->QueryShort()+".\n"); }
   else if (weap2->QueryWC()>weap1->QueryWC()) {write(
       capitalize(weap2->QueryShort())+" is better than "+weap1->QueryShort()+".\n");  }
   else write("The weapons are equal.\n");
   return CAST_SUCCESS;
}

MyFail()
{
   write("Maybe the first weapon is better than the second one.\n");
   return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("compare",ST_KNOW,30,#'MyCast,"compare weapons",40);
 SetSpellDesc("This spell will compare to weapons.\n");
 SetSpellUsage("cast compare <weapon1> with <weapon2>\n");
 SetMemoLevel(GC_SORCERER,8);
 SetMemoLevel(GC_ARCHMAGE,8);
 SetFailFn(#'MyFail);

 NoMemorize();
}

