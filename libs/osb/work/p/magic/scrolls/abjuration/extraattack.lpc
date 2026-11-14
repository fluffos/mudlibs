/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <moving.h>
inherit "/obj/scroll";

#define TP this_player()

private int cnt;

Killme(object player)
{
object mon;
  cnt--; 
  if (cnt<=0 || !player)
  {
    if (player) tell_room(environment(player),"You stop the double attack.\n");
    remove();
  }
  else
  {
    mon=first_inventory(environment(player));
    while(mon) 
    {
       if (living(mon) && mon->QueryIsPlayer()) mon->Attack();
      mon=next_inventory(mon);
    }
    call_out("Killme",4,player);
  }
}

int MyCast(string str)
{
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  if (present("_xattack",TP))
  {
    write("The spell is still active.\n");
    return CAST_FAIL_NOMSG;
  }
  SetIds(({"_xattack"})); /* no scroll anymore */

  Message(({"Everybody is going to hit twice in combat.\n",
       "Everybody is going to hit twice in combat.\n"}) );
  cnt=TP->QueryAttr("Wis")/2;
  if (cnt<5) cnt=5;
  if (cnt>12) cnt=12;
  call_out("Killme",1,TP);
  SetWeight(0);
  ForbidCast();
  SetShort(0);
  move(TP,M_NOCHECK);
  SetNoDrop();

  return CAST_SUCCESS;
}

int MyFail() {
int dam;
     if (Repulse(TP,TP,ST_ZAP)) return CAST_REPULSE;
     Message(({"Your weapon hits you!\n",
         TP->QueryName()+" gets hit by "+
	 TP->QueryPossessiv()+" own weapon.\n"}) );
     dam=10+random(30);
     dam=TP->Defend(ModifyMagic(dam),DT_ZAP,0);
     Message(QueryCastDamage(dam));
     return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("attack",ST_OTHER,30,#'MyCast,"extra attack",10);
 SetSpellDesc(
"This spell will allow all players in a room to attack twice\n\
for some rounds in combat.\n");
 SetSpellUsage("cast attack\n");
 SetMemoLevel(GC_SORCERER,11);
 SetMemoLevel(GC_ARCHMAGE,11);
 SetFailFn(#'MyFail);
 NoDestruct();
 cnt=0;

}

