/**
 * Bing!  This is a bouncy ball.
 * @author Sandoz
 */

#include <move_failures.h>

inherit OBJECT_OBJ;

string col;

int do_throw( object *obs );

void setup() {
    set_name("ball");
    set_weight(8);
    set_value(160);
    init_dynamic_arg( ([ ]) );
} /* setup() */

void init() {
    TP->add_command("throw", TO,
        "<direct:object:me> to <indirect:living:here>", (: do_throw($1) :) );
    TP->add_command("bounce", TO, "<direct:object:me>");
} /* init() */

int do_bounce() {
    add_succeeded_mess("$N let$s $D fall, and it bounces back to $p "
        "hands.\n");
    return 1;
} /* do_bounce() */

int do_throw( object *obs ) {
    object ob;

    if( sizeof(obs) > 1 ) {
        add_failed_mess("You cannot $V $D to more than one person at a "
            "time.\n");
        return 0;
    }

    ob = obs[0];

    if( !ob->query_free_limbs() || move( ob ) != MOVE_OK ) {
        move( ENV(TP) );
        tell_object( ob, TP->the_short()+" throws "+the_short()+" to "
            "you, but you fail to catch it.\n");
        tell_room( ENV(TP), TP->the_short()+" throws "+the_short()+" to "+
            ob->the_short()+", but "+ob->HE+" fails to catch it.\n",
            ({ TP, ob }) );
        add_succeeded_mess( ({ "$N $V $D to $I, but "+ob->HE+" fails to "
            "catch it.\n", "" }), obs );
    } else {
        tell_object( ob, TP->the_short()+" throws "+the_short()+" to "
            "you and you catch it gracefully.\n");
        tell_room( ENV(TP), TP->the_short()+" throws "+the_short()+" to "+
            ob->the_short()+", who catches it gracefully.\n",
            ({ TP, ob }) );
        add_succeeded_mess(({"$N $V $D to $I, who catches it gracefully.\n",
            ""}), obs );
    }

    return 1;

} /* do_throw() */

/** @ignore yes */
mapping query_dynamic_auto_load() {
    mapping map;
    if( !clonep(TO) )
        return 0;
    map = ([ "::" : ::query_dynamic_auto_load() ]);
    if( col )
        map["col"] = col;
    return map;
} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping map ) {

    if( map["::"] )
        ::init_dynamic_arg( map["::"] );

    if( map["col"] )
        col = map["col"];

    if( !col )
        col = choice( ({ "red", "green", "blue", "yellow",
                         "orange", "colourful", "white" }) );

    set_short( col+" ball");
    add_adjective( col );
    add_alias("toy");
    add_plural("toys");

    set_long("This ball has been made out of slightly tanned animal skin, "
        "and has been painted "+( col == "colourful" ? "with a mishmash of "
        "colours" : col )+".  It is curious how they have managed to keep "
        "the air in though.\n");

} /* init_dynamic_arg() */
