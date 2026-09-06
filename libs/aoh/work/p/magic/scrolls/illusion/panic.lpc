/* Adapted and improved by Softbyte 1995 */
#include <secure/wizlevels.h>
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

void DoAttack(object mon) {
  int hit;
  if (mon && living(mon) && !IS_WIZARD(mon) && mon!=this_player()) 
  {
        if (Repulse(mon, this_player())) return;
	tell_room(environment(mon),mon->QueryName()+" runs away in panic.\n"); 
	mon->GoAway();
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
  filter(all_inventory(environment(this_player())),#'DoAttack);
  return CAST_SUCCESS;
}

int MyFail() 
{
   if (Repulse(this_player(),this_player())) return CAST_REPULSE;
   Message(({"You run away in panic!\n",
     this_player()->QueryName()+" runs away in panic!\n"}));
   this_player()->GoAway();
   return CAST_SUCCESS;
}

create()
{
 ::create();
 AddSpell("panic",ST_INFLUENCE,125,#'MyCast,"mass panic",50);
 SetSpellDesc("Everybody in a room will run away in panic.\n");
 SetSpellUsage("cast panic\n");
 
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,18);
 SetMemoLevel(GC_ARCHMAGE,21);
 SetFailFn(#'MyFail);

 NoMemorize();
}

