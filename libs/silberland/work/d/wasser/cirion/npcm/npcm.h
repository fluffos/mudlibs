//  npcm.h
//  Header-Datei fuer den NPC-Master
//
//  (c) 1999 by Cirion@Silberland
//
//  06/09/99
//
//
/**-----------------------------------------------------------------------**/

#include "../water.h"  //enthaelt alles was das Herz begehrt

#define WIZNAME "cirion"
#define NPCMHOME "/d/wasser/cirion/npcm"
#define NPC NPCMHOME"/npc"
#define NPCM NPCMHOME"/npcm.lpc"
#define NPCMLOG NPCMHOME"/log"
#define NPCMERRLOG NPCMLOG"/err"
#define NPCMEVENTLOG NPCMLOG"/event"
#define NPCMSTATUSLOG NPCMLOG"/status"
#define NPCMQUERYLOG NPCMLOG"/query"

#define STDNPC NPC"/stdnpc.lpc"

#define LOGSUFFIX ".log"

#ifdef DBME
#undef DBME
#endif
#define DBME(x) if (find_player(WIZNAME)) tell_object(find_player(WIZNAME),(break_string(ANSI_RED"Bug in npcm:"ANSI_NORMAL" "+x+"\n")))
#define LOGERR(x) write_log(NPCMERRLOG+LOGSUFFIX,dtime(time())+" \nError in npcm: "+x+"\n",10000)
#define LOGREP(uid,x) write_log("/log/report/"+uid+".rep",dtime(time())+" \nError in NPC-Master: "+x)
#define TELLBUGGER(user,x) tell_object(user,break_string(ANSI_RED"Error in NPC-Master: "ANSI_NORMAL" "+x+"\n"))
#define LOGEVENT(x) write_log(NPCMEVENTLOG+LOGSUFFIX,dtime(time())+" Event: "+x+"\n",25000)
#define LOGSTATUS(ob) write_log(NPCMSTATUSLOG+LOGSUFFIX,dtime(time())+" Status request from: "+file_name(ob)+" (uid: "+getuid(ob)+")\n",5000)
#define LOGQUERY(x) write_log(NPCMQUERYLOG+LOGSUFFIX,dtime(time())+" Query: "+x+"\n",12000)

#define FORALL(x,y) for (x=sizeof(y);x-->0;)


//Defines fuer den Code
#define NPC_STATUS_ACTIVE 1
#define DEFAULT_NPC_STATUS 1
#define MAX_NPC_STATUS 1

//Defines fuer stdnpc.c
#define NPCM_ACTIVE 2
#define NPCM_REGISTERED 1