/*
 * /secure/master.h
 *
 * This file includes the prototypes for the master. Since the master has
 * been split in several files, some prototypes are necessary to allow
 * the functions to access functions in other parts that are included after
 * the calling module.
 */

/*
 * /secure/master.c
 */
nosave void reset_master();
nosave void save_master();
varargs object finger_player(string pl_name, string file);
varargs mixed do_debug(string icmd, mixed a1, mixed a2, mixed a3);
public void check_memory(int dodecay);
string creator_object(object obj);
public int valid_player_info(mixed actor, string name, string func);
varargs int valid_query_ip(mixed actor, object target);
int valid_read(string file, mixed reader, string func);
int valid_write(string file, mixed writer, string func);
int exist_player(string pl_name);
public int query_start_time();

/*
 * /secure/master/fob.c
 */
nosave void remove_all_applications(string wname);
nosave string add_wizard_to_domain(string dname, string wname, string cmder);
nosave int do_change_rank(string wname, int rank, string cmder);

/*
 * /secure/master/sanction.c
 */
nosave void remove_all_sanctions(string name);


/*
 * /secure/master/guild.c
 */
nosave void remove_from_guilds(string name);
