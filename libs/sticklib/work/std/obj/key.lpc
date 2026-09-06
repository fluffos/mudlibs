// A new standard key. Coded by Doomdark 15.2.-93
//
// Version 2.0 19-may-95 by Doomdark

inherit "/basic/id";

#include <key_defs.h>

string type;		// ie. 'small key' -> type == "small"
string code;		// Special code; used in determining whether the key
// fits in some lock.
int value;		// How valuable is this key? (usually 10 gc)
int weight;		// How much does this key weigh? (usually 1)

/****************************************************************
*								*
*			Query-functions.			*
*								*
****************************************************************/

int query_value() { return value; }
int query_weight() { return weight; }
string query_type() { return type; }
string query_code() { return code; }

/****************************************************************
*								*
*			Set-functions.				*
*								*
****************************************************************/

int
set_key_data(string str)	// Just for compatibility's sake... :-)
{
    if (sscanf(str, "%s %s", type, code) == 2) return 1;
    return 2;	// Odd... Anyway that's how it has been earlier too..
}

string
set_type(string str)
{
    int i, j;
    string *s, t, *ids;
    if (!str || !stringp(str))
	return type;
    type = str;
    i = j = sizeof(s = explode(str, " ")) - 1;
    t = "key";
    ids = ({ t });
    while (i >= 0) {
	t = s[i] + " " + t;
	if (i == j)
	    ids += ({ t });
	else
	    ids += ({ t, s[i] + " key" });
	i--;
    }
    set_id(ids);
    set_name(type + " key");
    if (!query_long())
	set_long("It's a "+str+" key, wonder where it fits?");
    return 0;
}

string
set_code(string str)
{
    if (!str || !stringp(str)) return code;
    code = str;
    return code;
}

void set_value(int x) { value = x; }
void set_weight(int x) { if(x >= 0) weight = x; }

/****************************************************************
*								*
*				Lfuns				*
*								*
****************************************************************/

public status get() { return 1; }

void
create()
{
    string n;
    int nr;
    type = code = 0;
    weight = 1;
    value = 10;
    set_short("A key");
    set_name("key");
    if (sscanf(object_name(this_object()), "%s#%d", n, nr) < 2)
	return;
    // Won't create original keys...
    this_object()->create_key();
}
