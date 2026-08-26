/**
 * This handler deals with clocks which chime. It uses a single 15 minute
 * callout to make all clocks on the mud which choose to chime chime the
 * quarter, half or hours.
 * @author Ceres
 * @changed Rewrote parts and changed to work on Divided Sky, Sandoz 2002.
 */

#include <time.h>
#include <chime.h>

#define QUARTER (SECONDS_PER_MINUTE*MINUTES_PER_HOUR/CHIME_QUARTER_HOUR)
#define HALF    (SECONDS_PER_MINUTE*MINUTES_PER_HOUR/CHIME_HALF_HOUR)
#define HOUR    (SECONDS_PER_MINUTE*MINUTES_PER_HOUR/CHIME_HOUR)

class chime *quarter_list, *half_list, *hour_list;
int call_id;

private void check_chimes();
private void do_chime( class chime record, int type );

/** @ignore yes */
private void start_ticking() {

    if( call_id ) {
        remove_call_out( call_id );
        call_id = 0;
    }

    if( sizeof(quarter_list) ) {
        call_id = call_out( (: check_chimes :),
            ( 1 + QUARTER ) - time() % QUARTER );
        return;
    }

    if( sizeof(half_list) ) {
        call_id = call_out( (: check_chimes :),
            ( 1 + HALF ) - time() % HALF );
        return;
    }

    if( sizeof(hour_list) ) {
        call_id = call_out( (: check_chimes :),
            ( 1 + HOUR ) - time() % HOUR );
        return;
    }

} /* start_ticking() */

/** @ignore yes */
void create() {
    quarter_list = ({ });
    half_list = ({ });
    hour_list = ({ });
    start_ticking();
} /* create() */

/**
 * Register a clock to do chimes. The num parameter specifes when to
 * chime.  If it is 1 then the clock chimes every hour, if it is
 * 2 the clock chimes ever half hour, if it is 4 the
 * clock chimes every quarter hour.  Anything else and
 * the clock never chimes.  NB: if you set it to chime the quarter hours
 * it will only chime the quarter hours, it will not chime the hours
 * or the half hours.  You need to call this function three times to
 * get your clock to chime the hour, half and quarter hours.
 * Repeated calls to this function from the same object will only
 * overwrite the previous messages assigned to the object.
 * <p>
 * The function "do_chime" will be called on the clock
 * when the chime occurs.  The message will be passed in as the first
 * argument, the second will be the type of chime (CHIME_HOUR, CHIME_HALF_HOUR,
 * CHIME_QUARTER_HOUR).
 * @param ob the object being registered
 * @param num when to chime
 * @param mess the message to chime with, can be an array of messages as well
 */
int register_for_chimes( object ob, int num, mixed mess ) {
    class chime record, *tmp;
    int found;

    switch( num ) {
      case 1:
        tmp = hour_list;
        break;
      case 2:
        tmp = half_list;
      break;
      case 4:
        tmp = quarter_list;
      break;
      default:
        return 0;
    }

    foreach( record in tmp ) {
      if( record->ob == ob ) {
          found = 1;
          break;
      }
    }

    if( !found )
        record = new( class chime );

    record->ob = ob;
    record->mess = mess;

    if( !found ) {
        switch( num ) {
          case 1:
            hour_list += ({ record });
            break;
          case 2:
            half_list += ({ record });
            break;
          case 4:
            quarter_list += ({ record });
            break;
          default:
            return 0;
        }
    }

    start_ticking();
    return 1;

} /* register_for_chimes() */

/** @ignore yes */
private void check_chimes() {
    class chime record;

    call_out( (: start_ticking :), 4 );

    quarter_list = filter( quarter_list, (: objectp( $1->ob ) :) );
    half_list = filter( half_list, (: objectp( $1->ob ) :) );
    hour_list = filter( hour_list, (: objectp( $1->ob ) :) );

    if( time() % HOUR < 4 ) {
        if( sizeof(hour_list) )
            foreach( record in hour_list )
                do_chime( record, CHIME_HOUR );
    } else if( time() % HALF < 4 ) {
        if( sizeof(half_list) )
            foreach( record in half_list )
                do_chime( record, CHIME_HALF_HOUR );
    } else if( time() % QUARTER < 4 ) {
        if( sizeof(quarter_list) )
            foreach( record in quarter_list )
                do_chime( record, CHIME_QUARTER_HOUR );
    }

} /* check_chimes() */

/** @ignore yes */
private void do_chime( class chime record, int type ) {

    if( !record || !record->ob )
        return;

    (record->ob)->do_chime( record->mess, type );

} /* do_chime() */

/** @ignore yes */
void init_dynamic_arg( mapping map ) {
    if( !mapp(map) )
        return;

    if( map["quarter"] )
        quarter_list = map["quarter"];
    if( map["half"] )
        half_list = map["half"];
    if( map["hour"] )
        hour_list = map["hour"];

    start_ticking();

} /* init_dynamic_auto_load() */

/** @ignore yes */
mapping query_dynamic_auto_load() {
    mapping map;

    map = ([ ]);

    if( sizeof(quarter_list) )
        map["quarter"] = quarter_list;
    if( sizeof(half_list) )
        map["half"] = half_list;
    if( sizeof(hour_list) )
        map["hour"] = hour_list;

    return map;

} /* query_dynamic_auto_load() */
