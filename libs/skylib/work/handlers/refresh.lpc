/**
 * This is the Refresh Handler.  When a player refreshes or
 * gets deleted, this handler is called upon, so that all the
 * miscellaneous bookkeeping about that player can be reset.
 * This should be used for taking someone out of the playtesters'
 * group, resetting their criminal status, etc.  Everything,
 * in short, which is not a property on the player object or otherwise
 * can be handled entirely by the player object without using any other
 * objects.
 *
 * If you have code that stores information about a player outside of
 * the player object, then you should call register_delete() on this
 * handler.  That will then remember the function you give it.
 * Then, whenever a player refreshes or deletes, the function you
 * specified will get called with a string with the player
 * name.  Do the right thing.
 *
 * If your object moves to a different file, then you will
 * have to manually unregister the object from the refresh
 * handler.  This is very important!  To unregister, simply
 * call register_delete() again, with the same object, but
 * give 0 for the function.
 *
 * Each object can have only one refresh function registered,
 * and clones can't have any!
 *
 * The callback functions should be in the form of -
 *    void callback_func( string player )
 *
 * @author Sin
 *
 * @change 17 Nov 1998, Sin
 *     Handles deletions now, too.
 * @change 04 Aug 2001, Sandoz
 *     Stripped all the refresh stuff and left only one type of deletion.
 *     Fixed a few things regarding removing callback functions.
 */

#include <playerinfo.h>
#include <origin.h>

#define SAVE_FILE "/save/refresh"

mapping delete_callbacks;

/** @ignore yes */
protected void save_me() {
    unguarded( (: save_object, SAVE_FILE, 0 :) );
} /* save_me() */

/** @ignore yes */
/* This is used to make the player info handler happy */
string query_name() { return "Refresh Handler"; }

/** @ignore yes */
void create() {
    seteuid( master()->creator_file( file_name(TO) ) );

    unguarded( (: restore_object, SAVE_FILE :) );

    if( !delete_callbacks )
        delete_callbacks = ([ ]);

} /* create() */

/** @ignore yes */
void dest_me() {
    destruct(TO);
} /* dest_me() */

/**
 * Use this function to tell the refresh handler about functions that
 * you want to have called whenever any player refreshes or gets
 * deleted.
 *
 * Typically, you will call this by hand, with the 'call' command,
 * rather than coding a call to this function into your code.
 *
 * The first parameter is the object that contains the callback
 * to be called.  This can be either a pointer to the object, or
 * the filename to the object.
 *
 * The second parameter is the name of the function that should be
 * called.  This callback should take one parameter: a string
 * containing the player's name who's data is being deleted.
 *
 * This function will refuse to register a callback if either:
 * the object is a clone, the callback isn't defined in the object, or
 * the callback is a function pointer.
 * @see unregister_delete()
 */
string register_delete( mixed ob, string func ) {
    object real;

    if( objectp(ob) ) {
        if( !ob = base_name(ob) )
            return "Please supply an object.";
    }

    if( !real = load_object(ob) )
        return "Couldn't find the object.";

    if( !func || !function_exists( func, real ) )
        return "Couldn't find the callback function.";

    if( !undefinedp( delete_callbacks[ob] ) && delete_callbacks[ob] == func )
        return "Callback function already registered.";

    delete_callbacks[ob] = func;
    save_me();

    return "Delete callback function successfully added.";

} /* register_delete() */

/**
 * This method unregisters a deletion call back function.
 * @param ob the object to remove
 * @param fun the function to remove
 * @return 1 upon success, 0 upon failure
 */
int unregister_delete( string ob, string fun ) {
    if( adminp( previous_object(-1) ) &&
        !undefinedp( delete_callbacks[ob] ) && delete_callbacks[ob] == fun ) {
        map_delete( delete_callbacks, ob );
        save_me();
        return 1;
    }
    return 0;
} /* unregister_delete() */

/**
 * This method goes through and calls all the registered deletion
 * callbacks.  The parameter passed to the deletion callbacks is
 * a string containing the name of the player who is being deleted.
 */
void player_deleted( string player ) {
    string ob;

    if( origin() != ORIGIN_LOCAL &&
        file_name(PO) != BULK_DELETE_H ) {
        return;
    }

    foreach( ob in keys( delete_callbacks ) ) {
        object obj;

        catch( obj = load_object(ob) );

        if( !obj ) {
            log_file("BAD_DEL_CALLBACK", "File : %s, Function : %s\n",
                     ob, delete_callbacks[ob] );
            continue;
        }
        call_out( (: call_other, obj, ({ delete_callbacks[ob], player }) :), 1 );
    }

} /* player_deleted() */

/**
 * This function gets called by the player object whenever
 * a player refreshes.  You should never call this function directly.
 */
void player_refreshed( object player ) {

    if( !player || base_name(PO) != PLAYER_OBJ )
        return;

    // Slip an event into their playerinfo.
    PLAYERINFO_HANDLER->add_entry( TO, player->query_name(), "refresh",
                                   "They did a full refresh.", 0 );

    // Delete their stuff.
    player_deleted( player->query_name() );

} /* player_refreshed() */

/**
 * This method returns the current list of deletion callback functions.
 * @return the current list of deletion callback functions
 */
mapping query_delete_callbacks() { return delete_callbacks; }

/** @ignore yes */
mixed stats() {
    return map( sort_array( keys( delete_callbacks ), 1 ),
        (: ({ $1, $2[$1] }) :), delete_callbacks );
} /* stats() */
