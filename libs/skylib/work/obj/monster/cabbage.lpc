inherit NPC_OBJ;

#include <config.h>
#include <move_failures.h>

void check_env();
void zap_cabbage();
string long_desc();

int eaten;
string owned;
object my_owner;

void setup() {
    set_name("cabbage");
    set_long( "A small cute looking cabbage.\n" );
    basic_setup("cabbage", 1, 0 );

    add_respond_to_with( ({ ({ "@hug", "@snuggle", "@cuddle", "@nestle", }),
        query_name() }), "#respond_nice");

    add_respond_to_with( ({ ({ "@skick", "@spunch", "@sburn", "@jump", }),
        query_name() }), "#respond_nasty");

} /* setup() */

void set_owner( object thing ) {

    if (!objectp( thing ) )
        return;
    set_long( (: long_desc :) );
    owned = thing->query_name();    
    my_owner = thing;

    load_chat(30, ({
        1, "@roll up",
        1, "@purr",
        1, ":$V$0=ruffles its,ruffle their$V$ fronds.",
        1, ":$V$0=looks,look$V$ green.",
        1, "@snuggle " + owned,
        1, "@stare dre at " + owned,
        1, "@nestle " + owned,
        1, "@roll over" }) );

    check_env();
} /* set_owner() */

string long_desc() {
    if ( my_owner && environment( my_owner ) == environment() ) {
        return "This small, cute-looking cabbage stares adoringly at " +
        my_owner->one_short() + ".\n";
    }

    return "This small, cute-looking cabbage is looking off into the "
    "distance.  It is obviously hopelessly lost.\n";
} /* long_desc() */

void respond_nice( object souler ) {

    if ( my_owner && souler == my_owner) {
        init_command("nestle "+ file_name( souler ) );
    } 
    else {
        init_command("peer curiously "+ file_name( souler ) );
    }
} /* respond_nice() */

void respond_nasty( object souler ) {
    if ( my_owner && souler == my_owner) {
        init_command("gasp");
        init_command("cry", 2);
    } 
    else {
        init_command( "sburn " + file_name( souler ) + " dream");
    }
} /* respond_nasty() */

void init() {
    ::init();

    this_player()->add_command("eat", this_object(), "<direct:object'cabbage'>" );    

    if ( owned && !my_owner ) {
        do_command( "cry" );
        do_command( "'Woe is me! Where art thou, " + capitalize( owned ) + "?" );
        call_out( (: zap_cabbage :), 1 );
        return;
    }

} /* init() */

int do_eat() {
    if ( this_player() != my_owner || eaten) {
        this_player()->add_failed_mess( this_object(), "You cannot eat this "
          "cabbage!\n" );
        return -1;
    }


    this_player()->add_succeeded_mess( this_object(), 
      ({ "The cabbage lovingly and "
        "adoringly purrs quietly as you viciously rip off its fronds and "
        "eat it.  It dies looking wonderingly into your face.\n", 
        "$N $V $D.\n" }) );
    call_out( (: zap_cabbage :), 2 );
    return 1;
} /* do_eat() */


void zap_cabbage() {        
    if ( environment() ) {
        all_inventory()->move( environment() );
    }

    if ( my_owner ) {
        do_command( "unfollow " + file_name( my_owner ) );
    }

    eaten = 1;
    my_owner = 0;
    owned = 0;
    move( "/room/rubbish" );
} /* zap_cabbage() */

int attack_by(object ob) {
    ob->stop_fight(this_object());
    tell_object(ob, "The cabbage is a terrible pacifist.\n");
} /* attack_by() */

int attack_ob(object ob) {
    ob->stop_fight(this_object());
    tell_object(ob, "The cabbage is a terrible pacifist.\n");
} /* attack_by() */

int adjust_hp(int number, object attacker) {
    return 0;
} /* adjust_hp() */

void event_exit(object ob, string mess, object to) {
    call_out( (: check_env :), 10 );
    ::event_exit( ob, mess, to);
} /* event_exit() */

void event_dest_me(object ob) {
    call_out( (: check_env :), 1 );
} /* check_env() */

void check_env() {
    object my_env, owner_env, *caterpillars;

    if ( !owned )
        return;

    my_env = environment();
    if ( !my_env ) {
        return;
    }

    if ( !my_owner ) {
        do_command( "cry" );
        zap_cabbage();
        return;
    }

    owner_env = environment( my_owner );
    if ( !owner_env ) {
        return;
    }

    if ( file_name( my_env ) == "/room/rubbish" ) {
        return;
    }

    if ( this_object()->query_property( "dead" ) ) {
        return;
    }

    if (my_env == my_owner) {
        return ;
    }

    if (owner_env == my_env) {
        return ;
    }

    if (owner_env->query_mirror_room() == my_env) {
        return ;
    }

    caterpillars = match_objects_for_existence( "caterpillar", ({ owner_env }) );

    if ( my_env != owner_env && !sizeof(caterpillars)) {
        move( owner_env, "$N appear$s with a squelch.",
          "$N disappear$s with a squelch." );
        do_command( "follow " + file_name( my_owner ) );
    }

} /* check_env() */

object query_owner() { 
    return my_owner; 
} /* query_owner() */

/*
 * On Cabbage Day, we need to be moved out of a player's inventory.
 */
int query_theft_command() {
    return -1;
} /* query_theft_command() */

int move(object dest, string mess1, string mess2) {
    int ret;

    ret = ::move(dest, mess1, mess2);
    if (ret == MOVE_OK) {
        call_out((: check_env :), 10);
    }
    return ret;
} /* move() */
