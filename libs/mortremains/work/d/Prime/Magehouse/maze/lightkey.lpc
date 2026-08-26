#include <mudlib.h>

inherit OBJECT;

create() {
    seteuid(getuid());
    set("to_lock", "light key") ;
    set("name", "key");
    set("long", @EndKey
This key is made of light somehow transformed by magic into something that you
can hold, the prisms also shift somehow when you look at the key, but your
mortal eyes, can't tell, exactly how.
EndKey   
);                    
    set("short", "Light Key");
    set("id", ({ "light", "light key", "key" }));
    set("lock_turn", 10);
}
