//Room:/d/lingshedao/lsroad2.c
inherit ROOM;
void create()
{
        set("short", "山间小道");
        set("long", "这是一条碎石小路,往北就到山冈了.\n");
        set("exits", ([
                "southeast"    : __DIR__"lsroad1",
                "northup"  : __DIR__"shangang",
        ]));
        set("no_clean_up",0);
        set("outdoors","lingshedao");
        setup();
        replace_program(ROOM);
}
