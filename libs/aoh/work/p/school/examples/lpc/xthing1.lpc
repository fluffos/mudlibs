/*   A simple thing  (Mateese, 21-Jun-1992)
**
** A simple thing.
*/

#include <properties.h>     /* needed for setting value and light */

inherit "/std/thing";

  /* Initialize us */
create() {

  ::create();

    /* We need a short description */
  Set(P_SHORT, "a simple thing");

    /* also a long one. In fact, there are two long descriptions: one
    ** for the simple 'look at', the other for 'examine'.
    ** The only newlines (\n) specified are those needed to divide the
    ** description into meaningful paragraphs. The wrapping of too long
    ** lines down to the players linelength is done automatically.
    */
  Set(P_LONG, ({
 "This is just an simple thing (/d/archwiz/common/lpc/exm/xthing1.c).\n"
+"It has a weight of 100 gr, a value of 10 coins, and emits no light.\n"
,"This simple thing has no feature worth closer examination.\n"
         }) );

   /* We have a weight of 100 grams.
   ** Note that the old obj/treasure (implicitely) counted in kilograms.
   */
 Set(P_WEIGHT, 100);

    /* We also have a value of 10 coins.
    ** It could be set by 'SetValue(10)' but we do it directly just for fun.
    */
  Set(P_VALUE, 10);

    /* Now ensure that this key responds to the id "thing" as well
    ** as to the id "simple thing".
    ** Also allow 'thing' to be spelled as 'xthing'.
    ** We could also add more adjectives, which then could be used
    ** in any combination.
    */
  AddId("thing");
  AddId("xthing");
  AddAdjective("simple");

    /* Emit no light. 
    ** Though this is the default, we show the method here.
    */
  Set(P_LIGHT, 0);
}

/* that's all */
