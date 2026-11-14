// SilberLand MUDlib
//
// std/thing.c -- standard object
//
// $Date: 1997/09/25 15:12:22 $                      
/* $Revision: 3.3 $       
 * $Log: thing.c,v $
 * Revision 3.3  1997/09/25 15:12:22  Woody
 * inherited material nicht mehr (-> std/thing/description)
 *
 * Revision 3.2  1997/03/13 03:16:21  Woody
 * prepared for revision control
 *
 * Revision 3.1  1996/01/24 00:04:01  Hate
 * added description::init() (lies command)
 *
 * Revision 3.0  1995/11/22 14:31:26  Jof
 * Updated to revision 3.0
 *
 * Revision 2.10  1995/11/22 14:04:11  Jof
 * Fixed RCS header
 *
 * Revision 2.9  1995/08/24 19:14:44  Jof
 * Add id 'Ding' instead of 'ding'
 *
 * Revision 2.8  1995/06/14  09:01:35  Wargon
 * read() nach thing/description verlegt.
 *
 * Revision 2.7  1994/07/10  17:36:33  Jof
 * Weg mit "show"
 *
 * Revision 2.6  1994/07/10  17:23:38  Jof
 * *** empty log message ***
 *
 * Revision 2.5  1994/03/09  21:49:09  Hate
 * minor changes to meet new lib order
 *
 */                            

// A thing. (by Marvin and Deepthought) 
//
// 1994 (Hate) I've changed a bit
//
// The most general object class. It defines the really basic functions.
// This is the Nightfall I standard object which is supposed to replace
// obj/treasure.
//
// This object should understand the properties short, long, info, read_msg,
// value, weight.
//
// weight is given in grams, 1 kilogram (kg) = 1000 grams (g) = 1 old weight
// unit

#pragma strong_types

inherit "std/thing/properties";
inherit "std/thing/description";
inherit "std/thing/moving";
//inherit "std/thing/util";
inherit "std/thing/language";
inherit "std/thing/commands";
inherit "std/thing/restrictions";

#define NEED_PROTOTYPES

#include <thing/properties.h>

#include <properties.h>
#include <language.h>
#include <defines.h>
#include <wizlevels.h>

void create()
{
  properties::create();
  description::create();
  commands::create();
  restrictions::create();
  //AddId("Ding");
}

// Prevents tampering with the master object
int query_prevent_shadow() { return 1; }

void init() 
{
  commands::init();
  description::init();
}

void reset()
{

}
