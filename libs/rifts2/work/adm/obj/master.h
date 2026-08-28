/* FILE: /adm/obj/master.h */
#include <config.h>
#include <daemons.h>
#include <databases.h>
#include <dirs.h>
#include <objects.h>
#include <rooms.h>
#include <security.h>
#define READ 0
#define WRITE 1

#define GROUP_DAEMON "/adm/obj/master/group_d"
#define PRIVS_DAEMON "/adm/obj/master/privs_d"
#define ACCESS_DAEMON "/adm/obj/master/access_d"

/* Required function definitions */
string creator_file(string str);

void preload(string str);

void load_access();

void load_groups();

void load_privs();

nomask int check_access(string file, object ob, int ind);

/* Optional function definitions */
void flag(string str);

string *epilog(int load_empty);

string error_handler(mapping errs, int caught);

int view_errors(object user);

int valid_save_binary(string file);

void socket_preload();

int valid_write(string file, object ob, string fun);

int valid_read(string file, object ob, string fun);

nomask int check_access(string file, object ob, int ind);

object connect();

mixed compile_object(string file);

nosave void crash(string err);

int valid_shutdown(string euid);

int valid_seteuid(object ob, string id);

int valid_bind(object binder, object old_obj, object new_obj);

int valid_shadow(object ob);

int valid_snoop(object snooper, object snoopee);

int valid_exec(string nom);

int valid_hide(object who);

int valid_override(string file, string nom);

int valid_socket(object caller, string func, mixed *info);

int load_player_from_file(string nom, object ob);

void save_player_to_file(object ob);

string get_wiz_name(string file);

void log_error(string file, string msg);

void destruct_environment_of(object ob);

string make_path_absolute(string file);

int player_exists(string str);

string get_root_uid();

string get_bb_uid();

string creator_file(string str);

string domain_file(string str);

string author_file(string str);

nosave int slow_shutdown();

int save_ed_setup(object who, int code);

int retrieve_ed_setup(object who);

string get_ed_buffer_save_file_name(string file);

int is_locked();

int query_member_group(string who, string grp);

mapping query_groups();