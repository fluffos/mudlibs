
/*
 * Patches to destruct sleepers.  If called twice while player is non-
 * interactive, it will destroy the player and inventory.  Called every
 * MAX_QUIET_TIME seconds, currently 5 mins, so a player gets 5-10
 * mins of grace after a disconnect.  Hacked to also check login times
 * and warn the user of his impending demise.  Further hacked to implode
 * them if they are idle for too long.
 *
 * Players do NOT get reimbursed for their inventory - too easy to make
 * too much money...
 *
 * Gandalf's patch.
 */

int telltime;

/*
 * 19980501 Hunter   added use of max_quiet_time store variable
 */

sleeper_check(arg) 
{
    call_out("sleeper_check", MAX_QUIET_TIME, 0);
    (int|string) is_interactive = query_ip_number(this_object());
    string qm = "link dead";
    int qt = this_object()->query_store("max_quiet_time");
    if (!qt)
      qt = MAX_QUIET_TIME;

    if (is_interactive) {
	if (this_object()->query_idle() < qt*3)
	    return;
	if (query_wiz())
	    return;
	qm = "idle";
	}
    else {
	if (this_object()->query_idle() < qt*2)
	    return;
	qm = "link dead";
	}
    save_me();
    object o = environment();
    if (o)
        tell_room(o, short() + " decides that being " + qm + " is boring.\n");
    log_enter("(LD quit sequence)");
    cmdquit();
    }


/*
 * quick check to ensure the player is allowed to be logged on now.
 * called from sleeper_check and login.
 */

still_in_hours() {
        int day;
        int tm2;

    day = ((time() + TIME_ADJUST)/DAY) % 7;
    if (!( (day == 2) || (day == 3)) ) {
    if (!allow(name)) {
    tm2 = ((time()+TIME_ADJUST) % DAY);
    if ((tm2 > MORNING) && (tm2 < EVENING)) { 
	return 0;
	} 
      }
    }
    return 1;
}

