
#include <player_handler.h>
#include <origin.h>

#define ERASE_RATE 30
#define ONE_DAY (60*60*24)
#define MIN_DELAY (30*ONE_DAY)
#define MAX_DELAY (600*ONE_DAY)
#define TIMES_AGE 30

#define FOLDER_H     HANDLER_DIR "/folder_handler"
#define PLAYERINFO_H HANDLER_DIR "/playerinfo"

#define ALPHABET ({ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", \
                    "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", \
                    "w", "x", "y","z" })

#define SAVEFILE SECURE_DIR SAVE_DIR HANDLER_DIR "/bulk_delete.os"

int last_log_on, time_on, creator;
mapping map_prop;

nosave string *dirs, current;

private void delete_name(string name);
private void check_name(string name);
protected void do_delete_check();

/** @ignore yes */
protected void create() {
    string var;

    seteuid("Root");
    dirs = ({ });

    if( file_exists(SAVEFILE) ) {
        var = unguarded( (: read_file, SAVEFILE :) );
        dirs = restore_variable(var);
    }

    call_out("continuous_erase", 1 );
    unguarded( (: do_delete_check() :) );

} /* create() */

/** @ignore yes */
protected void reset() {
    string var;

    var = save_variable(dirs);
    unguarded( (: write_file, SAVEFILE, var, 1 :) );

    if( find_call_out("continuous_erase") == -1 )
        call_out("continuous_erase", 1 );

} /* reset() */

/** @ignore yes */
void delete_related_files( string name, int mail ) {
    string *files;

    if( origin() != ORIGIN_LOCAL && TP && TP->query_name() != name &&
        PO != find_object("/cmds/admin/rmp_layer") &&
        PO != find_object("/secure/cmds/lord/securitytool") ) {
        user_event("inform", sprintf("Not doing erasing in "
            "delete_related_files. PO : %O", PO ), "admin");
        unguarded( (: write_file, "/log/CHEAT", ctime( time() )+
            ": illegal attempt to delete related files using "+
            file_name(TO)+"\nTP : "+( TP ? file_name(TP)+" ("+
            TP->query_name()+")" : 0 )+"\nTrace: "+ back_trace() :) );
        return;
    }

    REFRESH_H->player_deleted( name );
    PLAYER_H->delete_from_cache( name );

    unguarded( (: rm, "/save/artifacts/"+name :) );
    unguarded( (: rm, "/save/cmr_library/"+name+".o" :) );
    unguarded( (: rm, "/save/bank_accounts/"+name[0..0]+"/"+name+".o" :) );

    if( sizeof( files = get_dir( "/w/.dead_ed_files/"+name+"-*" ) ) )
        map( files, (: unguarded( (: rm, "/w/.dead_ed_files/"+ $1 :) ) :) );

    if( mail ) {
        // We only delete their player info if we also delete their mail.
        FOLDER_H->delete_account( name );
        PLAYERINFO_H->player_remove( name );
        BOARD_H->delete_player( name );
    }

} /* delete_related_files() */

protected void do_delete_check() {
    string *bits, name;
    mixed rubbish;

    call_out("do_delete_check", ONE_DAY );

    bits = get_dir( PLAYER_SAVE_DIR+DELETE_DIR+"/*.o" );

    foreach( string bit in bits ) {
        rubbish = stat( PLAYER_SAVE_DIR+DELETE_DIR+"/"+bit );
        if( rubbish[1] + ( ONE_DAY * 10 ) < time() ) {
            sscanf( bit, "%s.o", name );
            log_file("EXPIRED", "%s Requested player deletion: %s.\n",
                                ctime(time()), name );
            user_event("inform", "Auto deleting user "+CAP(name), "delete");
            delete_related_files( name, 1 );
            unguarded( (: rm( PLAYER_SAVE_DIR+DELETE_DIR+"/"+$(bit) ) :) );
        }
    }

} /* do_delete_check() */

/** @ignore yes */
protected void continuous_erase( string *all_files ) {

    if( !sizeof(all_files) ) {
        if( !sizeof(dirs) )
            dirs = ALPHABET;

        current = dirs[random(sizeof(dirs))];
        dirs -= ({ current });
        all_files = get_dir( PLAYER_SAVE_DIR + current + "/*.o" );
    }

    if( sizeof(all_files) )
        check_name( all_files[0][0..<3] );

    call_out("continuous_erase", ERASE_RATE, all_files[1..] );

} /* continuous_erase() */

/** @ignore yes */
private void check_name( string name ) {
    int age;

    if( find_player(name) )
        return;

    if( !PLAYER_H->test_user(name) ) {
        delete_name(name);
        return;
    }

    unguarded( (: restore_object, LOGIN_OBJ->query_player_file_name(name) :) );

    if( creatorp(name) || creator || map_prop["no delete"] )
        return;

    // Logged on within MIN_DELAY.
    if( last_log_on > time() - MIN_DELAY )
        return;

    // TIME_AGE times age or MAX_DELAY.
    age = time_on * TIMES_AGE;
    if( age < -MAX_DELAY )
        age = -MAX_DELAY;

    // They have not reached their idle limit yet.
    if( age < last_log_on - time() )
        return;

    delete_name(name);

} /* check_name() */

/** @ignore yes */
private void delete_name( string name ) {
    string pfile;

    if( !pfile = (string)LOGIN_OBJ->query_player_file_name(name) ) {
        log_file("FAILED_DELETE", "%s Failed to delete %s - No player file in "
            "login ob!\n", ctime(time()), name );
        return;
    }

    user_event("inform", "Deleting timed out user "+CAP(name), "delete");
    log_file("EXPIRED", "%s Timed out player deletion: %s\n",
                        ctime(time()), name );

    delete_related_files( name, 1 );
    rm( pfile+".o" );

} /* delete_name() */

/** @ignore yes */
int delete_files( string letter ) {
    string *all_files;

    if( !sizeof( filter( previous_object(-1), (: interactive($1) :) ) ) ) {
        unguarded( (: write_file, "/log/CHEAT", ctime( time() )+
                   ": illegal attempt to delete timed out player files using "
                   "BULK_DELETE_H.\nTrace: " + back_trace() :) );
        return 0;
    }

    if( !adminp( previous_object(-1) ) ) {
        unguarded( (: write_file, "/log/CHEAT", ctime( time() )+
                   ": illegal attempt to delete timed out player files using "
                   "BULK_DELETE_H.\nTrace: " + back_trace() :) );
        return 0;
    }

    log_file("EXPIRED", "%s Manually Requested Processing of %s.\n",
                        ctime(time()), letter );

    all_files = get_dir( PLAYER_SAVE_DIR+ letter +"/*.o" );

    if( !sizeof(all_files) )
        return notify_fail("Directory empty.\n");

    // Put the current current back into the array so it's not skipped.
    dirs += ({ current });
    // Make the requested letter current.
    current = letter;
    // Remove the new current letter from the array.
    dirs -= ({ current });
    // Remove the old call out.
    remove_call_out("continuous_erase");
    call_out("continuous_erase", 5, all_files );

    return 1;

} /* delete_files() */

/** @ignore yes */
int clean_up_files( string dir ) {
    int i;
    string *all_files = ({ });

    if( !sizeof( filter( previous_object(-1), (: interactive($1) :) ) ) ) {
        unguarded( (: write_file, "/log/CHEAT", ctime( time() )+
                   ": illegal attempt to delete unused files using "
                   "BULK_DELETE_H.\nTrace: " + back_trace() :) );
        return 0;
    }

    if( !adminp( previous_object(-1) ) ) {
        unguarded( (: write_file, "/log/CHEAT", ctime( time() )+
                   ": illegal attempt to delete unused files using "
                   "BULK_DELETE_H.\nTrace: " + back_trace() :) );
        return 0;
    }

    switch( dir ) {
      case "artifacts" :
        all_files = get_dir("/save/"+ dir +"/*");
      break;
      case "mail" :
        all_files = get_dir("/save/"+ dir +"/*inbox.o");
      break;
      case "bank_accounts" :
      case "library" :
        all_files = get_dir("/save/"+ dir +"/*.o");
      break;
      case ".dead_ed_files" :
        all_files = get_dir("/w/.dead_ed_files/");
      break;
      default :
        return notify_fail("Invalid directory.\n");
    }

    all_files -= ({ ".", ".." });

    if( !sizeof(all_files) )
        return notify_fail("Directory empty.\n");

    for( i = sizeof(all_files) - 1; i > -1; i-- ) {
      switch( dir ) {
        case "artifacts" :
          call_out((: check_name :), 5 * (i + 1), all_files[i]);
        break;
        case "mail" :
          call_out((: check_name :), 5 * (i + 1),
                                     explode( all_files[i], "inbox")[0] );
        break;
        case ".dead_ed_files" :
          call_out((: check_name :), 5 * (i + 1),
                                     explode( all_files[i], "-")[0] );
        break;
        default :
          call_out((: check_name :), 5 * (i + 1), all_files[i][0..<3]);
        break;
      }
    }

    return 1;

} /* clean_up_files() */

/** @ignore yes */
mixed stats() {
    return ({
        ({"current letter", current }),
        ({"remaining dirs", sizeof(dirs) ? implode( dirs, ", ") : 0 }),
    });
} /* stats() */
