/*---------------------------------------------------------------------------
** A sample equipment thing  (Mateese, 06-Dec-1994)
**
** All this T-Shirt does is adding a stupid description to the players 
** as long as it is worn.
**---------------------------------------------------------------------------
*/


#include <properties.h>
#include <equipment.h>

inherit "/obj/equipment";

#define TP   this_player()

//---------------------------------------------------------------------------
public void create() 

// Initialise the object.

{
  // You know this already...
  ::create();
  Set(P_SHORT, "a baggy t-shirt");
  Set(P_LONG, "This is a simple baggy t-shirt, but an expensive one.\n");
  AddId("t-shirt");
  AddId("shirt");
  AddAdjective("baggy");
  Set(P_VALUE, 1000);

  // The T-Shirt can just be worn, nothing else.
  Set(P_USAGE, EQM_WEAR);
}

//---------------------------------------------------------------------------

public string QueryExtralook() 
{
  return Query(P_WORN)
         ? capitalize(TP->QueryPronoun())+" is a follower of Benetton.\n"
         : 0;
}

/***************************************************************************/
