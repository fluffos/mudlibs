//---------------------------------------------------------------------------
// /p/skills/climbing.c
//
// The climb skill handling of OSB
// (c) Softbyte@OSB 19dec97
// [Softbyte] 19dec97:    Basic skill handling and functions
//---------------------------------------------------------------------------

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <daemons.h>
#include <msgclass.h>
#include <skills.h>
#include <math.h>
#include <combat.h>



#define TO this_object()
#define TP this_player()


// ========================= Special skill functions ========================
// ************************    Climbing     *********************************
mixed OnSucceedClimbing(object who, int skill, string arg, string extra,mixed p)
{
mixed dest;
mixed text;
string prev;
  if (!arg || !p) return 0;
  
  dest=p[P_SK_CLIMB_DEST];
  if (!dest) return 0;

  text=p[P_SK_CLIMB_MSG];

  seteuid(getuid());

  // Get the base path
  if (S_PO) prev=object_name(S_PO);
  else prev=0;
  if (prev) 
  {
    prev=implode(explode(prev,"/")[0..<2],"/");
  }


  if (stringp(dest)) dest=resolve_file(dest,prev);
  
  if (text) // special move 
  { 
    if (ME_OK!=who->move(dest,M_SPECIAL,text))
    {
      msg_object(who,CMSG_ERROR,"Hmm, cannot move there.\n");
      return 1;
    }
  }
  else
  {
    if (ME_OK!=who->move(dest,M_GO))
    {
      msg_object(who,CMSG_ERROR,"Hmm, cannot move there.\n");
      return 1;
    }
  }
  return 1;
}
mixed OnFailClimbing(object who, int skill, string arg, string extra,mixed p)
{
mixed hurt;
  if (!arg) return 0;
  msg_write(CMSG_GENERIC,
  "Trying to climb "+arg+" you fall down again. Ouch, that hurt.\n");
  seteuid(getuid());
  
  // Check whether we shall hurt
  if (p)
  {
    hurt=p[P_SK_CLIMB_HURTHP];
    // In case we gave a closure
    if (hurt && closurep(hurt) ) hurt=funcall(hurt,who,skill,arg);
    // TODO: Replace by Defend
    if (hurt && intp(hurt) ) who->ReduceHP(hurt);
  }
  return 1;
}




