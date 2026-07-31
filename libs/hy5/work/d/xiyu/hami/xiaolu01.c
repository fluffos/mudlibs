// xiaolu01   哈密小路
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "小路");
    set( "long", @LONG
一条碎石小路，向东通向一个西域小镇，在这边远的地方，是如此的平静、
安宁，一扫大漠的黄沙，这里四周的田地是一片青翠，树木郁郁葱葱，十分茂盛
，树盖和树林枝繁叶茂，色泽浓重。
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "west" : "/d/xiyu/gebi",
    "east" : __DIR__"xiaolu02",
]) );
    set( "outdoors", "西域" );
    setup();
}

