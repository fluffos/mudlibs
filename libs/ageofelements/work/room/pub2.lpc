#include <mxp.h>

inherit "/lib/room";

int current_problem, starts_thinking;
object solved_by, wrong_by;
int problem_value;

void notify(string str);

void create_room() {
    set_lumens(1);

    set_brief("The local pub");

    set_description(
	"You are in the local pub. You can order drinks here.\n\n"
	"     First class beer       12 coins\n"
	"     Special of the house   50 coins\n"
	"     Firebreather          150 coins\n"
	//"     Potion of healing     200 coins\n"
      );

    add_exit("west", "/room/yard");

    add_permanent_object("/obj/level_list");
    add_permanent_object("/obj/Go/rules");

    add_transient_object( ({ "/obj/monster"
	, ({ "set_name", "player" })
	, ({ "set_alias", "go player" })
	, ({ "set_short", "Go player" })
	, ({ "set_long", sprintf("A man sitting beside a go board, concentrating \
on a %^BOLD%^%sproblem%s%^RESET%^. He looks as if he wants help. Why not look at his problem, \
and %^BOLD%^%ssay%s%^RESET%^ to him where to play?"
		, MXPTAG("send 'look at problem' HINT='look at problem'")
		, MXPTAG("/send")
		, MXPTAG("send 'say play column row' HINT='say play column row'")
		, MXPTAG("/send")
	      ) })
	, ({ "set_level", 10 })
	, ({ "set_al", 200 })
	, ({ "set_ep", 39000 })
	, ({ "set_hp", 100 })
	, ({ "set_wc", 12 })
	, ({ "set_match"
	    , this_object()
	    , ({ "got_play", "make_move" })
	    , ({ "says:", "PISS" })
	    , ({ " play", " OFF" })
	  })
	, ({ "load_chat"
	  , 1
	  , ({ "Go player says: Hm. This is tricky!\n"
	    , "Go player says: The moron who wrote this book didn't deal \
with this problem.\n"
	    , "Go player says: A throw in here should just be wasted.\n"
	    , "Go player says: This group is more alive than I am.\n"
	    , "Go player says: This is simple using oi-otoshi.\n" })
	  })
      }) );

    set_commands( ([
	"order": "order"
	, "buy": "order"
	, "look": "look"
      ]) );
}

void reset_room() {
    current_problem = 0;
    problem_value = 0;
}

int order(string str)
{
    object drink;
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what?\n");
       return 1;
    }

    if (str == "beer") {
	name = str;
	short_desc = "A bottle of beer";
	mess = "That feels good";
	heal = 0;
	value = 12;
	strength = 2;
    } else if (str == "special" || str == "special of the house") {
	name = "special";
	short_desc = "A special of the house";
	mess = "A tingling feeling goes through your body";
	heal = 10;
	value = 50;
	strength = 8;
    } else if (str == "firebreather" || str == "fire") {
	name = "firebreather";
	short_desc = "A firebreather";
	mess = "A shock wave runs through your body";
	heal = 25;
	value = 150;
	strength = 12;
#if 0
    } else if (str == "potion" || str == "potion of healing") {
	name = "potion";
	short_desc = "A potion of healing";
	mess = "You are totally healed";
	heal = 1000;
	value = 200;
	strength = 0;
#endif
    } else {
       write("What?\n");
       return 1;
    }

    if (this_player()->query_money() < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
	return 1;
    }

    drink = clone_object("obj/drink");

    if (!this_player()->add_weight(drink->query_weight())) {
	write("You can't carry more.\n");
	destruct(drink);
	return 1;
    }

    if (!drink->set_value(name + "#" + short_desc + "#" + mess +
	"#" + heal + "#" + value + "#" + strength)) {
	write("Error in creating drink.\n");
	destruct(drink);
	return 1;
    }

    drink->set_pub();
    move_object(drink, this_player());
    this_player()->add_money(- value);
    write("You pay " + value + " for a " + name + ".\n");
    say(this_player()->query_name() + " orders a " + name + ".\n");
    return 1;
}

int got_play(string str) {
    string who, what;

    if (current_problem > 2) {
	say("The go player says: I'm tired of playing for a while.\n");
	return 1;
    }

    if (sscanf(str, "%s tells you: play %s\n", who , what) == 2 ||
	sscanf(str, "%s says: play %s\n", who , what) == 2) {

	if (current_problem == 0) {
	    if (what == "b1" || what == "b 1" || what == "1b" || what == "1 b")
		solved_by = find_living(lower_case(who));
	    else
		wrong_by = find_living(lower_case(who));
	    problem_value = 50;
	}

	if (current_problem == 1) {
	    if (what == "b2" || what == "b 2" || what == "2b" || what == "2 b")
		solved_by = find_living(lower_case(who));
	    else
		wrong_by = find_living(lower_case(who));
	    problem_value = 100;
	}

	if (current_problem == 2) {
	    if (what == "d3" || what == "d 3" || what == "3d" || what == "3 d")
		 solved_by = find_living(lower_case(who));
	     else
		 wrong_by = find_living(lower_case(who));
	    problem_value = 200;
	}

	notify("The go player contemplates a proposed play.\n");
	tell_object(present("player"), "Arne PISS OFF\n");
          /* Crude way to trigger the Go players next action */
    } else if (sscanf(str, "%s tells you: %s", who, what) == 2) {
	say("The go player says: What?\n");
    }

    return 0;
}

void show_problem() {
    if (current_problem > 2) {
	write("The player looks tired.\n");
	return;
    }

    if (!present("player")) {
	return;
    }

    write("The board looks like this:\n\n");
    say(this_player()->query_name() +
	" examines the go problem.\n");
    if (current_problem == 0) {
	write("5|.......\n" +
	      "4|.......\n" +
	      "3|@@@@@..\n" +
	      "2|OOOO@..\n" +
	      "1|...O@..\n" +
	      " --------\n" +
	      "  abcdefg\n" +
	      "\nIt is black ('@') to play.\n");
	return;
    } else if (current_problem == 1) {
	write("7|.......\n" +
	      "6|.......\n" +
	      "5|@@@....\n" +
	      "4|OOO@@..\n" +
	      "3|O.OO@..\n" +
	      "2|...O@..\n" +
	      "1|..OO@..\n" +
	      " --------\n" +
	      "  abcdefg\n" +
	      "\nIt is black ('@') to play.\n");
	return;
    } else if (current_problem == 2) {
	write("5|..........\n" +
	      "4|...@@@@@..\n" +
	      "3|@@@.O...@.\n" +
	      "2|@OO@OOOO@.\n" +
	      "1|@OO.O...@.\n" +
	      " -----------\n" +
	      "  abcdefg\n" +
	      "\nIt is white ('O') to play.\n");
	return;
    } else {
	write("The go player does not want to be disturbed any more.\n");
    }
}

void make_move(string str) {
    if (solved_by) {
	say("The go player says: Right! That works!\n" +
	    "He immediately plays out a new problem.\n");
	current_problem += 1;
	tell_object(solved_by,
		    "You feel that you have gained some experience.\n");
	solved_by->add_exp(problem_value);
	solved_by = 0;
    }

    if (wrong_by) {
	say("The go player says: No, that doesn't work.\n");
	say("He sinks back into his deep thought.\n");
	wrong_by = 0;
    }
}

void notify(string str) {
    say(str);
    write(str);
}

int look(string str) {
    string what, rest;

    if (str) {
	if (!present("player")) {
	    return 0;
	}

	if (sscanf(str, "at %s", what) == 1 || sscanf(str, "%s", what) == 1) {
	    if (what == "game" || what == "problem" || what == "board") {
		show_problem();
		return 1;
	    }
	}
    }

    return 0;
}
