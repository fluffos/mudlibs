
// dynamic stop command in an object

#include <std.h>

inherit OBJECT;

string stopstr;
string stopfun;
object stopob;
object *victims;

void create() {
  ::create();
  set_weight(0);
  set_name("stop_ob");
  stopstr = "";
  stopfun = "";
  stopob = 0;
  victims = ({});
}

void init() {
  ::init();
  add_action("cmd_stop", "stop");
}

string query_stop() { return stopstr; }
// set_stop("drinking"); will let you <stop drinking>
void set_stop(string str) { stopstr = str; }
// the ob->fun(tp) to call when they stop, fun must take an object arg which is this_player
void set_function(object ob, string fun) { stopob = ob; stopfun = fun; }
// a watch list of victims, if these all die this ob goes away
void set_victims(object *vic) { victims = vic; }

int cmd_stop(string str) {
  object tp = this_player();
  if (environment(this_object()) != tp) return 0;

  if (str != stopstr) return 0;
  if (!stopob) return 0;
  if (!strlen(stopfun)) return 0;

  // if victims has been set, make sure at least one is still alive
  if (!sizeof(victims) || sizeof(filter(victims, (: objectp($1) :) )))
    call_other(stopob, stopfun, tp);

  // only one use of this command possible
  remove_action("cmd_stop", "stop");
  // can't remove the ob that defines the add_action you're running
  call_out("removeme", 0);

  return 1;
}

void removeme() {
  this_object()->remove();
}

void notify_kill(object vic) {
  if (!sizeof(victims)) return;

  // remove mobs that have been killed by someone else
  victims = filter(victims, (: objectp($1) :) );

  // if this kill is in the list, remove it...
  if (member_array(vic, victims) != -1)
    victims -= ({ vic });

  // ...and if it was the last one, we're done
  if (!sizeof(victims))
    removeme();
}
// remove if the user dies
void notify_die(object killer) {
  removeme();
}

