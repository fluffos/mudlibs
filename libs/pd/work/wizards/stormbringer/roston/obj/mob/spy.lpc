#include <std.h>
#include <roston.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("Bum");
    set_short("Old Bum");
    set_long("An old bum. Upon closer inspection the dark skin and pointed ears reveal this bum to be a drow.");
    set_id(({"bum", "old bum", "spy"}));
    set_level(40+random(5));
    new(ARM"robes")->move(this_object());
    force_me("wear robes");
    new(WEP"s_dagger")->move(this_object());
    force_me("wield dagger");
    set_race("drow");
    set_body_type("human");
    set_gender("male");
    set_moving(1);
    set_speed(1);
    set_wimpy(30);
    set_emotes(3,({"The spy glances around the room looking for a way out.",
                   "%^CYAN%^The spy exclaims:%^RESET%^ You will not stop me from reporting in!",}),1);

}                     
                          

