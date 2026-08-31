#include <std.h>

inherit UNDEAD;

void create() {
  object ob;
  ::create();
  set_short("A witch");
  set_long("The witch cackles and twirls her broom.");
  set_id(({"witch", "QOmonster"}));
  set_body_type("human");
  set_race("witch");
  set_gender("female");
  set_level(4 + random(5));
  set_name("witch");
  set_skill("blunt", 50);
  ob = new(WEAPON);
  ob->set_short("broom");
  ob->set_name("broom");
  ob->set_id(({ "broom" }));
  ob->set_long("A long broom with straw at one end.  Not very good for sweeping.");
  ob->set_type("blunt");
  ob->set_wc(2);
  ob->set_weight(2);
  ob->move(this_object());
  force_me("wield broom");
}
