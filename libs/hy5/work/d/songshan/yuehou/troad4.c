// /d/yuehou/troad4.c

inherit ROOM;

void create()
{
        set("short", "土道");
        set("long", @LONG
这里是岳候镇的街道，街道两旁的生意霎是繁忙，不少行人
都驻足，购买自己的日常所需。从这里向北走是一个小土坡，向
西是街道的西头，向南是一家杂货店，向东走是小镇广场。
LONG
        );

       set("exits", ([
                "north"             : __DIR__"tupo",
                "west"             : __DIR__"troad3",
                "east"             : __DIR__"tcenter",
                "south"             : __DIR__"house2",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

