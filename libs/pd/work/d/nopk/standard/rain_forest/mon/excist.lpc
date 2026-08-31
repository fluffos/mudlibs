#include <rain.h>
#include <std.h>
inherit "/std/vendor";

create() {
   ::create();
   set_name("excist");
   set_id( ({ "excist" }) );
   set_short("Excist, the weapon master");
   set("aggressive", 0);
   set_level(12);
   set_class("fighter");
   set_long("Excist used to be a master warrior but retired from "
            "serious wounds and become a shop keeper.");
   set_type(({ "weapon" }));
   set_languages( ({ "elfish" }) );
   set_gender("male");
   set_alignment(40);
   set_race("elf");
   add_money("gold", random(600));
   set_body_type("human");
   set_currency("gold");
   set_storage_room(ROOMS"storage");
   set_skill("bargaining", 150);
   set_property("no bump", 1);
   set_property("no attack", 1);
   new(WEA"esword")->move(this_object());
   this_object()->force_me("wield sword");
}

int is_invincible() {
    set_sp(query_max_sp());
   this_object()->force_me("shout in eltherian Help!! I am being attacked by "+
     (string)previous_object()->query_cap_name());
    return 0;
}

