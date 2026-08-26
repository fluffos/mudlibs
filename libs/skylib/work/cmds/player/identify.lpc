
#define EFFECT "/std/effects/object/identity_hold"

inherit COMMAND_BASE;

/** @ignore yes */
mixed cmd( object *things, string word ) {
    object thing;
    mapping ids;

    if( !word )  {
        ids = unique_mapping( things, (: $1->query_identifier() :) );
        foreach( word, things in ids )
            write("You "+( !word ? "do not have "+
                query_multiple_short(things, "the")+" identified." :
                "have "+query_multiple_short(things, "the")+" identified "
                "as \""+word+"\".") + "\n");
        return 1;
    }

    if( sizeof(things) > 1 ) {
        add_failed_mess("You can only identify one thing at a time.\n");
        return 0;
    }

    thing = things[0];
    word = lower_case( word );
    thing->add_effect( EFFECT, ([ "identity" : word ]) );

    write( (string)thing->the_short()+" may now be identified as \""+
        word +"\".\n" );
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({ "<indirect:object:me> as <string'some new name'>",
              (: cmd( $1, $4[1] ) :),
              "<indirect:object:me>",
              (: cmd( $1, 0 ) :) });
} /* query_patterns() */
