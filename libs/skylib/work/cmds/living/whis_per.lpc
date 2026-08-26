/**
 * @changed Added support for adverbs - Sandoz, July 2003.
 */

#include <drinks.h>
#include <player.h>

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( object *obs, string mess, string adverb ) {
    object *fail;
    string lang;
    int i;

    if( !sizeof( obs -= ({ TP }) ) ) {
        add_failed_mess("You have difficulty getting your lips near your "
            "ear.\n");
        return 0;
    }

    if( TP->query_gagged() ) {
        add_failed_mess("You have been gagged!  You will not be able to say "
            "things again until the gag is removed.  You should probably "
            "talk to a creator about this.\n");
        return 0;
    }

    lang = TP->query_current_language();
    if( !LANGUAGE_H->query_language_spoken( lang ) ) {
        add_failed_mess( lang +" is not a spoken language.\n" );
        return 0;
    }

    fail = TP->query_ignoring(obs);
    if( sizeof(fail) ) {
        add_failed_mess("You cannot whisper to $I since you are ignoring "
            "them.\n", fail );
        if( !sizeof( obs -= fail ) )
            return 0;
    }

    fail = TP->query_ignored_by(obs);
    if( sizeof(fail) ) {
        add_failed_mess("You cannot whisper to $I they are ignoring you.\n",
            fail );
        if( !sizeof( obs -= fail ) )
            return 0;
    }

    if( !interactive( TP ) ) {
        mess = TP->convert_message( mess );
        mess = TP->fit_message( mess );
    }

    if( TP->query_volume( D_ALCOHOL ) )
        mess = TP->drunk_speech( mess );

    if( adverb ) {
        if( adverb[0] != '@' || sizeof(adverb) < 2 ) {
            add_failed_mess("Invalid adverb syntax to whisper.\n");
            return 0;
        }
        adverb = replace_string( adverb[1..], "_", " ")+" ";
    } else {
        i = strlen( mess ) - 1;

        while( i >= 0 && mess[ i ] == ' ')
            i--;

        switch( mess[ i ] ) {
          case '!' :
            adverb = "urgently ";
          break;
          case '?' :
            adverb = "questioningly ";
          break;
          default :
            adverb = "";
        }
    }

    mess += "%^RESET%^";

    TP->do_whisper( ENV(TP), "whisper", TP->one_short()+" whispers "+adverb,
        mess, obs, lang, TP );

    write("You whisper "+adverb+"to "+query_multiple_short( obs, "the")+
        ": "+mess+"\n");

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "<indirect:living:here> <string'message'>",
        (: cmd( $1, $4[1], 0 ) :),
        "<string'message'> to <indirect:living:here>",
        (: cmd( $1, $4[0], 0 ) :),
        "<indirect:living:here> <word'@adverb'> <string'message'>",
        (: cmd( $1, $4[2], $4[1] ) :),
        "<string'message'> <word'@adverb'> to <indirect:living:here>",
        (: cmd( $1, $4[0], $4[1] ) :),
    });
} /* query_patterns() */
