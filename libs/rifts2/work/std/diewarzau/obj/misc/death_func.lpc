/*
  A function to hande the death of players during guildmmaster
  challenge.

  Diewarzau 7/4/96
  DarkeLIB 0.2
*/

#include <rooms.h>
#include <daemons.h>
#define ARENA "/std/diewarzau/rooms/gm_arena"

void gm_death(object who, object att) {
  object *inv;
  object ob, jroom, gm;

  if(!att || !who) {
    return;
  }
  message("info", "%^CYAN%^You have lost your guild master position to "+
	  (string)att->query_cap_name()+"!", who);
  att->move(ROOM_START);
  who->move(ROOM_START);
  jroom = load_object("/d/damned/guilds/join_rooms/"+
		      (string)att->query_class()+
		      "_join");
  jroom->reset_master();
  ob = present("guildmaster", jroom);
  map_array(all_inventory(ob), (: call_other :), "move", att);
  gm = ob;
  ob = new(sprintf("/d/damned/guilds/%s/%s_obj",
		   (string)who->query_class(),
		   (string)who->query_class()));
  seteuid("Damned");
  ob->make_me_master(att);
  seteuid(geteuid());
  if(gm) gm->remove();
  message("info", "%^GREEN%^%^BOLD%^You are transported to the church.",
	  ({ att, who }));
  inv = filter_array(all_inventory(who), (: (arrange_string(file_name($1),
							    $2) ==
					     ("/d/damned/guilds/"+$3)) :),
		     17 + strlen((string)who->query_class()),
		     (string)who->query_class());
  map_array(inv, (: call_other :), "remove");
  who->save_player((string)who->query_name());
  ARENA->set_cip(0);
  if((ob = present("challenge soul", att))) ob->remove();
  if((ob = present("challenge soul", who))) ob->remove();
  ({ att, who })->new_body();
  ({ att, who })->heal(5000);
  DAMAGE_D->stop_cont_damage(att);
  DAMAGE_D->stop_cont_damage(who);
  ({ att, who })-> remove_paralyzed();
  ({ att, who })->set("death save", 0);
  return;
}

void other_guy(object who, object att) {
  object ob;

  if(!att || !who) return;
  ({ att, who })->move(ROOM_START);
  att->new_body();
  att->heal(5000);
  DAMAGE_D->stop_cont_damage(att);
  att-> remove_paralyzed();
  ({ att, who })->set("death save", 0);
  ARENA->set_cip(0);
  message("shout", "The DemiUrge shouts: "+(string)att->query_cap_name() +
	  " unsuccessfully challenged "+
	  (string)who->query_cap_name()+
	  " for the position of guild master of the "+
	  pluralize((string)who->query_class())+"!",
	  users());
  message("info", "%^GREEN%^%^BOLD%^You are transported to the church.",
	  ({ att, who }));
  if((ob = present("challenge soul", att))) ob->remove();
  if((ob = present("challenge soul", who))) ob->remove();
  return;
}

