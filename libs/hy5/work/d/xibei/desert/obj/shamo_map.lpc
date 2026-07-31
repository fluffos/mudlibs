/* shamo_map.c
 * from XO Lib
 * a npc of desert
 * created by hydra 19980423
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980423
 */

inherit ITEM;

int LookMap( string );

void create()
{
    set_name( "沙漠行旅图",({ "xinglv tu","tu","map" }) );
    set_weight( 200 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit","幅" );
        set( "long",@LONG
一幅关于怎么过沙漠的图。据说是勤劳的楼兰国人花了几代人的心血画的，
是他们在被沙漠吞噬，行将灭亡的时候总结出来的规律。
你可以查(cha)一下图，试试他能否给你一些出沙漠的方法。
LONG
        );
        set( "material","paper" );
    }

    set( "no_drop",1 );
    set( "no_get",1 );
    set( "cant_sell","这种破东西，本店不收。\n" );
    setup();
}


void init()
{
    add_action( "LookMap","cha" );
}

int LookMap( string arg )
{
    string south;
    object me;
    me = this_player();
    if( arg != "xinglv tu" && arg!="tu" && arg!="map" ) return 0;
    if( environment( me )->query( "outdoors" ) != "desert" )
        return notify_fail( "图在这个地方没用。\n" );
    if( south = environment( me )->query_south( 1 ) )
        write( "你打开图，仔细看了一下，你终于认清了南方：" + south +"。\n" );
    else
        write( "在这个地方图没有用。\n" );
    return 1;
}


