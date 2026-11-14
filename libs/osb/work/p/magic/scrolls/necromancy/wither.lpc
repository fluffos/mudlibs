/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
  object mon;
  int st;
  int dam;
  if (!str) mon=GetEnemy(this_player());
  else mon=present(str,environment(this_player()));
  if (!mon)
  {
    write("Cast it on what?\n");
    return CAST_FAIL_NOMSG;
  }
  if (mon->Query("withered")>2) {
     write("That one is already withered.\n");
     return CAST_FAIL_NOMSG;
  }
  if (mon->QueryIsPlayer()) LogCast(this_player(),mon);
  if (Repulse(mon, this_player())) return CAST_REPULSE;
  Message( ({mon->QueryName()+" looks much older now.\n",
       mon->QueryName()+" looks much older now.\n"}) );
  mon->Set("withered", mon->Query("withered")+1);
  dam=10+random(40);
  dam=mon->Defend(ModifyMagic(dam), DT_PSYCHO, 0);
  Message(QueryCastDamage(dam,mon));
  if (random(2)==0) mon->ModifyAttr("Int",-1);
  if (random(3)==0) mon->ModifyAttr("Dex",-1);
  if (random(2)==0) mon->ModifyAttr("Con",-1);
  mon->ModifyAttr("Str",-1);
  return CAST_SUCCESS;
}

int MyFail() {
int dam;
   Message( ({"You are withering!\n",
       this_player()->QueryName()+" is withering!\n"}) );
  if (random(10)==0)
  {
     this_player()->ModifyAttr("Con",-1);
     Message("You loose constitution and feel much weeker now.\n");
  }
  dam=10+random(40);
  dam=this_player()->Defend(ModifyMagic(dam), DT_PSYCHO, 0);
  Message(QueryCastDamage(dam));
  return CAST_SUCCESS;
}

create() 
{
 ::create();
 AddSpell("wither",ST_DARK,98,#'MyCast,"wither fist",70);
 SetSpellDesc(
"This spell will wither a monster i. e. make it older.\n\
It will lose on Int, Con, Dex and Str and up to 50 HP.\n\
You can cast this spell on a monster up to three times.\n");
 SetSpellUsage("cast wither <monster>\n");
 SetMemoLevel(GC_NECROMANCER,18);
 SetMemoLevel(GC_ARCHMAGE,18);
 
 SetFailFn(#'MyFail);
 NoMemorize();
}

