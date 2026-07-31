/* shamo9.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980325
 */

#define DIR   "/d/xiyu/lvzhou1"
//define the correct way

#include "shamo.h"

mapping *exit = ({
    ([ "forward" : "/d/xiyu/lvzhou1",
         "right" : __DIR__"shamo" + ( random( 5 )+5 ),
         "backward":__DIR__"shamo8",
         "left" : __DIR__"shamo" + ( random( 5 )+5 ),
       ]),
    ([ "right" : "/d/xiyu/lvzhou1",
         "backward" : __DIR__"shamo" + ( random( 5 )+5 ),
         "left":__DIR__"shamo8",
         "forward" : __DIR__"shamo" + ( random( 5 )+5 ),
       ]),
    ([ "backward" : "/d/xiyu/lvzhou1",
         "left" : __DIR__"shamo" + ( random( 5 )+5 ),
         "forward":__DIR__"shamo8",
         "right": __DIR__"shamo" + ( random( 5 )+5 ),
       ]),
    ([ "left" : "/d/xiyu/lvzhou1",
         "forward" : __DIR__"shamo" + ( random( 5 )+5 ),
         "right":__DIR__"shamo8",
         "backward" : __DIR__"shamo" + ( random( 5 )+5 ),
       ]),
});


void create()
{
    set( "short","大沙漠" );
    SetLong();

    set( "exits",exit[random( 4 )] );

    set( "outdoors","desert");
    set( "not_startroom",1 );
    setup();
    if( random( 4 ) == 1 )
        new( __DIR__"obj/stone" ) -> move( this_object() );
    if( random( 4 ) == 2 )
        new( __DIR__"obj/xiaostone" ) -> move( this_object() );
}

void init()
{
    add_action( "do_look",({ "look","l" }) );
    SetLong();
    if( this_player()->query( "hydra/desert/from" ) == "西域" )
        DecWater( this_player(),time() );
}
