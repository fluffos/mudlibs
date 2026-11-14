/*
 * Guest logins don't save, and don't do irritating things
 * like randomly flee, etc.
 */

autoheal() {
    if (headache) {
	headache -= 1;
	if (headache == 0)
	    tell_object(myself, "You no longer have a head ache.\n");
    }
    if (hit_point < max_hp() || sp < max_sp()) {
	if (intoxicated) heal_self(5);
	else heal_self(1);
    }
    if (intoxicated) {
	if ((intoxicated -= 1) == 0) {
	    headache = max_headache;
	    max_headache = 0;
	    tell_object(myself,
	       "You suddenly without reason get a bad head ache.\n");
	    if ((hit_point -= 3) < 0)
		hit_point = 0;
	}
    }
    call_out("autoheal", INTERVAL_BETWEEN_HEALING);
}

#define MIN_STUFFED (-3) /* 25 mins or so */

show_hunger() {
	if (stuffed <= 0) {
		 tell_object(myself, 
			"You are starving with hunger! You feel weaker.\n");
		 damage("hunger", -3*(stuffed-1));
		 weakness = query_str()/5+1;
		 if (stuffed <= MIN_STUFFED) {
		     tell_object(myself, "Your health is damaged! You need food badly!\n");
		     add_stat("con", -1, 890, 0, "You feel your constitution is restored somewhat.");
		     }
	}
	else if (stuffed <= query_siz() / 3)  {
		tell_object(myself, "You are very hungry.\n");
		damage("hunger", 1);
	}
	else if (stuffed < query_siz() * 2 / 3)
		tell_object(myself, "You are quite hungry.\n");
	else if (stuffed > query_siz() * 3 / 2 )
		tell_object(myself, "You are comfortably full.\n");
	else if (stuffed > query_siz() * 2) 
		tell_object(myself, "You are really stuffed full of food!\n");
    return 1;
}

hunger() {
	if ((!query_guest()) && (!ghost) && query_ip_number(this_player())) {
	    stuffed--;	
	    if (stuffed < MIN_STUFFED) stuffed = MIN_STUFFED;
	    show_hunger();
	}
	if (!query_wiz()) call_out("hunger", INTERVAL_BETWEEN_FOOD);
}

query_weakness() { return weakness; }

intoxicate() {
    int n;

    if (!intoxicated)
        return;
    n = random(7);
    if (n == 0) {
	checked_say(cap_name + " hiccups.\n");
	write("You hiccup.\n");
    } else if (n == 1) {
	checked_say(cap_name + " seems to fall, but takes a step and recovers.\n");
	write("You stumble.\n");
    } else if (n == 3) {
	write("You feel drunk.\n");
	checked_say(cap_name + " looks drunk.\n");
    } else if (n == 5) {
	checked_say(cap_name + " burps.\n");
	write("You burp.\n");
    }
    call_out("intoxicate", 5 + random(56));
}

add_intoxication(i) {
    intoxicated += i;
    if (intoxicated < 0) {
	intoxicated = 0;
	remove_call_out("intoxicate");
	return;
    }
    if (intoxicated && find_call_out("intoxicate") == -1)
        call_out("intoxicate", 5 + random(56));
}

query_intoxication() { return intoxicated; }
query_percent_intoxication() { return 100 * intoxicated / (query_con() + 3); }
query_food() { return stuffed; }
drink_alcohol(strength) {
    if (intoxicated > query_con() + 3 && strength > 0) {
        write("You fail to reach the drink with your mouth.\n");
	return 0;   /* He's too drunk to drink any more! */
    }
    add_intoxication(strength);
    if (intoxicated == 0)
	write("You are completely sober.\n");
    if (intoxicated > 0 && headache) {
	headache = 0;
	tell_object(myself, "Your head ache disappears.\n");
    }
    if (intoxicated > max_headache)
	max_headache = intoxicated;
    if (max_headache > 8)
	max_headache = 8;
    return 1;
}

query_headache () { return headache; }
query_max_headache () { return max_headache; }

/* quiet = 0   - display messages
 * quiet = 1   - no messages
 * quiet = -1  - hungry messages only (no "stuffed full of food")
 *  Jenna June 2000
 */
eat_food(int amount, int quiet)
{
	string msg;

        if (stuffed > query_siz() * 3  && amount > 0) 
	{
	    if (!quiet)
	        tell_object(this_object(),"You can't fit another bite in!\n");
            return 0;
        }
        stuffed += amount;
        if (stuffed < 1)
                msg = "You are starving!!\n";
        else if (stuffed <= query_siz() / 3)
                msg = "You are very hungry.\n";
        else if (stuffed < query_siz() * 2 / 3)
                msg = "You are quite hungry.\n";
	else if (!quiet)
	{
            if (stuffed > query_siz() * 2)
                msg = "You are really stuffed full of food!\n";
            else if (stuffed > query_siz() * 3 / 2 )
                msg = "You are comfortably full.\n";
	}

	if (msg && quiet < 1)
	    tell_object(this_object(), msg);

        if (stuffed > query_siz()) {
                if (weakness) {
		     if (!quiet)
                        tell_object(this_object(), "You feel much better and stronger.\n");
                     /*add_str(weakness);*/
                     weakness = 0;
                }
        }
    return 1;
}

set_headache(arg){
	headache = arg;
	return 1;
}

set_max_headache(arg){
	max_headache = arg;
	return 1;
}

set_intoxication(arg){
	intoxicated = arg;
	return 1;
}
