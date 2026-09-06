/* Fluffy Bag  (Mateese, 28-Sep-92)
**
** An example for /std/container.
** As you'll see, /std/container is just another child of /std/thing.
*/

#include <properties.h>   /* for the property names */

inherit "/std/container";

/*-------------------------------------------------------------------------
** Initialize us.
*/

create () {

  ::create();

    /* We need a short description */
  Set(P_SHORT, "a fluffy bag");

    /* QueryLong() is overloaded to return a string showing the weights of the
    ** bag and its contents.
    */

    /* Containers should have internal descriptions */
  Set(P_INT_SHORT, "inside a fluffy bag");
  Set(P_INT_LONG,  
"This is an example container (/d/archwiz/common/lpc/exm/xcontainer.c).\n" +
"You are inside of it.\n"
            );

    /* Value (*yawn*) */
  Set(P_VALUE, 100);
 
    /* Weight */
  Set(P_WEIGHT, 200);

    /* Our IDs: 'bag', 'fluffy bag'*/
  AddId("bag");
  AddAdjective("fluffy");

    /* We can carry up to 7 kg, makes a total of 7.2 kg */
  Set(P_MAX_WEIGHT, 7200);

    /* The bag is opaque */
  Set(P_TRANSPARENCY, 0);
}

/*-------------------------------------------------------------------------
** Return a summary of our current weights.
*/

QueryLong(str) {
  int contweight, maxweight, actweight, myweight;

    /* The actual total weight */
  actweight = Query(P_WEIGHT);

    /* The total weight of the contents alone */

  contweight = Query(P_WEIGHT_CONTENT);

    /* The max allowed load */
  maxweight = Query(P_MAX_WEIGHT);

    /* Now compute my own weight */
  myweight = actweight - (contweight * Query(P_WEIGHT_CHG)) / 1000;

  return 
"This is an example container (/d/archwiz/common/lpc/exm/xcontainer.c).\n"
+"A cute fluffy bag. You can put things in it.\n"
+"The bag alone weighs "+myweight+" g, and can contain up to "
        +maxweight+" g.\n"
        +"At the moment, it contains total "+contweight
        +" g, giving an overall weight"+" of "+actweight+" g.\n"
+Content();
  /* The final call to Content() adds the list of contents */
}

/*************************************************************************/
