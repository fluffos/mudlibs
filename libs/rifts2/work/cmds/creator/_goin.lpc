/*  /cmds/creator/_goin.c

 *  Made for DarkeMUD

 *  Created by Geldron 030396

 *  Copyright (c) 1996, DarkeMUD

 *  Do not remove this header

 */



#include <std.h>



inherit DAEMON;



int cmd_goin(string arg) {

    object ob;

    string short;



    if(!arg) {

	write("Syntax: <goin OBJ>");

	return 1;

    }

    if(present(arg, this_player()))

	ob = present(arg, this_player());

    else if(present(arg, environment(this_player())))

	ob = present(arg, environment(this_player()));

    else {

	write(arg + ": not present.");

	return 1;

    }

    short = ob->query_short();

    write("You enter " + short + ".");

    this_player()->move_player(ob);

    return 1;

}



void help() {

    write("Syntax: <goin OBJ>\n\n"

      "Enters the inventory of the target.");

}

