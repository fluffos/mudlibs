

#include <std.h>
inherit MONSTER;

int die_dummy();

void create() {
    ::create();
    set_name("Test Dummy");
    set_id( ({ "test dummy","dummy" }) );
    set_short("Test Dummy");
    set_long(
      "A wooden test dummy padded in leather. It was designed "
      "to simulate combat for inexperienced adventurers to hone "
      "thier abilities. "
    );
    set_class("fighter");
   set_level(2);
   add_exp(0);
    set("paralyzed",10000000000000);
   set_die( (: die_dummy() :) );
    set_gender("nueter");
    set_race("Test Dummy");
   set_hp(1500);
   set_max_hp(1500);
   set_body_type("human");
    set_stats("constitution", 10);
    set_stats("dexterity", 10);
    set_skill("defense", 10);
}

int die_dummy() {
   message("other_action", query_cap_name()+" falls to the ground from its post",
   environment(this_object()),({ this_object() }));
   return 1;
}

