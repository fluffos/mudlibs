
#include <std.h>
#include <rest.h>

inherit MONSTER;

int do_special_check(string);

mapping sizeinfo = ([
  "small" : 35,
  "medium" : 40,
  "large" : 50,
]);
string *allsizes = keys(sizeinfo);

void create() {
  string col, size, long;
  int level;
  string *spells = ({
    "bite", "claw", "tailspear", "swoop", "usespecial",
    "dragonfury", "wrap 10", "roar", "shield me",
    "sunder", "sunder", "dispell", "faithwing", "faithwing", "solarflare",
  });
  ::create();
  set_gender( ({ "male", "female" })[random(2)] );
  col = "white";
  size = allsizes[random(sizeof(allsizes))];
  
  set_name(col+" dragon");
  set_id( ({ "dragon", col+" dragon", }) );
  long = "This dragon has %^BOLD%^%^"+upper_case(col)+"%^"+col+"%^RESET%^ scales. ";

  switch (size) {
    case "medium":
      set_short("a "+col+" dragon");
      long += capitalize(query_subjective())+" is about average size for a dragon.";
    break;

    default:
      set_id(query_id() + ({ size+" "+col+" dragon", size+" dragon" }) );
      set_short("a "+size+" "+col+" dragon");
      long += capitalize(query_subjective())+" is rather "+size+".";
  }
  if (random(10) == 3) set_rest_type(SIT);

  set_long(long);
  set_class("dragon");
  set_race("dragon");
  set_body_type("dragon");
  set_subclass(col);
  set_alignment(1500);

  level = sizeinfo[size];
  level = level + random(level/8) - random(level/8);
  set_level(level);

  //set_stats("constitution", query_stats("constitution")*2);
  set_hp(query_max_hp());
  set_max_sp(query_max_sp()*2);
  set_max_mp(query_max_mp()*2);
  set_sp(query_max_sp());
  set_mp(query_max_mp());

  if (random(400) > 200)
    add_money("gold", 30+random(20));

  set_spell_chance(50+random(25));
  set_spells(spells);

  add_action("do_special_check", "usespecial");
}

// these hit everyone in the room, so only use them when there are no other mobs
int do_special_check(string str) {
  object tp = this_player();
  object tgt = tp->query_current_attacker();
  object env = environment(tp);
  object *mobs;
  mapping specials = ([
    "red" : ({ "breathe", "rage" }),
    "black" : ({ "breathe", "chainlightning", "chaosvapor" }),
    "white" : ({ "breathe", "dispell all" }),
    "blue" : ({ "breathe", "dispell all" }),
  ]);
  string *colspecials;
  string use, col;

  if (!tp || tp != this_object() || !env) return 0;

  mobs = filter(all_inventory(env), (: $1->is_monster() :) );

  if (tp->query_level() < 50 && random(50) < 25 && tgt)
    use = "breathe "+tgt->query_name();
  else if (!sizeof(mobs)) {
    col = tp->query_subclass();
    colspecials = specials[col];
    if (sizeof(colspecials))
      use = colspecials[random(sizeof(colspecials))];
  }

  if (!use) {
    if (tp->query_level() < 50)
      use = "breathe";
    else
      use = "claw";
  }

  command(use);

  return 1;
}
