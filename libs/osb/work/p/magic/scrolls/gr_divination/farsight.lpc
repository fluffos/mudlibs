/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <secure/wizlevels.h>
inherit "/obj/scroll";

int MyCast(string str) {
  object wolf, envi;
  string name;
  if (!str) 
  {
    write("Whome do you want to find?\n");
    return CAST_FAIL_NOMSG; 
  }
  wolf = find_player(str);
  if (!wolf) wolf = find_living(lower_case(str));
  if (!wolf) {
     write("That one can't be found.\n"); 
     return CAST_FAIL_NOMSG;
  }
  if ((IS_WIZARD(wolf) || wolf->QueryInvis()) && !IS_WIZARD(this_player())) {
     write("I can't find that one.\n");
     return CAST_FAIL_NOMSG;
  }
  if (Repulse(wolf, this_player())) return CAST_REPULSE;
  name = capitalize(wolf->QueryName());
  envi = environment(wolf);
  write("Looking where "+name+" is, you see:\n");
  if (envi) write(envi->QueryIntLong());
  if (envi) write(envi->Content());
  else write("Nothing.\n");
  return CAST_SUCCESS;
}

int MyFail() {
   write("Try it again!\n");
   return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("sight",ST_KNOW,25,#'MyCast,"far sight",35);
 SetSpellDesc(
"This spell will allow you to see the description of the room a\n\
monster or player is in at the moment.\n");
 SetSpellUsage("cast sight <name>\n");
 SetMemoLevel(GC_SORCERER,7);
 SetMemoLevel(GC_ARCHMAGE,7);
 SetFailFn(#'MyFail);
}

