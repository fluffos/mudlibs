// /guanwai/baihe2.c

inherit ROOM;

void create()
{
        set("short", "白河小道");
        set("long", @LONG
这里是长白山下的一小道，寒风瑟瑟，让人不寒而栗。
LONG );
        set("exits", ([
                "north"  : __DIR__"baihe",
                "east"   : __DIR__"haigang",

        ]));
        set("no_clean_up", 0);
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}

