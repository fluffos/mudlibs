//      shanlu2.c ɽ·
//      Designed by secret ()
//      97/04/09

inherit ROOM;

void create()
{
        set("short","ɽ·");
        set("long",@LONG
һɽС·
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "northup" : __DIR__"shanmen",
                "eastdown" : __DIR__"shanlu1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
