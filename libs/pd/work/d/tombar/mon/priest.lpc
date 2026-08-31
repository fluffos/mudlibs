#include <std.h>
#include <tombar.h>
inherit MONSTER;
void init() {
    ::init();
    add_action("instakill","instakill");
}

void create() {
    ::create();
    set_name("high priest");
    set_long("This is the high priest of the Temple.  He goes about doing his "
      "priestly things like making sacrifices to the demons.");
    set_id(({ "high priest", "priest", "calidrynth", "priest calidrynth", 
	"high priest calidrynth" }));
    set_short("The High Priest Calidrynth");
    set_level(50);
    set_race("gremlin");
    set_spells(({"instakill"}));
    set_spell_chance(95);
    set("aggressive", 20);
    set_body_type("gremlin");
    set_gender("male");
    new(WEP"sacknife")->move(this_object());
    this_object()->force_me("wield knife");
}

int instakill() {
    object *env;
    int i;
    if(this_player() != this_object() && !wizardp(this_player())) return 0;
    //this_object()->force_me("shout May the gods of the demon world be please with my sacrifice.");
    this_object()->force_me("say May the gods of the demon world be please with my sacrifice.");
    i = sizeof(env =all_inventory(environment(this_object())));
    while(i--) {
	if(env[i]->is_player())
	    env[i]->die();
	message("environment","Dark lightening reaches out from the priests hands.  You "
	  "cannot help yourself.  You are in completly out of control.", env[i]);
    }
}

