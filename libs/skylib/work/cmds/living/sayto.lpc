/**
 * The sayto command, trial out by Turrican for a commands daemon.
 * @changed Added support for adverbs - Sandoz, July 2003.
 */

#include <player.h>
#include <drinks.h>

inherit COMMAND_BASE;
inherit SPEECH_BASE;

/** @ignore yes */
mixed cmd( object *obs, string mess, string adverb ) {
    string word, s1, cur_lang;
    object *fail;

    obs -= ({ TP });

    if( !sizeof(obs) ) {
        add_failed_mess("Whoops, hard to have a conversation with yourself!\n");
        return 0;
    }

    if( !ENV(TP) ) {
        add_failed_mess("You are in limbo, no-one can hear you.\n");
        return 0;
    }

    if( TP->query_gagged() ) {
        add_failed_mess("You have been gagged!  You will not be able to say "
            "things again until the gag is removed.  You should probably "
            "talk to a creator about this.\n");
        return 0;
    }

    if( adverb ) {
        if( adverb[0] != '@' || sizeof(adverb) < 2 ) {
            add_failed_mess("Invalid adverb syntax to sayto.\n");
            return 0;
        }
        adverb[0] = ' ';
        adverb = replace_string( adverb, "_", " ");
    } else {
        adverb = "";
    }

    cur_lang = TP->query_current_language();

    if( !LANGUAGE_H->query_language_spoken(cur_lang) ) {
        add_failed_mess( CAP(cur_lang)+" is not a spoken language.\n");
        return 0;
    }

    if( !interactive( TP ) ) {
        mess = TP->convert_message( mess );
        mess = TP->fit_message( mess );
    }

    word = query_word_type(mess);

    if( TP->query_volume(D_ALCOHOL) )
        mess = drunk_speech(mess);

    // General speech modifications (curses, etc).
    if( stringp( s1 = TP->mangle_speech(mess) ) )
        mess = s1;

    mess = de_eight(mess);
    TP->remove_hide_invis("hiding");

    if( sizeof( fail = TP->query_ignoring(obs) ) )  {
        write("You are ignoring "+query_multiple_short(fail)+", so "+
            ( sizeof(fail) > 1 ? " they" : fail[0]->HE )+" couldn't reply "
            "anyway.\n");
        if( !sizeof( obs -= fail ) )
            return 1;
    }

    if( sizeof( fail = TP->query_ignored_by(obs) ) )  {
        write("You are currently being ignored by "+
            query_multiple_short( fail )+".\n");
        if( !sizeof( obs -= fail ) )
            return 1;
    }

    if( word != "ask") {
        TP->comm_event( ENV(TP), "person_say", TP->one_short()+" "+
            word+"s to "+query_multiple_short(obs)+adverb+": ", mess,
            cur_lang );

        if( cur_lang != "common")
            word += " in "+cur_lang;

        my_mess("You "+word+" to "+TP->convert_message(
            query_multiple_short( obs, "the") )+adverb+": ", mess );

    } else {
        TP->comm_event( ENV(TP), "person_say", TP->one_short()+" "+
            word+"s "+query_multiple_short(obs)+adverb+": ", mess, cur_lang );

        if( cur_lang != "common")
            word += " in "+cur_lang;

        my_mess("You "+word+" "+TP->convert_message(
            query_multiple_short( obs, "the") )+adverb+": ", mess );
    }

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "<indirect:living:here> <string'message'>",
        (: cmd( $1, $4[1], 0 ) :),
        "<indirect:living:here> <word'@adverb'> <string'message'>",
        (: cmd( $1, $4[2], $4[1] ) :),
    });
} /* query_patterns() */
