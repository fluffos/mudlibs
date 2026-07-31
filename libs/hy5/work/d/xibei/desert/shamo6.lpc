/* shamo3.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980409
 * for more information to see shamo3.c
 */

#define DIR   __DIR__"shamo5"
//define the correct way

#include "shamo.h"

public int month;
mapping *exit = ({
    ([ "forward" : __DIR__"shamo5",
         "right" : __FILE__,
         "backward":__DIR__"shamo7",
         "left" : __FILE__,
       ]),
    ([ "right" : __DIR__"shamo5",
         "backward" : __FILE__,
         "left":__DIR__"shamo7",
         "forward" : __FILE__,
       ]),
    ([ "backward" : __DIR__"shamo5",
         "left" : __FILE__,
         "forward":__DIR__"shamo7",
         "right": __FILE__,
       ]),
    ([ "left" : __DIR__"shamo5",
         "forward" : __FILE__,
         "right":__DIR__"shamo7",
         "backward" : __FILE__,
       ]),
});


void create()
{

    set( "short","大沙漠" );
    SetLong();
    set( "exits",exit[random( 4 )] );

    if ( random( 3 ) == 0 )
        set( "objects",([ /*sizeof() == 1*/
            __DIR__"npc/camel":1,
        ]) );
    set( "磁场",1);    
    set( "outdoors","desert");
    set( "not_startroom",1 );
    setup();
}

void init()
{
    add_action( "do_look",({ "look","l" }) );
    remove_call_out( "check_month" );
    call_out( "check_month",2 );
    eventClear( this_object() );
    SetLong();
    remove_call_out("greet_me");    
    call_out( "greet_me",1,this_player() );
}

void check_month()
{   
    month = localtime( time_tick )[ LT_MON ] + 1;
    if( month > 7 || month < 4 )
        call_out( "before_storm",10 );
    else 
        call_out( "before_storm",100 );
}

void before_storm()
{
    message( "vision",RED"突然你感觉到脚下的沙子在震动。。。。。\n"NOR,this_object() );
    message( "vision",RED"你抬头向四周望了一下，你发现在远处的空中一团黑色的"
"烟雾在不停\n的扭动着，你隐隐感觉到有一丝不祥之兆。。。\n"NOR,this_object() );
    call_out( "check_storm",10 );
}

void check_storm()
{
    if( random( 60 ) >40 )
    {
        message( "vision",YEL"那团黑色的东西在空中盘旋了半天后，渐渐的远离而"
"去了。\n"NOR,this_object() );
    call_out( "check_month",450 );
    }
    else
    {
        message( "vision",RED"只见那团烟雾，伴随着巨大的旋风慢慢的向近处移动"
"过来，迎面而来\n的沙子，迷的你睁不开双眼。\n"NOR,this_object() );
        call_out( "sand_storm",5 );
    }
}

void sand_storm()
{
    object *all,*inv;
    int i,j,rannum;

    message( "vision",RED"伴随着风的呼啸声，沙子被卷到了半空，形成了螺旋式的擎"
"天圆柱。\n"NOR,this_object() );
    all = all_inventory( this_object() );
    for ( i=0; i<sizeof( all ); i++ )
    {
        if ( !living( all[i] ) && userp( all[i] ) )
        {
            destruct( all[i] );
            continue;
        }
        if ( !userp( all[i] ) ) 
        {
            //all[i]->die();
            continue;
        }
        else
        {
            inv = all_inventory( all[i] );
            for ( j=0;j<sizeof( inv );j++ ) 
            {
                inv[j] -> move( environment( all[i] ) );
                destruct( inv[j] );
            }   
            tell_object( all[i],"你感觉到一股巨大的力量把你托到了半空，然后你又掉了下来。\n" );
            rannum = random( 100 );
            if( rannum >97 )
            {
                switch( ( random( 5 )+5 ) )
                {
                    case 1:    
                        all[i] -> move( __DIR__"loulan1" );    
                        all[i] -> unconcious();          
                        break;
                    default:
                        all[i] -> die();
                       break;
                }
            }  
            else if( rannum >89 )
            {
                all[i] -> move( __DIR__"lvzhou" );
                all[i] -> unconcious();
            }
            else
            {
                all[i] -> move( __DIR__"shamo" + rannum/9 );
                all[i] -> unconcious();
            }
        }
        message( "vision","突然从空中掉下一物，砸在了地上。\n",
environment( all[i] ),({ all[i] }) );
    }
    call_out( "check_month",300 );
}
