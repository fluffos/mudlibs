#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "闺房");
        set("long", @LONG
这是凌小姐的闺房，一股幽香扑面而来。一张绣榻放在墙角，垂着细纱。
凌小姐正对着一盆菊花在沉思。西面是座花园。
LONG
        );

        set("exits", ([
                "south" : __DIR__"houyuan",
                "west" : __DIR__"huayuan",
        ]));

        set("objects", ([
                __DIR__"npc/shuanghua" : 1,
        ]));
        set("cost", 0);
        setup();
}

void init()
{
	add_action("do_biqi", "biqi");
	add_action("do_biqi", "bingqi");
}

int do_biqi()
{
	object me = this_player();
	if (!me->query_temp("jinboxunhua"))
		return 0;
	me->set_temp("biqi", 1);
	message_vision(HIG"$N深吸一口气，屏住了呼吸。\n"NOR, me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "south")
		me->delete_temp("biqi");
	return ::valid_leave(me, dir);
}