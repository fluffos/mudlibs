/* stone.c
 * from XO Lib
 * a npc of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980325
 */

inherit ITEM;

void create()
{
    set_name( "指南针",({ "zhinan zhen","compass" }) );
    set_weight( 200 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit","个" );
        set( "long","一个指南针，是中国古代人智慧的结晶。\n" );
        set( "value",5000 );
        set( "material","iron" );
    }

    set( "can_use",10 );
    setup();
}

void init()
{
    add_action( "do_use","use" );
}

int do_use( string arg )
{
    string south;
    object me;
    me = this_player();
    if( arg != "zhinan zhen" && arg != "compass" ) return 0;
    if( query( "can_use" )<1 ) return notify_fail( "这个指南针已经不能用了。\n" );
    if( environment( me )->query( "outdoors" ) != "desert" )
        return notify_fail( "在这种地方你还用得着指南针来判断方向吗?\n" );
    if( south = environment( me )->query_south( 0 ) )
        write( "你打开指南针,发现他的南针指向" + south +"方向。\n" );
    else
        write( "在这个地方指南针没有用。\n" );
    if ( environment( me )->query( "磁场" ) )
        add( "can_use",-2 );
    else 
        add( "can_use",-1 );
    return 1;
}


