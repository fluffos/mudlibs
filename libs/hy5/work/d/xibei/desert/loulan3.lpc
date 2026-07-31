/* loulan3.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980408
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980408
 */

inherit ROOM;

void create()
{
    set( "short","古民房" );
    set( "long",@LONG
这里是一些残存的房屋，没有屋顶，但房柱、墙壁仍在。红柳枝编成的篱，
再抹上黄泥，作成夹墙；房柱歪七扭八，倾斜而立；胡杨木的大门依然敞开着，
似乎主人刚走出家门，一会儿就会回来。
LONG
    );

    set( "outdoors","desert");
    set( "exits",([ /*sizeof() == 2 */
        "north" : __DIR__"loulan2",
    ]) );

    set( "not_startroom",1 );
    setup();
}


