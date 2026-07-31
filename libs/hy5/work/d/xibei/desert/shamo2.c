/* shamo2.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

#define DIR   __DIR__"shamo3"
//define the correct way

#include "shamo.h"

mapping exit = ([
    0:([ "forward" : __DIR__"shamo3",
         "right" : __DIR__"shamo" + random( 5 ),
         "backward":__DIR__"shamo1",
         "left" : __DIR__"shamo" + random( 5 ),
       ]),
    1:([ "right" : __DIR__"shamo3",
         "backward" : __DIR__"shamo" + random( 5 ),
         "left":__DIR__"shamo1",
         "forward" : __DIR__"shamo" + random( 5 ),
       ]),
    2:([ "backward" : __DIR__"shamo3",
         "left" : __DIR__"shamo" + random( 5 ),
         "forward":__DIR__"shamo1",
         "right": __DIR__"shamo" + random( 5 ),
       ]),
    3:([ "left" : __DIR__"shamo3",
         "forward" : __DIR__"shamo" + random( 5 ),
         "right":__DIR__"shamo1",
         "backward" : __DIR__"shamo" + random( 5 ),
       ]),
]);

string look_tujiu();

void create()
{
    set( "short","大沙漠" );
    SetLong();
    set( "exits",exit[random( 4 )] );

    set( "outdoors","desert");
    if( ( clock >=5 && clock <=10 ) || ( clock >= 14 && clock <=20 ) )
    {
        set( "item_desc",([
            "秃鹫" : (: look_tujiu :),
        ]) );
        set( "have_tujiu",1 );
    }
    set( "not_startroom",1 );
    setup();
    if( random( 4 ) == 1 )
        new( __DIR__"obj/stone" ) -> move( this_object() );
    if( random( 4 ) == 1 )
        new( __DIR__"obj/stone" ) -> move( this_object() );
    if( random( 4 ) == 2 )
        new( __DIR__"obj/xiaostone" ) -> move( this_object() );
}

void init()
{
    add_action( "do_look",({ "look","l" }) );
    remove_call_out("greet_me");
    call_out("greet_me",1,this_player());
}

string look_tujiu()
{
    if( this_object()->query( "have_tujiu" ) )
        return "一只巨大的秃鹫，正在空中盘旋着寻找猎物。\n";
    else
        return "这里的秃鹫已经被打光了。\n";
}



