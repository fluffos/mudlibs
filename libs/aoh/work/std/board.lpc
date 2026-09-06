/* The standard board.
**
** New properties:
**   P_GROUPS: The groups the board carries. It's never empty.
**
**   12-Aug-92 [m] Derived from Mateese's newsmatrix.
**   17-Aug-92 [m] Faulty regexp() patterns notified.
**   18-Aug-92 [m] Bug in fread() removed.
**   26-Aug-92 [m] Some patches: .signature included; input-commands ~i, ~r
**   27-Aug-92 [m] Blueprint did call_out *blush*
**   29-Aug-92 [m] Write-Rights are checked before actual writing
**   02-Sep-92 [m] Nicened listing of group contents
**   05-Sep-92 [m] _clear_plinfo() no longer called_out.
**   14-Sep-92 [m] Fixed concurrent note reading.
**   19-Nov-92 [m] SetGroups() fixed.
**   08-Dec-92 [m] M_LEVEL can be an array now; list uses smore().
**   25-Jun-94 [m] _display_note() also takes a footer string.
**                 Read notes are followed by number footer.
**   08-Nov-94 [m] 'list' now list just the last NO_NOTES headers,
**                 'list full' lists all.
**   13-May-95 [m] New commands 'lock' and 'unlock'.
**   12-Apr-98 [m] New userlevel system of OSB.
**
**  [m] Mateese, Biontic Magics & Darkness
*/

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <news.h>
#include <secure/wizlevels.h>

#include "/obj/lib/stddefs.h"

#include <string.h>
inherit "/lib/string";

inherit "/std/thing";

#define EXPLODE explode /* old_explode - S.P. */

/*-------------------------------------------------------------------------*/

#define VERSION "980412"
#define VERSNR 0

#define PLINFO_CLEAR  1800 /* Interval of clearance of plinfo */

#define DEFAULT_GROUP "general"

#define USAGE(con,txt) if (con) return notify_fail(txt) && 0; else
#define FAIL(msg) return notify_fail(msg) && 0

/*-------------------------------------------------------------------------*/

nosave string *groups;   /* Names/Patterns of the groups to carry, first
                         ** is the default group
                         */

nosave mapping plinfo;
#define PI_PLAYER 0
#define PI_DATA   1
#define D_GROUP   0      /* Last read group */
#define D_MSG     1      /* Message under preparation */
#define D_MUTEX   2      /* Flag for msg-preparation */
#define D_SMORE   3      /* an array of the SMore-Parameters */
nosave int lastclear;

nosave int nrgroups;     /* Nr of groups carried by this board,
                         ** set by _match_groups()
                         */
nosave int blueprint;

void _clear_plinfo();

/*-------------------------------------------------------------------------
*/

varargs void create () {
  thing::create();
  if (sizeof(explode(object_name(ME),"#")) != 2) { blueprint = 1; return; }
  AddId ("board");
  AddId ("newsboard");
  SetShort ("a generic newsboard");
  SetLong ("This is a generic newsboard.\n");
  Set(P_WEIGHT, 1000000);  /* Much to heavy to carry this */
  Set(P_READ_MSG,
"A small sign reads:\n"+
"  Generic NewsBoard - v."+VERSNR+" ("+VERSION+")\n"+
"     Biontic Magics & Darkness\n"
          );
  Set(P_INFO, "Generic Board, v."+VERSNR+" ("+VERSION+") by Mateese");
  plinfo = ([]);
  groups = ({ DEFAULT_GROUP });
  nrgroups = 1;
  Set(P_NOGET, "You can't take it: the board is securily fixed.\n");
  Set(P_HELP_MSG,
 "\n"
+"Boards allow you to read and deposit notes, sometimes even in several\n"
+"thematic groups in parallel.\n"
+"\n"
+"The available commands are:\n"
+"  list              : list notes and other information.\n"
+"  read              : read notes\n"
+"  note              : write new notes\n"
+"  remove            : remove a note.\n"
+"  lock              : lock a note against accidental deletion\n"
+"  unlock            : unlock a locked note\n"
+"  group, next, prev : selection of groups if supported.\n"
+"\n"
+"All commands give specific info when given as '<cmd> ?', e.g. 'list ?'.\n"
+"Every command may be preceded by 'board', e.g. 'board list'.\n"
+"It is possible that you may not do everything, see the 'list' command \n"
+"  for information.\n"
+"\n"
          );
}

void reset() {
  if (blueprint) return;
  lastclear = 0;  /* Force a clear */
  _clear_plinfo();
}

varargs int move (mixed dest, int method, mixed extra) {
  if (method == M_NOCHECK) return thing::move(dest, method, extra);
  if (dest && stringp(dest)) dest = find_object(dest);
  if (dest && objectp(dest) && !living(dest)) return thing::move(dest, method, extra);
  return 0;
}

/*-------------------------------------------------------------------------
** Set/Query plinfo[]. It is important that we get copies, not pointers.
** Every now and then, all non-players are removed. This happens only
** in intervals of at least PLINFO_CLEAR seconds.
*/

void _set_data (object pl, mixed *data) {
  if (!pl || !data) return;
  if (member(plinfo, pl))
    plinfo[pl] = data;
  else
    plinfo += ([pl:data]);
}

mixed *_get_data (object pl) {
  if (!member(plinfo, pl)) {
    mixed *d = ({groups[0], 0, 0, 0});
    _set_data(pl, d);
    return d;
  }
  return plinfo[pl];
}

void _set_pgroup (object pl, string group) {
  mixed *data;
  (data = _get_data(pl))[D_GROUP] = group;
  _set_data (pl,data);
}
#define _get_pgroup(pl)  (_get_data(pl)[D_GROUP])

void _set_pmsg (object pl, mixed *msg) {
  mixed *data;
  (data = _get_data(pl))[D_MSG]=({})+msg;
  _set_data (pl,data);
}
#define _get_pmsg(pl)   (_get_data(pl)[D_MSG])

void _set_pmutex (object pl, int mutex) {
  mixed *data;
  (data = _get_data(pl))[D_MUTEX]=mutex;
  _set_data (pl,data);
}
#define _get_pmutex(pl)  (_get_data(pl)[D_MUTEX])

void _set_psmore (object pl, mixed *sm) {
  mixed *data;
  (data = _get_data(pl))[D_SMORE]=({})+sm;
  _set_data (pl,data);
}
#define _get_psmore(pl)   (_get_data(pl)[D_SMORE])

void _clear_plinfo() {
  /* int i, size;
  mixed *ind; */
  if (blueprint || time()-lastclear < PLINFO_CLEAR || !plinfo)
    return;
  lastclear = time();
  /* size = sizeof((ind = m_indices(plinfo))); */
  /* plinfo = filter(m_indices(plinfo), #'interactive); */
  plinfo = filter(plinfo, (: interactive($1) :));
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
** Return an array of all the groups matched by 'groups'.
*/

string _adapt_pattern (string pattern) {
  if (!pattern) return 0;
  return "^"+string_replace (string_replace (pattern, ".", "\\.")
                            , "\\\\.", "."
                            )+"$";
}

varargs string *_match_groups (mixed pattern) {
  int i, countem;
  string *rc, *names, *match;
  object news;
  countem = !pattern;
  if (!pattern) pattern = groups;
  else if (!pointerp(pattern)) pattern = ({ pattern });
  if (!(news = _newsserver())) return 0;
  names = ({string *})news->GetNames();
  rc = ({});
  for (i = 0; i < sizeof(pattern) && sizeof(names); i++) {
    if (!(match = regexp(names, _adapt_pattern(pattern[i])))) {
      write ("Faulty pattern '"+pattern[i]+"'.\n");
      match = ({});
    }
    names -= match;
    rc += match;
  }
  if (countem) nrgroups = sizeof(rc);
  return rc;
}

/*-------------------------------------------------------------------------
** Check actual group of PL for unread notes and print according message.
** If <newgroup> is given: try to change actual group. Return success.
*/

varargs int _chg_act (string newgroup) {
  object news;

  if (!(news = _newsserver())) return 0;
  if (!newgroup && !(newgroup = _get_pgroup(PL)))
    FAIL ("No group specified.\n");
  if (member(_match_groups(), newgroup) == -1)
    FAIL ("No group '"+newgroup+"' on this board.\n");
  if ((({mixed})news->GetStatus(newgroup)) == NEWS_ILLPARM)
    FAIL ("No such group '"+newgroup+"'.\n");
  _set_pgroup(PL, newgroup);
/*  write ("Selected group '"+newgroup+"'.\n"); */
  return 1;
}

/*-------------------------------------------------------------------------
** check_owner() checks if the right player is trying to use us.
*/

int check_owner() {
  return PL && environment(PL) == environment(ME);
}

/*-------------------------------------------------------------------------
** Set the groups this board should carry. It might be a single
** string or an array of string. Each string might be a regexp, except
** that . and \. switch their meanings and each pattern will be enclosed
** in '^$'.
*/

string *SetGroups (mixed names) {
  if (!names) return groups;
  if (!pointerp(names)) names = ({ names });
  return groups = ({})+names;
}

string *QueryGroups() { return groups; }

/*-------------------------------------------------------------------------
** Return an extended long-description.
*/

varargs string QueryLong() {
  string long;
  string line, group;
  int i;
  object news;
  mixed data;

  long = thing::QueryLong();
  if ( news = _newsserver()) {
    nrgroups = sizeof(_match_groups());
    if (nrgroups < 0) long += "It's not possible to put notes on it.\n";
    else {
      long += "You may put notes ";
      if (nrgroups > 1) long += "in one of the "+nrgroups+" groups.\n";
      else long += "on it.\n";
    }
  }
  else long += "Unfortunately it's not usable at the moment.\n";
  long += "Use 'help board' for information about its usage.\n";
  if (!check_owner()) return long;
  /*names = */ _match_groups();
  if (!(group = _get_pgroup(PL))) return long;
  if (intp(data = ({mixed})news->GetHeaders(group))) return long;
  say (({string})PL->QueryName()+" studies the board.\n");
  long += "\nYou see "+sizeof(data)+" notes ";
  if (nrgroups > 1) long += "in group '"+group+"'.\n\n";
  else long +="on the board.\n\n";
  i = 0;
  if (sizeof(data) > NO_NOTES)
    i = sizeof(data)-NO_NOTES;
  for ( ; i < sizeof(data); i++) {
    line = radjust (""+(i+1),2);
    if (data[i][M_FLAGS] && -1 != member(data[i][M_FLAGS], MF_LOCKED))
      line += "*";
    else
      line += ":";
    line += " "+ladjcut (data[i][M_TITLE], 53);
    line += " ("+ladjust(data[i][M_WRITER],10);
    line += ", "+stime(data[i][M_TIME], SD_SDATE)[0..5];
    line += ")";
    long += line+"\n";
  }
  return long;
}

/*-------------------------------------------------------------------------
** Add our commands.
*/

void init() {
  string *names;
  thing::init();
  add_action ("fread", "inspect");
  if (!check_owner()) return;
  add_action ("_dispatch"  , "", 1);
  _clear_plinfo();
  names = _match_groups();
  if (names && sizeof(names)) {
    if (!member(plinfo, PL) && !_chg_act(names[0]))
      write ("Warning: Can't find default-group '"+names[0]+"'.\n");
  }
  else _match_groups();
}

int _dispatch(string arg) {
  string verb;
  if ((verb = query_verb()) == "board" || verb == "newsboard") {
    if (!arg) verb = 0;
    else if (sscanf (arg, "%s %s", verb, arg) < 2) verb = arg, arg = 0;
  }
  if (verb && verb != "" && function_exists("f"+verb, ME))
    return ({int})call_other(ME, "f"+verb, arg);
  return 0;
}

/*-------------------------------------------------------------------------
** Create a default writemsg;
*/

mixed *_mk_writemsg() {
  mixed *msg;
  msg = allocate(M_SIZE);
  msg[M_WRITER] = capitalize(geteuid(PL));
  msg[M_TITLE] = "<untitled>";
  if (!(msg[M_LEVEL] = PL_WLEVEL))
    msg[M_LEVEL] = ({ ({int})PL->QueryLevel()
                    , ({int})RACEMASTER->XPtoLevel(({int})PL->QueryXP())
                   });
  msg[M_TIME] = time();
  msg[M_GROUPS] = ({});
  msg[M_TEXT] = "";
  return msg;
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
** More a note to the player. Return success.
** This needs us overloading SMore...
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
** Command 'help'
*/

int fhelp (string arg) {
  if (!check_owner()) return 0;
  if (arg && id(arg)) {
    write (QueryHelpMsg());
    return 1;
  }
  return 0;
}

/*-------------------------------------------------------------------------
** Command 'list'
*/

int flist (string arg) {
  string *args, *names, line, text;
  int i, j, all;
  object news;
  mixed data;

  if (!check_owner()) return 0;
  if (nrgroups > 1)
    USAGE (arg == "?",
 "[board] list [<groupname> | notes] [full]\n"
+"  Lists the last notes in the current group. If <groupname> is specified,\n"
+"  the current group will be changed to it first. If 'full' is specified,\n"
+"  all notes are listed.\n"
+"[board] list groups\n"
+"  Lists the names of all groups on this board.\n"
+"[board] list rights [all]\n"
+"  Tells you your rights in the current group (or in all groups).\n"
          );
  else
    USAGE (arg == "?",
 "[board] list [full]\n"
+"  Lists the last notes on the board, or all if 'full' is specified.\n"
+"[board] list rights\n"
+"  Tells you your rights on this board.\n"
          );

  if (!(news = _newsserver())) return 1;

  names = _match_groups();

  if ((!arg || arg == "notes") && !(arg = _get_pgroup(PL)))
    FAIL("You specified no group to list.\n");

  if (   sizeof(args = EXPLODE(lower_case(arg), " ")) <= 2
      && args[0] != "groups" && args[0] != "rights"
     ) {
    int full;

    if (arg == "full") {
      full = 1;
      if (!(arg = _get_pgroup(PL))) FAIL("You specified no group to list.\n");
    }
    else if (sizeof(args) > 1 && args[1] == "full") {
      full = 1;
      arg = args[0];
    }

    if (arg && arg != _get_pgroup(PL) && !_chg_act(arg)) return 0;

    if (intp(data = ({mixed})news->GetHeaders(arg)))
      FAIL(_decode (data, arg));

    say (({string})PL->QueryName()+" studies the board.\n");
    write ("You see "+sizeof(data)+" notes ");
    if (nrgroups > 1) write ("in group '"+arg+"'.\n\n");
    else write ("on the board.\n\n");
    text = "";
    i = 0;
    if (!full & sizeof(data) > NO_NOTES)
      i = sizeof(data)-NO_NOTES;
    for ( ; i < sizeof(data); i++) {
      line = radjust (""+(i+1),2);
      line += ": "+ladjcut (data[i][M_TITLE], 53);
      line += " ("+ladjust(data[i][M_WRITER],10);
      line += ", "+stime(data[i][M_TIME], SD_SDATE)[0..5];
      line += ")";
      text += line+"\n";
    }
    smore (text, ({int})PL->Query(P_PAGESIZE));
    return 1;
  }

  if (args[0] == "rights") {
    if (sizeof(args) > 2) FAIL ("Too much arguments.\n");
    if (sizeof(args) == 2 && args[1] != "all")
      FAIL ("Illegal argument '"+args[1]+"'.\n");

    say (({string})PL->QueryName()+" studies the board.\n");
    all = sizeof(args) == 2;
    if (all) i = 0; else i = member(names, _get_pgroup(PL));
    text = "";
    for (;i < sizeof(names); i++) {
      text += "Group: "+names[i]+"\n  ";
      if (intp(data = ({mixed})news->GetGroup(names[i])))
        text += _decode (data, names[i]);
      else {
        line = "";
        for (j = G_READ; j <= G_DELETE; j++)
          if (({int})news->CheckRights(data[j])) {
            if (line != "") line += ", ";
            line += ({ "read notes", "write notes", "delete notes"
                    })[j-G_READ];
          }
        text += (line != "" ? "You may "+line+".\n"
                            : "You can't do anything.\n"
                );
      }
      if (!all) break;
    }
    smore (text, ({int})PL->Query(P_PAGESIZE));
    return 1;
  }

  if (sizeof(args) > 1) FAIL ("Too much arguments.\n");
  if (args[0] != "groups") FAIL ("What?\n");


  say (({string})PL->QueryName()+" studies the board.\n");
  write ("The board carries "+sizeof(names)+" group"+(nrgroups!=1?"s":"")
         +".\n  "+implode(names, "\n  ")+"\n");
  return 1;
}

/*-------------------------------------------------------------------------
** Command 'group'
*/

int fgroup (string arg) {
  string grp;

  if (!check_owner() || nrgroups < 2) return 0;
  USAGE (arg == "?",
 "[board] group [<groupname>]\n"
+"  Sets or displays the current group.\n"
        )

  if (!arg) {
    if (!(grp = _get_pgroup(PL))) write ("No current group.\n");
    else write ("Current group: "+grp+"\n");
    return 1;
  }
  return _chg_act (arg);
}

/*-------------------------------------------------------------------------
** Command 'next', 'prev'
*/

varargs int fnext (string arg, int prevg) {
  int ix;
  string *names, actgroup;

  if (!check_owner() || nrgroups < 2) return 0;
  USAGE (arg,
 "[board] "+(prevg ? "prev\n" : "next\n")
+"  Goes to the "+(prevg ? "previous" : "next")
  +" group (the trash-group is skipped).\n"
        )

  if (!(_newsserver())) return 1;
  names = _match_groups();
  if (nrgroups <= 1) FAIL ("There is only one group on this board.\n");

  actgroup = _get_pgroup(PL);

  if (!prevg) {
    if (!actgroup || (ix = member(names, actgroup)) == -1) ix = -1;
    if (names[(ix+1) % sizeof(names)] == TRASH) ix++;
    return _chg_act (names[(ix+1) % sizeof(names)]);
  }
  if (!actgroup || (ix = member(names, actgroup)) == -1) ix = 0;
  ix += sizeof(names);
  if (names[(ix-1) % sizeof(names)] == TRASH) ix--;
  return _chg_act (names[(ix-1) % sizeof(names)]);
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

  args = EXPLODE(arg, " ");
  nr = ({});
  i = 0;
  if (nrgroups > 1 && i < sizeof(args)) {
    if (args[i] == "group") {
      if (++i >= sizeof(args)) FAIL ("Not enough arguments.\n");
      groupname = args[i++];
    }
    else if (args[i] != "note" && !sscanf (args[i], "%d", val)
            ) groupname = args[i++];
  }

  if (i < sizeof(args) && args[i] == "note" && ++i >= sizeof(args))
    FAIL ("Not enough arguments.\n");
  for (; i < sizeof(args); i++) {
    if (!sscanf (args[i], "%d", val) || args[i] != ""+val || val <= 0)
      FAIL ("Illegal arg '"+args[i]+"'.\n");
    nr += ({ val });
  }

  if (!sizeof(nr)) FAIL ("Not enough arguments.\n");

  if (groupname && !_chg_act(groupname)) return 0;
  if (groupname) write ("\n");
  if (!(groupname = _get_pgroup(PL)))
    FAIL ("You specified no group to remove from.\n");

  say (({string})PL->QueryName()+" removes some notes from the board.\n");
  news = _newsserver();
  for (i = 0; i < sizeof(nr); i++) {
    if (intp(val = ({mixed})news->GetHeaders(groupname, nr[i])))
      write ("Can't "+(unlock ? "unlock" : "lock")+" note "+nr[i]
             +_decode(val, groupname, "Note not found.\n")
             +(nrgroups>1?" in group '"+groupname+"'":"")+": "
             +_decode(val, groupname, "Not that many notes.\n")
            );
    else if (unlock)
      write ("Unlocking note "+nr[i]+" '"+val[M_TITLE]+"'"
             +(nrgroups>1?" in group '"+groupname+"'":"")+": "
          +_decode((val = ({int})news->RemoveFlag (groupname, nr[i], MF_LOCKED))
                     , groupname, "Not that many notes.\n"
                     )
            );
    else
      write ("Locking note "+nr[i]+" '"+val[M_TITLE]+"'"
             +(nrgroups>1?" in group '"+groupname+"'":"")+": "
             +_decode((val = ({int})news->AddFlag(groupname, nr[i], MF_LOCKED))
                     , groupname, "Not that many notes.\n"
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
  if (nrgroups > 1)
    USAGE (!arg || arg == "?",
 "[board] remove [[group] <groupname>] [note] <no>...\n"
+"  Removes the <no>th's notes in the current group.\n"
+"  If <groupname> is specified, the current group is changed to it before.\n"
          );
  else
    USAGE (!arg || arg == "?",
 "[board] remove [note] <no>...\n"
+"  Removes the <no>th's notes from the board.\n"
          );

  if (!(news = _newsserver())) return 1;

  args = EXPLODE(arg, " ");
  nr = ({});
  i = 0;
  if (nrgroups > 1 && i < sizeof(args)) {
    if (args[i] == "group") {
      if (++i >= sizeof(args)) FAIL ("Not enough arguments.\n");
      groupname = args[i++];
    }
    else if (args[i] != "note" && !sscanf (args[i], "%d", val)
            ) groupname = args[i++];
  }

  if (i < sizeof(args) && args[i] == "note" && ++i >= sizeof(args))
    FAIL ("Not enough arguments.\n");
  for (; i < sizeof(args); i++) {
    if (!sscanf (args[i], "%d", val) || args[i] != ""+val || val <= 0)
      FAIL ("Illegal arg '"+args[i]+"'.\n");
    nr += ({ val });
  }

  if (!sizeof(nr)) FAIL ("Not enough arguments.\n");

  if (groupname && !_chg_act(groupname)) return 0;
  if (groupname) write ("\n");
  if (!(groupname = _get_pgroup(PL)))
    FAIL ("You specified no group to remove from.\n");

  say (({string})PL->QueryName()+" removes some notes from the board.\n");

  for (i = 0; i < sizeof(nr); i++) {
    if (intp(val = ({mixed})news->GetHeaders(groupname, nr[i])))
      write ("Can't remove note "+nr[i]
             +_decode(val, groupname, "Note not found.\n")
             +(nrgroups>1?" from group '"+groupname+"'":"")+": "
             +_decode(val, groupname, "Not that many notes.\n")
            );
    else
      write ("Removing note "+nr[i]+" '"+val[M_TITLE]+"'"
             +(nrgroups>1?" from group '"+groupname+"'":"")+": "
             +_decode((val = ({int})news->RemoveNote (groupname, nr[i]))
                     , groupname, "Not that many notes.\n"
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
  string *args, groupname;
  int i, nr;
  object news;
  mixed msg;

  if (!check_owner()) return 0;
  if (nrgroups > 1)
    USAGE (!arg || arg == "?",
 "[board] read [[group] <groupname>] [note] <no>]\n"
+"  Read the <no>th note in the current group.\n"
+"  If <groupname> is specified, the current group is changed to it before.\n"
        );
  else
  USAGE (!arg || arg == "?",
 "[board] read [note] <no>\n"
+"  Read the <no>th note on the board.\n"
        );

  if (!(news = _newsserver())) return 1;

  args = ({});
  if (arg) args = EXPLODE(arg, " ");
  i = 0; nr = -1;
  if (nrgroups > 1 && i < sizeof(args)) {
    if (args[i] == "group") {
      if (++i >= sizeof(args)) FAIL ("Not enough arguments.\n");
      groupname = args[i++];
    }
    else if (args[i] != "note" && !sscanf (args[i], "%d", nr))
      groupname = args[i++];
  }
  if (i >= sizeof(args) || (args[i] == "note" && ++i >= sizeof(args)))
    FAIL ("Not enough arguments.\n");
  if (!sscanf (args[i], "%d", nr) || args[i] != ""+nr || nr <= 0)
    FAIL ("Illegal arg '"+args[i]+"'.\n");
  if (i+1 < sizeof(args)) FAIL ("Too much arguments.\n");

  if (groupname && !_chg_act(groupname)) return 0;
  if (groupname) write ("\n");
  if (!(groupname=_get_pgroup(PL))) FAIL ("You specified no group to read.\n");
  msg = ({mixed})news->GetNote (groupname, nr);
  if (intp(msg))
    FAIL (_decode (msg, groupname, "Not that many notes.\n"));

  say (({string})PL->QueryName()+" reads a note on the board.\n");

  return _display_note (msg, 0, "[End of "+groupname+":"+nr+"]\n");
}

/*-------------------------------------------------------------------------
** Command 'note'
*/

int fnote (string arg) {
  mixed msg, data;
  string group;
  object news;

  if (!check_owner()) return 0;
  USAGE (!arg || arg == "?",
 "[board] note <title>\n"
+"  Write a new note with given <title>"
  +(nrgroups>1?" for the current group.\n":".\n")
          )

  if (_get_pmutex(PL)) FAIL ("You ARE already writing a note!\n");
  if (!(group=_get_pgroup(PL))) FAIL ("You need a group to write to!\n");

  if (!(news = _newsserver())) return 1;
  if (intp(data = ({mixed})news->GetGroup(group)))
    FAIL("Group "+group+": "+_decode (data, group));
  if (!({int})news->CheckRights(data[G_WRITE])) {
    if (nrgroups > 1)
      FAIL("You have no right to write in group '"+group+"'.\n");
    else
      FAIL("You have no right to put a note on this board.\n");
  }

  msg = _mk_writemsg();
  msg[M_TITLE] = arg;
  msg[M_GROUPS] = ({ _get_pgroup(PL) });
  _set_pmsg (PL, msg);
  _set_pmutex (PL, 1);

  say (({string})PL->QueryName()+" starts writing a note.\n");

  write (
"Enter your text; finish with '**' or '.', cancel with '~' or '~q'.\n"
+"  Use '~r' to redisplay your input"
  +(PL_WLEVEL?", '~i <file>' to include a file.\n":".\n")
+"]"
        );
  input_to ("write_note");
  return 1;
}

void write_note (string line) {
  object news;
  mixed msg, rc;
  string fname;

  if (!line) line = "";

  if (line == "**" || line == ".") {
    _set_pmutex (PL, 0);
    if (!(news = _newsserver())) return;
    msg = _get_pmsg(PL);
    if (!msg[M_TITLE] || msg[M_TITLE] == "") msg[M_TITLE] = "<untitled>";
    fname = ({string})PL->get_path("~/.signature");
    if (fname && file_size(fname) > 0 && msg[M_TEXT]) {
      write ("..appending ~/.signature\n");
      msg[M_TEXT] += read_file(fname);
    }
    rc = ({int})news->StoreNote ( msg[M_TITLE]
                                 , msg[M_TEXT]
                                 , msg[M_GROUPS]
                                 );
    if (intp(rc))
      write ("Error: "+_decode (rc,msg[M_GROUPS][0]));
    else if (sizeof(rc) == 1) write ("You put a note on the board.\n");
    else write (implode(rc[1..sizeof(rc)], "\n")+"\n");
    say (({string})PL->QueryName()+" finishes writing a note.\n");
    return;
  }

  if (line == "~" || line == "~q") {
    _set_pmutex (PL, 0); write ("Note cancelled.\n");
    say (({string})PL->QueryName()+" aborts writing a note.\n");
    return;
  }

  if (line == "~r")
    write ("You wrote so far:\n--\n"+_get_pmsg(PL)[M_TEXT]+"--\n");
  else if (PL_WLEVEL && sizeof(line) > 2 && line[0..1] == "~i") {
    line = EXPLODE(line[2..sizeof(line)]," ")[0];
    if (!line) write ("Include what?\n");
    else {
      fname = ({string})PL->get_path(line);
      if (!({int})PL->is_file(fname)) write ("'"+fname+"' is not a valid file.\n");
      else if (!(line = read_file(fname)))
        write ("Can't read file '"+fname+"'.\n");
      else {
        (msg = _get_pmsg(PL))[M_TEXT] += line;
        _set_pmsg(PL, msg);
        write ("Included.\n");
      }
    }
  }
  else {
    (msg = _get_pmsg(PL))[M_TEXT] +=implode(break_line (line, 77), "\n")+"\n";
    _set_pmsg(PL, msg);
  }

  write ("]");
  input_to ("write_note");
}

/*************************************************************************/
