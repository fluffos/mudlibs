// Room: /d/quanzhou/dongjie.c

inherit ROOM;

void create()
{
        set("short", "东街");
        set("long", @LONG
这里是泉州的东大街。东面是一个港口，从那里可以出海。北面
是著名的精武馆的泉州分馆。
LONG
        );

        set("exits", ([
                "east" : __DIR__"haigang",
               "north" : __DIR__"wgm1",
                "west" : __DIR__"zhongxin",
        ]));


        set("no_clean_up", 0);
        set("valid_startroom", 1);

        setup();
        replace_program(ROOM);
}
