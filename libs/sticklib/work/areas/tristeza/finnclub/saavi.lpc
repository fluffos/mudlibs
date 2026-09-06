
id(str) { return str == "saavi" || str == "bucket" || str == "sauna_saavi"; }

reset(arg) { }

short() { return "a 'saavi' rests on the floor here"; }

long(arg) {
    write(
      "'Saavi' means a bucket. This bucket is a traditional one made of wood.\n"+
      "This one is rather special: it's always magically full of water.\n");
}

init() {
    add_action("throw","throw");
    add_action("throw","heit{");
    add_action("throw","heita");
}

int lc;

throw(arg) {
    string mita, minne;

    if (!arg) {
	notify_fail("What did you want to " + query_verb() + "?\n");
	return 0;
    }

    notify_fail("What's the point in throwing " + arg + "?\n");

    arg = lower_case(arg);

    if (arg != "l|yly{" && arg != "loylya" &&
      arg != "vett{" && arg != "vetta") {
	if (sscanf(arg, "%s to %s", mita, minne) != 2 &&
	  sscanf(arg, "%s on %s", mita, minne) != 2)
	    return 0;
	if (minne != "kiuas" && minne != "stove") return 0;
	if (mita != "water") {
	    notify_fail(
	      "The warning nymph tells you: You cannot throw " + mita + " on our kiuas!\n");
	    return 0;
	}
    }

    if (!present("sauna_kauha",this_player())) {
	notify_fail("You are not holding the kauha.\n");
	return 0;
    }

    if (lc) {
	write(
	  "The warning nymph tells you: Relax, there is no hurry, take it easy...\n");
	return 1;
    }

    lc = 1;

    write("Ok. The water evaporates with a loud hiss!\n");
    say(this_player()->query_name() + " throws water on the kiuas!\n"+
      "The water immediately evaporates with a loud hiss!\n");

    call_out("loyly",1);
    return 1;
}

loyly() {
    object *inv;
    int i, tem;

    lc = 0;

    tell_room(environment(),
      "The room is filled by l|yly (in english, steam)!\n"+
      "It's getting hot in here!\n");

    /* Steam doesn't warm the sauna much in real life...
       but this is fantasy! */

    tem = environment()->query_celcius();
    tem += (3 + random(7));

    /* Restore low temperature after a loyly competition */
    if (tem > 165) {
	tell_room(environment(),
	  "The warning nymph arrives in a puff of smoke and says: 'Hey, this place\n"+
	  "is hot!' Then she says a few magical words and the sauna cools. The\n"+
	  "nypmh waves happily and disappears.\n");

	tem = 60 + random(40);
	environment()->set_celcius(tem);

	tell_room(environment(),
	  "The temperature is now just a freezing " + tem + " degrees celcius.\n");
	return;
    }

    environment()->set_celcius(tem);

    inv = all_inventory(environment());

    for (i = 0; i < sizeof(inv); i++) {
	if (inv[i]->query_coder_level() ||
	  inv[i]->query_level() >= (random(tem / 6)))
	    tell_object(inv[i],
	      "But the " + tem + " degrees celcius just makes you feel even better!\n");
	else {
	    tell_object(inv[i],
	      "You CAN'T STAND IT any more! The Heat! Arghh! Flee! (Chicken!!!)\n");
	    inv[i]->run_away();
	}
    }
}
