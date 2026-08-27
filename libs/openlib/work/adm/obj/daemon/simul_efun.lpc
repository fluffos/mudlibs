/*  -*- LPC -*-  */
// Simulated Efuns file

#include <dirs.h>

void
create()
{
  efun::set_privs(this_object(), save_variable(1));  // set our privs here
}

// Get the object id number of a clone

varargs int
getoid(object ob)
{
  int id;

  if( !ob )
    ob = previous_object();

  sscanf(file_name(ob), "%*s#%d", id);
  return id;
}

// Get the owner of a file.  Used by log_error() in master.c.

string
file_owner(string file)
{
  string name, rest, dir;

  if( sscanf(file, USER_DIR "/%s/%s/%s", dir, name, rest) == 3 )
    return name;
  else
    return 0;
}

// Get the simul_efun object...analogous to master()

object
simul_efun()
{
  return this_object();
}

// This file has all the efuns includes in it.
#include "simul_efun/efuns.h"
