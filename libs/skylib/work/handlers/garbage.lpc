/**
 * handler to remove junk lost in null-space from the mud
 * so they wont waste memory, and (if they have a heart_beat)
 * cpu anymore.
 * @changed Sandoz, 09/09/2002
 * Changed to not consider doors/chatters with no my_room junk.
 * The refs count should still get those.
 * @changed Sandoz, 16/10/2002
 * Added a new cleanup scheme, that will hold back on heaps of rooms
 * calling out real_clean at the same time, and that will call
 * reclaim_objects() on more sensible times.
 */

// Minimum time between reboots (28800 == 8 hours).
#define MIN_TIME 28800

// Maximum no. of faults per timer interval.
#define FAULT_RATE 8500

// How long a room has to be idle before cleaning up.
#define ROOM_IDLE_DELAY 1800

// If a room has been idle for this long don't clean it up again since
// it is probably not going to go away.
#define ROOM_STABLE_DELAY 10800

// The interval at which to do housekeeping.
#define HOUSEKEEP_INTERVAL 600

// Whether or not we don't want to automatically reboot when major page
// faults get too high.
#define AUTO_REBOOT

private int lag, maxlag, minlag;
private int faults_prev, stime_prev, utime_prev, uptime_prev;
private int rate_exceeded, times_run;

// The new clean up puts the rooms to be cleaned up in an array,
// and then calls real_clean on some of them every second.
// Once the array is empty, we call reclaim_objects().
// - Sandoz
#define NEW_CLEAN_UP

#ifdef NEW_CLEAN_UP
// sub_arr_size is the size of rooms in each subarray.
// If sub_arr_size is 0, then the rooms array contains objects,
// instead of arrays of objects.
private int sub_arr_size;
// rooms_left stores the number of room currently on the clean up list,
// to avoid calling sizeof() every time a room is being cleaned up.
// This value may be off by sub_arr_size - 1, because it is set to
// sizeof( rooms ) * sub_arr_size, whereas the last member of rooms can be
// semi-filled.  The value will be correct if the rooms array is an array
// of objects though.
private int rooms_left;
// This can be either an array of room objects,
// or an array of arrays of room objects.
private mixed rooms;
#endif

private void cycle();
private void reclaim_and_log();
private void housekeeping();
private void tidy_up();
private void check_reboot();

/** @ignore yes */
private void create() {
    mapping map;

    map = rusage();

    faults_prev = map["majflt"];
    stime_prev = map["stime"];
    utime_prev = map["utime"];

    uptime_prev = uptime();

#ifdef NEW_CLEAN_UP
    sub_arr_size = -1;
#endif

    call_out( (: housekeeping :), HOUSEKEEP_INTERVAL / 2 );
    call_out( (: cycle :), 1 );

} /* create() */

#ifdef NEW_CLEAN_UP
private void clean_up_room( object ob ) {
    if( ob ) {
        int i;
        if( catch( i = ob->real_clean() ) && ( !i && ob ) ) {
            tell_creator("sandoz", "Failed real_clean() on %O",
                file_name(ob) );
            catch( ob->clean_up() );
        }
    }
} /* clean_up_room() */

private void finish_clean_up() {
    // Let the rubbish room do what it does, and then reclaim.
    sub_arr_size = -1;
    call_out( (: reclaim_and_log :), 10 );
} /* finish_clean_up() */
#endif

/** @ignore yes */
private void cycle() {
    int diff;

    diff = real_time() - time();

    if( diff > 2 && ( lag += ( diff -= 2 ) ) > maxlag )
        maxlag = diff;
    else if( diff < minlag )
        minlag = diff;

    call_out( (: cycle :), 1 );

#ifdef NEW_CLEAN_UP
    switch( sub_arr_size ) {
      case -1:
      break;
      case 0:
        clean_up_room( rooms[0] );
        rooms = rooms[1..];
        if( !( --rooms_left ) )
            finish_clean_up();
        break;
      default:
        diff = sub_arr_size;
        while( diff-- )
            clean_up_room( rooms[0][diff] );
        rooms = rooms[1..];
        if( !( rooms_left -= sub_arr_size ) )
            finish_clean_up();
    }
#endif

} /* cycle() */

private void reclaim_and_log() {
    string log;
    int rmem, ocount;

    rmem = memory_info();
    ocount = reclaim_objects();
    rmem -= memory_info();

    log = sprintf("Reclaimed %d object%s (%d byte%s)", ocount,
        ( ocount > 1 ? "s" : ""), rmem, ( rmem > 1 ? "s" : "") );

    event( users(), "inform", log, "cpu");

    log_file("RECLAIM", "%s - %s.\n", ctime(time()), log );

} /* reclaim_and_log() */

/**
 * Filter function for the objects() efun.  We only want clones without
 * references from other objects that are not shadowing stuff,
 * not in a room and are not rooms themselves.
 */
int get_junk( object ob ) {
    return ( clonep(ob) && refs(ob) == 2 && !query_shadowing(ob) &&
             !ENV(ob) && !function_exists("query_last_visited", ob ) );
} /* get_junk() */

/**
 * @ignore yes
 * A word of explanation from Ceres.
 * The system reboots based on the rate of major page faults
 * ie. the rate of paging.  To handle updating of the drum
 * it will not reboot if prev_faults is 0 and just in case,
 * there is a minimum uptime as well.
 */
private void check_reboot() {
    int faults_now, stime_now, utime_now, reboot;
    mapping map;
    string log;

    map = rusage();

    stime_now = map["stime"];
    utime_now = map["utime"];
    faults_now = map["majflt"];

    log = "CPU usage for period = "+
        (((( utime_now - utime_prev )+( stime_now - stime_prev ) ) / 10.0 ) /
        ( uptime() - uptime_prev ) )+"% Fault rate is "+
        ( faults_now - faults_prev );

    event( users(), "inform", log, "cpu");
    log_file("CPU", ctime(time())+" - "+log+".\n");

    log = "Machine lag is "+( lag / 600 )+" seconds (average) "+
        minlag+" seconds (min) "+maxlag+" seconds (max)";

    event( users(), "inform", log, "cpu");
    log_file("CPU", log+".\n");

    // If we're already rebooting then don't do anything.
    if( SHUTDOWN_H->query_shutdown() < 10 )
        return;

#ifdef AUTO_REBOOT
    if( uptime() > MIN_TIME && faults_now > ( faults_prev + FAULT_RATE ) ) {
        if( rate_exceeded )
            reboot = 1;
        else
            rate_exceeded = 1;
    } else {
        rate_exceeded = 0;
    }
#endif

    if( reboot ) {
        SHUTDOWN_H->init_shutdown( 10, 1 );
        log_file("REBOOT", ctime(time())+" Auto; Faults: "+
            faults_now+", "+faults_prev+"; uptime: "+uptime()+"; CPU: "+
            (((( utime_now - utime_prev ) +
            ( stime_now - stime_prev ) ) / 10.0 ) /
            ( uptime() - uptime_prev ) )+"\n");
        // Get a dump of the objects before we go down.
        // dumpallobj();
        return;
    }

    faults_prev = faults_now;
    uptime_prev = uptime();
    stime_prev = stime_now;
    utime_prev = utime_now;

    lag = 0;
    maxlag = 0;
    minlag = 600;

} /* check_reboot() */

/**
 * @ignore yes
 * Do memory saving things.
 */
private void tidy_up() {
    times_run++;

#ifndef NEW_CLEAN_UP
    // Perform reclamation of unreferenced objects.
    if( !( times_run % 3 ) )
        reclaim_and_log();
#endif

    // This does a manual call of clean_up on rooms since the driver
    // doesn't do it for a couple of reasons like references,
    // which rooms have more than 1.
    // We do it every half hour after we've been up at least 1 hour.
    if( times_run > 6 && ( times_run % 3 == 1 ) ) {
        object *obs;
#ifdef NEW_CLEAN_UP
        int sz;
#endif
        obs = objects( (: function_exists("query_last_visited", $1 ) :) );

        if( ( times_run % 18 ) != 1 ) {
            // We're just doing rooms that haven't been visited for a while
            // (but not too long) and that don't want to keep loaded.
            obs = filter( obs, (: !$1->query_keep_room_loaded() &&
                $1->query_last_visited() < ( $2 - ROOM_IDLE_DELAY ) ||
                $1->query_last_visited() > ( $2 - ROOM_STABLE_DELAY ) :),
                time() );
        } else {
            // Every three hours give the stable rooms a poke too.
            obs = filter( obs, (: !$1->query_keep_room_loaded() &&
                $1->query_last_visited() < ( $2 - ROOM_IDLE_DELAY ) :),
                time() );
        }

#ifndef NEW_CLEAN_UP
        foreach( object ob in obs )
            catch( ob->clean_up() );
#else

        // Divide them into arrays of objects.
        if( ( sz = sizeof(obs) ) > HOUSEKEEP_INTERVAL ) {
            int i, j, k, cells;

            sub_arr_size = sz / HOUSEKEEP_INTERVAL + 1;

            cells = sz / sub_arr_size;

            if( sz % ( cells * sub_arr_size ) )
                cells++;

            rooms = allocate( cells, (: allocate( sub_arr_size ) :) );

            for( i = 0, k = 0; i < cells - 1; i++ )
                for( j = 0; j < sub_arr_size; j++ )
                    rooms[i][j] = obs[k++];

            for( j = 0; k < sz; k++ )
                rooms[i][j++] = obs[k];

            rooms_left = cells * sub_arr_size;

        } else {
            if( rooms_left = sizeof( rooms = obs ) )
                sub_arr_size = 0;
            else
                sub_arr_size = -1;
        }
#endif

        log_file("CLEAN_UP", "%s Cleaning %d idle rooms. Current "
            "memory %.2fMB\n", ctime(time()), sizeof(obs),
            memory_info() / 1024000.0  );

        event( users(), "inform", sprintf("Cleaning %d idle rooms",
            sizeof(obs) ), "cpu");
    }

} /* tidy_up() */

/** @ignore yes */
private void housekeeping() {
    object *junk;

    call_out( (: check_reboot :), 10 );
    call_out( (: tidy_up :), 20 );
    call_out( (: housekeeping :), HOUSEKEEP_INTERVAL );

    junk = objects( (: get_junk :) );

    foreach( object ob in junk ) {
        log_file("NULLSPACEJUNK", "%s - %O (%O) cloned by %O.\n",
            ctime(time()), ob, ob->query_short(), ob->query_cloned_by() );
        catch( ob->dest_me() );
        if( ob )
            destruct(ob);
    }

} /* housekeeping() */

/** @ignore yes */
int query_faults_prev() { return faults_prev; }

/** @ignore yes */
mixed stats() {
    return ({
        ({"lag", lag }),
        ({"maxlag", maxlag }),
        ({"minlag", minlag }),
        ({"previous faults", faults_prev }),
        ({"previous stime", stime_prev }),
        ({"previous utime", utime_prev }),
        ({"previous uptime", uptime_prev }),
        ({"rate exceeded", rate_exceeded }),
        ({"times run", times_run }),
#ifdef NEW_CLEAN_UP
        ({"array size", ( sub_arr_size != -1 ? sub_arr_size : 0 ) }),
        ({"rooms left", rooms_left }),
#endif
        });
} /* stats() */
