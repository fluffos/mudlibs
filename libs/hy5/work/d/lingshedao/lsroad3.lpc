//Room:/d/lingshedao/lsroad3.c
inherit ROOM;
void create()
{
        set("short", "山间小道");
        set("long", @LONG
这是一条碎石小道.路的两旁郁郁葱葱,参天的大树直插
云霄.往北就是上山顶的路了.可是却模模糊糊的什么也看不
清.
LONG );
        set("exits", ([
                "westdown"    : __DIR__"lsroad1",
                "northup"  : __DIR__"shanyao",
        ]));
        set("no_clean_up",0);
        set("outdoors","lingshedao");
        setup();
        replace_program(ROOM);
}
