#include <std.h>
#include <sindarii.h>

inherit ROOM;

void ball() {
    object ob;

    write("You find a crystal ball.");
    say(this_player()->query_name()+" finds a crystal ball.");
    remove_search("default");
    remove_search("tunnel");
  
   ob = new(MAG+"ball");
    if(ob->move(this_player())) {
        message("my_action", "You drop the crystal ball!", this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " drops the crystal ball!", this_object(),({this_player()}));
        ob->move(this_object());
    }
}

void create() {
    ::create();
    set_property("light", -2);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("no castle", 1);
    set("short", "Deep inside a tunnel underneath the mountains");
    set("long",
        "The tunnel of goblins comes to an end here, deep inside "
        "the evil Daroq Mountains.");
    set_exits( (["up" : ROOMS+"mountains/tunnel2"]) );
}

void reset() {
    ::reset();
    set_search("default", (: ball :));
    set_search("tunnel", (: ball :));
}
/*
void ball() {
    object ob;

    write("You find a crystal ball.");
    say(this_player()->query_name()+" finds a crystal ball.");
    remove_search("default");
    remove_search("tunnel");
    ob = new("/d/standard/obj/magic/ball");
    if(ob->move(this_player())) {
        message("my_action", "You drop the crystal ball!", this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " drops the crystal ball!", this_object(),({this_player()}));
        ob->move(this_object());
    }
}

*/
