//      tulu3.c 土路
//      Designed by secret (秘密)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","土路");
        set("long",@LONG
这是一条不起眼的土路。尘埃泛起的远方，北边波光
潋滟的一大片幽蓝水光处，就是著名的圣湖。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "south" : __DIR__"tulu2",
                "north" : __DIR__"shenghu",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

