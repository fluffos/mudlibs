/*
 *	Start a character up after we've been switched to.
 *	Reworked - G.
 *	There's some stuff at the end still waiting to be put in (ripped 
 *	out of connect.c)
 *	Initial stats are set by the new_player callback; they are placed 
 *	on the `stat learning' list, to be settled in to over time from 
 *	initial stats of 12 or less.
 *
 * This is going to be reworked again (in the fullness of time) to 
 * integrate most startup functions into one function, which accepts 
 * a `level', ranging from uninitialised to fully logged in and 
 * operative.  The `connectedness' status won't matter, because
 * players will just be objects.
 */

/* 
 * History
 * 951219 Hunter	fixed bug with start_location (it didn't
 *			shift the player to a location, if they had
 *			a home set, and it could not be loaded).
 * 990113 Jenna		Modified to use new new_player sequence
 * 990729 Jenna		Added "Tip of the Day" in logon_messages()
 * 000706 Jenna		Ditto for "wiztips"
 */

#include <ansi.h>
#include <board.h>

/*
 * Functions required just to make us responsive to external probes 
 * (i.e. looks like a player).
 */

nosave basic_startup() 
{
    /* shouldn't redo dependent stuff */
    if (myself) return 0;				

    myself = this_object();
    /* want to avoid keeping thousands of loaded (stat'd) players */
    call_out("check_superfluous", 300);		
    enable_commands();

    /* problems with init_actions(). let's see if this fixes it.
       Bel 24 Mar 2001 */
    init_parser();

    /* for `command'.  Belongs here. */
    set_this_player(myself);
    /* for internal hash table */
    set_living_name(lower_case(name));		

    init_actions();				
    return 1;					
}

/*
 * Player objects are created by (eg) fingering them; we want to clean these
 * out after some time - hence we have the following loop.
 *
 * This check should be kept quite distinct from in-game ones (including
 * the sleeper check); the only override is the definition of a hook that
 * will say `no, I'm really meant to be here' (eg for if zombies get
 * implemented).
 */

nosave int check_ip_at = 0;	/* warn before they're kicked off */

nosave check_superfluous() {
    call_out("check_superfluous", 300);		/* want to avoid keeping thousands of loaded (stat'd) players */
    /*
     * Give warnings if they are due to be logged off (access restrictions)
     */
    if (check_ip_at > 0 && query_ip_number(this_object())) {
	if (time() >= check_ip_at) {
	    (int|string) reason;
	    catch reason = "std/bar"->check_ip(query_ip_number(this_object()),
			name, wiz_level, 0);;
	    if (stringp(reason)) {
		write(reason + "\n");
		command("quit");
		return;
		}
	    else if (reason > 0)
		check_ip_at = time() + reason * 60;
	    else
		check_ip_at = 0;
	    }
	else {
	    int x = (check_ip_at - time()) / 300; /* x * 5 minutes */
	    if (x < 4)
	        tell_object(this_object(), "Access from your site closes in " + (x * 5 + 5) + " minutes.\n");
	    }
	}
    if (query_ip_number(this_object()))		/* if someone's playing with us, that's cool */
	return;
    if (query_su_level(this_object()) >= GOD)	/* a real player object; let sleeper check, etc, take care of it */
	return;
    if (this_object()->no_quit())		/* there's actually a reason for staying logged in... */
	return;
    flush_output(0);
    destruct(this_object());			/* otherwise, clean it up */
    }

/*
 * Things that may need reinitialisation due to the passage of time while
 * logged out, or to make sure they're working again after possible savefile
 * problems.  This should really just call the apropriate (inherited) functions.
 * Should be used here only, on login, to make sure stuff is fixed.
 */


nosave start_clean() 
{

    /* Random things to initialise. */
    soul = 0;
    set_light(1);

    /* kick off stats package */
    new_expire_time(0);		

    /* be sure the body is cool...  */

    /* no body description */
    if (!pointerp(body_locations)) 
    {		
        /* try to get one */
        if (stringp(race))			
            catch body_locations = "std/monsterer"->test(race);;

        /* if it worked, use it */
        if (pointerp(body_locations))		
        {
	    set_body(body_locations);
        }
        else
        {
        /* otherwise, default to a healthy human */
	    set_body(				
            	({ "head", "2s*", "chest", "4*", "abdomen", "4*",
		   "left arm", "2h", "right arm", "2h",
		   "left hand", "1h", "right hand", "1h",
		   "right leg", "3m", "left leg", "3m",
		   "left foot", "1m", "right foot", "1m" }) );
        }
	}


    /* These assume we've just been loaded, have no inventory, etc.  */

    local_weight = 0;
    base_armour = 0;
    name_of_weapon = 0;
    attacker_ob = 0;
    weapon_class = WEAPON_CLASS_OF_HANDS;

    /* Random little checks.  */
    if (query_invis(0) >= SOMEONE) cap_name = "Someone";
    else cap_name = capitalize(name);
}

nosave int done_load_initial = 0;

nosave load_initial_obs() 
{
    string eval;

    if (done_load_initial) return;

    done_load_initial = 1;
    eval = catch { load_auto_obj(auto_load); };
    if (eval)  // Jenna Mar 01
	LOG->log("AUTO_LOAD", "Error in " + file_name(this_object()) +
		"->load_auto_obj()! " + eval + "\n");

    if (inventory) call_out("restore_objects", 10);
}

/*
 * We just created a player object (by someone logging in).
 * Start him normally and log him in.  The time given should be
 * the time until he should be kicked off (0 or -ve: no check).
 */

restart_player(int howlong) 
{
    if (howlong > 0) check_ip_at = time() + howlong * 60 + 61;
    start_noninteractive();
    logon_messages();
    status_messages();
    start_location();
    init_actions();		/* for `command'.  Belongs here */
    log_enter("(ENTERS)");
    LOGIN_SERVER->notify_login(this_object());
    time_stamp = time();
#ifdef TRACK_ACTION
    track_action("SAVEFILE", "restore", "age="+query_age());
    track_action("LOGINS", "enter", "ip=" + query_ip_number(this_object()));
#endif
}

/*
 * For when you want a fully functional object, just avoiding
 * the usual logon message crap.  generally for player objects that
 * will be made god level real soon (or already have).
 */

nosave int done_start_nonint = 0;

start_noninteractive() 
{
    if (done_start_nonint) return;

    done_start_nonint = 1;
    start_virtual();
    restore_souls();
    load_initial_obs();
    if (!query_wiz())
        catch "std/peerage"->update_lord_station(name);;
    start_call_outs();
    return 0;
}

/*
 * For a probable object - behaves like a living for stat(), etc, but
 * doesn't age, doesn't have souls.  Called by the player creation object.
 * Nothing here relies on levels or savefiles - most players are probably
 * created through stat(), anyway.  Will schedule its own destruction.
 */

nosave int done_probeable = 0;

start_virtual() 
{
    if (done_probeable) return;

    done_probeable = 1;
    basic_startup();
    start_clean();
    return 0;
}

/*
 * Reconnection after link death (or after it was loaded by a god to
 * do battle in the arena while the player was away).
 */

reconnected() 
{
    if (caller()) if (query_su_level(caller()) < GOD) return 0;
    if (!query_ip_number(this_object())) return 0;
    if (!environment(this_object())) return restart_player();

    /* should already be living, etc */
    clean_connects();
    myself->log_enter("(switched)");
#ifdef TRACK_ACTION
    track_action("LOGINS", "reconnect", "ip="+query_ip_number(this_object()));
#endif
    command("glance");
    if (!query_invis())
        tell_room(environment(myself), cap_name 
	+ " returns from the horror of link death!\n"); 
    status_messages();
    tell_object(myself, "*** You can review what happened while you "
	+"were away with 'what-happened'\n");
    LOGIN_SERVER->notify_reconnect(this_object());
    return 1;
}



/*
 * This should happen just as we are about to be injected into the game (when
 * we are a fully configured object).
 */

nosave status_messages() 
{
    write("\n");
    catch "room/city/post"->query_mail();;
    if (query_invis())	write("Invisibility level: " + query_invis() + "\n");
    if (muffled)	write("Earmuffs are on.\n");
    if (brief)		write("You are in brief mode.\n\n");
    if (ghost)		write("*** You are a ghost ***\n");
    if (query_pow() < 3 && !query_wiz())
			write("*** Your life force is running out ***\n");
    if (query_wiz()) {
	array files = ({ });
	if (file_size("log/"+name) >= 0)
	    files = ({ "LOG" });
	if (file_size("log/"+name+".err") >= 0)
	    files += ({ ".ERR" });
	if (file_size("log/"+name+".rep") >= 0)
	    files += ({ ".REP" });
	if (sizeof(files) > 0)
	    write("\n*** You have log files: " + implode(files, ", ") + " ***\n");
	set_action("parry", 1);
	set_reaction("parry", 1);
	}
	catch PEERAGE_SERV -> update_lord_station (name,0);;
}

nosave logon_messages() 
{
    object bbs;

    if (wiz_level > 0)
    {
	OUTPUT_FILE->cat("WIZNEWS");
	bbs = load_object(BOARD_SERV + "/wiztips");
    }
    else
    { 
	OUTPUT_FILE->cat("NEWS");
	bbs = load_object(BOARD_SERV + "/tips");
    }
    if (bbs)
    {
	catch 
	{
	    int x = random(bbs->number_of_notes());
	    write("-----------------------------Tip of the " +
	    "Day-----------------------------\nTip #" +
	    bbs->show_note(x,1) + "------------------------"+
	    "-------------------------------------------------\n");
	};
    }

    if (called_from_ip && query_ip_number() != called_from_ip)
	write("Your last login was from " + called_from_ip + "\n");
    called_from_ip = query_ip_number();
}

/*
 * If we're not already in an environment, move us to our starting home.
 */
nosave start_location() 
{
    object start_loc;
    array locs = [ "room/city/inn", "room/vill/inn", 
	"players/dodinas/villages/room/deall/innupper" ];
    string fail;

    if (environment(this_object()) || !myself) return;

    if (home) 
    {           /* Check that it will load */
        start_loc = load_object(home);
        if (objectp(start_loc))
        {
	    if (start_loc->authorised(myself) ||
		index(locs, home) != -1)
	    {
                fail = catch move_object(myself, start_loc);;
		if (fail)
		    fail = "Error in moving to "+
			start_loc->query_short_desc();
	    }
            else
                fail = "You are not allowed to start the game "+
                        "in "+start_loc->query_short_desc();
        }
        else
            fail = "Unable to load \""+home+"\"";
        if (stringp(fail))
	{
	    tell_object(myself, "!\n! Failed to move you to your starting "
		+"location!\n! "+fail+".\n!\n");
	}
    }
    else
    {
	fail = "You have no starting location set";
    }	   
    if (!home || stringp(fail)) 
    {
	/* 5 days before you start logging in in more random places */
    int x = random((query_age()/(3600 * 24 * 5))+1);
	x = x % sizeof(locs);
	start_loc = load_object(locs[x]);
	if (!start_loc) 
 	{
	    write("Looks like we're having internal problems finding a "
		+"starting location for your character; still trying.\n");
	    for (x = 0; x < sizeof(locs); x++) 
	    {
		start_loc = load_object(locs[x]);
		if (start_loc)
		    break;
	    }
	    if (!start_loc) 
	    {
		write("Can't find anywhere to start you!\nSorry...\n");
		flush_output();
	/* don't modify their savefile if we cant put them in the game */
		destruct(this_object()); 
 	    }
	}
    }
    move_object(this_object(), start_loc);
    command("glance");
    checked_say(query_name() + " enters the game.\n");
}

/*
 * Cleanups for things that get broken when you disconnect.
 * Will change as the socket interface changes.
 */

nosave clean_connects() {
    while (query_caution())
	pop_caution();
#if 0
/* These suck.  Should really have an `activity'... */
    while (query_caution() == "using vi" ||
	   query_caution() == "editing" ||
	   query_caution() == "more-ing" ||
	   query_caution() == "viewing files" ||
	   query_caution() == "reading notes" )
		pop_caution();
#endif
    }

/*
 *	Note: No stuff should be added in here anymore;
 *	Find the appropriate soul and add it there!
 *
 * This is now nosave.
 */

nosave init_actions() 
{
/*
 * This first line is to ensure that the commands are added to this object,
 * rather than to the login object.
 */
    enable_commands();

    add_action("echo_string", "echotome"); /* kludge for vi */
    add_action("terminal", "terminal"); /* should be in wiz_soul? */
    add_action("toggle_monitor","monitor");

/* Support for second chars - if we allow them, why not actually
 * support them (same philosophy as aliases).  "commander <playername>"
 * lets a player force you, but you have to go link dead for it to
 * work.  This way, they log in (and thus provide their passwd),
 * link die, and the commander gets all their output; he can
 * control them with "<playername> cmd".  When the executor is together,
 * we'll add some autonomous functions to it.
 * Gandalf.
 */
    add_action("set_commander", "commander?", 4);	/* the ? is optional (for queries) */
    add_action("show_commanded", "commanded");

/* supa-spiffy link-death buffer retaining - G :) */
    add_action("review_catch_buf", "what-happened", 4);

    add_action("cmdquit", "quit");
    add_action("save_character","save");
    add_action("change_password", "password");
    add_action("ear_muffs", "earmuffs", 3);

    add_action("set_action", "action", 3);
    add_action("set_reaction", "reaction", 3);
    add_action("describe","describe",3);
    add_action("toggle_brief","brief",3);
    if (query_wiz()) {
      add_action("soul","soul",0);
      /* add_action("switch_player","switchto"); */
      }
}

/*
 * For a one-shot character.
 */

start_one_shot(myname) {
    if (query_su_level(this_object()) < GOD) {
		/* too many hassles at the moment */
	return 0;
    }
    if (query_su_level(caller()) < GOD)
	return 0;
    if (myself)
	return 0;
	start_new_player(myname, 0, 1);
	return 1;
	}

/*
 * When creating a new player from scratch.
 * Give it the unencrypted password.
 */

int really_guest;

start_new_player(myname, passwd, is_g) 
{
    if (query_su_level(this_object()) < GOD) {
		/* too many hassles at the moment */
	return 0;
    }
    if (query_su_level(caller()) < GOD) return 0;
    if (myself) return 0;

    name = myname;
    really_guest = is_g;

    if (passwd) set_password(passwd);

    creation_time = time();
    time_stamp = time();
    level = 1;
	/* make sure they don't have a savefile if they exit prematurely */
    is_guest = 1;	

    basic_startup();
    start_clean();
    restore_souls();
    logon_messages();

#ifdef TRACK_ACTION
    track_action("LOGINS", "new-char", "ip="+query_ip_number(this_object()));
#endif

    /* Jenna's hilite check */
    string s = "\nColour check: are these words "+
                ANSI->scolor(GREEN, "green") + " and " +
                ANSI->scolor(YELLOW, "yellow") + "?\n[Enter \"y\" or \"n\"]: ";
    tell_object(myself, s);
    input_to("start_new_player2");
    }

start_new_player2(str) {
    string lstr = str + "  ";

    tell_object(myself, "\n");
    if (lstr[0] == 'y' || lstr[0] == 'Y')
            command("hilite on", myself);
    else
            tell_object(myself, "Ok.\n");

/*
 * Moved from ~dredd to RO/new_player as a general fix for creation cheating.
 * Also a chance to test out the capability stuff.
 */
    (int|object) o = find_object("P/new/"+name);
    if (o) {
	rename_object(o, "P/new/"+name+"/#"+random(50000));
	destruct(o);
	}

    string lname = name + "     ";

    o = clone_object("players/jenna/guide/new_player");	
    this_object()->add_store("new_entry",1);
    set_uid_me(o, 22, "dredd");
    rename_object(o, "P/new/"+name);
    int x = random(10000);
    o->start_new(make_cap("new_player:"+x, 1), "new_player:"+x, this_object());
    log_enter("(NEW)");
    LOGIN_SERVER->notify_start(this_object());
    return 1;
}

/* curtesy function */
new_player_done()
{
    LOGIN_SERVER->notify_login(this_object());
    /* restart call outs - where is that done? */
    start_call_outs();
    command("glance");
    checked_say(query_name() + " begins the game.\n");
}

/* This is called back from the new player object */

int newplayer_abort(cap, cn) {	/* called if they quit the new player sequence */
    if (!auth_user(cn, cap)) {
	return 0;
	}
    is_guest = 1;		/* force no save on savefile */
    }

/*
 * Set up stats.  We gave the newplayer stuff a capability
 * to set the stats on this object (cuts the logs down :)
 * If it's properly authenticated here, we're laughing.
 */

int set_newplayer_stats(cap, cn, ra, stn, stv, skn, skv) {
    if (!auth_user(cn, cap)) {
	LOG->log("STATS", "Unauthenticated attempt to set stats from " + file_name(caller()) + "\n");
	catch tell_object(find_player("gandalf"),
		"Unauthenticated attempt to set stats from " + file_name(caller()) + "\n");;
	return 0;
	}
    int x, y, z, w;
    for (x=0; x < sizeof(stn); x++) 
    {
    if (stv[x] < 3) stv[x] = 3; /* safety hack */
	y = random(stv[x] / 2);
	if (y >= stv[x])
	    y = 0;	/* be careful to avoid stat death */
	add_stat(stn[x], stv[x], 0, 0, 0, 0);
	z = 0;
#if 0
/* Ok, I've turned this off for a while - seems to be less point now
 * that we have guest chars.
 */
	while (y > 0) {
	    w = random(y) + 1;
	    add_stat(stn[x], -w, random(7200) + 1200, 0, "You feel yourself settling into your new body a little.");
	    y -= w;
	    }
#endif
	}
    for (x=0; x < sizeof(skn); x++) {
	add_skill(skn[x], skv[x], 0, 0, 0, 0);
#if 0
/* And again. */
	y = random(skv[x] / 3);
	add_skill(skn[x], -y, random(7200) + 1200, 0, "You feel your skills normalise a little");
#endif
	}
    internal_set_race(ra);
    set_body("std/monsterer" -> test(race));
    soul ("on", "silent"); /* Give them the new race soul */
    return 1;
}

log_enter(reason) 
{
string ws;
    if (!reason) reason = "(none)";
    if (query_wiz()) ws = "WL"+wiz_level;
    else ws = "PQ"+quests_completed()+":"+query_pow()+query_str()+query_con()+query_int()+query_dex();
    LOG->log("ENTER", query_host_name()[..4] + " " + capitalize(name) + " " + ws + " @ " + query_ip_number() + " " +
 reason + ".\n");
#ifdef TRACK_ACTION
    track_action("LOGINS-2", reason,
	"ip="+query_ip_number(this_object()) + "; age=" + query_age());
#endif
}

