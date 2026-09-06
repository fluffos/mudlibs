#include <const.h>

/** This object is for holding information on banned names for characters --
 * swearwords, themed character names (Luc, Rodenon, Cerina, etc), system
 * names (root, flex, world), and anything else that you don't want to be
 * allowed.
 *
 * The banned names are stored as a string of regular expressions. For
 * swearwords and similar, you should call add_banned_expression, and
 * it will generate a very general regular expression that will not
 * only ban the swearword, but will also understand unusal casing,
 * (sPaM), intermediate characters (s_p_a_m), and inserting it into
 * the middle of words (_sp_am_me_is_ter). Otherwise call add_banned_name,
 * which only bans the literal spelling which you give.
 *
 * There should be wizard commands which deal with this object.
 */

/// An array of regular expressions -- all the banned names.
string *banned_names;

/** Initializes this object. If a save-file exits
 * (it must be /secure/banned_names), then it will load
 * from it, otherwise it will reset the list to banning
 * only a few important names that have system meaning.
 */
void create() {
   if( file_exists("/secure/banned_names.o") )
      restore_object( "/secure/banned_names" );
   else
      banned_names = ({ MASTER_UID + "\\>", "flex\\>", "all\\>" });
}

/** \return An array of all banned names. Each entry is
 * a string containing a regular expression. For the format
 * used, see the 'regexp' command.
 */
string *query_banned_names() {
   return banned_names;
}

/** Allows you to modify the banned names array
 * directly. Be careful with this.
 */
void set_banned_names( string *names ) {
   banned_names = names;
}

/** \return True if \a name is banned, false if it is
 * an allowed name.
 */
int query_banned( string name ) {
   string curr_exp;

   foreach( curr_exp : banned_names )
   if( sizeof(regexp(({ name }),  curr_exp)) )
      return 1;
   return 0;
}

/** Adds a banned name literally. If you only care that
 * a certain, exact string is banned (such as the root
 * UID, "root"), then you should call this function. If you
 * are trying to ban swearwords, where even permutations
 * of the word would be considered unacceptable, use
 * add_banned_expression instead.
 *
 * If you wish, you may ban a regular expression with
 * this function as well -- simply pass in the regular
 * expression as the name.
 */
void add_banned_name( string name ) {
   banned_names += ({ "^" + name + "\\>" });
   save_object( "/secure/banned_names" );
}

/** This function converts a plain string into a regular
 * expression disallowing very many permutations of it.
 * for example, if "spam" is considered a bad four-letter
 * word, then this will also block "s_p_a_m", "sP.Ammeister"
 * "xyzspamxyz" and so forth. It won't block "spaxm".
 */
void add_banned_expression( string name ) {
   int i;
   string curr_exp;

   curr_exp = ".*";
   name = lower_case(name);
   for( i = 0; i < strlen(name); i++ ) {
      if( name[i] >= 'a' && name[i] <= 'z' ) {
         curr_exp += "["+name[i..i];
         name[i] -= 32;
         curr_exp += name[i..i]+"][^A-Za-z]*";
      }
      else
         curr_exp += name[i..i] + "[^A-Za-z]*";
   }

   banned_names += ({ curr_exp });

   save_object( "/secure/banned_names" );
}
