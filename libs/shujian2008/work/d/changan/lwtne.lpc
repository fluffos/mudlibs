// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/lwtne.c

inherit ROOM;

void create()
{
        set("short", "了望台");
        set("long", @LONG
守城的重要哨岗。中间有一个巨大的烟炉，里面装满了狼粪，一侧挂着一
口铜钟，每当有紧急情况，守城卫兵就放狼烟、鸣钟为警，调动官兵，以备外
族来犯。几名值勤的岗哨仔细的观察着城外的动静。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "south" : __DIR__"eastchq1",
                "west"  : __DIR__"northchq6",
        ]));

        set("objects", ([
        __DIR__"npc/zhqbing" : 2,
        ]));
        
        set("incity",1);
	setup();
}

