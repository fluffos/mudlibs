/*  /cmds/hm/_wordcurse.c

 *  Made for DarkeMUD

 *  Created by Geldron 031096

 *  Copyright (c) 1996, DarkeMUD

 *  Do not remove this header

 */





inherit DAEMON;



int cmd_wordcurse(string arg) {

    object ob;



    if(!arg) {

	message("word_curse", syntax("wordcurse LIV"), TP);

	return 1;

    }

    ob = present(arg, ENV(TP));

    if(!ob) {

	message("word_curse", arg + ": not found.", TP);

	return 1;

    }

    if(TP->query_ppe() < 400) {

	message("word_curse", "You do not have enough mp.", TP);

	return 1;

    }

    TP->add_mp(-400);

    message("word_curse", "You word curse " + ob->query_cap_name() + "!", TP);

    message("word_curse", "Things suddenly turn fuzzy...", ob);

    new("/std/obj/curses/word_curse")->sh_init(ob);

    return 1;

}



void help() {

    message("word_curse_help", syntax("wordcurse LIV") + "\n\n"

      "MaKeS thiNgS lOoK fuNkY.  Only temporary and costs 400 mp.", TP);

}

