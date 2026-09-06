#ifndef __TOOL_H__
#define __TOOL_H__

/*
 * MGtool-1.3
 * File: tool.h
 * Maintainer: Kirk@MorgenGrauen
 */

/*------------------------------------------*/
/* the original Xtool is copyrighted by Hyp */
/*------------------------------------------*/

#ifndef MASTER
#define MASTER __MASTER_OBJECT__
#endif

#define VOID "/room/void"

#define NULL               (0)
#define FALSE              (0)
#define TRUE               (1)
#define ERROR              (-1)
#define PREV               previous_object()
#define TP                 efun::this_player()
#define RTP                efun::this_interactive()
#define TOOL_NAME          "MGtool"
#define TOOL_VERSION       "1.3.3"
#define TOOL_TITLE         TOOL_NAME+" v"+TOOL_VERSION
#define TOOL_INTERNAL      "1.3.3-10.07.97"

#define TOOL_PATH          "/obj/tools/MGtool"

#define TOOL_MANPAGE       TOOL_PATH+"/tool.doc"
#define TOOL_NEWS          TOOL_PATH+"/tool.news"
#define TOOL_LOG           "/log/xtool"
#define XPROF_MACRO        TOOL_PATH+"/prof.h"
#define LAG_O_DAEMON       "/p/daemon/lag-o-daemon"

#define TOOL_LEVEL         (40)

#define MORE_LINES         (20)
#define MAX_HISTORY        (25)
#define MAX_RECURSION      (6)
#define TRACE_LEVEL        (1|2|4|8)
#define AUTOLOAD_ARGS      ({TOOL_INTERNAL, modi, morelines})
#define EXEC_LINES         (10)
#define EXEC_TIME          (1)

#define IA(x)              interactive(x)
#define ENV(x)             environment(x)
#define LOWER(x)           lower_case(x)
#define NAME(x)            ((string)x->query_name())
#define CNAME(x)           CAP((string)NAME(x))

#define RNAME(x)           getuid(x)
#define CRNAME(x)          CAP(RNAME(x))

#define LEVEL(x)           query_wiz_level(x)

#define FORALL(x, y)       for(x=first_inventory(y);x;x=next_inventory(x))
#define DESTRUCT(x)        Destruct(x)
#define ALEFT(x,y,z)       sprintf("%-*'"+z+"'s", y, (""+(x))[0..y-1])
#define ARIGHT(x,y,z)      sprintf("%*'"+z+"'s" , y, (""+(x))[0..y-1])
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

#define ERR_FILE           "/players/"+RNAME(cloner)+"/.err"
#define LPC_FILE           "/players/"+RNAME(cloner)+"/.tool.lpc"
#define TMP_FILE           "/players/"+RNAME(cloner)+"/.tool.tmp"
#define SAVE_FILE          "/players/"+RNAME(cloner)+"/.toolrc"
#define XPROF_FILE         "/players/"+RNAME(cloner)+"/prof.lpc"
#define PIPE_FILE          "/players/"+RNAME(cloner)+"/.tool.pipe"
#define PRIVATE_HEADER     "/players/"+RNAME(cloner)+"/.xtool.h"
#define PIPE_DELETE(x)     if(pipe_out&&pipe_ovr&&file_size(x)>=0) rm(x)

#define PIPE_IN            1
#define PIPE_OUT           2
#define PIPE_MAX           10000

#define XGREP_REVERT       1
#define XGREP_ICASE        2

#define SECURE1()    if(!security()) return;
#define SECURE2(x)   if(!security()) return x;
#define USAGE1(x,y)  notify_fail("Usage: "+(y)+"\n");\
                     if((x)=="?") return FALSE;
#define USAGE2(x,y)  notify_fail("Usage: "+(y)+"\n");\
                     if((!(x))||((x)=="?")) return FALSE;
#define USAGE3(x)    return WLN("Usage: "+(x))

nosave int CatFile();
nosave int Command(string str);
int CommandScan(string arg);
int DoAlias(string verb, string arg);
int DoHistory(string line);
nosave int MoveObj(object obj1, object obj2, int silent);
nosave int XGrepFile(string pat, string file, int revert);
int Xcall(string str);
int Xcallouts(string str);
int Xcat(string str);
int Xcindent(string str);
int Xclean(string str);
int Xclone(string str);
int Xuclone(string str);
int Xcmds(string str);
int Xdate(string str);
int Xdbg(string str);
int Xdclean(string str);
int Xddes(string str);
int Xdes(string str);
int Xdlook(string str);
int Xdo(string str);
int Xdupdate(string str);
int Xecho(string str);
int Xeval(string str);
int Xforall(string str);
int Xgoto(string str);
int Xgrep(string str);
int Xhbeats(string str);
int Xhead(string str);
int Xhelp(string str);
int Xids(string str);
int Xinfo(string str);
int Xinherit(string str);
int Xinventory(string str);
int Xlag(string str);
int Xlight(string str);
int Xload(string str);
int Xlook(string str);
int Xlpc(string str);
int Xman(string str);
int Xmore(string str);
int Xmove(string str);
int Xmsg(string str);
int Xmtp(string str);
int Xproc(string str);
int Xprops(string str);
int Xprof(string str);
int Xquit(string str);
int Xscan(string str);
int Xset(string str);
int Xsh(string str);
int Xsort(string str);
int Xstop(string str);
int Xtool(string str);
int Xtrace(string str);
int Xtrans(string str);
int Xupdate(string str);
int Xwc(string str);
int Xwho(string opt);
nosave string crname(object who);
int id(string str);
int move(mixed dest);
nosave int security();
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
nosave object *SubNodes(object obj);
nosave varargs object FindObj(string str, object env, int silent);
nosave object VarToObj(string str);
nosave varargs object XFindObj(string str, int silent);
nosave string ObjFile(object obj);
nosave string PlayerAge(object obj);
nosave string PlayerDomain(object obj, int flag);
nosave string PlayerIP(object obj, int flag);
nosave string PlayerIdle(object obj);
nosave string PlayerMail(object obj, int flag);
nosave string PlayerRace(object obj, int flag);
nosave string PlayerSnoop(object obj, int flag);
nosave string PlayerStats(object obj, int flag);
nosave string PlayerWho(object obj);
nosave string VarToFile(string str);
nosave string VarToPureFile(string str);
nosave string XFile(string file);
nosave string XFindFile(string file);
nosave varargs void DeepPrintShort(object env, int indent, string pre, string file);
nosave void Destruct(object obj);
nosave void DumpProperties(object obj, int flag);
nosave void Inheritance(object obj, string func, string pre);
void InvisCheck();
nosave void MoreFile(string str);
void NetDeadCheck(int show);
nosave void PrintObj(object obj, string file);
nosave varargs void PrintShort(string pre, object obj, string file);
void SnoopCheck();
nosave void VarCheck(int show);
nosave int  Write(string str);
nosave void XExecFile(int line);
nosave void XMoreFile(string file, int flag);
nosave void XMsgSay(string str);
nosave void XMsgShout(string str);
nosave void XMsgTell(string str);
nosave void XmtpScript(string dir, string file, string opt);
void actions();
void init();
void update_tool(mixed *args, object obj);
string _query_long();
string _query_short();

nosave int CallFunc(string verb, string str);
nosave string GetFunc(string verb, int test);

nosave string PrepareLine(string str);
nosave string QuoteLine(string str);
nosave string UnquoteLine(string str);
int QuoteOk(string str);
nosave string *ExplodeCmds(string str);

string read_buffer(string filename, int start, int number);
string load_buffer(int line);
int read_line(int offset);

/*
 * debug stuff
 */
void TK(string str);
int Xtk(string str);

#endif /* __TOOL_H__ */
