/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str)
{
object mon;
string name;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this "+QuerySpellNoun()+".\n");
    return CAST_FAIL_NOMSG;
  }
  mon=first_inventory(environment(this_player()));
  while(mon)
  {
     if (Repulse(mon, this_player())) continue;
     if (living(mon)) 
     {
       mon->SetAggressive(0);
       mon->StopAllHunting(); 
       name=capitalize((mon->QueryName()||mon->QueryShort()));
       Message( ({name+" is calmed.\n",
                  name+" is calmed.\n"}) );
     }
     mon=next_inventory(mon);
  }
  return CAST_SUCCESS;
}

int MyFail() 
{
   Message( ({"You fail to calm anybody.\n",
      this_player()->QueryName()+" fails to calm anybody.\n"}) );
   return CAST_SUCCESS;
}
create()
 {
 ::create();
 AddSpell("calm",ST_INFLUENCE,35,#'MyCast,"calm",10);
 SetSpellDesc(
"This spell will stop all fighting in a room and calm all the monsters.\n");
 SetSpellUsage("cast calm\n");
 SetMemoLevel(GC_SORCERER,16);
 SetMemoLevel(GC_ARCHMAGE,16);
 SetFailFn(#'MyFail);

 NoMemorize();
}

