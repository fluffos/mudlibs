#ifndef _CATALOG_FLUFFOS_AUTO_H
#define _CATALOG_FLUFFOS_AUTO_H

/* FluffOS global include for the StickLib LDMud → FluffOS conversion. */

#define THISO this_object()
#define THISP this_player()
#define status int

void _efun_move_to(mixed dest) {
  if (dest)
    efun::move_object(dest);
}

#endif
