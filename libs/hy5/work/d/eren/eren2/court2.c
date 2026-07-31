 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "彩石路");
        set("long", @LONG
一条用五彩石块砌成的道路，很难想象在这个阴湿的山洞里竟然有人
会花费如此的心机。石块映着烛火，闪烁着妖异的光芒，为这个山洞平添
了几分神秘的色彩。
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"court3",
                "westup" : __DIR__"court1",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
