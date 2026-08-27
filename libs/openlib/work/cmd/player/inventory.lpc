/*  -*- LPC -*-  */
// Orig by someone way back when :)
// Rewritten by Tim 22 Apr 96 to use list_obs() efun

#include <command.h>

int
main()
{
  object *inv;

  inv = all_inventory(this_player());

  if( !sizeof(inv) )
    write("You are empty handed\n");
  else
    write("You are carrying:\n" + list_obs(inv, 1));

  return 1;
}
