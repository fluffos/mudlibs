#include <std.h>
#include <dragonevent.h>
inherit MONSTER;
int do_cast(string);
void create() {
    ::create();
    set_name("ogre mage");
    set_id( ({ "ogre", "ogre7" }) );
    set_class("mage");
    set_subclass("wizard");
    set_level(50);
    set_short("ogre mage" );
    set_long("%^RESET%^%^GREEN%^This nasty looking ogre stands about 5 feet taller than the average human. He has nasty %^BOLD%^%^YELLOW%^yellow teeth %^RESET%^%^GREEN%^that compliment his pale green skin.%^RESET%^" );
    set_race( "ogre" ); 
    set_gender( "male" );
    set_body_type("ogre");
    set_spells( ({ "cast disease", "cast shadowburst", "cast soulburn", "cast pillar", "cast manamissile", "cast pressure", "cast sear", "cast shroud", "cast flamewall" }) );
    set_spell_chance(85); 
    set_aggressive(20+random(10));
    new(DRAG_ARM "ogre_pants")->move(this_object());
    force_me("wear pants");
  set_skill("melee", 50);
    add_action("do_cast", "cast");
}

int do_cast(string str) {
  object tp = this_player();
  object to = this_object();
  string sub;
  int hp = query_hp();

  if (tp != to) return 0;

  switch (str ? str : "") {

    case "disease": case "shadowburst": case "soulburn":
      sub = "necromancer";
    break;

    case "pillar": case "manamissile": case "pressure":
      sub = "wizard";
    break;

    case "sear": case "shroud": case "flamewall":
      sub = "pyromancer";
    break;

    default: return 1;
  }

  set_subclass(sub);
  set_hp(hp);
  set_skill("melee", 50);
  command(str);

  return 1;
}
