#include <std.h>

inherit OBJECT;

void create() {
::create();
set_name("stone");
set_short("A magical stone");
set_long("This stone tells you who is the strongest person out of all whos on at this time.");
set_id( ({ "stone", "magical stone"}) );
set_value(1);
set_weight(1);

}

void init() {
::init();
add_action("fcalc","calculate");
}

int fcalc() {
object *user = users();
string highest;
int cnt;

int i = sizeof(user);

while(i--) {
int b;
b = user[i]->query_stats("strength")+user[i]->query_stats("dexterity")+user[i]->query_stats("constitution")+user[i]->query_stats("charisma")+user[i]->query_stats("wisdom")+user[i]->query_stats("intelligence");
if (cnt < b) { cnt = b; highest = user[i]->query_cap_name(); }

message("info", user[i]->query_cap_name()+" has "+user[i]->query_stats("strength")+"str/"+user[i]->query_stats("dexterity")+"dex/"+user[i]->query_stats("constitution")+"con/"+user[i]->query_stats("charisma")+"cha/"+user[i]->query_stats("wisdom")+"wis/"+user[i]->query_stats("intelligence")+"int", find_player("seeker"));
}
message("info", highest+" has the most stat points with "+cnt+".",environment());
return 1;
}
