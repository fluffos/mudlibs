#include <std.h>
#include <rain.h>
inherit MONSTER;

create() {
   ::create();
   set_name("guardian");
   set_short("A royal guardian");
   set_long("This guard has been recently promoted to the status "
            "of guardian. He now guards the council room");
   set_level(15);
   set_gender("male");
   set_class("fighter");
   set_race("elf");
   set_body_type("human");
   set_id(({"guard", "royal guard", "guardian"}));
   new(WEA"pike")->move(this_object());
   new(ARM"boots")->move(this_object());
   new(ARM"bplate")->move(this_object());
   this_object()->force_me("wear all");
   this_object()->force_me("wield pike");
}
