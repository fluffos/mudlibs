/**************************************************

 NAME:    partyd.c

 PURPOSE: Party daemon

 AUTHOR:  Tron.

 CHANGES:
	25-sep-95: Added second mapping to speed up
		checking in which party player
		belongs to. Also, now supports new
		party follow. -+ Doomdark +-
	26-sep-95: As whole party system is rewritten,
		this too is... -+ Doomdark +-
	06-nov-95: Added a way to add 'hook' so that
		each time a player moves, certain
		object gets informed. The function is
		"add_move_hook()". For more information,
		check the function. :-)

***************************************************/

#include "/sys/configuration.h"

#include <party.h>

int party_id;

// party_id : ({ player_ob1, ...})
// Party leader is always the first in the list.
mapping parties;

mapping members;	// "Reversed" party list; index is player object,
// value number of party player belongs to.

mapping hooks;		// Mapping of all hooks 'connected' to players.

status hb_on;		// Turning hb on is costly... So let's be sure it's needed

nomask int del_party(object o, int i);
varargs nomask int set_party_data(int i, string s, mixed x, mixed y);

// Let's check out which parties exist at the moment... :-/
nomask void
create()
{
    //object *u, *tmp, pl;
    //int i, pid;
    parties = ([ ]);
    members = ([ ]);
    hooks = ([ ]);
    party_id = 0;
}

nomask void
reset()
{
    object *x;
    int i;
    // Let's clean 'em up; it's possible some players have quitted,
    // yet call to 'player_quitted' has failed for some reason... :-(
    m_delete(parties, 0);
    m_delete(members, 0);
    m_delete(hooks, 0);
    x = m_indices(parties);
    i = sizeof(x);
    while (i--) {
	// This _shouldn't_ happen, but let's be sure. -+ Doomdark +-
	if (!parties[x[i]])
	    m_delete(parties, x[i]);
    }
    x = m_indices(members);
    i = sizeof(x);
    while (i--) {
	// Likewise...
	if (!members[x[i]])
	    m_delete(members, x[i]);
    }
    x = m_indices(hooks);
    i = sizeof(x);
    while (i--) {
	if (!hooks[x[i]])
	    m_delete(hooks, x[i]);
    }
}

// These might be handy sometimes:
mapping
query_party_members()
{
    return members;
}

mapping
query_move_hooks()
{
    return hooks;
}

nomask mapping
query_parties()
{
    return parties;
}

nomask mixed
query_party(int pid)
{
    return parties[pid];
}

nomask status
query_prevent_shadow()
{
    return 1;
}

nomask private int
_add_new_party(object plr, int pid)
{
    object shadow_ob;
    plr -> set_party(PARTY_LEADER, 1);
    plr -> set_party(PARTY_ID, pid);
    parties[pid] = ({ plr });
    members[plr] = pid;	// Let's add this too.
    return 1;
}

nomask private int
_add_party(object plr, int pid)
{
    object shadow_ob;
    mixed  p_data;

    p_data = parties[pid];
    if (!p_data) return 0;

    plr -> set_party(PARTY_MEMBER, 1);
    plr -> set_party(PARTY_ID, pid);

    p_data += ({plr});
    parties[pid] = p_data;
    members[plr] = pid;	// Let's add this info too.

    return 1;
}

nomask private int
_generate_pid() { return ++party_id; }

nomask int
add_party(object inviter, object member)
{
    int i;
    int pid, pid2;

    if (!member || !inviter) return 0;

    // Check if player is part of some other party.
    if (pid = members[member]) return 0;

    pid = members[inviter];
    if (!pid) {
	pid = _generate_pid();
	if(!_add_new_party(inviter, pid)) return 0;
	i = 1;
    }
    pid2 = (_add_party(member, pid)) ? pid : 0;

    if (!pid2 && i) {
	del_party(inviter, pid);
    }

    if (pid2 && !hb_on) {
	configure_object(this_object(), OC_HEART_BEAT, (hb_on = 1));
    }

    return pid2;
}


nomask int
del_party(object plr, int pid)
{
    mixed arg;
    int i, siz;
    int leader;

    if (!plr || !pid) return 0;

    if (!(arg = parties[pid])) return 0;

    if ((i = member(arg, plr)) == -1)
	return notify_fail("No such member in the party.\n"), 0;

    if (i == 0) leader = 1;

    m_delete(members, plr);
    arg[i]->set_party(PARTY_ID, 0);
    arg[i] = 0;

    arg -= ({ 0 });

    siz = sizeof(arg);
    if (siz == 1) {
	arg[0]->tell_me("The party is disbanded.");
	m_delete(members, arg[0]);
	arg[0]->set_party(PARTY_ID, 0);
	m_delete(parties, pid);
    } else if (!siz)
	m_delete(parties, pid);
    else {
	if (leader) {
	    set_party_data(pid, "tell_me",
	      "[Party]: The new party leader is "+ capitalize(
		(string)arg[0]->query_real_name()));

	    arg[0] -> set_party(PARTY_LEADER, 1);

	}
	parties[pid] = arg;
    }

    return 1;
}

varargs nomask int
set_party_data(int pid, string func, mixed arg, mixed arg2)
{
    mixed list;
    int i;

    list = parties[pid];
    if(!list) return 0;

    i = sizeof(list);
    while (i--)
	if(list[i])
	    call_other(list[i], func, arg, arg2);

    return 1;
}

nomask mixed
query_party_data(int pid, string func, mixed arg)
{
    mixed list;
    int i, j;
    mixed ret;
    status is_null;
    list = parties[pid];
    if (!list) return 0;

    ret = ({});
    i = sizeof(list);
    for (j = is_null = 0; j < i; j++) {
	if (list[j])
	    ret += ({ call_other(list[j], func, arg) });
	else is_null++;
    }
    if (is_null) {
	list -= ({ 0 });
	parties[pid] = list;
	m_delete(members, 0);
    }
    return ret;
}

nomask int
disband_party(int pid)
{
    int i;
    mixed list;

    if (!(list = parties[pid])) return 0;

    list -= ({ 0 });
    m_delete(members, 0);

    i = sizeof(list);

    while (i--) {
	m_delete(members, list[i]);
	list[i]->set_party(PARTY_ID, 0);
    }

    m_delete(parties, pid);

    return 1;
}

nomask mixed
update_party(int pid)
{
    int i;
    mixed list;

    if(!pid || !parties) return 0;

    list = parties[pid];

    if (!list) return 0;

    if (!(i = sizeof(list)))
	return list;

    while (i--)
	if (!list[i]) break;

    if (i < 0) return list;	// Was ok.

    list -= ({ 0 });
    if (i = sizeof(list)) {
	if (i > 1) {
	    if (!list[0]->query_party(PARTY_LEADER)) {
		set_party_data(pid, "tell_me", "[Party]: The new party leader is "+
		  capitalize((string)list[0]->query_real_name()));
		list[0] -> set_party(PARTY_LEADER, 1);
	    }
	} else {
	    list[0]->tell_me("The party is disbanded.");
	    m_delete(members, list[0]);
	    list[0]->set_party(PARTY_ID, 0);
	    m_delete(parties, pid);
	    return 0;
	}
    } else {
	m_delete(parties, pid);
	return 0;
    }
    // Let's be sure we get rid of these... 
    m_delete(members, 0);

    return list;
}

nomask void
share_party_exp(object killer, int pid, int exp)
{
    mixed list;
    int i;
    int tlvl;
    int texp;
    object env;
    object ob;

    if (!pid || !exp || !killer) return;

    env = environment(killer);

    list = update_party(pid);
    if (list == 0) {
	killer->add_exp(exp);
	return;
    }

    i = sizeof(list);
    while (i--) {
	if (env == environment(list[i]))
	    tlvl += (int)list[i]->query_level();
    }
    if (!tlvl) return;
    // Let's round it to nearest integer. -+ Doomdark +-
    texp = (exp + tlvl / 2) / tlvl;

    i = sizeof(list);
    while (i--) {
	if (env == environment(list[i])) {
	    tlvl = (int)list[i]->query_level();
	    list[i]->add_party(PARTY_EXP, texp * tlvl);
	}
    }
}

nomask void
heart_beat()
{
    int *pid_list;
    int i;

    if (!parties || !sizeof(parties)) {
	configure_object(this_object(), OC_HEART_BEAT, (hb_on = 0));
	return;
    }

    pid_list = m_indices(parties);
    i = sizeof(pid_list);
    while (i--)
	update_party(pid_list[i]);
}

// This will be called when a player moves. Now, we have to check if
// we are leading a party!

void
player_moved(object plr, string verb, string arg, object room)
{
    int i;
    object *party;
    mixed tmp;
    mixed s;
    // First we'll check whether we belong to a party.
    if ((i = members[plr]) && (party = parties[i])
      && sizeof(party) && party[0] == plr
      && plr->query_party(PARTY_DO_LEAD)) {
	// Also; query_party(PARTY_DO_LEAD) checks that we're not invis...
	i = 0;
	// Ok. So let's rock...
	if (stringp(arg) && sizeof(arg))
	    s = verb + " " + arg;
	else
	    s = verb;
	while (++i < sizeof(party)) {
	    if (party[i] && environment(party[i]) == room)
		party[i] -> add_party(PARTY_DO_FOLLOW, s);
	}
    }
    // Now... Let's check if some object(s) want(s) to catch this move...
    // If so, we'll inform it(them):

    if (tmp = hooks[plr]) {
	if (objectp(tmp)) {
	    tmp -> player_moved(plr, verb, arg, room);
	}
	else if (pointerp(tmp)) {
	    i = s = 0;
	    while (i < sizeof(tmp)) {
		if (objectp(tmp[i]))
		    tmp[i] -> player_moved(plr, verb, arg, room);
		else s++;
		i++;
	    }
	    // Now; some object(s) may have been destructed. If so, we'll remove it(them)
	    // from the array.
	    if (s) {
		tmp -= ({ 0 });
		if (!sizeof(tmp))
		    m_delete(hooks, plr);
		else if (sizeof(tmp) == 1)
		    hooks[plr] = tmp[0];
		else hooks[plr] = tmp;
	    }
	}
    }
}

// This gets called when a player quits. We can now remove references
// to the player object, thus making life a whole lot easier... :-)
void
player_quitted(object ob)
{
    m_delete(members, ob);
    m_delete(hooks, ob);
}

// This will add a new 'hook' for the player (argument 1). In effect,
// this means that every time player in question moves (through an
// exit, or by a command defined by room), object (argument 2) will
// get its function "player_moved" called with 4 arguments;
// - object player: player who moved
// - string verb: verb of the command player entered ("east", "enter" etc.)
// - string rest: rest of the command (after verb). May be 0. (if command
//		was "enter house", this'll be "house" etc.)
// - object room: room player moved from.

// Note: use this function with care... this is useful for following
// monsters and such, but causes extra call_other's, which tends to
// make things slower (if used carelessly).

// When you no longer need to catch moves player makes, please do use
// call to function "remove_move_hook".

status
add_move_hook(object plr, object ob)
{
    mixed tmp;
    if (!plr || !ob || plr == ob || ob == this_object()) return 0;
    if (!(tmp = hooks[plr]))
	hooks[plr] = ob;
    else if (pointerp(tmp)) {
	tmp -= ({ 0 });
	hooks[plr] = tmp + ({ ob });
    } else {
	hooks[plr] = ({ tmp, ob });
    }
    return 1;
}

status
remove_move_hook(object plr, object ob)
{
    mixed tmp;
    if (!(tmp = hooks[plr])) return 0;
    if (!pointerp(tmp))
	m_delete(hooks, plr);
    else {
	tmp -= ({ ob, 0 });
	if (!sizeof(tmp))
	    m_delete(hooks, plr);
	else if (sizeof(tmp) == 1)
	    hooks[plr] = tmp[0];
	else
	    hooks[plr] = tmp;
    }
    return 1;
}

object
query_move_hook(object followee, object follower)
{
    mixed x;
    if (!follower) return hooks[followee];
    if (!(x = hooks[followee])) return 0;
    if (objectp(x)) return (x == follower) ? follower : 0;
    if (!pointerp(x)) return 0;
    return (member(x, follower) >= 0) ? follower : 0;
}
