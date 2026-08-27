
  /* inheritance */
inherit "/std/room";

  /* global variables */
string save_file;
string guild_name;
string guildmaster;
string guildmaster_title;
string *patrons;
string *officers;
string *members;
string message;

  /* function declarations */
void load_it();
void save_it();
int add_guild_office(string office);

  /* function definitions */
void create() {
  save_file = file_name(this_object()) + "_save";
  patrons = ({ });
  officers = ({ });
  members = ({ });
  ::create();
  load_it();
}

void dest_me() {
  save_it();
  ::dest_me();
}

string query_save_file() { return save_file; }
void set_save_file(string file_name) {
  save_file = file_name;
  load_it();
}

string query_guild_name() { return guild_name; }
void set_guild_name(string name) { guild_name = name; }

string query_guildmaster() { return guildmaster; }
string set_guildmaster(string name) { guildmaster = name; }

string query_guildmaster_title() { return guildmaster_title; }
string set_guildmaster_title(string title) { guildmaster_title = title; }

string query_guild_message() {
  load_it();
  return message;
}

void set_guild_message(string str) {
  message = str;
  save_it();
}

string *query_guild_patrons() {
  load_it();
  return patrons;
}

int add_guild_patron(string name) {
  if (!patrons)
    patrons = ({ });
  name = lower_case(name);
  if (member_array(name, patrons) != -1)
    return 0;
  patrons += ({ name });
  save_it();
  return 1;
}

int remove_guild_patron(string name) {
  if (!patrons)
    patrons = ({ });
  name = lower_case(name);
  if (member_array(name, patrons) == -1)
    return 0;
  patrons -= ({ name });
  save_it();
  return 1;
}

string *query_guild_officers() {
  load_it();
  return officers;
}

int set_guild_office(string name, string office) {
  int i;

  if (!officers)
    officers = ({ });
  name = lower_case(name);
  if (member_array(name, officers) != -1)  
    return 0;
  if ((i = member_array(office, officers)) == -1) {
    add_guild_office(office);
    i = member_array(office, officers);
  }
  officers[i-1] = name;
  save_it();
  return 1;
}

int add_guild_office(string office) {
  if (!officers)
    officers = ({ });
  if (member_array(office, officers) != -1)
    return 0;
  officers += ({ "" });
  officers += ({ office });
  save_it();
  return 1;
}

int remove_guild_office(string office) {
  int i;

  if (!officers)
    officers = ({ });
  if ((i = member_array(office, officers)) == -1)
    return 0;
  officers -= ({ office });
  officers -= ({ officers[i-1] });
  save_it();
  return 1;
}

string *query_guild_members() {
  load_it();
  return members;
}

int add_guild_member(string name) {
  if (!members)
    members = ({ });
  name = lower_case(name);
  if (member_array(name, members) != -1)
    return 0;
  members += ({ name });
  save_it();
  return 1;
}

int remove_guild_member(string name) {
  if (!members)
    members = ({ });
  name = lower_case(name);
  if (member_array(name, members) == -1)
    return 0;
  members -= ({ name });
  save_it();
  return 1;
}

int check_member(string name) {
  if (!members)
    members = ({ });
  if (!officers)
    officers = ({ });
  name = lower_case(name);
  if (name == guildmaster)
    return 1;
  if (member_array(name, officers) != -1)
    return 1;
  return (member_array(name, members) != -1);
}

void load_it() {
  if (save_file)
      restore_object(save_file);
}

void save_it() {
  if (save_file)
      save_object(save_file);
}
