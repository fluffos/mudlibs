//dadian.c

inherit ROOM;

void create()
{
        set("short","佛殿");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
                "south"         :       __DIR__ "tingyuan",
                ])
        );
        set("objects",([
            __DIR__"npc/fangzhang"  : 1,
        ]) );
//      replace_program(ROOM);
        setup();
}

