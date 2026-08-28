#ifndef __USER_H
#define __USER_H

void create();
void setup();
void init_path();
void net_dead();
void restart_heart();
void describe_current_room(int verbose);
varargs void move_player(mixed dest, string msg);
int remove();
void receive_message(string msg_class, string msg);
void hide(int x);
void reset_terminal();
void restrict_channel(string channel);
void unrestrict_channel(string str);
nosave private void register_channels();
void receive_snoop(string str);
int cmd_quit(string str);
int query_age();
int set_blocked(string type);
int query_blocked(string type);
string *query_channels();
void set_client(string str);
string query_client();
string query_cwd();
void set_email(string str);
string query_email();
void set_id(string *bogus);
string *query_id();
int id(string str);
varargs int query_invis(object ob);
int query_login_time();
void set_log_harass(int x);
int query_log_harass();
void set_name(string str);
string query_name();
void set_news(string type, int sz);
int query_news(string type);
void set_password(string str);
string query_password();
void set_position(string str);
string query_position();
string query_prompt();
void set_real_name(string str);
string query_real_name();
string query_short();
string query_title();
int set_verbose();
int query_verbose();
int set_where_block();
int query_where_block();
string get_path();
varargs void setenv(string key, string val);
string getenv(string key);

#endif /* __USER_H */
