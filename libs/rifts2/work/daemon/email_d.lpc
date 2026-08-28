//    This daemon handles email address registration.
//    -Diewarzau 1/28/96
//    DarkeLIB 1.0

#include <security.h>
#include <dirs.h>
#include <rooms.h>

mapping email = ([]);

string em_lower(string em);
void save_me();

void save_me() {
  seteuid(UID_DAEMONSAVE);
  save_object(DIR_DAEMONS_SAVE+"/email");
  seteuid(getuid());
}

string em_lower(string em) {
  string nm, addr;
  seteuid(UID_DAEMONSAVE);
  if(file_exists(DIR_DAEMONS_SAVE+"/email.o"))
    restore_object(DIR_DAEMONS_SAVE+"/email");
  seteuid(getuid());
  if(sscanf(em, "%s@%s", nm, addr) != 2) return lower_case(em);
  return sprintf("%s@%s", nm, lower_case(addr));
}

void create() {

  seteuid(getuid());
  return;
}

void pre_register() {
  object pl;
  int i, idx;
  string *dirs, *files, em, rept;

  seteuid(UID_USERSAVE);
  email = ([]);
  dirs = filter_array(
      map_array(get_dir(DIR_USERS+"/*"), (: $2 + $1 :),
        DIR_USERS+"/"),
      (: (file_size($1) == $2) :), -2);
  dirs = filter_array(dirs, (: (strlen($1) < $2) :), 18);
  files = ({});
  write(format_page(dirs, 2));
  i = sizeof(dirs);
  while(i--) {
    if(!get_dir(dirs[i]+"/*.o")) continue;
    files += map_array(get_dir(dirs[i]+"/*.o"), (: replace_string :),
      ".o", "");
  }
  i = sizeof(files);
  write("Number of files: "+i);
  rept = "Report:\n--------------------------------------------------\n";
  email = allocate_mapping(i);
  while(i--) {
    reset_eval_cost();
    seteuid(UID_ROOT);
    if(pl) destruct(pl);
    pl = new("/std/user");
    if(catch(master()->load_player_from_file(files[i], pl))) {
      seteuid(UID_USERSAVE);
      continue;
    }
    seteuid(UID_USERSAVE);
    em = (string)pl->query_email();
    write(sprintf("%s - %s \n",em,pl->query_name()));
    em = em_lower(em);
    if(email[em] && email[em] != files[i]) {
      rept += "Duplicate email: "+
        sprintf("%s and %s (%s)", files[i], email[em],
          em)+"\n";
    } else
      email += ([ em : files[i] ]);
  }
  seteuid(UID_ROOT);
  write_file("/open/email_report.txt", rept);
  save_me();
  seteuid(getuid());
  return;
}

int check_dup_email(string em, string nm) {
  
  em = em_lower(em);
  if(email[em]) return 1;
  seteuid(getuid());
  email += ([ em : nm ]);
  save_me();
  return 0;
}

void unregister_email(string em) {
  em = em_lower(em);
  map_delete(email, em);
  save_me();
  return;
}

string generate_pass(string nm) {
  object pl = new("/std/user");
  string pass;

  if(geteuid(previous_object()) != UID_ROOT) 
    return 0;
  seteuid(UID_ROOT);
  pl->set_name(nm);
  master()->load_player_from_file(nm, pl);
  pass = (string)ROOM_SETTER->random_password(random(4)+5);
  pl->set_password(pass);
  seteuid(UID_USERSAVE);
  pl->save_player(nm);
  seteuid(getuid());
  return pass;
}


string query_player(string em) {
  em = em_lower(em);
  if(!email[em]) return "None.";
  return email[em];
}
