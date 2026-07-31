// Modify By Yanyang@SJ 2001.3.2
// Room: /d/tiezhang/zoulang-4.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
你走在一条走廊上。南面北面都有个黑暗的小屋，还隐隐传来一些酣声。
LONG
        );
        set("exits", ([
                "west" : __DIR__"zoulang-1",
                "east" : __DIR__"gjfang",
                "north": __DIR__"xxsnan",
                "south": __DIR__"xxsnv",
        ]));

        set("item_desc",([            
            "north" : "里面光线很暗，你什么也看不到，只能听到一阵阵男性的酣声。\n",
            "south" : "里面光线很暗，你什么也看不到，只能闻到一股淡淡的清香。\n",
           ]));

        set("no_clean_up", 0);

        set("coor/x",-310);
        set("coor/y",-250);
        set("coor/z",10);
        setup();
}

int valid_leave(object me, string dir)
{
        if ((dir == "north" && me->query("gender") == "女性")||(dir == "south" && me->query("gender") != "女性"))
        {
                return notify_fail("你不能进去，去另一间休息室吧！\n");
        }
        return ::valid_leave(me, dir);
}

