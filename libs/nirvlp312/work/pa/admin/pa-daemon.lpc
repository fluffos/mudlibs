/*
 *      File:                   pa-daemon.c
 *      Function:               Tracks player affairs wizards
 *      Author(s):              Vertebraker@Nirvana
 *      Copyright:              Copyright (c) 2005 Vertebraker
 *                                      All Rights Reserved.
 *      Source:                 09/24/2005
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

string *nms;

#define TEXTFILE "/pa/admin/pa-list.txt"
#define PA_MEMBERS ({ "martha", "stardream", "fred" })

void reset(int arg) {
  if(arg) return;
#if 1
nms = PA_MEMBERS;
#else
  nms = explode(read_file(TEXTFILE), "\n");
#endif
}

void save_me() {
  int s;
#ifdef __LDMUD__
return;
#endif
  rm(TEXTFILE);
  s=sizeof(nms);
  while(s--)
  write_file(TEXTFILE, nms[s]+"\n");
}

void add_name(string nm){
  if((int)this_player()->query_level() < ELDER)
    return 0;
  if(!nms) nms=({});
  if(member_array(nm,nms) == -1) {
    nms += ({nm});
  }
  save_me();
}

void delete_name(string nm){
  if((int)this_player()->query_level() < ELDER)
    return 0;
  if(!nms) nms=({});
  if(member_array(nm,nms) > -1) {
    nms -= ({nm});
  }
  save_me();
}

string * query_names() {
  return nms;
}

status query_name(string nm) {
  if(!nms) nms = ({ });
  return member_array(nm,nms) > -1;
}

int query_prevent_shadow() { return 1; }
