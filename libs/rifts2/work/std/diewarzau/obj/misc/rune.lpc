//    A generic rune.
#include <move.h>
#include <rooms.h>
#include <daemons.h>
#include <dirs.h>

inherit "/std/Object";
inherit "/std/locker_logic";

string caster;
string my_file;
string *non_active;
int level;
int clevel;

void remove();
void preserve_me();
void set_caster_level(int clvl);
int query_level();
int query_caster_level();

void set_caster_level(int clvl){clevel = clvl;}

int query_caster_level() { return clevel; }

void restore_locker(string file) {
  seteuid(getuid());
  if(!file_exists(DIR_OBJECTS+"/"+file+".o")) return;
  restore_object(DIR_OBJECTS+"/"+file);
  return;
}

int is_rune() { return 1; }

int query_level() { return level; }

void set_level(int l) { level = l; }

int my_rune_filter(object item) {
  if(!item->is_rune()) return 0;
  if(base_name(item) == base_name(this_object())) return 1;
  return 0;
}

void remove() {
  object env;
  
  if((env=environment()) && environment()->query_is_locker_room()) {
    this_object()->move(ROOM_VOID);
    SAVE_ITEMS_D->update_lockers(env);
  }
  ::remove();
  return;
}

void set_dur(int dur) {
  call_out("remove_rune", dur);
  return;
}

int detect_magic(object who) {
  if(!living(who)) return 0;
  if(caster == (string)who->query_name()) return 1;
  if(random(100) < (int)who->query_skill("detect magic")) return 1;
  return 0;
}

void start_preserve() {
  remove_call_out("remove_rune");
  return;
}

void remove_rune() {
  object *inv;

  inv = filter_array(all_inventory(environment()), "detect_magic",
    this_object());
  message("info", "%^CYAN%^A magical rune fades into nothingness.",
    inv);
  remove();
  return;
}

string query_cap_name() { return "Rune"; }

void set_caster(string str) { caster = str; }

int move(mixed dest) {
  if(objectp(dest) && living(dest)) return MOVE_NOT_ALLOWED;
  return ::move(dest);
}

void create() {
  ::create();
  set_name("rune");
  set_short("A rune");
  set_long("A rune");
  set_storage_key("rune");
  set_id(({ "rune" }));
  my_file = 0;
  level = 1;
  non_active = ({});
  return;
}

void preserve_me() {
  int spec;
  string *dir;

  seteuid(getuid());
  remove_call_out("remove_rune");
  dir = get_dir(DIR_OBJECTS+"/rune_*");
  spec = 0;
  my_file = "rune_0";
  while(member_array(my_file+".o", dir) >= 0) {
    spec++;
    my_file = sprintf("rune_%d", spec);
  }
  set_property("preserved", 1);
  SAVE_ITEMS_D->update_lockers(environment());
  return;
}

void init() {
  function go_off;
  int save;
  object who;

  who = this_player();
  
  ::init();
  if((string)who->query_name() == caster) {
    add_action("erase_rune", "erase");
    if(query_property("preserved")) {
      add_action("add_player", "runeadd");
      add_action("remove_player", "runeremove");
      add_action("list_players", "runelist");
      add_action("xfer_owner", "runeset");
    }
    if(!query_property("non-combat")) return;
  }
  if(this_object()->query("delay")) return;
  if(!functionp(go_off=query("function"))) return;
  if(query("safe flag")) return;
  if(this_player()->query_flying() && (query_level() < 3) )
    {
    message("runeinfo", "%^GREEN%^You fly, unharmed, over the rune.%^RESET%^", who);
     return;
    }
  if(wizardp(who)) return;
  if(query_property("can resist")) {
    if(stringp(query_property("save mod")))
      save = (int)who->query_stats(query_property("save mod"));
    else save = 0;
    save += (int)who->query_property("magic resistance");
    save -= 15 * query_level() - 30;
    save += ((int)who->query_level() - query_caster_level()) * 2;
    if(random(110) < save) {
      message("info", "%^CYAN%^%^BOLD%^You resist the effects of a rune.",
          this_player());
      return;
    }
  }
  if(pointerp(non_active) &&
    member_array((string)this_player()->query_name(), non_active) >= 0)
    return;
  if(this_player()->is_pet() && this_player()->query_owner()) 
    {
    	if(pointerp(non_active) &&
    	member_array((string)this_player()->query_owner(), non_active) >= 0)
    	    return;
    }
//about to change who to the caster if he's on (sorry for confusion, just saving time
    if(caster && (who=find_player(caster)) && !query_property("non-combat")) 
    {
    if(!wizardp(who)) this_player()->kill_ob(who, 1);
    if(wizardp(this_player())) return; 
    }

(*go_off)(this_player());
return;
}


int list_players(string str) {
  if(!str) return notify_fail("Syntax: runelist <rune>\n");
  if(present(str, environment()) != this_object())
    return notify_fail("Rune '"+str+"' not found.\n");
  if(!non_active || !sizeof(non_active)) {
    write("There are no players (besides you) immune to the effects "+
      "of this rune.");
    return 1;
  }
  write("The following players are immune to the effects of this rune:\n\n"+
    format_page(non_active, 2));
  return 1;
}

int erase_rune(string str) {
  string me;
  object env;

  if(!sscanf(str, "rune %s", me)) return notify_fail ("Syntax: erase rune <rune-name>\n");
  if(present(me, environment()) != this_object())
    return notify_fail("Rune '"+me+"' not found.\n");
  write("Rune erased.");
  if(query_property("preserved")) {
    env = environment();
    set("safe flag", 1);
    this_object()->move(ROOM_VOID);
    SAVE_ITEMS_D->update_lockers(env);
  }
  remove();
  return 1;
}

int xfer_owner(string str) {
  object who;

  if(!str) return notify_fail("Syntax: runeset <player>\n");
  who = find_player(lower_case(str));
  if(!who || environment(who) != environment(this_player())) {
    write("Cannot find '"+str+"'.");
    return 1;
  }
  caster = (string)who->query_name();
  write("Ownership transferred to "+capitalize((string)who->query_name())+".\n"+
  "New owner must leave and re-enter room to gain commands.");
  return 1;
}

int add_player(string str) {
  string me, player;

  if(!str || sscanf(str, "%s to %s", player, me) != 2)
    return notify_fail("Syntax: 'runeadd <player> to <rune>\n");
  if(present(me, environment()) != this_object())
    return notify_fail("Rune '"+me+"' not found.\n");
  player = lower_case(player);
  if(member_array(player, non_active) >= 0) {
    write("That player is already on the immune list.");
    return 1;
  }
  non_active += ({ player });
  write("Player: '"+player+"' added to the immune list.");
  preserve_me();
  return 1;
}

int remove_player(string str) {
  string me, player;

  if(!str || sscanf(str, "%s from %s", player, me) != 2)
    return notify_fail("Syntax: 'runeadd <player> to <rune>\n");
  if(present(me, environment()) != this_object())
    return notify_fail("Rune '"+me+"' not found.\n");
  player = lower_case(player);
  if(member_array(player, non_active) < 0) {
    write("That player is not on the immune list.");
    return 1;
  }
  non_active -= ({ player });
  write("Player: '"+player+"' removed from the immune list.");
  preserve_me();
  return 1;
}

int delay_rune(int delay) {
  if(query("delay")) return 0;
  set("delay", 1);
  set("safe flag", 1);
  call_out("delay_action", delay);
  return 1;
}

int filter_living(object who) { return living(who); }

void delay_action() {
  object *inv, who;
  int i, save;
  function go_off;

  if(!environment()) {
    remove();
    return;
  }
  set("safe flag", 0);
  inv = filter_array(all_inventory(environment()), "filter_living",
      this_object());
  if(inv && (i=sizeof(inv)) && functionp(go_off=query("function"))) {
    while(i--) {
      if(query_property("can resist")) {
        if(stringp(query_property("save mod")))
          save = (int)inv[i]->query_stats(query_property("save mod"));
        else save = 0;
        save += (int)inv[i]->query_property("magic resistance");
        save -= 15 * query_level() - 45;
        if(random(100) < save) {
          message("info", "%^CYAN%^%^BOLD%^You resist the effects of a rune.",              inv[i]);
          continue;
        }
      }
      if(caster && (who=find_player(caster)) && !query_property("non-combat"))
        inv[i]->kill_ob(who, 1);
      (*go_off)(inv[i]);
    }
  }
  set("delay", 0);
  remove();
  return;
}

string query_short() {
  if(!this_player() || random(100) <
    (int)this_player()->query_skill("detect magic"))
    return ::query_short();
  return 0;
}

int query_is_locker() {
  return query_property("preserved");
}

string query_my_file() {
  return my_file;
}


