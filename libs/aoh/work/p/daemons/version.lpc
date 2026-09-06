/*--------------------------------------------------------------------------
 * /p/daemons/version.c -- Return the current mudlib version.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * This silly small object returns the most actual version of the mudlib,
 * as available in /sys/secure/version.h.
 * On every call it checks if the file has been changed (for example by
 * the revision control system) and if yes, destructs itself so that the
 * next query will return the updated version.
 *
 * The interface function is:
 *   MudlibVersion()
 * which returns a string of the form "<major>.<minor>-<patchlevel", 
 * e.g. "0.0-35".
 *--------------------------------------------------------------------------
 */

#include <secure/config.h>
#include <secure/version.h>
#include <daemons.h>

/*--------------------------------------------------------------------------*/
nomask void create ()

{
  if (object_name(this_object()) != LIBVERSION_D)
  {
    raise_error("Illegal attempt.\n");
    destruct (this_object());
  }
}

nomask void reset ()

// Check if the /sys/secure/version.h is more recent than this object.
// If yes, selfdestruct.

{
  if (program_time() < file_date("/sys/secure/version.h"))
    destruct(this_object());
}

nomask int prevent_shadow (object shadow) { return 1; }

nomask int clean_up(int ref) { destruct(this_object()); return 0; }

/*--------------------------------------------------------------------------*/

// small helpfun to prevent call_out errors
void destruct_us() {
  if ( this_object() )
    destruct( this_object() );
}

public string
MudlibVersion ()

// Return the mudlib version as a string "<major>.<minor>-<patchlevel>",
// e.g. "0.0-0".
// The function will take care that it follows any change
// in /sys/secure/version.h with at max one call offset.

{
  if (program_time() < file_date("/sys/secure/version.h"))
    call_out( #'destruct_us, 1 );
  return LIBVERSION+"."+LIBREVISION+"-"+LIBPATCHLEVEL;
}

/***************************************************************************/
