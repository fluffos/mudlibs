#ifndef __EXITS_H
#define __EXITS_H

protected int cmd_go(string str);
protected int cmd_enter(string str);
void reinitiate();
void set_exits(mapping mp);
varargs void add_exit(string dir, string dest, function pre, function post);
void remove_exit(string dir);
string query_exit(string str);
string *query_exits();
void set_enters(mapping mp);
varargs void add_enter(string dir, string dest, function pre, function post);
void remove_enter(string dir);
string query_enter(string str);
string query_enters();
string query_direction(string dest);
void add_track(object ob, string str);
int query_track(string res);
mapping query_tracks();
void add_scent(object ob, string str);
int query_scent(string nom);
mapping query_scents();

#endif /* __EXITS_H */
