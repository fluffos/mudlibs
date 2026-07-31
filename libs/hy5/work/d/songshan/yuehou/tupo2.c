// /d/yuehou/tupo2.c

inherit ROOM;

void create()
{
        set("short", "小土坡");
        set("long", @LONG
这里是一个小土坡。从这里向西走是一座寺庙。
LONG
        );

       set("exits", ([
                "south"             : __DIR__"tupo",
                "west"             : __DIR__"miao",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

