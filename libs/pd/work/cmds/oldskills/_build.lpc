//      /bin/user/_build.c
//      ranger ability to build fires/shelter
//      created by Nightshade 11-10-01
//      shelter added by Djerr 11-12-01
#include <std.h>

inherit DAEMON;
int abil();

int cmd_build(string str) {
    if (this_player()->query_subclass() != "ranger") {
       notify_fail("What?\n");
       return 0;
    }
    if(!str && (str != "shelter") && (str != "fire")) {
        notify_fail("Build what?\n");
        return 0;
    }
    if(this_player()->query_disable()) {
        write("You are too busy doing something else!");
        return 1;
    }
    if(present("shelter",environment(this_player()))) {
        write("There is already a shelter in the room.");
        return 1;
    }
    this_player()->set_disable();
    if(str == "shelter") {
        if(present("firewood",this_player()) && present("firewood 2",this_player()) && present("sinew",this_player())) {
            write("You begin to build a shelter.");
            say(this_player()->query_cap_name()+" works feverishly on a shelter.");
            call_out("shelter",8);
            return 1;
        }

        else {
            if(!present("firewood",this_player()))
                write("You need some firewood.");
            else if(!present("firewood 2",this_player()))
                write("You need another piece of firewood.");
            else if(!present("sinew",this_player()))
                write("You do not have sinew.");
            return 1;
        }

    }
    if(!present("firewood",this_player())) {
        write("You do not have anything to start a fire with!");
        return 1;
    }
    if(present("campfire",environment(this_player()))) {
        write("There is already a campfire here!");
        return 1;
    }
    write("You begin building a fire.");
    say(this_player()->query_cap_name()+" squats and starts to build a fire.");
    this_player()->set_paralyzed(4,"You are busy building your fire.");
    call_out("fire",4);
    return 1;
}

int fire() {
    object ob;

    if(this_player()->query_skill("nature") < random(50) + 20) {
        write("A gust of wind blows out your fire before you can build it.");
        say("A slight breeze blows out "+pluralize(this_player()->query_cap_name())+" puny fire.");
        return 1;
    }
    write("Your fire spreads and catches.");
    say(pluralize(this_player()->query_cap_name())+" fire comes to life.");
    ob = new("/d/nopk/standard/obj/misc/forage/campfire");
    ob->move(environment(this_player()));
    if(present("firewood",this_player()))
      present("firewood",this_player())->remove();
    if(present("firewood",this_player()))
      present("firewood",this_player())->remove();
    return 1;
}

int shelter() {
    object ob;

    if(this_player()->query_skill("nature") < random(25) + 15) {
        write("Your poorly made shelter collapses.");
        say(pluralize(this_player()->query_cap_name())+" poorly made shelter collapses.");
        return 1;
    }
    write("You build a secure shelter.");
    say(pluralize(this_player()->query_cap_name())+" builds a secure shelter.");
    ob = new("/d/nopk/standard/obj/misc/forage/shelter");
    ob->move(environment(this_player()));
    if(present("firewood",this_player()))
      present("firewood",this_player())->remove();
    if(present("firewood",this_player()))
      present("firewood",this_player())->remove();
    if(present("sinew",this_player()))
      present("sinew",this_player())->remove();
    return 1;
}



void help() {
    write("Syntax: <build [fire\\shelter]>\n\n"
      "Rangers can build a fire to warm themselves\n"
      "and brew tea, or build a shelter for protection.\n"
    );
}
int abil() {
    if(this_player()->query_subclass() != "ranger") return 0;
    if(this_player()->query_skill("nature") < 80) return 0;
    return 1;
}
