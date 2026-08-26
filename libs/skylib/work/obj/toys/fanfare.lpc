/**
 * This is a nice brazen fanfare.
 * @author Sandoz
 */

inherit HELD_OBJ;

/** @ignore yes */
void setup() {
    set_name("fanfare");
    set_short("brass fanfare");
    add_alias("toy");
    add_plural("toys");
    add_adjective("brass");

    set_long("This is a well kept brazen fanfare, with holes on the upper "
        "side, that can be covered with fingers, to change the pitch of the "
        "sound of the instrument when blown.");

    set_weight(10);
    set_value(220);

} /* setup() */

/** @ignore yes */
int do_blow( object *obs ) {
    object *people;

    if( obs ) {
        if( sizeof(obs) > 1 ) {
            add_failed_mess("You can only $V $D at one person at a time.  "
                "Make up your mind!\n");
            return 0;
        }
        add_succeeded_mess("$N take$s a hefty lungful of breath, point$s $D "
            "at $I and blow$s into it, making $I jump in fright.\n"
            "The screeching sound echoes for a while, then slowly fades.\n",
            obs );
    } else {
        add_succeeded_mess(
            "$N take$s a hefty lungful of breath and blow$s into $D.\n"
            "The screeching sound echoes for a while, then slowly fades.\n");
    }

    if( sizeof( people = filter( users(), (: ENV($1) :)  ) ) )
        BROADCASTER->broadcast_event( people, ENV(TP)->query_co_ord(),
            "someone blows a fanfare, and the screeching sound echoes over "
            "the lands, then fades slowly.", 4000 );

    return 1;

} /* do_blow() */

/** @ignore yes */
void init() {
    add_command("blow", "<direct:object:me>", (: do_blow(0) :) );
    add_command("blow", "<direct:object:me> at <indirect:living:here>",
        (: do_blow($1) :) );
    add_command("play", "<direct:object:me>", (: do_blow(0) :) );
} /* init() */
