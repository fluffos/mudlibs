#include "priest_spell.h"

// This spell does not train your skills! (nor does use them)

void begin_detect(object who, mixed target);
status end_detect(object who, mixed target);

void
create_spell() {
    lvl = 4;
    cost = 5;
    funs = ({ #'begin_detect, #'end_detect });
    skills_used = ({ });
}


void
begin_detect(object who, mixed target) {
    if(target == "") target = 1;
    else if(!(target=present(target, HERE)) || !living(target)) {
	who->tell_me("No such living being here.");
	target = 0;
	return;
    }

    HERE->tell_here(":%<me.capname>% pray%<me.ending_s>% for " GOD_NAME
      " to reveal the unholy beings.",0,0,0,who,0,0);
}


int
detect_one_room(mixed room) {
    object *inv;
    int i, n;
    object ob;

    if(stringp(room)) {
	if(!(ob = find_object(room))) {
	    room->load_me_now();
	    if(!(ob = find_object(room))) return 0;
	}
	room = ob;
    }
    inv = all_inventory(room);
    i = sizeof(inv);
    while(--i>=0) {
	if(living(inv[i]) && inv[i]->query(LIV_UNDEAD))
	    n++;
    }
    return n;
}


status detect_this_room(object who) {
    int n;
    if(n = detect_one_room(environment(who)))
	who->tell_me(sprintf("You sense presence of %d undead being%s \
in this room.", n, (n>1)?"s":""));
    return n;
}


status detect_next_rooms(object who) {
    mixed *rooms;
    string *exits, *found;
    mapping tmp;
    int i, n;
    string str;

    tmp = environment(who)->query_exits();
    if(!tmp) return 0;

    exits = m_indices(tmp);
    rooms = m_values(tmp);
    if(!(i = sizeof(rooms))) return 0;

    found = ({ });
    while(--i>=0) {
	if(detect_one_room(rooms[i]) && random(3))
	    found += ({sprintf("'%s'", exits[i])});
    }
    if(!(n=sizeof(found))) return 0;
    who->tell_me(sprintf("You sense presence of undead beings in exit%s %s.",
	(n>1)?"s":"", implode(found, ", ", " and ")));
    return n;
}


status
end_detect(object who, mixed target) {
    who->add_sp(-cost);

    if(intp(target)) {
	if(detect_this_room(who)) return 1;
	if(detect_next_rooms(who)) return 1;
	who->tell_me("You don't sense any undead beings nearby.");
	return 0;
    }

    if(target->query(LIV_UNDEAD))
	who->tell_me(":%<him.capname>% emits an aura of unholy life.",
	  0,0,0,target,0);
    else who->tell_me(":%<him.capname>% is perfectly normal living being.",
	  0,0,0,target,0);
    return 1;
}
