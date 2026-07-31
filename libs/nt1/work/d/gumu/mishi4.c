// mishi4.c 密室
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "密室");
        set("long", @LONG
这里是古墓中的密室，四周密不透风，你只能借着墙上昏暗的灯
光来勉强分辨方向。墙是用整块的青石砌合起来的，接合的甚是完美，
你难以从中找出一丝缝隙。墙上好象雕有一些诗句。
LONG
        );

        set("exits", ([
                "west" : __DIR__"mishi3",
                "east" : __FILE__,
                "north" : __FILE__,
                "south" : __FILE__,
        ]));

        setup();
        replace_program(ROOM);
}
