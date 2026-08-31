#include <std.h>
#include <lodos.h>
inherit MONSTER;

void create() {
 ::create();
   set_short("a Lodian citizen");
   set_id(({ "citizen", "lodian citizen", "lodian" }));
   set_name("citizen");
   set_level(19);
   set_long("The citizens calmly walk about lodos in the safety they "
      "have.");
   set_body_type("human");
   set_race("gnome");
   set_stats("dexterity", 30);
   set_stats("constitution", 30);
  if (random(10) > 6) {
   set_gender("male");
   if (random(2) == 2)
      new(ARM"trousers")->move(this_object());
   else
      new(ARM"tunic")->move(this_object());
  } else {
   set_gender("female");
   new(ARM"dress")->move(this_object());
  }
  if (random(3) == 2)
   new(ARM"boots")->move(this_object());
   set_heart_beat(1);
}
