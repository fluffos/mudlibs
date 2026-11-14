/* Rewritten by Softbyte August 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
#include <properties.h>
inherit "/obj/scroll";

string estimate(object mon) 
{
string s;
int mac,mwc,mdodam,msurvivetime;
int pac,pwc,pdodam,psurvivetime;
int dex,hitchance,factor;
int i;
object pl;
mixed *obp;

 pl=this_player();

 mwc=0;
 /* Hands *3 /5 + Dex/5 + Str /5   */
 obp=mon->QueryHands();
 for(i=0; i<sizeof(obp); i++)
     if (!objectp(obp[i][1])) mwc+=obp[i][2]*3/5+mon->QueryDex()/5 +mon->QueryStr()/5;
 /* Weapons WC + Str */
 obp=mon->QueryWeapons();
 for(i=0; i<sizeof(obp); i++)
     if (obp[i]) mwc+=obp[i]->QueryWC()+mon->QueryStr();

 /* Armours AC */
 mac=mon->Query(P_AC);
 obp=mon->QueryArmours();
 for(i=0; i<sizeof(obp); i++)
     if (obp[i]) mac+=obp[i]->QueryAC();

 pwc=0;
 /* Hands *3 /5 + Dex/5 + Str /5   */
 obp=pl->QueryHands();
 for(i=0; i<sizeof(obp); i++)
     if (!objectp(obp[i][1])) pwc+=obp[i][2]*3/5+pl->QueryDex()/5 +pl->QueryStr()/5;
 /* Weapons WC + Str */
 obp=pl->QueryWeapons();
 for(i=0; i<sizeof(obp); i++)
     if (obp[i]) pwc+=obp[i]->QueryWC()+pl->QueryStr();

 /* Armours AC */
 pac=pl->Query(P_AC);
 obp=pl->QueryArmours();
 for(i=0; i<sizeof(obp); i++)
     if (obp[i]) pac+=obp[i]->QueryAC();

 dex=pl->QueryDex()-mon->QueryDex();

 hitchance=66-dex*3;
 if (hitchance>100) hitchance=100;
 if (hitchance<0) hitchance=0;
 mdodam=(mwc/2-pac)*hitchance/100;   /* monster attack does damage */
 if (mdodam<1) mdodam=1;

 hitchance=66+dex*3;
 if (hitchance>100) hitchance=100;
 if (hitchance<0) hitchance=0;
 pdodam=(pwc/2-mac)*hitchance/100;   /* player attack does damage */
 if (pdodam<1) pdodam=1;

 psurvivetime=pl->QueryHP()/mdodam +1;
 msurvivetime=mon->QueryHP()/pdodam +1;

 s=(mon->QueryName()||mon->QueryShort())+" ";

 /* factor is how much percdent the winner is stronger than the looser */
 if (psurvivetime>=msurvivetime)  /* player wins , factor>=100 */
 {
   factor=100*psurvivetime/msurvivetime;  /* 200==> we are twice as strong */
   if (factor<110) s+="is equal to you.";
   else if (factor<170) s+="is weaker than you.";
   else if (factor<275) s+="is much weaker than you.";
   else if (factor<500) s+="is very much weaker than you.";
   else if (factor<1000) s+="would be easy to kill.";
   else s="You will fall down laughing when fighting "+mon->QueryName()+".";
 }
 else  /* monster wins , factor>=100 */
 {
   factor=100*msurvivetime/psurvivetime;  /* 200==> Monster is twice as strong */
   if (factor<110) s+="is equal to you.";
   else if (factor<150) s+="is stronger than you.";
   else if (factor<225) s+="is much stronger than you.";
   else if (factor<500) s+="is very much stronger than you.";
   else if (factor<1000) s+="will be nearly impossible to kill.";
   else s="will fall down laughing when "+mon->QueryPronoun()+" sees you.";
 }
 s+="\n";
 return(capitalize(s));
}

int MyCast(string str) 
{
object wolf;
   if (!str) wolf=GetEnemy(this_player()); /* draw random enemy */
   else wolf=present(str, environment(this_player()));
   if (!wolf)
   {
     write("That's not here.\n"); 
     return CAST_FAIL_NOMSG;
   }
   Message(estimate(wolf));
   return CAST_SUCCESS;
}

int MyFail() {
   write("It seems to be stronger.\n");
   return CAST_SUCCESS;
}
create() {
 ::create();
 AddSpell("consider",ST_KNOW,5,#'MyCast,"consideration",10);
 SetSpellDesc("This spell will allow you to consider a monster.\n");
 SetSpellUsage("cast consider <monster>\n");
 SetMemoLevel("allmage",2);
 SetFailFn(#'MyFail);
}

