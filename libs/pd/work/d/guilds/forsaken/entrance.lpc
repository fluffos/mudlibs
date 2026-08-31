#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "light" : 2, "no teleport":1, "indoors":1, "no bump":1])
);
    set_name("Entrance of the Forsaken guild");
    set_long("The room is narrow and made of solid black stone polished to "
      "reflect objects like thousands of tiny mirrors. The cold and dank air feel "
      "like that of the air from a cave deep underground. There is a large obsidian "
      "archway to the north. The only other feature in the room is a large blue "
      "fire that burns off of the stone itself.");
    set_items(([
        "fire" : "The coldfire seems to beckon you to enter.",
      ]));
    set_exits(([
        "out" : "/d/nopk/tirun/efallor1",
      ]));
}
void init() {
    ::init();
    add_action("go_fire", "fire");
}
int go_fire() {
    if(this_player()->query_guild()!="forsaken" && !wizardp(this_player())) {
        write("You are burnt by the fire.\n");
        say(this_player()->query_cap_name()+" is burnt by the fire.");
        this_player()->add_hp(-10);
        return 1;
    }
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
        notify_fail(GUILD_D->query_lock_reason());

    write("The fire doesnt hurt as you enter it.");
    say(this_player()->query_cap_name()+" enters the fire and disappears.");
    this_player()->move_player(ROOMS"forsaken/hall");
    return 1;
}
