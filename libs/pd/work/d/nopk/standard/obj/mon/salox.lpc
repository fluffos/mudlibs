#include <std.h>
inherit MONSTER;

#include <daemons.h>

void create() {
    ::create();
set_name("salox");
   set_id( ({ "salox", "salox the deranged" }) );
    set_short("Magician Salox the Deranged");
    set_long("No one knows his purpose in the grand scheme of things, "
             "or even why he exists.");
    set_level(51);
    set_hp(10000);
   set_stats( "intelligence", 1000 );
    set_body_type("human");
   set_race("pixie");
   set_gender("male");
}


void catch_tell(string str) {
    string who, what, extra;

    if((int)SHUT_D->query_time_remaining() > 180) return;
    if(sscanf(str, "%s %s %s", who, what, extra) != 3) return;
    if(what != "tells") return;
    who = lower_case(who);
    if(!find_living(who)) return;
find_living(who)->move("/d/nopk/standard/supply");
    tell_object(find_living(who), "You are magically teleported somewhere.\n");
}
