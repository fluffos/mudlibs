/* Advent - Persian Rug -- Mateese, 19-Aug-96
 *
 * The Persian Rug, guarded by the dragon in the Secret Canyon.
 * It can't be taken as long as the dragon is nearby.
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("o/treasure");

/*-----------------------------------------------------------------------*/
/* To add the extra description for the dragon, we overload the
 * existing extra desciption for the treasure.
 */

public string LongExtra()
{
  string msg;

  msg = ::LongExtra();
  if (environment(this_object())
   && present(ADV_DRAGON, environment(this_object()))
     )
    msg += "The dragon is sprawled out on the persian rug.\n";
  return msg;
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  Set(P_SHORT, "a persian rug");
  Set(P_LONG, "A marvellous persian rug.\n");
  Set(P_WEIGHT, 3000);
  Set(P_VALUE, 500);
  AddId("rug");
  AddAdjective("persian");
  
  Set(P_TREASURE, F_RUG);
  Set(P_XP, 1600);
}

/*-----------------------------------------------------------------------*/
public mixed QueryNoGet()

/* Don't take the rug while the dragon is present.
 * NF has not true dynamic P_NOGETs, so move() has been overloaded, too.
 */
 
{
  if (environment(this_object())
   && present(ADV_DRAGON, environment(this_object()))
     )
    return "You'll need to get the dragon to move first.\n";
  return ::QueryNoGet();
}

/*-----------------------------------------------------------------------*/
public varargs int move (mixed dest, int method, mixed extra)

/* If it is a get, set a proper P_NOGET (dynamic P_NOGETs are not possible
 * with the current implementation).
 */

{
  int rc;

  /* Can't be taken if the dragon is nearby. */
  if (M_GET == method)
  {
    Set(P_NOGET, 0);
    if (environment(this_object())
     && present(ADV_DRAGON, environment(this_object()))
       )
      Set(P_NOGET, "You'll need to get the dragon to move first.\n");
  }
  rc = ::move(dest, method, extra);
  Set(P_NOGET, 0);
  return rc;
}

/*************************************************************************/
