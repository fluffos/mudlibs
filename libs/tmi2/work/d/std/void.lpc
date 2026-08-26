#include <mudlib.h>
#include <uid.h>
#include <priv.h>

inherit ROOM ;

void create() {
	::create() ;
	set("short", "The Void");
   set("long", @ENDTEXT
You are in the void.
There is nothingness everywhere and you cannot stand it!
However, Mobydick has kindly left some streamers to cheer the place up.
ENDTEXT
        );
	set("light", 1);
      set("volume",100000, MASTER_ONLY);
     set("capacity",10000000, MASTER_ONLY);
     set("bulk", 100000, MASTER_ONLY);
    set("mass" , 100000, MASTER_ONLY);
	seteuid(getuid(this_object()));
}

int remove() {
    if (previous_object()) {
        if (this_player(1) &&
                !adminp(geteuid(this_player(1))))
            error("The void may not be destructed.\n");
    }
    return 0;
}
