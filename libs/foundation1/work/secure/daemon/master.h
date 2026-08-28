#ifndef __MASTER_H
#define __MASTER_H

void create();
void new_read();
void new_write();
void new_groups();
nosave private void load_access(string cfg, mapping refmap);
void flag(string str);
string *epilog(int x);
string privs_file(string file);
void preload(string str);
void socket_preload();
int valid_write(string file, object ob, string fun);
int valid_read(string file, object ob, string fun);
int valid_apply(string *ok);
int check_access(object ob, string fun, mixed file, string *ok, string oper);
nomask nosave int check_user(object ob, string fun, string file, string oper);
nomask nosave int check_domain(object ob, string fun, string file, string o);
object connect();
object compile_object(string str);
nosave void crash(string err);
int valid_hide(object who);
int valid_override(string file, string nom);
int valid_socket(object ob, string fun, mixed *info);
string get_wiz_name(string file);
mixed apply_unguarded(function f);
string error_handler(mapping mp, int caught);
void log_error(string file, string msg);
void destruct_env_of(object ob);
string make_path_absolute(string file);
int player_exists(string str);
string domain_file(string str);
string author_file(string str);
nosave int slow_shutdown();
int save_ed_setup(object who, int code);
int retrieve_ed_setup(object who);
string get_save_file_name(string file);
int is_locked();
string *parse_command_id_list();
string *parse_command_plural_id_list();
string *parse_command_adjectiv_id_list();
string *parse_command_prepos_list();
string parse_command_all_word();
void create_save();
object player_object(string nom);
string get_root_uid();
string get_bb_uid();
string creator_file(string str);

#endif /* __MASTER_H */
