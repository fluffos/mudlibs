/* Do not remove the headers from this file! see /USAGE for more info. */

// Adapted to new user menu system, Tsath 2022

//: PLAYERCOMMAND
// USAGE
//   ``quit``
//
// Quit the game. See you later, perhaps?
//
// .. TAGS: RST

#include <config/user_menu.h>

inherit CMD;

private
void main()
{
   string name = this_body()->query_name();

   this_body()->quit();
   if (name && strlen(name) > 5 && name[0..4] == "Guest")
   {
      out("Not saving guests.");
      this_user()->quit();
      return;
   }
#ifdef USE_USER_MENU
   this_user()->exit_all_channels();
   new (USER_MENU)->start_menu();
#else
   this_user()->save_me();
   this_user()->quit();
#endif
}