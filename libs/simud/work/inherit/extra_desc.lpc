#include <const.h>

/** This is used to add extra descriptions to
 * a room without actually creating extra objects. This is
 * usually bad practice, since creating full-blown scenery
 * objects is much more flexible, but for things like
 * cave-paintings or "look at sky", this is just
 * what you need.
 *
 * Note that nothing is added to the room description by
 * these extra descriptions. Rather, this provides a mechanism
 * for allowing "look at" for any object that is mentioned
 * in the room's 'long' description but which doesn't
 * really exist.
 *
 * This object also handles local desc vars. These are
 * variables to be used only by conditional expressions
 * within this object (as opposed to global conditional
 * variables, which can be used in any object).
 */

/// A mapping of keywords to strings for local descriptions.
mapping descs;

/** A mapping of variable names to various data pieces for local
 * conditional variables.
 */
mapping desc_vars;

/// A "root" object with extended descriptions.
string desc_root;
object desc_root_ob;

/// Internal protected function. Used to get an object pointer to root object.
protected int eval_desc_root() {
   desc_root_ob = find_object( desc_root );
   if( !desc_root_ob ) desc_root_ob = find_room( desc_root, this_object() );
   if( !desc_root_ob ) desc_root = 0;
   return desc_root_ob != 0;
}

/** Adds an extra description to this object. The
 * extra description will get used when 'keyword'
 * is passed in. If you want to have multiple keywords
 * map to a single description, add the other keywords
 * as aliases:
 *
 * set_extra_desc( "waves", "!ocean" ); // When you look at waves, fetch description for ocean.
 *
 * Aliases are evaluated shallowly.
 *
 * \param keyword The keyword for referencing the
 * description.
 * \param desc The description itself.
 * \return 1 on success, which should always happen
 * as long as desc is a string.
 */
int set_extra_desc( string keyword, string desc ) {
   if( !mappingp(descs) ) descs = ([ ]);
   if( !stringp(desc) || desc == "" ) return 0;
   descs[keyword] = desc;
   return 1;
}

/** Queries one of the extra descriptions literally.
 * This will not dereference aliases. This function is
 * provided as a low-level backdoor -- if all you are
 * interested in is getting a description, use extra_id
 * instead.
 *
 * Although this function does not handle aliases, it
 * will check for extra descriptions in the description root
 * object, if there is one.
 */
string query_extra_desc( string keyword ) {
   if( mappingp(descs) && stringp(keyword) && member(descs, keyword) )
      return descs[keyword];
   if( desc_root ) {
      if( !desc_root_ob ) eval_desc_root();
      if( desc_root_ob ) return desc_root_ob->query_extra_desc( keyword );
   }
}

/** This allows you to set a "root" description object;
 * if you want to have a set of descriptions that are
 * common to many rooms, you should use this. You
 * need to create an extra_desc enabled object which
 * all of your branch objects will connect to.
 * Then, call this function in each branch object,
 * pointing them back to the root object. This will
 * make every description from the root objects
 * available in the branch objects as well.
 *
 * Root objects may themselves have root objects.
 * Be careful not to make a circular reference.
 *
 * \return True on success. The object must be valid
 * when you try to set the desc_root, or it will fail.
 */
int set_desc_root( string objref ) {
   if( !stringp(objref) ) return 0;
   desc_root = objref;
   return eval_desc_root();
}

/** \return The currently set description root object
 * reference. See set_desc_root().
 */
string query_desc_root() {
   return desc_root;
}

/** Sets a local description variable. See Simul_efun::set_global_desc_var().
 * \param var The name of the variable to set; generally an upper-case string.
 * \param val The value for this variable. String, integer, closure, or array.
 */
void set_desc_var( string var, mixed val) {
   if( !mappingp(desc_vars) ) desc_vars = ([ ]);
   if( val == 0 ) m_delete( desc_vars, var );
   else desc_vars[var] = val;
}

/** Queries a local description variable, but does not evaluate it.
 * See See Simul_efun::eval_desc_var().
 * \param var The variable whose value you wish to query.
 * \return 0 for an unset variable, the variable's value otherwise.
 */
mixed query_desc_var( string var ) {
   if( mappingp(desc_vars) )
      return desc_vars[var];
   else
      return 0;
}

/// Sets the desc_vars mapping directly.
void set_desc_vars( mapping m ) {
   desc_vars = m;
}

/// \return The entire desc_vars mapping.
mapping query_desc_vars() {
   return desc_vars;
}

/** Removes an extra description for this
 * object. See set_extra_desc().
 * \param keyword The keyword for the description you
 * wish to remove.
 * \return 1 on success, 0 if there was
 * no extra description named \a keyword.
 */
int remove_extra_desc( string keyword ) {
   if( !member(descs, keyword) ) return 0;
   m_delete( descs, keyword );
   return 1;
}

/// \return The entire descs mapping.
mapping query_descs() {
   return descs;
}

/// Sets the descs mapping directly.
void set_descs( mapping m ) {
   descs = m;
}

/** \return The string (description) associated with \a str; this is the
 * description which you should print. If there is no such description,
 * 0 is returned.
 */
string extra_id(string str) {
   string curr;
   object ob;

   if( curr = query_extra_desc( str ) )
      if( curr[0] == '!' ) return query_extra_desc( curr[1..] );
      else return curr;
   if( sscanf(str, "the %s", str) == 1 )
      return extra_id( str );
   return 0;
}
