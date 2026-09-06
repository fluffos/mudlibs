/*----------------------------------------------------------------------*/
/* The Xtool - Copyright 1992 by Hyp                                    */
/*                                                                      */
/* File: xtool.h                                                        */
/*----------------------------------------------------------------------*/

#include "dependencies.h"

#if MUD_NF || MUD_MG || MUD_OSB
#if MUD_NF || MUD_OSB
inherit "/std/thing";
#else
inherit "/std/thing/properties";
#endif
#include <properties.h>
#include <moving.h>
#ifdef MUD_OSB
#include <secure/wizlevels.h>
#include <secure/userinfo.h>
#else
#include <secure/wizlevels.h>
#include <config.h>
#include <userinfo.h>
#endif
#endif

#ifndef MASTER
#define MASTER __MASTER_OBJECT__
#endif

#if MUD_NF && !MUD_OSB
#define VOID "/std/void"
#elif !MUD_OSB
#define VOID "/room/void"
#endif

#include "xtool.lib.h"

#define NULL               (0)
#define FALSE              (0)
#define TRUE               (1)
#define ERROR              (-1)
#define TO                 this_object()
#define PREV               previous_object()
#define TP                 efun::this_player()
#define RTP                efun::this_interactive()
#define TOOL_NAME          "Xtool"
#define TOOL_VERSION       "1.3"
#define TOOL_TITLE         TOOL_NAME+" v"+TOOL_VERSION
#define TOOL_INTERNAL      "1.3h-14.02.96"

#if MUD_NF || MUD_MG
#define TOOL_PATH          "/obj/tool/xtool"
#endif
#if MUD_TA
#define TOOL_PATH          "/w/hyp/tool/xtool"
#endif
#if MUD_BB
#define TOOL_PATH          "/obj/tools/xtool"
#endif
#if MUD_TM
#define TOOL_PATH          "/players/hyp/tool/xtool"
#endif

#define TOOL_MANPAGE       TOOL_PATH+"/xtool.doc"
#define TOOL_NEWS          TOOL_PATH+"/xtool.news"
#define XPROF_MACRO        TOOL_PATH+"/xprof.h"

#if MUD_NF || MUD_MG
#define TOOL_LEVEL         (40)
#endif
#if MUD_TA
#define TOOL_LEVEL         (51)
#endif
#if MUD_BB || MUD_TM
#define TOOL_LEVEL         (20)
#endif

#define MORE_LINES         (20)
#define MAX_HISTORY        (25)
#define MAX_RECURSION      (6)
#define TRACE_LEVEL        (1|2|4|8)
#define AUTOLOAD_ARGS      ({TOOL_INTERNAL, modi, morelines, aliases})
#define EXEC_LINES         (10)
#define EXEC_TIME          (1)
#if MUD_NF
#define SUBSTR(x,y,z)      (x)[y..z]
#define FIRST(x,y)         (x)[0..y]
#define LAST(x,y)          (x)[<y..]
#define RIGHT(x,y)         (x)[y..]
#define LEFT(x,y)          (x)[0..<y]
#else
#define SUBSTR(x,y,z)      extract(x,y,z)
#define FIRST(x,y)         extract(x, 0, y)
#define LAST(x,y)          extract(x, -(y), -1)
#define RIGHT(x,y)         extract(x, y, -1)
#define LEFT(x,y)          extract(x, 0, -(y))
#endif
#define IA(x)              interactive(x)
#define ENV(x)             environment(x)
#define CAP(x)             capitalize(x)
#define LOWER(x)           lower_case(x)
#define NAME(x)            ((string)x->query_name())
#define CNAME(x)           CAP((string)NAME(x))

#if MUD_NF || MUD_MG
#define RNAME(x)           ((x)?getuid(x):"<none>")
#endif
#if MUD_TA || MUD_BB || MUD_TM
#define RNAME(x)           ((string)x->query_real_name())
#endif

#if MUD_BB || MUD_TM
#define CRNAME(x)          ((string)x->query_vis_name()||"")
#else
#define CRNAME(x)          CAP(RNAME(x))
#endif

#if MUD_NF || MUD_MG
#if MUD_OSB
#define LEVEL(x)           query_user_level(x)
#else
#define LEVEL(x)           query_user_level(x)
#endif
#endif
#if MUD_TA || MUD_BB || MUD_TM
#define LEVEL(x)           ((int)x->query_level())
#endif

#define FORALL(x, y)       for(x=first_inventory(y);x;x=next_inventory(x))
#define DESTRUCT(x)        Destruct(x)
#if MUD_NF
#define ALEFT(x,y,z)       sprintf("%-*.*'"+z+"'s", y, y, ""+(x))
#define ARIGHT(x,y,z)      sprintf("%*.*'"+z+"'s", y, y, ""+(x))
#else
#define ALEFT(x,y,z)       sprintf("%-*'"+z+"'s", y, extract(""+(x), 0, y-1))
#define ARIGHT(x,y,z)      sprintf("%*'"+z+"'s" , y, extract(""+(x), 0, y-1))
#endif
#define W(x)               Write(x)
#define WLN(x)             W(x+"\n")
#define WDLN(x)            W(x+".\n")

#define MODE_ON(x)         (modi|=x)
#define MODE_OFF(x)        (modi&=~x)
#define MODE(x)            (modi&x)
#define MODE_HEART         (1)
#define MODE_FIRST         (2)
#define MODE_PROTECT       (4)
#define MODE_INVCHECK      (8)
#define MODE_ENVCHECK      (16)
#define MODE_NDCHECK       (32)
#define MODE_VARCHECK      (64)
#define MODE_ECHO          (128)
#define MODE_SHORT         (256)
#define MODE_SNOOPCHK      (512)
#define MODE_INVISCHK      (1024)
#define MODE_SCANCHK       (2048)

#if MUD_TA
#define ERR_FILE           "/w/"+RNAME(cloner)+"/.err"
#define LPC_FILE           "/w/"+RNAME(cloner)+"/.xtool.lpc"
#define TMP_FILE           "/w/"+RNAME(cloner)+"/.xtool.tmp"
#define SAVE_FILE          "w/"+RNAME(cloner)+"/.xtoolrc"
#define XPROF_FILE         "/w/"+RNAME(cloner)+"/xprof.lpc"
#else
#define ERR_FILE           "/players/"+RNAME(cloner)+"/.err"
#define LPC_FILE           "/players/"+RNAME(cloner)+"/.xtool.lpc"
#define TMP_FILE           "/players/"+RNAME(cloner)+"/.xtool.tmp"
#define SAVE_FILE          "/players/"+RNAME(cloner)+"/.xtoolrc"
#define XPROF_FILE         "/players/"+RNAME(cloner)+"/xprof.lpc"
#endif

#define SECURE1()    if(!security()) return;
#define SECURE2(x)   if(!security()) return x;
#define USAGE1(x,y)  notify_fail("Usage: "+(y)+"\n");\
                     if((x)=="?") return FALSE;
#define USAGE2(x,y)  notify_fail("Usage: "+(y)+"\n");\
                     if((!(x))||((x)=="?")) return FALSE;

int CatFile();
int Command(string str);
int CommandScan(string arg);
int DoAlias(string verb, string arg);
int DoHistory(string line);
int MoveObj(object obj1, object obj2, int silent);
int XGrepFile(string pat, string file);
int Xalias(string str);
int Xcall(string str);
int Xcallouts(string str);
int Xcindent(string str);
int Xclean(string str);
int Xclone(string str);
int Xcmds(string str);
int Xdate(string str);
int Xdbg(string str);
int Xdclean(string str);
int Xddes(string str);
int Xdes(string str);
int Xdlook(string str);
int Xdo(string str);
int Xdupdate(string str);
int Xeval(string str);
int Xforall(string str);
int Xgoto(string str);
int Xgrep(string str);
int Xhbeats(string str);
int Xhelp(string str);
#if MUD_NF || MUD_MG
int Xids(string str);
#endif
int Xinfo(string str);
int Xlight(string str);
int Xinherit(string str);
int Xload(string str);
int Xlook(string str);
int Xlpc(string str);
int Xman(string str);
int Xmore(string str);
int Xmove(string str);
int Xmsg(string str);
int Xmtp(string str);
int Xprops(string str);
int Xprof(string str);
int Xquit(string str);
#if MUD_NF
int Xrevive(string str);
#endif
int Xscan(string str);
int Xset(string str);
int Xsh(string str);
int Xstop(string str);
int Xtool(string str);
int Xtrace(string str);
int Xtrans(string str);
int Xunalias(string str);
int Xupdate(string str);
int Xwho(string opt);
int id(string str);
int inventory();
varargs int move(mixed dest);
int security();
int write_newinvobj(object who);
int write_newenvobj(object who);
int write_netdead(object who);
int write_alive(object who);
int write_snoopee(object who);
int write_nosnoop(object who);
int write_invisobj(object who);
int write_invislvg(object who);
int write_invisply(object who);
int write_visibobj(object who);
int write_visiblvg(object who);
int write_visibply(object who);
mixed *QueryAutoObject();
object *SubNodes(object obj);
object FindObj(string str, object env);
object VarToObj(string str);
object XFindObj(string str);
string ObjFile(object obj);
string PlayerAge(object obj);
#if MUD_NF
string PlayerJobs(object obj, int flag);
#endif
#if MUD_NF || MUD_MG
string PlayerDomain(object obj, int flag);
#endif
string PlayerIP(object obj, int flag);
string PlayerIdle(object obj);
string PlayerMail(object obj, int flag);
#if MUD_NF || MUD_MG
string PlayerRace(object obj, int flag);
#endif
string PlayerSnoop(object obj, int flag);
string PlayerStats(object obj, int flag);
string PlayerWho(object obj);
varargs string QueryLong();
varargs string QueryShort();
string VarToFile(string str);
string VarToPureFile(string str);
string XFile(string file);
string XFindFile(string file);
void DeepPrintShort(object env, int indent, string pre);
void Destruct(object obj);
#if MUD_NF || MUD_MG
void DumpProperties(object obj);
#endif
void Inheritance(object obj, string func, string pre);
void InvisCheck();
void MoreFile(string str);
void NetDeadCheck(int show);
void PrintObj(object obj);
void PrintShort(string pre, object obj);
void SetAutoObject(mixed *args);
void SnoopCheck();
void VarCheck(int show);
void Write(string str);
void XExecFile(int line);
void XMoreFile(string file, int flag);
void XMsgSay(string str);
void XMsgShout(string str);
void XMsgTell(string str);
void actions();
void init();
void update_tool(mixed *args, object obj);
/* funny thing, the pre-k verison of Amys Drivers in MG
 * complains about the following lines, so I just if-def'ed them out
 * same with the definition of void create() in xtool.c. Had to remove
 * the void declaration infront of it.
 */
#if MUD_NF
void create();
#endif
#if !MUD_MG
void heart_beat();
#endif

#if MUD_MG
string _query_long();
string _query_short();
#endif

#if MUD_TA || MUD_BB || MUD_TM
string short();
string long();
void __INIT();
void reset(int flag);
void init_arg(mixed *args);
mixed *query_auto_load();
int drop();
int get();
#endif
