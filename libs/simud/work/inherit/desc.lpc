#include <const.h>
#include <sys/regexp.h>

/**
 * \c #include \c <desc.h> to use this file.
 *
 * Inheriting this object lets the derived object have a description.
 * The large majority of game objects have a description, so they will inherit this
 * object. You should include desc.h to use these functions.
 */
/// Inheritable component for defining descriptions

string name;  ///< The name of this object; generally just one word.

/** @name Sets
 * Functions for setting the variables used to describe an object.
 */
//@{
/**
 * Sets the audio file to play as background music while someone is
 * inside the object - or one of its contents.
 */
void set_bgm(string str) { SBODY("bgm", str) }

/**
 * Sets the description you get when you look at an object.
 * When a player looks at this object, they will get this
 * description. For the description on the inside of the
 * object, use set_long.
 */
void set_look(string str) { SBODY("look", str) }

/**
 * Sets the long description of a room-style object. The long description
 * is given to players or monsters who are inside the object
 * when they look around.
 */
void set_long(string str) { SBODY("long", str) }

/**
 * Sets the short (or "brief") description for a room-style object.
 * Given as the title of a room when looking.
 */
void set_short(string str) { SBODY("short", str) }

/**
 * Sets the "distant" description of an object. This is a short,
 * undetailed description of an object. It must include an indefinite article,
 * like "a dog" or "an orange," unless the word makes no sense with
 * an article, like "Bob's sword". The article should not be capitalized.
 */
void set_distant(string str) { SBODY("distant", str) }

/**
 * (Optional) Sets the specific description of an object. This is the
 * same as set_distant, except that it uses the definite article --
 * "the dog" or "the orange". You don't usually need to set this,
 * as it will be generated automatically if you leave it blank.
 * The article should not be capitalized, unless it is a proper name,
 * like "The Red Sword of Illinden."
 */
void set_specific(string str) { SBODY("specific", str) }

/**
 * (Optional) Sets the taste of an object; used for the lick soul
*/
void set_taste(string str) { SBODY("taste", str) }

/**
 * Sets the plural description of an object. This should be the plural
 * form of the name of this object, so if the object is named "soldier"
 * this should be "soldiers."
 */
void set_plural(string str) { SBODY("plural", str) }

/**
 * Sets the name for a singular unit of this object, such as:
 * one "ounce" of gold.
 */
void set_unit(string str) { SBODY("unit", str) }

/**
 * (optional) Sets the name for multiple units of this object, such as:
 * one "ounces" of gold.
 */
void set_units(string str) { SBODY("units", str) }

/**
 * Gives the object a name. This should be a short, simple name, usually
 * one word, by which players and wizards can identify the object.
 */
void set_name(string str) { name = str; }

/**
 * (Optional) Sets an alternative name. If your object is a mercenary soldier, and
 * the name is mercenary, you can set alt_name to soldier so that the MUDlib
 * is able to identify this object under either description.
 *
 * You may also pass in an array of alternative names, such as ({ "soldier", "mercenary" })
 * and then all of them will be checked.
 */
void set_alt_name(string *str) {
   if( stringp(str) )
      this_object()->set_var( "alt_name", ({ str }) );
   else
      this_object()->set_var( "alt_name", str );
}

/** Allows you to tag additional alternative names onto this
 * object. The alt_name list is stored as an array of strings.
 */
void add_alt_name( string str ) {
   if( stringp(this_object()->query_alt_name()) ) this_object()->set_var( "alt_name", ({ this_object()->query_alt_name() }) );
   if( !pointerp(this_object()->query_alt_name()) ) this_object()->set_var( "alt_name", ({ }) );
   this_object()->set_var( "alt_name", this_object()->query_alt_name() + ({ str }) );
}

/** Set the entire array of alt_plurals directly. If you pass
 * in a string, it will become the only alt_plural.
 */
void set_alt_plural( string *str ) {
   if( stringp(str) )
      this_object()->set_var( "alt_plural", ({ str }) );
   else
      this_object()->set_var( "alt_plural", str );
}

/** Add an alternative plural name to whatever ones are
 * currently set. May be called repeatedly to define multiple
 * names, though passing an array into set_alt_plural is usually easiest.
 */
void add_alt_plural( string str ) {
   if( !pointerp(this_object()->query_alt_plural()) ) this_object()->set_var( "alt_plural", ({ }) );
   this_object()->set_var( "alt_plural", this_object()->query_alt_plural() + ({ str }) );
}
/** Removes names from the list of alternative names. This
 * is simply dropping items from the list.
 */
void remove_alt_name( string str ) {
   if( stringp(this_object()->query_alt_name()) ) this_object()->set_var( "alt_name", ({ this_object()->query_alt_name() }) );
   if( !pointerp(this_object()->query_alt_name()) ) this_object()->set_var( "alt_name", ({ }) );
   this_object()->set_var( "alt_name", this_object()->query_alt_name() - ({ str }) );
}
/**
 * (Optional) Sets the object's type. This is another string by
 * which players may identify the object. Some objects which inherit this
 * one give special meaning to this variable (armour type, player character
 * type, etc).
 */
void set_type(string str) { SBODY( "type", str ); }
//@}

/**
 * @name Queries
 * Functions used for querying description-related variables.
 * See the "set" functions for more detailed information.
 */
//@{
///< Automatically generated. The name of this object based on its filename.
string query_default_name() {
   string tmp = as_string( regmatch( object_name(), "/.+/([^#]+)#*.*", RE_MATCH_SUBS )[1] );
   return implode( explode(tmp, "_"), " " );
}

///< The name of this object; generally just one word.
string query_name() {
   if( name )
      return name;
   return this_object()->query_default_name();
}

/// A brief description of the object from inside (room title).
string query_default_short() { return "Inside " + capitalize(query_name()); }

/// Automatically generated. Before vowels, "an"; otherwise, "a".
string query_default_distant() {
   if ( regmatch(query_name()[..0], "[aeiou]") )
      return "an " + query_name();
   return "a " + query_name();
}

/// Automatically generated.
string query_default_specific() { return "the " + query_name(); }

/// Automatically generated.
string query_default_plural() { return query_name() + "s"; }

/// The string given when you look at an object from inside.
string query_long() { QBODY( "long", this_object()->query_default_long() ) }

/// A brief description of the object from inside (room title).
string query_short() { QBODY( "short", this_object()->query_default_short() ) }

/// This object as a list item (include indefinite article: "a box")
string query_distant() { QBODY( "distant", this_object()->query_default_distant() ) }

/// The definite article version of the distant. Automatically generated.
string query_specific() { QBODY( "specific", this_object()->query_default_specific() ) }

/// The taste of the object, optional.
string query_taste() { QBODY( "taste", this_object()->query_default_taste() ) }

/// The background music.
string query_bgm() { QBODY( "bgm", this_object()->query_default_bgm() ) }

/// The string given when you look at an object from outside.
string query_look() { QBODY( "look", this_object()->query_default_look() ) }

/// The name of this object, pluralized (sock->socks)
string query_plural() { QBODY( "plural", this_object()->query_default_plural() ) }

/// The name of this object, pluralized (sock->socks)
string query_unit() { QBODY( "unit", this_object()->query_default_unit() ) }

/// The name of this object, pluralized (sock->socks)
string query_units() { QBODY( "units", this_object()->query_default_units() ) }

/// Alternative name(s) for this object -- for typing convenience. Guarantees returning an array.
string *query_alt_name() {
   string *ret = this_object()->query_default_alt_name();
   if( !pointerp(ret) ) ret = ({ });
   QBODY( "alt_name", ret  );
}

/// Alternative plural name(s) for this object. Guarantees an array, even if empty.
string *query_alt_plural() {
   string *ret = this_object()->query_default_alt_plural();
   if( !pointerp(ret) ) ret = ({ });
   QBODY( "alt_plural", ret  );
}

/** \return True if \a str is a plural form for the name
 * of this object; false otherwise.
 */
int query_is_plural( string str ) {
   return str == query_plural() || member(query_alt_plural(), str) >= 0;
}

/**
 * \return The name of this object capitalized.
 */
string query_cap_name() { if( stringp(query_name()) ) return capitalize(query_name()); else return 0; }

/// The "type" of this object. Sometimes used for special purposes (armour, players, etc).
string query_type() { QBODY( "type", 0 ) }
//@}

/**
 * \return A list (string separated by \\n's) of variables with set/query pairs in this object.
 *
 * This function is used by the object editor. You may call this if you wish
 * to know whether a derived object inherits this one.
 */
string desc_info() {
   return "long\nshort\ndistant\nspecific\nlook\nplural\nname\nalt_name\nalt_plural\ntype";
}

/**
 * \return true if the str "identifies" this object.
 *
 * \warning If you override the id() function, you should call ::id() as well
 * so that the values set in the object will still be checked for
 * identification.
 */
object id(string str) {
   string * possibles;

   str = lower_case("" + str);

   possibles = ({ query_name(),
                  query_specific(),
                  this_object()->query_var("distant"),
                  this_object()->query_distant(),
                  this_object()->query_var("specific"),
                  this_object()->query_plural(),
                  query_unit() + " of " + query_name(),
                  query_unit() + " of " + query_specific(),
                  query_unit() + " of " + query_distant(),
                  query_units() + " of " + query_plural(),
                  query_type()
               }) + query_alt_name() + query_alt_plural();

   possibles = map( possibles, (: ($1 != 0) ? lower_case(to_string($1)) : 0 :) );
   if ( member(possibles, str) != -1 )
      return this_object();
   possibles = map( possibles, (: ($1 != 0) ? ("the " + to_string($1)) : 0 :) );
   if ( member(possibles, str) != -1 )
      return this_object();

   // If this object is a container, check for contents; otherwise it will return 0.
//   return this_object()->container_id(str);
   // No more container transparency! It causes lots of bugs.
   return 0;
}
