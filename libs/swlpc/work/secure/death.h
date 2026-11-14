#if 0
/* in living */
set_death_hook(ob, fn) {
	if (!ob) {
		death_hook = 0;
		return;
	}
	if (!fn) fn = "death";
	death_hook = ({ ob, fn });
	return 1;
}
#endif

nosave suicide() 
{
	write("You decide you've had enough and kill yourself!\n");
	say(cap_name + " ruthlessly commits suicide.\n");
	death();
	return 1;
}

ultimate_death() 
{
string fn; string nm;
	if (query_pow() > 0) return;
	if (query_wiz() > 0) return; 
	if (query_su_level(this_object()) < GOD)
	    return "Need to be able to save";
	if (name == "guest") return;	/* tee hee */
	nm = this_object()->query_real_name();
catch tell_object(find_player("gandalf"), "UDEATH: "+nm+"\n");;
	"std/banish"->add(nm, - (time() + query_age()) );
#ifdef TRACK_ACTION
	track_action("LOGINS", "ultimate-death", "age="+query_age());
#endif
	time_stamp = 0;
	check_final_purge();
	return 1;
}

/*
 * remove a savefile from the game, and clean up associated
 * in-game stuff - not necessarily through death.
 */

check_final_purge() {
	if (query_su_level(caller()) < GOD)
		return;
	if (query_su_level(this_object()) < GOD)
	    return;
	if (time_stamp + (90*24*3600) >= time()) /* 90 days */
		return;

	string nm = this_object()->query_real_name();
	catch tell_object(find_player("gandalf"), "PURGING: "+nm+"\n");;

	if (file_size(PLAYER_SERV->GetPlayerSavefile(nm, this_object())
										+ ".o.bak")>=0) 
		rm(PLAYER_SERV->GetPlayerSavefile(nm, this_object()) + ".o.bak");
	catch "std/remove_player"->remove_player(nm);;
	if (query_wiz()) {
	if (time_stamp + (180*24*3600) >= time()) /* 180 days */
		return;
		if (file_size ("P/players/Inactive/"+nm+".o") >=0)
			rename("P/players/Inactive/"+nm+".o",
					"P/players/Inactive/"+nm+".o.bak");
		rename(PLAYER_SERV->GetPlayerSavefile(nm, this_object()) + ".o",
					"P/players/Inactive/"+nm+".o");

		destruct(this_object());
		return 0;
		}
	if (file_size ("old_players/"+nm+".o") >=0)
		rename("old_players/"+nm+".o", "old_players/"+nm+".o.bak");
	rename(PLAYER_SERV->GetPlayerSavefile(nm, this_object()) + ".o", "old_players/"+nm+".o");
	destruct(this_object());
	}

second_life() {
    make_scar();
    	/* This is to stop the infinite loop that was introduced because
    				of death from zero stats. */
    if (!(this_player() -> query_stat ("san"))) add_san(-random(5));
    /* make_ghost(); Not needed. This is already done in death() */
    stuffed = query_siz() * 3 / 2;
    /*if (weakness) add_str(weakness);*/
    disable = ({ });
    if (query_hp() < 0) add_hp(-query_hp() + 1);
    weakness = 0;
    headache = 0;
    intoxicated = 0;
    string attacker_name = "unknown";
    if (attacker_ob)
	catch attacker_name = attacker_ob->query_real_name();;
    EVENT_NOTIFY->event_notify(name, "DEATH", attacker_name);
#ifdef TRACK_ACTION
    track_action("HEALTH", "death", "killer="+attacker_name);
#endif
    if ( attacker_ob && !(attacker_ob->query_npc()))
        EVENT_NOTIFY->event_notify(attacker_name, "KILLED", name);
    attacker_ob = 0;
    save_me();
    if (query_pow() <= 0) {
		"room/death/death"->death(this_object());
	}
    else {
    tell_object(myself, "\nYou die.\nYou have a strange feeling.\n" +
		"You can see your own dead body from above.\n\n");
    }
    return 1;
}

remove_ghost() 
{
    if (!ghost) return 0;
    tell_object(this_object(),"You feel a very strong force.\n");
    tell_object(this_object(),"You are sucked away...\n");
    tell_object(this_object(),"You reappear in a more solid form.\n");
    say("Some mist disappears.\n");
    say(cap_name + " appears in a solid form.\n");
    ghost = 0;
    set_light(-1);
    msgin = "arrives";
    msgout = "leaves";
    /* Get us to the appropriate level for our experience */
    soul("on",1);
#ifdef TRACK_ACTION
    track_action("HEALTH", "regenerate", "hp="+query_hp());
#endif
    return 1;
}

/*
 * This is really a brutal hack to prevent wizzes from fucking up with stats.
 */
#if 0
/* moved to RO/living and modified - Jenna April 2000 */
stat_zero(x) {
    if (ghost) return 0;
    if (stringp(x))
	stat_death(x);
    else if (arrayp(x)) {
	stat_death(x[0]);
	}
    }

stat_death(ty) {
    int x;
    while (-1 != (x = find_call_out("stat_death")))
	remove_call_out("stat_death");
    if (ty == "str") tell_object(this_object(), "Your strength is reduced to nothing.\nYou cannot breathe, and your heart is too weak to pump blood!\n");
    else if (ty == "con") tell_object(this_object(), "Your constitution is totally drained.\nYour internal organs pack it in!\n");
    else if (ty == "int") tell_object(this_object(), "Your intelligence is destroyed.\nYour brain falls apart.\n");
    else if (ty == "wis") tell_object(this_object(), "Your instincts have deserted you.\nYour autonomic nervous system fails\n");
    else if (ty == "chu") tell_object(this_object(), "You have no chutzpah!  You die of embarrasement...\n");
    else if (ty == "san") tell_object(this_object(), "Your sanity leaves you totally!  Your mind floats free...\n");
    else if (ty == "dex") tell_object(this_object(), "Your dexterity is reduced to nothing!  You trip and split your skull open.\n");
    else if (ty == "siz") tell_object(this_object(), "Your body has shrunk to nothing!  You leave this plane for another.\n");
    else tell_object(this_object(), "Your " + ty + " is reduced to 0!\n");
    add_stat(ty, 1-query_stat(ty));
    this_object()->death();
    }
#endif

