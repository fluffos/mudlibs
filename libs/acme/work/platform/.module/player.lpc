/**
 * A module to support player objects.
 *
 * @author devo@eotl
 * @alias PlayerMixin
 */
#pragma no_clone
#include <capability.h>

virtual inherit AvatarMixin;
virtual inherit SoulMixin;

private mapping CAPABILITIES_VAR = ([ CAP_PLAYER ]);

private int enabled;
private string player;

public void setup();
public void teardown();
int is_player();
void set_player(string player_id);
string query_player();

/**
 * Setup the PlayerMixin.
 */
public void setup() {
  AvatarMixin::setup();
  SoulMixin::setup();
  enabled = 1;
}

public void teardown() {
  AvatarMixin::teardown();
  SoulMixin::teardown();
  enabled = 0;
}

/**
 * Returns true to designate that this object represents a player.
 *
 * @return 1
 */
int is_player() {
  return enabled;
}

/**
 * Set the player id of this player object.
 * 
 * @param player_id the player id
 */
void set_player(string player_id) {
  player = player_id;
}

/**
 * Query the player id of this player object.
 * 
 * @return the player id
 */
string query_player() {
  return player;
}
