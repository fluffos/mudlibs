/**
 * Utility library for dealing with the capabilities API.
 *
 * @author devo@eotl
 * @alias CapabilityLib
 */

protected int is_capable(object ob, string cap);

/**
 * Test if an object has a specified capability.
 *
 * @param  ob  the object to test
 * @param  cap the capability in question
 * @return     1 if the object has the specified capability, otherwise 0
 */
protected int is_capable(object ob, string cap) {
  mapping caps = query_capabilities(ob);
  return (member(caps, cap));
}
