/**
 * This is the tell command.
 * @changed Added support for adverbs - Sandoz, July 2003.
 */

#include <drinks.h>
#include <player.h>

#define TELL_REPLY_PROPERTY "tell reply list"
#define CUT_THOUGH_PROPERTY "cut earmuffed tells"
#define FAIL_DONT_ASK       0
#define ASK                 1
#define CUT_DONT_ASK        2

inherit COMMAND_BASE;
inherit SPEECH_BASE;

/**
 * This method delegates tells from cres to earmuffed players.
 * All emoticon and "asks you" or "exclaims" stuff removed.
 */
void delayed_tell( string yesno, object *recipients, string mess ) {
    object  ob, *netdead;
    int disappeared;

    yesno = lower_case(yesno);

    if( yesno != "yes" && yesno != "y") {
        write("Ok, tell aborted.\n");
        return;
    }

    netdead = ({ });
    mess = replace( mess, "%^", " ");

    disappeared = sizeof( recipients ) - sizeof( recipients -= ({ 0 }) );

    foreach( ob in recipients ) {
        if( !interactive( ob ) )
            netdead += ({ ob });

        // Tell them even if they are net dead -
        // it'll end up in their tell history.
        ob->event_person_tell( TP, TP->query_cap_name()+" cuts "
            "through your ear muffs and tells "+
            query_multiple_short( recipients - ({ ob }) + ({"you"}) )+": ",
            mess );
    }

    if( sizeof(netdead) )
        write("Warning: "+query_multiple_short(netdead)+
            ( sizeof(netdead) == 1 ? " is" : " are")+" net dead.\n");

    if( disappeared )
        write("It seems "+disappeared+" person"+( disappeared > 1 ?
            "s have" : " has")+" disappeared.\n");

    // Ooops - no one left to talk to!
    if( !sizeof( recipients ) ) {
        write("No-one wanted to stay around long enough to hear what you "
            "had to say.\n");
        return;
    }

    my_mess("You tell "+TP->convert_message(
        query_multiple_short(recipients) )+": ", mess );

    TP->add_tell_history("You cut through earmuffs and tell "+
        CAP( TP->convert_message( query_multiple_short( recipients ) ) )+": ",
        mess );

    return;

} /* delayed_tell() */

/** @ignore yes */
int cmd( string arg, mixed thing, string adverb ) {
    object *earmuffed, *net_dead, *multiple_earmuffed, *cannot_see;
    object *obs, *ok, *fail;
    string word, mangle, lang, words, them_mess, me_mess, who;
    string *ok_string;
    int i, gag;
    mixed busy;

    if( adverb ) {
        if( adverb[0] != '@' || sizeof(adverb) < 2 ) {
            add_failed_mess("Invalid adverb syntax to tell.\n");
            return 0;
        }
        adverb[0] = ' ';
        adverb = replace_string( adverb, "_", " ");
    } else {
        adverb = "";
    }

    // Don't allow someone with tells ear muffed to use tell.
    if( TP->check_earmuffs("tell") ) {
        add_failed_mess("You have tells earmuffed.\n");
        return -1;
    }

    if( pointerp(thing) ) {
        words = arg;

        if( function_exists("trap_tell", ENV(TP) )  &&
            member_array( TO, previous_object(-1) ) == -1 ) {
            return ENV(TP)->trap_tell( words, thing, 0 );
        }
    } else if( !objectp( thing ) ) {
        string old;
        if( !arg || sscanf( old = arg, "%s %s", word, words ) != 2 )
            return 0;

        word = lower_case( word );
        word = TP->expand_nickname( word );

        if( sizeof( thing = explode( word, ",") ) == 1 ) {
            thing = find_player( word );
        } else {
            thing = map( thing, (: find_player :) );
            thing -= ({ 0 });
        }

        if( !thing ) {
            if( ( i = member_array('@', old ) ) != -1 ) {
                string empty, mud, *bits;

                who = old[0..i-1];
                i = sizeof( bits = explode( old[i+1..], " ") );

                while( i-- ) {
                    mud = INTERMUD_H->mud_exists( implode( bits[0..i], " ") );

                    if( mud ) {
                        if( !TP->query_creator() ) {
                            add_failed_mess("Sorry, only creators may send "
                                "intermud tells.\n");
                            return 0;
                        }

                        if( i == sizeof(bits) - 1 ) {
                            empty = mud;
                            continue;
                        }

                        words = implode( bits[i+1..], " ");

                        if( INTERMUD_H->tell( who, mud, words+"%^RESET%^") ) {
                            TP->event_person_tell( TP, "You tell "+CAP(who)+
                                "@"+mud+": ", words );
                            return 1;
                        } else {
                            add_failed_mess("There are no muds registered "
                                "with the name "+implode( map( bits[0..i],
                                (: CAP($1) :) ), " ")+".\n");
                            return 0;
                        }
                    }
                }

                if( empty ) {
                    add_failed_mess("You cannot send an empty tell to "+
                        CAP(who)+"@"+empty+".\n");
                    return 0;
                }

                add_failed_mess("There are no muds registered with that "
                    "name.\n");
                return 0;
            }

            add_failed_mess( CAP(word)+" is not logged in.\n");
            return 0;
        }

        if( ENV(TP) ) {
            if( function_exists("trap_tell", ENV(TP) ) &&
                member_array( TO, previous_object(-1) ) == -1 ) {
                return stringp(thing) ?
                    ENV(TP)->trap_tell( words, ({ thing }), 0 ):
                    ENV(TP)->trap_tell( words, thing, 0 );
            }
        }
    } else {
        words = arg;
    }

    if( !pointerp(thing) )
        obs = ({ thing });
    else
        obs = thing;

    if( !sizeof( obs -= ({ TP }) ) ) {
        add_failed_mess("Talking to yourself again.  I don't know.\n");
        return 0;
    }

    if( sizeof(obs) > 20 ) {
        add_failed_mess("You can only tell messages to up to 20 people.\n");
        return 0;
    }

    if( sizeof( fail = TP->query_ignoring(obs) ) )  {
        write("You are currently ignoring "+query_multiple_short(fail)+
            ", so "+( sizeof(fail) > 1 ? " they" : fail[0]->HE )+" couldn't "
            "reply anyway.\n");
        if( !sizeof( obs -= fail ) )
            return 1;
    }

    if( sizeof( fail = TP->query_ignored_by(obs) ) ) {
        if( !TP->query_creator() ) {
            write("You are currently being ignored by "+
                query_multiple_short(fail)+", so you cannot tell them "
                "anything.\n");
            if( !sizeof( obs -= fail ) )
                return 1;
        } else {
            write("Warning!  "+query_multiple_short(fail)+
                ( sizeof(fail) > 1 ? " have" : " has")+" you on ignore.\n");
        }
    }

    if( !TP->query_creator() && TP->adjust_sp( -TELL_COST ) < 0 )
        return notify_fail(NO_POWER);

    word = query_word_type( words, "");

    if( word != "")
        word = " "+word+"ing";

    if( TP->query_volume(D_ALCOHOL) )
        words = drunk_speech( words );

    // General speech modifications (curses, etc).
    if( stringp( mangle = TP->mangle_speech( words ) ) )
        words = mangle;

    if( ENV(TP) ) {
        if( function_exists("mangle_tell", ENV(TP) ) )
            words = ENV(TP)->mangle_tell( words, thing, 0 );
    }

    if( word != " asking") {
        me_mess = "tell";
    } else {
        me_mess = "ask";
        word = "";
    }

    net_dead = ({ });
    multiple_earmuffed = ({ });
    earmuffed = ({ });
    ok = ({ });
    cannot_see = ({ });

    foreach( thing in obs ) {
        if( TP->query_gagged() ) {
            if( !creatorp(thing) ) {
                obs -= ({ thing });
                gag = 1;
                continue;
            }
        }

        if( sizeof(obs) > 1 && thing->check_earmuffs("multiple-tell") ) {
            multiple_earmuffed += ({ thing });
        } else if( thing->check_earmuffs("tell") ) {
            if( TP->query_creator() &&
                TP->query_property(CUT_THOUGH_PROPERTY) == CUT_DONT_ASK ) {
                // A cre that doesn't care about earmuffs, so we warn the
                // cre and player, but don't add to the ear muffed array.
                write("You cut through "+thing->poss_short()+" earmuffs.\n");
                tell_object( thing, TP->the_short()+" cuts through your "
                    "earmuffs.\n");
                // Add to the array of people who get the message.
                ok += ({ thing });
            } else {
                // Ok, someone cares, so we add to earmuffed array.
                earmuffed += ({ thing });
            }
        } else if( !TP->query_invis() || reference_allowed( TP, thing ) ) {
            ok += ({ thing });
        } else {
            cannot_see += ({ thing });
            ok += ({ thing });
        }
    }

    if( !sizeof(obs) ) {
        tell_object( TP, "You have been gagged!  You will not be able to "
            "tell anything to players until the gag is removed.  Perhaps you "
            "should talk to a creator about this.\n");
        return 1;
    } else if( gag ) {
        tell_object( TP, "You have been gagged!  You will only be able to "
            "talk to creators until the gag is removed.  All non creators "
            "removed from this tell.\n");
    }

    ok_string = map( ok, (: $1->query_name() :) ) + ({ TP->query_name() });

    foreach( thing in ok ) {
        words = replace( words, "%^", " ");
        thing->event_person_tell( TP, CAP( TP->short( 0, 1 ) )+" "+me_mess+
            "s "+query_multiple_short( ok - ({ thing }) + ({"you"}) )+
            ( thing->check_earmuffs("emoticon") ? "" : adverb )+
            word + ": ", words );

        // Lasts for 15 minutes.
        thing->add_property( TELL_REPLY_PROPERTY, ok_string, 15 * 60 );

        if( !interactive(thing) && userp(thing) )
            net_dead += ({ thing });
    }

    if( sizeof(net_dead) )
        write("Warning: "+query_multiple_short( map( net_dead,
            (: $1->query_cap_name() :) ) ) + ( sizeof(net_dead) == 1 ?
            " is" : " are")+" net dead.\n");

    if( sizeof(multiple_earmuffed) )
        write( query_multiple_short(multiple_earmuffed)+
            ( sizeof(multiple_earmuffed) == 1 ? " has" : " have")+" multiple "
            "tells earmuffed.\n");

    if( sizeof( earmuffed ) ) {
        write( query_multiple_short(earmuffed)+
            ( sizeof(earmuffed) == 1 ? " has" : " have")+" tells "
            "earmuffed.\n");
        if( TP->query_creator() &&
            TP->query_property(CUT_THOUGH_PROPERTY) != FAIL_DONT_ASK ) {
            write("Cut through earmuffs? (y/n) ");
            input_to( (: delayed_tell :), earmuffed, words, lang );
        }
    }

    busy = TP->query_busy();

    if( busy == 1 ) {
        write("Warning! You have your busy flag on.\n");
    } else if( pointerp(busy) && sizeof( ok - busy ) ) {
        write("Warning! You are currently set as busy with "+
            query_multiple_short(busy)+".\n");
    }

    if( sizeof(cannot_see) )
        write("Warning! "+query_multiple_short(cannot_see)+" cannot see you "
            "and will not be able to respond.\n");

    if( sizeof(ok) ) {
        them_mess = TP->convert_message( CAP( query_multiple_short(ok) ) );
        my_mess("You "+me_mess+" "+them_mess +
            ( TP->check_earmuffs("emoticon") ? "" : adverb ) + word + ": ",
            words );

        TP->add_tell_history("You "+me_mess+" "+them_mess + word +
            ( thing->check_earmuffs("emoticon") ? "" : adverb )+": ",
            words );

    } else if( TP->query_creator() && !sizeof( earmuffed ) ) {
        // We don't want this message *and* the one about cutting
        // through ear muffs, so if the player is a cre and has
        // already gotten the (y/n) stuff, we skip this.
        add_failed_mess("It seems no one was listening.\n");
        return -1;
    }

    return 1;

} /* cmd() */

/** @ignore yes */
int reply_cmd( string mess, string adverb ) {
    string *rep;
    object *obs;

    if( !rep = TP->query_property(TELL_REPLY_PROPERTY) ) {
        add_failed_mess("No-one has told you anything in the last 15 "
            "minutes.\n");
        return 0;
    }

    if( !sizeof( obs = map( rep, (: find_player($1) :) ) - ({ 0 }) ) ) {
        add_failed_mess("None of "+query_multiple_short(rep)+" are currently "
            "online.\n");
        return 0;
    }

    return cmd( mess, obs, adverb );

} /* reply_cmd() */

/** @ignore yes */
mixed query_patterns() {
    mixed ret;

    ret = ({
        "<indirect:player> <string'message'>", (: cmd( $4[1], $1, 0 ) :),
        "reply <string'message'>", (: reply_cmd( $4[0], 0 ) :),
        "<indirect:player> <word'@adverb'> <string'message'>",
        (: cmd( $4[2], $1, $4[1] ) :),
        "reply <word'@adverb'> <string'message'>",
        (: reply_cmd( $4[1], $4[0] ) :),
    });

    if( TP->query_creator() )
        ret += ({"<string'player@mudname <message>'>",
            (: cmd( $4[0], 0, 0 ) :) });

    return ret;

} /* query_patterns() */
