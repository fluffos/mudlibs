/*************************************************************************
 * New bench by Necros - Jan 5 1997                                      *
 ************************************************************************/
#include "/sys/configuration.h"

#include <treasure.h>
#include <invis_levels.h>
#define CAPNAME capitalize(this_player()->query_real_name())

#define MAX_PEOPLE 5
// 26-Apr-97 / Graah: slightly worse, was 100 - ...
#define HEAL_CHANCE 75 - (who->query_level()) + random(20)
// Big lords get penalized.
#define HEAL_AMOUNT random(3)+1

string short, long, *people, *id;
int bench_max_people;

nomask int query_prevent_shadow() { return 1; }

private nomask void remove_person(string who);
void set_bench_short(string a) { short = a; }
void set_bench_long(string b)  { long = b;  }
void set_bench_max_people(int x) { bench_max_people = x; }
nomask private status heal(object who);
status extra_heal(object who);

void create_treasure() {
    string bench_color, bench_material, bench_adj;
    set_name("bench");
    set_id(({ "bench" }));
    configure_object(this_object(), OC_HEART_BEAT, 1);
    people = ({ });
    bench_color = ({ "red", "blue", "yellow", "orange", "purple", "crimson",
      "black", "white", "gray", "magenta", "lavender" }) [random(11)];
    bench_adj = ({ "old", "new", "worn", "dirty", "clean", "rough", "smooth",
      "low", "high", "wide", "narrow", "fancy", "plain", "dull",
      "interesting" }) [random(14)];
    bench_material = ({ "wood", "metal", "stone", "pine", "oak", "cedar",
      "mahogany", "steel", "bronze" }) [random(9)];
    short = capitalize(bench_adj)+" "+bench_color+" "+bench_material+" bench";
    long = "This is a "+short+". It looks like a good place to take a "
    "breather from all violence of killing. ";
    bench_max_people = MAX_PEOPLE;
}

int extra_heal(object who) { return 0; }

private nomask void add_person(string who) { people += ({ capitalize(who) }); }

status left() {
    remove_person(CAPNAME);
    return 0;
}

private nomask void remove_person(string who) {
    object w;
    w = find_player(lower_case(who));
    if(w && !interactive(w)) w->set_sit(0);
    people -= ({ capitalize(who) });
}

nomask string *query_people() { return people; }

void init_treasure() {
    int i;
    string *exits;
    add_action("sit", "sit");
    add_action("stand", "stand");
    if(environment()->query_exits())
	exits = m_indices(environment()->query_exits());
    else exits = ({});
    if(sizeof(exits))
	for(i=0;i<sizeof(exits);i++)
	    add_action("left", exits[i]);
}

nomask status sit() {
    if(this_player()->query_sit() ||
      member(people, CAPNAME) >= 0) {
	this_player()->tell_me("You're already sitting on the bench. ");
	return 1;
    }
    if(sizeof(people) >= bench_max_people) {
	notify_fail("You sit on the ground, as there is no room "
	  "on the bench. ");
	return 0;
    }
    this_player()->tell_me(
      "You plop your tired bones on the bench and take a breather. "
    );
    // sit command does this message.
    // environment()->tell_here(CAPNAME+" sits down on the bench. ",
    //   this_player());
    add_person(CAPNAME);
    this_player()->set_sit(1);
    return 1;
}

nomask status stand() {
    if (!this_player()->query_sit() || member(people, CAPNAME) == -1) return 0;
    this_player()->tell_me("You stretch lazily and stand up from the bench. ");
    remove_person(CAPNAME);
    environment()->tell_here(CAPNAME+" stands up from the bench. ",
      this_player());
    this_player()->set_sit(0);
    return 1;
}

nomask void heart_beat() {
    int i;
    object who;
    if(!sizeof(people)) return;
    for(i=0;i<sizeof(people);i++) {
	who = present4(lower_case(people[i]), environment(this_object()),
	  this_object(), IL_TOTALLY_INVISIBLE);
	if(!who) { remove_person(people[i]); return; }
	if(!who->query_sit()) { remove_person(people[i]); return; }
	else heal(who);
    }
    if(extra_heal(who) < HEAL_AMOUNT) who->heal_self(extra_heal(who));
    return;
}

private nomask status heal(object who) {
    if(!who) return 0;
    if(random(100)+1 <= HEAL_CHANCE) {
	who->heal_self(HEAL_AMOUNT);
	return 1;
    }
    return 0;
}

string query_short() {
    string rets;
    rets = short;
    if(sizeof(people)) {
	rets += " (with "+implode(people, "&")+" sitting on it)";
    }
    return rets;
}

string query_long() {
    string rets;
    rets = long;
    if(sizeof(people)) {
	rets += "You see the following people sitting on it: "+
	implode(people, "&")+". ";
    }
    return rets;
}

status get() { return 0; }

