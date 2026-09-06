/** This object holds basic scenery information -- basically a set
 * of four variables used to add the extra descriptions that scenery
 * needs in order to work. Any object that inherits this one will
 * act like a piece of scenery (meaning it will be a part of the
 * room description, rather than attached to the list at the end
 * of the description ... except in brief mode).
 */

/// Scenedesc variables; see their functions for more information
string phrase, position, preposition, closing_phrase;

/// Used by an object editor to know what is editable on this object.
string scenedesc_info() { return "phrase\nposition\npreposition"; }

/** \return The phrase associated with this piece of scenery. This is
 * generally a complete phrase, such as "There is a big rock ~plac."
 */
string query_phrase() {
   if( !this_object()->query_var("phrase") ) {
      this_object()->set_var( phrase );
      phrase = 0;
   }
   QBODY( "phrase", this_object()->query_default_phrase() );
}

/** \return The string describing this scenery's location; "here" is
 * typical. This replaces ~plac in the phrase.
 */
string query_position() { return position; }

/** The preposition appropriate for objects associating with this
 * scenery -- on, in, under, etc.
 */
string query_preposition() { return preposition; }

/** Sets the phrase this scenery adds to the room description.
 */
void set_phrase( string x ) {
   this_object()->set_var("phrase", x);
}

/** Sets the scenery's position; the position replaces ~plac in the
 * phrase.
 */
void set_position( string x ) { position = x; }

/** Sets the appropriate preposition to use with this scenery.
 * "on" for tables, "in" for chests or drawers.
 */
void set_preposition(string x) { preposition = x; }

/** \return A string describing the inventory of this object, in brief.
 * May be used as a sentence component.
 */
string get_inven_list() {
   object *ob;
   int i;

   ob = all_inventory();

   if( !sizeof(ob) ) return 0;

   return inventory_string( ob );
}

/** \return The completely processed phrase describing this piece
 * of scenery. The return value from this is used in the room
 * description.
 */
string query_scene_phrase() {
   string a, b, s, *il;

   if( !query_phrase() ) set_phrase( "There is a piece of scenery ~plac." );
   if( !position ) position = "here";
   if( sscanf(query_phrase(), "%s~plac%s", a, b) == 2 )
      s = a + position + b;
   else s = query_phrase();

   return s;
}

/** \return True, if the phrase is set; false otherwise. Allows a
 * piece of scenery to revert to a normal object, if desired.
 */
int query_scenery() { return stringp(query_phrase()); }
