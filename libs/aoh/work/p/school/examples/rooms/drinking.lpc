/**=========================================================================**
 **                                                                         **
 **  This file illustates one way of adding a water source to rooms from    **
 **  which players can drink. It also allows players to refill empty        **
 **  containers from the source of water.                                   **
 **                                                                         **
 **=========================================================================**/
 

  // -------------------------------------------------------------------
  //  First we need to include the properties header file. It contains
  //  the definition of the macro P_REFILL.
  //  We also include config.h for later in the notify_fail() macro and
  //  macros.h for the NAME and TP macros.
  // -------------------------------------------------------------------
 
#include <properties.h>
#include <config.h>
#include <macros.h>
#include <msgclass.h>

  // -------------------------------------------------------------------
  //  Next, we define a macro for the amount of water a player will consume
  //  every time they drink from our fountain. It is not technically 
  //  necessary to make it a #define, but it's easier to edit if you
  //  later want to change the amount of liquid consumed.
  // -------------------------------------------------------------------

#define DRINK  15

  // -------------------------------------------------------------------
  //  Set up your room like you normally would.
  // -------------------------------------------------------------------

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("Example Drinking Room");
  SetIntLong(
    "This room is an example room to illustrate how to "
    "include the possibility to drink from things like "
    "wells, fountains, streams, pools, etc.\n"
    "There is a large fountain in the middle of the room.\n");
             
  AddDetail("fountain",
    "Shining while alabaster. It is filled with crystal clear water, "
    "which appears to be drinkable.\n");
  
  // ... (snip) ...
  
  // -------------------------------------------------------------------
  //  Here is where we add the possibility for players to refill empty
  //  containers. P_REFILL is the property we set, and "water" is the 
  //  kind of liquid they will get in their bottles. The liquid could
  //  be set to any kind of liquid.  
  // -------------------------------------------------------------------
  
  Set(P_REFILL, "water");
  
  // -------------------------------------------------------------------
  //  Now we add the action "drink" to the room. Just adding it, though,
  //  isn't enough. We also have to write our own function to handle the
  //  action - without that, a player would just get 'What?'. When a 
  //  player types drink, the function 'cmd_drink()' will be called.
  // -------------------------------------------------------------------
  
  AddRoomCmd("drink", "cmd_drink");
}

  // -------------------------------------------------------------------
  //  Now here is our custom function to handle the drink command.
  // -------------------------------------------------------------------

int cmd_drink(string str)
{
  
  // -------------------------------------------------------------------
  //  First we make sure they really typed something after 'drink'.
  //  If they didn't type a second word, we gracefully exit with a
  //  notify_fail() message. Don't use write() -- we need to give other 
  //  objects a chance to catch this verb. Return 0 indicates that
  //  we did not choose to handle this verb.
  // -------------------------------------------------------------------
  
  if(!str)
  {
     notify_fail("Drink what from what?\n");
     return 0;
  }
  
  // -------------------------------------------------------------------
  //  Next we check to see if the player typed the right words after
  //  'drink'. This is the trickiest part of defining commands -- you
  //  usually have the play Guess What The Player Might Type and try
  //  to handle anything reasonable. Logically, a player might not just
  //  try to 'drink water', since it's in a fountain, so we try to catch
  //  at least the most plausible cases. There are several ways of doing
  //  this (it's called 'parsing'), but the way we show here is perhaps 
  //  the easiest.
  //
  //  But before we play our guessing game, we make sure that the input
  //  from the player does not contain unnecessary spaces or uppercase
  //  characters. The mudlib provides the function 'norm_id()' which
  //  does this work for us.
  // -------------------------------------------------------------------

  str = norm_id(str);
  
  if(str != "water" && str != "water from fountain" && str != "from fountain")
  {
    notify_fail("Drink what from what?\n");
    return 0;
  }
  
  // -------------------------------------------------------------------
  //  If we have made it this far, that means that the player definitely
  //  typed the correct verb ('drink') and a correct argument (at least
  //  'water', perhaps also from our fountain). Now we want to add some
  //  drink points to the player. The average maximum drink points for most
  //  races lies between 75-100 points. When the points fall below a 
  //  certain level, the player starts getting the 'You are thirsty'
  //  messages. It is not possible to add more than the max to a player.
  
  //  We first query how many points they currently have, add our DRINK
  //  quantity (15, in this case) and see if the sum is lower than what
  //  their maximum drink level is. If the sum is higher, we tell the
  //  player that they are no longer thirsty. It is important here to use
  //  the argument NOTIFY_NOT_VALID to notify_fail(), by the way.
  // -------------------------------------------------------------------

  if ( (TP->QueryDrink() + DRINK) > TP->QueryMaxDrink() )
  {
    notify_fail("You can't drink that much.\n", NOTIFY_NOT_VALID);
    return 0;
  }
  
  // -------------------------------------------------------------------
  //  Now we add 15 drink points to the player's character, tell them that
  //  they had a refreshing drink of fountain water and return 1 to 
  //  indicate that we successfully handled this function. (Come to think
  //  of it, fountain water doesn't sound very refreshing, but what the
  //  heck...)
      
  //  After adding the drink points to our player, we need to tell them
  //  that something happened. The efun write() tells a string message
  //  to the player who activated the function (in this case, the player
  //  who drank from the fountain). The efun say() sends a message to
  //  other livings in the room with our player. We use the message class
  //  of say here to take advantage of message buffering.
  // -------------------------------------------------------------------

  TP->AddDrink( DRINK );
  
  write("You quench your thirst with the clear, cold water.\n");
  msg_say( CMSG_SAY, NAME(TP) + " drinks from the fountain.\n", TP );
  
  return 1;
}

  // -------------------------------------------------------------------
  //  EXCERCISES  1a) Write your own room which contains something the 
  //                  player can drink. It doesn't have to be water. 
  //              1b) Add the ability for players to refill bottles or
  //                  other drink containers.
  //              2)  Think about the last notify_fail() and the arguments
  //                  it used (NOTIFY_NOT_VALID). Read the document on 
  //                  notify_fail() and think about why it's necessary here.
  //                  Try changing your room so that it doesn't use any 
  //                  argument and see what happens.
  //                  (hint: 'man notify_fail')
  //              3)  Think again about the last if clause. What happens if 
  //                  the player has a maximum drink level of 100, currently
  //                  has 90 drink points, and attempts to drink from our 
  //                  fountain? Fix the code so that it is more logical.
  // -------------------------------------------------------------------
  
  // -------------------------------------------------------------------
  //  TIPS        1)  Use the xtool to measure your own drink level
  //                  while testing a room which offers drinking. To
  //                  see how many drink points you currently have, do:
  //                         xcall $m->QueryDrink()
  //                  and to see what your own max drink level is, do:
  //                         xcall $m->QueryMaxDrink()
  // -------------------------------------------------------------------
  
  // -------------------------------------------------------------------
  //  SEE ALSO        /doc/concepts/messages
  //                  /doc/sefun/msg_say
  //                  /doc/sefun/notify_fail
  //                  /doc/std/room
  // -------------------------------------------------------------------
