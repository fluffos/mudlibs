// Petrarch
// Merentha Lib 1.0
// user.c

#ifndef __USER_H__
#define __USER_H__

void set_class(string str);
int move_player(mixed dest);
void display_welcome_messages();
void save_player(string name);
void load_player(string name);
void add_channels();
void setup();
string query_position();
void set_position(string str);
void set_password(string str);
string query_password();
void catch_tell(string str);
int id(string arg);
string process_input(string arg);
int cmd_quit();
void receive_message(string msgclass, string msg);
void net_dead();
void reconnect();
void init_aliases();
void add_alias(string a, string b);
void remove_alias(string a);
varargs mixed query_alias(string a);
void init_nicknames();
void add_nickname(string a, string b);
void remove_nickname(string a);
string *query_history();
varargs mixed query_nickname(string a);
void setenv(string env, mixed arg);
mixed getenv(string env);
int is_user();

varargs void more(mixed input, int lines, int start, object return_object, string return_function, string topic, int x);
string write_prompt();
string query_cwd();
int set_cwd(string dir);

#endif
