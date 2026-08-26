/**
 * Drinks Cart
 * For all those thirsty creators
 *
 * Created by Mahray,  11/04/01
 * Updated 26/03/02 (rather late) so it works again
 * Fixed up and moved to /std/objects.c - Sandoz, Sept. 2002.
 */

inherit NPC_OBJ;

void setup() {
    set_name("cart");
    set_short("drinks cart");
    add_adjective("drinks");

    set_long("This seems to be an animated drinks cart.  Perhaps if you "
        "talk to it, you might be able to obtain a drink.\n");

    basic_setup("human", 25, "neuter");

    load_chat( 10, ({
        1, "'Oh go on... Order a drink!",
        1, "'Some milk perhaps?  Or tea?",
        1, "'You must be thirsty from all this coding, come on, "
           "let me serve you something!",
        1, ":spills some milk on $lpossshort$ lap.",
      }));

    add_respond_to_with( ({ ({"drink", "drinks"}) }), ({
        "'Would you like a drink?",
        "'Tea, coffee, coke, and milk are available.",
        "'Just name one."
        }) );

    add_respond_to_with( ({"tea"}), "#do_tea");
    add_respond_to_with( ({"coffee"}), "#do_coffee");
    add_respond_to_with( ({"coke"}), "#do_coke");
    add_respond_to_with( ({"milk"}), "#do_milk");
    add_respond_to_with( ({"@pat"}), "purr $hcname$");

} /* setup() */

object make_cup( int vol ) {
    object cup;

    cup = clone_object(VESSEL_OBJ);
    cup->set_name("cup");
    cup->set_max_volume(vol);

    return cup;

} /* make_cup() */

void do_tea( object person ) {
    object cup, drink;

    cup = make_cup( 750 );
    cup->set_short("tea cup");
    cup->add_adjective("tea");
    cup->set_long("This is a well made porcelin tea cup, complete with a "
        "saucer.\n");

    drink = clone_object(LIQUID_OBJ);
    drink->set_name("tea");
    drink->set_short("tea");
    drink->medium_alias("Tea");
    drink->set_long("This is the calming drink known to everyone, tea.\n");
    drink->add_eat_effect("/std/effects/ingested/calm", 60 );
    drink->set_amount( 750 );
    drink->move(cup);

    if( cup->move(person) ) {
        do_command("'Bugger, you are too burdened to accept a cup of tea.");
        cup->dest_me();
    } else {
        do_command("'There you are, "+person->query_gender_title()+", a cup "
            "of tea.");
    }

} /* do_tea() */

void do_coffee( object person ) {
    object cup, drink;

    cup = make_cup( 750 );
    cup->set_short("coffee cup");
    cup->add_adjective("coffee");
    cup->set_long("This is a well made porcelin coffee cup, complete with a "
        "saucer.\n");

    drink = clone_object(LIQUID_OBJ);
    drink->set_name("coffee");
    drink->set_short("coffee");
    drink->medium_alias("CoffeE");
    drink->set_long("This is your average cup of coffee.  Hot and strong.\n");
    drink->add_eat_effect("/std/effects/ingested/sugar", 60 );
    drink->set_amount( 750 );
    drink->move(cup);

    if( cup->move(person) ) {
        do_command("'Bugger, you are too burdened to accept a cup of "
            "coffee.");
        cup->dest_me();
    } else {
        do_command("'There you are, "+person->query_gender_title()+", a cup "
            "of coffee.");
    }

} /* do_coffee() */

void do_coke( object person ) {
    object cup, drink;

    cup = make_cup( 950 );
    cup->set_short("coke cup");
    cup->add_adjective("coke");
    cup->set_long("This cup is tall and made of glass.\n");

    drink = clone_object(LIQUID_OBJ);
    drink->set_name("coke");
    drink->set_short("coke");
    drink->medium_alias("cOkE");
    drink->set_long("Black, fizzy, and full of sugar and caffeine, coke "
        "is a popular drink.\n");
    drink->add_eat_effect("/std/effects/ingested/caffeine", 60 );
    drink->set_amount( 950 );
    drink->move(cup);

    if( cup->move(person) ) {
        do_command("'Bugger, you are too burdened to accept a cup of "
            "coke.");
        cup->dest_me();
    } else {
        do_command("'There you are, "+person->query_gender_title()+", a cup "
            "of coke.");
    }

} /* do_coke() */

void do_milk( object person ) {
    object cup, drink;

    cup = make_cup( 960 );
    cup->set_short("milk cup");
    cup->add_adjective("milk");
    cup->set_long("This is a tall and cold glass.\n");

    drink = clone_object(LIQUID_OBJ);
    drink->set_name("milk");
    drink->set_short("milk");
    drink->medium_alias("MiLk");
    drink->set_long("This is plain old milk.  Smooth and white.\n");
    drink->set_amount( 960 );
    drink->move(cup);

    if( cup->move(person) ) {
        do_command("'Bugger, you are too burdened to accept a cup of "
            "milk.");
        cup->dest_me();
    } else {
        do_command("'There you are, "+person->query_gender_title()+", a cup "
            "of milk.");
    }

} /* do_milk() */

/** @ignore yes */
int attack_by( object thing ) {
    tell_object( thing, "Awww, come on.  Leave the poor cart alone.\n");
    thing->stop_fight(TO);
    return 0;
} /* attack_by() */

/** @ignore yes */
varargs void run_away( int dummy ) { return; }

/** @ignore yes */
void adjust_hp( int num, object who, object wep, string att ) { return; }
