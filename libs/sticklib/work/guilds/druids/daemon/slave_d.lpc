/*
 * SLAVE DAEMON (Couldn't invite a better name :)
 * written by Chopin 6/7/97
 *
 * This daemon keeps log of "slaves" a player has, and moves them
 * with him.
 */


#include "../global.h"
#include <daemons.h>
#include <room_defs.h>

#define F_FOLLOW 1
#define F_NO_MESSAGES 2

mapping slaves;
mapping temp_data; // used when player goes ld
// ([ player: had_follow_hook; ({ slave1, room, follow_data, ...}), ... ])

void create() {
    slaves = ([]);

    // If it's multidimensional mapping, make it be one!!!! -+ Doomdark +-
    //temp_data = allocate_mapping(0, 2);
    temp_data = ([]);
}

status add_slave(object player, object ob) {
    mixed t;

    if (!player || !ob) return 0;

    if (!(t = slaves[player])) {
	slaves[player] = ([ ob : 0 ]); // default follow off
    } else {
	t -= ([ 0 ]);
	t += ([ ob : 0 ]);
    }

    return 1;
}

status remove_slave(object player, object ob) {
    mixed t;

    if (!(t = slaves[player])) {
	return 0;
    }

    t -= ([ ob, 0 ]);

    if (!sizeof(t)) {
	m_delete(slaves, player);

	PARTY_D->remove_move_hook(player, this_object());
    }

    return 1;
}

// used, when player quits:
void remove_all_slaves(object player) {
    mixed t;
    int i;
    object *objs;

    m_delete(temp_data, player);

    if (!(t = slaves[player])) {
	return;
    }

    objs = m_indices(t);

    foreach (object ob : objs) {
	if(!environment(ob)->query(ROOM_ISOLATED)) {
	    ob->transfer_all_to(GUILD_ROOM_DIR + "temp_storage");
	    ob->vanish();
	}
    }

    m_delete(slaves, player);

    PARTY_D->remove_move_hook(player, this_object());
}


void go_ld(object player) {
    mixed t, *data;
    int i;
    object *objs;
    status had_follow_hook;

    if (!(t = slaves[player])) {
	return;
    }

    had_follow_hook = PARTY_D->query_move_hook(player, this_object());

    PARTY_D->remove_move_hook(player, this_object());

    objs = m_indices(t);

    data = ({});

    foreach (object ob : objs) {
	data += ({ ob, object_name(environment(ob)) });
	ob->move_player("X", GUILD_ROOM_DIR + "oblivion");
    }

    temp_data += ([ player : had_follow_hook; data]);
}


void recover_from_ld(object player) {
    mixed data, t;
    int i,n;
    object room, ob;
    string room_name;

    if (!(t = slaves[player])) {
	return;
    }

    if (temp_data[player, 0]) {
	PARTY_D->add_move_hook(player, this_object());
    }

    data = temp_data[player, 1];

    for (i = 0, n = sizeof(data); i < n;) {
	ob = data[i++];

	if (!ob) {
	    i += 2;
	    continue;
	}

	room_name = data[i++];
	room_name->query_short(); // no unnecessary cache flushes

	if (room = find_object(room_name)) {
	    ob->move_player("X", room);
	} else {
	    // the room has become bugged or something
	    ob->transfer_all_to(GUILD_ROOM_DIR + "temp_storage");
	    ob->vanish();
	}
    }
}

object *query_slaves(object player) {
    mixed t;

    if (!(t = slaves[player])) {
	return 0;
    }

    return m_indices(t);
}

mapping query_data() {
    return slaves;
}

// remember to mask bit 2, if you only want to know if a monster is
// following a player.
int query_follow(object player, object ob) {
    mixed t;

    if (!(t = slaves[player])) {
	return 0;
    }

    return t[ob];
}

/* SPECIAL: follow_data
 * bit 1 - are we following?
 * bit 2 - shall we leave moving messages, ie. use standard move_player?
 */
status set_follow(object player, object ob, int follow_data) {
    status had_follow_hook;
    int *tmp;
    mixed t;

    if (!(t = slaves[player])) {
	return 0;
    }

    t[ob] = follow_data;

    tmp = m_values(t);

    had_follow_hook = PARTY_D->query_move_hook(player, this_object());

    if (member(tmp, 1) == -1 && member(tmp, 3) == -1) {
	if (had_follow_hook) {
	    PARTY_D->remove_move_hook(player, this_object());
	}
    } else {
	if (!had_follow_hook) {
	    PARTY_D->add_move_hook(player, this_object());
	}
    }

    return 1;
}


void player_moved(object player, string verb, string arg, object room) {
    mixed t;
    int follow_data;

    t = slaves[player];

    if (!t || !mappingp(t)) {
	m_delete(slaves, player);

	PARTY_D->remove_move_hook(player, this_object());
	return;
    }

    foreach (object slave, mixed data : t) {
	if (!((follow_data = data) & F_FOLLOW)) {
	    continue;
	}

	if (room != environment(slave)) {
	    continue;
	}

	if (follow_data & F_NO_MESSAGES) {
	    // let's inform only the player
	    player->tell_me(sprintf("%s enters, following you.",
		capitalize(slave->query_real_name())));

	    if (slave && environment(player)) {
		move_object(slave, environment(player));
	    }
	} else {
	    slave->move_player(sprintf("following %s master",
		slave->Possessive()), environment(player));
	}
    }
}

void debug() {
    printf("Slaves: %O\n\nLinkdeads' slaves: %O\n", slaves, temp_data);
}

void save_data() {
    save_object(GUILD_SAVE_DIR + "slave_d");
}
