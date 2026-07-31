//      kedian.c 客店
//      Designed by secret (秘密)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","客店");
        set("long",@LONG
这里是一个路边的小客店。来往的行人都在这里稍事
休息。往东的路可以到达中原。
LONG );
//        set("valid_startroom",1);
        set("exits",([
                "east" : __DIR__"tulu2",
        ]));
        set("objects", ([
            __DIR__"npc/xiaoer2" :1
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

