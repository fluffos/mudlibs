
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

// DefaultThing is what we query if no specific part of an object is being inspected
// ie, smell, smell longsword
string DefaultThing = "default";
// these messages will be tweaked by each sense command
string MsgFailNoTgt = "That is not here.";
string MsgFailEnvDef = "There is nothing here to $V.";
string MsgFailEnv = "You don't $V that here.";
string MsgFailObDef = "There is nothing on $O to $V.";
string MsgFailOb = "You don't $V that on $O.";
string MsgToTgt = "$N $Vs you.";
string MsgToEnvDef = "$N $Vs.";
string MsgToEnv = "$N $Vs $I.";
string MsgToEnvOwn = "$N $Vs $P $R.";
string MsgToEnvOb = "$N $Vs $O.";
// able to hide this sense action from the person to whom you're doing it??
// ie, you can quietly look at someone but not quietly touch him
int StealthTgtMsg = 1;
// how much stealth to use
int StealthUsed = 2;
// name of the sense we're querying, each command sets this
string Sense = "";
// alternate verb to use, query_verb() is default
string Verb = "";
// list of words that can go between specific things and the target name
// smell rose on tree, smell stench of goblin, etc
string *Separators = ({"on", "from", "of"});

varargs string expandos(string str, object tgt, string what, string sep) {
  mapping words = ([
    "N" : (: this_player() ? this_player()->query_cap_name() : "" :),
    "V" : (:
      strlen($(Verb)) ? $(Verb)
        : (strlen(query_verb()) ? query_verb() : "") :),
    "O" : (:
      $(tgt) ? ($(tgt)->is_living()
        ? remove_article($(tgt)->query_cap_name())
        : definite_article(strip_color($(tgt)->query_short()))
      ) : "" :),
    "P" : (: this_player() ? this_player()->query_possessive() : "" :),
    "R" : (:
      $(tgt) ? ($(tgt)->is_living()
        ? remove_article($(tgt)->query_cap_name())
        : remove_article(strip_color($(tgt)->query_short()))
      ) : "" :),
    "I" : (: strlen($(what)) ? definite_article($(what)) : "" :),
    "S" : (: strlen($(sep)) ? $(sep) : "" :),
  ]);

  if (nullp(str)) return "";
  if (nullp(tgt)) tgt = 0;
  if (nullp(what)) what = "";
  if (nullp(sep)) sep = "";

  foreach (string thing, mixed f in words)
    str = replace_string(str, "$"+thing, evaluate(f));

  return str;
}

void set_verb(string v) { Verb = v; }
void set_sense(string s) { Sense = s; }
void set_stealth(int x) { StealthUsed = x; }
void set_can_stealth_tgt(int x) { StealthTgtMsg = (x > 0 ? 1 : 0); }
void set_default(string def) { DefaultThing = def; }
void set_separators(string *sep) { Separators = sep; }
void set_msg_failnotgt(string str) { MsgFailNoTgt = str; }
void set_msg_failenvdef(string str) { MsgFailEnvDef = str; }
void set_msg_failenv(string str) { MsgFailEnv = str; }
void set_msg_failobdef(string str) { MsgFailObDef = str; }
void set_msg_failob(string str) { MsgFailOb = str; }
void set_msg_totgt(string str) { MsgToTgt = str; }
void set_msg_toenv(string str) { MsgToEnv = str; }
void set_msg_toenvdef(string str) { MsgToEnvDef = str; }
void set_msg_toenvown(string str) { MsgToEnvOwn = str; }
void set_msg_toenvob(string str) { MsgToEnvOb = str; }

int cmd(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  string name, what, yourmsg, msg, sep;
  mixed ret;

  if (!str) {
    tgt = env;
    what = DefaultThing;
  }

  // smell goblin's knife, where knife is an object he is carrying
  else if (sscanf(str, "%s's %s", name, what) == 2) {
    // I use name as the name of the object we're querying everywhere else
    // and what as the string we're checking
    // smell flower on tree -> what == flower, name == tree
    // but here, name is the name of the person HOLDING the object
    // named what, and I'm being loose with the variables
    if (objectp(tgt = present(name, env)))
      tgt = present(what, tgt);
    what = DefaultThing;
  }

  // smell rose on bouquet, where bouquet is an object in room or your inv
  else {
    foreach (string s in Separators) {
      if (sscanf(str, "%s "+s+" %s", what, name) == 2) {
        if (!objectp(tgt = present(name, tp)))
          tgt = present(name, env);
        sep = s;
        break;
      }
    }
  }

  // smell rose, where rose is an object in room or your inv
  // smell rose, where rose is a smell in the room
  if (!strlen(what) || !objectp(tgt)) {
    what = DefaultThing;
    if (!objectp(tgt = present(str, tp))) {
      if (!objectp(tgt = present(str, env))) {
        tgt = env;
        what = str;
      }
    }
  }

  if (!tgt)
    FAIL(expandos(MsgFailNoTgt, tgt));

  ret = tgt->query_sense(Sense, what);

  if (!functionp(ret) && !strlen(ret)) {
    if (what == DefaultThing) {
      if (tgt == env)
        FAIL(expandos(MsgFailEnvDef, tgt));
      else
        FAIL(expandos(MsgFailObDef, tgt));
    }
    else {
      if (tgt == env)
        FAIL(expandos(MsgFailEnv, tgt, what, sep));
      else
        FAIL(expandos(MsgFailOb, tgt, what, sep));
    }
  }

  if (functionp(ret))
    ret = (string)evaluate(ret, what);

  // if not returning a message to this_player, don't show any messages,
  // let the function do it
  if (!(stringp(ret) && strlen(ret)))
    return 1;

  message(Sense, ret, tp);
  
  if (!StealthTgtMsg)
    yourmsg = MsgToTgt;

  if (!tp->use_stealth(StealthUsed)) {
    if (!strlen(yourmsg))
      yourmsg = MsgToTgt;
    if (tgt == env) {
      if (what == DefaultThing)
        msg = MsgToEnvDef;
      else
        msg = MsgToEnv;
    }
    else if (environment(tgt) == tp)
      msg = MsgToEnvOwn;
    else 
      msg = MsgToEnvOb;
    if (strlen(msg))
      message("other_action", expandos(msg, tgt, what, sep),
        env, ({ tp, tgt }) );
  }
  if (strlen(yourmsg) && tgt->is_living())
    message("other_action", expandos(yourmsg, tgt, what), tgt);

  return 1;
}

void help() {
  string s = implode(Separators, "|");
  string v;
  v = file_name(this_object());
  v = v[strsrch(v, "/", 1)+2..<1]; // extract the command name
  message("help",
    expandos(
    "Syntax: "+v+"\n"
    "        "+v+" [what]\n"
    "        "+v+" [object]\n"
    "        "+v+" [person]\n"
    "        "+v+" [what] ("+s+") [object]\n"
    "        "+v+" [what] ("+s+") [person]\n"
    "        "+v+" [person]'s [object]\n\n"
    "Allows you to "+v+" things you encounter."
    ), this_player() );
}

