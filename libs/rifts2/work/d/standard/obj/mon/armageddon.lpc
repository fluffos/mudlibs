inherit "std/monster";

#include <daemons.h>

void create() {
    ::create();
    set_name("gamedriver");
    set_id( ({ "armageddon", "asshole" }) );
    set_short("The All Powerful GameDriver");
    set_long("He appears once and briefly only to cause doom to the mud.\n");
    set_level(1);
    set_exp(1);
    set_max_hp(900000);
    set_hp(900000);
    set_max_mdc(1000);
    set_mdc(1000);
    set_stats( "ps", 1000);
    set_stats( "pe", 1000);
    set_body_type("human");
}


void catch_tell(string str) {
    string who, what, extra;

    if((int)SHUT_D->query_time_remaining() > 180) return;
    if(sscanf(str, "%s %s %s", who, what, extra) != 3) return;
    if(what != "tells") return;
    who = lower_case(who);
    if(!find_living(who)) return;
    find_living(who)->move("/d/standard/square");
    tell_object(find_living(who), "You are magically teleported somewhere.\n");
}
