/*
    flag.c - flag support, give and take flags
    Sep 1991 by marion@cs.tu-berlin.de
*/

// Carador, 08-Feb-1994
#define DATABASE       "/save/flag_use"		/* MUST start with '/' */
#define WIZINFO        "/open/flag_use"		/* MUST start with '/' */
#define MAX_FLAG_VALUE 400
#define LOCATION       "/room/adv_lpc"

// added by Carador, 08-Feb-1994
#include <kernel.h>
inherit ACCESS;

string used_flags;

reset (arg) {
    if (!arg) {
	used_flags = 0;
	load_flags (DATABASE);
    }
}

who_calls () {
    string who;

    load_flags (DATABASE);
    if (!this_player() ||
	(this_player()->query_level() < 21 && creator (previous_object ()))) {
	who = creator (previous_object());
    } else {
	if (this_player()->query_level() < 21) who = "god";
	who = this_player()->query_real_name();
    }
    return who;
}

alloc_flags (num, why) {
    string who, new;
    int i;

    if (num < 1 || !why || !(who = who_calls())) return;
    if (used_flags) for (i = 0; i < sizeof (used_flags) - 1 && !new; i++) {
	if (used_flags[i+1][0] - used_flags[i][1] > num) {
	    used_flags = slice_array (used_flags, 0, i)
		+ ({({ used_flags[i][1]+1, used_flags[i][1]+num, who, why })})
		+ slice_array (used_flags, i+1, sizeof (used_flags)-1);
	    new = ({ used_flags[i][1]+1, used_flags[i][1]+num });
	}
    }

    if (!new) {
	if (used_flags && sizeof (used_flags)) {
	    if (used_flags[i][1] + num >= MAX_FLAG_VALUE) return;
	    used_flags +=
		({({ used_flags[i][1]+1, used_flags[i][1]+num, who, why })});
	    new = ({ used_flags[i][1]+1, used_flags[i][1]+num });
	} else {
	    used_flags = ({({ 0, num-1, who, why })});
	    new = ({ 0, num-1 });
	}
    }

    if (!save_flags (DATABASE)) {
	load_flags (DATABASE);
	return;
    } else {
	write_info (WIZINFO);
    }
    return new;
}

free_flags (start, end) {
    string who;
    int i;

    if (!(who = who_calls())) return;
    if (!used_flags) return;
    if (!end) end = start;
    for (i = 0; i < sizeof (used_flags) && start <= end; i++) {
	if (used_flags[i][0] <= start && used_flags[i][1] >= start
	    && who == used_flags[i][2]) {
	    if (used_flags[i][0] == start) {
		if (used_flags[i][1] <= end) {
		    start = used_flags[i][1]+1;
		    used_flags = slice_array (used_flags, 0, i-1)
			+ slice_array (used_flags, i+1, sizeof (used_flags)-1);
		} else {
		    start = used_flags[i][0] = end + 1;
		}
	    } else {
		if (used_flags[i][1] <= end) {
		    int tmp;

		    tmp = used_flags[i][1];
		    used_flags[i][1] = start-1;
		    start = tmp+1;
		} else {
		    used_flags = slice_array (used_flags, 0, i)
			+ slice_array (used_flags, i, sizeof (used_flags)-1);
		    /* copy reference to make new instance */
		    used_flags[i] = slice_array (used_flags[i], 0, 3);
		    used_flags[i][1] = start-1;
		    start = used_flags[++i][0] = end+1;
		}
	    }
	}
    }

    if (start <= end || !save_flags (DATABASE)) {
	load_flags (DATABASE);
	return;
    } else {
	write_info (WIZINFO);
    }
    return 1;
}

pad (str, n) {
    if (strlen (str) < n) {
	return str + extract ("                                        ",
	    0, n - strlen (str) - 1);
    } else return str;
}

/* write_info - write info to file 'to' */
write_info (to) {
    int i;

    rm (to);
    write_file (to,
"\
THIS FILE IS WRITTEN BY THE FLAG DISPENSER, IF YOU CHANGE ANYTHING, IT'S LOST\n\
SOON. PLEASE USE THE FLAG DISPENSER AT '" + LOCATION + "'.\n\
\n\
This list shows all legally allocated flag values and their owner.\n\
\n\
RANGE	WHOM                USE\n"
    );
    for (i = 0; i < sizeof (used_flags); i++) {
	if (used_flags[i][0] < used_flags[i][1]) {
	    write_file (to,
used_flags[i][0] + "-" + used_flags[i][1] + "\t"
+ pad (capitalize (used_flags[i][2]), 20)
+ used_flags[i][3] + "\n"
	    );
	} else {
	    write_file (to,
used_flags[i][0] + "\t" + pad (capitalize (used_flags[i][2]), 20)
+ used_flags[i][3] + "\n"
	    );
	}
    }
}

load_flags (from) {
// Carador, 08-Feb-1994
    if (unguarded(1,#'file_size,from+".o") < 0) return;
    return unguarded(1,#'restore_object, from);
}

save_flags (to) {
// Carador, 08-Feb-1994
    unguarded(1,#'save_object,to);
    return (unguarded(1, #'file_size, to+".o"));
}

