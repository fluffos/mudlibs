//cool 98.4.18
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "小集市");
        set("long", @LONG
这里是武馆门前的一个小集市，人来人往，许多做小买卖的
人在不停的吆喝。人群中有不少小流氓在寻衅滋事，许多人都敢
怒不敢言。
LONG);
        set("exits", ([
              "north" : __DIR__"guanmen",
              "southwest" : "/d/xiangyang/northroad1",
        ]));
               set("no_fight",1);
	set("outdoors", "武馆");
	setup();
}

