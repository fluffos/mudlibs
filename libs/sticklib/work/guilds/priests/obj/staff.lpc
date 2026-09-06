/*
 * Wow, what a mess this was...
 * Cleaned up by Chopin, 5/28/97
 */

#include "../priest.h"
#include "../skills.h"
#include <weapon.h>
#include <stats.h>
#include <conditions.h>
#include <living_defs.h>

#define ENV environment
#define TO this_object()
#define TP this_player()

#define STAFF_FULLNESS_STRINGS ({"almost empty of mental energy", \
"quite empty of mental energy", "partially full of mental energy", \
"almost full of mental energy","full of mental energy"})

#define IS_OWNER (owner && TP && TP == owner)

int has_sp, max_has_sp, last_use;
status zapping;
object owner;
string owner_name;
string staff_short, staff_long, staff_id;


/* QUERY FUNCTIONS */

status is_priest_staff() { return 1; }
int query_max_sps() { return max_has_sp; }
int query_cur_sps() { return has_sp; }
int query_last_use() {return last_use; }
object query_owner() { return owner; }
string query_owner_name() { return owner_name; }
string query_staff_name() { return staff_short; }
string query_staff_id() { return staff_id; }
status query_zapping() { return zapping; }

/* SET FUNCTIONS */

void set_last_use(int x) {last_use = x; }
void set_zapping(status x) { zapping = x; }
void set_sps(int x) { has_sp = x; }

/* PROTOTYPES */

void self_destruct();
string my_query_long(string what, object who);



status add_sps(int x) {
    has_sp += x;
    if(has_sp > max_has_sp) { has_sp = max_has_sp; return 1; }
    if(has_sp < 0)   { has_sp = 0; return 1; }
    return 0;
}

private void
calculate_max_sp() {
    int i, l, l2;

    if(!owner) { 
	max_has_sp = 50;
	return;
    }
    l = owner->query_level();
    switch(l) {
    case 0..19:
	staff_short = "stick";
	staff_long = "a small pine stick";
	set_name(capitalize(owner_name) + "'s stick of " GOD_NAME);
	set_id(({"stick","stick of "+lower_case(GOD_NAME),"pine stick"
	    ,"small stick","small pine stick"}));
	set_weight(2);
	break;
    case 20..29:
	staff_short = "staff";
	staff_long = "a long oak staff";
	set_name(capitalize(owner_name) + "'s staff of " GOD_NAME);
	set_id(({"staff","staff of "+lower_case(GOD_NAME),"oak staff",
	    "long oak staff","long staff"}));
	set_weight(3);
	break;
    default:
	staff_short = "staff";
	staff_long = "a huge ebony staff";
	set_name(capitalize(owner_name) + "'s staff of "+GOD_NAME);
	set_id(({"staff","staff of "+lower_case(GOD_NAME),"ebony staff",
	    "huge staff","huge ebony staff"}));
	set_weight(4);
	break;
    }
    set_id(STAFF_ID);
    staff_id = staff_short + " of " GOD_NAME;
    i = l;
    if(i>40) i = 40;
    set_wc(4 + i/3);

    i = owner->query_stat(ST_INT);
    /*
	i = owner->query_stat(ST_INT) - 10;
	i = (i<0) ? 0 : i;
	l = (l<11) ? 0 : (l-10);
	max_has_sp = 50 + i*i/4 + 1000*l/(l+37);
    */
    max_has_sp = 3 * i * owner->query_race_stat(RACE_SP_RATE) / 2;
    if(max_has_sp > 850) max_has_sp = 850;
}


public void
set_owner(mixed who) {
    if(objectp(who)) {
	owner = who;
	owner_name = who->query_real_name();
    }
    else {
	owner = find_player(lower_case(who));
	owner_name = lower_case(who);
    }
    calculate_max_sp();
}


void
reset_weapon() { 
    if(has_sp && ENV() && ENV() != owner)
	has_sp = has_sp * 80 / 100;
    /* Sps won't last forever... */
}

void
create_weapon() {
    owner = owner_name = 0;
    staff_short = "staff";
    staff_long = "a long oak staff";
    staff_id = "staff of " + GOD_NAME;
    set_name("staff");
    set_id( ({ staff_id,"holy "+staff_id }) );
    set_long(#'my_query_long);
    set_weight(4);
    max_has_sp = 50;
    has_sp = 0;
    set_wc(10);
    set(WP_BLUNT);
    set(WP_TWO_HANDED);
    set(WP_TYPE, "staff");
    set_wield_func(TO);
}


string
my_query_long(string what, object who) {
    object ob;
    string str;

    if(!objectp(who)) who = TP;

    if(!IS_PRIEST(who) && !who->query_coder_level()) {
	str = sprintf("It's %s. Somehow it seems to emit some kind of \
a godly power, which makes you uncertain if it's wise to touch it. ",
	  staff_long);
	if(owner_name)
	    str += sprintf("There's a name '%s' engraved on it",
	      capitalize(owner_name));
    }
    else {
	str = sprintf("It's %s, and you recognize it as a '%s'. \
It seems to be %s.", staff_long, staff_id, 
	  STAFF_FULLNESS_STRINGS[has_sp*9/2/max_has_sp]);
	if(who->query_coder_level())
	    str += sprintf(" (coder info: %d/%d sps) ",has_sp, max_has_sp);
	if(owner_name)
	    str += sprintf("It has a name '%s' engraved on it",
	      capitalize(owner_name));
    }
    return str;
}

// Damn, can't use a closure here, because of /basic/curse.c!
varargs string
query_short(object who) {
    if (!objectp(who)) who = TP;
    if (!who || !environment() || !IS_PRIEST(who))
	return capitalize(staff_long);
    if(!owner) return "A " + staff_id;
    return sprintf("%s's %s%s",
      capitalize(owner_name), staff_id, wielded ? " (wielded)":"");
}

status
drop(int silently)
{
    if(!environment() || !owner) return 0; // shouldn't happen, but...
    if(environment() != owner) {
	if(query_verb() == "quit") {
	    object x;
	    if((x = find_player(owner_name)) && (x = ENV(x)))
		call_out("quit2",1,x);
	    else call_out("quit2",1,0);
	}
	return 0;
    }
    else switch(query_verb()) {
    case "drop":
	owner->tell_me("Your "+staff_id+" doesn't want to be dropped!\n");
	break;
    case "give":
	owner->tell_me("Your "+staff_id+" refuses to be given to anyone!\n");
	break;
    }
    return 1;
}

void quit2(object x)
{
    if(objectp(x)) x -> tell_here(
	  capitalize(owner_name) + "'s "+staff_short+" levitates up toward the sky.\n"
	  +"Suddenly, it disappears.");
    destruct(TO);
}


status
get() {
    string verb;
    verb = query_verb();
    if(verb == "get" || verb == "take")
	TP->tell_me(sprintf("You %s the %s, and feel mighty divine \
powers it has!", verb, staff_short));
    if(!IS_PRIEST(TP))
	call_out("self_destruct", 3+random(5)); // *grin*
    return 1;
}

status
wield(object this, object who)
{
    object room;

    if(!IS_PRIEST(who)) {
	who->tell_me("As you try to wield the staff, you feel \
terrible pain in your head!\nYour hands start shaking violently!\n\
You drop the staff.");
	ENV(who)->tell_here(":%<me.capname>% tries to wield the staff, \
but %<me.possessive>% hands start shaking violently.\n%<me.capname>% \
drops the staff!",0,0,who,who,0,0);
	who->add_hp(-(5+random(10)));
	move_object(TO, ENV(who));
	who->add_weight(query_weight());
	return 1;
    }
    who->tell_me("You feel the power of " GOD_NAME " the almighty as \
you wield "+staff_short);
    return 0;
}


void
self_destruct(){
    object holder;

    holder = ENV(TO);
    if((!interactive(holder)) || IS_PRIEST(holder) ||
      holder->query_coder_level()) return;

    holder->tell_me("The staff suddenly begins to vibrate violently, \
and you notice a blue sheen running up and down it's length. As you watch \
in horror, this increases in freqency and seems to emit a deafening \
shriek. With a loud scream, as if the very air around you were splitting, \
the staff explodes into a thousand pieces. You feel very strange.....");

    ENV(holder)->tell_here(":%<me.capname>% has a worried look. You \
notice that the staff in %<me.possessive>% hand has begun to shake \
violently and a blue sheen seems to be covering %<me.objective>%. As you \
watch in horror, the staff blue aura begins to pulsate and emit a high \
pitched hum increasing in frequency until you can hear it no longer.\n\
Suddenly, with a deafening roar, the air is ripped from your lungs. \
As you slowly look around, you notice %<me.name>% lies crumpled on the \
floor.",0,0,holder,holder,0,0);

    holder->add_condition(C_UNCONSCIOUS,5+random(5));
    holder->hit_player(random(holder->query_hp()),DT_AIR,0,TO);
    destruct(TO);
}

status 
no_steal() { return 1; }

status
is_curseable() { return 0; }

