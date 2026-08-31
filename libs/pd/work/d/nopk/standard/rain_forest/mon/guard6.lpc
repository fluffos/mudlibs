#include <std.h>
#include <rain.h>
inherit MONSTER;

create() {
   ::create();
   set_name("guard");
   set_short("A raknid guard");
   set_long("This guard has been recently hired to protect "
            "the castle from invaders.");
   set_level(12);
   set_gender("male");
   set_class("fighter");
   set_race("raknid");
   set_body_type("raknid");
   set_id(({"guard", "raknid guard", "guardian"}));
   new(WEA"doublesword")->move(this_object());
   new(WEA"doublesword")->move(this_object());
   new(ARM"artarm")->move(this_object());
   this_object()->force_me("wear armour");
   this_object()->force_me("wield sword 1");
   this_object()->force_me("wield sword 2");
}
