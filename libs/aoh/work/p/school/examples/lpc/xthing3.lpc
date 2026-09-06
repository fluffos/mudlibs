/* A singing rose  (Mateese, 05-Jul-1994)
**
** An example for smells and noises.
*/

#include <properties.h>     /* needed for setting value and light */

inherit "/std/thing";

/*----------------------------------------------------------------------------
** Initialize us 
*/

create() {

  ::create();

    /* We need a short description */
  Set(P_SHORT, "a beautiful rose");

    /* also a long one */
  Set(P_LONG, 
 "This is a noisy smelling thing (/d/archwiz/common/lpc/exm/xthing3.c).\n"
+"It's a wonderful singing rose.\n"
         );

   /* We have a weight of 100 grams. */
  Set(P_WEIGHT, 100);

    /* We also have a value of 10 coins. */
  Set(P_VALUE, 10);

    /* Respond to the id's 'rose', 'beautiful rose' */
  AddId("rose");
  AddAdjective("beautiful");

    /* Set a smell for the rose.
    */
  Set(P_SMELL, "It smells sweetly.\n");

    /* Set the basic noise of the rose.
    ** It is extended in Noise() by some random song.
    */
  Set(P_NOISE, "The rose is faintly humming.\n");

}

/*--------------------------------------------------------------------------
** Extend the noise description of the rose by a random song.
*/

string Noise(string what) {
  string noise, rc;

  noise = ::Noise(what);

  if (noise[<1] == '\n') // Remove trailing newline.
    noise = noise[0..<2];

  switch (random(5)) {
    case 0: rc = "a fancy jitterbug.\n"; break;
    case 1: rc =  "some Dead Kennedy sounds.\n"; break; 
    case 2: rc = "a lovely tune.\n"; break; 
    case 3: rc = "nothing but single sounds.\n"; break;
    default: rc = "nothing.\n";
  }
  return noise+" You recognize "+rc;
}

/*--------------------------------------------------------------------------*/
