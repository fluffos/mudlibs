#include <std.h>
#include <sindarii.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("anarchin");
    set_short("Anarchin the anarchist");
    set_long("Anarchin is one of the leaders of the anarchist cult near the "
      "Tirunian border. Anarchin is the true anarchist at heart, and she "
      "despises anything to do with the law.");
    set_race("ogre");
    set_body_type("human");
    set_alignment(-900);
    set_gender("female");
    set_level(11);
    set_max_hp(300);
    set_hp(300);
    set_id(({ "anarchin", "anarchist", "anarchin the anarchist" }));
    new(ROOMS"cult/obj/handaxe")->move(this_object());
    command("wield axe");
}
