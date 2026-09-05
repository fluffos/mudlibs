// room: /d/xingxiu/tianroad6.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "顶峰");
        set("long", @LONG
这里是此间的最高峰了，四周美景尽收眼底。东面有一条小路可以下山。
LONG
        );
        set("exits", ([
            "eastdown" : __DIR__"tianroad5",
        ]));
        set("objects", ([
               __DIR__"npc/snake" : 2, 
               __DIR__"npc/lingyang" : random(2), 
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

