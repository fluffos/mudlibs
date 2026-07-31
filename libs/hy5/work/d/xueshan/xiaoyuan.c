//      xiaoyuan.c 小院
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","小院");
        set("long",@LONG
这里是寺内的小院，收拾的相当干净利索。来来往往
的香客和喇嘛，一边在暗示着雪山寺香火之盛，一边也好
象在表示喇嘛的口福也真不坏。因为北边就是个厨房。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "west" : __DIR__"guangchang",
                "north" : __DIR__"chufang",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

