/**
 * Helpers command, used to display which newbie helpers are online at 
 * the moment or to test if someone offline is a newbie helper.
 * <p>
 * Trial version.
 * <p>
 * @author Taffyd
 * @started 23/04/99 7:45PM
 */

#include <login.h>

inherit COMMAND_BASE;

int cmd() {
    object *helpers;
    string mess;
        
    helpers = filter( users(), (: !creatorp($1) && 
        $1->query_property( "newbie helper" ) :) );
    
    switch( sizeof( helpers ) ) {
        case 0:
            mess = "There are no newbie helpers logged on at the "
                "moment.\n";
        break;
        
        case 1:
            if ( helpers[ 0 ] == this_player() ) {
                mess = "You are the only newbie helper logged on at the "
                    "moment.\n";
            }
            else {
                mess = helpers[ 0 ]->query_short() + " is the only newbie "
                    "helper logged on at the moment.\n";
            }
        break;
        
        default:
            mess = query_multiple_short( helpers->query_short() ) + " are "
                "newbie helpers.\n";
    }
    
    tell_object( this_player(), mess );
     
    return 1;
} /* cmd() */

int test_helper( string player_name ) {
    
    player_name = lower_case( player_name );
    
    if ( LOGIN_OB->test_property( player_name, "newbie helper" ) ) {
        tell_object( this_player(), capitalize( player_name ) +
            " is a newbie helper.\n" );
        return 1;
    }
    
    tell_object( this_player(), capitalize( player_name ) + 
        " is not a newbie helper.\n" );
    return 1;
} 
mixed *query_patterns() {
    return ({ "", (: cmd :),
              "<string'name'>", (: test_helper( $4[ 0 ] ) :) });
} /* query_patterns() */
