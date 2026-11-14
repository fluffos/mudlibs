/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object who;
string s;
int amount;
  if (!str ) 
   {
     write("Wrong usage of spell 'heal creature'.\n");
     return CAST_FAIL_NOMSG;
  }
  who=present(str, environment(this_player()));
  if (!who) {
     write("I can't find "+str+".\n");
     return CAST_FAIL_NOMSG;
  }
  if (who->QueryIsPlayer() || !living(who)) {
     write("You can heal only NPCs, fellows and familiars!\n");
     return CAST_FAIL_NOMSG;
  }
  s=who->QueryName()||who->QueryShort();
  /* NO modify magic ! */
  amount=100+random(22);
  Message( ({"You heal "+s+" ("+amount+").\n",
      this_player()->QueryName()+" heals "+s+".\n"}));
  who->Heal(amount);
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
    if (Repulse(this_player(),this_player(),DT_ZAP)) return CAST_REPULSE;
    Message(({"A huge fist appears and smashes you to the ground.\n",
       "A huge fist appears and smashes "+this_player()->QueryName()+
       " to the ground.\n"}));
    dam=20+random(20);
    dam=this_player()->Defend(ModifyMagic(dam), DT_ZAP, 0);
    Message(QueryCastDamage(dam));
    return CAST_SUCCESS;
}

create() 
{
 ::create();
 AddSpell("heal",ST_HEAL,70,#'MyCast,"heal creature",25);
 SetSpellDesc(
"You can heal fellows and familiars with this spell, but no players.\n");
 SetSpellUsage("cast heal <creature>\n");
 SetMemoLevel("allmage",10);
 SetFailFn(#'MyFail);

 NoMemorize();
}

