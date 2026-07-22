// mtroad6.c  山间平地

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
这里是森林中的一块小平地。长草没胫，野花浪漫，四周都是
密密的森林。时不时传来阵阵野兽嘶叫，飞鸟啼鸣。西南有一高崖
突兀而起，极是险峻。
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
            "east"  : __DIR__"mtroad4",
            "west"  : __DIR__"mtroad4",
            "north" : __DIR__"mtroad4",
            "south" : __DIR__"mtroad4",
        ]));
        set("objects", ([
            __DIR__"npc/shipopo" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

