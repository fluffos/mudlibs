/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <properties.h>
inherit "/obj/scroll";


int MyCast(string str)
{
object wolf;
string s,c;
  if (!str) { write("Identify what?\n");  return CAST_FAIL_NOMSG;}
  wolf=present(str,this_player());
  if (!wolf) wolf=present(str,environment(this_player()));
  if (!wolf) {write("Identify what?\n"); return CAST_FAIL_NOMSG;}
  c=geteuid(wolf);
  if (c) c=capitalize(c); else c="Mr. Unknown";
  s=wolf->Query(P_MAGIC)||wolf->Query(P_INFO)||c;
  if (s && !wolf->Identify(this_player())) 
     write("The following is special about it: "+s+".\n");
  return CAST_SUCCESS;
}

int MyFail() {
   write("The following is special about it: NOTHING!\n");
   return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("identify",ST_KNOW,10,#'MyCast,"idendify",25);
 SetSpellDesc("This spell will allow you to identify an object.\n");
 SetSpellUsage("cast identify <object>\n");
 SetMemoLevel("allmage",9);
 SetFailFn(#'MyFail);
}

