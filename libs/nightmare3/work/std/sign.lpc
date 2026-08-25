//      /std/sign.c
//      from the Nightmare mudlib
//	fixed to match the new lib by Drakken, which in fact was
//	a rewrite from scratch - 94-11-25

#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_no_clean(1);
}

int allow_get(object ob) { 
    if (::allow_get(ob)) {
	if (ob)
	    message("my_action","You cannot get that!",ob);
    }
    return 0;
}
