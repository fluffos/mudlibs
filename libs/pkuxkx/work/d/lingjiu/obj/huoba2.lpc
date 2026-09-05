//huoba.c   燃烧的火把，用来在黑暗的地方照明

#include <ansi.h>
inherit ITEM;
#include "/d/xingxiu/obj/fire.h"

void create()
{
        set_name("燃烧的火把", ({"huoba"}));
       set_weight(80);
       set("long", 
" 
这是一支熊熊燃烧的火把，它发出的光芒把四周都照亮了。\n\n"+
HIR"                 <^^^\\ \n"+
"                  \\  / \n"+
NOR"                   ||  \n"+
"                   ||  \n"+
"                   ||  \n"
);                		set("no_drop",1);
        set("no_get",1);

}

void init()
{
	add_action("do_make", "make");
       call_out("ximie", 240, this_object());
}

void ximie(object ob)
{
	object me=this_player();
    write("火把的光芒跳动了几下，然后就熄灭了，霎时间，四周一片漆黑。\n");
    destruct(ob);
	me->set_temp("use_fire", 0);
}
