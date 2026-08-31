#include <std.h>
#include <tirun.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("chance");
   set_id( ({ "chance" , "ferrel" }) );
   set_short("Chance");
   set_level(6);
   set_long("A young ferrel. He seems to be looking for something.");
   set_alignment(-100);
   set_race("ferrel");
   set_body_type("ferrel");
   set_gender("male");
   set_moving(1);
   set_speed(6);
   set_says(5, ({"I will find their hide-out!",
                "I know it is in a warehouse here somewhere...",
                "I am going to be a thief!"}), 0);
   new(WEP"mace")->move(this_object());
   force_me("wield mace");
   new(ARM"gloves")->move(this_object());
   force_me("wear gloves");
}
