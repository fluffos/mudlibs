/**
 * A base module for stuff made from living (or undead), organic matter.
 *
 * @author devo@eotl
 * @alias OrganismCode
 */

inherit StuffCode;
inherit IdMixin;

private string gender;

protected void setup() {
  IdMixin::setup();
}

public string query_gender() {
  return gender;
}

public int set_gender(string g) {
  gender = g;
  return 1;
}

/**
 * Returns true to designate that this object is a living character.
 *
 * @return 1
 */
nomask public int is_organism() {
  return 1;
}

/**
 * Set up a new living object.
 */
protected void create() {
  StuffCode::create();
  setup();
}
