// Group-daemon. Handles groups of npcs doing some things together,
// like fighting.
//
// Version 1.0 27-may-95 by Doomdark
//
// When a npc of some npc group is attacked, it sends a message to
// this daemon. Daemon starts its heart_beat if it's not already on,
// and adds a new request on the global attack list of all groups.
// At next heart_beat, attack gets processed like this:
//
// 1) Object who called daemon first, gets its "group_attacked"
//    called with 3 arguments:
//	- object victim: pointer to object that initiated call (ie. in
//	  this case, this_object()!).
//	- object attacker: pointer to object that attacked npc.
//	- object *members: other npcs left in the group.
//
// This call is done so object can "yell help".
//
// If call to the function returns 0, no further actions; request is
// simply removed from the list. Otherwise, daemon moves the request
// to the second list, and at next heart_beat:
//
// 2) Each npc of the group gets its "group_attacked"-function called.
//    However, for big groups, only 5 npcs get their func called at
//    each heart_beat. This is to prevent too_long_eval_cost.

// Structure of groups-mapping:
// ([ group_name : ({ npc1, npc2, ... }), group_name2 : ({ ... }) ... ])

// Structure of attack list 1:
// ({ ({ victim1, attacker1, group1 }), ({ victim2, attacker, group2 })... })

// Structure of attack list 2:
// ({ ({ victim1, attacker1, ({ npc2_in_group, npc3_in_group, ... }) }), ... })
// (ie. otherwise same as list 1, but group members are directly in the list;
// this is to allow group to be called few npcs at a time. And this is to
// prevent too_long_eval_costs...).

#include "/sys/configuration.h"

mapping groups;		// Groups of npcs
mixed *attacks;		// Groups under attack, and to be processed.
mixed *attacks2;	// Groups under attack, after call for help is made.

status hb_on;		// Is our heart_beat on?
status processing;	// To prevent recursion on attacks.

#define		MAX_NPC_PER_HB		5
// This means how many npcs of group will be asked to join fight
// each heart beat. This is to prevent possible too_long_eval_costs.

void
create()
{
    groups = ([ ]);
    attacks = ({ });
    attacks2 = ({ });
}

// Let's clean mapping up... May contain some unused groups.
void
reset()
{
    string *grs;
    object *members;
    int i, size;
    if (!hb_on) {
	attacks = ({ });
	attacks2 = ({ });
    }

    for (i = sizeof(grs = m_indices(groups)) - 1; i >= 0; i--) {
	if (!pointerp(members = groups[grs[i]])) continue;
	members -= ({ 0 });		// Let's remove kileld npcs from group.
	if (!sizeof(members))
	    members = 0;	// We'll mark this group empty...
	groups[grs[i]] = members;
    }
    groups = m_delete(groups, 0);	// Now let's remove empty groups..
}

object *
query_group(string gname)
{
    return groups[gname];
}

// With this we'll add a npc to a group of npcs. If no such group
// exists yet, we'll create it.
void
add_to_group(string group, object npc)
{
    object *x;
    if (!(x = groups[group]))
	x = ({ npc });
    else {
	x -= ({ 0 });
	if (member(x, npc) >= 0) return;	// Already in group.
	x += ({ npc });
    }
    groups[group] = x;
}

void
group_attacked(object npc, object attacker, string group)
{
    if (processing) return;

    if (!hb_on)
	configure_object(this_object(), OC_HEART_BEAT, (hb_on = 1));

    attacks += ({ ({ npc, attacker, group }) });
}


void
process_attacks2()
{
    int size, size2, i, j;
    mixed *x;
    object *group, victim, attacker;
    for (size = sizeof(attacks2), i = 0; i < size; i++) {
	if (!(x = attacks2[i])) continue;
	if (!(victim = x[0]) || !(attacker = x[1])
	  || environment(victim) != environment(attacker)) {
	    // Either victim, or attacker (or both) has died, or either one has fled.
	    // In that case, let's remove the request.
	    attacks2[i] = 0;
	    continue;
	}
	if ((size2 = sizeof(group = x[2])) > MAX_NPC_PER_HB) {
	    // If more npcs, we'll handle just first from the group now.
	    attacks2[i][2] = group[MAX_NPC_PER_HB .. size2 - 1];
	    size2 = MAX_NPC_PER_HB;
	    group = group[0 .. size2 - 1];
	} else {
	    attacks2[i] = 0;
	    // Otherwise, let's mark this request done now.
	}
	for (j = 0; j < size2; j++) {
	    if (group[j])
		group[j] -> group_attacked(victim, attacker, group);

	    // Note that 3rd argument isn't now whole group! However, it shouldn't
	    // usually matter. If it does, we'll have to think of neat way to provide
	    // better solution. -+ Doomdark +-

	}
    }
    attacks2 -= ({ 0 });
    // Let's finally remove processed requests.
    // Note that unlike in "process_attacks" we can't simply clear whole
    // array as it may still contain partially processed requests!
}

void
process_attacks()
{
    int i, size, size2;
    object *x, victim, attacker;
    mixed *tmp;
    object dd;
    for (i = 0, size = sizeof(attacks); i < size; i++) {
	if (!(tmp = attacks[i]))
	    continue;
	attacks[i] = 0;	// Let's remove this from the first list.
	if (!(victim = tmp[0]) || !(attacker = tmp[1])
	  || environment(victim) != environment(attacker))
	    continue;

	// Victim or attacker is (or both are) dead, or attacker or victim has
	// fled away from the room!

	if (victim -> group_attacked(victim, attacker, (x = groups[tmp[2]]))) {
	    // We'll 'ask' npc if it wants other members to be asked to help...
	    // That is, if there are still other npcs alive.
	    x -= ({ 0, victim });	// Let's remove dead npcs, and originating
	    // npc, from the list.
	    if (!sizeof(x)) continue;

	    // Now, we'll move this request to the other list to be processed on
	    // next heart_beat.

	    attacks2 += ({ ({ victim, attacker, x }) });
	}
    }

    attacks = ({ });	// If we've got this far, it'll be empty.
    // Nulling of elements if done just to be
    // sure we won't repeat calls.
}

// Let's first process actual giving of help, as they're supposed to
// be more urgently needed... 8-)
void
heart_beat()
{
    string error;
    int i;
    processing = 1;
    if (sizeof(attacks2)) {
	if (error = catch(process_attacks2())) {
	    write(error);	// Let's hope it goes to some log!!!
	    processing = 0;
	    return;
	}
    } else if (!sizeof(attacks)) {

	// If no more calls, we can turn hb off to save CPU-time.
	configure_object(this_object(), OC_HEART_BEAT, (processing = hb_on = 0));
	return;
    }

    if (sizeof(attacks)) {
	if (error = catch(process_attacks())) {
	    write(error);	// Let's hope it goes to some log!!!
	}
    }
    processing = 0;
}

mapping
query_groups()
{
    return groups;
}
mixed *
query_attacks(int x)
{
    return x ? attacks2 : attacks;
}
