/*   A weird key (Mateese, 09-Sep-1994)
**
** This is a false key, not suitable for anything, except as example
** for using /obj/key.
*/

#include <properties.h>     /* needed for setting the value */

inherit "/obj/key";

  /* Initialize us */
create() {

  ::create();

    /* We need a short description */
  Set(P_SHORT, "a weird key");

    /* also a long one */
  Set(P_LONG, "A weird looking key. You wonder where it may fit.\n");

    /* We have a weight of 100 grams.
    ** Note that the old obj/treasure (implicitely) counted in kilograms.
    */
  Set(P_WEIGHT, 100);

    /* We also have a value of 10 coins.
    ** It could be set by 'SetValue(10)' but we do it directly just for fun.
    */
  Set(P_VALUE, 10);

    /* Now ensure that this key responds to the id "key" as well
    ** as to the id "weird key".
    ** It could be alternatively done with two calls to AddId().
    ** We could also add more adjectives, which then could be used
    ** in any combination.
    */
  AddId("key");
  AddAdjective("weird");

    /* Give the key it's KeyIds (in case they differ from its normal ids).
     * Note that for a recognition, the KeyIds must be given _exactly_ as
     * they are specified here. In contrast, normal ids are normalized to 
     * all lowercase and ignore the extraneous spaces.
     */
  AddKeyId("very special  Keyid");
  AddKeyId("second special  Keyid");

    /* This is a very special key: it also has a KeyCode.
     * To use this key, the user must specifiy one of both KeyIds and 
     * additionally exact this KeyCode.
     */
  Set(P_KEYCODE, "the secret KeyCode");
}

/* that's all */
