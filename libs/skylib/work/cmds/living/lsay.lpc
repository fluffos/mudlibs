/**
 * The lsay command, trial out by Turrican for a commands daemon.
 */

#include <drinks.h>

inherit COMMAND_BASE;
inherit SPEECH_BASE;

/** @ignore yes */
int cmd( string arg ) {
    string word, s1, cur_lang, lang, mess;
    int *co_ords;

    if( TP->query_gagged() )
        return notify_fail("You have been gagged!  You will not be able "
            "to say things again until the gag is removed.  Perhaps you "
            "should talk to a creator about this.\n");

    if( !ENV(TP) )
        return notify_fail("You are in limbo, no-one can hear you.\n");

    cur_lang = TP->query_current_language();

    if( !LANGUAGE_H->query_language_spoken(cur_lang) )
        return notify_fail( CAP(cur_lang)+" is not a spoken language.\n");

    if( !interactive(TP) ) {
        arg = TP->convert_message( arg );
        arg = TP->fit_message( arg );
    }

    word = query_word_type(arg);

    if( TP->query_volume(D_ALCOHOL) )
        arg = drunk_speech(arg);

    // General speech modifications (curses, etc).
    if( stringp( s1 = TP->mangle_speech(arg) ))
        arg = s1;

    arg = de_eight(arg);

    TP->remove_hide_invis("hiding");

    if( cur_lang != "common")
        lang = " in "+cur_lang;
    else
        lang = "";

    mess = "$one_short:"+file_name(TP)+"$ "+"$V$0="+word+"s,"+word+"$V$ "
           "loudly: ";

    TP->comm_event( ENV(TP), "person_say", mess, arg, cur_lang );

    // Broadcast it around a little.
    co_ords = ENV(TP)->query_co_ord();
    BROADCASTER->npc_shout_event( TP, mess, arg, cur_lang, co_ords, 20 );

    my_mess("You " + word + " loudly" + lang + ": ", arg );

    TP->add_say_history("You " + word + " loudly" + lang + ": ", arg );

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "<string'message'>", (: cmd( $4[0] ) :),
    });
} /* query_patterns() */
