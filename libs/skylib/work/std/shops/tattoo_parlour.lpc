/**
 * This is the basic tattoo parlour inherit.
 * To use the inherit, you need to assign a tattooist NPC object to
 * the 'keeper' variable, and deal with the cloning and checking for
 * his/her existance each reset, etc.
 * @see set_tattoo_cost()
 * @see set_remove_cost()
 * @see /std/effects/other/tattoo
 * @see /std/npcs/tattooist
 * @author Shiannar, 14/10/01, inheritized by Sandoz, 2002.
 */

#define TATTOO      EFFECTS_DIR "/other/tattoo"

#define TATTOO_COST 72000  // Default cost is 12 platinum coins.
#define REMOVE_COST 144000 // Removal cost is 24 platinum coins.
#define QMS(x)      query_multiple_short( x, "poss", 1 ) // 1st person.

inherit ROOM_OBJ;

string place;
object keeper;
int tattoo_cost, remove_cost;

void create() {
    remove_cost = REMOVE_COST;
    ::create();
    add_help_file("tattoo_parlour");
} /* create() */

/**
 * This method sets the cost of a single tattoo.
 * @param cost the cost of a single tattoo
 */
void set_tattoo_cost( int cost ) { tattoo_cost = cost; }

/**
 * This method returns the cost of a tattoo in this parlour.
 * @return the cost of a tattoo in this parlour
 */
int query_tattoo_cost() { return tattoo_cost || TATTOO_COST; }

/**
 * This method sets the cost of tattoo removal in this parlour.
 * If set to 0, then no removal services are offered.
 * @param cost the tattoo removal cost, if 0, no removal is offered
 */
void set_remove_cost( int cost ) { remove_cost = cost; }

/**
 * This method returns the tattoo removal cost in this parlour.
 * @return the tattoo removal cost
 */
int query_remove_cost() { return remove_cost; }

/**
 * This method sets the monetary area of the parlour.
 * This is used to decide which currency to accept here.
 * @param str the place to set
 */
void set_place( string str ) { place = str; }

/**
 * This method returns the place name to use for currency calculations.
 * @return the monetary area this parlour is in
 */
string query_place() { return place || "default"; }

/**
 * This method returns all the tattooable bodyparts.
 * @return all the tattooable bodyparts
 */
string *query_tattooables() { return TATTOO->query_tattooables(); }

int check_keeper() {
    return ( keeper && ENV(keeper) == TO );
} /* check_keeper() */

/** @ignore yes */
int do_request( string tattoo, string bodypart ) {
    object *obs;

    if( !check_keeper() ) {
        add_succeeded_mess( ({
            "The tattoo artist is not here to serve you!\n",
            "$N look$s around and blink$s.\n"}) );
        return 1;
    }

    tell_object( TP, "You enquire about getting a tattoo.\n");
    tell_room( TO, TP->the_short()+" $V$0=enquires,enquire$V$ about getting "
        "a tattoo done.\n", TP );

    if( keeper->query_busy() ) {
        keeper->do_command("sayto "+TP->query_name()+" I'm busy right "
                "now, you can go next.");
        return notify_fail("");
    }

    if( !TATTOO->query_tattooable( bodypart ) ) {
        keeper->do_command("sayto "+TP->query_name()+" I'm sorry, but I "
            "cannot tattoo your \""+bodypart+"\".  Please read the sign "
            "for the list of available bodyparts.");
        return notify_fail("");
    }

    if( sizeof( obs = TATTOO->query_tattoo_covered( TP, bodypart ) ) ) {
        keeper->do_command("sayto "+TP->query_name()+" I'm afraid you are "
            "going to have to remove "+QMS(obs)+" before I can help you.");
        return notify_fail("");
    }

    if( lower_case(tattoo) == "tattoo") {
        keeper->do_command("sayto "+TP->query_name()+" I know you want a "
            "tattoo, but I need to know more details.");
        return notify_fail("");
    }

    if( TP->query_value_in( query_place() ) < tattoo_cost ) {
        keeper->do_command("sayto "+TP->query_name()+" I'm sorry, "+
            TP->short()+", but you need "+MONEY_H->money_value_string(
            query_tattoo_cost(), query_place() )+" or the same in change to "
            "get a tattoo.");
        return notify_fail("");
    }

    TP->pay_money( MONEY_H->create_money_array( query_tattoo_cost(),
        query_place() ), query_place() );

    add_succeeded_mess("");

    return keeper->do_tattoo( TP, tattoo, bodypart );

} /* do_request() */

/** @ignore yes */
int do_remove( string bodypart ) {
    object *obs;
    int *effs;

    if( !check_keeper() ) {
        add_succeeded_mess( ({
            "The tattoo artist is not here to serve you!\n",
            "$N look$s around and blink$s.\n"}) );
        return 1;
    }

    tell_object( TP, "You enquire about getting a tattoo removed.\n");
    tell_room( TO, TP->the_short()+" $V$0=enquires,enquire$V$ about getting "
        "a tattoo removed.\n", TP );

    if( keeper->query_busy() ) {
        keeper->do_command("sayto "+TP->query_name()+" I'm busy right now, "
                "you can go next.");
        return notify_fail("");
    }

    if( !TATTOO->query_tattooable( bodypart ) ) {
        keeper->do_command("peer "+TP->query_name()+" carefully");
        keeper->do_command("sayto "+TP->query_name()+" I'm sorry, but \""+
                bodypart+"\" is a bodypart I have never heard of before.");
        return notify_fail("");
    }

    if( sizeof( obs = TATTOO->query_tattoo_covered( TP, bodypart ) ) ) {
        keeper->do_command("sayto "+TP->query_name()+" I'm afraid you are "
            "going to have to remove "+QMS(obs)+" before I can help you.");
        return notify_fail("");
    }

    if( !sizeof( effs = TP->effects_matching("body.tattoo") ) ) {
        keeper->do_command("'Hrmm.  It would appear you're not tattooed.");
        return notify_fail("");
    }

    if( undefinedp( TP->arg_of( effs[0] )[bodypart] ) ) {
        keeper->do_command("'Hrmm.  It would appear you have no tattoos "+
            TATTOO->expand_tattooable( bodypart, "your")+".");
        return notify_fail("");
    }

    if( TP->query_value_in( query_place() ) < query_remove_cost() ) {
        keeper->do_command("sayto "+TP->query_name()+" I'm sorry, "+
            TP->short()+", but you need "+MONEY_H->money_value_string(
            query_remove_cost(), query_place() )+" or the same in change to "
            "get a tattoo removed.");
        return notify_fail("");
    }

    TP->pay_money( MONEY_H->create_money_array( query_remove_cost(),
        query_place() ), query_place() );

    add_succeeded_mess("");

    return keeper->do_remove( TP, bodypart );

} /* do_remove() */

/** @ignore yes */
void init() {
    ::init();
    add_command("request", "<string'tattoo'> on [my] <string'bodypart'>",
        (: do_request( $4[0], $4[1] ) :) );
    if( remove_cost )
        add_command("remove", "tattoos {on|from} [my] <string'bodypart'>",
            (: do_remove( $4[1] ) :) );
} /* init() */

/** @ignore yes */
mixed stats() {
    return ::stats() + ({
        ({"tattoo cost", tattoo_cost }),
        ({"removal cost", remove_cost }),
        ({"no removal", !remove_cost }),
        ({"place", query_place() }),
        ({"keeper", keeper }),
    });
} /* stats() */
