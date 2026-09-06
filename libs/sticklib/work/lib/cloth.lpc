/*
 * Clothing as object.
 *
 * Needed mainly when we take off clothes and/or give them to someone else.
 *
 * Wear and remove commands can be used with clothes, however, "wear all"
 * and "remove all" shouldn't include clothing. Just clothes will be saved,
 * not armour. Boots, belt, cloak and such are armours.
 *
 * Clothing must have cloth type set, use functions:
 *	void set_cloth_type(string)
 *	string query_cloth_type()
 *
 * Different types of clothing can be found in /bin/daemons/clothingd.c
 *
 * When clothing is worn, the cloth object is destructed.
 *
 */


inherit "/basic/id";

string cn;
int weight, value;

int is_clothing() { return 1; }

void
create()
{
    set_short("mouldy rotten socks");
    set_long("They smell absolutely horrible!");
    set_id(({ "cloth", "clothing", "sock", "mouldy", "rotten" }));

    value = 0;

    this_object()->create_cloth();
}

void set_cloth_type(string n) { cn = n; }
string query_cloth_type() { return cn; }

int query_weight() { return weight; }
void set_weight(int w) { weight = w; }
int query_value() { return value; }
void set_value(int v) { value = v; }
int get() { return 1; }
int drop() { return 0; }
