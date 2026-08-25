// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit OBJ;
inherit M_GETTABLE;

void setup()
{
    object ob;

    set_unit("幅");
    set_id("picture", "古画");
    set_gettable(1);
    if ( (ob = this_body()) && (ob = environment(ob)) ) {
        set_long("你朝画上看去，看到：\n\n" + ob->long());
        add_save( ({ "long" }) );
    }
}

