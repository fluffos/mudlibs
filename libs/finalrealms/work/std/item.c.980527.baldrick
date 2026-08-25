/* Item.c 
 * Made by Baldrick.
 * to be used instead of /std/object on *EVERY* object that can be carried.
 * 
 * Right now it's only armour.c and weapon.c that inherits it.
 * and for now that's the only one needing it..
 * unless you have any wear / wieldable items.. the should also inherit this
 */

inherit "/std/object";

status wearable;
status holdable;
int size, armour_type;
int hands;  /* Hamlet */


// Moved move() and dest_me() to below.
// set_in_use() too
// Radix
#include "/std/basic/item_misc.c"


void set_holdable(int i) 
{ 
    holdable = i; 
    if (wearable && holdable)
	wearable = 0;
}

void set_wearable(int i) 
{ 
    wearable = i; 
    if (wearable && holdable)
	holdable = 0;
}
void set_armour_type(int i)
{
    armour_type = i;
}

int query_holdable() { return holdable; }
int query_wearable() { return wearable; }
int query_in_use() { return in_use; }
int query_armour_type() { return armour_type; }

void create()
{
    holdable = wearable = 0;
    size = 0;                 // Fix by Wonderflug
    object::create();
    hands = 1;
}

/* Sizes.. This will be used in wield and wear and later also by containers.
 * Will have it here and not in /std/object because the roomsize is something 
 * else.. 
 * Baldrick aug '95.
 */

void set_size(int i)
{
    size = i;
} /* void size */

int adjust_size(int i)
{
    size += i;
    return size;
} /* adjust_size */

int query_size()
{
    return size;
} 

/* Hamlet Sep 1995 */
void set_hands_needed(int i) 
{
    hands = i;
}

int query_hands_needed() { return hands; }


// Radix, needed for long()
string cond_string() { return(0); }

// Radix moved long() from /obj/weapon.c & armour.c to here.
// Also added calc_extra_look() cause it was unused (though inherited)
// Jan 18, 1996
string long(string s, int dark)
{
    string cond = cond_string();
    string xtra = calc_extra_look();
    if(!cond) cond = "";
    if(!xtra) xtra = "";
    return ::long()+xtra+cond;
}
