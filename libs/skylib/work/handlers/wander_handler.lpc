/**
 * Handles NPCs wandering randomly around the place and NPCs
 * following a route to a destination.
 * @see /str/npc->move_me_to()
 * @author Wodan
 * @author Pinkfish
 * @changed Rewritten by Wodan 19-6-1997.
 * @changed Rewritten by Sandoz 23-6-2002.
 */

#define LAST_LOC_PROPERTY "last locations"

/**
 * This class stores the data for a single NPC that is following a route.
 */
class route_traveller {
    int movetime;
    int delay;
    string dest;
}

private mapping wanderers, travellers, moving;
private nosave int tick;

/** @ignore yes */
void create() {
    wanderers = ([ ]);
    travellers = ([ ]);
    moving = ([ ]);

    set_heart_beat(1);

} /* create() */

/**
 * This method returns the mapping of move times and NPCs
 * that are going to move at a particular move time.
 * @return the moving NPCs mapping
 */
mapping query_moving() { return moving; }

/**
 * This method returns the mapping of all wandering NPCs
 * and their related data.
 * @return a mapping of all wandering NPCs and their data
 */
mapping query_wanderers() { return wanderers; }

/**
 * This method returns the mapping of all travelling NPCs
 * and their related data.
 * @return a mapping of all travelling NPCs and their data
 */
mapping query_travellers() { return travellers; }

/** @ignore yes */
private void add_moving( object monster, int when ) {
    if( !pointerp( moving[when] ) )
        moving[when] = ({ monster });
    else if( member_array( monster, moving[when] ) == -1 )
        moving[when] += ({ monster });
} /* add_moving() */

/**
 * Called from the NPC to start them moving.  This should not
 * need to be called inside your code.  It is called from the
 * function move_me_to in the NPC object.
 * @see /std/npc->move_me_to()
 * @param delay the delay between each move
 * @param dest the destination room for the npc
 * @return 0 if it failed and 1 on success
 */
int move_me_please( int delay, string dest ) {
    object monster;
    int when;

    if( !intp(delay) )
        return 0;

    monster = PO;

    if( delay < 5 )
        delay = 5;

    when = time() + delay;

    travellers[monster] = new( class route_traveller,
                               delay    : delay,
                               movetime : when,
                               dest     : dest );

    add_moving( monster, when );
    return 1;

} /* move_me_please() */

/** @ignore yes */
private void do_wander_move( int running_away, object monster ) {
    mapping dest_dir;
    string tmp, direction;
    string *dirs, *room_zones, *move_zones, *last_locs, *last_used;
    object env;

    if( !monster || monster->do_not_wander() || monster->query_hp() <= 0 ||
        !( env = ENV(monster) ) || file_name(env)[1..4] == "room" ||
        monster->query_property(PASSED_OUT) )
        return;

    if( !running_away && sizeof( (object *)monster->query_attacker_list() ) )
        return;

    if( !mapp( dest_dir = (mapping)env->query_dest_dir_mapping() ) ||
        !sizeof(dest_dir)  )
        return;

    last_locs = monster->query_propery(LAST_LOC_PROPERTY);
    if( !pointerp(last_locs) )
        last_locs = ({ });

    move_zones = (string *)monster->query_move_zones();
    dirs = shuffle( keys(dest_dir) );
    last_used = ({ });

    foreach( tmp in dirs ) {
        if( sizeof(move_zones) ) {
            room_zones = (string *)MAP_H->query_zones( dest_dir[tmp] );
            if( !room_zones || !sizeof( move_zones & room_zones ) )
                continue;
        }

        if( member_array( dest_dir[tmp], last_locs ) == -1 ) {
            direction = tmp;
            break;
        } else
            last_used += ({ tmp });
    }

    if( !direction ) {
        if( sizeof(last_used) ) {
            direction = choice(last_used);
        } else
            return;
    }

    tmp = dest_dir[direction];

    last_locs += ({ tmp });
    if( sizeof(last_locs) > 4 )
        last_locs = last_locs[sizeof(last_locs)-4..];

    monster->add_property( LAST_LOC_PROPERTY, last_locs );
    monster->do_move(direction);

} /* do_wander_move() */

/** @ignore yes */
private void do_route_move( object monster ) {
    string direc;

    if( direc = monster->get_next_route_direction() ) {
        // Catch so that we could use runtiming, but loading rooms.
        if( catch( monster->do_command(direc) ) )
            catch( monster->do_command(direc) );
    }

    if( direc && !monster->query_stop_moving() ) {
        travellers[monster]->movetime = time() + travellers[monster]->delay;
        add_moving( monster, travellers[monster]->movetime );
    } else {
        direc = file_name( ENV(monster) );
        monster->stopped_route( direc == travellers[monster]->dest );
        map_delete( travellers, monster );
    }

} /* do_route_move() */

/**
 * This method makes all NPCs that should either wander or
 * follow their route move.
 */
private void heart_beat() {
    int time, cur_time, *times;
    object monster, *monsters;

    cur_time = time();
    monsters = ({ });

    // Separate the monsters we are going to move, and remove them
    // from the main mapping.
    foreach( time in sort_array( keys(moving) - ({ 0 }), 1 ) ) {
        if( time <= cur_time ) {
            monsters += moving[time] - ({ 0 });
            map_delete( moving, time );
        }
    }

    foreach( monster in monsters ) {
        if( travellers[monster] ) {
            do_route_move( monster );
        } else {
            times = monster->query_move_after();
            time = time() + times[ 0 ] + random( times[ 1 ] );
            if( time < time() + 2 )
                time = time() + 2;
            add_moving( monster, time );
            do_wander_move( 0, monster );
        }
    }

    if( tick++ == 100 ) {
        tick = 1;
        wanderers = filter( wanderers, (: $1 :) );
        travellers = filter( travellers, (: $1 :) );
    }

} /* heart_beat() */

/**
 * This method makes an NPC to stop wandering.
 * @param ob the NPC to stop wandering
 */
void delete_move_after( object ob ) {
    if( !undefinedp( wanderers[ob] ) ) {
        int time = wanderers[ob];

        if( !undefinedp( moving[time] ) ) {
            // Only delete if they are not going to do a route move
            // at the same moment.
            if( undefinedp( travellers[ob] ) ||
                time != travellers[ob]->movetime ) {
                moving[time] -= ({ ob, 0 });
                if( !sizeof( moving[time] ) )
                    map_delete( moving, time );
            }
        }
        map_delete( wanderers, ob );
    }
} /* delete_move_after() */

/**
 * This method puts an NPC into the random movement group.
 * This is called from the set_move_after code in the NPC object.
 * You should not need to call this function directly.
 * @param runaway whether or not this is a wimpy attempt
 * @see /std/npc->set_move_after()
 */
void move_after( int runaway ) {
    int *after;
    object monster;

    if( runaway )
        return do_wander_move( runaway, PO );

    monster = PO;

    if( pointerp( after = monster->query_move_after() ) ) {
        delete_move_after(monster);
        runaway = time() + after[ 0 ] + random( after[ 1 ] );
        wanderers[monster] = runaway;
        add_moving( monster, runaway );
    }

} /* move_after() */

/** @ignore yes */
mapping *query_dynamic_auto_load() {
    return ({ wanderers, travellers, moving });
} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping *maps ) {
    wanderers = maps[0];
    travellers = maps[1];
    moving = maps[2];
} /* init_dynamic_arg() */

/** @ignore yes */
mixed stats() {
    return ({
        ({"wanderers", sizeof(wanderers) }),
        ({"travellers", sizeof(travellers) }),
    });
} /* stats() */
