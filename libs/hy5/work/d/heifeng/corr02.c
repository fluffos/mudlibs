// /d/heifeng/corr02.c

inherit ROOM;

void create()
{
        set("short", "过道");
        set("long", @LONG
你走在小路上，身边不时有强盗经过。在这种地方，还是小
心一点的好。过道的右边是一个厨房，左边是兵器房。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"corr",
            "north"  : __DIR__"corr03",
            "east"   : __DIR__"cookrm",
            "west"   : __DIR__"weaponrm",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

