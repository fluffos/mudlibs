/* Adapted and improved by Softbyte 1995 */
#include <combat.h>
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
 int i; 
 mixed *hnds;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  hnds = this_player()->QueryHands();
  for (i = 0; i < sizeof(hnds); i++) {
      if (hnds[i][HAND_WC] >=8)
      {
        Message("Seems you have already casted the spell for your "+
           hnds[i][HAND_SHORT]+".\n");
      }
      else
      {
        Message(({"Your "+hnds[i][HAND_SHORT]+" starts to glow.\n",
           add_gen(this_player()->QueryName())+
           " "+hnds[i][HAND_SHORT]+" starts to glow.\n"}));
         hnds[i][HAND_WC] += 8;
         return CAST_SUCCESS;
      }
  }
  return CAST_SUCCESS;
}

int MyFail() {
  Message(({"You fall down laughing.\n",
      this_player()->QueryName()+" falls down laughing.\n"}));
  return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("vorpal",ST_CHANGE,55,#'MyCast,"vorpal plating",10);
 SetSpellDesc(
"This spell will create a magic field around your hands\n\
which increases the WC of your bare hands.\n");
 SetSpellUsage("cast vorpal\n");
 SetMemoLevel("allmage",5);
 SetFailFn(#'MyFail);
}

