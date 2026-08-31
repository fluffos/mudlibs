#include <std.h>
#include <citrin.h>

inherit MONSTER;


void create() {
    ::create();
    set_name("eel");
    set_short("an electric eel");
    set_long("The eel looks electrifying.  It would not be "
      "wise to wonder to close to it.");
    if(random(2)) set_level(40); else
	set_level(50);
    if(random(2)) set_gender("male"); else
	set_gender("female");
    set_race("eel");
    set_body_type("fish");
    set_id(({ "eel", "electric eel", }));
    set_spells(({ "electric" }));
    set_spell_chance(30);
    add_action("felectric", "electric");
}

int felectric() {
    int resist, para;
    object ob;

    ob = query_current_attacker();

    message("attack", "The eel tips back and %^BOLD%^%^CYAN%^shocks%^RESET%^ you!  A sudden "
      "rush of paralyzing pain rushes through you.", query_current_attacker());
    message("attack", "The eel tips back and %^CYAN%^%^BOLD%^shocks%^RESET%^ "+
      query_current_attacker()->query_cap_name()+"!", environment(this_object()), ({ ob }));
    resist = ob->query_stats("wisdom")/8+ob->query_skill("magic defense")/50;
    para = 2+random(4);
    if(resist>para) message("attack", "You are lucky and not affected by the "
	  "eels paralyzing shock.", ob);
    else ob->set_paralyzed( 2*(para-resist) );
    return 1;
}

