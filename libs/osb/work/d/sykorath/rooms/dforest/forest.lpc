/*
  A standard room for the forest
  made by Magictcs - march 97
  it will log all non existing details, (with check if the thing is mentioned
    in the long description of the room)
  this room is for inheriting only!
*/

#include <properties.h>
#include <rooms.h>
#include <sykorath.h>

#define FORESTLOG          "/log/magictcs/forest.log"
// log missing details? --> yes :)
//#define LOGDETAILS 1

inherit "/std/room";

//*****************************
// ignored details (stupid eh?)
//*****************************
// don't log a single word of the following ones!
string *nondetails = ({ "the","and","there","some",
    "you","he","she","they",
    "your","his","her","their",
    "a","an",
    "on","at","into","to",
    "are","is","was","were","can","could"});

// adds a string to the list of nonlogged details - usefull because the
// autologging function has some small problems 
// for example: AddNonDetail("blubb"); - will never log 'blubb',
// even if it is named somewhere in the room!
void AddNonDetail(string non) {
  if (non)
    nondetails+=({non});
}

//********************
// log missing details
//********************
// log missing details (because it is not implemented in the mudlib
// so we do it here :)
// don't check for some words like "he,she,and,the,...."
// maybe adding a check if str is mentioned somewhere else?
// (smell,noise,other details?)
// function checks only short and long description of the room yet
#ifdef LOGDETAILS
string  GetDetail(string str) {
  string ret;
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
    // only if str is in short or long
    if (strstr(QueryIntLong(),str)!=-1 || 
        strstr(QueryIntShort(),str)!=-1) {
dtell("magictcs","DETAIL logged!!\n");
      write_file(FORESTLOG,"missing: "+object_name()+": \""+str+"\".\n");
      return ret;
    }
  }
  return ret;
}
#endif

//*******************************
// search belongs to the mudlib!!
//*******************************
int search(string str) {
  notify_fail("You found nothing.\n");
  return 0;
}

create() {
  ::create();
  SetTPort(TPORT_OUT);                 // teleporting out is disabled
  AddRoomCmd("search",#'search);
}

