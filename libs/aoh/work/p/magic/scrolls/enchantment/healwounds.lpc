/* Written by Softbyte August 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object wer;
int amount;
  if (!str) 
  {
    write("Who should be healed?\n");
    return CAST_FAIL_NOMSG;
  }
  wer=present(str, environment(this_player()));
  if (!wer)
  {
     write("I can't see that player here.\n");
     return CAST_FAIL_NOMSG;
  }
  if (wer == this_player() )
  {
    write("You cannot heal yourself!\n");
    return CAST_FAIL_NOMSG;
  }
    Message( ({"You heal "+wer->QueryName()+".\n",
       wer->QueryName()+" is healed by "+this_player()->QueryName()+".\n",
       ({wer}),({"You are healed by "+this_player()->QueryName()+".\n"}) }) );
  /* No modify magic */
  amount=15+random(20);
  wer->HealHP(  amount );
  return CAST_SUCCESS;
}

int MyFail() 
{
  if (Repulse(this_player(),this_player())) return CAST_REPULSE;
  Message( ({"Seems you are a bad healer.\n",
       this_player()->QueryName()+" sighs deeply.\n"}) );
  return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("wheal",ST_HEAL,50,#'MyCast,"heal wounds",50);
 SetSpellDesc(
"This spell will give someone back up to 45 hitpoints.\n\
You cannot cast this spell on yourself!\n");
 SetSpellUsage("cast wheal <target>\n");
 SetMemoLevel(GC_SORCERER,12);
 SetMemoLevel(GC_ARCHMAGE,12);
 
 SetFailFn(#'MyFail);
}

