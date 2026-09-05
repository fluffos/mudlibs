// File		: xuedi2.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>
#include "snow.h"

inherit ROOM;

void create()
{
	set("short", HIW"雪地"NOR);
	set("long", @LONG
这里是一片雪地，厚厚的积雪足以没膝，可见山上终年如此，而凌霄城处于
如此高寒之地，即便有独门的御寒之物，门下弟子也需要扎实的内功根基。远处
山上就是凌霄城了。旁边似乎有一个洞(dong)，经常有人走来走去的样子。
LONG);

	set("outdoors", "凌霄城");

	set("item_desc", ([
		"snow": (: snow :),
		"dong" : "一个洞，洞口不大，人肯定钻不进去。\n",
	]));

	set("objects", ([
	]));

	set("exits", ([
		"north" : __DIR__"xuedi3",
		"westdown" : __DIR__"xuepo2",
	]));

	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="dong" )
        {
//                if( (fam = me->query("family")) && fam["family_name"] == "丐帮" ) 
                        message("vision",

                                me->name() + "钻入了洞中。\n",
                                environment(me), ({me}) );
                        me->move("/d/gaibang/underlx");
                        message("vision",
                                me->name() + "从外边钻了进来。\n",
                                environment(me), ({me}) );
                        return 1;
        }
}       
