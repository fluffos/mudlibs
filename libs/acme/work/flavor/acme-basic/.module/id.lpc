/**
 * Support for objects which can be identified on the command line.
 *
 * @author devo@eotl
 * @alias IdMixin
 */

#include <capabilities.h>

private variables private functions inherit ArrayLib;

default private variables;

string primary_id, *secondary_ids, *ids;

default public functions;

private void update_ids();

/**
 * Returns the primary id of the object. An object may only have one primary
 * id. This id can be used to give hints to the player about how to refer to
 * the object on the command line.
 *
 * @return the primary id, or 0 if the object has no primary id
 */
string query_primary_id() {
  return primary_id;
}

/**
 * Set the primary id of the object.
 *
 * @param str the new primary id
 * @return    0 for failure, 1 for success
 * @see       query_id()
 */
int set_primary_id(string str) {
  primary_id = str;
  update_ids();
  return 1;
}

/**
 * Return the secondary ids of the object. An object may have any number of
 * secondary ids. These ids may be used to identify the object, but should
 * not be used when giving player usage instructions.
 *
 * @return the array of secondary ids
 */
string *query_secondary_ids() {
  return secondary_ids;
}

/**
 * Set all secondary ids of the object. Any previously set secondary ids will
 * be overwritten by this list.
 *
 * @param str the array of secondary ids
 * @return    0 for failure, 1 for success
 * @see       query_secondary_ids()
 */
int set_secondary_ids(string *str) {
  secondary_ids = str;
  update_ids();
  return 1;
}

/**
 * Add a new secondary id to the object. If the object already has the
 * secondary id, it will be shifted to the end of the array.
 *
 * @param str the secondary id
 * @return    0 for failure, 1 for success
 * @see       query_secondary_ids()
 */
int add_secondary_id(string str) {
  secondary_ids -= ({ str });
  secondary_ids += ({ str });
  update_ids();
  return 1;
}

/**
 * Remove a secondary id from the object.
 *
 * @param str the secondary id to remove
 * @return    0 for failure, 1 for success
 * @see       query_secondary_ids()
 */
int remove_secondary_id(string str) {
  secondary_ids -= ({ str });
  update_ids();
  return 1;
}

/**
 * Return a list of all the ids of the object. This is the primary id plus
 * any secondary ids which have been applied to the object.
 *
 * @return an array of all ids
 */
string *query_ids() {
  return ({ primary_id }) + secondary_ids;
}

/**
 * Test whether a string matches one of the ids applied to this object.
 *
 * @param  str the string to test
 * @return     1 if the string is a valid id, 0 if not
 */
int test_id(string str) {
	return ( (str == primary_id) || (member(secondary_ids, str) != -1) );
}

/**
 * Update the list of combined primary and secondary ids.
 */
private void update_ids() {
  ids = unique_array(({ primary_id }) + secondary_ids);
  return;
}

/**
 * Initialize IdMixin. If this function is overloaded, be advised that the
 * mixin's private variables are initialized in the parent implementation.
 */
protected void setup_id() {
  primary_id = 0;
  secondary_ids = ({ });
}

/**
 * This function is here to support the present() efun.
 *
 * @param  str the id to test
 * @return     1 if the string is a valid id, 0 if not
 */
int id(string str) {
  return test_id(str);
}

/**
 * Return the capabilities this mixin provides.
 *
 * @return the 'id' capability
 */
public mapping query_capabilities() {
  return ([ CAP_ID ]);
}
