#include <std.h>
#include <locations.h>

inherit OBJECT;

string seal_mark_cmd, seal_break_cmd;
string seal_mark_msg, seal_break_msg, seal_break_room_msg;
string seal_finish_msg, seal_finish_room_msg, seal_finish_enter_msg;
string seal_meld_msg;
string seal_marked_filename, seal_marked_label;
string seal_marked_short, seal_marked_long;
string *seal_marked_id;
int seal_is_marked, seal_max;
string seal_guild;
int seal_autoload_level;

mixed query_property(string prop);
string expandos(string str);
void set_marked(int x);
void set_marked_filename(string file);
void set_marked_label(string label);
void set_marked_short(string sh);
void set_marked_long(string lo);
void set_marked_id(string *i);
void set_seal_max(int x);
void set_mark_command(string str);
void set_break_command(string str);
void set_mark_msg(string str);
void set_break_msg(string str);
void set_break_room_msg(string str);
void set_finish_msg(string str);
void set_finish_room_msg(string str);
void set_finish_enter_msg(string str);
void set_meld_msg(string str);
void set_guild(string str);
void set_autoload_level(int);
int query_marked();
int query_seal_max();
string query_marked_filename();
string query_marked_label();
string query_marked_short();
string query_marked_long();
string *query_marked_id();
string query_mark_command();
string query_break_command();
string query_mark_msg();
string query_break_msg();
string query_break_room_msg();
string query_finish_msg();
string query_finish_room_msg();
string query_finish_enter_msg();
string query_meld_msg();
string query_guild();
int query_autoload_level();
int do_mark(string str);
int do_break(string str);
void finish_teleport(object tp);
void set_marked_descs();
void do_meld();
mixed *query_auto_load();
void init_arg(mixed *args);


void create() {
  ::create();
  
  // defaults
  set_marked(0);
  set_seal_max(30);
  set_mark_command("mark");
  set_break_command("break");
  set_marked_short("A seal marked with $L");
  set_marked_long("A small hardened wax seal marked with the location of $L.\n");
  set_marked_id( ({ "seal", "marked seal" }) );
  set_mark_msg("\n%^BOLD%^%^WHITE%^You mark the wax with a location.\n");
  set_break_msg("%^BOLD%^%^GREEN%^Mystical energies engulf you!\n");
  set_break_room_msg("%^BOLD%^%^GREEN%^Mystical energies engulf $N!\n");
  set_finish_msg("\n%^BOLD%^%^GREEN%^You appear in a new location!\n");
  set_finish_room_msg("%^BOLD%^%^GREEN%^$N vanishes from sight$R!");
  set_finish_enter_msg("%^BOLD%^%^GREEN%^$N appears$R.");
  set_meld_msg("$S melts in your hand.");
  set_autoload_level(20);
}

void init() {
  object to = this_object();
  object env;
  object *allofme;

  ::init();

  if (!to || !(env = environment(to)) || this_player() != env) return;

  allofme = filter(all_inventory(env),
    (: base_name($1) == base_name($(to)) :)
  );

  if (sizeof(allofme) > query_seal_max()) {
    call_out("do_meld", 2);
    return;
  }

  if (!query_guild() || (query_guild() && this_player()->query_guild() == query_guild())) {
    if (!query_marked()) {
      add_action("do_mark", query_mark_command());
    }
    else {
      add_action("do_break", query_break_command());
    }
  }

}

mixed query_property(string prop) {
  if (prop && prop == "magic item")
    return ( (string *)::query_property(prop) || ({}) )+
      ({ query_marked() ? query_break_command() : query_mark_command() });
  return ::query_property(prop);
}

void set_marked_filename(string file) { seal_marked_filename = file; }
void set_marked_label(string label) { seal_marked_label = label; }
void set_marked(int x) { seal_is_marked = (x > 0 ? 1 : 0); }
void set_marked_short(string sh) { seal_marked_short = sh; }
void set_marked_long(string lo) { seal_marked_long = lo; }
void set_marked_id(string *i) { seal_marked_id = i; }
void set_seal_max(int x) { seal_max = x; }
void set_mark_command(string str) { seal_mark_cmd = str; }
void set_break_command(string str) { seal_break_cmd = str; }
void set_mark_msg(string str) { seal_mark_msg = str; }
void set_break_msg(string str) { seal_break_msg = str; }
void set_break_room_msg(string str) { seal_break_room_msg = str; }
void set_finish_msg(string str) { seal_finish_msg = str; }
void set_finish_room_msg(string str) { seal_finish_room_msg = str; }
void set_finish_enter_msg(string str) { seal_finish_enter_msg = str; }
void set_meld_msg(string str) { seal_meld_msg = str; }
void set_guild(string str) { seal_guild = str; }
void set_autoload_level(int x) { seal_autoload_level = x; }

int query_marked() { return seal_is_marked; }
int query_seal_max() { return seal_max; }
string query_marked_filename() { return seal_marked_filename; }
string query_marked_label() { return seal_marked_label; }
string query_marked_short() { return seal_marked_short; }
string query_marked_long() { return seal_marked_long; }
string *query_marked_id() { return seal_marked_id; }
string query_mark_command() { return seal_mark_cmd; }
string query_break_command() { return seal_break_cmd; }
string query_mark_msg() { return seal_mark_msg; }
string query_break_msg() { return seal_break_msg; }
string query_break_room_msg() { return seal_break_room_msg; }
string query_finish_msg() { return seal_finish_msg; }
string query_finish_room_msg() { return seal_finish_room_msg; }
string query_finish_enter_msg() { return seal_finish_enter_msg; }
string query_meld_msg() { return seal_meld_msg; }
string query_guild() { return seal_guild; }
int query_autoload_level() { return seal_autoload_level; }

string expandos(string str) {
  mapping exp = ([
    "N" : (: this_player() ? this_player()->query_cap_name() : "" :),
    "L" : (: query_marked() ? query_marked_label() : "" :),
    "S" : (: query_short() :),
    "R" : (: (this_player() && sizeof(this_player()->query_riders()) ) ?
             " with "+this_player()->query_riders_list()+" on "+this_player()->query_possessive()+" back" : "" :),
  ]);

  foreach (string thing, mixed f in exp)
    str = replace_string(str, "$"+thing, (*f)() );

  return str;
}

int do_mark(string str) {
  object tp = this_player();
  object env = environment(tp);

  if (tp->query_paralyzed()) return 0;

  if (!str || str == "")
    return notify_fail("Syntax: "+query_mark_command()+" [location]\n");

  if (strsrch(str, " ") != -1)
    return notify_fail("Only one word is allowed.\n");

  if (!env || env->query_property("no teleport"))
    return notify_fail("A magical force prevents you.\n");

  set_marked(1);
  set_marked_filename(base_name(env));
  set_marked_label(str);

  add_action("do_break", query_break_command());
  remove_action("do_mark", query_mark_command());

  message("info", expandos(query_mark_msg())+"%^RESET%^", tp);

  set_marked_descs();

  return 1;
}

int do_break(string str) {
  object tp = this_player();
  object env = environment(tp);

  if (!str || present(str, tp) != this_object()) return 0;

  if (tp->query_paralyzed()) return 0;

  if (!env || env->query_property("no teleport"))
    return notify_fail("A magical force prevents you.\n");

  if (tp->query_current_attacker())
    return notify_fail("You are too busy fighting!\n");

  if (tp->query_arena())
    return notify_fail("You cannot do that in the arena!\n");

  if (tp->query_ghost())
    return notify_fail("You cannot do that as a ghost.\n");

  message("info", expandos(query_break_msg())+"%^RESET%^", tp);
  message("info", expandos(query_break_room_msg())+"%^RESET%^", env, tp);

  call_out("finish_teleport", 6, tp);
  remove_action("do_break", query_break_command());
  this_object()->move(TEMP_LOC);

  return 1;
}

void finish_teleport(object tp) {
  object oldenv;
  object newenv;
  object *who;

  if (!tp || tp->query_ghost()) return;

  oldenv = environment(tp);

  if (!oldenv || oldenv->query_property("no teleport") ||
      !(newenv = load_object(query_marked_filename()))) {
    message("info", "Nothing happens.", tp);
    return;
  }

  message("info", expandos(query_finish_msg())+"%^RESET%^", tp);
  message("info", expandos(query_finish_room_msg())+"%^RESET%^", oldenv, tp);

  who = ({ tp });
  if (sizeof(tp->query_riders())) {
    who += (object *)tp->query_riders();
    message("info", "You are pulled along on "+tp->query_cap_name()+"'s back.",
      tp->query_riders() );
  }
  who->move(newenv);

  message("info", expandos(query_finish_enter_msg())+"%^RESET%^", newenv, who);

  who->describe_current_room(1);

  this_object()->remove();
}

void set_marked_descs() {
  set_short(expandos(query_marked_short())+"%^RESET%^");
  set_long(expandos(query_marked_long())+"%^RESET%^");
  set_id( ( sizeof(query_marked_id()) ? query_marked_id() : query_id() ) + ({ query_marked_label() }) );
}

void do_meld() {
  message("info", expandos(query_meld_msg())+"%^RESET%^", environment(this_object()));
  this_object()->remove();
}

mixed *query_auto_load() {
  if (this_player()->query_level() >= query_autoload_level() &&
      (!query_guild() || this_player()->query_guild() == query_guild()))
    return ({ base_name(this_object()),
              ({ query_marked(), query_marked_label(), query_marked_filename() })
           });
  else
    return 0;
}

void init_arg(mixed *args) {

  // old seals did it this way
  if (sizeof(args) == 4) {
    seal_is_marked = args[3];
    seal_marked_label = args[0];
    seal_marked_filename = args[2];
  }
  // this is for new seals
  else {
    seal_is_marked = args[0];
    seal_marked_label = args[1];
    seal_marked_filename = args[2];
  }

  if (query_marked())
    set_marked_descs();
}

