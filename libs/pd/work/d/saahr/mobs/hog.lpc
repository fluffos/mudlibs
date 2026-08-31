
#include <std.h>
#include <saahr.h>

inherit MONSTER;

int do_my_special(string str);

void create() {
  ::create();
  set_name("wild hog");
  set_race("hog");
  set_body_type("quadruped");
  set_gender( ({"male","male","female"})[random(3)] );
  set_id(({"hog", "wild hog"}));
  set_short("Wild hog");
  set_long(
    "A large black hog that lives in the forest. Though it lacks "
    "tusks, its teeth are quite sharp and its eyes fierce.");

  set_class("fighter");
  set_subclass("berserker");
  set_level(27+random(9));

  set_spells(({"rush", "headbutt", "my_special"}));
  set_spell_chance(75);
  add_action("do_my_special", "my_special");
}

int do_my_special(string str) {
  object tp = this_player();
  string what;

  if (tp != this_object()) return 0;

  if (tp->query_hp() < 50 && load_object("/cmds/skills/_fury")->abil())
    what = "fury";

  else {
    object *mobs;
    mobs = filter(all_inventory(environment(tp)),
	(: ($1->is_monster() && !$1->is_pet()) :) );
    mobs -= filter(tp->query_attackers()->query_riding(),
	(: $1 :) );
    mobs -= ({ tp });
    if (!sizeof(mobs))
      what = "rage";
    else
      what = "headbutt";
  }

  if (!what) what = "headbutt";
  command(what);
  return 1;
}

int is_invincible() { command("brawn"); return 0; }

