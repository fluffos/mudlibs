/*
** File: rose.c
** Purpose: To Make Shya Feel Better.
Date: April 5th, 2000
*/

#include <mudlib.h>

inherit OBJECT ;

void create() {
    set ("short", "A long stemmed rose");
    set ("long", @EndText
This is a single long stemmed red rose.  The smell is quite sweet.
The beauty of this flower is unsurpassed by any you have come
across before.
EndText
    );
    set("id", ({ "rose" }) );
    set ("mass", 0);
    set ("value", 0);

}

//void init {
void init() {
    add_action("dipshit", "smell");
}

int dipshit(string str){
    if(!str) {
	write ("Smell what?");
	return 1;
    }
    if (str == "rose" ){
	write ("You smell the sweetest rose ever.\n");
	return 0;
    }
}
int query_auto_load() {return 1;}
