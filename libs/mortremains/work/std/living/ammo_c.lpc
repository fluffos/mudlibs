/* File:    ammo_c.c
// Creator: Grendel@tmi-2
// When:    07-15-93
//
// Raped by Cyanide into ammo.c, 7 Jun 1999.
//
// This file provides a mechanism for a player to be credited and
// debited with ammo.  Calling set or add bypasses certain checks
// and does not account for encumbrance.
*/

#include "/u/c/cyanide/debug.h"

mixed query(string what);
varargs int add(string what, mixed amt, int security);

int ammo_credit(string type, int amount)
{
    if(!type || !stringp(type) || !amount || !intp(amount))
	return 0;
    add("ammo/"+type,amount);
    return 1;
}

int ammo_debit(string type, int amount)
{
    if(!type || !stringp(type) || !amount || !intp(amount))
	return 0;
    if(query("ammo/"+type) < amount)
	return 0;
    add("ammo/"+type,-amount);
    return 1;
}
