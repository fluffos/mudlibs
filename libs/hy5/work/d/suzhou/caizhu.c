
inherit ROOM;

void create()
{
        set("short", "翰林府门");
        set("long", @LONG
一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子镇住了大门两侧，
大门上的朱漆足足有三寸厚。门上一张匾，上书“翰林府”三个大字。
LONG
        );

        set("exits", ([
                "south" : __DIR__"wanjing",
                "north" : __DIR__"dayuan1",
        ]));

        set("objects", ([
                __DIR__"npc/wolfdog" : 2,
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}


