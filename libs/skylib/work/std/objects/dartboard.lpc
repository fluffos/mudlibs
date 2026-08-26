/**
 * A dartboard by Someone.
 * @changed Converted to add_command() and cleaned up by Sandoz, 2002.
 */

inherit OBJECT_OBJ;

string name1, name2, target;
object player1, player2;
int score1, score2, in_use, thrown;

void setup() {
    set_name("dartboard");
    add_property("there", "mounted on the wall");
    set_short("dartboard");

    set_long("This is a dartboard.  A game for the bored and the "
        "restless.\n");

    set_weight(20);
    set_value(0);
    reset_get();

    set_read_mess("This is a game of darts for two players.  Before "
        "beginning their throws, the players must both type 'play darts'.  "
        "Each player in turn can then throw three darts at the board "
        "(by typing 'throw dart' three times).  Note that your accuracy is "
        "affected by your DEX stat.  The winner of the game is the "
        "player with the highest score after all darts have been thrown.\n");

} /* setup() */

/** @ignore yes */
void init() {
    add_command("play", "darts");
    add_command("abandon", "game");
    add_command("throw", "dart");
} /* init() */

/** @ignore yes */
int do_play() {
    if( in_use ) {
        write("The dartboard is in use right now.\n");
        return 1;
    }

    if( player1 ) {
        if( TP == player1 ) {
            add_failed_mess("You can't play against yourself!\n");
            return 0;
        }

        player2 = TP;
        name2 = player2->query_name();
        target = CAP( choice( DOMAIN_H->query_creators() -
            ({ name1, name2 }) ) );
        tell_room( ENV(TO), player1->the_short()+" and "+
            player2->the_short()+" have started a game of darts, throwing "
            "at a picture of "+target+".\n");
        tell_room( ENV(TO), "It is "+player1->poss_short()+" turn to throw "
            "darts.\n");
        in_use = 1;
        return 1;
    }

    player1 = TP;
    name1 = player1->query_name();

    tell_object( TP, "You can abandon the game at any time if no one takes "
        "up your challenge by typing 'abandon game'.\n");
    tell_room( ENV(TO), TP->the_short()+" is looking for someone to play "
        "darts with.\n", TP );

    set_heart_beat(1);
    return 1;

} /* do_play() */

/** @ignore yes */
void end_game() {
    set_heart_beat(0);

    in_use  = 0;
    thrown  = 0;
    player1 = 0;
    player2 = 0;
    name1   = 0;
    name2   = 0;
    score1  = 0;
    score2  = 0;
    target = 0;

} /* end_game() */

/** @ignore yes */
int do_abandon() {
    if( TP == player1 || TP == player2 ) {
        add_succeeded_mess("$N call$s off the game of darts.\n");
        end_game();
        return 1;
    }

    add_failed_mess("You are not participating in the game.\n");
    return 0;

} /* do_abandon() */

/** @ignore yes */
int score_it( int i ) {
    string str;

    if( i < 2 ) {
        str = "the wall. No score.\n";
        i = 0;
    } else if( i < 19 ) {
        str = "number "+i+", scoring "+(i*5)+".\n";
        i *= 5;
    } else if( i == 19 ) {
        str = target+"'s face! Score of 250!\n";
        i = 250;
    } else {
        str = target+"'s nose! Score of 500!\n";
        i = 500;
    }

    tell_object( TP, "You hit " + str );
    tell_room( ENV(TO), TP->the_short()+" hits " + str, TP );

    return i;

} /* score_it() */

/** @ignore yes */
int do_throw() {
    int hit;
    string str;

    if( !in_use || ( TP != player1 && TP != player2 ) ) {
        add_failed_mess("You are not currently playing.\n");
        return 0;
    }

    if( !player1 || ENV(player1) != ENV(TO) ) {
        tell_room( ENV(TO), CAP(name1)+" is no longer here.  "
            "The game of darts is called off.\n");
        end_game();
        return 1;
    }

    if( !player2 || ENV(player2) != ENV(TO) ) {
        tell_room( ENV(TO), CAP(name2)+" is no longer here.  "
            "The game of darts is called off.\n");
        end_game();
        return 1;
    }

    if( in_use == 1 && TP == player1 ) {
        thrown += 1;

        tell_object( TP, "You throw a dart.\n");
        tell_room( ENV(TO), TP->the_short()+" throws a dart.\n", TP );

        hit = score_it( random(21) + ( ( player1->query_dex() - 13 ) / 2 ) );

        if( hit == 500 ) {
            write("You feel a little more experienced.\n");
            player1->adjust_xp(10);
        }

        score1 += hit;

        if( thrown == 3 ) {
            tell_object( TP, "That was your third dart.  Your total score "
                "is "+score1+".\n");
            tell_room( ENV(TO), TP->the_short()+" has a score of "+
                score1+" after three darts.\n", TP );
            tell_room( ENV(TO), "It is now "+player2->poss_short()+" turn to "
                "throw darts.\n");
            in_use = 2;
        }

        return 1;
    }

    if( in_use == 2 && TP == player2 ) {
        thrown += 1;

        tell_object( TP, "You throw a dart.\n");
        tell_room( ENV(TO), TP->the_short()+" throws a dart.\n", TP );

        hit = score_it( random(21) + ( ( player2->query_dex() - 13 ) / 2 ) );

        if( hit == 500 ) {
            write("You feel a little more experienced.\n");
            player2->adjust_xp(10);
        }

        score2 += hit;

        if( thrown == 6 ) {
            tell_object( TP, "That was your third dart.\n");

            if( score1 > score2 ) {
                str = " with a score of "+score1+" to "+score2+".\n";
                tell_object( TP, player1->the_short()+" beats you" + str );
                tell_object( player1, "You beat "+player2->the_short() + str );
                tell_room( ENV(TO), player1->the_short()+" beats "+
                    player2->the_short() + str, ({ player1, player2 }) );
            } else if( score2 > score1 ) {
                str = " with a score of "+score2+" to "+score1+".\n";
                tell_object( TP, "You beat "+player1->the_short() + str );
                tell_object( player1, player2->the_short()+" beats you" + str );
                tell_room( ENV(TO), player2->the_short()+" beats "+
                    player1->the_short() + str, ({ player1, player2 }) );
            } else {
                tell_room( ENV(TO), "It is a tie with a score of "+
                    score1+"!\n");
            }

            end_game();

        }

        return 1;
    }

    add_failed_mess("It is not your turn to throw darts!\n");
    return 0;

} /* do_throw() */

/** @ignore yes */
void heart_beat() {
    if( !player1 )
        player1 = find_player( name1 );

    if( name2 && !player2 )
        player2 = find_player( name2 );

    if( !player1 || ENV(TO) != ENV(player1) )
        tell_room( ENV(TO), CAP(name1)+" is no longer here.  "
            "The game of darts is called off.\n");
    else if( name2 && ( !player2 || ENV(TO) != ENV(player2) ) )
        tell_room( ENV(TO), CAP(name2)+" is no longer here.  "
            "The game of darts is called off.\n");
    else
        return;

    end_game();

} /* heart_beat() */

/** @ignore yes */
mixed stats() {
    return ({
        ({"in use", in_use }),
        ({"player 1", name1 }),
        ({"player 2", name2 }),
        ({"score 1", score1 }),
        ({"score 2", score2 }),
        ({"target", target }),
    });
} /* stats() */
