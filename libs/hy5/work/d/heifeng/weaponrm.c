// /d/heifeng/weaponrm.c

inherit ROOM;

void create()
{
        set("short", "兵器房");
        set("long", @LONG
这里是存放兵器的地方。一些常用的兵器整齐地放在
屋里的架柜上。几个强盗刚刚取了些兵器下山去了，还有
几把刀枪散落在地上。
LONG
        );
        set("exits", ([ 
            "east"   : __DIR__"corr02",
]));
        set("objects",([
        __DIR__"npc/obj/spear" : 2,
        __DIR__"npc/obj/blade" : 2,
]));
        setup();
        replace_program(ROOM);
}

