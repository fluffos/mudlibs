// by Zine

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "粪坑");
    set("outdoors","quanzhen");
	set("long", @LONG
这里是一个粪坑，臭气熏天，没事不要久留。但有些全真弟子天天来舀(yao)
粪。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shuitang",
]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
    object me=this_player();
    add_action("do_yao","yao");
    if (!me->query_temp("全真粪坑"))
    {
        me->set_temp("全真粪坑",1);
        message_vision("这里正好臭气四溢，$N一不留神，吸了一大口，差点被熏晕过去。\n",me);
    }
}

int do_yao()
{
    object me=this_player();
    object tong;
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!present("fen tong",me))
    {
        tell_object(me,"你不是要用手捞粪吧？\n");
        return 1;
    }
    tong=present("fen tong",me);
    if (tong->query("is_tong")!=2)
    {
        tell_object(me,"你的粪桶在哪？\n");
        return 1;
    }
    if (tong->query("full"))
    {
        tell_object(me,"桶里已经装满粪便了，再装就要漫出来了。\n");
        return 1;
    }
    tong->set("full",1);
    message_vision("$N打起了满满一桶粪便，心满意足地叹了口气。\n",me);
    return 1;
}