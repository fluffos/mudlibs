#include <std.h>
#include <fenton.h>
inherit "/std/vendor";

create() {
    ::create();
   set_name("Contour");
   set_id( ({ "contour", "vendor", "armorsmith", "weaponsmith"}) );
    set_short("Contour, the greedy shopkeeper.");
    set("aggressive", 0);
    set_level(75);
    set_long("He buys and sells armor and weapon goods.\n"+
        "<help shop> will get you a list of shop commands.\n");
    set_languages( ({ "artrexcian" }) );
    set_gender("male");
    set_alignment(40);
    set("race", "artrell shell");    add_money("gold", random(2000));
    set_body_type("artrell");
    set_currency("gold");
    set_storage_room("/d/standard/storage");

    set_skill("melee",250);
    set_skill("attack",200);
     set_skill("bargaining", 250);
    set_property("no bump", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
this_object()->force_me("shout in farsi Wave bye bye to "+
      (string)previous_object()->query_cap_name());
    return 0;

}
