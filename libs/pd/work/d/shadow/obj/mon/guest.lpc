#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("guest");
  set("id",({"guest","noble","person","monster"}));
  set_level(26);
  set("short","Wedding Guest");
  set("long","This guest is here to attend the wedding of the prince and his bride.");
  set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_alignment(100);
  this_object()->add_money("gold",random(250));
}
