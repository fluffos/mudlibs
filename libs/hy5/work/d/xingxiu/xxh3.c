// Room: /d/xingxiu/xxh3.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。
这里通向星宿海的深处。
LONG );
        set("objects", ([
                __DIR__"npc/gushou"  : 2,
                __DIR__"npc/boshou"  : 1,
                __DIR__"npc/haoshou"  : 1,
    "quest/menpai/xingxiu/shi" : 1,
	]) );
	set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("exits", ([
             "southwest" : __DIR__"xxh2",
             "northwest" : __DIR__"xxh5",
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
    set_temp("wayao2",2);
        setup();
        replace_program(ROOM);
}

