#include <std.h>

inherit OBJECT;

void create() {
   ::create();
   set_name("logger");
   set_id(({ "logger" }));
   set_long("You do not notice that here.");
   set_properties(([ "no auction":1, "no store":1 ]));
}

int query_auto_load() { return 1; }

int give() { 
    if (wizardp(this_player())) return 0;
    return 1; }
int reclaim() { 
    if (wizardp(this_player())) return 0;
    return 1; }
int store() { 
    if (wizardp(this_player())) return 0;
    return 1; }
int put() { 
    if (wizardp(this_player())) return 0;
    return 1; }
int drop() {
    if (wizardp(this_player())) return 0;
    return 1;
}
int bury() {
    if (wizardp(this_player())) return 0;
    return 1;
}
int dest() {
    if (wizardp(this_player())) return 0;
    return 1;
}
