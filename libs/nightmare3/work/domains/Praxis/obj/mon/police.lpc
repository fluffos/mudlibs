#include <std.h>
#include <rooms.h>

inherit MONSTER;

private object __Target;

void go_home();

void init() {
    monster::init();
    add_action("cmd_surrender", "surrender");
}

void heart_beat() {
    if(!__Target || (int)__Target->query_ghost()) go_home();
    monster::heart_beat();
    if(__Target && environment(__Target) != environment(this_object()))
      go_home();
}

void set_target(object ob) {
    if(!ob) return;
    __Target = ob;
    move(environment(ob));
    ob->add_follower(this_object());
    command("kill "+(string)ob->query_name());
}

void go_home() {
    __Target = 0;
    move(ROOM_SHERIFF);
}

protected int cmd_surrender(string unused) {
    if(this_player() != __Target) return 0;
    this_player()->cease_all_attacks();
    this_player()->move(ROOM_SHERIFF);
    ROOM_SHERIFF->add_prisoner(this_player());
    go_home();
    return 1;
}
