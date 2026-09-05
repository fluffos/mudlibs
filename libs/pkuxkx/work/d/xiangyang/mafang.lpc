#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "马房");
	set("long", 
	"这里是郭靖家的马房,一为中年马夫正在辛辛苦苦的喂马.
   槽头上栓着一匹马很特别,浑身上下" + RED"血红血红"NOR + "的.\n"

	);
    
	set("exits", ([

		"east" : __DIR__"houyuan"          
	]));

	set("objects", ([
		__DIR__"npc/mafu" : 1,
	        __DIR__"npc/obj/hanxuema" : 1,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{        
        object* inv;
        int i;
        inv = deep_inventory(me);



        if ((dir == "east") && (!me->query_temp("取马")))
	{
                for(i=sizeof(inv)-1; i>=0; i--)
                    if((inv[i]->query("id") == "hanxue ma") )
	                return notify_fail("这位" + RANK_D->query_respect(this_player()) + ",没有郭大小姐的同意,您是不能拿走这匹马的。\n");
	}
        return ::valid_leave(me, dir);
}

