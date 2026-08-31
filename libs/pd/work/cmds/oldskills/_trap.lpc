//    Ranger traps.
//    By Nightshade.
 
#include <std.h>
inherit DAEMON;
int abil();
 
int cmd_trap(string str) {

    if (!abil()) {
        return 0;
    }
    if(this_player()->query_ghost()) {
        notify_fail("You won't be able to do much in that form.\n");
        return 0;
    }
    if (this_player()->query_disable()) {
        write("You are too busy to set a trap.");
        return 1;
    }
    if(environment(this_player())->query_property("no attack")) {
        notify_fail("Greater powers prevent your malice.\n");
        return 0;
    }
    if(strsrch(base_name(environment(this_player())), "/d/tirun") != -1) {
        notify_fail("You wouldn't dare set a trap in town!\n");
        return 0;
    }
    if((int)this_player()->query_sp() < 20) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    if(present("ranger_trap_id", environment(this_player()))) {
        notify_fail("This room is already trapped!\n");
        return 0;
    }
    if(!present("firewood 2", this_player())) {
        notify_fail("You do not have enough wood to build a trap.\n");
        return 0;
    }
    if(!present("sinew 3", this_player())) {
        notify_fail("You do not have enough sinew to build a trap.\n");
        return 0;
    }
    present("sinew", this_player())->remove();
    present("sinew", this_player())->remove();
    present("sinew", this_player())->remove();
    present("firewood", this_player())->remove();
    present("firewood", this_player())->remove();
    write("You deftly set up a trap in the room.");
    this_player()->set_paralyzed(2, "You are busy with the trap.");
    new("/d/standard/obj/magic/trap")->move(environment(this_player()));
    present("ranger_trap_id", environment(this_player()))->set_skill(this_player()->query_skill("nature"));
    this_player()->add_skill_points("nature", random(this_player()->query_skill("nature")/10)+random(10));
    return 1;
}

void help() {
   write("Syntax: <trap>\n\n"
      "Rangers can set traps within a room, catching their victims off guard.");
}

int abil() {
   object r;
   r = this_player();
   if (!r) return 0;
   if (r->query_subclass() == "ranger"  && r->query_level() >= 13) return 1;
   else return 0;
}
