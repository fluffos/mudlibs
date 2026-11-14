// SilberLand MUDlib
//
// TRAY/DESCRIPTION.C -- standard description for trays
//
// $Date: 1997/06/25 12:10:54 $                      
/* $Revision: 3.1 $       
 * $Log: description.c,v $
 * Revision 3.1  1997/06/25 12:10:54  Woody
 * "auf" verlangt dem DATIV *grins*
 *
 * Revision 3.0  1997/03/13 02:38:36  Woody
 * prepared for revision control
 *
 * Revision 2.2  1995/05/09  08:43:04  Jof
 * Moved from container ...
 *
 * Revision 2.3  1995/02/22  13:05:56  Hate
 * long declared as varargs (Rumata)
 * Hate=?
 *
 * Revision 2.2  1994/03/18  12:09:47  Jof
 * Fixed indentation
 *
 * Revision 2.2  1994/03/18  12:09:47  Jof
 * Fixed indentation
 *
 * Revision 2.1  1994/02/24  09:47:42  Kirk
 * *** empty log message ***
 *
 * Revision 2.0  1994/01/13  16:59:55  mud
 * *** empty log message ***
 *
 * Revision 1.2  1994/01/08  13:10:50  mud
 * #pragma strong_types
 *             
 */                            

inherit "std/container/description";

#pragma strong_types

#define NEED_PROTOTYPES

#include <container.h>
#include <properties.h>
#include <defines.h>
#include <wizlevels.h>
#include <language.h>

void create()
{ 
  ::create();
  AddId("tray");
}

varargs string long() {
  string descr, inv_descr;

  descr = process_string(QueryProp(P_LONG));
  inv_descr = make_invlist(PL, all_inventory(ME) );
  if ( inv_descr != "" )
    descr += "Auf " + QueryPronoun(WEM) + " liegt:\n" + inv_descr;
  return descr;
}
