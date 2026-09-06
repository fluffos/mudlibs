/*
  Inherit this room in all rooms of the madmonks guild
  made by magictcs - 8 may 97

  the room will log all missing details (but only the ones of the 
  long description of the room) into the file: MADMONKLOG
  so it should be easy to find all missing details :)

  this room is for inheriting only!!

  a simple search is implemented (can be overloaded)
*/
 
#include <rooms.h>
#include <moving.h>
#include <properties.h>

#ifdef ONESTEPBEYOND
#include <secure/wizlevels.h>
#else
#include <wizlevels.h>
#endif

#include "/p/guilds/madmonks/madmonks.h"

inherit "/std/room";

// notify missing details to creator of the guild??
// comment out the following line, if lord should not be notigied
#define NOTIFY_LORD 1
#define LORD "magictcs"

// log details?
// comment the following line for no log of missing details
#define LOGDETAILS 1

// ignored details (stupid eh?)
string *nondetails = ({ "the","and","there","some",
    "you","he","she","they",
    "your","his","her","their",
    "a","an",
    "on","at","into","to",
    "are","is","was","were","can","could"});

// adds a string to the list of nonlogged details - usefull because the
// autologging function has some small problems 

void AddNonDetail(string *non) {
  int i;
  if (non) {
    if (stringp(non)) {
      nondetails+=({non});             // add a single string
      return;
    }
    for (i=0;i<sizeof(non+({}));i++)   // add an array of string
      nondetails+=({non[i]});
  }
}

string *QueryNonDetails() {
  return nondetails;
}

// search belongs to the mudlib!!
int search(string str) {  
  notify_fail("You found nothing.\n");
  return 0;
}

/* very simple - but no more is needed here */
create() {
  ::create();
  AddRoomCmd("search",#'search);
}

/* log missing details (because it is not implemented in the mudlib */
/* so we do it here :) */
/* don't check for some words like "he,she,and,the,...." */
/* maybe adding a check if str is mentioned somewhere else?
   (smell,noise,other details?) */
/* and at least - notify me, if a detail was logged :) */
#ifdef LOGDETAILS
string * GetDetail(string str) {
  string *ret;
  mapping detail;
  mixed dummy;
  int i;
  if (!str) return 0;
  ret=::GetDetail(str);
  if (ret==0) {
    // check the short and long descriptions
    if (member(nondetails,str)!= -1) {
      // ignore all words from the list (don't log the missing 'details'!)
      return ret;
    }
    // supress item-ids
    if (present(str,TO)) { return ret; }
    if (strstr(QueryIntLong(),str)!=-1 || 
        strstr(QueryIntShort(),str)!=-1) {
#ifdef NOTIFY_LORD
      dtell(LORD,"MADMONK DETAIL LOGGED!\n");
#endif
      write_file(MADMONKLOG,"missing: "+object_name()+": \""+str+"\".\n");
      return ret;
    }
  }
  return ret;
}
#endif

