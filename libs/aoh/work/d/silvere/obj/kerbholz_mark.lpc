// This is the object, that watches the player/npc until it dies.
// It is used by the kerbholz.
// created:       Sonic [08-Jun-1997]
// last changed:  Sonic [08-Jun-1997] *combat-stuff*

#include <properties.h>
#include <moving.h>
#include <macros.h>
inherit "/std/thing";

string owner, target;

string GetInfo() { return "Mark created by "+CAP(owner)+"'s Kerbholz, realname is "+target+".\n"; }
string QueryOwner() { return owner; }
int SetOwner(string str, object who)
{
   if(!str) return 0;
   Set(P_EXTRALOOK,CAP(HESHE(who))+" has a blue tattoo on "+HISHER(who)+" forehead.\n");   
   who->AddFollower(TO);
   owner=lower_case(str);
   target=RNAME(who);
   return 1;
}

void catch_tell(string str)
{
   string corpse;
   object who;

   if(!str) return;
   if(sscanf(lower_case(str),"%s died",corpse)==1)
   {
      who=find_player("sonic");
      if(who) tell_object(who,"*** Kerbholzmark: "+str[0..<2]+"["+lower_case(corpse)+"/"+target+"]\n");
      if(lower_case(corpse)==target)
      {
/* Do the actual check, who died and who killed him/her.
 * if the player has set the mark here, write the kill to
 * the kerbholz.
 */
         if(who) tell_object(who,"*** Kerbholzmark: "+CAP(RNAME(PO))+" has killed "+CAP(corpse)+".\n");
      }
      remove();
   }
}

void create()
{
   ::create();
   enable_commands();
   Set(P_IDS,({"k_mark","kerbholzmark"}) );
   Set(P_SHORT,0);
   Set(P_WEIGHT,0);   
   Set(P_NOGIVE,"");
   Set(P_NOGET,"");
   Set(P_NODROP,"");
   Set(P_MSGIN,"");
   Set(P_MSGOUT,"");
   Set(P_MMSGIN,"");
   Set(P_MMSGOUT,"");
}
