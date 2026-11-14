/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object mon;
mixed *limbs;
  int i, wc;
  if (!str) mon=GetEnemy(this_player());
  else mon=present(str,environment(this_player()));
  if (!mon) 
  {
    write("That's not here.\n");
    return CAST_FAIL_NOMSG;
  }
  if (!mon->QueryIsNPC()) {
     write("You can't cast it on that.\n"); return CAST_FAIL_NOMSG; }
  if (mon->Query("foul")>0) {
     write("It's limbs are already rotting.\n");
     return CAST_FAIL_NOMSG;
  }
  if (Repulse(mon, this_player())) return CAST_REPULSE;
  mon->Set("foul",1);
  limbs = mon->QueryHands();
  if (limbs && sizeof(limbs)) for (i=0; i<sizeof(limbs); i++) {
     wc = limbs[i][HAND_WC];
     limbs[i][HAND_WC] = wc / 2;
  }
  if (limbs) mon->SetHands(limbs);
  tell_room(environment(this_player()),add_gen(capitalize(mon->QueryName()))+
            " limbs are rotting.\n");
  return CAST_SUCCESS;
}

int MyFail() {
   if (random(10)==0)
   {
     this_player()->ModifyAttr("Str",-1);
     Message(({"You loose strength and feel a bit weaker now.\n",
       this_player()->QueryName()+" is a bit weaker now.\n"}));
   }
   else Message(({"Nothing happens.\n","Nothing happens.\n"}) );
   return CAST_SUCCESS;
}

create()
{
 ::create();
 AddSpell("foul",ST_DARK,50,#'MyCast,"foul limbs",45);
 SetSpellDesc("This spell will make a monsters limbs start to rott.\n");
 SetSpellUsage("cast foul <monster>\n");
 SetMemoLevel(GC_NECROMANCER,9);
 SetMemoLevel(GC_ARCHMAGE,9);
 
 SetFailFn(#'MyFail);
}

