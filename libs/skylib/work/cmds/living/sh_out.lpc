
#include <player.h>
#include <drinks.h>
#include <language.h>

inherit COMMAND_BASE;
inherit SPEECH_BASE;

#define BEEP sprintf("%c",7)

#define NO_QUIT_INVENTORY 1
#define NO_QUIT_COMBAT    2

string query_shout_word_type( string str );
void my_mess( string fish, string erk );

/**
 * @ignore yes
 * ok... the shout cost is charged for every 10 letters, plus a bonus
 * one for the start charge..  SO a shout of yes will cost 1 social
 * point... where as a shout of lots a letters will cost lots
 */
int cmd( string str ) {
    string s1, s2, s;
    string cur_lang;


    if( !str || str == "")
        return notify_fail("Syntax : shout <text>\n");

    if( !ENV(TP) )
        return notify_fail("You appear to be in limbo...\n");

    if( TP->query_property("dead") )
        return notify_fail("You don't have any lungs, how can you shout?\n");

    if( TP->check_earmuffs("shout") )
        return notify_fail("Why shout when you can't hear people shout "
            "back?\n");

    cur_lang = TP->query_current_language();

    if( !LANGUAGE_H->query_language_spoken(cur_lang) )
        return notify_fail( CAP(cur_lang)+" is not a spoken language.\n");

    if( !LANGUAGE_H->query_language_distance(cur_lang) )
        return notify_fail( CAP(cur_lang)+" cannot be spoken at a "
            "distance.\n");

    if( TP->query_invis() )
        return notify_fail("Invisible people cannot shout, they cannot "
            "see their arm in front of their face.  Shouting is out of "
            "the question.\n");

    if( TP->query_gagged() )
        return notify_fail("You have been gagged!  You will not be able "
            "to shout again until the gag is removed.  Perhaps you should "
            "talk to a creator about this.\n");

    if( TP->query_property("recently shouted") ) {
        return notify_fail("You have shouted very recently, perhaps you "
            "should give your lungs a small break and try again in a "
            "couple seconds.\n");
        TP->add_property("recently shouted", 1, 2 );
    }

    if( userp(TP) && !creatorp(TP) ) {
        if( TP->adjust_sp( -SHOUT_COST * ( strlen(str) / 10 + 1 ) ) < 0 )
            return notify_fail(NO_POWER);
        TP->adjust_max_sp( -(SHOUT_COST * ( strlen(str) / 10 + 1 ) / 10 ) );
        TP->add_property("recently shouted", 1, 2 );
    }

    // Remove colour shouts 'properly'.
    while( strsrch( str, "%^") != -1 )
        str = replace_string(str, "%^", "");

    if( !interactive(TP) ) {
        str = TP->convert_message( str );
        str = TP->fit_message( str );
    }

    s1 = query_shout_word_type(str);

    if( s1 != "yell")
        s = "shouts" + s1;
    else
        s = s1 + "s";

    str = replace( str, BEEP, "");

    if( TP->query_volume( D_ALCOHOL ) )
        str = drunk_speech( str );

    TP->remove_hide_invis("hiding");

    if( s1 != "yell") {
        if( cur_lang != "common")
            s1 += " in "+cur_lang;
        my_mess("You shout" + s1 + ": ", str );
    } else {
        if( cur_lang != "common")
            s1 += " in "+cur_lang;
        my_mess("You " + s1 + ": ", str );
    }

    s2 =  " " + lower_case(str);

    user_event( TP, "person_shout", TP->a_short()+" "+s,
        str, cur_lang, ENV(TP)->query_co_ord(),
        ( 100 * ( TP->query_con() + TP->query_str() ) ) / 3 );

    ENV(TP)->event_person_shout( 0, TP->one_short()+" "+s,
        str+"%^RESET%^", cur_lang );

    BROADCASTER->npc_shout_event( TP, TP->a_short()+" "+s,
        str+"%^RESET%^", cur_lang, ENV(TP)->query_co_ord(),
        ( 100 * ( TP->query_con() + TP->query_str() ) ) / 3 );

    return 1;

} /* cmd() */

/** @ignore yes */
string query_shout_word_type( string str ) {
    switch( str[<1] ) {
      case '!':
        return "yell";
      case '?':
        return " asking";
      default:
        return "";
    }
} /* query_shout_word_type() */

/** @ignore yes */
void my_mess( string fish, string erk ) {
    if( !interactive(TP) )
        return;

    printf("%s%-=*s\n", fish, TP->query_cols() - strlen(fish),
        TP->fix_string(erk) );

} /* my_mess() */
