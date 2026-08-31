inherit MONSTER;

create() {
    ::create();
    set_name("halfling");
    set_id( ({ "halfling" }) );
    set_short("A critically wounded halfling");
    set_level(1);
    set_long("This halfling warrior's life hangs by a thread. Unless tended quickly, he will surely bleed to death. Even so, he will not be in any condition to speak for several days.");
    set_gender("male");
    set_alignment(700);
    set("race", "halfling");
    set_hp(1);
    add_money("gold", random(20));
    set_body_type("human");
    set_die( (: call_other, this_object(), "death_func":) );

}

int death_func() {
    message("say", "The wounded halfling is no match for the likes of you and is quickly dispatched.", environment(this_object()));
    return 1;
}

void catch_tell(string str) {
    string a, b;

    if(this_player() != this_object())
    {

	if(sscanf(str, "%sdrow%s", a, b) == 2) {
	    this_object()->force_me("speak D... dr-ow... aah... s-south...");
	    return 1;
	}

	if(sscanf(str, "%shalfling%s", a, b) == 2) {
	    this_object()->force_me("speak Oooooohhhhhh.... to the south...");
	    return 1;
	}

	if(sscanf(str, "%sheal%s", a, b) == 2 || sscanf(str, "%shelp%s", a,b) == 2) {
	    this_object()->force_me("say Mmweph... it hur..ts...");
	    return 1;
	}
    }

}
