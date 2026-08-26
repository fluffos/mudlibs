
#include <config.h>

/**
 * This method decides whether or not a specific object should be able
 * to use external databases.
 *
 * Arguments:
 *   ob is the object performing the db_* query
 *   action can be one of the following strings:
 *     connect, close, exec, commit, fetch, rollback
 *     these correspond to the db_* functions
 *   info is any extra information depending on the action
 *     For 'connect' it is an array of the form: ({ database, host, user })
 *     For 'exec' it is an array of the form: ({ exec string })
 *     For other types of action it is an empty array.
 *
 * Return value:
 *   For actions other than 'connect', a return value of 0 disallows the
 *   action and generates an error, while a return value of 1 allows the
 *   action.
 *   For 'connect', the return value can be a password for the
 *   database, or 1 if the database has no password or 0 to prevent
 *   connection.
 *
 * @param ob the object performing the db_* query
 * @param action "close", "commit", "connect", "exec", "fetch" or "rollback"
 * @param info additional data depending on the action
 * @return 1 to allow, 0 to deny, for action "connect" return the
 * password to send to the database as a string (or return 1 if no
 * password is needed)
 */
mixed valid_database( object ob, string action, mixed info ) {
    if( action == "connect") {
        switch( info[0] ) {
          case CONFIG_DB_CLUSTERS:
            return CONFIG_DB_PASS;
          case CONFIG_DB_ERRORS:
            return CONFIG_DB_PASS;
          default:
            return 0;
        }
    }

    return 1;

} /* valid_database() */
