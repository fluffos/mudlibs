// /d/yuehou/house1.c

inherit ROOM;

void create()
{
        set("short", "民宅");
        set("long", @LONG
这里是岳候镇的一间民宅，这里住着一家人，主人每天外出
干活，妻子和孩子在家伺候老人。从这里向北是小镇的市集。
LONG
        );

       set("exits", ([
                "north"             : __DIR__"troad3",
]) );

       set("light_up",1);

       setup();
       replace_program(ROOM);
}

