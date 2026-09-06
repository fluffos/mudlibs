/* Idle daemon

Evicts idling players from the mud.

NEW:  Players get bonuses to allowable idle time based on level
NEW:  Idling wizards get even bigger bonuses than players, but are
    no longer immune (security concerns wrt. unsecured consoles.  These guys
    do have special access to the mud after all)

Admins however, are still immune because they are:
1)  observably prone to koaning
2)  grumpy if disconnected without their consent
3)  trusted to be 1337 enough not to leave their consoles open and unsecured

*/

void create()
{
    call_out("check_all_users", 60);
}

void idle_boot(object sleepyhead)
{
    object who;
    foreach(who: users()) {
        set_actor(sleepyhead);
        set_listener(who);
        msg_object(who,"~CLAB~Name ~verbfall asleep and ~verbroll offline.~CDEF");
    }
    sleepyhead->quit(1);
}

void check_all_users()
{
    object who;
    remove_call_out("check_all_users");
    foreach (who: users()) {
        int idle_score;
        int level_buff;
        int staff_buff;
        int total_idleness;

        idle_score = query_idle(who);
        level_buff = who->query_level();

        if (level_buff >= 1000) {
            continue; /* don't grumpify a koany admin */
        }

        /* level bonus */
        if (level_buff >= WIZLEVEL) {
            staff_buff = level_buff - WIZLEVEL;
            level_buff = WIZLEVEL;
        }

        /* 1 minute bonus on allowable idleness per player level */
        /* 10 minute bonus on allowable idleness per wizard level */

        total_idleness = idle_score
            - (1 * 60 * level_buff)
            - (10 * 60 * staff_buff);

        /* base idleness allowed is 30 minutes */

        if (total_idleness > 30 * 60) {
            idle_boot(who);
        }
    }
    call_out("check_all_users", 60);
}
