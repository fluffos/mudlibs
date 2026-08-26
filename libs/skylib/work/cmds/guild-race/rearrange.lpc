/**
 * New stat ROLLING method.  Basically best 3 of 4d6.  Capability of
 * subtraction from some of the stats.  Let's *hope* there's no need.
 * Warns immortals if there seems to be a script in action.
 * @author Hamlet Sept 1995
 * @changed Majorly rewritten for Divided Sky - Shaydz
 * @changed Removed the stat deduction code - Sandoz, July 2003.
 */

inherit COMMAND_BASE;

// This is the order in the race object.
#define CON stats[ 0 ]
#define DEX stats[ 1 ]
#define INT stats[ 2 ]
#define STR stats[ 3 ]
#define WIS stats[ 4 ]

string *thestats = ({"str", "dex", "con", "int", "wis"});

void ordering( string order );
void confirm_order( string answer );
void do_the_roll();
void finish_rolling( string answer );
void confirm_exit( string answer );
void store_values();
void wipe_stuff();
void house_keeping( int log, int times );

string get_racial_bonus( object player ) {
    string race_ob;
    int *stats;

    if( !player || !race_ob = player->query_race_ob() ) {
        stats = allocate( 5, 0 );
    } else {
        // get the real racial bonuses from the race object,
        // so we won't get -1 dex as a racial bonus when burdened.
        stats = race_ob->query_stats();
    }

    return sprintf("str: %2d  dex: %2d  con: %2d  int: %2d  "
        "wis: %2d", STR, DEX, CON, INT, WIS );

} /* get_racial_bonus() */

int cmd() {

    tell_object( TP, "\n"+
        mud_name()+" uses a dice rolling method to generate player stats.\n\n"
        "You can only rearrange once, but you may re-roll as many times "
        "as you like.  However, the use of triggers, robots and scripting "
        "to choose stats is not allowed.\n\n"
        "Your stats are adjusted by your racial bonuses.\n"
        "The racial bonuses for "+pluralize( TP->query_race() )+" are: "+
        get_racial_bonus( TP )+".\n"
        "These bonuses will not be applied until after you have finished "
        "rearranging your stats.\n\n"
        "We need to know in what order of importance you place your stats.  "
        "It is advisable to know what type of character you would like to "
        "play, and what the primary stats for that type of char would be.  "
        "The primary stats should be the first ones you list, although the "
        "choice is yours, but remember:\n"
        "%^RED%^You can only do this once!%^RESET%^\n\n"
        "For example, enter your stat priorities in the form:  "
        "str con dex wis int\n\n"
        "Enter your stat order: ");

    input_to("ordering", 0 );
    return 1;

} /* cmd() */

/* We elicit their order of preference for the attributes. */
void ordering( string order ) {
    string *stuff, spew;
    int i, *slots, *statorder;

    if( !order || order == "" || order == 0 ) {
        tell_object( TP, "That order is not valid.  Try something "
            "like: str dex con int wis\n\nEnter your stat order: ");
        input_to("ordering", 0 );
        return;
    }

    if( lower_case(order) == "quit"[0..strlen(order)-1] ) {
        tell_object( TP, "Rearrange cancelled.\n");
        wipe_stuff();
        return;
    }

    stuff = explode(order, " ");

    if( sizeof(stuff) < 5 ) {
        tell_object( TP, "You must include all 5 stats.  Try something like: "
            "str dex con int wis\n\nEnter your stat order: ");
        input_to("ordering", 0 );
        return;
    }

    slots = allocate( 5 );
    statorder = allocate( 5, -1 );

    for( i = 0; i < 5; i++ ) {
        statorder[i] = member_array( lower_case(stuff[i]), thestats );
        if( statorder[i] == -1 ) {
            tell_object( TP, "That order is not valid.  Try something "
                "like: str dex con int wis\n\nEnter your stat order: ");
            input_to("ordering", 0 );
            return;
        }
        slots[statorder[i]] = 1;
    }

    for( i = 0; i < 5; i++ )
        if( !slots[i] ) {
            tell_object( TP, "You must include all 5 stats.  Try something "
                "like: str dex con int wis\n\nEnter your stat order: ");
            input_to("ordering", 0 );
            return;
        }

    /* We now have their desired order stored in statorder. */
    spew = implode( ({ thestats[statorder[0]], thestats[statorder[1]],
                       thestats[statorder[2]], thestats[statorder[3]],
                       thestats[statorder[4]] }), " ");

    tell_object( TP, "\nYou have selected:  "+spew+"\nIs this correct? "
        "('y' or 'n' or 'q' to quit) ");

    TP->add_property("statorder", statorder );
    TP->add_property("beginroll", time() - TP->query_property("rolltime") );
    input_to("confirm_order", 0 );
    return;

} /* ordering() */

void confirm_order( string answer ) {
    if( !answer || answer == "" ) {
        tell_object( TP, "You must answer 'y' or 'n': ");
        input_to("confirm_order", 0 );
        return;
    }

    if( lower_case(answer) == "quit"[0..strlen(answer)-1] ) {
        tell_object( TP, "Rearrange cancelled.\n");
        wipe_stuff();
        return;
    }

    if( member_array( answer, ({"y","Y","yes","n","N","no"}) ) == -1 ) {
        tell_object( TP, "You must answer 'y' or 'n': ");
        input_to("confirm_order", 0 );
        return;
    }

    if( member_array( answer, ({"y","Y","yes"}) ) != -1 ) {
        tell_object( TP, "\n"
            "Next you will be shown a roll of your stats.  You may either "
            "keep this roll or roll again.\n\n"
            "You may roll as many times as you wish.\n\n"
            "Keep in mind that no character is perfect and that it is "
            "often more fun to role-play a character that is flawed in "
            "some way.\n\n"
            "Also know that racial bonuses get added later and these scores "
            "do not include them.\n\n");

        tell_object( TP, "Rolling...\n\n");
        do_the_roll();
        return;
    }

    tell_object( TP, "Try again...\n\nEnter your stat order: ");
    input_to("ordering", 0 );
    return;

} /* confirm_order() */

void do_the_roll() {
    int i, j, *statorder, *scores;
    int *dice = allocate( 4 );
    int *tmp = allocate( 5 );

    if( !scores = TP->query_property("scores") )
        scores = allocate( 5 );

    for( i = 0; i < 5; i++ ) {
        for( j = 0; j < 4; j++ )
            dice[j] = 1 + random( 7 );
        dice = sort_array( dice, -1 );
        tmp[i] = dice[0] + dice[1] + dice[2];
    }

    tmp = sort_array( tmp, -1 );

    if( ( tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4] ) > 65 ) {
        do_the_roll();
        return;
    }

    statorder = TP->query_property("statorder");

    for( i = 0; i < 5; i++ )
        scores[statorder[i]] = tmp[i];

    TP->add_property("scores", scores );

    tell_object( TP, "Your scores are:\n\t"+
        thestats[statorder[0]]+": "+tmp[0]+"\t\t"+
        thestats[statorder[1]]+": "+tmp[1]+"\t\t"+
        thestats[statorder[2]]+": "+tmp[2]+"\n\t"+
        thestats[statorder[3]]+": "+tmp[3]+"\t\t"+
        thestats[statorder[4]]+": "+tmp[4]+"\n\n");

    tell_object( TP, "Would you like to keep this roll? "
        "('y' or 'n' or 'q' to quit): ");

    input_to("finish_rolling");
    return;

} /* do_the_roll() */

/* See if they want to keep it or re-roll */
void finish_rolling( string answer ) {
    int times;

    if( !answer || answer == "" ) {
        tell_object(TP,"Answer 'y' or 'n': ");
        input_to("finish_rolling");
        return;
    }

    times = TP->query_property("timesrolled");
    times++;

    if( lower_case(answer) == "quit"[0..strlen(answer)-1] ) {
        tell_object( TP, "Rearrange cancelled.\n");
        TP->add_property("timesrolled", times );
        wipe_stuff();
        return;
    }

    if( member_array( answer, ({"y","Y","n","N","yes","no"}) ) == -1 ) {
        tell_object( TP, "Answer 'y' or 'n': ");
        input_to("finish_rolling");
        return;
    }

    TP->add_property("timesrolled", times );

    if( TP->query_property("beginroll") )
        TP->add_property("rolltime", time() - TP->query_property("beginroll") );

    if( times && ( ( times % 100 ) == 0 ) )
        house_keeping( 0, times );

    if( member_array( answer, ({"y","Y","yes"}) ) != -1 ) {
        tell_object( TP, "Remember, these stats do not include your racial "
            "bonuses.\n"
            "The racial bonuses for "+pluralize(TP->query_race())+" are: "+
            get_racial_bonus( TP )+".\n"
            "These bonuses will be applied when you finish rearranging.\n"
            "Are you sure? ('y' or 'n'): ");
        input_to("confirm_exit");
        return;
    }

    tell_object( TP, "\nScores deleted.  Re-rolling...\n\n");
    do_the_roll();
    return;

} /* finish_rolling() */

void confirm_exit( string answer ) {
    if( !answer || answer == "" ) {
        tell_object( TP, "Answer 'y' or 'n': ");
        input_to("confirm_exit");
        return;
    }

    if( answer == "quit" || answer == "q" ) {
        tell_object( TP, "Rearrange cancelled.\n");
        wipe_stuff();
        return;
    }

    if( member_array( answer, ({"y","Y","yes","n","N", "no"}) ) == -1 ) {
        tell_object( TP, "Answer 'y' or 'n': ");
        input_to("confirm_exit");
        return;
    }

    if( member_array( answer, ({"y","Y","yes"}) ) != -1 ) {
        tell_object( TP, "Stat generation is now completed.  The rearrange "
            "command has been removed from you.\n");
        store_values();
        return;
    }

    tell_object( TP, "\nScores deleted.  Re-rolling...\n\n");
    do_the_roll();
    return;

} /* confirm_exit() */

/* Set the attributes and clean out some junk. */
void store_values() {
    mapping stats_prop;
    int times, *scores;

    times = TP->query_property("timesrolled");
    scores = TP->query_property("scores");

    log_file("REARRANGE", ctime(time())+": "+TP->query_cap_name()+" rolled "+
        times+" times, got: "+scores[0]+" "+scores[1]+" "+scores[2]+" "+
        scores[3]+" "+scores[4]+".\n");

    TP->adjust_str( scores[0] - TP->query_real_str() );
    TP->adjust_dex( scores[1] - TP->query_real_dex() );
    TP->adjust_con( scores[2] - TP->query_real_con() );
    TP->adjust_int( scores[3] - TP->query_real_int() );
    TP->adjust_wis( scores[4] - TP->query_real_wis() );

    TP->add_property("stats_rearranged", 1 );

    event( users(), "inform", TP->query_cap_name()+" rolled "+times+" times, "
        "got: str:"+scores[0]+" dex:"+scores[1]+" con:"+scores[2]+" int:"+
        scores[3]+" wis:"+scores[4], "rolls" );

    stats_prop = ([
        "str" : scores[0],
        "dex" : scores[1],
        "con" : scores[2],
        "int" : scores[3],
        "wis" : scores[4],
        ]);

    TP->add_property("original_stats", stats_prop );

    wipe_stuff();
    house_keeping( 1, times );

    TP->remove_property("rolltime");
    TP->remove_property("timesrolled");
    TP->remove_known_command("rearrange");
    TP->add_property("rearrange v1.2", 1 );
    TP->save();

    return;

} /* store_values() */

void wipe_stuff() {
    TP->remove_property("statorder");
    TP->remove_property("scores");
    if( TP->query_property("beginroll") )
        TP->add_property("rolltime", time() - TP->query_property("beginroll") );
    TP->remove_property("beginroll");
} /* wipe_stuff() */

int init_wecareat( int times ) {
    int wecareat;

    if( times == 100 )
        return 100;

    wecareat = 100;

    while( wecareat < times )
        wecareat *= 2;

    return wecareat;

} /* init_wecareat() */

void house_keeping( int logme, int times ) {
    int duration, wecareat, beginroll, tmp;

    beginroll = TP->query_property("beginroll");
    duration = time() - beginroll;

    if( ( ( times * 100 ) / duration ) > 90 ) {
        string str;

        wecareat = init_wecareat( times );

        switch( tmp = duration / 60 + 1 ) {
          case 1 :
            str = "minute";
          break;
          default :
            str = tmp + " minutes";
        }

        if( times == wecareat || ( logme && ( times >= 100 ) ) )
            log_file("REARRANGE", "%s rolled %ix in %s%s at %s.\n",
                TP->query_cap_name(), times, tmp == 1 ? "one " : "",
                str, ctime(time()) );

        event( users(), "inform", "WARNING! "+TP->query_cap_name()+" has "
            "rolled for stats "+times+" times in the last "+str, "rolls");
    }

} /* house_keeping() */
