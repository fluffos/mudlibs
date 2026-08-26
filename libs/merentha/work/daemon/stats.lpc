// Petrarch
// Merentha Lib 1.0
// stats.c

#include <daemons.h>
#include <std.h>

inherit DAEMON;

void init_stats(object ob, string str) {
    if(!ob) return;
    if(!str) str=ob->query_race();
    ob->set_stats(RACE_D->query_stats(str));
    ob->set_stat_bonuses((["eyes":0]));
    ob->set_max_items(ob->query_stat("strength")/10);
    ob->set_max_mass(ob->query_stat("strength")/2);
}
