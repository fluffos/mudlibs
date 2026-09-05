// /d/dali/dadian

inherit ROOM;

void create()
{
    set("short", "三元宫");
    set("long", @LONG
三元宫是天龙寺正殿，本因方丈平时就在此处收徒授课。殿内
虽有不少天龙弟子在此，却一点也没有喧哗之声。
LONG
       );
    set("outdoors", "dali");

    set("exits", ([
                "north" : __DIR__"yuan",
                "south" : __DIR__"changlang",
                ]));
    set("objects", ([
                CLASS_D("tianlong")+"/benyin" : 1,
                __DIR__"npc/shami" : 4 ]) );

    set("no_clean_up", 0);
    set("valid_startroom", 1);
    setup();
    replace_program(ROOM);
    "/clone/board/tls_b"->foo();

}
