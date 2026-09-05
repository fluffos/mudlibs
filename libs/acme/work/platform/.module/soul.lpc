/**
 * Support for items capable of communication by emoting.
 *
 * @author devo@eotl
 * @alias SoulMixin
 */
#pragma no_clone
#include <capability.h>

private mapping CAPABILITIES_VAR = ([ CAP_SOUL ]);
//private string CMD_IMPORTS_VAR = PlatformBinDir "/soul.cmds";

private int enabled;

public void setup();
public void teardown();
int has_soul();

/**
 * Setup the SoulMixin.
 */
public void setup() {
  enabled = 1;
}

/**
 * Tear down the SoulMixin.
 */
public void teardown() {
  enabled = 0;
}

/**
 * Return true to indicate this object has a soul.
 * 
 * @return 1
 */
int has_soul() {
  return enabled;
}
