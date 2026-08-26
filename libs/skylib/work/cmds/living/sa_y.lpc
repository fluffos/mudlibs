/**
 * The say command, trial out by Turrican for a commands daemon.
 * @changed Added support for adverbs - Sandoz, July 2003.
 */

#include <drinks.h>

inherit COMMAND_BASE;
inherit SPEECH_BASE;

/** @ignore yes */
int cmd( string mess, string adverb ) {
    string word, s1, cur_lang;

    if( TP->query_gagged() ) {
        return notify_fail("You have been gagged!  You will not be able "
            "to say things again until the gag is removed.  Perhaps you "
            "should talk to a creator about this.\n");
    }

    if( !ENV(TP) )
        return notify_fail("You are in limbo, no-one can hear you.\n");

    if( adverb ) {
        if( adverb[0] != '@' || sizeof(adverb) < 2 ) {
            add_failed_mess("Invalid adverb syntax to say.\n");
            return 0;
        }
        adverb[0] = ' ';
        adverb = replace_string( adverb, "_", " ");
    } else {
        adverb = "";
    }

    cur_lang = TP->query_current_language();

    if( !LANGUAGE_H->query_language_spoken(cur_lang) )
        return notify_fail( CAP(cur_lang)+" is not a spoken language.\n");

    if( !interactive(TP) ) {
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

    TP->comm_event( ENV(TP), "person_say", "$one_short:"+file_name(TP)+"$ "
        "$V$0="+word+"s,"+word+"$V$"+adverb+": ", mess, cur_lang );

    word += adverb;

    if( cur_lang != "common")
        word += " in " + CAP(cur_lang);

    my_mess("You "+word+": ", mess );
    TP->add_say_history("You "+word+": ", mess );

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "<string'message'>", (: cmd( $4[0], 0 ) :),
        "<word'@adverb'> <string'message'>", (: cmd( $4[1], $4[0] ) :),
    });
} /* query_patterns() */
