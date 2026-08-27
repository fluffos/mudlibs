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
void load_admin_teams();
int query_admin_team_member(string member, string team);
varargs int valid_query_ip(mixed actor, object target);

/*
 * /secure/master/fob.c
 */
nosave void remove_all_applications(string wname);
nosave string add_wizard_to_domain(string dname, string wname, string cmder);
nosave int do_change_rank(string wname, int rank, string cmder);

/*
 * /secure/master/purge.c
 */

/*
 * /secure/master/sanction.c
 */
nosave void remove_all_sanctions(string name);
