// SilberLand MUDlib
//
// sys/bank.h -- div. Konstanten fuer die Zentralbank
//
// $Date: 1997/03/31 12:37:20 $
/* $Revision: 1.3 $
 * $Log: bank.h,v $
 * Revision 1.3  1997/03/31 12:37:20  Woody
 * prepared for revision control
 *
 * Revision 1.2  1995/07/12  13:05:36  Jof
 * 90% -> 30&
 *
 * Revision 1.1  1995/07/10  07:27:19  Jof
 * Initial revision
 *
 */

#ifndef __BANK_H__
#define __BANK_H__

#define ZENTRALBANK "/p/daemon/zentralbank.lpc"

#define BANK_DEFAULT_PERCENT 20 // So viele % der Einzahlung gehen aufs Konto
#define SHOP_PERCENT_LEFT 30 // So viele % kriegt der Laden fuer Objekte
			     // gutgeschrieben, die er zerstoert

#define STORE_PERCENT_LEFT 25 // Dito fuer den Store

#endif  //__BANK_H__

