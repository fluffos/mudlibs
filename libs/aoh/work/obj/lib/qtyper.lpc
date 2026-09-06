/*  -*- LPC -*-  */
/*   Quicktyper-Lib
**
** Implements the quicktyper-functions in an inheritable object.
**
**   1.0  14-Aug-92 [m] Extracted from Hyp's XTool 1.1.2
**   1.1  18-Aug-92 [m] A missing order_alist() inserted
**   1.2  19-Aug-92 [m] Removed typechecking from some funs
**   1.3  20-Aug-92 [m] DoHeartBeat() added.
**        05-Oct-92 [m] fixed for new NF.
**   1.4  25-Mar-93 [Pepel] move execution of do into heart_beat
**   1.5  24-Jun-93 [Pepel] abort do when command() got error
**   1.6  08-May-96 [Sique] "more" for aliases, patterns
**
** [m] Mateese, Biontic Magics & Darkness
*/

#include <config.h>
#include <moving.h>
#include <secure/wizlevels.h>
#include <properties.h>
#include "/obj/lib/stddefs.h"
#include <string.h>
#include "/obj/lib/qtyper.h"

inherit "/lib/string";

/*-------------------------------------------------------------------------*/

#define VERSION "1"

#define NEW_ALIST ({({}),({})})

#define DEF_MAXHIST        (25)
#define DEF_MAXRECUR       (6)
#define DEF_HISTCHARS      ("%!^")

#define QMODE_ON(x)         (qmode|=x)
#define QMODE_OFF(x)        (qmode&=~x)
#define QMODE(x)            (qmode&x)

#define FORME        if(!ForMe()) return FALSE;
#define ALLOWED      if(!Allowed()) return TRUE;
#define USAGE(con,y) if (con) return notify_fail((y)) && FALSE;else

#define EXEC_LINES         (10)
#define EXEC_TIME          (1)

/*-------------------------------------------------------------------------*/

nosave int    qmode;     /* our operation-mode */
nosave int    didparse;  /* Flag if the command has been parsed already */
nosave string *history;  /* the history buffer: local for privacy */
nosave string *scriptline;
nosave int    scriptsize;
nosave object lastenv;   /* Last env we have been */
nosave object lastroom;  /* Last room our env has been */
nosave object *lastinv;  /* Last inv of our environment */
nosave object *lasteinv; /* Last inv of our environment's environment */
nosave object lastowner; /* Last owner of the qtyper */

  /* Temporary copies of the data in the player */
nosave mapping aliases;  /* the aliases */
nosave int maxhist;
nosave int maxrecur;
nosave string histrep;   /* %% by default */
nosave string chist;     /* % by default */
nosave string carg;      /* ! by default */
nosave string crepl;     /* ^ by default */

/* some variables for delayed execution of 'do' commands */
nosave string *do_list;	/* array of command strings */
nosave int do_count;	/* repeat count for do_list[0] */

public varargs int move(mixed dest, int method, mixed extra);

/*-------------------------------------------------------------------------
** Return current owner. This is always the player carrying us.
** If it's existing and different from an existing last one, clear the
** history-buffer.
*/

object _get_owner() {
  object env;
  string rn;
  if (!(env = environment(ME))
      || !(rn = ({string})env->QueryRealName())  /* is now secure... :-) */
      || env != find_player(rn)
     ) return 0;
  if (lastowner && env && lastowner != env) history = ({});
  return lastowner = env;
}

/*-------------------------------------------------------------------------
** Check if we should react on a command.
**
** We accept every command coming from our environment if its a player.
*/

int ForMe() { return PL && _get_owner() == PL; }

/*-------------------------------------------------------------------------
** Check if the PL is allowed to give us a command.
**
** If PL is no wiz, everything is ok.
** Else if QMODE_NOFORCE is active, PL must be IPL.
*/

int Allowed() {
  if (PL && !IS_IMMORTAL(PL)) return TRUE;
  if (QMODE(QMODE_NOFORCE) && PL != IPL) return FALSE;
  return TRUE;
}

/*-------------------------------------------------------------------------
** Set or get the data from the player.
*/

mapping get_aliases() {
  mapping al;
  object pl;
  pl = environment()||PL;
  return (al = ({mapping})pl->QueryProp(P_ALIASES)) ? al : ([]);
}

void set_aliases (mapping al) { PL->SetProp(P_ALIASES, al); }

string get_histchars() {
  string s;
  object pl;
  pl = environment()||PL;
  return (s = ({string})pl->QueryProp(P_HISTCHARS)) ? s : DEF_HISTCHARS;
}

void set_histchars (string str) {
  if (str && sizeof(str) == 3) PL->SetProp(P_HISTCHARS, str);
}


int get_maxhist() {
  int i;
  object pl;
  pl = environment()||PL;
  return (i = ({int})pl->QueryProp(P_MAXHIST)) ? i : DEF_MAXHIST;
}

void set_maxhist (int i) {
  if (i > 0) PL->SetProp(P_MAXHIST, i);
}


int get_maxrecur() {
  int i;
  object pl;
  pl = environment()||PL;
  return (i = ({int})pl->QueryProp(P_MAXRECUR)) ? i : DEF_MAXRECUR;
}

void set_maxrecur (int i) {
  if (i > 0) PL->SetProp(P_MAXRECUR, i);
}

/*-------------------------------------------------------------------------*/

void create() {
  if (sizeof(explode(object_name(ME), "#"))!=2) return;
  qmode = QMODE_ACTIVE | QMODE_HEART | QMODE_FIRST | QMODE_ECHO
          | QMODE_NOFORCE;
  lastinv = lasteinv = ({});
  history = ({});
  didparse = FALSE;
  set_heart_beat(QMODE(QMODE_HEART));
  enable_commands();	/* need this to do command() in heart_beat() */
}

/*-------------------------------------------------------------------------
** Add the qtyper-Commands if the qtyper is active.
** If the arg is not 0, add only the parsing-command.
*/

protected varargs void AddActions (int parseonly) {
  if (!parseonly) {
    add_action("q_alias"  , "alias");
    add_action("q_unalias", "unalias");
    add_action("q_history", "history");
    add_action("q_do"     , "do");
    add_action("q_for"    , "for");
    add_action("q_sh"     , "sh");
  }
  add_action("CommandScan", "", 1);
  if (!parseonly) add_action("q_mode", "qmode");
    /* Since qmode may change the histchars, expanding might be dreadful */
}

/*-------------------------------------------------------------------------
** Add our commands on init. If necessary, move to environment again
** to get on first place of the sentence-List.
*/

void init() {
  // TODO: Remove this debug
  if (!objectp(ME))dtell("mateese", sprintf("%O: lib/qtyper, me not object\n", ME));
  if (!ME || ME == PL || sizeof(explode(object_name(ME), "#"))!=2) return;
  AddActions();
  if (QMODE(QMODE_FIRST) && first_inventory(environment(ME)) != ME)
    move(environment(ME), M_NOCHECK);
}

/*-------------------------------------------------------------------------
** Check if we need to get on top of the sentence-list
*/
#if 0
DoHeartBeat ( object lroom, object lowner, object* linv, object *lrinv
            , object room, object owner, object *inv, object *rinv
            )
{
}
#endif

void PlayerNetdead (int arg) {
  set_heart_beat(!arg && QMODE(QMODE_HEART));
}

void heart_beat() {
  object env, eenv, *inv, *einv;

  if (!(env = environment(ME))) return;
  else eenv = environment(env);

  inv = all_inventory(env);
  einv = eenv ? all_inventory(eenv) : ({});

  if (QMODE(QMODE_FIRST) && env &&
      (lastroom != eenv || sizeof(inv-lastinv) || sizeof(einv-lasteinv))
     ) move(env, M_NOCHECK);
#if 0
  DoHeartBeat (lastroom, lastowner, lastinv, lasteinv, eenv, env, inv, einv);
#endif
  lastroom = eenv;
  lastinv = inv;
  lasteinv = einv;
  didparse = FALSE; /* If it got an error, this should be necessary */

  if (do_list) {
    string c;
    int n;

    if (!do_count) {
      if (sizeof(do_list) == 1) {	/* it was the last one on the list */
	do_list = 0;
        tell_object(lastowner, "Done.\n");
	return;
      } else {				/* parse next one */
	do_list = do_list[1..];
	switch (sscanf(do_list[0], "%d#%s", n, c)) {
	  case 0:	/* was only a string */
	  case 1:	/* was only a number */
	    do_count = 1;
	    break;
	  case 2:
	    do_count = n<1 ? 1 : n;
	    do_list[0] = c;
	    break;
	}
      }
    }
    /* now we have some nice command, and a nice count */
    do_count--;
    tell_object(lastowner, "Doing: `"+do_list[0]+"'\n");
    if (c = catch(lastowner->command_me(do_list[0]))) {
      tell_object(lastowner, "Got: `"+c+"'\nDone.\n");
      do_list = 0; do_count = 0;
    }
  }
  return;
}

/*-------------------------------------------------------------------------
** Set or get the autoload-args.
** Inactive qtypers return no args.
** The setting returns success.
*/

mixed QueryAutoObject() {
  return QMODE(QMODE_ACTIVE)
          ? ({ VERSION, qmode, get_aliases(), get_maxrecur()
             , get_maxhist(), get_histchars()
            })
          : 0;
}

int SetAutoObject(mixed *args) {
  if (!args || !sizeof(args)) return FALSE;
  if (args[0] < VERSION && IS_IMMORTAL(PL))
    write ("++ QTyper upgraded to version "+VERSION+"\n");

  if (sizeof(args) < 6) {
    if (IS_IMMORTAL(PL))
      write ("++ QTyper: Not enough init-data - using defaults.\n");
    return FALSE;
  }
  qmode = args[1];
  set_aliases   (args[2]);
  set_maxhist   (args[3]);
  set_maxrecur  (args[4]);
  set_histchars (args[5]);
  if (QMODE(QMODE_HEART)) set_heart_beat(1);

  if (sizeof(args) > 6 && IS_IMMORTAL(PL))
    write ("++ QTyper: Ignored extraneous init-data.\n");
  return TRUE;
}

/*-------------------------------------------------------------------------
** Own Command-fun with local echo.
*/

int Command(string str) {
  if (QMODE(QMODE_ECHO)) write (str+"\n");
  return ({int})PL->command_me (str);
}

/*-------------------------------------------------------------------------
** Get all the data we need for command parsing from the player, and
** derive other needed data from it.
** Since the flow of command cycles through us, we could save work
** by this.
*/

void get_data() {
  string histchars;
  histchars = get_histchars();
  chist = histchars[CHAR_HIST..CHAR_HIST];
  carg  = histchars[CHAR_ARG..CHAR_ARG];
  crepl = histchars[CHAR_REPL..CHAR_REPL];
  histrep  = chist + chist;
  maxhist = get_maxhist();
  maxrecur = get_maxrecur();
  aliases = get_aliases();
}

/*-------------------------------------------------------------------------
** Set or get the mode of the qtyper.
** The heart_beat mode (when specified) also does a set_heart_beat().
*/

void qmode_on (int mode) {
  if (mode & QMODE_ACTIVE)   QMODE_ON(QMODE_ACTIVE);
  if (mode & QMODE_FIRST)    QMODE_ON(QMODE_FIRST);
  if (mode & QMODE_HEART)  {
    QMODE_ON(QMODE_HEART); set_heart_beat(0); set_heart_beat(1);
  }
  if (mode & QMODE_ECHO)     QMODE_ON(QMODE_ECHO);
  if (mode & QMODE_NOFORCE)  QMODE_ON(QMODE_NOFORCE);
}

void qmode_off (int mode) {
  if (mode & QMODE_ACTIVE)   QMODE_OFF(QMODE_ACTIVE);
  if (mode & QMODE_FIRST)    QMODE_OFF(QMODE_FIRST);
  if (mode & QMODE_HEART)  { QMODE_OFF(QMODE_HEART); set_heart_beat(0); }
  if (mode & QMODE_ECHO)     QMODE_OFF(QMODE_ECHO);
  if (mode & QMODE_NOFORCE)  QMODE_OFF(QMODE_NOFORCE);
}

int qmode (int mode) { return qmode & mode; }

/*-------------------------------------------------------------------------
** Take the command line and replace any history commands.
** Return the changed line.
*/

protected string DoHistory (string line) {
  int i;
  string cmd, *strs;

  if(!line) return NULL;

  if (   line[0..1] == histrep && sizeof(history)
      && (cmd = history[0] + line[2..<1])
     ) line = cmd;

  else if (   line[0..0] == crepl && (strs = explode(line, crepl))
      && sizeof(strs) && strs[0] && sizeof(history) && (cmd=history[0])
     ) {
      if (sizeof(strs) == 2) cmd = string_replace(cmd, strs[0], strs[1]);
      else cmd = string_replace(cmd, strs[0], "");
      line = cmd;
  }

  else if (line[0..0] == chist && (sscanf(line[1..<1], "%d", i))) {
    i = i > 0 ? i : 1;
    i = i <= sizeof(history) ? i : sizeof(history);
    if (!sizeof(history) || !(cmd = history[i-1])) return NULL;
    line = cmd;
  }

  else if (line[0..0] == chist)
    for(i = 0; i < sizeof(history); i++)
      if ((cmd = history[i]) && history[i][0..sizeof(line)-2] == line[1..<1]) {
        line = cmd;
        break;
      }

  history = ({ line }) + history;
  if (sizeof(history) > maxhist) history = history[0..maxhist-1];

  return line;
}

/*-------------------------------------------------------------------------
** Take the command line and replace any aliases in max. maxrecur
** iterations.
** Return the changed line.
*/

protected string DoAlias (string arg) {
  int i, s, has_star, has_simple, alen, apos, didit;
  string cmd, *args, tail;
  int level;

  for (level = 0; level <= maxrecur; level++) {
    if (!arg) return NULL;
    args = explode(arg, " ");
    if (!member(aliases, args[0])) return arg;
    cmd = aliases[args[0]];
    s = sizeof(args);
    tail = "";
    has_simple = sizeof(regexp ( ({ cmd }), carg+"[0-9]*"));
    if (has_star = sizeof (regexp( ({ cmd }), carg+"[0-9]*\\*")))
      cmd = string_replace (cmd, carg+"*", carg+"1*");
    alen = sizeof(arg)-1; apos = alen+1;
    for (i = s-1; i >= 0; i--) {
      didit = 0;
      while (apos > 0 && arg[--apos] == ' '); apos -= sizeof(args[i]);
      if (has_star && sizeof(regexp( ({ cmd }), carg+i+"\\*"))) {
        cmd = string_replace(cmd, carg+i+"*", arg[apos+1..alen]);
        didit = 1;
      }
      if (has_simple && sizeof(regexp( ({ cmd }), carg+i))) {
        cmd = string_replace(cmd, carg+i, args[i]);
        didit = 1;
      }
      if (!didit && i && !has_star && sizeof(args[i]))
        tail = sizeof(tail) ? args[i]+" "+tail : args[i];
    }
    arg = cmd + (sizeof(tail) ? " "+tail : "");
  }
  write ("*** QTyper: Too deep alias-nesting - command aborted.\n");
  return NULL;
}

/*-------------------------------------------------------------------------
** In case of illegal force, inform owner and forcer.
*/

void NotifyForce (string command) {
  write ( "Your quicktyper protects you from a force by "
        + capitalize(getuid(IPL))+" ["+command+"].\n"
        );
  tell_object(IPL, capitalize(({string})PL_RNAME)
             +"'s quicktyper absorbes your force.\n"
             );
}

/*-------------------------------------------------------------------------
** Generate the command line and perform history and alias substituion
** on it. The command the line, but do not reparse.
*/

varargs int CommandScan (string arg, int isline) {
  string verb, line;

  if (!ForMe() || !QMODE(QMODE_ACTIVE) || didparse)
    return FALSE;

  if (!(verb = query_verb()) && !isline) return FALSE;
  get_data();
  if (!isline) arg = verb + (arg ? " "+arg : "");
  if (Allowed()) {
    if (   !(line = DoHistory (arg))
        || !(line = DoAlias (line))
        || line == arg
       ) return FALSE;
    didparse = TRUE;
    Command(line);
    didparse = FALSE;
    return TRUE; /* efun::command() already took care of notify_fail */
  }
  if (QMODE(QMODE_NOFORCE) && PL != IPL) {
    NotifyForce (arg);
    return TRUE;
  }
  return FALSE;
}

/* formatted alias line */

private string alias_line(string al)
{
  return " " + ladjust(al + " ", 12, ".") + " " +
    (aliases[al]||"<undefined>");
}

/*-------------------------------------------------------------------------
** Command 'alias'
*/

int q_alias (string arg) {
  string al, cmd, *als;
  mapping aliases;

  FORME; ALLOWED;
  USAGE (arg=="?",
 "alias\n  Shows the list of current aliases.\n"
+"alias <verb>\n  Show the alias for <verb>\n"
+"alias <verb> <text>\n  Sets the alias for <verb> to <text>.\n"
        );

  aliases = get_aliases();
  if (!arg) {
    if (sizeof(aliases)) {
      als = sort_array(m_indices(aliases), #'> /*'*/);
      write("Current aliases:\n");
      smore(map(als, #'alias_line /*'*/));
    }
    else write ("No aliases defined.\n");
  }
  else if (sscanf(arg, "%s %s", al, cmd) == 2) {
    write ("Setting alias '"+al+"' to '"+cmd+"'.\n");
    aliases[al] = cmd;
    set_aliases (aliases);
  }
  else {
    if (member(aliases, arg))
      write ("Alias '"+arg+"' is set to '"+cmd+"'.\n");
    else if (sizeof(als = regexp(m_indices(aliases),"^" + arg))) {
      write("Aliases matching " + arg + "\n");
      als = sort_array(als,#'> /*'*/);
      smore(map(als,#'alias_line /*'*/));
    }
    else write ("An alias '"+arg+"' does not exist.\n");
  }
  return TRUE;
}

/*-------------------------------------------------------------------------
** Command 'unalias'
*/

int q_unalias (string str) {
  string cmd;
  mapping aliases;

  FORME; ALLOWED;
  USAGE(!str || str == "?","unalias <verb>\n  Removes the alias for <verb>\n");
  aliases = get_aliases();
  if (member(aliases, str)) {
    cmd = aliases[str];
    write ("Unset alias '"+str+"', was '"+cmd+"'.\n");
    m_delete(aliases, str);
    set_aliases(aliases);
  }
  else write ("An alias '"+str+"' does not exist.\n");
  return TRUE;
}

/*-------------------------------------------------------------------------
** Command 'history'
*/

int q_history (string str) {
  int i, s;

  FORME; ALLOWED;
  USAGE (str,"history\n  Displays the contents of the history buffer.\n");
  if (s = sizeof(history)) {
    for (i = s; --i >= 0;)
      write (radjust(""+(i+1), 2)+": "+history[i]+"\n");
  }
  else write ("No commands given so far.\n");
  return TRUE;
}

/*-------------------------------------------------------------------------
** Command 'do'
*/

int q_do (string str) {
  FORME; ALLOWED;
  USAGE (!str || str == "?",
 "do [<number1>#]<command1>[;[<number2>#]<command2>] ...\n"
+"  Executes in a row <command1> <number1> times, <command2> <number2> times\n"
+"  and so on.\n"
        );

  if (do_list) {
    if ("stop" != str) write(
"Your QuickType is busy already. `do stop' will stop the actions.\n");
    else {
      write("stopping execution of do command.\n");
      do_list = do_count = 0;
      if (!QMODE(QMODE_HEART)) {
	set_heart_beat(0);
	write("HeartBeat of QuickTyper stopped.\n");
      }
    }
    return 1;
  }
  do_list = ({0})+(explode(str, ";")-({""}));	/* argl. das mir. ein dummy */
  set_heart_beat(1);
  heart_beat();
  return TRUE;
}

/*-------------------------------------------------------------------------
** Command 'for'
*/

string *long_get_dir (string pat, int all) {
  int i, s;
  string dir, *file, *tmp;

  if(!pat) return ({});
  dir="";
  if ((tmp = explode(({string})PL->get_path(pat), "/")) && ((s=sizeof(tmp))>1))
    dir = "/"+implode(tmp[0..s-2], "/");
  s = sizeof(tmp=get_dir(pat));
  file = ({});
  for (i = 0; i < s; i++) {
    if (all) file = file + ({dir+"/"+tmp[i]});
    else if (file_size (dir+"/"+tmp[i]) >= 0) file = file + ({dir+"/"+tmp[i]});
  }
  return file;
}


int q_for (string str) {
  int i, s, t, u;
  string pat, cmd, arg, *strs, *files, fh, fr, fe, ft, ff;

  if (!ForMe() || !IS_IMMORTAL(PL)) return FALSE;
  ALLOWED;
  USAGE (!str||str=="?",
 "for <filepattern> <command>\n"
+"  Executes <command> for each file matched by <filepattern>\n"
        );
  if (sscanf (str, "%s %s", pat, arg) != 2) return FALSE;
  files = long_get_dir (pat, FALSE);
  if(!(s = sizeof(files))) {
    write("No matching files found.\n");
    return TRUE;
  }
  strs = explode(files[0], "/");
  fh = "/";
  if (t = sizeof(strs)-1) fh += implode(strs[0..t-1], "/");
  for (i = 0; i < s; i++) {
    ft = explode(files[i], "/")[t];
    if ((strs = explode(ft, ".")) && (u = sizeof(strs)-1)) {
      ff = implode(strs[0..u-1], ".");
      fr = fh+"/"+ff;
      fe = strs[u];
    } else {
      fe = "";
      ff = ft;
      fr = files[i];
    }
    cmd = string_replace (arg, carg+carg, files[i]);
    cmd = string_replace (cmd, carg+"e", fe);
    cmd = string_replace (cmd, carg+"f", ff);
    cmd = string_replace (cmd, carg+"h", fh);
    cmd = string_replace (cmd, carg+"r", fr);
    cmd = string_replace (cmd, carg+"t", ft);
    if(!(Command(cmd))) break;
  }
  return TRUE;
}


/*-------------------------------------------------------------------------
** Command 'sh'
*/

void _qexecfile(int line) {
  int i;

  if (!scriptline) return;
  for (i = line; i < scriptsize && i < line+EXEC_LINES; i++) {
    if (!scriptline[i]) continue;
    if (!Command(scriptline[i])) return;
  }
  if (i < scriptsize) call_out("_qexecfile", EXEC_TIME, i);
  else scriptline = NULL;
}


int q_sh (string str) {
  if (!ForMe() || !IS_IMMORTAL(PL)) return FALSE;
  ALLOWED;
  USAGE (!str || str=="?",
 "sh <file>\n"
+"  Executes each line in <file> as if typed from the keyboard.\n"
         );
  if (scriptline) {
    write("Cannot execute another script file until last execution has ended.\n");
    return TRUE;
  }
  str = ({string})PL->get_path (str);
  if (file_size(str) < 0) {
    write("Cannot read file '"+str+"'.\n");
    return TRUE;
  }
  str = read_file(str, 1, 1000);
  if(!(scriptline = explode(str, "\n"))) {
    write ("Bad script file.\n");
    return TRUE;
  }
  scriptsize = sizeof(scriptline);
  _qexecfile (1);
  return TRUE;
}

/*-------------------------------------------------------------------------
** Command 'qmode'
*/

int q_mode (string str) {
  int iswiz, i, ix, size, didset;
  mixed val;
  string *args;

  FORME; ALLOWED;

  if (iswiz = IS_IMMORTAL(PL)) {
    USAGE (str == "?",
 "qmode [active on|off] [heart on|off] [echo on|off] [noforce on|off]\n"
+"      [first on|off] [maxhist <size>] [recurse <depth>] [chars <three chars>]\n"
+"  Set and/or display the qtyper operation aspects.\n"
          );
  }
  else {
    USAGE (str == "?",
 "qmode [echo on|off] [history <size>] [chars <three chars>]\n"
+"  Set and/or display some quicktyper options (see 'help quicktyper').\n"
          );
  }

  if (str) {
    size = sizeof(args = explode (str, " "));

    for (i = 0; i < size-1; i += 2) {
      if (iswiz || args[i] == "")
        ix = member(({ "active", "heart", "echo", "noforce"
                                     , "first", "history", "recurse", "chars"
                                    }), args[i]);
      else
        ix = member(({ "", "", "echo", ""
                                     , "", "history", "", "chars"
                                    }), args[i]);
      if (ix == -1) {
        write ("Unknown arg '"+args[i]+"'.\n");
        continue;
      }
      if (ix <= 4)
        if ((val = member(({ "off", "on" }), args[i+1] )) == -1) {
          write ("Unknown setting '"+args[i+1]+"'.\n");
          continue;
        } else;
      else if (ix <= 6)
        if (!sscanf(args[i+1],"%d", val) || ""+val != args[i+1] || val < 1) {
          write ("Illegal value '"+args[i+1]+"'.\n");
          continue;
        } else;
      else if (!(val = args[i+1]) || sizeof(val) != 3) {
        write ("Illegal value '"+args[i+1]+"'.\n");
        continue;
      }
      didset = 1;
      switch (args[i]) {
      case "active"  : if (val) qmode_on(QMODE_ACTIVE);
                       else qmode_off(QMODE_ACTIVE);
                       break;
      case "heart"   : if (val) qmode_on(QMODE_HEART);
                       else qmode_off(QMODE_HEART);
                       break;
      case "echo"    : if (val) qmode_on(QMODE_ECHO);
                       else qmode_off(QMODE_ECHO);
                       break;
      case "noforce" : if (val) qmode_on(QMODE_NOFORCE);
                       else qmode_off(QMODE_NOFORCE);
                       break;
      case "first"   : if (val) qmode_on(QMODE_FIRST);
                       else qmode_off(QMODE_FIRST);
                       break;
      case "history" : set_maxhist(val); break;
      case "recurse" : set_maxrecur(val); break;
      case "chars"   : set_histchars(val); break;
      }
    }
    if (size % 2) write ("Missing value for '"+args[size-1]+"'.\n");
    if (!didset) return TRUE;
  }
  if (!iswiz)
    write ("Executed commands "+(QMODE(QMODE_ECHO)?"will":"won't")
          +" be echoed.\n"
	  +"The history remembers up to "+get_maxhist()+" lines.\n"
	  +"The magic characters are '"+get_histchars()+"'\n"
          );
  else
    write ("QTyper-Status:\n"
+"  Command parsing " +(QMODE(QMODE_ACTIVE) ? "enabled" : "disabled")+".\n"
+"  Heart "           +(QMODE(QMODE_HEART) ? "beats" : "doesn't beat")+".\n"
+"  Pole position "   +(QMODE(QMODE_FIRST) ? "tried to hold" : "ignored")+".\n"
+"  Commands are"     +(QMODE(QMODE_ECHO) ? "" : "n't")+" echoed.\n"
+"  Force protection "+(QMODE(QMODE_NOFORCE) ? "enabled" : "disabled")+".\n"
+"  History           : "+get_maxhist()+" lines.\n"
+"  Alias substitution: "+get_maxrecur()+" recursions.\n"
+"  Magic chars       : '"+get_histchars()+"'\n"
          );
  return TRUE;
}

/*************************************************************************/
