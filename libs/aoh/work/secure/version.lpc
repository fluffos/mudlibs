/*--------------------------------------------------------------------------
 * /secure/version.c -- Update the version numbers in /sys/secure/version.h
 *
 * Copyright (C) 1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * This object is to be used to bump (increment) the version and revision 
 * number of the mudlib in /sys/secure/version.h. While doing this, it also
 * takes care of modifying the PRCS version number accordingly.
 * The bumps are logged in /log/VERSIONS, to have a small history of OSB.
 *
 * The interface functions are:
 *   int BumpRevision(string why)
 *   int BumpVersion(string why)
 * The result is 0 on success, non-0 on failure.
 *--------------------------------------------------------------------------
 */

#include <secure/config.h>

/*--------------------------------------------------------------------------*/
#define VERSIONLOG "VERSIONS"  // The log/ filename to log the bumps in.

private string *file;  // The version file as list of lines

private int lineVersion, lineRevision, linePatchlevel, linePRCS;
  // The line numbers of the Version, Revision, Patchlevel and PRCS version.
private int version, revision, prcs;
   // The parsed numbers of Version, Revision, and PRCS version.

/*--------------------------------------------------------------------------*/
nomask void create ()

{
  if (object_name(this_object()) != "/secure/version")
  {
    raise_error("Illegal attempt.\n");
    destruct (this_object());
  }
  seteuid(getuid());
}

nomask int prevent_shadow (object shadow) { return 1; }

nomask int clean_up(int ref) { destruct(this_object()); return 0; }

/*--------------------------------------------------------------------------*/
private int
ReadVersionFile()

// Read the version.h file into memory and parse it into the global variables.
// Return 0 on success, 1 on failure.

{
  string tmp;
  int i, j;

  lineVersion = -1;
  lineRevision = -1;
  linePatchlevel = -1;
  linePRCS = -1;

  // Read the file
  tmp = read_file("/sys/secure/version.h");
  if (!tmp || !sizeof(tmp))
     return 1;
  file = explode(tmp, "\n");

  // Look for the magic defines
  for (i = 0; i < sizeof(file); i++)
  {
    if (1 == sscanf(file[i], "#define %!.0tLIBVERSION %!.0t%d", j))
    {
      lineVersion = i;
      version = j;
    }
    else if (1 == sscanf(file[i], "#define %!.0tLIBREVISION %!.0t%d", j))
    {
      lineRevision = i;
      revision = j;
    }
    else if (1 == sscanf(file[i], "#define %!.0tLIBPRCSLEVEL %!.0t%d", j))
    {
      linePRCS = i;
      prcs = j;
    }
    else if (1 == sscanf(file[i], "#define %!.0tLIBPATCHLEVEL %!.0t%d", j))
    {
      linePatchlevel = i; // Just needed to reset this line
    }
  }
  
  if (lineVersion < 0
    || lineRevision < 0
    || linePRCS < 0
    || linePatchlevel < 0
      )
    return 1;
    
  return 0;
}

/*--------------------------------------------------------------------------*/
private int
WriteVersionFile()

// Write the new version.h file.
// Return 0 on success, 1 on failure.

{
  if (!rm("/sys/secure/version.h"))
    return 1;

  file[lineVersion] = "#define LIBVERSION "+version;
  file[lineRevision] = "#define LIBREVISION "+revision;
  file[linePatchlevel] = "#define LIBPATCHLEVEL 0";
  file[linePRCS] = "#define LIBPRCSLEVEL "+prcs;

  return !write_file("/sys/secure/version.h", implode(file, "\n")+"\n");
}

/*--------------------------------------------------------------------------*/
public int
BumpVersion(string why)

// Bump (increment) the library version by one, setting revision and
// patchlevel down to zero. Also increment the PRCS level.
// The bump is logged in /log/VERSIONS with 'why' (hey, having a history
// of the mud would be nice, wouldn't it?).
// 
// Return 0 on success, non-0 on failure.

{
  if (!stringp(why) || !sizeof(why) || !this_interactive())
    return 1;
  if (ReadVersionFile())
    return 1;
  version++;
  revision = 0;
  prcs++;
  if (WriteVersionFile())
    return 1;
  log_file(VERSIONLOG, ctime()+" "+getuid(this_interactive())+" New Version "
                       +version+"."+revision+" (prcs "+prcs+")\n  "+why+"\n"
          );
  return 0;
}

/*--------------------------------------------------------------------------*/
public int
BumpRevision(string why)

// Bump (increment) the library revision by one, setting patchlevel down to
// zero. Also increment the PRCS level.
// The bump is logged in /log/VERSIONS with 'why' (hey, having a history
// of the mud would be nice, wouldn't it?).
// 
// Return 0 on success, non-0 on failure.

{
  if (!stringp(why) || !sizeof(why) || !this_interactive())
    return 1;
  if (ReadVersionFile())
    return 1;
  revision++;
  prcs++;
  if (WriteVersionFile())
    return 1;
  log_file(VERSIONLOG, ctime()+" "+getuid(this_interactive())+" New Revision "
                       +version+"."+revision+" (prcs "+prcs+")\n  "+why+"\n"
          );
  return 0;
}

/***************************************************************************/
