#ifndef PLAYER_H
#define PLAYER_H

/* protected fns */

protected void heart_beat();
void add_standard_commands();
protected void wiz_commands();
protected void wiz_commands2();
protected void get_new_player_object();
protected void time_out();
protected status logon();
protected void logon2(string str);
protected void check_password(string p);
protected void new_password(string p);
protected void logon3();
protected void logon4(string maddr);
protected void logon5();
protected void logon6(string gender_str);
protected void logon7();
protected void logon8(string str);
protected void logon8_validate_race(string str);
protected void logon9_log_wizard();
protected void logon9(object where);
protected void logon9_throw_out_other_copy(string str);
protected void destruct_all_inventory(object ob);
protected status wimpy(string str);
protected status change_password();
protected void change_password1(string str);
protected void change_password2(string str);
protected status suicide();
protected void pass1(string str);
protected status suicide_note(string arg);
protected void do_suicide(string note);
protected status describe();
protected status get_desc(string arg);
protected status skills(string str);
protected status score();
protected status  hp();
protected status chfn();
protected void chfn2(string str);
protected void chfn3(string str, status plan_only);
protected void chfn4(string arg);
protected status change_plan();
protected status fix_it(string str);
protected status put(string str);
protected status pick_up(string str);
protected status drop_thing(string str);
protected status  give_object(string str);
protected status kill(string str);
protected status access(string dir, string file, string mode);
protected status show_mainlog();
protected status security(int sec_level);
protected int FILE_SIZE(string file);

protected status filter_users(object ob);
protected status filter_wizards(object ob);
protected status by_name(object a, object b);
protected status by_level(object a, object b);
protected status by_age(object a, object b);
protected status by_environment(object a, object b);
protected status by_level(object a, object b);
protected status by_ip_number(object a, object b);
protected status by_sec_level(object a, object b); 
protected status command_centre(string str);
status do_cmd(string str);
protected status echo(string str);
protected status more(string str);

/* callable fns */

/* sets */

string set_title(string t);
string set_pretitle(string t);
string set_al_title(string t);
string set_enter_room(string str);
int set_intoxicated(int i);
int set_stuffed(int i);
int set_soaked(int i);
int set_headache(int i);
int set_scar(int i);
string set_quests(string *arr);
string set_guild_string(string s);
string set_email(string s);
string set_description(string s);
string set_plan(string s);
int set_time_to_save(int i);
status set_edit_on(status i);
status set_informed(status i);
status set_start();

/* querys */

string query_realname();
string query_last_login();
string query_enter_room();
status query_edit();
status query_informed();
status query_prevent_shadow();
string query_email();
string query_al_title();
string query_title();
string query_desc();
int query_total_exp();
int query_intoxication();
int query_stuffed();
int query_soaked();
string query_guild_string();
object query_other_copy();

/* toggles */

status toggle_brief(status silently);
status toggle_no_wimpy();
status toggle_ghost();

/*  quests */  
  
status query_quest(string str);
void add_quest(string str);
void remove_quest(string str);

/* adds */

int add_exp(int e);
int add_intoxication(int i);
int add_stuffed(int i);
int add_soaked(int i);
void add_alignment(int a);


varargs void shout_tell(string str, string lang);
void show_scar();
status save_character();
void save_me(status value_items);
status restore_me();
status quit(mixed arg);
status church();
status inventory();
status examine(string str);
status look(string str, status extra);
status help(string what);
status second_life();
int drink_alcohol(int drink_strength);
status drink_soft(int drink_strength);
status eat_food(int food_strength);
string valid_write(string str);
string valid_read(string str);
status tail_file(string path);
status cat_file(string path);

status secure(int sec_level);
int query_security();
int query_security_level();
int set_security_level(string domain);
string make_path(string file);
status pwd();
status toggle_invis();
int compute_values(object ob);
void illegal_patch(string what);
void load_auto_obj();
void compute_auto_str();

int get_alias_index(string str);
status add_alias(string str);
void remove_alias(string str);
status log_for_players(string file, string str);
string who();
status emote(string str);
status tell(string str);
status whisper(string str);
status shout_to_all(string str);
protected void move_or_destruct_inventory(object arg);



status valid_file_name(string arg);
void get_party();
status toggle_hp( string str);

#endif /* PLAYER_H */
