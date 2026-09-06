inherit "/obj/monster";

void create_monster() {
    set_name("harry");
    set_alias("vagrant");
    set_short("Harry the affectionate");
    set_long("Harry has an agreeable look.");
    set_ac(0);
    set_level(3);
    set_al(50);
    set_ep(2283);
    set_wc(5);
    set_aggressive(0);
    set_random_pick(20);
    set_move_at_reset(0);
    load_chat(2, ({ "Harry says: What are you waiting for?\n"
	, "Harry says: Hello there!\n"
	, "Harry says: I don't like winter.\n"
	, "Harry says: I don't like snow.\n"
	, "Harry says: I don't like rain.\n"
	, "Harry says: Who are you?\n"
	, "Harry says: Why do you look like that?\n"
	, "Harry says: What are you doing here?\n"
	, "Harry says: Nice weather, isn't it?\n"
	, "Harry smiles.\n"
      }) );
    load_a_chat(20, ({ "Harry says: Don't hit me!\n",
	"Harry says: That hurt!\n",
	"Harry says: Help, someone!\n",
	"Harry says: Why can't you go bullying elsewhere?\n",
	"Harry says: Aooooo\n",
	"Harry says: I hate bashers!\n",
	"Harry says: Bastard\n",
	"Harry says: You big brute!\n",
      }) );
    set_match(this_object()
	, ({ "why_did" // action
	    , 0
	    , 0
	    , 0
	    , 0
	    , "how_does_it_feel"
	    , "smiles"
	    , "say_hello"
	    , "test_say"
	    , 0
	    , "follow"
	    , "gives"
	  })
	, ({ "sells" // type
	    , "attack"
	    , "left"
	    , "takes"
	    , "drops"
	    , "is now level"
	    , "smiles"
	    , "arrives"
	    , "says:"
	    , "tells you:"
	    , "leaves"
	    , "gives"
	  })
	, ({ 0 // match
	    , 0
	    , "the game"
	    , 0
	    , 0
	    , 0
	    , " happily."
	    , 0
	    , 0
	    , 0
	    , 0
	    , 0
	  })
      );
}

void notify(string str) {
    say(str);
    write(str);
}

void why_did(string str) {
    string who, what;
    sscanf(str, "%s %s", who, what);

    if (who == "harry" || who == "Harry") {
	return;
    }

    if (sscanf(str, "%s sells %s.\n", who, what) == 2) {
	notify("Harry says: Why did you sell " + what + "\n");
    }

    if (sscanf(str, "%s attacks %s.\n", who, what) == 2) {
	notify("Harry says: Why is " + who + " attacking " + what + "?\n");
    }

    if (sscanf(str, "%s left the game.\n", who) == 1) {
	notify("Harry says: Why did " + who + " quit the game?\n");
    }

    if (sscanf(str, "%s takes %s.\n", who, what) == 2) {
	notify("Harry says: Why did " + who + " take " + what + "?\n");
    }

    if (sscanf(str, "%s drops %s.\n", who, what) == 2) {
	notify("Harry says: Why did " + who + " drop " + what + "?\n");
    }
}

void how_does_it_feel(string str) {
    string who, what;
    sscanf(str, "%s %s", who, what);

    if (who == "harry" || who == "Harry") {
	return;
    }

    if (sscanf(str, "%s is now level %s.\n", who, what) == 2) {
	notify("Harry says: How does it feel, being of level " + what +
	       "?\n");
    }
}

void smiles(string str) {
    string who, what;
    sscanf(str, "%s %s", who, what);

    if (who == "harry" || who == "Harry") {
	return;
    }

    if (sscanf(str, "%s smiles happily.", who) == 1 &&
	who != "Harry") {
	notify("Harry smiles happily.\n");
    }
}

void say_hello(string str) {
    string who;

    if (sscanf(str, "%s arrives.", who) == 1) {
	notify( "Harry says: Hi " + who + ", nice to see you !\n");
    }
}

void test_say(string str) {
    string a, b, message;
    sscanf(str, "%s %s", a, b);

    if (a == "harry" || a == "Harry") {
	return;
    }

    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
	return;
    }

    str = b;

    if (str == "hello" || str == "hi" || str == "hello everybody") {
	message = "Harry says: Pleased to meet you!\n";
    }

    if (str == "shut up") {
	message = "Harry says: Why do you want me to shut up ?\n";
    }

    if (sscanf(str, "%sstay here%s", a, b) == 2 ||
	sscanf(str, "%snot follow%s", a, b) == 2 ||
	sscanf(str, "%sget lost%s", a, b) == 2) {
	message = "Harry says: Ok then.\n";
    }

    if (!message) {
	message = "Harry says: Why do you say '" + str + "'???\n";
    }

    notify(message);
}

void follow(string str) {
    string who, where;

    if (sscanf(str, "%s leaves %s.\n", who, where) == 2) {
	init_command(where);
    }
}

void gives(string str) {
    string who, what, whom;
    int rand;
    object obj, next_obj;

    if (sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3) {
	return;
    }

    if (whom != "Harry") {
	return;
    }

    if (what == "firebreather" || what == "special" ||
       what == "beer" || what == "bottle") {
	rand = random(4);

	if (rand == 0) {
	    if (random(10) > 6) {
		notify("Harry sighs and says: I guess you're gonna kill me now.\n");

		obj = first_inventory(this_object());

		while (obj) {
		    next_obj = next_inventory(this_object());
		    transfer(obj, environment(this_object()));
		    notify("Harry drops " + obj->short() + ".\n");
		    obj = next_obj;
		}

		init_command("west");
	    }
	}

	if (rand == 1) {
	    init_command("drink " + what);
	}

	if (rand == 2) {
	    obj = first_inventory(this_object());

	    while (!obj->id(what)) {
		obj = next_inventory(obj);
	    }

	    transfer(obj, environment(this_object()));
	    notify("Harry drops the " + what + ".\n");
	}

	if (rand == 3) {
	    obj = first_inventory(this_object());

	    while (!obj->id(what)) {
		obj = next_inventory(obj);
	    }

	    transfer(obj, find_living(lower_case(who)));
	    notify("Harry returned the " + what + " to " + who + ".\n");
	}
    } else if (what == "corpse") {
	notify("Harry says: HEY, bury your corpses yourself, asshole.\n");

	obj = first_inventory(this_object());

	while (!obj->id(what)) {
	    obj = next_inventory(obj);
	}

	transfer(obj, find_living(lower_case(who)));
	notify("Harry returned the " + what + " to " + who + ".\n");
    } else {
	notify("Harry says: Thank you very much, sir.\n");
    }
}

void monster_died() {
    object obj, b;
    int num;

    obj = first_inventory(this_object());

    while (obj) {
	b = next_inventory(this_object());

	if (obj->id("bottle")) {
	    destruct(obj);
	    num = 1;
	}

	obj = b;
    }

    if (num) {
	notify("There is a crushing sound of bottles breaking, as the body falls.\n");
    }
}
