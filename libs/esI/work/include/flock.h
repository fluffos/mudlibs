//
// File: flock.h
// Creator: Robocoder@TMI-2 (06-22-93)
//
// File locking definitions/declarations.
//

#ifndef __FLOCK
#define __FLOCK

#include <daemons.h>

// To enable logging:
//   #define FILE_LOG in $(MUDLIB)/include/logs.h

// For more selective logging, #define NON_CRITICAL_PATHS
// in $(MUDLIB)/include/flock.h.
// This should be a list of paths that // _should not_ be logged.
// For example,
//   #define NON_CRITICAL_PATHS "/tmp/","/open/"
// Note: the leading and trailing slashes, the quotes around each top level
//   path, and the commas for delimeters.
#define NON_CRITICAL_PATHS "/tmp/","/open/","/ftp/","/u/"

// #define REUSE_ED_LOCK_KLUDGE to enable a kludge to reuse an unfreed
// editor lock; this can be useful if CMD_ED was updated or manually
// destructed--clean_up() should return 0 to prevent the driver from
// removing it from memory--while the ed command was in use, thus preventing
// a callback to free the lock; this is a temporary workaround for what
// is inherently a driver feature (or bug, depending on your POV); this
// is not a precedent for adding further kludges to this daemon; this
// "enhancement" should satisfy the majority of B&Mers though
#define REUSE_ED_LOCK_KLUDGE

/***************************************************************************/

/*
 * modes
 */
#define F_LOCK    0
#define F_UNLOCK  1

/*
 * file_lock(string path, int mode)
 *   - non-blocking call to daemon;
 *   - returns TRUE if successful, FALSE otherwise
 */
#define file_lock(path, mode) (int) FLOCK_D->flock(path, mode)

/*
 * query_lock_object(string path)
 *   - returns object locking that file
 */
#define query_lock_object(path) (object) FLOCK_D->query_lockobj(path)

/*
 * free_locks(object player)
 *   - frees locks associated with a player object
 *   - doesn't return anything
 */
#define free_locks(player) (void) FLOCK_D->free_lockobj(player)

/*
 * query_lock_filename(object locker)
 *   - returns name of a file locked by that object
 *   - warning: may not be reliable if object has more than 1 lock outstanding
 */
#define query_lock_filename(locker) (string) FLOCK_D->query_lockfn(locker)

/*
 * query_locks()
 *   - prints names of locked files, and object that owns the lock
 *   - no return value
 */
#define query_locks() (void) FLOCK_D->dump_locks()

#endif
