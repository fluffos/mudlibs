/*--------------------------------------------------------------------------
 *  /p/school/examples/container/goldfish.c --  Example NPC
 *
 *  Copyright (C) 1997 by One Step Beyond.
 *  All Rights Reserved.
 *  Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 *  01-Nov-97 [tune]  creation
 *
 *  This NPC is cloned by a container (its fishbowl). It demonstrates
 *  how an object can interact with its environment and how to use
 *  heartbeats in NPC's.
 *
 *  Section 1: General NPC configuration
 *
 *  Section 2: Dynamic long descriptions
 *
 *  Section 3: Overloading heartbeat() to check the NPC's environment
 *
 */


// -------------------------------------------------------------------------
//       [Section 1]      Initial Configuration
// -------------------------------------------------------------------------
//
//       Setting up a simple NPC doesn't take much effort. The basic
//       things you should configure are short and long, name, race,
//       level, and gender. This will give you a perfectly functional,
//       though somewhat bland, NPC.
//
//       The directory /p/school/examples/npc/ contains more example
//       npcs which use some of the more sophisticated features, too.
//


  // -------------------------------------------------------------------
  //   This is a macro which we use to determine where our fish is
  //   located. Our fishbowl defines the property IS_FISHBOWL.
  // -------------------------------------------------------------------

#define IS_FISHBOWL  "IsFishbowl"
#include <properties.h>
#include <msgclass.h>
inherit "/std/npc";

// -------------------------------------------------------------------
//  Counter is a global variable that we will use later in heartbeat().
// -------------------------------------------------------------------
int counter;


void create()
{
    // -------------------------------------------------------------------
    //   Always start NPC's like this (and only NPC's!)
    // -------------------------------------------------------------------

  ::create();

    // -------------------------------------------------------------------
    //    If you set both a name and a short, set the name first.
    //    If the name is set secondly, it will overwrite the short.
    //
    //    The advantage to having both a short and a name is that
    //    the NPC will be listed by its short in room inventories,
    //    but will respond to find_living queries by it's name.
    //
    //    Giving your NPC a name will not add the name to its ids,
    //    but it will react to its name like an id.
    // -------------------------------------------------------------------


  SetName("goldfish");
  SetShort("a goldfish");

  AddId("fish");

  Set(P_GENDER, GENDER_FEMALE);
  Set(P_LEVEL, 2);

    // -------------------------------------------------------------------
    //  We need to make sure that the goldfish is light enough to be
    //  picked up by players, and also light enough to fit into our
    //  fishbowl. Our fish weighs 300 grams.
    // -------------------------------------------------------------------

  Set(P_WEIGHT, 300);

  Set(P_RACE, "goldfish");

  Set(P_NOTAKE, 0);

  SetShrugMsg(
   "The goldfish blows bubbles at you. Did you really expect an answer?\n");

    // -------------------------------------------------------------------
    //  We initialize our counter variable to 0 here. Technically,
    //  this is unnecessary, since all uninitialized variables in LPC
    //  are set to 0 (zero), but it's good style to do it anyway.
    // -------------------------------------------------------------------

  counter = 0;

    // -------------------------------------------------------------------
    //  We will use the heart_beat() to check the environment.
    //  In order to do that, we have to start the heart_beat().
    // -------------------------------------------------------------------

  SetHeart(1);
}

// -------------------------------------------------------------------------
//       [Section 2]      Dynamic Long Descriptions
// -------------------------------------------------------------------------
//
//       Naturally, when fish are removed from water, they die,
//       since they aren't able to breathe air like we do.
//
//       By overloading QueryLong(), we can show two different
//       long descriptions, based on where the fish is: the normal
//       description when it's in its fishbowl, and an "endangered"
//       description when it has been removed from its water.
//
//       QueryLong() is queried each time someone looks at the fish.
//       We check the environment of the fish, and return a string
//       accordingly. Notice that create() contains no SetLong().


varargs string QueryLong()
{
  if(environment() && environment()->Query(IS_FISHBOWL))
     return "A small goldfish. It's big, black eyes stare at you.\n";

  return "The small goldfish flops around gasping for breath. It will "
         "surely die outside of the fishbowl.\n";
}

//-------------------------------------------------------------------------
//       [Section 3]      Using heart_beat() to check the environment
//-------------------------------------------------------------------------
//
//       Every living object, as in real life, has a heartbeat. In LPC,
//       this is simulated with the function heart_beat().
//       The heart_beat() is used for internal functions as well as
//       as for our environment check, so we have to make sure the
//       right code is executed.

void heart_beat()
{
  object env;
  env = environment();

  ::heart_beat();  // Perform the internal functions.

  if (QueryHeart())
  {
    if ( env &&  (! env->Query(IS_FISHBOWL)) )
    {
       if( counter % 5 == 0 )
       {

          if( env->Query(P_IS_LIVING) )
          {
             msg_object( env, CMSG_TELL,
                         "The goldfish flops around, gasping for water.\n");
          }
          else
          {
             msg_room( env, CMSG_ROOM|MMSG_SEE,
                     ({ "The goldfish flops around gasping for water.\n",
                        "You hear odd wet flopping noises.\n" }) );
          }
          DoDamage(3);
          if(!this_object()) return;
       }
       counter++;
    }
  }
}
