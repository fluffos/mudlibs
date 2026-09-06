#include <skills.h>

/** This will be the base object for all guild objects.
 * As guilds develop further, this object will also be
 * developed.
 *
 * When a player or monster does not yet have a guild, functions normally
 * filled by a personal guild object will be relegated to the master
 * guild object, "/obj/guild". Therefore, code added to this file
 * should not assume that this object is in the inventory of this_player().
 * Derived guild objects, however, are welcome to make this assumption.
 */

/** Informs a player/living creature of an event that has occurred. This
 * is done by calling the function \a message_type in the player/living's
 * guild object passing it \a message_data and \a dest.
 *
 * Functions called should either print their message directly to \a dest
 * and return 0. If they do this, then they must pay attention to the dest
 * parameter. Alternatively, they may simply return the string to be
 * printed to the living object. In this case, this function will worry
 * about routing it correctly.
 * \param message_type The function in the guild object that will be called.
 * \param message_data (Optional) A mixed type variable with data concerning the message in it.
 * \param dest (Optional) A pointer to the object receiving the message.
 * If not specified, this_player() is assumed.
 */
varargs void inform( string message_type, mixed message_data, object dest ) {
   string val;

   if( !dest ) dest = this_player();
   if( !stringp(message_type) ) return;
   if( !function_exists(message_type, this_object()) )
      msg("(Undefined message type '"+message_type+"'): "+to_string(message_data));
   else {
      // The function called may either print the value outright, or return
      // a value to be printed here. Printing a value outright should only
      // be used when a special effect is needed; if you need to though, return
      // 0, and this function won't print anything. Otherwise, this
      // function will print the string you return.
      val = call_other( this_object(), message_type, message_data, dest );
      if( stringp(val) )
         msg_object( dest, val );
   }
}

/// Message received when your skill improves.
string skillup( string skill ) {
   string skillname;

   skillname = SKILL_NAMES[skill];
   if( !skillname ) skillname = "at "+skill;

   return "~CLABYour skill " + skillname + " ~CLABhas improved.~CDEF";
}

/// \todo This function doesn't do anything.
string showready( int val ) {
   int show_meter;

   show_meter = this_player()->query_autoready();
}
