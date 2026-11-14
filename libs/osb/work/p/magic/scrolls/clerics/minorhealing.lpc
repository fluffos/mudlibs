/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object wer;
int lvl;
int amount;
  if (!str) wer = this_player();
  else wer=present(str, environment(this_player()));
  if (!wer)
  {
     write("I can't see that player here.\n");
     return CAST_FAIL_NOMSG;
  }
  lvl = this_player()->QueryLevel();
  if (wer != this_player())
    Message( ({"You heal "+wer->QueryName()+".\n",
       wer->QueryName()+" is healed by "+this_player()->QueryName()+".\n",
       ({wer}),({"You are healed by "+this_player()->QueryName()+".\n"}) }) );
 else
   Message( ({"You heal yourself.\n",
         this_player()->QueryName()+" is healed.\n"}) );
  /* NO modifymagic */
  amount=lvl/2+random(lvl);
  wer->HealHP( amount );
  return CAST_SUCCESS;
}

int MyFail() 
{
  if (Repulse(this_player(),this_player())) return CAST_REPULSE;
  Message( ({"Seems you are a bad healer.\n",
       this_player()->QueryName()+" sighs deeply.\n"}) );
  return CAST_SUCCESS;
}
int QueryCost()
{
  return 15+this_player()->QueryLevel();
}
create()
{
 ::create();
 AddSpell("minor",ST_HEAL,#'QueryCost,#'MyCast,"minor healing",60);
 SetSpellDesc(
"This spell will give someone back up to 1.5*level hitpoints.\n\
It will cost you 15 + level spellpoints to cast it.\n\
If you simply type 'cast minor' the spell will be casted on you.\n");
 SetSpellUsage("cast minor <target>\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,12);
 SetMemoLevel(GC_ARCHMAGE,22);
 SetFailFn(#'MyFail);

}

