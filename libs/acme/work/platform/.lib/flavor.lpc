/**
 * Utility library for dealing with flavors.
 *
 * @author devo@eotl
 * @alias FlavorLib
 */

protected string get_flavor(object ob);

/**
 * Get the flavor the object belongs to.
 * TODO this probably doesn't belong here and needs a real implementation
 *
 * @param ob the object to query
 * @return   the object's flavor
 */
protected string get_flavor(object ob) {
  string name = program_name(ob);
  if (name[0..12] == "/platform/") {
    return "platform";
  }
  return "";
}
