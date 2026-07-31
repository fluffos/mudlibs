// /d/yuehou/tcenter.c

inherit ROOM;

void create()
{
        set("short", "小镇广场");
        set("long", @LONG
这里是岳候镇的广场。广场上有不少小商贩做着各种买卖，
还有一些人正在闲逛。从这里向北是小镇的北面，向东是广场西
侧，向西是一个小土道。
LONG
        );

       set("exits", ([
                "north"             : __DIR__"center_n",
                "west"             : __DIR__"troad4",
                "east"             : __DIR__"center_e",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

