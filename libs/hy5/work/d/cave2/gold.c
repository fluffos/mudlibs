 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "金屋");
        set("long", @LONG
黄金的墙壁果然随之移动，现出了道门户，人还未进去，已有
一片辉煌的光洒了出来。这金色的墙壁后，竞赫然全都是珠宝，
数不清的珠宝，任何人做梦都想不到会有这么多的珠宝！ 
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
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
