 inherit ROOM;
void create()
{
        set("short", "暗河");
        set("long", @LONG
大水忽然往外冲，你身不由主，也随着水势被冲了出去，扑通一下掉
进了一条暗河之中。暗河不深，河水又黑又绿，冰凉的浸得你骨头都发麻，
一块随你一快儿掉下来的木板一起一伏，在水中荡漾。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"river2",
        ]));
        set("objects", ([
//              __DIR__"npc/rat" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}    
