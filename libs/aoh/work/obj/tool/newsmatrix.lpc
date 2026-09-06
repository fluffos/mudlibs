/* Small Blackboard
**
** A portable news-monger/-reader.
**
**   10-Aug-92 [m] Cmd 'list'.
**   11-Aug-92 [m] Grouphandling.
**   12-Aug-92 [m] Some tweaks.
**   13-Aug-92 [m] Command-clashing with boards better handled.
**   17-Aug-92 [m] Faulty regexp() patterns notified.
**   18-Aug-92 [m] Command 'note' instead of 'new'.
**                 Now lists amount of unread notes.
**                 Command 'edit'.
**   26-Aug-92 [m] Some patches: post-groups-definition cleaned;
**                 .signature included; input-commands ~i, ~h, ~r;
**                 Command 'reply'.
**   28-Aug-92 [m] Command 'catchup'.
**   29-Aug-92 [m] Subjectloss in 'reply' fixed, 'list rights' improved.
**   31-Aug-92 [m] Adapted for new property system.
**   02-Sep-92 [m] Nicened the listing of group contents.
**   08-Dec-92 [m] Now uses /log/<owner>.newsrc if necessary; M_LEVEL can
**                 now be an array; small fixes in fread();
**                 list uses smore().
**   05-Mar-93 [m] Command 'ignore', 'regard'.
**                 'reply' now starts new notes.
**                 Option 'new' for 'next','prev'.
**                 Reading new notes now cycles through all groups.
**   08-Mar-93 [m] Small bugfixes
**   08-Apr-93 [m] Tweaks for new explode().
**   01-Oct-93 [m] Bugfix for 'regard' and 'ignore'.
**   10-Oct-93 [m] Reading .newsedit doubled lines.
**   13-Jan-94 [m] 'news list status' confused subscribed and unsubscribed.
**   14-May-94 [m] Updated 'help rights' for new '@<name>' right.
**   25-May-94 [m] Proper recognition of unspecified rights.
**                 _display_note() also takes a footer string.
**                 Read notes are followed by number footer.
**                 Improved ignore command.
**   03-Aug-94 [m] 'ignore' ignored arguments.
**   08-Nov-94 [m] 'list' now list just the last NO_NOTES headers,
**                 'list full' lists all.
**                 The 'wiznews' notes read on login are automatically
**                 considered 'read'.
**   25-Nov-94 [m] 'ignore' clashed with the player command. It now needs
**                 at least one arg.
**   19-Apr-95 [m] No longer autoloading for mortals.
**   13-May-95 [m] New commands 'lock' and 'unlock'.
**   12-Apr-98 [m] New userlevel system of OSB.
**
**  [m] Mateese, Biontic Magics & Darkness
*/

#include <config.h>
#include <properties.h>
#include <news.h>
#include <secure/wizlevels.h>

#include "/obj/lib/stddefs.h"

#include <string.h>
nosave variables inherit "/lib/string";
nosave variables inherit "/std/thing";
#define OLD_MESSAGE_COMPAT
/*-------------------------------------------------------------------------*/

#define REVTAG   "980412"
#define VERSION  0
#define REVISION 26
#define VER_REV  VERSION+"."+REVISION

#define USAGE(con,txt) if (con) return notify_fail(txt);else
#define FAIL(msg) return notify_fail(msg)

#define DEFAULT_GROUP "general"

/*-------------------------------------------------------------------------*/

mixed saveload;

string *ignpattern;      /* Pattern for unsubscribed groups */
//string *unsub;           /* Assoc-List of unsubscribed groups */
mapping unsub;

nosave mapping groupinfo;
//nosave mixed *groupinfo; /* Personal Info about the groups as alist */
#define GI_NAME 0        /* Groupnames, Key of 'groupinfo' */
#define GI_DATA 1        /* Groupinfos, data of 'groupinfo' */
#define I_LASTID 0       /*   int last_read_id in group */
#define DEFAULT_GROUPINFO ({ 0 })

nosave string actgroup;
nosave mixed msgread;
nosave mixed writemsg;
nosave int mutex;

void _save_groupinfo();
varargs int _chg_act(string newgroup, int silent);

/*-------------------------------------------------------------------------
*/

void create() {
  thing::create();
  AddId ("newsmatrix");
  AddId ("matrix");
  SetReadMsg (
"A small sign reads:\n"+
"  Newsmatrix -- v "+VER_REV+" ["+REVTAG+"]\n"+
"   Biontic Magics & Darkness\n"
          );
  SetNoDrop("You won't drop this.\n");
  SetNoGet("It is stuck to the ground.\n");
  SetNoGive(1);
  SetInfo ("Newsmatrix "+VER_REV+" ["+REVTAG+"] by Mateese");
  SetHelpMsg("Try \"help matrix\".\n");
  groupinfo = ([]);
  unsub = ([]);
  ignpattern = ({});
  mutex = 0;
}

int id(string str) {
  if (!PL || !PL_WLEVEL) return 0;
  return thing::id(str);
}

varargs int remove (int arg) {
  _save_groupinfo();
  return thing::remove();
}

/*-------------------------------------------------------------------------
** Save/Load the groupinfo.
*/

void _save_groupinfo () {
  string lname, wname;
  if (!geteuid(ME) || !find_player(geteuid(ME))) return;
  saveload = ({ VERSION, groupinfo });
  wname = WPATH+geteuid(ME)+"/.newsrc";
  lname = "/log/news/"+geteuid(ME)+".nrc";
  if (file_size (WPATH+geteuid(ME)) == -2) {
    if (file_size (lname+".o") >= 0) rm (lname+".o");
    save_object (wname);
  }
  else save_object (lname);
  saveload = 0;
}

void _load_groupinfo () {
  string name;
  if (!geteuid(ME) || !find_player(geteuid(ME))) return;
  saveload = 0;
  unsub = 0;
  name = WPATH+geteuid(ME)+"/.newsrc";
  if (file_size(name+".o") < 0)
    name = "/log/news/"+geteuid(ME)+".nrc";
  if (file_size(name+".o") >= 0)
    catch(restore_object(name));
  if (saveload)
    groupinfo = saveload[1];
  else {
    write ("Can't restore newsmatrix from '"+name+".o'.\n");
    unsub = ([]);
  }
  saveload = 0;
}

/*-------------------------------------------------------------------------
** Set/Query groupinfo[].
*/

string _get_lastid (string name) {
  string lastid, newsid;
  if (!member(groupinfo, name))
    lastid = "";
  else
    lastid = groupinfo[name][I_LASTID];
  if (name == "wiznews") {
    newsid = ({string})PL->QueryLastNewsId();
    if (stringp(newsid) && newsid > lastid)
      lastid = newsid;
  }
#ifdef OLD_MUDNAME_COMPAT
  if (lastid[0] == 'n')
  {
    lastid = capitalize(lastid);
    if (ix >= 0)
      groupinfo[name][I_LASTID] = lastid;
  }
#endif
  return lastid;
}

void _set_lastid (string name, string id) {
  mixed info;
  if (!name || !id) return;
  if (member(groupinfo, name)) {
    if (groupinfo[name][I_LASTID] < id)
      groupinfo[name][I_LASTID] = id;
  }
  else {
    info = DEFAULT_GROUPINFO;
    info[I_LASTID] = id;
    groupinfo[name] = info;
  }
}

/*-------------------------------------------------------------------------
** check_owner() checks if the right player is trying to use us.
*/

int check_owner() {
  return PL && PL_WLEVEL && PL == environment(ME);
}

/*-------------------------------------------------------------------------
** Check the euid of this_player() against ours.
** If we have none, try to set it to this_players().
** If this fails, the player can't use us, our euid is reset and tried
** to be set to the players one.
*/

varargs int check_euid (int silently, object pl) {
  if (!pl) pl = PL;
  if (!pl || !living(pl)) return 0;
  if (!previous_object() || geteuid(previous_object()) != geteuid(ME)) {
    if (!silently) write ("Sorry, this newsmatrix is not yours.\n");
    return 0;
  }

  if (!geteuid(ME) && !seteuid(geteuid(pl))) {
    if (!silently) write ("Sorry, this newsmatrix is not yours.\n");
    return 0;
  }

  if (!geteuid(ME) || geteuid(ME) != geteuid(pl)) {
    seteuid(0);
    if (!seteuid(geteuid(pl))) {
      if (!silently) write ("You have no right to do that!\n");
      return 0;
    }
  }
  return 1;
}

/*-------------------------------------------------------------------------
** Create or evaluate the autoload-data.
*/

void SetAutoObject (mixed *args) {
  if (!pointerp(args) || sizeof(args) < 1) {
    write ("Can't initialize the Newsmatrix.\n");
    return;
  }

  if (args[0] != VERSION)
    write ("The Newsmatrix has been improved since your last visit here!\n");

  if (sizeof(args) > 1)
    write ("The Newsmatrix couldn't understand all the init-data.\n");
  _load_groupinfo();
  return;
}


mixed QueryAutoObject () {
  _save_groupinfo();
  if (!check_owner())
    return 0;
  return ({ VERSION });
}

/*-------------------------------------------------------------------------
** Make Long and Short description depending on the actual setting of
** euid.
*/

varargs string QueryShort() {
  string euid;

  if (PL && !PL_WLEVEL) return 0;
  check_euid (1, environment(ME));
  if(euid = geteuid(ME)) euid = capitalize(euid);

  if (!euid) return "a newsmatrix";
  return add_gen(euid)+" newsmatrix";
}

varargs string QueryLong() {
  string euid, uid;
  string long;

  check_euid (1, environment(ME));
  if(uid = getuid(ME)) uid = capitalize(uid);
  if(euid = geteuid(ME)) euid = capitalize(euid);
  long =
 "This is a newsmatrix. It's humming of all the news flowing through it.\n"
+(actgroup?"It's currently set to group '"+actgroup+"'"
          :"It's set to no group")+" .\n"
+"Use 'help matrix' for more informations.\n";
  if (euid != geteuid(PL)) {
    if (!euid)
      long += "But this instance must be trusted to to be useful,\n"+
              "since only "+uid+" can use it now fully.\n";
    else
      long += "This special instance may be used fully only by "+euid+".\n";
  }
  return long;
}

/*-------------------------------------------------------------------------
** Add and decode our commands.
*/

void init() {
  if (!check_owner()) return 0;
  thing::init();
  add_action ("read"      , "inspect");
  add_action ("_dispatch" , "", 1);
  _load_groupinfo();
  if (!actgroup && !_chg_act(DEFAULT_GROUP))
    write ("Warning: Can't find default-group '"+DEFAULT_GROUP+"'.\n");
}

int _dispatch(string arg) {
  string verb;
  if ((verb = query_verb()) == "news") {
    if (!arg) verb = 0;
    else if (sscanf (arg, "%s %s", verb, arg) < 2) verb = arg, arg = 0;
  }
  if (verb && verb != "" && function_exists("f"+verb, ME))
    return ({int})call_other(ME, "f"+verb, arg);
  return 0;
}

/*-------------------------------------------------------------------------
** Exchange \. and . in a string and enclose it in ^...$.
*/

string _adapt_pattern (string pattern) {
  string rc;
  if (!pattern) return 0;
    /* all . become \. , thus all \. become \\. */
  rc = string_replace (pattern, ".", "\\.");
   /* now replace all \\. faka \. by . */
  return "^"+string_replace (rc, "\\\\.", ".")+"$";
}

/*-------------------------------------------------------------------------
** Create a default writemsg;
*/

void _mk_writemsg() {
  writemsg = allocate(M_SIZE);
  writemsg[M_WRITER] = capitalize(geteuid(PL));
  writemsg[M_TITLE] = "<untitled>";
  writemsg[M_LEVEL] = PL_WLEVEL;
  writemsg[M_TIME] = time();
  writemsg[M_GROUPS] = ({});
  writemsg[M_TEXT] = "";
}

/*-------------------------------------------------------------------------
** Find the news-master.
*/

object _newsserver() {
  object ob;
  if (ob = find_object(NEWSSERVER)) return ob;
  catch(call_other(NEWSSERVER, "???"));
  if (ob = find_object(NEWSSERVER)) return ob;
  write ("Fatal: Can't find News-Demon.\n");
  return 0;
}

/*-------------------------------------------------------------------------
** Convert the News-errorcode into a string.
*/

varargs mixed _decode (int code, string groupname, string txt3) {
  if (intp(code)) {
    switch (code) {
    case NEWS_OK      : return "Done.\n";
    case NEWS_ILLPARM : return "Illegal parameters.\n";
    case NEWS_ILLGROUP: if (groupname)
                          return "Illegal group '"+groupname+"'.\n";
                        return "Illegal group.\n";
    case NEWS_NORIGHT : return "You are not permitted to do that.\n";
    case -3           : if (txt3) return txt3;
    }
  }
  return "Unknown error.\n";
}

/*-------------------------------------------------------------------------
** Convert the special info from a group-descriptor into an array of strings.
*/

varargs string *_gdsc2str (mixed *gdsc, object news) {
  string line, *rc;
  int j;

  rc = ({ });
  for (j = G_OWNER; j <= G_SUBGROUP; j++) {
    line = ({ "Owner : "
            , "Read  : "
            , "Write : "
            , "Delete: "
            , "SubGrp: "
           })[j-G_OWNER];
    line += "Lvl >= "+radjust (query_user_tag(gdsc[j][0]), 3);
    if (sizeof(gdsc[j]) > 1)
      line += ", "+implode (gdsc[j][1..sizeof(gdsc[j])], ", ");
    rc += break_line (line, 70, "        ");
  }
  if (gdsc[G_MAXMSG] < 0)
    rc += ({ "Max. "+(-gdsc[G_MAXMSG])+" notes, expiring enabled." });
  if (gdsc[G_MAXMSG] == 0)
    rc += ({ "Unlimited notes." });
  if (gdsc[G_MAXMSG] > 0)
    rc += ({ "Max. "+gdsc[G_MAXMSG]+" notes, no expiring." });
  line = ({ "Not logging anything"
          , "Logging new notes"
          , "Logging expired notes"
         })[gdsc[G_LOGMODE]];
  if (gdsc[G_LOGGER] && gdsc[G_LOGGER] != "")
    line += " to ["+gdsc[G_LOGGER]+"]";
  rc += ({ line+"." });
  return rc;
}

/*-------------------------------------------------------------------------
** Parse a gdsc-description from command args, rights are properly ordered.
** On error, display it and return 0.
** Else return an array of the parsed gdsc, and a flag-array
** which gdsc-item has been specified.
** Optionally allow just the rights being specified.
*/

mixed _parse_gdsc (string *args, int justrights) {
  mixed *gdsc, *flag, data;
  int i, ix;
  mixed val;
  mapping m;

  m = ([ 'p':LVL_PLAYER, 'a':LVL_ANCIENT, 'w': LVL_WIZARD ]);
  gdsc = allocate(G_SIZE);
  gdsc[G_OWNER]    = ({ -1 });
  gdsc[G_READ]     = ({ -1 });
  gdsc[G_WRITE]    = ({ -1 });
  gdsc[G_DELETE]   = ({ -1 });
  gdsc[G_SUBGROUP] = ({ -1 });
  flag = allocate(G_SIZE);
  for (i = 1; i < sizeof(args); i++) {
    switch (args[i]) {
    case "owner" :
    case "read"  :
    case "write" :
    case "delete":
    case "subgrp":
      if (i+1 >= sizeof(args)) FAIL ("Illegal arg '"+args[i]+"'\n");
      ix = member( ({ "owner", "read", "write", "delete", "subgrp" })
                        , args[i]) + G_OWNER;
      data = gdsc[ix]; i++;
      while (i < sizeof(args)
             && member(({ "max", "log", "logger", "owner", "read"
                                , "write", "delete", "subgrp"
                                }), args[i]
                             ) == -1
            ) {
        if (intp(val = atoi(args[i]))
          || -1 != (val = member(m, lower_case(args[i])[0]))
           )
         data[0] = val;
        else data += ({ lower_case(args[i]) });
        i++;
      }
      gdsc[ix] = data; flag[ix] = 1;
      i--;
      break;
    case "max" :
      if (justrights || ++i >= sizeof(args))
        FAIL ("Illegal arg '"+args[i]+"'\n");
      if (args[i] == "unlim" || args[i] == "unlimited") val = 0;
      else if (!sscanf (args[i], "%d", val) || args[i] != ""+val || val <= 0)
        FAIL ("Illegal value '"+args[i]+"' for 'max'\n");
      else {
        if ((i+1) < sizeof(args)
            && (args[i+1] == "exp" || args[i+1] == "expire")
           ) i++, val = -val;
        gdsc[G_MAXMSG] = val; flag[G_MAXMSG] = 1;
      }
      break;
    case "log" :
      if (justrights || (i+1) >= sizeof(args)
          || (ix = member(({ "off", "new", "exp", "expire" }), args[++i]
                                )) == -1
         )
        FAIL ("Illegal mode '"+args[i]+"'\n");
      if (ix == 3) ix = 2;
      gdsc[G_LOGMODE] = ix; flag[G_LOGMODE] = 1;
      break;
    case "logger" :
      if (justrights || (i+1) >= sizeof(args))
        FAIL ("Illegal value '"+args[i]+"'\n");
      i++;
      gdsc[G_LOGGER] = (args[i] == "none" ? 0 : args[i]);
      flag[G_LOGGER] = 1;
      break;
    default: FAIL ("Illegal arg '"+args[i]+"'\n");
    }
  }
  return ({ gdsc, flag });
}

/*-------------------------------------------------------------------------
** Check given group for unread notes, return amount.
** If data is given, it is assumed to be the group-data and its name
** is used.
** 0 means: Failure, -1: nothing unread.
*/

varargs int _count_unread (string group, mixed data) {
  object news;
  mixed headers;
  string lastid;
  int i;

  if (!(news = _newsserver())) return 0;
  if (!data) {
    if (!group) FAIL ("No group specified.\n");
    if ((data = ({mixed})news->GetStatus(group)) == NEWS_ILLPARM)
      FAIL ("No such group '"+group+"'.\n");
    data = data[0];
  }
  else group = data[G_NAME];
  if ((lastid = _get_lastid(group)) < data[G_LASTID]) {
    if (intp(headers = ({mixed})news->GetHeaders(group)))
      FAIL(_decode (headers, actgroup));
    for (i = sizeof(headers); --i >= 0 && headers[i][M_ID] > lastid;);
    if (!(i = sizeof(headers)-1-i)) return -1;
    return i;
  }
  return -1;
}

/*-------------------------------------------------------------------------
** Check actgroup for unread notes and print according message.
** If <newgroup> is given: try to change actgroup.
** Return 0 for failure, 1 for success (no unread news),
** and -n for success (n unread news).
*/

varargs int _chg_act (string newgroup, int silent) {
  object news;
  mixed data;
  int i;

  if (newgroup && newgroup == actgroup) return 1;
  if (!(news = _newsserver())) return 0;
  if (!newgroup && !(newgroup = actgroup))
    FAIL ("No group specified.\n");
  if ((data = ({mixed})news->GetStatus(newgroup)) == NEWS_ILLPARM)
    FAIL ("No such group '"+newgroup+"'.\n");
  if (member(unsub, newgroup) && !silent) {
    write ("Group '"+newgroup+"' is currently ignored.\n");
  }
  actgroup = newgroup;
  if (!(i = _count_unread(actgroup, data[0]))) return 0;
  if (!silent) {
    write (actgroup+": ");
    if (i < 0) write ("Nothing new in this group.\n");
    else write ("There are "+i+" unread notes in this group.\n");
  }
  return (i < 0 ? 1 : -i);
}

/*-------------------------------------------------------------------------
** More a note to the player. Return success.
*/

varargs int _display_note (mixed *msg, int allgroups, string footer) {
  string header;

  if (!msg) FAIL ("No note available.\n");
  header = msg[M_WRITER] + " [";
  if (pointerp(msg[M_LEVEL])) header += msg[M_LEVEL][0]+"/"+msg[M_LEVEL][1];
  else header += query_user_tag(msg[M_LEVEL]);
  header += "] -- "+stime(msg[M_TIME], SD_SDATE | SD_TIME);
  if (msg[M_FLAGS] && -1 != member(msg[M_FLAGS], MF_LOCKED))
    header += " -- Locked";
  header += "\n";
  if (allgroups && !sizeof(msg[M_GROUPS])) header += "Groups: <none>\n";
  else if (allgroups || sizeof(msg[M_GROUPS]) > 1)
    header += "Groups: "+implode(msg[M_GROUPS], ",")+"\n";
  header += " -- "+msg[M_TITLE]+" --\n";
  if (!stringp(footer))
    footer = "";
  smore (header+msg[M_TEXT]+footer, ({int})PL->Query(P_PAGESIZE));
  return 1;
}

/*-------------------------------------------------------------------------
** Go to the next/previous group. 'trash', and optionally all groups
** with read news, are skipped.
** Result is success, and -1 for 'no more unread groups'.
*/

int _next (int prevp, int unreadp) {
  int ix, last, rc, dir, flag;
  string *names;
  object news;

  if (!(news = _newsserver())) return 1;

  names = ({string *})news->GetNames() - m_indices(unsub);
  if (!prevp) {
    if (!actgroup || (ix = member(names, actgroup)) == -1) ix = -1;
    dir = 1;
  }
  else {
    if (!actgroup || (ix = member(names, actgroup)) == -1) ix = 0;
    dir = -1;
  }
  if (!unreadp) {
    if (names[(ix+dir) % sizeof(names)] == TRASH) ix += dir;
    return _chg_act (names[(ix+dir) % sizeof(names)], 0);
  }

  ix += sizeof(names);
  last = ix % sizeof(names);
  flag = 0;
  do {
    if (names[(ix+dir) % sizeof(names)] != TRASH)
      rc = _chg_act (names[(ix+dir) % sizeof(names)], 1);
    ix = (ix+dir) % sizeof(names);
    if (last == ix && flag++) {
      write ("No more unread news.\n");
      rc = _chg_act (names[last], 1);
      return -1;
    }
  } while (rc >= 0);
  write (actgroup+": ");
  write ("There are "+(-rc)+" unread notes in this group.\n");
  return 1;
}

/*-------------------------------------------------------------------------
** Command 'help'
*/

int fhelp (string arg) {
  if (!check_owner()) return 0;
  if (arg && id(arg)) {
    write (
 "\n"
+"Newsmatrix "+VER_REV
              +" ["+REVTAG+"] - Mateese, Biontic Magics & Darkness.\n"
+"\n"
+"This tool is also for reading the news as for managin the news-demon.\n"
+"The commands are:\n"
+"  list                  : list notes and groups.\n"
+"  read, store, clear    : read and store notes, clear buffers\n"
+"  catchup               : marks notes as read\n"
+"  note, add, reply,\n"
+"  subj, incl, edit      : create new notes\n"
+"  post, remove          : post / remove a note.\n"
+"  lock, unlock          : lock / unlock a note.\n"
+"  mkgroup, rmgroup      : creation/removal of groups.\n"
+"  setgroup              : change the characteristics of groups.\n"
+"  addright, rmright     : add rights for groups.\n"
+"  set, next, prev       : selection of groups for access.\n"
+"  ignore, regard        : (un)subscription of groups\n"
+"\n"
+"All commands give specific info when given as '<cmd> ?', e.g. 'list ?'.\n"
+"  Also try 'help rights' for info about the access-rights, and\n"
+"  read /doc/concepts/news.\n"
+"All commands may be preceded by 'news', e.g. 'news list', in case some\n"
+"  other objects (boards!) defined the same commands.\n"
+"Some commands accept patterns as argument. These are always regular\n"
+" expressions like the ones used in ed, see /doc/efun/regexp,\n"
+" except that '.' and '\\.' exchanged their meanings and every pattern\n"
+" is internally enclosed in '^$'.\n"
+"Of course you need to be of sufficient level for the various actions, and\n"
+" some commands work only if the matrix has you euid.\n"
+"The matrix ids as 'newsmatrix' and 'matrix'.\n"
+"\n"
          );
    return 1;
  }
  if (arg == "rights") {
    write (
 "\nNews - Rights handling.\n\n"
+"Each of the actions 'read note', 'write note', 'delete note' and\n"
+" 'handling of subgroups' has specification of who is permitted to\n"
+" to that. A similar specification exists for who 'owns' the group\n"
+" (the owner may do anything).\n"
+"Each right consists of an userlevel and some optional strings.\n"
+" The userlevel can be defined by its proper name ('player', 'ancient',\n"
+" 'wizard') or the associated integer value.\n"
+" The integer defines the minimal needed userlevel for permission.\n"
+" The strings define permitted users directly by name, or indirectly\n"
+" by domain. The syntax is:\n"
+"   <name>    : specifies one user.\n"
+"   $<domain> : specifies all domain-members.\n"
+"   +<domain> : specifies all domain-(vice)lords.\n"
+"   *<domain> : specifies the domain-lord.\n"
+"   @<object> : <object>->CheckRights(euid) checks the right.\n"
+" It is sufficient to meet one of the criterias (either level or name)\n"
+" to get permission.\n"
+"\n"
          );
    return 1;
  }
  return 0;
}

/*-------------------------------------------------------------------------
** Command 'list'
*/

int flist (string arg) {
  string *args, pattern, line, text;
  int state, i, j;
  object news;
  mixed data;

  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "[news] list [<groupname>] [full]\n"
+"  Lists the last notes in <groupname> or the current group.\n"
+"  If 'full' is specified, all notes are listed.\n"
+"[news] list groups [<pattern>]\n"
+"  Lists the names of all groups (or all names matching <pattern>).\n"
+"  Groups with unread notes are marked with '*'.\n"
+"[news] list unread [<pattern>]\n"
+"  Lists the names of all groups (or all names matching <pattern>)\n"
+"  with unread news.\n"
+"[news] list rights [<pattern>]\n"
+"  Lists your rights in all groups (or all names matching <pattern>).\n"
+"[news] list status [<pattern>]\n"
+"  Lists the names of all groups (or all names matching <pattern>) and\n"
+"  some extended info about them (includes ignored groups).\n"
+"[news] list ignored\n"
+"  List the names of all ignored groups.\n"
+"[news] list demon\n"
+"  List some internal info of the news demon.\n"
        );

  if (!(news = _newsserver())) return 1;

  if (!arg && !(arg = actgroup)) FAIL("You specified no group to list.\n");

  if (sizeof(args = old_explode(lower_case(arg), " ")) <= 2
      && member(({ "groups", "status",  "demon",  "rights"
                                 , "unread", "ignored" }), args[0]
                      ) == -1
     ) {
    mixed headers;
    int   full;

    if (arg == "full") {
      full = 1;
      if (!(arg = actgroup)) FAIL("You specified no group to list.\n");
    }
    else if (sizeof(args) > 1 && args[1] == "full") {
      full = 1;
      arg = args[0];
    }
    if (intp(headers = ({mixed})news->GetHeaders(arg)))
      FAIL(_decode (headers, arg));
    write ("Group '"+arg+"' contains "+sizeof(headers)+" notes.\n\n");
    text = "";
    i = 0;
    if (!full && sizeof(headers) > NO_NOTES)
      i = sizeof(headers)-NO_NOTES;
    for ( ; i < sizeof(headers); i++) {
      line = radjust (""+(i+1),2);
      if (headers[i][M_FLAGS] && -1 != member(headers[i][M_FLAGS], MF_LOCKED))
        line += "*";
      else
        line += ":";
      line += " "+stime(headers[i][M_TIME], SD_SDATE);
      line += " [";
      if (pointerp(headers[i][M_LEVEL]))
        line += radjust(""+headers[i][M_LEVEL][0],2)+"/"
                +radjust(""+headers[i][M_LEVEL][1],2);
      else line += radjust(query_user_tag(headers[i][M_LEVEL]),5);
      line += "] "+ladjust(headers[i][M_WRITER],10);
      line += " "+headers[i][M_TITLE];
      text += ladjcut(line, 77)+"\n";
    }
    smore(text, ({int})PL->Query(P_PAGESIZE));
    return 1;
  }

  if (sizeof(args) == 1 && args[0] == "demon") {
    data = ({mixed})news->GetInterna();
    write (
 "News-Demon "+data[NEWS_IVERSION]+" at "+stime(time(), SD_DATE|SD_TIME)+"\n"
+"  "+data[NEWS_ICNTGRPS]+" groups known, "+data[NEWS_ICNTCACHE]+" cached.\n"
+"  Cache-clear every "+(data[NEWS_ITIMEINT]/60)+" min, hold-threshold is "
  +data[NEWS_IMINTOUCH]+" touches per interval.\n"
+(data[NEWS_ILASTFLUSH] ?
    "  Last clear on: "+stime(data[NEWS_ILASTFLUSH], SD_DATE|SD_TIME)+".\n"
    : ""
  )
+"  Save-delay is "+(data[NEWS_IDSAVEINT]/60)+" min, "
  +(data[NEWS_IDSAVEPEND] == -1 ? "no save pending.\n"
    : "save scheduled for "
      +stime(time()+data[NEWS_IDSAVEPEND], SD_DATE|SD_TIME)+".\n"
   )
          );
    return 1;
  }

  if (args[0] == "rights") {
    if (sizeof(args) > 2) FAIL ("Too much arguments.\n");
    pattern = (sizeof(args) == 2) ? args[1] : 0;

    args = ({string *})news->GetNames(_adapt_pattern(pattern)) - m_indices(unsub);
    write ("There are "+sizeof(args)+" matching groups.\n");
    text = "";
    for (i = 0; i < sizeof(args); i++) {
      text += args[i]+"\n  ";
      if (intp(data = ({mixed})news->GetGroup(args[i])))
        text +=_decode (data, args[i]);
      else {
        line = "";
        if (({int})news->CheckRights(data[G_OWNER]))
          text += "You have owner-rights on this group.\n  ";
        for (j = G_READ; j <= G_SUBGROUP; j++)
          if (({int})news->CheckRights(data[j])) {
            if (line != "") line += ", ";
            line += ({ "read notes", "write notes"
                     , "delete notes", "mangle subgroups"
                    })[j-G_READ];
          }
        text += (line != "" ? "You may "+line+".\n"
                            : "You can't do anything.\n"
                );
      }
    }
    smore (text, ({int})PL->Query(P_PAGESIZE));
    return 1;
  }

  if (sizeof(args) > 2) FAIL ("Too much arguments.\n");
  state = member(({ "groups",  "status", "unread", "ignored" }), args[0]);
  if (state == -1) FAIL ("What?\n");

  pattern = (sizeof(args) == 2) ? args[1] : 0;

  args = ({string *})news->GetNames (_adapt_pattern(pattern));
  if (member(({ 0, 2 }), state) != -1) args = args - m_indices(unsub);
  else if (state == 3) args = args & unsub;
  write ("There are "+sizeof(args)+" matching groups.\n");
  j = 0;
  text = "";
  for (i = 0; i < sizeof(args); i++) {
    data = (({mixed})news->GetStatus (args[i]))[0];
    if (_get_lastid(args[i]) < data[G_LASTID]) text += " * ";
    else if (state == 2) continue;
    else text += "   ";
    j++;
    text += ladjust (args[i], 30);
    if (state != 2) {
      if (!data[G_ACTMSG]) text += ": No notes.";
      else text += ": "+data[G_ACTMSG]+" notes.";
    }
    if (state != 1) { text += "\n"; continue; }
    text += " ("
            + (data[G_USAGE] < 0 ? "not cached" : data[G_USAGE]+" accesses")
            + (member(unsub, args[i]) ? "" : ", unsubscribed" )
            +")\n";
    text += "     "+implode(_gdsc2str(data, news), "\n     ")+"\n";
  }
  if (state == 2)
    if (j) text += j+" groups have unread news.\n";
    else text += "No unread news anywhere.\n";
  smore (text, ({int})PL->Query(P_PAGESIZE));
  return 1;
}

/*-------------------------------------------------------------------------
** Command 'mkgroup', 'addgroup'
*/

int fmkgroup (string arg) {
  string *args;
  int i, rc;
  object news;
  mixed data;

  if (!check_owner()) return 0;
  USAGE (!arg || arg == "?",
 "[news] mkgroup <groupname> [<groupname>..<groupname>]\n"
+"  Creates the named group(s) (if you're permitted to).\n"
+"Syn.: [news] addgroup\n"
        );

  if (!(news = _newsserver())) return 1;

  args = old_explode(arg, " ");
  for (i = 0; i < sizeof(args); i++) {
    if (i) write ("\n");
    write ("Creating '"+args[i]+"': "
          +_decode ((rc = ({int})news->AddGroup (args[i])), args[i]
                   , "Done - using existing savefile.\n"
                   )
          );
    if (rc == NEWS_OK || rc == NEWS_ILLFILE) {
      data = (({mixed})news->GetStatus (lower_case(args[i])))[0];
      write ("Status:\n");
      write ("  "+implode(_gdsc2str(data, news), "\n  ")+"\n");
    }
  }
  return 1;
}

int faddgroup (string arg) { return fmkgroup (arg); }

/*-------------------------------------------------------------------------
** Command 'rmgroup'
*/

int frmgroup (string arg) {
  string *args, *names;
  int i, j;
  object news;

  if (!check_owner()) return 0;
  USAGE (!arg || arg == "?",
 "[news] rmgroup <groupname> [<groupname>..<groupname>]\n"
+"  Creates the named group(s) (if you're permitted to).\n"
+"  Each of the names may also be a pattern.\n"
        );

  if (!(news = _newsserver())) return 1;

  args = old_explode (lower_case(arg), " ");
  for (i = 0; i < sizeof(args); i++) {
    names = ({string *})news->GetNames (_adapt_pattern(args[i]));
    for (j = 0; j < sizeof(names); j++)
      write ("Removing '"+names[j]+"': "
            +_decode (({int})news->RemoveGroup (names[j]), names[j])
            );
  }
  return 1;
}

/*-------------------------------------------------------------------------
** Command 'setgroup'
*/

int fsetgroup (string arg) {
  string *args, *names;
  int i, j, rc;
  object news;
  mixed data, *dsc, *flag;

  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "[news] setgroup [<pattern>] <arg>...\n"
+"  Changes the characteristics of group <pattern> (or the current group)\n"
+"  to <arg>s. One <arg> may be:\n"
+"    owner | read | write | delete | subgrp { <level> | <name> }\n"
+"      Specifies the resp. rights.\n"
+"    max <num> [exp/ire]\n"
+"      Allows max. <num> notes, optionally with auto-removal.\n"
+"    max unlim/ited\n"
+"      Allows unlimited notes.\n"
+"    log off | new | exp/ire\n"
+"      Sets logging mode.\n"
+"    logger <name> | none\n"
+"      Sets the name of the logger-object.\n"
+"  Unspecified characteristics aren't changed.\n"
        );

  if (!(news = _newsserver())) return 1;

  if (!arg && !(arg = actgroup)) FAIL ("You specified no group to set.\n");

  args = old_explode (lower_case(arg), " ");

  if (   !sizeof(names = ({string *})news->GetNames(_adapt_pattern(args[0])))
      && args[0] != actgroup) {
    args = ({ actgroup }) + args;
    names = ({string *})news->GetNames(_adapt_pattern(actgroup));
  }
  if (!sizeof(names))
    FAIL ("No matching groups.\n");

  if (!(data = _parse_gdsc(args, 0))) return 0;
  dsc = data[0]; flag = data[1];
  for (i = 0; i < sizeof(names); i++) {
    if (i) write ("\n");
    write ("Setting '"+names[i]+"': ");
    data = (({mixed})news->GetGroup (names[i]));
    for (j = 0; j < sizeof(flag); j++) if (flag[j]) data[j] = dsc[j];
    rc = ({int})news->SetGroup (data);
    write (_decode (rc, names[i]));
    if (rc == NEWS_OK) {
      write ("Status:\n");
      write ("  "+implode(_gdsc2str(({mixed})news->GetGroup(names[i]), news)
                         , "\n  ")
             +"\n");
    }
  }
  return 1;
}

/*-------------------------------------------------------------------------
** Command 'setright', 'addright', 'rmright'
*/

varargs int fsetright (string arg, int rmrights) {
  string *args, *names;
  int i, j, rc;
  object news;
  mixed data, *dsc, *flag;

  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "[news] "+(rmrights ? "rmright" : "addright")+" [<pattern>] <right> ...\n"
+"  "+(rmrights ? "Removes the <right>s"
                : "Adds the <right>s")
     +" for the group <pattern> (or the current group).\n"
+"  One <right> is:\n"
+"    owner | read | write | delete | subgrp { <level> | <name> }\n"
+"      Specifies the resp. rights.\n"
+"  Unspecified rights aren't changed.\n"
+(rmrights ? "" : "Syn.: [news] setright\n")
        );

  if (!(news = _newsserver())) return 1;

  if (!arg && !(arg = actgroup)) FAIL ("You specified no group to set.\n");

  args = old_explode (lower_case(arg), " ");

  if (   !sizeof(names = ({string *})news->GetNames(_adapt_pattern(args[0])))
      && args[0] != actgroup
     ) {
    args = ({ actgroup }) + args;
    names = ({string *})news->GetNames(_adapt_pattern(actgroup));
  }
  if (!sizeof(names))
    FAIL ("No matching groups.\n");

  if (!(data = _parse_gdsc(args, 1))) return 0;
  dsc = data[0]; flag = data[1];
  for (i = 0; i < sizeof(names); i++) {
    if (i) write ("\n");
    write ("Setting '"+names[i]+"': ");
    for (j = G_OWNER; j <= G_SUBGROUP; j++) {
      if (!flag[j]) continue;
      if (rmrights) rc = ({int})news->RemoveRights (names[i], j, dsc[j]);
      else          rc = ({int})news->AddRights (names[i], j, dsc[j]);
      if (rc != NEWS_OK) break;
    }
    write (_decode(rc, names[i]));
  }
  return 1;
}

int faddright (string arg) { return fsetright (arg); }
int frmright (string arg) { return fsetright (arg, 1); }

/*-------------------------------------------------------------------------
** Command 'clear'
*/

int fclear (string arg) {
  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "[news] clear [prep | read | both]\n"
+"  Clears one or both note buffers, default is 'prep'.\n"
        );

  if (!arg) arg = "prep";
  switch (arg) {
    case "prep": writemsg = 0; write ("Prepared note cleared.\n"); break;
    case "read": msgread = 0; write ("Read note cleared.\n"); break;
    case "both": writemsg = 0; msgread = 0;
                 write ("Both buffers cleared.\n");
                 break;
    default: FAIL ("Illegal arg '"+arg+"'.\n");
  }
  return 1;
}

/*-------------------------------------------------------------------------
** Command 'set'
*/

int fset (string arg) {
  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "[news] set [<groupname>]\n"
+"  Sets or displays the current groupname.\n"
        );

  if (!arg) {
    if (!actgroup) write ("No current group.\n");
    else write ("Current group: "+actgroup+"\n");
    return 1;
  }
  return _chg_act (arg);
}

/*-------------------------------------------------------------------------
** Command 'next', 'prev'
*/

varargs int fnext (string arg, int prevg) {
  if (!check_owner()) return 0;
  USAGE (arg == "?" || (arg && arg != "new"),
 "[news] "+(prevg ? "prev" : "next")+" [new]\n"
+"  Goes to the "+(prevg ? "previous" : "next")
  +" group (the trash-group is skipped).\n"
+"  If 'unread' is specified, only unread groups are visited.\n"
        );

  return _next (prevg, !!arg);
}

int fprev (string arg) { return fnext (arg, 1); }

/*-------------------------------------------------------------------------
** Command 'lock', 'unlock'
*/

varargs int flock (string arg, int unlock) {
  string *args, groupname;
  int i, *nr;
  mixed val;
  object news;

  if (!check_owner()) return 0;
  if (unlock)
  {
    USAGE (!arg || arg == "?",
 "[news] lock [[group] <groupname>] <no>...\n"
+"  Unlocks the <no>th's notes in the current group.\n"
+"  If <groupname> is specified, the current group is changed to it before.\n"
          );
  }
  else
  {
    USAGE (!arg || arg == "?",
 "[news] unlock [[group] <groupname>] <no>...\n"
+"  Locks the <no>th's notes in the current group against expire/deletes.\n"
+"  If <groupname> is specified, the current group is changed to it before.\n"
          );
  }

  if (!(news = _newsserver())) return 1;

  args = old_explode(arg, " ");
  nr = ({});
  i = 0;
  while (i < sizeof(args)) {
    if (args[i] == "group") {
      if (++i >= sizeof(args)) FAIL ("Not enough arguments.\n");
      groupname = args[i++];
    }
    else if (!sscanf (args[i], "%d", val)) groupname = args[i++];
    if (i >= sizeof(args)) break;
    if (args[i] == "note" && ++i >= sizeof(args))
      FAIL ("Not enough arguments.\n");
    break;
  }

  for (; i < sizeof(args); i++) {
    if (!sscanf (args[i], "%d", val) || args[i] != ""+val || val <= 0)
      FAIL ("Illegal arg '"+args[i]+"'.\n");
    nr += ({ val });
  }

  if (!sizeof(nr)) FAIL ("Not enough arguments.\n");

  if (groupname && !_chg_act(groupname)) return 0;
  if (!actgroup) FAIL ("You specified no group to remove from.\n");
  if (groupname) write ("\n");
  for (i = 0; i < sizeof(nr); i++) {
    if (intp(val = ({mixed})news->GetHeaders(actgroup, nr[i])))
      write ("Can't "+(unlock ? "unlock" : "lock")+" "+actgroup+" #"+nr[i]+": "
             +_decode(val, actgroup, "Note not found.\n")
            );
    else if (unlock)
      write ("Unlocking "+actgroup+" #"+nr[i]+" '"+val[M_TITLE]+"': "
           +_decode((val = ({int})news->RemoveFlag(actgroup, nr[i], MF_LOCKED))
                   , actgroup, "Note not found.\n"
                   )
          );
    else
      write ("Locking "+actgroup+" #"+nr[i]+" '"+val[M_TITLE]+"': "
           +_decode((val = ({int})news->AddFlag(actgroup, nr[i],MF_LOCKED))
                   , actgroup, "Note not found.\n"
                   )
          );
    if (val != NEWS_OK) break;
  }
  return 1;
}

int funlock (string arg) { return flock (arg, 1); }

/*-------------------------------------------------------------------------
** Command 'remove'
*/

int fremove (string arg) {
  string *args, groupname;
  int i, *nr;
  mixed val;
  object news;

  if (!check_owner()) return 0;
  USAGE (!arg || arg == "?",
 "[news] remove [[group] <groupname>] <no>...\n"
+"  Removes the <no>th's notes in the current group.\n"
+"  If <groupname> is specified, the current group is changed to it before.\n"
        );

  if (!(news = _newsserver())) return 1;

  args = old_explode(arg, " ");
  nr = ({});
  i = 0;
  while (i < sizeof(args)) {
    if (args[i] == "group") {
      if (++i >= sizeof(args)) FAIL ("Not enough arguments.\n");
      groupname = args[i++];
    }
    else if (!sscanf (args[i], "%d", val)) groupname = args[i++];
    if (i >= sizeof(args)) break;
    if (args[i] == "note" && ++i >= sizeof(args))
      FAIL ("Not enough arguments.\n");
    break;
  }

  for (; i < sizeof(args); i++) {
    if (!sscanf (args[i], "%d", val) || args[i] != ""+val || val <= 0)
      FAIL ("Illegal arg '"+args[i]+"'.\n");
    nr += ({ val });
  }

  if (!sizeof(nr)) FAIL ("Not enough arguments.\n");

  if (groupname && !_chg_act(groupname)) return 0;
  if (!actgroup) FAIL ("You specified no group to remove from.\n");
  if (groupname) write ("\n");
  for (i = 0; i < sizeof(nr); i++) {
    if (intp(val = ({mixed})news->GetHeaders(actgroup, nr[i])))
      write ("Can't remove "+actgroup+" #"+nr[i]+": "
             +_decode(val, actgroup, "Note not found.\n")
            );
    else
      write ("Removing "+actgroup+" #"+nr[i]+" '"+val[M_TITLE]+"': "
           +_decode((val = ({int})news->RemoveNote (actgroup, nr[i]))
                   , actgroup, "Note not found.\n"
                   )
          );
    if (val != NEWS_OK) break;
  }
  return 1;
}

/*-------------------------------------------------------------------------
** Command 'read'
*/

int fread (string arg) {
  string *args, groupname, lastid, footer;
  int i, nr;
  object news;
  mixed msg;

  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "[news] read [[group] <groupname>] [new | <no>]\n"
+"  Read the next new or the <no>th note in the current group.\n"
+"  The note is also stored in an internal buffer.\n"
+"  If <groupname> is specified, the current group is changed to it before.\n"
+"  When reading new notes, groups are changed automatically.\n"
+"[news] read last\n"
+"  Rereads the last note from the internal buffer.\n"
+"[news] read prep\n"
+"  Reviews the note currently under preparation.\n"
        );

  if (!(news = _newsserver())) return 1;

  if (arg == "prep") {
    if (!writemsg) FAIL ("No note under preparation.\n");
    return _display_note (writemsg, 1, "[End of prepared note]\n");
  }

  if (arg != "last") {
    args = ({});
    if (arg) args = old_explode(arg, " ");
    i = 0; nr = -1;
    while (i < sizeof(args)) {
      if (args[i] == "group") {
        if (++i >= sizeof(args)) FAIL ("Not enough arguments.\n");
        groupname = args[i++];
      }
      else if (   args[i] != "new" && args[i] != "note"
               && !sscanf (args[i], "%d", nr)
              ) groupname = args[i++];
      if (i >= sizeof(args)) break;
      if (args[i] == "new") break;
      if (!sscanf (args[i], "%d", nr) || args[i] != ""+nr || nr <= 0)
        FAIL ("Illegal arg '"+args[i]+"'.\n");
      break;
    }
    if (i+1 < sizeof(args)) FAIL ("Too much arguments.\n");

    if (groupname && !_chg_act(groupname)) return 0;
    if (!actgroup) FAIL ("You specified no group to read.\n");
    if (groupname) write ("\n");
    msg = ({mixed})news->GetNote (actgroup, (nr > 0 ? nr : 0));
    if (intp(msg))
      FAIL (_decode (msg, actgroup
                    , (nr<=0?"Note not found.\n":"Not that many notes.\n")
                    )
           );
    if (nr > 0) msgread = msg;
    else {
      lastid = _get_lastid(actgroup);
      for (i = 0; i < sizeof(msg); i++)
        if (msg[i][M_ID] > lastid) break;
      if (i >= sizeof(msg)) {
        if (_next (0, 1) < 1) return 1;
        msg = ({mixed})news->GetNote (actgroup, 0);
        if (intp(msg))
          FAIL (_decode (msg, actgroup, "Note not found.\n"));
        lastid = _get_lastid(actgroup);
        for (i = 0; i < sizeof(msg); i++)
          if (msg[i][M_ID] > lastid) break;
      }
      if (i >= sizeof(msg)) {
        write ("No more new notes.\n");
        return 1;
      }
      write (actgroup+": "+(i+1)+"\n");
      msgread = msg[i];
    }
  }
  if (msgread) _set_lastid (actgroup, msgread[M_ID]);
  footer = "[End of "+actgroup+":"+(nr > 0?nr:i+1)+"]\n";
  return _display_note (msgread, 0, footer);
}

/*-------------------------------------------------------------------------
** Command 'store'
*/

int fstore (string arg) {
  string filename, header;
  int which;
  mixed *msg;

  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "[news] store [<filename>]\n"
+"  Stores the last read note as <filename> (default is 'news').\n"
+"[news] store prep [<filename>]\n"
+"  Stores the currently prepared note as <filename> (default is 'pnote').\n"
        );

  if (!check_euid(0, PL)) return 1;

  if (!arg) filename = "news";
  else if (sscanf (arg, "prep %s", filename)) which = 1;
  else filename = arg;

  msg = (which ? writemsg : msgread);
  if (!msg) FAIL ("No note available.\n");

  filename = ({string})PL->get_path(filename);
  if (({int})PL->is_dir(filename)) FAIL ("'"+filename+"' is a directory.\n");
  write ("Appending note to "+filename+"\n");
  header = mkstr (76, "-")
           +"ID: "+msg[M_ID]+"\n"
           +"Groups: "+implode(msg[M_GROUPS],", ")+"\n"
           +"Author: "+msg[M_WRITER]+" [";
  if (pointerp(msg[M_LEVEL]))
    header += msg[M_LEVEL][0]+"/"+msg[M_LEVEL][1];
  else header += query_user_tag(msg[M_LEVEL]);
  header += "]\t\t\t\t"+stime(msg[M_TIME], SD_DATE | SD_TIME) + "\n\n"
           +" -- "+msg[M_TITLE]+" --\n";
  if (sizeof(msg[M_GROUPS]) > 1)
    header += "  Groups: "+implode(msg[M_GROUPS], ", ")+"\n";
  header += msg[M_TITLE]+"\n"+msg[M_TEXT];
  if (!write_file (filename, header)) write ("Error during writing!\n");
  return 1;
}

/*-------------------------------------------------------------------------
** Command 'reply' - calls write_note() for actual writing
*/

int freply (string arg) {
  string *args, groupname;
  int i, nr;
  object news;
  mixed msg;

  if (!check_owner()) return 0;
USAGE (arg == "?",
 "[news] reply [[group <groupname>] [note] <nr>] [<title>]\n"
+"  Start a new note as a reply to the last one read. If <title> is not\n"
+"  given, the read title (if necessary with leading 'Re: ') is chosen.\n"
+"  Specifying <nr> with or w/o <groupname> loads the specified note\n"
+"  into the internal buffer as if read.\n"
       );

  if (mutex) FAIL ("You ARE already writing a note!\n");

  nr = -1;
  if (arg) {
    args = ({});
    if (arg) args = old_explode(arg, " ");
    i = 0; groupname = actgroup;
    if (args[i] == "group") {
      if (++i >= sizeof(args)) FAIL ("Not enough arguments.\n");
      groupname = args[i++];
    }
    if (args[i] == "note") {
      if (++i >= sizeof(args)) FAIL ("Not enough arguments.\n");
      if (!sscanf (args[i], "%d", nr) || args[i] != ""+nr || nr <= 0)
        FAIL ("Illegal value '"+args[i]+"' for 'note'.\n");
    }
    else if (!sscanf (args[i], "%d", nr) || args[i] != ""+nr || nr <= 0)
      nr = -1;
    if (nr > 0) i++;
    if (i) arg = implode(args[i..sizeof(args)], " ");
  }

  if (nr >= 0) {
    if (!groupname) FAIL ("You specified no group to read.\n");
    if (!(news = _newsserver())) return 1;
    if ((({int})news->GetStatus(groupname)) == NEWS_ILLPARM)
      FAIL ("No such group '"+groupname+"'.\n");
    msg = ({mixed})news->GetNote (groupname, nr);
    if (intp(msg))
      FAIL (_decode (msg, groupname, "Not that many notes.\n"));
    msgread = msg;
    write ("Replying to "+groupname+" #"+nr+" '"+msg[M_TITLE]+"'\n");
  }

  _mk_writemsg();
  if (actgroup) writemsg[M_GROUPS] = ({ actgroup });

  if (arg && sizeof(arg)) writemsg[M_TITLE] = arg;
  if (!msgread) FAIL ("You read nothing to reply to.\n");
  if (!arg || !sizeof(arg)) {
    string foo;
    if (arg = msgread[M_TITLE]) {
      if (sscanf(capitalize(arg), "Re: %s", foo)) arg = foo;
      writemsg[M_TITLE] = "Re: "+arg;
    }
  }
  write ("Starting a new reply '"+writemsg[M_TITLE]+"'\n");

  write ("Enter your text; finish with '**' or '.'; help with '~h'.\n]");
  input_to ("write_note");
  mutex = 1;
  return 1;
}

/*-------------------------------------------------------------------------
** Command 'note', 'add'
*/

varargs int fnote (string arg, int mode) {
  if (!check_owner()) return 0;
  switch (mode) {
  case 0: USAGE (arg == "?",
 "[news] note [<title>]\n"
+"  Starts a new note, optionally with title <title>.\n"
                );
  case 1: USAGE (arg == "?",
 "[news] add [<title>]\n"
+"  Continues a new note, optionally with title <title>.\n"
          );
  }

  if (mutex) FAIL ("You ARE already writing a note!\n");

 if (mode != 1 || !writemsg) {
    write ("Ok, starting a new note.\n");
    _mk_writemsg();
    if (actgroup) writemsg[M_GROUPS] = ({ actgroup });
  }
  if (arg) writemsg[M_TITLE] = arg;

  write ("Enter your text; finish with '**' or '.'; help with '~h'.\n]");
  input_to ("write_note");
  mutex = 1;
  return 1;
}

int fadd(string arg) { return fnote (arg, 1); }

void write_note (string line) {
  if (!line) line = "";
  if (line == "~h" || line == "~?")
    write ("You are preparing a note for later posting. Commands are:\n"
          +"  '**' , '.' : End the input ('~' and '~q' serve as well).\n"
          +"  '~r'       : Redisplay what you've written so far.\n"
          +"  '~i note'  : include the note last read.\n"
          +"  '~i <file>': include the contents of the specified file.\n"
          +"  '~h', '~?' : this help.\n"
          );
  else if (line == "**" || line == ".") {
    mutex = 0;
    write ("Don't forget to 'post' your note.\n");
    return;
  }
  else if (line == "~" || line == "~q") {
    mutex = 0;
    write ("Ok.\n");
    return;
  }
  else if (line == "~r")
    write ("You wrote so far:\n--\n"+writemsg[M_TEXT]+"--\n");
  else if (sizeof(line) > 2 && line[0..1] == "~i") {
    line = old_explode(line[2..sizeof(line)]," ")[0];
    if (!line) write ("Include what?\n");
    else if (line == "note") {
      if (!msgread) write ("No read note available for include.\n");
      else {
        writemsg[M_TEXT] += msgread[M_TEXT];
        write ("Included.\n");
      }
    }
    else {
      string fname;
      fname = ({string})PL->get_path(line);
      if (!({int})PL->is_file(fname)) write ("'"+fname+"' is not a valid file.\n");
      else if (!(line = read_file(fname)))
        write ("Can't read file '"+fname+"'.\n");
      else {
        writemsg[M_TEXT] += line;
        write ("Included.\n");
      }
    }
  }
  else  writemsg[M_TEXT] += implode(break_line (line, 77), "\n")+"\n";
  write ("]");
  input_to ("write_note");
}

/*-------------------------------------------------------------------------
** Command 'incl'
*/

int fincl (string arg) {
  string file, fname;

  if (!check_owner()) return 0;
  USAGE (!arg || arg == "?",
 "[news] incl note | <filename>\n"
+"  Inserts either the specified file, or the last read note into the\n"
+"  note under writing.\n"
        );

  if (!writemsg) {
    write ("Ok, starting a new note!\n");
    _mk_writemsg();
  }

  if (arg == "note") {
    if (!msgread) FAIL ("No read note available for include.\n");
    file = msgread[M_TEXT];
  }
  else {
    fname = ({string})PL->get_path(arg);
    if (!({int})PL->is_file(fname)) FAIL ("'"+fname+"' is not a valid file.\n");
    if (!(file = read_file(fname)))
      FAIL ("Can't read file '"+fname+"'.\n");
    write ("Read file '"+fname+"'.\n");
  }

  writemsg[M_TEXT] += file;
  if (arg == "note") write ("Ok.\n");

  return 1;
}

/*-------------------------------------------------------------------------
** Command 'edit'
*/

varargs int fedit (string arg) {
  int i;
  string fname;

  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "[news] edit [<title>]\n"
+"  Edit the note under preparation with ed.\n"
        );

  if (!check_euid(0, PL)) return 0;

  if (mutex) FAIL ("You ARE already editing a note!\n");

  if (!writemsg) {
    write ("Ok, starting a new note.\n");
    _mk_writemsg();
    if (actgroup) writemsg[M_GROUPS] = ({ actgroup });
  }

  if (arg) writemsg[M_TITLE] = arg;

  fname = WPATH+geteuid(ME)+"/.newsedit";
  if ((i = file_size(fname)) == -2)
    FAIL ("Error: Temporary '"+fname+"' is a directory.\n");
  if (i >= 0 && !rm (fname))
    FAIL ("Error: Can't remove old temporary '"+fname+"'.\n");
  write_file (fname, writemsg[M_TEXT]);
  mutex = 1;
  ed (fname, "note_edited");
  return 1;
}

void note_edited () {
  string fname, text, msg;
  int line, i;

  mutex = 0;
  fname = WPATH+geteuid(ME)+"/.newsedit";
  if ((i = file_size(fname)) == -2)
    msg = "Error: Temporary '"+fname+"' is a directory.\n";
  else if (i < 0) msg = "Error: Temporary '"+fname+"' not found.\n";
  else {
    writemsg[M_TEXT] = "";
    for (line = 1; (text = read_file(fname, line, 20)); line += 20)
      writemsg[M_TEXT] += text;
    msg = "Ok.\n";
  }
  if (PL) tell_object(PL, msg);
}

/*-------------------------------------------------------------------------
** Command 'subj'
*/

int fsubj (string arg) {
  if (!check_owner()) return 0;

  USAGE (!arg || arg == "?",
 "[news] subj <title>\n"
+"  Sets the title of the note in preparation to <title>.\n"
          );

  if (!writemsg) {
    write ("Ok, starting a new note.\n");
    _mk_writemsg();
  }
  writemsg[M_TITLE] = arg;
  write ("Ok.\n");
  return 1;
}

/*-------------------------------------------------------------------------
** Command 'post'
*/

int fpost (string arg) {
  string *args, *names, *match, fname, sig;
  int i;
  mixed rc;
  object news;

  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "[news] post [<pattern>...] [title <title>]\n"
+"  Posts the prepared note, optionally with new title <title>, in\n"
+"  the groups specified by <pattern>. The <patterns> may be separated\n"
+"  with spaces or ','. A single '+' represents the current group.\n"
+"  If no group is specified, the note is posted to the group in\n"
+"  it was prepared, else in the current one.\n"
+"  If you there is a file '~/.signature', it is appended to the note\n"
+"  before posting.\n"
         )

  if (!writemsg) FAIL ("There's no prepared note.\n");

  if (!(news = _newsserver())) return 1;

  if (arg) {
    args = old_explode(arg, " ");
    names = ({});
    for (i = 0;i < sizeof(args) && args[i] != "title"; i++)
      names += old_explode (args[i], ",");
    for (i = 0;i < sizeof(names); i++)
      if (names[i] == "+") names[i] = (actgroup ? actgroup : "");
    if (sizeof(names)) writemsg[M_GROUPS] = names;
    if (i < sizeof(args)) {
      if (i+1 >= sizeof(args)) FAIL ("Not enough arguments.\n");
      writemsg[M_TITLE] = implode (args[i+1..sizeof(args)], " ");
    }
  }
  else if (!writemsg[M_GROUPS] || !sizeof(writemsg[M_GROUPS]))
     writemsg[M_GROUPS] = ({ actgroup });

  names = ({string *})news->GetNames();
  args = ({});
  for (i = 0; i < sizeof(writemsg[M_GROUPS]) && sizeof(names); i++) {
    if (!(match = regexp(names, _adapt_pattern(writemsg[M_GROUPS][i])))) {
      write ("Faulty pattern '"+writemsg[M_GROUPS][i]+"'.\n");
      match = ({});
    }
    names -= match;
    args += match;
  }
  if (!sizeof(args)) write ("No (existing) groups specified.\n");
  else {
    sig = "";
    fname = ({string})PL->get_path("~/.signature");
    if (fname && file_size(fname) > 0 && writemsg[M_TEXT]) {
      write ("..appending ~/.signature\n");
      sig += read_file(fname);
    }
    if (!writemsg[M_TITLE] || writemsg[M_TITLE] == "")
      writemsg[M_TITLE] = "<untitled>";
    rc = ({int})news->StoreNote ( writemsg[M_TITLE]
                          , writemsg[M_TEXT]+sig
                          , args
                          );
    if (intp(rc)) write (_decode (rc));
    else {
      if (sizeof(rc)-1 != sizeof(args)) {
        for (i = 1; i < sizeof(rc); i++)
          args -= ({ old_explode (rc[i], ": ")[1] });
        arg = "Posted to: "+implode (args, ", ");
        write (implode (break_line (arg, 75, "  "), "\n")+"\n");
      }
      if (sizeof(rc) > 1) write (implode(rc[1..sizeof(rc)], "\n")+"\n");
    }
  }

  return 1;
}

/*-------------------------------------------------------------------------
** Command 'catchup'
*/

int fcatchup (string arg) {
  string *args, *names;
  int i;
  object news;
  mixed data;

  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "[news] catchup [<pattern>..]\n"
+"  Marks all notes in the specified groups (or the current one) as read.\n"
+"  '+' is a shorthand for the actual group.\n"
+"[news] catchup all\n"
+"  Marks all unread notes as read.\n"
        );

  if (!(news = _newsserver())) return 1;

  if (!arg && !(arg = actgroup)) FAIL ("You specified no group to set.\n");

  if (arg == "all") {
    args = ({string *})news->GetNames() - m_indices(unsub);
    names = ({});
    for (i = 0; i < sizeof(args); i++) {
      data = (({mixed})news->GetStatus (args[i]))[0];
      if (_get_lastid(args[i]) < data[G_LASTID])
        names += ({ args[i] });
      }
    if (!sizeof(names)) FAIL ("There's nothing to catch up.\n");
  }
  else {
    args = old_explode (string_replace (arg, "+", actgroup), " ");
    names = ({});
    for (i = 0; i < sizeof(args); i++)
      if (sizeof(data = ({mixed})news->GetNames(_adapt_pattern(args[i]))))
        names += data;

    names -= m_indices(unsub);
    if (!sizeof(names))
      FAIL ("No matching groups.\n");
  }

  write ("There are "+sizeof(names)+" matching groups.\n");

  for (i = 0; i < sizeof(names); i++) {
    write (ladjust(names[i],20)+": ");
    if (intp(data = ({mixed})news->GetStatus (names[i]))) {
      write (_decode (data, names[i]));
      continue;
    }
    _set_lastid(names[i], data[0][G_LASTID]);
    write ("Caught up.\n");
  }
  return 1;
}

/*-------------------------------------------------------------------------
** Command 'ignore'
*/

int fignore (string arg) {
  string *args, *names;
  int i;
  object news;
  mixed data;

  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "[news] ignore <pattern>..\n"
+"  Ignores the specified groups (use '+' for the current one).\n"
 "[news] ignore add [<pattern>..]\n"
+"  Additionally ignores the specified groups (or the current one).\n"
+"[news] ignore list\n"
+"  Lists all patterns used to ignore groups.\n"
+"[news] ignore refresh\n"
+"  Reevaluates all ignore patterns to catch newly created groups.\n"
+"'+' is a shorthand for the actual group.\n"
        );

  if (!(news = _newsserver())) return 1;
  if (!arg) FAIL ("You specified no group to set.\n");

  args = old_explode (string_replace (arg, "+", actgroup), " ");

  if (lower_case(args[0]) == "list")
  {
    if (sizeof(args) > 1)
      FAIL("Too much arguments.\n");
    if (!sizeof(ignpattern))
      write("No ignore patterns specified.\n");
    else
    {
      names=explode(sprintf("%-70#s", implode(ignpattern, "\n")), "\n");
      write(sizeof(ignpattern)+" ignore patterns:\n   "
            +implode(names, "\n   ")+"\n");
    }
    return 1;
  }

  if (lower_case(args[0]) == "add")
    ignpattern = ignpattern+args[1..];
  else if (lower_case(args[0]) == "refresh")
  {
    if (sizeof(args) > 1)
      FAIL("Too much arguments.\n");
    write("Refreshing list of ignored groups.\n");
  }
  else
    ignpattern = args;

  if (!sizeof(ignpattern))
    FAIL("No groups to ignore.\n");

  names = ({});
  for (i = 0; i < sizeof(ignpattern); i++)
  {
    data = ({mixed})news->GetNames(_adapt_pattern(ignpattern[i]));
    if (sizeof(data)) {
      data = data - names;
      names += data;
    }
  }

  names -= (names & unsub);
  if (!sizeof(names))
    FAIL ("No matching groups.\n");

  unsub = mkmapping(m_indices(unsub)+names);
  write ("There are "+sizeof(names)+" matching groups.\n");
  for (i = 0; i < sizeof(names); i++)
    write (ladjust(names[i],20)+": ignored.\n");

  return 1;
}

/*-------------------------------------------------------------------------
** Command 'regard'
*/

int fregard (string arg) {
  string *args, *names;
  int i;
  object news;
  mixed data;

  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "[news] regard [<pattern>..]\n"
+"  Un-Ignores the specified groups (or the current one).\n"
+"  '+' is a shorthand for the actual group.\n"
        );

  if (!(news = _newsserver())) return 1;
  if (!arg && !(arg = actgroup)) FAIL ("You specified no group to set.\n");

  args = old_explode (string_replace (arg, "+", actgroup), " ");
  if (pointerp(ignpattern))
    ignpattern -= args;
  names = ({});
  for (i = 0; i < sizeof(args); i++)
  {
    if (sizeof(data = ({mixed})news->GetNames(_adapt_pattern(args[i])))) {
      data = data - names;
      names += data;
    }
  }

  names = names & unsub;
  if (!sizeof(names))
    FAIL ("No matching ignored groups.\n");

  unsub = mkmapping(m_indices(unsub)-names);
  write ("There are "+sizeof(names)+" matching groups.\n");
  for (i = 0; i < sizeof(names); i++)
    write (ladjust(names[i],20)+": regarded.\n");

  return 1;
}

/*************************************************************************/
