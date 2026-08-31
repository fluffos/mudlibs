#include <std.h>
#include <dragonevent.h>
inherit MONSTER;

int event_die(object ob);
object enemy;
object init_room;
int stayAlive;

void create() {
  ::create();
  set_name("ogre guard");
  set_id( ({ "ogre", "ogre king guard", "ogre guard", "guard" }) );
  set_level(40+random(6));
  set_short("ogre king guard");
  set_long("One of the Ogre King's personal guards. He looks like any other guard, but he would defend his lord the king to the death, no matter what the cost.");
  set_race( "ogre" ); 
  set_gender( "male" );
  set_body_type("ogre");
  set_spells( ({ "headbutt", "jab", "shimmer", "whirl", "shadowburst", "razorlash" }) );
  set_spell_chance(30); 
  set_class("fighter");
  set_subclass("antipaladin");
  set_skill("attack", 240);
  set_alignment(-1200);
  set_aggressive(5000);
  new(DRAG_ARM "ogre_pants")->move(this_object());
  new(DRAG_WEP "ogre_club")->move(this_object());
  new(DRAG_WEP "ogre_club")->move(this_object());
  force_me("wear pants");
  force_me("wield club");
  force_me("wield club");

  set_heart_beat(1);
  set_die( (: event_die :) );
  stayAlive = 0;
}

int event_die(object ob) {
  if(!ob) ob = this_player();
  if(ob->is_player())
    DRAG_D->ogre_killed(ob->query_name());
  return 1;
}

void init() {
  ::init();
  if(enemy) return;
  if(!this_player()->is_player()) return;
  if(this_player()->query_property("passive")) return;
  enemy = this_player();
  init_room = environment(this_object());
}

void heart_beat() {
  ::heart_beat();
  if(!this_object()) return;
  if(!enemy) return;
  if(!present(enemy, environment(this_object())))
  {
    if(environment(enemy)->query_instance_group_id() != "Ogre King Throne Instance") {
      if(!stayAlive) {
        this_object()->remove();
        return;
      }
      enemy = 0;
      if(init_room) this_object()->move(init_room);
      return;
    }
    this_object()->move(environment(enemy));
    message("info", "Ogre guard comes running into the room.", environment(this_object()));
  }
}

void make_permanent() { stayAlive = 1; }
