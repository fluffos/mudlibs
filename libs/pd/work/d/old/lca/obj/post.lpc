#include <lca.h>
#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("post");
    set_long("The old post was once used as a board.");
    set_id(({"post", "old post"}));
    set_short("an old post");
    set_prevent_get( "Your not a lumberjack!" );
}

void init() {
    ::init();
    add_action("post", "post");
}

int post() {
    message("environment", "The board has come from so much disrepair "
      "that it would be imposible to post any notes.", this_player());
    return 1;
}

