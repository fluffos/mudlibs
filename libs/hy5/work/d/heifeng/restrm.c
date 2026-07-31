// /d/heifeng/restrm.c

inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
这里是强盗们休息的地方。屋里整齐地排放着两排木床。有
几个强盗还是呼呼地睡着，像是刚值过夜班。
LONG
        );
        set("exits", ([ 
//            "north"  : __DIR__"corr05",
            "east"   : __DIR__"corr06",
//            "west"   : __DIR__"hell1",
]));
        setup();
        replace_program(ROOM);
}

