/*
** File: key6.c
** Other Notes: This item is for a lil quest-wanna-be.
** Credits:
**   Created by Nsd.
**    8 Oct 97 Cyanide added the init/remove thing to clean up the mud!
*/

#include <mudlib.h>

inherit OBJECT;

void create() {
    seteuid(getuid());
      set("author", "Nsd");
     set("name", "key");
set("id", ({ "key", "key of obsession" }) );
set("short", "the key of obsession");
    set("long", @EndLong
This is the key of obsession. One of the seven keys
that must be given to the stolen innocence.
EndLong
    );
    set("value", 0);
}     

void init() {
    if (!living(environment(this_object())))
	call_out("remove", 1);
}

void remove() {
    if (environment(TO)) 
	tell_room(environment(this_object()), 
"What a mistake you have made!! Now you won't wake up.
The key has vanished...\n");
    ::remove();
}
