/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";
#define MAX_PRESAY_LEN 40

int MyCast(string str) {
  if (!str) this_player()->SetPresay("");
  else if (strlen(str)>MAX_PRESAY_LEN)
  {
    write("That is no decent presay!\n");
    return CAST_FAIL_NOMSG;
  }
  else this_player()->SetPresay(str+" ");
  Message(({"You change your presay.\n",
            this_player()->QueryName()+" makes some magical gestures.\n"}) );
  return CAST_SUCCESS;
}

int MyFail() {
  this_player()->SetTitle("the one who is too stupid to change presays");
  Message(({"You change your presay.\n",
            this_player()->QueryName()+" makes some magical gestures.\n"}) );
  return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("presay",ST_CHANGE,50,#'MyCast,"change presay",10);
 SetSpellDesc("This spell allows you to change your presay.\n");
 SetSpellUsage("cast presay <new presay>\n");
 SetMemoLevel("allmage",8);
 SetFailFn(#'MyFail);

 NoMemorize();
}

