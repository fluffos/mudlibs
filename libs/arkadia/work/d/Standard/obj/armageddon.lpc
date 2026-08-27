/*
 * /d/Genesis/obj/armageddon.c
 *
 * Revision history:
 * /Mercade, August 5th 1994, general revision of the Armageddon system.
 */

#pragma no_clone
#pragma no_inherit
#pragma save_binary
#pragma strict_types

inherit "/secure/armageddon";

#include <std.h>

#define ARMA_TELL    "/d/Standard/obj/arma_tell"
#define ARMA_TELL_ID "_arma_tell_"

/*
 * Function name: shutdown_started
 * Description  : Whenever a shutdown is announced, all mortal players
 *                should get an object allowing them to use tell.
 */
void
shutdown_started()
{
}

/*
 * Function name: shutdown_stopped
 * Description  : If a previously announced shutdown is canceled by
 *                the authorizing wizard, the players should loose their
 *                tell-object again.
 * Arguments    : string shutter - the one who decided not to shut down.
 */
void
shutdown_stopped(string shutter)
{
}