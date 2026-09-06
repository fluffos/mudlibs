/*
 *-----------------------------------------------------------------
 * player object
 *
 * These are the communication commands available for all players
 * YUCK ! this thematically conflicts with the soul ! Pepel
 * Even worse: all the Mudlink stuff is here (Mateese grins
 * demonically)
 *-----------------------------------------------------------------
 * [Mica] removed _tell_mudlink
 *        removed rdict command - broken and no replacement
 */

#include <config.h>
#include <properties.h>
#include <ansi.h>
#include <daemons.h>
#include <secure/wizlevels.h>
#include <driver/object_info.h>
#include UDP_HEADER

#define THIS this_object()
#define TI this_interactive()
#define TP this_player()
#define PREV previous_object()
#define ME this_object()

#define POLICEHQ "/d/archwiz/common/room/city/policehq"

#define INDENT 3
#define LINE 78

public varargs mixed Query(string str); // std/base
public void set_no_buffering( int x );  // std/player/message
public varargs int CanSee(object env);  // std/living/description
public int QueryLevel();                // std/living/description
public string QueryRealName();          // std/living/description
string QueryPresay();                   // std/player/soul

string indent_text (string txt) {
  return txt[0..INDENT-1]+sprintf("%*s%-*=s", INDENT, "", LINE-INDENT,
		                  txt[INDENT..])[INDENT..];
}

/*
 * the channel communication for players and wizards
 */

string *channels = ({});
nosave int channels_on = 1;
int earmuffs;
int echomode;
mapping ignoredNames = ([]); // Time to end ignore, indexed by name
nosave string away;

string QueryAway() { return away; }
string SetAway(string s) { return away = s; }

int SetEchoMode(int i) { return echomode = i; }
int QueryEchoMode() { return echomode; }

void echo_txt(string msg) {
  if (echomode)
    write(msg);
  else
    write("Ok.\n");
}

int fechomode(string arg) {
  if (!arg || arg == "") {
    write ("Echo mode is "+(echomode ? "on" : "off")+"\n");
    return 1;
  }
  arg = lower_case(arg);
  if (arg == "on") {
    echomode = 1;
    write("Echo mode activated.\n");
    return 1;
  }
  if (arg == "off") {
    echomode = 0;
    write("Echo mode deactivated.\n");
    return 1;
  }
  return 0;
}

mapping SetIgnored(mapping m) {
  return ignoredNames = m;
}

mapping QueryIgnored() { return copy(ignoredNames); }

int fignore (mixed arg) {
  string name, name2, *ix;
  int    zeit;
  int    i;

  if (arg && (!TI | (TI != THIS && !IS_WIZARD(TI)))) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  if (arg && query_verb() == "unignore") {
    arg = lower_case(arg);
    if (member(({"channel", "shout", "pshout", "wshout"}), arg[0..<2]) != -1)
      arg = arg[0..<2];
    m_delete(ignoredNames, arg);
    if (member(({"channel", "shout", "pshout", "wshout"}), arg) != -1)
      arg = arg+"s";
    else
      arg = capitalize(arg);
    write("Listening to "+arg+" again.\n");
    say(Query(P_NAME)+" stops ignoring "+arg+"\n");
    return 1;
  }

  if (arg && query_verb() == "ignore") {
    notify_fail("Ignore whom for how long?\n");
    arg = explode(arg, " ");
    if (sizeof(arg) < 2)
      arg += ({ "60" });
    if (sizeof(arg) > 2)
      return 0;
    name = lower_case(arg[0]);
    zeit = -1;
    if (lower_case(arg[1]) != "always" && (zeit = to_int(arg[1])) < 1)
      return 0;
    if (member(({"channel", "shout", "pshout", "wshout"}), arg[0..<2]) != -1)
      arg = arg[0..<2];
    if (member(({"channel", "shout", "pshout", "wshout"}), name) != -1)
      name2 = name+"s";
    else
      name2 = capitalize(name);
    if (IS_WIZARD(name) || name == geteuid(THIS))
      write ("You can't ignore "+name2+".\n");
    else {
      say(Query(P_NAME)+" ignores "+name2+".\n");
      if (zeit > 0) {
        write("Ignoring "+capitalize(name)+" for "+zeit+" minutes.\n");
        ignoredNames[name] = time()+60*zeit;
      }
      else {
        write("Ignoring "+name2+".\n");
        ignoredNames[name] = -1;
      }
    }
    return 1;
  }

  ix = m_indices(ignoredNames);
  arg = ({});
  for (i = 0; i < sizeof(ix); i++) {
    zeit = ignoredNames[ix[i]];
    if (zeit > 0 && time()-zeit >= -30)
      ignoredNames = m_delete(ignoredNames, ix[i]);
    else {
      if (member(({"channel", "shout", "pshout", "wshout"}), ix[i]) != -1)
        name = ix[i]+"s";
      else
        name = capitalize(ix[i]);
      arg += ({name+": "
              +(zeit >= 0 ? to_string((zeit+30-time())/60)+" min" : "always")
             });
    }
  }

  if (!sizeof(arg))
    write("You listen to everyone.\n");
  else
    write("You are ignoring:\n"+sprintf("%75#s\n", implode(arg, "\n")));
  return 1;
}

varargs int check_ignore(string type, object by)
{
  int itype;
  int rc; /* 1: Ok, 0: ignore, -1: Silent ignore */
  int tzeit, zeit; /* Time to ignore left; if <= 0: no longer ignored. */
  string name;

  rc = 1;
  if (!by)
    by = PREV;
  while(TI && by && !IS_WIZARD(by)) {
    if (    !m_contains(&zeit, ignoredNames, getuid(TI)))
      zeit = -1;
    else if (zeit <= 0)
      zeit = 1;
    else
      zeit = zeit-time();
    if (zeit <= 0)
      m_delete(ignoredNames, getuid(TI));

    if (   !m_contains(&tzeit, ignoredNames, name = type)
        && !m_contains(&tzeit, ignoredNames, name = "all"))
      tzeit = -1;
    else if (tzeit <= 0)
      tzeit = 1;
    else
      tzeit = tzeit-time();
    if (tzeit <= 0)
      m_delete(ignoredNames, name);

    itype = member(({"channel", "shout", "pshout", "wshout", "hshout", "all"}), name);
    if (itype != -1 && tzeit > 0) {
      rc = -1;
      break;
    }
    if (itype == 0 && query_user_level(PREV) < earmuffs) {
      rc = -1;
      break;
    }
    if (zeit > 0) {
      switch(type) {
      case "converse": rc = -1; break;
      case "tell":
        if ((!IS_IMMORTAL(this_player()) && ({int})THIS->QueryInvis()) || (!interactive(THIS) && query_once_interactive(THIS)))
          rc = -1;
        else
          rc = 0;
        break;
      default: rc = 0;
        break;
      }
    }
    break;
  } /* while (TI...) */
  return rc;
}

int ear (string msg, string type) {
  int rc; /* 1: Ok, 0: ignore, -1: Silent ignore */
  string away;

  rc = check_ignore(type);
  if (stringp(msg))
  {
    if (rc > 0)
    {
      tell_object(THIS, msg);
      if ("tell" == type && away = QueryAway())
        write(capitalize(getuid(THIS))+" is away, "+away+".\n");
    }
    else if (rc == 0)
      write(capitalize(getuid(THIS))+" ignores you.\n");
  }
  return rc;
}

int _tell_ear (object ob, string msg, string type) {
  int rc;

  if (!call_resolved(&rc, ob, "ear", msg, type)) {
    if (stringp(msg))
      tell_object(ob, msg);
     rc = 1;
  }
  return rc;
}

/* -------------------------------------------------------------------------
 * Channel handling
 * -------------------------------------------------------------------------
 */

string * SetChannels(string *chs) { return channels = chs; }
string * QueryChannels() { return channels_on ? channels : ({}); }

int SetChannelsOn( int n ) { return channels_on = n; }
int QueryChannelsOn() { return channels_on; }

void ChannelOn(string ch) {
  if (!channels) channels=({});
  channels-=({ch});
  channels+=({ch});
}

void ChannelOff(string ch) {
  if (!channels) channels=({});
  channels-=({ch});
}

/* ---------------------------------------------------------------------- */

void add_comm_commands() {
  add_action("_away", "away");
  add_action("_whisper", "whisper");
  add_action("_xshout", "shout");
  add_action("_xshout", "pshout");
  if (IS_IMMORTAL(ME)) add_action("_xshout", "wshout");
  add_action("_rtell", "rtell");
  add_action("_etell", "etell");
  add_action("fechomode", "echomode");
  add_action("freport", "report");
  add_action("fignore", "ignore");
  add_action("fignore", "unignore");
  if (!IS_IMMORTAL(ME)) return;
  add_action("_echo", "echo");
  add_action("_echoto", "echoto");
  add_action("_xshout", "echoall");
  if (!IS_IMMORTAL(ME)) return;
  add_action("_earmuffs", "earmuffs");
  add_action("_xshout", "pecho");
  add_action("_xshout", "wecho");
}

int QueryEarmuffs() { return earmuffs; }
#if __VERSION__ > "3.5.0"
int _earmuffs(string|int e) {
#else
int _earmuffs(string e) {
#endif
  if (stringp(e) && ""!= e) earmuffs = to_int(e);
  write("Earmuffs are on "+earmuffs+"\n");
  return 1;
}

int _whisper(string str) {
  object ob;
  string who;
  string msg;
  string it;

  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Whisper what ?\n");
    return 1;
  }
  it = lower_case(who);
  ob = find_living(it);
  if (!CanSee() || !ob || !present(it, environment(this_player()))) {
    write("I can't see a player with that name here.\n");
    return 1;
  }
  echo_txt(indent_text("You whisper to "+({string})ob->Query(P_NAME)+": "+msg+".\n"));
  _tell_ear(ob, indent_text(Query(P_NAME) + " whispers to you: " + msg +"\n"), "whisper");
  say(indent_text(Query(P_NAME)+" whispers something to "+({string})ob->Query(P_NAME)+".\n"), ob);
  return 1;
  }

/* arg 0:echoall 1:pecho 2:wecho 3:_shout 4:pshout 5:wshout */
int _xshout(string str) {
  object *whos, who;
  int i, mylev, hislev, how;
  string ostr;
  if (!str || str == "") {
    notify_fail(capitalize(query_verb())+" what?\n");
    return 0;
  }
  how = member ( ({ "echoall", "pecho", "wecho", "shout", "pshout"
                        , "wshout"}), query_verb());
  if (how < 0) return 0;
  // if (QuerySP() < 1) { write("You are low on power.\n"); return 1; }
  // if (!IS_IMMORTAL(this_player())) SetSP(QuerySP()-30);
  ostr = str;
  if (Query(P_FROG)) str = "Hriibit! Hriiibit!";
  whos = users();
  mylev = QueryLevel();
  for (i = 0; i < sizeof(whos); i++) {
    if ((who = whos[i]) == ME) {
      string tmp;
      tmp = "You ";
      switch(how) {
      case 0: tmp += "echo to all: "; break;
      case 1: tmp += "echo to all players: "; break;
      case 2: tmp += "echo to all wizards: "; break;
      case 3: tmp += "shout: "; break;
      case 4: tmp += "shout to all players: "; break;
      case 5: tmp += "shout to all wizards: "; break;
      }
      echo_txt(indent_text(tmp+ostr+"\n"));
      continue;
    }
    if ((hislev = ({int})who->QueryEarmuffs()) && mylev <= hislev) continue;
    switch (how) {
      case 0: _tell_ear(who, str+"\n", "echoall"); break;
      case 1: if (!IS_WIZARD(who)) _tell_ear(who, str+"\n", "pecho"); break;
      case 2: if (IS_WIZARD(who)) _tell_ear(who, str+"\n", "wecho"); break;
      case 3: _tell_ear(who, indent_text(capitalize(QueryRealName())+" shouts: "+str+"\n"), "shout");
              break;
      case 4: if (!IS_WIZARD(who))
	        _tell_ear(who, indent_text(capitalize(QueryRealName())
                        +" shouts to all players: "+str+"\n"), "pshout");
              break;
      case 5: if (IS_WIZARD(who))
                _tell_ear(who, indent_text(capitalize(QueryRealName())
                        +" shouts to all wizards: "+str+"\n"), "wshout");
              break;
    }
  }
  if (how == 4) /* pshout */
    CHANNEL_D->SendTell("pshout",capitalize(QueryRealName()),ostr);
  return 1;
}


int _echo(string str) { say(str+"\n"); echo_txt("You echo: "+str+"\n"); return 1; }

int _echoto(string str) {
  object ob;
  int i;
  string who, msg, *whos;
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Echoto what ?\n");
    return 1;
  }
  if (!stringp(who))
    return 0;
  whos = explode(who, ",");
  for (i = 0; i < sizeof(whos); i++) {
    if (!sizeof(whos[i])) {
      whos[i] = 0;
      continue;
    }
    ob = find_living(lower_case(whos[i]));
    if (!ob) {
      write("No living named '"+whos[i]+"' found.\n");
      whos[i] = 0;
      continue;
    }
    if (_tell_ear(ob, msg + "\n", "echoto") > 0)
    {
      whos[i] = capitalize(whos[i]);
      if (({int})ob->QueryInvis() || !({string})ob->Short())
        whos[i] = "("+whos[i]+")";
    }
    else
      whos[i] = 0;
  }
  whos -= ({ 0 });
  if (sizeof(whos) < 1)
    write("Nobody there to echo to.\n");
  else {
    if (sizeof(whos) == 1)
      who = whos[0];
    else
      who = implode(whos[0..<2], ",") + " and "+whos[<1];
    echo_txt("You echoed to "+who+": "+msg+"\n");
  }
  return 1;
}

int _rtell(string str) {
  object room;
  string a,b;
  if (!IS_IMMORTAL(TP)) return 0;
  if (!str) str = "me nothing";
  if (sscanf(str, "%s %s", a, b)!=2) { write("rtell where what\n"); return 1; }
  if (!(room=find_object(a))) { write("No such room!\n"); return 1; }
  tell_room(room, QueryPresay()+Query(P_NAME)+" says from somewhere: "+b+"\n");
  write("OK.\n");
  return 1;
}

int _etell(string str) {
  string a,b;
  object who;
  if (!IS_IMMORTAL(this_player())) return 0;
  if (!str) str="me nothing";
  if (sscanf(str,"%s %s",a,b)!=2) { write("etell whom what?\n"); return 1; }
  if (!(who=find_living(a))) { write("No one with that name.\n"); return 1; }
  write("Ok.\n");
  tell_room(environment(who), "You hear a hollow voice saying: "+b+"\n");
  return 1;
}

int _away(string arg) {
  if (!arg)
  {
    write("You are back.\n");
    say(Query(P_NAME)+" is back.\n");
    SetAway(0);
    return 1;
  }
  if (lower_case(arg) == "check" || arg == "?")
  {
    if (away = QueryAway())
      write("Your away message is:\n  "
            +capitalize(getuid(THIS))+" is away, "+away+"\n");
    else
      write("You have no away message set.\n");
    return 1;
  }
  say(Query(P_NAME)+" is away, "+arg+".\n");
  SetAway(arg);
  write("Your away message is set to:\n  "
        +capitalize(getuid(THIS))+" is away, "+away+".\n");
  return 1;
}

int freport(string arg) {
  if (this_interactive() != this_object()) {
    notify_fail("You can't do that this way.\n");
    return 0;
  }

  write("Sorry, at the moment this command is not functional.\n"
	"If you have any suggestion what to do with it, let us know.\n"
	" -- The Administration\n"
	);
  return 1;
#if 0
  write(
"Enter you report to the police. End input with '**' or '.', abort with '~q'\n"
       );
  if (stringp(arg)) {
    write("]");
    input_to("_next_report_line", 0, ({arg}));
  } else {
    write("Subject: ");
    input_to("_next_report_line", 0, ({}));
  }
  return 1;
#endif
}

#if 0
void _next_report_line(string line, string *msg) {
  string *names;
  string *rec;
  if ("~q" == line) {
    write("Report aborted.\n");
    return;
  }
  if ("." != line && "**" != line) {
    msg += ({ line });
    write("]");
    input_to("_next_report_line", 0, msg);
    return;
  }
  names = POLICEHQ->QueryCop();
  rec = MAILDEMON->DeliverMail(
    ({ getuid(this_object())
     , getuid(this_object())
     , names[0]
     , names[1..]
     , ({})
     , msg[0]
     , time()
     , ""
     , implode(msg[1..], "\n")+"\n"
     })
  );
  if (sizeof(rec))
    write("Report delivered to "+implode(rec, ",")+"\n");
  else
    write("Uh-oh, could not deliver report. Please contact an arch directly.\n");
}
#endif
