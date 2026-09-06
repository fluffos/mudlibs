/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object mon, poison;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  mon=first_inventory(environment(this_player()));
  while (mon) 
  {
    if (living(mon) && mon->QueryIsPlayer() )
    {
      mon->HealHP(50); /* no ModifyMagic !*/
      poison=present("gas",mon);
      if (poison) call_other(poison,"healing","healed"); 
      mon->SetPoison(0);
      if (mon!=this_player())
        Message( ({ "You heal "+mon->QueryName()+".\n",
           this_player()->QueryName()+" heals "+mon->QueryName()+".\n",
           ({mon}),({"You are healed by "+this_player()->QueryName()+".\n"}) }) );
      else
        Message( ({"You heal yourself.\n",
                 this_player()->QueryName()+" is healed.\n"}) );
     }
     mon=next_inventory(mon);
  }
  return CAST_SUCCESS;
}

create() 
{
 ::create();
 AddSpell("anew",ST_HEAL,200,#'MyCast,"flesh anew",0);
 SetSpellDesc(
"This spell will heal every player by 50 hp. It will also heal poisoned players.\n");
 SetSpellUsage("cast anew\n");
 ForbidMemo("all");
 NoMemorize();
 NoSell();
}

