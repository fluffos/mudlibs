//      mishi.c 密室
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","密室");
        set("long",@LONG
这是一条小房间。什么东西都没有。
LONG );
        set("exits",([
                "south" : __DIR__"midao",
                "down" : "/d/city/guangchang" ,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
