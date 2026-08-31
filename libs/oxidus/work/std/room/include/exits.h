#ifndef __EXITS_H__
#define __EXITS_H__

mapping set_exits(mapping exit);
mapping remove_exit(string id);
mapping add_exit(string id, string path);
string query_exit(string id);
varargs mixed query_exit_dest(string id, int loaded);
varargs object *query_exit_dests(int loaded);
int valid_exit(string exit);
mapping query_exits();
string *query_exit_ids();
int has_pre_exit_func(string dir);
int has_post_exit_func(string dir);
void add_pre_exit_func(string dir, mixed func);
void add_post_exit_func(string dir, mixed func);
void remove_pre_exit_func(string dir);
void remove_post_exit_func(string dir);
mixed query_pre_exit_func(string dir);
mixed query_post_exit_func(string dir);

#endif // __EXITS_H__
