/* File:    money.c
// Creator: Grendel@tmi-2
// When:    07-15-93

// This file provides a mechanism for a player to be credited and
// debited with money.  Calling set or add bypasses certain checks
// and does not account for encumbrance.
*/

mixed query(string what);
varargs int add(string what, mixed amt, int security);

int credit(string type, int amount)
{
    if(!type || !stringp(type) || !amount || !intp(amount))
	return 0;
    if(query("capacity") < amount)
	return 0;
    add("capacity",-amount);
    add("wealth/"+type,amount);
    return 1;
}

int debit(string type, int amount)
{
    if(!type || !stringp(type) || !amount || !intp(amount))
	return 0;
    if(query("wealth/"+type) < amount)
	return 0;
    add("capacity",amount);
    add("wealth/"+type,-amount);
    return 1;
}
