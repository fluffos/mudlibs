#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/convo";
inherit DRAG_ROOMS"instance";

void create() {
  instance::create();
  convo::create();
  set_short("A mysterious cave");
  set_long("The cave seems to shake and shimmer, it's impossible to see anything.");
  set_properties( ([ "indoors" : 1, "light" : 1, "mountain" : 1, "no teleport" : 1 ]) );
  set_instance_group_id("Event Test Of Courage Instance");
  set_instance_dump_area("Event Test Of Courage Instance", DRAG_ROOMS"py/dump");
}

void player_death(object ob) {
  if(!ob) return;
  ob->move(DRAG_ROOMS"py/entrance");
  ob->set_hp(-100);
  ob->die();
}

/* If either of the two below returns 0, stop processing in whatever function that called it */

int harm_player(object ob, int hp) {
  if(!ob) return 0;
  ob->add_hp(-hp);
  ob->show_status_line();
  if(ob->query_hp()<1) {
    ob->set_hp(ob->query_max_hp());
    player_death(ob);
    return 0;
  }
  return 1;
}

int set_player_hp(object ob, int hp) {
  if(!ob) return 0;
  ob->set_hp(hp);
  ob->show_status_line();
  if(hp < 1) {
    ob->set_hp(ob->query_max_hp());
    player_death(ob);
    return 0;
  }
  return 1;
}
