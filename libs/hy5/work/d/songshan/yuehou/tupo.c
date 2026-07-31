// /d/yuehou/tupo.c

inherit ROOM;

void create()
{
        set("short", "小土坡");
        set("long", @LONG
这里是一个小土坡，据说原来是一个山丘。从这里向北走隐
约可以看见一座寺庙。
LONG
        );

       set("exits", ([
                "south"             : __DIR__"troad4",
                "north"             : __DIR__"tupo2",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

