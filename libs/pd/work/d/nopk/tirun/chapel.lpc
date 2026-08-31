#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
  ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_exits( 
              (["south" : ROOMS"monastery"]) );
    set("short","The chapel");
    set("long", 
        sprintf("The %s chapel is solemn and ancient with stained glass "
                "windows and dark oak pews.  Most wedding ceremonies "
                "are performed here.  Type <help marriage> for "
                "information on weddings.", "Tirun") );
   set_items(
             (["pews" : "Ancient oak seats, darkened by eons of "
                 "bottoms resting on them.",
               "windows" : "The windows show highlights of "
                 "mud history, many of them gorey.",
               "ceremony" : "The ceremony is only visible when you "
                 "scroll back."]) );
}

void init() {
  object ring;
  ::init();
  if(this_player()->query_married() && !present("wedding ring",this_player())) {
    ring = new("std/obj/wed_ring");
    ring->set_me(lower_case(this_player()->query_name()));
    ring->set_spouse(lower_case(this_player()->query_married()));
    ring->move(this_player());
    write("You renew your wedding vows.");
    say(this_player()->query_cap_name()+" renews "+possessive(this_player())+" vows.");
    this_player()->force_me("wear ring");
  }
}
