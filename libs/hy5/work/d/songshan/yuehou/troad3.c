// /d/yuehou/troad3.c

inherit ROOM;

void create()
{
        set("short", "土道");
        set("long", @LONG
这里是岳候镇的街道，街道两旁有不少做生意的人在叫卖，
好不热闹。从这里向西是岳候镇的小镇口，向南是一家民宅，向
东走还是街道。
LONG
        );

       set("exits", ([
                "west"             : __DIR__"wenter",
                "east"             : __DIR__"troad4",
                "south"             : __DIR__"house1",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

