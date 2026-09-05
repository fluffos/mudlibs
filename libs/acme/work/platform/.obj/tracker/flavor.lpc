/**
 * The FlavorTracker maintains the game's flavor hierarchy.
 *
 * @author devo@eotl
 * @alias FlavorTracker
 */
#pragma no_clone

#define DefaultFlavor   "acme-basic"
#define FlavorAvatar    _ObjDir "/avatar"

public void setup();
string query_avatar(string flavor, string player_id);

/**
 * Setup the FlavorTracker.
 */
public void setup() {
}

/**
 * Get the the avatar path for a flavor.
 * 
 * @param  flavor        the flavor of the avatar
 * @param  player_id     the player the avatar is for
 * @return the path to a valid avatar for the specified flavor
 */
string query_avatar(string flavor, string player_id) {
  return FlavorDir "/" + flavor + FlavorAvatar;
}

/**
 * Constructor.
 */
public void create() {
  setup();
}