/*
 * Wiz character daemon v1.0
 *
 * Keeps track of wiz players and test chars, can also be called to keep
 * track of cheating.
 *
 * Diewarzau 10/22/96
 * DarkeLIB 1.0
 */

#include <security.h>
#include <dirs.h>
#define WIZARD 1
#define PLAYER 2
#define TESTCHAR 3

object *wizchars_on;

class wiz_char {
  string name;
  string wiz_owner;
  int date_registered;
  int char_type;
  int time_on;
}

class wiz_char *load_characters();
void save_characters (class wiz_char *chars);
class wiz_char find_character(string my_name, class wiz_char *chars);

class wiz_char *load_characters() {
  class wiz_char *ret;
  string euid = geteuid(this_object());
  
  seteuid(UID_SECURE_DAEMONSAVE);
  if(!file_exists(DIR_SECURE_DAEMONS_SAVE+"/wizchar.v")) return ({});
  ret = restore_variable(read_file(DIR_SECURE_DAEMONS_SAVE+"/wizchar.v"));
  if(euid) seteuid(euid);
  else seteuid(getuid());
  return ret;
}

void save_characters(class wiz_char *chars) {
  string euid = geteuid(this_object());
  
  seteuid(UID_SECURE_DAEMONSAVE);
  if(file_exists(DIR_SECURE_DAEMONS_SAVE+"/wizchar.v"))
    rm(DIR_SECURE_DAEMONS_SAVE+"/wizchar.v");
  write_file(DIR_SECURE_DAEMONS_SAVE+"/wizchar.v", save_variable(chars));
  if(euid) seteuid(euid);
  else seteuid(getuid());
  return;
}

class wiz_char find_character(string my_name, class wiz_char *chars) {
  int i = sizeof(chars);

  while(i--) if(chars[i]->name == my_name) return chars[i];
  return 0;
}

void create() {
  class wiz_char *chars = load_characters();
  class wiz_char my_char;
  object *on = users();
  object who;

  seteuid(getuid());
  wizchars_on = ({});
  foreach(who in on) {
    foreach(my_char in chars)
      if((string)who->query_name() == my_char->name) wizchars_on += ({ who });
  }
  if(!event_pending(this_object())) {
    event("output_log", 32400, 0, 1);
  }
  call_out("update_chars", 62);
  return;
}

void update_chars() {
  class wiz_char *chars = load_characters();
  class wiz_char my_char;
  object who;
  object *new_chars = ({});
  string *who_add = ({});

  foreach(who in wizchars_on) {
    if(!who || !interactive(who)) continue;
    my_char = find_character((string)who->query_name(), chars);
    if(!my_char) continue;
    new_chars += ({ who });
    if(my_char->char_type == PLAYER && find_player(my_char->wiz_owner)) {
      seteuid(UID_LOG);
      log_file("wiz_illegal", "---Wiz player and Wiz logged on simultaneously---\n"+
        sprintf("Wiz: %s   Player: %s  Time %s\n", my_char->wiz_owner, my_char->name,
        ctime(time())));
      seteuid(getuid());
    }
    if(query_idle(who) >= 40) continue;
    who_add += ({ my_char->name });
  }
  foreach(my_char in chars) {
    if(member_array(my_char->name, who_add) >= 0) my_char->time_on += 62;
    who = find_player(my_char->name);
    if(!who || member_array(who, new_chars) != -1) continue;
    new_chars += ({ who });
  }
  save_characters(chars);
  wizchars_on = new_chars;
  call_out("update_chars", 60);
  return;
}

void output_log() {
  class wiz_char *chars = load_characters();
  class wiz_char *wizzes = ({});
  class wiz_char my_char;
  class wiz_char wiz;
  string log_str;
  string type;

  foreach(my_char in chars)
    if(my_char->char_type == WIZARD) wizzes += ({ my_char });
  log_str = sprintf("%|70s\n%|70s\n%s\n", "Log of Registered Wiz Character Times",
    ctime(time()), repeat_string("-=", 35));
  foreach(wiz in wizzes) {
    log_str += sprintf("\n%-13s Date Reg.: %s  Time On: %d:%02d\n", wiz->name,
      ctime(wiz->date_registered), wiz->time_on/3600, (wiz->time_on%3600)/60);
    foreach(my_char in chars) {
      if(my_char->char_type == WIZARD) continue;
      if(my_char->wiz_owner != wiz->name) continue;
      if(my_char->char_type == PLAYER) type = "Pl";
      else type = "TC";
      log_str +=
        sprintf("%4s: %-13s Date Reg.: %s  Time On: %d:%02d\n", type, my_char->name,
          ctime(my_char->date_registered), my_char->time_on/3600, (my_char->time_on%3600)/60);
      if(my_char->time_on > (wiz->time_on/2) && !member_group(wiz->name,
        ({ "elder", "mentor", "assist", "arch", "superuser" })) && my_char->char_type == PLAYER)
        log_str += "     VIOLATION!!!\n";
    }
  }
  seteuid(UID_LOG);
  if(file_exists("/log/wizchar_time")) rm("/log/wizchar_time");
  log_file("wizchar_time", log_str);
  return;
}

int is_registered(string who) {
  class wiz_char *chars = load_characters();
  class wiz_char res;

  res = find_character(who, chars);
  if(!res) return 0;
  return res->char_type;
}

void register(string who, int type, string owner) {
  class wiz_char *chars = load_characters();
  class wiz_char newchar;

  if(find_character(who, chars)) return;
  newchar = new(class wiz_char);
  newchar->name = who;
  newchar->time_on = 0;
  newchar->date_registered = time();
  newchar->wiz_owner = owner;
  newchar->char_type = type;
  chars += ({ newchar });
  save_characters(chars);
  return;
}

void debug_wizchars() {
  write(sprintf("%O", wizchars_on));
  return;
}

int remove_wizchar(string who) {
  class wiz_char *chars = load_characters();
  int idx, i;

  i = sizeof(chars);
  idx = -1;
  while(i--)
    if(chars[i]->name == who) idx = i;
  if(idx < 0) return 0;
  save_characters(exclude_array(chars, idx));
  return 1;
}

int compensate(string who, int tm) {
  class wiz_char *chars = load_characters();
  class wiz_char my_char;
  int i;

  if(!this_player() || !archp(this_player())) return 0;
  i = sizeof(chars);
  while(i--)
    if(chars[i]->name == who) my_char = chars[i];
  if(!my_char || tm < 0) return 0;
  my_char->time_on += tm;
  save_characters(chars);
  return 1;
}
