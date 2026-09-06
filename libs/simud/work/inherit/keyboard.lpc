#include <keys.h>

/** This file is inherited by players, or any other object that
 * would be interactive and need to use the keyboard in a single-
 * character input mode. It is used to recognize escape
 * sequences.
 *
 * This component should be included in any object that needs to
 * have its own keyboard settings. Players are the primary example
 * of this. The MUD has a pretty decent set of "default" escape
 * codes built in (see keys.h), but players using unusual
 * telnet clients may need to override some of them -- this is
 * particularly common for fixing the backspace/delete fiasco.
 * This file holds their override settings. These settings are
 * manipulated by the 'keysetup' verb.
 */

/** A mapping from key escape codes to key values.
 */
mapping key_codes;

/** Guarantee that key_codes is always a mapping. */
_create_keyboard() {
   key_codes = ([ ]);
}

/** Adds an escape sequence to the player's keyboard mapping.
 */
void add_key_code( int n, string val ) {
   key_codes[val] = n;
}

/** Removes an escape sequence from the player's keyboard
 * mapping.
 *
 * \param n The key code to delete. Use the constants in keys.h.
 */
void remove_key_code( int n ) {
   string s;

   foreach( s : key_codes ) {
      if( key_codes[s] == n ) m_delete( key_codes, s );
   }
}

/** \return The entire mapping of key codes. Be warned:
 * it is indexed not by the integer values of the key
 * codes, but by the values of the keys themselves. It
 * is assumed that if you are calling this function, you
 * know what you want.
 */
mapping query_key_codes() {
   return key_codes;
}

/** Allows you to set the key codes directly.
 * Not highly recommended, but it does allow for
 * some kinds of debugging.
 *
 * \param m A mapping of key codes. The code
 * itself is the key, and the integer enumerated
 * value is the value (see keys.h). If you pass
 * in a non-mapping, it will be ignored.
 */
void set_key_codes( mapping m ) {
   if( mappingp(m) )
      key_codes = m;
}

/** Restores this player's key codes setting to
 * their defaults (no custom keys). Equivalent
 * to set_key_codes( ([ ]) );
 */
void clear_key_codes() {
   key_codes = ([ ]);
}

/** Used by any character-mode input handler that needs to recognize
 * special keys (things like up-arrow, insert, ctrl+letter, etc.)
 * Every time you receive a key outside of the normal range of
 * type-able characters, you should start collecting characters which
 * follow. The escape codes for special keys are anywhere from one to
 * five or six bytes long. Call this function each time you get a new
 * character, until it returns a value other than KEY_NONE; at this
 * point, the key pressed has been recognized.
 *
 * As a safety valve, if the key is not recognized at all, then
 * after 10 characters this function will return KEY_UNKNOWN.
 * If you get a KEY_UNKNOWN error you should flush out your key
 * collector and perhaps give an error (so the user knows what
 * happened).
 *
 * This function makes use of both the player's custom
 * set of keys (set in keysetup) and a default mapping kept in keys.h.
 */
int translate_code( string val ) {
   int k;

   if( !mappingp(key_codes) ) key_codes = ([ ]);

   if( strlen(val) > 10 )
      return KEY_UNKNOWN;

   // Check to see if val is in the player's custom list of escape codes first.
   if( k = key_codes[val] )
      return k;

   // ... and also check if it is in the standard keyboard mapping
   if( k = DEFAULT_KEYS[val] )
      return k;

   // None of that worked, so give up.
   return KEY_NONE;
}
