//  Whit is a screwball

#include <daemons.h>
#include <std.h>
#include <guild.h>

inherit "/std/room";

void create() {
        ::create();
        set_name("Entrance to The Chosen");
        set_short("Entrance to The Chosen Guild");
        set_long("The ground here is made up of boulders piled "
                "up on each other. There are large cracks everywhere "
                "which would kill someone if they fell down. A "
                "large tree has grown in the middle of the boulders "
                "in the biggest crack of all.");
        set_exits(([
                "down":CHOSEN"hall",
                "out":"/d/nopk/tirun/wmullin1"
        ]));
        set_properties(([
                        "light":1,
                        "night light":1,
                        "no teleport":1,
        ]));
}

void init() {
        ::init();
        add_action("go_down", "down");
}

int go_down() {
        if(this_player()->query_guild() != "chosen" && !wizardp(this_player()))

{
          write("Astral winds blow preventing you from going any "
          "further into the guild.");
          say(this_player()->query_cap_name()+" is held back from entering "
                "the guild.");
          return 1;
        }
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
      notify_fail(GUILD_D->query_lock_reason());

        this_player()->move_player(CHOSEN"hall");
        return 1;
}
