/* Small Biont  (Mateese, 26-Jun-92)
**
** A simple example for /std/npc. This is a small, harmless monster.
**
** NOTE:
**   If the monster is cloned directly by a player, it is likely that
**   it'll won't be moved to it due to the wrong method to move().
*/

#include <properties.h>   /* for the property names */

inherit "/std/npc";

/*-------------------------------------------------------------------------
** Initialize us - as few as possible.
*/

create () {

  if (::create()) return;  /* Ignore the Blueprint */

    /* Initialize Name = Short and Long description */
  Set(P_NAME, "Araech");
  Set(P_LONG,
 "A simple harmless example monster. (/d/archwiz/common/lpc/exm/xnpc1.c).\n"
 "A small furry biont, happily humming. "
 "You almost immediately like her.\n"
         );

    /* Set the race. */
  Set(P_RACE, "biont");
 
    /* Set the gender to female. It ist 'neutral' per default. */
  Set(P_GENDER, GENDER_FEMALE);

    /* It is whimpy as hell */
  Set(P_WIMPY, Query(P_MAX_HP)/2);

    /* But likes to visit the world, with a propability
    ** of 250/1000 it moves on a heart_beat
    */
  Set(P_GO_CHANCE, 250);

    /* Set the movement messages.
    ** Even provide special messages if others can't see us moving.
    */
  Set(P_MSGIN,   ({ "arrives", "hushes in" }) );
  Set(P_MSGOUT,  ({ "leaves", "hushes out" }) );
  Set(P_MMSGIN,  ({ "plops in", "is here" }) );
  Set(P_MMSGOUT, ({ "fades away", "left" }) );
}

/*************************************************************************/
