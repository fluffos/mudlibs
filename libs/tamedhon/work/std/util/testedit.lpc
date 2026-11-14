// SilberLand MUDlib
//
// std/util/testedit.c -- Testeditor
// $Id: testedit.c,v 3.1 1997/03/13 02:42:16 Woody Exp mud $
// $Date: 1997/03/13 02:42:16 $
/* $Revision: 3.1 $
 * $Log: testedit.c,v $
 * Revision 3.1  1997/03/13 02:42:16  Woody
 * prepared for revision control
 *
 * Revision 3.0  1995/11/22 14:32:54  Jof
 * Updated to revision 3.0
 *
 * Revision 1.1  1995/11/22 14:19:50  Jof
 * Initial revision
 *
 */

inherit "/std/thing";
inherit "/std/util/ex";

#include <properties.h>

create()
{
  ::create();
  AddId("ex");
  SetProp(P_NAME, "Editor");
  SetProp(P_SHORT, "Ein Testeditor");
  SetProp(P_LONG, "Testeditor: Kommando: ex\n");
  AddCmd("ex", "ex");
}
