// /d/dalicheng/dlroad2.c

inherit ROOM;

void create()
{
set("short", "羊肠小路");
        set("long", @LONG
这是一条小路, 西南方通向大理段氏, 东北方通向成都城。
LONG
        );
        set("exits", ([
"southwest" : __DIR__"dlroad4",
"northeast" : __DIR__"dlroad1",
//"east" : "/u/bing/work/heizhao",
]));

        set("no_clean_up", 0);
set("outdoors", "dali");

        setup();
        replace_program(ROOM);
}
