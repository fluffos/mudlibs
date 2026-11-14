/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str,string spname,int backfire)
{
object poison;
  if (str || backfire)
  {
   if (!backfire)
      write("You cannot use an argument with this "+QuerySpellNoun()+".\n");
    return CAST_FAIL_NOMSG;
  }
  Message( ({"You heal yourself.\n",
       this_player()->QueryName()+" is healed.\n"}) ); 
  this_player()->HealHP(20+random(80)); /* NO ModifyMagic() */
  poison=present("gas",this_player());
  if (poison) call_other(poison,"healing","healed");
  this_player()->SetPoison(0);
  return CAST_SUCCESS;
}

create() 
{
 ::create();
 AddSpell("restore",ST_HEAL,60,#'MyCast,"flesh restore",0);
 SetSpellDesc(
"This spell will heal yourself by 100 HP as well as\n\
heal any poisoning.\n");
 SetSpellUsage("cast restore\n");
 ForbidMemo("all");
 NoSell();
 NoMemorize();
}

