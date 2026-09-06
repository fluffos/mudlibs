#include <const.h>

/** This object handles all the variables associated with
 * objects used for blocking exits. It is not strictly necessary
 * for an object to inherit this one in order to be used for
 * blocking exits. This object does allow you to have a lot
 * more flexibility in the way you handle exit blocking, though,
 * with things like special messages when the blocker stops
 * or passes someone, etc.
 */

/// A function used by the object editor to find internal variables.
string blocker_info() { return "block_message\nblock_visible\npass_message"; }

string block_message, ///< The message given when the exit is blocked.
       pass_message;  ///< The message given when someone is allowed to pass, if any.

/** If this flag is true, the blocker will be visible in the descriptions of the
 * rooms it's doing its blocking in. You still have to set a description for
 * it, of course.
 */
int block_visible;

/// \return The message returned when this object blocks something.
string query_block_message() { return block_message; }

/// \return The message returned when something is allowed to pass this object.
string query_pass_message() { return pass_message; }

/// \return True if this blocker should be visible in the room it's blocking in.
int query_block_visible() { return block_visible; }

/// Sets the "exit is blocked" message to \a x.
void set_block_message( string x ) { block_message = x; }

/// Sets the "passage allowed" message to \a x.
void set_pass_message( string x ) { pass_message = x; }

/// Sets the block_visible flag.
void set_block_visible(int x) { block_visible = x; }
