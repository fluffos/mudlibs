#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
set_name("duergar thief");
set_short("a duergar thief");
set_long("This duergar thief seems to be hiding out, as if he's being hunted.  If you work for Diran, you might want to kill him.  If you work for the Duergar, you probably want to <lead> him to safety.");
set_id(({"thief", "duergar", "duergar thief", "dthief"}));
    set_level(51);
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",20);
    set_faction("duergar");
    set_gender("male"); 
    add_money("gold", random(75));
        set_spell_chance(20);
    set_spells(({"stab", "kick", "punch"}));
        new(ARM"dgpants")->move(this_object());
     force_me("wear pants");
new(OBJ"largeruby")->move(this_object());
             new(ARM"dgshirt")->move(this_object());
     force_me("wear shirt");
                  new(WEP"mdsknife")->move(this_object());
     force_me("wield dagger");
         set_race("duergar");


}

init() {
    ::init();
    add_action("lead_fun", "lead");
}

int lead_fun(string str) {
    if(!str) return notify_fail("Lead who?\n");
    if(str != "thief") return notify_fail("Lead who?\n");
    if(query_following()) return notify_fail("The thief is already following.\n");
    message("info", "You motion for the thief to follow you.", this_player());
    force_me("say You are wise to stand with Duergar, "+this_player()->query_cap_name()+"! We will win the war!  Let us get to the Duergar Master Scout quickly!");
    set_following(this_player());
    this_object()->follow_allow(this_player()->query_name());
    this_object()->set_speech(0);
    return 1;
}

void heart_beat() {
    object me;
    ::heart_beat();
    if(!this_object()) return;
    if(!environment()) return;
    if(!query_following()) return;

    if(environment(this_object()) != environment(query_following())) {
        message("info", "The thief follows "+query_following()->query_cap_name()+".", environment(this_object()));
        message("info", "The thief follows you.", query_following());
        this_object()->move(environment(query_following()));
    }


    if(environment(this_object())->query_property("thiefendroom")) {
        if(!query_following()) this_object()->remove();

        force_me("say Thank you for bringing me safely back to Duergar!");

        if(!query_following()->this_player()->set_quest("diran")) {
this_player()->set_stats("intelligence",
this_player()->query_base_stats("intelligence")+1);
this_player()->add_exp(500000);
    message("info", "You have returned the thief to the city of Duergar.  You have solved the quest of Diran.", this_player());
    return 1;

            this_object()->remove();
        }

        this_object()->remove();
    }
}

