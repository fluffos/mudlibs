/**
 * A base module for stuff made from dead or inorganic matter.
 *
 * @author devo@eotl
 * @alias ThingCode
 */

inherit StuffCode;
inherit IdMixin;

/**
 * Set up a new thing.
 */
public void create() {
  setup_id();
}

/**
 * Boilerplate id() implementation
 * @param  str the potential id
 * @return     non-zero if the id matches
 */
int id(string str) {
  return test_id(str);
}

/**
 * Returns true to designate that this object represents a thing in the game.
 *
 * @return 1
 */
nomask public int is_thing() {
  return 1;
}

/**
 * Return a zero-width mapping of the capabilities this program provides.
 *
 * @return a zero-width mapping of capabilities
 */
public mapping query_capabilities() {
  return StuffCode::query_capabilities()
         + IdMixin::query_capabilities();
}
