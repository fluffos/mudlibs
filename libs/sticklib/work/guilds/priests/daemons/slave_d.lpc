/*
 * SLAVE DAEMON (Couldn't invite a better name :)
 * written by Chopin 6/7/97
 *
 * This daemon keeps log of "slaves" a player has, and moves them
 * with him.
 */
#include "../priest.h"
#include <daemons.h>
#include <room_defs.h>

#define F_FOLLOW 1
#define F_NO_MESSAGES 2

mapping slaves;
mapping temp_data; // used when player goes ld
// ([ pl: had_follow_hook; ({ slave1, room, follow_data, ...}), ... ])

create() {
    slaves = ([]);
    // If it's multidimensional mapping, make it be one!!!! -+ Doomdark +-
    temp_data = allocate_mapping(0, 2);
}

status
add_slave(object pl, object ob) {
    mixed t;

    if(!pl || !ob) return 0;
    if(!(t = slaves[pl]))
	slaves[pl] = ([ ob : 0 ]); // default follow off
    else {
	t -= ([ 0 ]);
	t += ([ ob : 0 ]);
    }
    return 1;
}

status
remove_slave(object pl, object ob) {
    mixed t;

    if(!(t = slaves[pl])) return 0;
    t -= ([ ob, 0 ]);
    if(!sizeof(t)) {
	slaves -= ([ pl ]);
	PARTY_D->remove_move_hook(pl, this_object());
    }
    return 1;
}

// used, when player quits:
void
remove_all_slaves(object pl) {
    mixed t;
    int i;
    object *objs, ob;

    m_delete(temp_data, pl);

    if(!(t = slaves[pl])) return;
    objs = m_indices(t);
    for(i=sizeof(objs); --i>=0;) {
	ob = objs[i];
	if(ob) {
	    if(!environment(ob)->query(ROOM_ISOLATED))
		ob->transfer_all_to(PRIEST_ROOM_DIR "temp_storage");
	    ob->vanish();
	}
    }
    slaves -= ([ pl ]);
    PARTY_D->remove_move_hook(pl, this_object());
}


void go_ld(object pl)
{
    mixed t, *data;
    int i;
    object *objs, ob;
    status had_follow_hook;

    if(!(t = slaves[pl])) return;
    had_follow_hook = PARTY_D->query_move_hook(pl, this_object());
    PARTY_D->remove_move_hook(pl, this_object());
    objs = m_indices(t);
    data = ({});
    for(i=sizeof(objs); --i>=0;) {
	ob = objs[i];
	if(!ob) continue;
	data += ({ ob, object_name(environment(ob)) });
	ob->move_player("X", PRIEST_ROOM_DIR "oblivion");
    }
    temp_data += ([ pl : had_follow_hook; data]);
}


void recover_from_ld(object pl)
{
    mixed data, t;
    int i,n;
    object room, ob;
    string room_name;

    if(!(t = slaves[pl])) return;
    if(temp_data[pl,0])
	PARTY_D->add_move_hook(pl, this_object());
    data = temp_data[pl, 1];
    for(i=0, n=sizeof(data); i<n;) {
	ob = data[i++];
	if(!ob) continue;
	room_name = data[i++];
	room_name->query_short(); // no unnecessary cache flushes
	if(room = find_object(room_name))
	    ob->move_player("X", room);
	else {
	    // the room has become bugged or something
	    ob->transfer_all_to(PRIEST_ROOM_DIR "temp_storage");
	    ob->vanish();
	}
    }
}


object*
query_slaves(object pl) {
    mixed t;

    if(!(t = slaves[pl])) return 0;
    return m_indices(t);
}

mapping query_data() { return slaves; }


// remember to mask bit 2, if you only want to know if a monster is
// following a player.
int
query_follow(object pl, object ob) {
    mixed t;
    if(!(t = slaves[pl]))
	return 0;
    return t[ob];
}


/* SPECIAL: follow_data
 * bit 1 - are we following?
 * bit 2 - shall we leave moving messages, ie. use standard move_player?
 */
status
set_follow(object pl, object ob, int follow_data) {
    status had_follow_hook;
    int *tmp;
    mixed t;

    if(!(t = slaves[pl])) return 0;
    t[ob] = follow_data;

    tmp = m_values(t);
    had_follow_hook = PARTY_D->query_move_hook(pl, this_object());
    if(member(tmp,1) == -1 && member(tmp, 3) == -1) {
	if(had_follow_hook)
	    PARTY_D->remove_move_hook(pl, this_object());
    }
    else {
	if(!had_follow_hook)
	    PARTY_D->add_move_hook(pl, this_object());
    }
    return 1;
}


void
player_moved(object pl, string verb, string arg, object room)
{
    mixed t;
    object ob, *monsies;
    int fd, i, *follow_data;

    t = slaves[pl];
    if(!t || !mappingp(t)) {
	slaves -= ([ pl ]);
	PARTY_D->remove_move_hook(pl, this_object());
	return;
    }
    monsies = m_indices(t);
    follow_data = m_values(t);
    i = sizeof(monsies);
    while(--i>=0) {
	if(!(ob = monsies[i])) {
	    t -= ([ 0 ]);
	    continue;
	}
	if(!((fd = follow_data[i]) & F_FOLLOW)) continue;
	if(room != environment(ob)) continue;
	if(fd & F_NO_MESSAGES) {
	    // let's inform only the player
	    pl->tell_me(sprintf("%s enters, following you.",
		capitalize(ob->query_real_name())));
	    if(ob && environment(pl))
		move_object(ob, environment(pl));
	}
	else {
	    ob->move_player(sprintf("following %s master",
		ob->Possessive()), environment(pl));
	}
    }
}

void
debug() {
    printf("Slaves: %O\n\nLinkdeads' slaves: %O\n", slaves, temp_data);
}

void save_data() {
    save_object(PRIEST_DAEMONS "slave_temp");
}
