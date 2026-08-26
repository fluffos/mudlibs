/**
 * The friends command, keeps track of your
 * friends.
 * Feb 18th '02 by Avelan
 */

#define LIST   0
#define ADD    1
#define REMOVE 2

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string friend, int flag ) {
    string *friends;
    function f;
    int i;

    i == sizeof( friends = TP->query_property("friends") || ({ }) );
    
    friends = filter( friends, (: PLAYER_H->test_user($1) :) );
    
    friend = lower_case( TP->expand_nickname(friend) );

    if( !sizeof(friends) )
        TP->remove_property("friends");
    else if( i != sizeof( friends ) )
        TP->add_property("friends", friends );

    if( flag == ADD ) {
        if( !PLAYER_H->test_user( friend ) ) {
            add_failed_mess( CAP(friend)+" doesn't appear to have a "
              "character on "+mud_name()+".\n");
            return 0;
        }

        if( friend == TP->query_name() ) {
            add_failed_mess("Come on, there must be someone other than "
                "yourself that you can add to your friends list.\n");
            return 0;
        }

        if( member_array( friend, friends ) != -1 ) {
            add_failed_mess( CAP(friend)+" appears to be already on your "
              "friends list.\n");
            return 0;
        }

        friends += ({ friend });
        TP->add_property("friends", friends );
        write( CAP(friend)+" has been added to your friends list.\n");
        return 1;
    }

    if( flag == REMOVE ) {
        if( !sizeof(friends) ) {
            add_failed_mess("You don't appear to have anyone on your friends "
                "list.\n");
            return 0;
        }

        if( member_array( friend, friends ) == -1 ) {
            add_failed_mess( CAP(friend)+" doesn't appear to be on your "
                "friends list.\n");
            return 0;
        }

        friends -= ({ friend });
        write( CAP(friend)+" has been removed from your friends list.\n");

        if( !sizeof(friends) ) {
            TP->remove_property("friends");
            return 1;
        }

        TP->add_property("friends", friends );
        return 1;
    }

    if( !sizeof(friends) ) {
        add_failed_mess("You don't appear to have anyone on your friends "
            "list.\n");
        return 0;
    }

    f = function( string name ) {
            int last;
            object ob;

            ob = find_player(name);
            last = ob ? ob->query_last_log_on() : PLAYER_H->test_last(name);

            return sprintf("%-16s %-26s %-15s", CAP(name),
                ( ob ? "Currently Logged In" : ctime(last) ),
                ( ob ? ( !interactive(ob) ? "Net dead" :
                "Idle: "+query_idle(ob) / 60 ) :
                time_string( time() - last, 1 ) ) );
    };

    friends = map( friends, f );
    friend = create_table( ({ "Friends", "friend" }), friends, 0 );

    tell_object( TP, friend );
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({ "", (: cmd( "", LIST ) :),
              "list", (: cmd( "", LIST ) :),
              "add <string'player'>", (: cmd( $4[0], ADD ) :),
              "remove <string'player'>", (: cmd ( $4[0], REMOVE ) :)
    });
} /* query_patterns() */
