#ifndef _CATALOG_FLUFFOS_AUTO_H
#define _CATALOG_FLUFFOS_AUTO_H

/* FluffOS global include for the LDMud → FluffOS conversion.
 * LDMud `status` is a boolean/int synonym. Every compiled object also
 * gets a 1-arg efun::move_object helper so the 2-arg simul can move
 * clones that are not this_object() (FluffOS efun is 1-arg only). */

#define THISO this_object()
#define THISP this_player()
#define status int

void _efun_move_to(mixed dest) {
  if (dest)
    efun::move_object(dest);
}

#endif
