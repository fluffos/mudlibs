
#define __MONEY_CLASS__
#define EFF "/handlers/mag_eff_handler"

#include <money.h>

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( object *things ) {
    int *effect;
    object place;
    mixed stuff;

    if( sizeof(things) > 1 ) {
        add_failed_mess("You can only flip one thing at once.\n");
        return 0;
    }

    if( !sizeof( stuff = things[ 0 ]->query_money_array() ) ) {
        add_failed_mess("You must have a coin to flip.\n");
        return 0;
    }

    if( sizeof(stuff) > 2 || stuff[ 1 ] != 1 ) {
        add_failed_mess("You can only flip one coin at a time.\n");
        return 0;
    }

    place = ENV(TP);

    tell_object( TP, "You flip "+things[ 0 ]->the_short()+".\n");
    tell_room( place, TP->one_short()+" flips "+things[ 0 ]->a_short()+".\n",
        ({ TP }) );

    effect = EFF->choose_effect( EFF->ambient_enchantment( things[ 0 ] ) );

    if( random( 1000 ) < effect[ 0 ] ) {
        switch( effect[ 1 ] ) {
          case 0 :
            things[ 0 ]->move( place );
            tell_room( place, things[ 0 ]->the_short()+" lands on its edge.\n");
            break;
          default :
            things[ 0 ]->move("/room/rubbish");
        }
        EFF->do_effect( effect[ 1 ], (string)things[ 0 ]->the_short(), place );
        return 1;
    }

    things[ 0 ]->move( place );

    stuff = MONEY_H->query_details_for( stuff[ 0 ] );
    tell_room( place, things[ 0 ]->the_short()+" falls "+
        place->query_property("here")+", "+( random( 2 ) ?
        stuff->head_short : stuff->tail_short )+" up.\n");
    
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({"<indirect:object:me>", (: cmd($1) :) });
} /* query_patterns() */
