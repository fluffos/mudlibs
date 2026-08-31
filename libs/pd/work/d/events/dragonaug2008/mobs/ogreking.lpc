#include <std.h>
#include <dragonevent.h>
inherit MONSTER;

varargs int event_die(object ob);

void create() {
  ::create();
  set_name("ogre king");
  set_id( ({ "ogre", "ogre king", "king" }) );
  set_level(70);
  set_short("the ogre king");
  set_long("This tall, pudgy ogre looks pretty intimidating. He stands above all the rest and has a regal air about him... Well, regal for an ogre.");
  set_race( "ogre" ); 
  set_gender( "male" );
  set_body_type("ogre");
  set_spells( ({ "rush" }) );
  set_spell_chance(60); 
  set_skill("melee", 330);
  set_class("fighter");
  set_subclass("berserker");
  new(DRAG_ARM "ogre_pants")->move(this_object());
  new(DRAG_WEP "ogre_club")->move(this_object());
  new(DRAG_WEP "ogre_club")->move(this_object());
  force_me("wear pants");
  force_me("wield club");
  force_me("wield club");

  set_die( (: event_die :) );

  set_property("passive", 1);
}

varargs int event_die(object ob) {
  if(!DRAG_D->query_data("canKillOgreKing")) return 1;
  if(!ob || !ob->is_player()) return 1;
  DRAG_D->ogre_king_killed(ob->query_name());
  return 1;
}

int make_attackable() {
  return remove_property("passive");
}

int make_unattackable() {
  return set_property("passive", 1);
}

mixed query_property(string str) {
  if(str == "passive" && ::query_property("passive")) {
    write("Before you can attack the ogre king, a guard rushes into the room and blocks your attack.");
    if(environment(this_object()))
      new(DRAG_MOBS"ogrekingguard")->move(environment(this_object()));
  }
  return ::query_property(str);
}
