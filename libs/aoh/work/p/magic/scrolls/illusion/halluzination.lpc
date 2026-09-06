/* Adapted and improved by Softbyte 1995 */
#include <properties.h>
#include <magic.h>
#include <guild.h>
inherit "obj/scroll";
#define TP this_player()

MyCast(str) 
{
  object who;
  string a,b;
  if (!str) {write("Spell used in a wrong way!\n"); return CAST_FAIL_NOMSG; }
  if (sscanf(str,"%s %s",a,b)<2) {
      write("Spell used in a wrong way!\n");
      return CAST_FAIL_NOMSG;
  }
  who=present(a,environment(TP));
  if (!who || !who->QueryIsPlayer()) 
  { 
    write("That player is not here!\n"); 
    return CAST_FAIL_NOMSG;
  }
  Message("You let "+who->QueryName()+" see a hallucination.\n"); 
  tell_object(who,"There seems to be "+b+".\n");
  return CAST_SUCCESS;
}

MyFail() {
   if (Repulse(TP,TP)) return CAST_REPULSE;
   Message("You see a big spider crawling over your feet.\n");
   return CAST_SUCCESS;
}


create() {
::create();
 AddSpell("hallucinate",ST_FUN,5,#'MyCast,"hallucination",10);
 SetSpellDesc(
"This spell let a player see something that is not there. The player\n"+
"will get the message 'There seems to be <something>.'.\n");
 SetSpellUsage("cast hallucinate <player> <something>\n");
 SetMemoLevel(GC_SORCERER,3);
 SetMemoLevel(GC_ARCHMAGE,3);
 
 SetFailFn(#'MyFail);
}

