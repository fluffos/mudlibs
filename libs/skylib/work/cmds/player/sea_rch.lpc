
#include <tasks.h>
#include <player.h>

#define SKILL   "general.perception"

class search_data {
    int id;
    object env;
} /* search_data() */

private void search_callout( object who, string str );

private nosave mapping searchers = ([ ]);

/** @ignore yes */
int cmd( string str ) {
    class search_data data;

    if( TP->query_property("dead") ) {
        add_failed_mess("You cannot search whilst dead.\n");
        return 0;
    }

    if( TP->query_fighting() ) {
        add_failed_mess("You cannot search whilst in combat.\n");
        return 0;
    }

    // This command takes four seconds, which equals two rounds.
    // We take off three, just in case.
    TP->adjust_time_left( -ROUND_TIME * 3 );

    if( searchers[TP] )
        remove_call_out( searchers[TP]->id );

    data = new( class search_data );
    data->id = call_out( (: search_callout :), 4, TP, str );
    data->env = ENV(TP);

    searchers[TP] = data;

    add_succeeded_mess("$N start$s to search around.\n");
    return 1;

} /* cmd() */

/** @ignore yes */
private void remove_searcher( object who ) {
    remove_call_out( searchers[who]->id );
    map_delete( searchers, who );
} /* remove_searcher() */

/** @ignore yes */
private void search_callout( object who, string str ) {
    mapping hide_invis;
    object *found, ob;
    string *types;
    mixed see;
    int i;

    if( who->query_fighting() ) {
        tell_object( who, "You appear to have entered combat and cannot "
            "finish searching.\n");
        return remove_searcher(who);
    }

    if( searchers[who]->env != ENV(who) ) {
        tell_object( who, "You seem to have moved away from where you "
            "started searching.\n");
        return remove_searcher(who);
    }

    if( function_exists("do_search", ENV(who) ) ) {
        switch( ENV(who)->do_search(str) ) {
        case 1 :
          return;
        case 0 :
          if( query_notify_fail() )
              tell_object( who, query_notify_fail() );
          return;
        default :
        break;
        }
    }

    if( !str ) {
        found = ({ });

        foreach( ob in INV(ENV(who)) ) {
            if( ob->query_visible(who) || ob->query_creator() )
                continue;

            if( mapp( hide_invis =  ob->query_hide_invis() ) )
                types = keys( hide_invis );
            else
                continue;

            if( !sizeof(types) )
                continue;

            for( i = 0; i < sizeof(types); i++ ) {
                if( hide_invis[ types[ i ] ][ 0 ] == who )
                    continue;

                if( intp( see = hide_invis[ types[ i ] ][ 1 ] ) ) {
                    see -= random( ENV(who)->query_light() );
                    see /= 2;

                    switch( TASKER->perform_task( who, SKILL, see, TM_FREE ) ) {
                      case AWARD :
                        tell_object( who, "%^YELLOW%^"+({
                            "You feel very perceptive.",
                            "You realise something new about searching."})
                            [random(2)]+"%^RESET%^.\n");
                      case SUCCEED :
                        found += ({ ob });
                        ob->remove_hide_invis( types[i] );
                        break;
                      default:
                    }
                    break;
                }
            }
        }
    }

    if( sizeof(found) ) {
        tell_object( who, "You search around and find "+
            query_multiple_short(found)+".\n");
    } else {
        tell_object( who, ({
            "You search around for a while, but don't find anything.\n",
            "You scrounge around.  The ground does look interesting, "
            "you decide.\n",
            "You look carefully at everything, but find nothing.\n",
            "After an intense search, you find nothing.\n"})[ random(4) ] );
    }

    tell_room( ENV(who), who->one_short()+" $V$0=searches,search$V$ around "
        "the place a bit.\n", who );

    event( ENV(who), "player_search");

    remove_searcher(who);

} /* search_callout() */

/** @ignore yes */
void interrupt_search( object who ) {
    if( searchers[who] ) {
        tell_object( who, "You stop searching.\n");
        remove_searcher(who);
    }
} /* interrupt_search() */

/** @ignore yes */
mixed query_patterns() {
    return ({"<string>", (: cmd($4[0]) :),
             "here", (: cmd(0) :),
             "", (: cmd(0) :) });
} /* query_patterns() */

/** @ignore yes */
mapping query_searchers() { return copy(searchers); }
