#include <std.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("taskmaster");
   set_id( ({ "taskmaster", "master", "orc" }) );
   set_short("a sadistic orc taskmaster");
  set_level(14);
   set_long("The sadistic taskmaster tortures anyone who doesn't "
            "obey the orc's cruel ideas of laws. He stares at you from "
            "behind his mask.");
    set_body_type("human");
   set_alignment(-1000);
   set("race", "orc");
   new("/d/standard/obj/armour/hood")->move(this_object());
   set_gender("male");
}
