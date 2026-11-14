// SilberLand MUDlib
//
// ARMOUR/MOVING.C -- armour moving object
//
// $Date: 1997/03/31 16:20:42 $                      
/* $Revision: 3.2 $       
 * $Log: moving.c,v $
 * Revision 3.2  1997/03/31 16:20:42  Woody
 * Nochmals an den include's gedreht, um die haesslichen Warnings
 * (Misplaces prototypes) endlich wegzukriegen. Erfolgreich :)
 *
 * Revision 3.1  1997/03/31 16:06:30  Woody
 * include armour.h, "ME->" raus
 *
 * Revision 3.0  1997/03/13 01:05:37  Woody
 * prepared for revision control
 *
 * Revision 2.3  1995/06/02  12:57:41  Rumata
 * move made varargs
 *
 * Revision 2.2  1995/01/23  17:47:39  Jof
 * *** empty log message ***
 *
 * Revision 2.1  1994/12/01  13:26:14  Jof
 * Minor bugfixing
 *
 */                            

#pragma strong_types

inherit "/std/thing/moving";

#define NEED_PROTOTYPES 1

#include <moving.h>
#include <thing.h>
#include <armour.h>


/* Ruestungen muessen vor Bewegung und Zerstoerung ausgezogen werden */

varargs int move(mixed dest, int method )
{
  DoUnwear(method & M_SILENT);
  if ((method&M_NOCHECK) || (!QueryProp(P_WORN)))
    return ::move(dest, method);
  return 0;
}

varargs int remove(int silent)
{
  DoUnwear(silent);
  if (!QueryProp(P_WORN))
    return ::remove();
  return 0;
}
