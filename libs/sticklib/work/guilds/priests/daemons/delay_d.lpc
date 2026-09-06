// DELAY DAEMON

mapping delays, frozen;

create() {
    delays = ([ ]);
    frozen = ([ ]);
}


void set_delay(object pl, int delay_type, int delay) {
    mapping t;

    if(!pl) return;
    if(!(t = delays[pl->query_real_name()]))
	delays[pl->query_real_name()] = ([ delay_type: time(); delay ]);
    else {
	t[delay_type,0] = time();
	t[delay_type,1] = delay;
    }
}

void add_delay(object pl, int delay_type, int delay) {
    mapping t;

    if(!pl) return;
    if(!(t = delays[pl->query_real_name()]))
	delays[pl->query_real_name()] = ([ delay_type: time(); delay ]);
    else {
	if(!member(t, delay_type))
	    t += ([ delay_type : time() ; delay ]);
	else 
	    t[delay_type,0] += delay;
    }
}


// QUERY_DELAY
// returns the amount of times "delay" seconds has passed since last query.
// return value -1 means, that not enough time has passed yet, and
// value 0 means, that delay_type didn't exist

int
query_delay(object pl, int delay_type) {
    mapping t;
    int time_passed, delay;

    if(!pl) return 0;
    delays -= ([0]);
    if(member(frozen, pl->query_real_name()))
	return -1;
    if(!(t = delays[pl->query_real_name()]))
	return 0;

    if(!member(t, delay_type))
	return 0;

    time_passed = time() - t[delay_type,0];
    delay = t[delay_type,1];
    if(time_passed<delay) 
	return -1;

    t[delay_type,0] = time() - time_passed % delay;
    return time_passed / delay;
}


// Called when player quits or goes ld
void freeze_delays(object pl) {
    if(!pl) return;
    frozen[pl->query_real_name()] = time();
}


void correct_time(int delay_type, int time, int delay, int delta) {
    time += delta;
}

// Called when player recovers from ld or logs back in
void unfreeze_delays(object pl) {
    mapping t;
    string name;

    if(!pl) return;
    name = pl->query_real_name();
    if(!member(frozen, name)) return;
    if(delays[name])
	walk_mapping(delays[name], #'correct_time, time() - frozen[name]);
    m_delete(frozen, name);
}


void
remove_delays(object pl) {
    delays -= ([ pl->query_real_name() ]);
}


void
debug () {
    printf("%O\n\n%O\n", delays, frozen);
}
