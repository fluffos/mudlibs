/* 
 queue_adt.c: LPC queue ADT - uses the list ADT

 author: Truilkan - 92/01/30

// Changed query("short") to query_short()  Leto, 94-11-11
*/

#include "adt_defs.h"

inherit ILIST_ADT;

mixed *enqueue(mixed obj)
{
	return insert(obj);
}

mixed dequeue()
{
	mixed *tail;

	set_tail(prev(tail = query_tail()));
	set_next(query_tail(),NULL);
	return value(tail);
}

int query_id(string str)
{
	return str == "queue";
}

//string query("short")
string query_short()
{
	return "a queue_adt object";
}
