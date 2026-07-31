// Room: /d/snow/npath3.c
inherit ROOM;
void create()
{
        set("short", "溪边小路");
        set("long", @LONG
你现在来到一条溪流边上的小路，溪水流过布满石块的河床发
出潺潺的声音，一条木桥跨过溪流往东通往镇外的小路，沿著溪边
往南不远处则可以望见一间磨坊。
LONG
        );
        set("outdoors", "xueting");
        set("exits", ([ /* sizeof() == 3 */
                //"east" : "/d/green/shuichi",
                "northwest" : __DIR__"npath2",
                "south" : __DIR__"lane2",
]));
        setup();
        replace_program(ROOM);
}
