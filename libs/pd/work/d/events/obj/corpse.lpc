//  Whit

#include <std.h>
#include <event.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("corpse");
    set_short("the corpse of a young adventurer");
    set_long("This is the dead corpse of a small adventurer.");
    set_prevent_get("You may not take the corpse.");
    set_id(({ "corpse" }));
}

void init() {
    ::init();
    add_action("sac", "sacrifice");
}

int sac(string str) {
    object ob;

    if(str != "corpse") return 0;
    write("Apon sacrificing the corpse you see something laying under it.\n");
    say(this_player()->query_cap_name()+" sacrifices the corpse.\n");
    say("You happen to see something laying under the corpse.\n");
    new(OBJ"journal")->move(environment(this_object()));
    ob = new(MON"messenger");
    ob->move(environment(this_object()));
    ob->start_corpse();
    this_object()->move("/wizards/whit/workroom");
    return 1;
}

