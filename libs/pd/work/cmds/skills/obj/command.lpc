
// dynamic command in an object
// for use with spells/abils

#include <std.h>

inherit OBJECT;

mixed cmdword;
string cmdfun;
string notifyfun;
object cmdob;
int catchall;
int uses;
int cleaning;

void create() {
  ::create();
  set_weight(0);
  set_name("command_ob");
  cmdword = 0;
  cmdfun = 0;
  cmdob = 0;
  catchall = 0;
  uses = -1;
  notifyfun = 0;
  cleaning = 0;
}

void init() {
  ::init();
  if (catchall)
    add_action("do_cmd", "", 1);
  else if (cmdword)
    add_action("do_cmd", cmdword);
}

// the command(s) to catch, word can be a string or array of strings
void set_command(mixed word) {
  if (stringp(word)) cmdword = word;
  else if (arrayp(word)) cmdword = filter(word, (: stringp($1) :) );
}

// the ob->fun(str) to call when they type cmdword, fun must take a string arg
// if this fun returns -1 this command ob will halt input processing and remove itself
// if this fun returns -2 it will remove itself but let input processing fall through
void set_function(object ob, string fun) { cmdob = ob; cmdfun = fun; }

// cmdob->notifyfun(killer, victim) is called when the person kills or dies
// if it returns -1, this command ob will remove itself
void set_notify(string fun) { notifyfun = fun; }

// catch all entered text instead of just certain words
void set_catchall(int i) { catchall = ( i == 0 ? 0 : 1 ); }

// how many times this can be called, -1 is unlimited
void set_uses(int i) { uses = ( i < 0 ? -1 : i ); }

int do_cmd(string str) {
  object tp = this_player();
  int ret;

  if (cleaning) return 0;
  if (query_verb() == "quit") return 0;
  if (wizardp(tp) && query_verb() == "dest") return 0;

  if (environment(this_object()) != tp) return 0;

  if (!cmdob) return 0;
  if (!strlen(cmdfun)) return 0;

  ret = call_other(cmdob, cmdfun, str);

  if (ret == 0) return 0;

  if (!this_object()) return 1; // something removed us

  if (ret == -1 || (uses != -1 && --uses < 1)) {
    if (catchall)
      remove_action("do_cmd", "");
    else if (cmdword) {
      if (stringp(cmdword))
        remove_action("do_cmd", cmdword);
      else
        foreach (string word in cmdword)
          remove_action("do_cmd", word);
    }
    // can't remove the ob that defines the add_action you're running
    call_out("removeme", 0);
  }

  if (ret == -2) {
    cleaning = 1;
    return 0;
  }

  return 1;
}

void removeme() {
  if (this_object())
    this_object()->remove();
}

// if nothing set, remove this ob when the player dies
void notify_die(object killer) {
  if (notifyfun) {
    if (call_other(cmdob, notifyfun, killer, environment(this_object())) == -1)
      removeme();
  }
  else
    removeme();
}

// no default for killing something
void notify_kill(object victim) {
  if (notifyfun)
    if (call_other(cmdob, notifyfun, environment(this_object()), victim) == -1)
      removeme();
}

