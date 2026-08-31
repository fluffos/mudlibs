/***********************
**  Limo by Seeker
** (C) 1966 UiS
***********************/

#include <std.h>

inherit OBJECT;

string current; // The current room this object is in...

string query_location()
{
 return current;
}

void set_location(string str)
{
 current = str;
}

void create()
{
 set_name("limosine");
 set_short("A large limosine");
 set_long("A large limosine with the license plate saying SEEKER");
 set_weight(1);
 set_value(1);
}
int get() { return 1; }

int init()
{
 ::init();
}

