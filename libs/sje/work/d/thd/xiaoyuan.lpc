// Room: /u/jpei/thd/xiaoyuan.c

inherit ROOM;

void create()
{
        set("short", "小院");
        set("long", @LONG
没有想到这里竟然会有这么幽雅的小院，假山回廊，花树盆景，无一不
是放置得极为合适，显然这里的主人非常熟悉布置，再联系到东、西、南三
面的桃花阵，足见主人熟通阴阳五行、变化生克之理。北面是一座小亭子。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"bagua1",
                "west" : __DIR__"bagua0",
                "south" : __DIR__"taohua1",
                "north" : __DIR__"jicui",
        ]) );
        set("no_clean_up", 0);
        set("outdoors","桃花岛");
        set("objects",([
                __DIR__"obj/shizi" : 1,
        ]));  

        setup();
}

int valid_leave(object me, string dir)
{
        if ((dir == "west" || dir == "east") && !me->query_temp("bagua_1") && me->query_skill("qimen-bagua", 1) < 90) 
                return notify_fail("你感觉这个桃花阵中暗藏八卦，隐隐生出阻力，将你推了回来！\n");
        
        return ::valid_leave(me, dir);
}

