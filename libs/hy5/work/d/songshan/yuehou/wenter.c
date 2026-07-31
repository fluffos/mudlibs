// /d/yuehou/wenter.c

inherit ROOM;

void create()
{
        set("short", "小镇口");
        set("long", @LONG
这里是岳候镇的小镇口，路旁树立着一个石碑，上面写着“
岳候镇”三个大字，据说当年岳飞岳将军打仗的时候曾经来到过
这里。
LONG
        );

       set("exits", ([
                "west"             : __DIR__"troad2",
                "east"             : __DIR__"troad3",
]) );
        set("objects", ([
                "/clone/npc/man" : 2,
        ]));
       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

