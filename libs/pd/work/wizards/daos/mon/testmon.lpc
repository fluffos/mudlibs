#include <std.h>
#include <daemons.h>
inherit MONSTER;
void create() {
    string *mon_races;
    string b, tmp;
    int i, r;
    ::create();
    set_name("test monster");
    mon_races = RACE_D->query_races();
    r = random(sizeof(mon_races));
    set_race(mon_races[r]);
    tmp = a_or_an(mon_races[r]);
    set_short(tmp+" " +mon_races[r]);
    set_id( ({ "test monster", "monster" }) + explode(query_short(), " ") );
    set_body_type(mon_races[r]);
    set_level(random(50));
    i = random(2);
    if(i == 1) {
	set_gender("male");
    } else {
	set_gender("female");
    }
}

