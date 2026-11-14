/*   Example Room 1  (Mateese, 20-Jul-96)
**
**   This room shows the simple usage of the standard room.
**   We also show automatically our obvious exits together with the long
**   room description.
*/

#include <properties.h>
#include <rooms.h>
#include <moving.h>            /* for the special exit  */
#include <secure/wizlevels.h>  /* for the special exits */
#include <macros.h>            /* mud-wide defines      */

inherit "/std/room";           /* we derive from this one */



int _do_west(string arg);      // prototypes
string _do_light (string key); 

/*------------------------------------------------------------------------*/
// The function "create()" is always called as soon as an object is
// created (the same way that main() is always called first in C programs). 
// It is usually used to initialize values and properties in the object.
// An object does not _need_ to have a create(), but all objects which have
// any kind of initialization usually do.


void create() 
{
    /* Here we call create() in the parent object, which is /std/room.
    ** This initializes the default values for rooms.
    */
  ::create();

    /* Now we set the short description 
     */
  Set(P_INT_SHORT, "The first example room");

    /* Set a nice long description.
    ** The various strings are concatenated by the gamedriver into one 
    ** string.
    ** The only newlines (\n) specified are those needed to divide the
    ** description into meaningful paragraphs. The wrapping of lines
    ** to the player's linelength is done automatically.
    */
  Set(P_INT_LONG,
   "You are in the first example room."
   "It features a 'normal' exit south, 'special' exits west and southwest, "
   "and a hidden exit.\n"
   "Note that the obvious exits are always shown.\n"
   "On the wall, you see a 'normal' detail, a picture, and a 'special' "
   "detail, a spotlight.\n"
   "To the south you exit the example room dungeon, also to the west "
   "(well, maybe). The example dungeon continues to the north, and there "
   "is a hidden exit to the southeast.\n"
   "To the east are the 'indoors'/'outdoors' example rooms.\n"
             );

    /* Add the 'normal' exit south */
  AddExit("south", "/d/archwiz/common/lpc/entrance");

    /* Add another 'normal' exit north, leading to the other example rooms
    */
  AddExit("north", "/d/archwiz/common/lpc/exm/xroom2");

    /* Add another 'normal' exit east, leading to the in/out example rooms
    */
  AddExit("east", "/d/archwiz/common/lpc/exm/xroom5");

    /* Add the 'special' exit west. 'Special' means that we can specify
    ** a function which gets called when a player want to take this exit.
    ** The function shall return the success.
    */
  AddExit("west", #'_do_west);

    /* This exit has exactly the same effect es the 'west' exit, just
    ** the way it is implemented is different: we don't use a special
    ** function but instead we mark it as checked and put the code
    ** into CheckAction() below.
    ** This is possible as the all we want to do is block the exit
    ** for non-VAWs.
    */
  AddExit("southwest", "/d/archwiz/common/lpc/entrance");
  CheckExit("southwest", DACT_CHECK);

    /* To the southeast is a hidden exit into the xthingroom.
     */
  AddExit("southeast", "/d/archwiz/common/lpc/exm/xthingroom");
  HideExit("southeast", 1);

    /* Add the 'normal' detail, the picture. Note the '\n' at the end. */
  AddDetail("picture", "A marvelous picture of LPCvice Orb.\n");

    /* Add the 'special' detail, the spotlight. Like the special exit, we
    ** specify a function to be called. This function has to return the
    ** description, complete with '\n' and all.
    ** Also, we give a variety of possible keywords for the spotlight,
    ** so 'look at spotlight' has the same effect as 'look at spot'.
    ** This we also could have done with the normal detail above.
    */
  AddDetail( ({ "spotlight", "spot", "light" }), #'_do_light);
}

/*------------------------------------------------------------------------
** Our Long-Description shall always include the Exits.
*/

varargs string IntLong (string arg) 
{
  string rc;
  rc = ::IntLong(arg);
  if (arg || !TP->QueryObvious())
    if (TP->QueryBrief())
      rc += "["+(THIS->Exits(1) || "")+"]\n";
    else
      rc += (THIS->Exits(0)+THIS->Doors(0)) || "";
  return rc;
}

/*------------------------------------------------------------------------*/
/* This fun handles the special exit to the west. We will only VAws let pass.
** This fun is a normal command fun, complete with command line argument.
*/

int _do_west(string arg) 
{
    /* 'west <arg>' is certainly wrong */
  if (arg) return 0;

    /* Do our stuff... */
  if (!IS_WIZARD(this_player())) {
    write ("You bounce back into the room.\n");
    show(this_player()->Query(P_NAME)
         +" tries to go west, but bounces back.\n");
  }
  else
    this_player()->move("/d/archwiz/common/lpc/entrance", M_GO, "west");
  return 1;
}

/*------------------------------------------------------------------------*/
/* This function overloads the default CheckAction() function.
** We use it to block the way southwest for everyone but VAws.
** The argument constellation we expect is ("exit", "southwest", ?, ?)
*/

varargs int CheckAction(string action, string verb, string arg, int method)
{
  if ("exit" == action && "southwest" == verb)
  {
    /* Do our stuff... */
    if (!IS_WIZARD(this_player())) 
    {
      show(this_player()->Query(P_NAME)
           +" tries to go west, but bounces back.\n");
      notify_fail("You bounce back into the room.\n"); // No write()!
      return 0; // Causes the move to fail.
    }
  }

  /* Else do the normal stuff */
  return ::CheckAction(action, verb, arg, method);
}

/*------------------------------------------------------------------------*/
/* This fun is for the special detail: a multi-colored spotlight.
** The 'key' given to the fun is derivated from the command 'look at <key>'.
*/

string _do_light (string key) {
  string color;
    /* Here, any action (even depending on the exact value of key)
    ** may take place. We instead do nothing but selecting a random color.
    */
  switch (random(6)) {
  case 0 : color = "red"; break;
  case 1 : color = "infrapink"; break;
  case 2 : color = "yellow"; break;
  case 3 : color = "green"; break;
  case 4 : color = "blue"; break;
  case 5 : color = "ultraroentgen"; break;
  }
    /* Now return the colored description. */
  return "You see nothing but a "+color+" spotlight.\n";
}

