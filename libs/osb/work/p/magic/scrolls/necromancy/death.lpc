/* Adapted and improved by Softbyte 1995 */
/* Last update: 13.06.95 Elfgar        */

#include <properties.h>
#include <combat.h>
#include <guild.h>
#include <magic.h>
inherit "/obj/scroll";
#define TP this_player()

int MyCast(string str) 
{
object mon;
string name;
int dam;
  if (!str) mon=GetEnemy(TP);
  else mon=present(str, environment(TP));
  if (!mon) { write("Cast it on whom?\n"); return CAST_FAIL_NOMSG; }
  if (!mon->QueryIsPlayer() && !mon->QueryIsNPC() )
  {
     write("You cannot cast this spell on that.\n");
     return CAST_FAIL_NOMSG;
  }
  if (mon->QueryIsPlayer()) LogCast(TP,mon);
  if (Repulse(mon,TP)) return CAST_REPULSE;
  Message( ({"Death touches "+mon->QueryName()+".\n",
    "Death touches "+mon->QueryName()+".\n"}) );
  dam=150+random(150);
  dam=mon->Defend(ModifyMagic(dam), DT_ZAP, 0);
  if (mon) Message(QueryCastDamage(dam,mon));
  return CAST_SUCCESS;
}
int MyFail()
{
int dam;
  if (Repulse(TP,TP)) return CAST_REPULSE;
  Message( ({"Death touches you.\n",
    TP->QueryName()+" is touched by death.\n"}) );
  dam=50+random(100);
  dam=TP->Defend(ModifyMagic(dam),DT_ZAP,0);
  Message(QueryCastDamage(dam));
  return CAST_SUCCESS; 
}

create()
{
 ::create();
 AddSpell("death",ST_ZAP,160,#'MyCast,"death touch",60);
 SetSpellDesc(
"This spell tries to kill a creature outright through sheer magical\n\
force by doing a damage of up to 300 hp. It effects only a monster\n\
that attacks you. For low level players it is dangerous to cast this\n\
spell!\n");
 SetSpellUsage("cast death <monster>\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,18);
 SetMemoLevel(GC_ARCHMAGE,28);
 SetFailFn(#'MyFail);
 
 NoSell();
 NoMemorize();
}

