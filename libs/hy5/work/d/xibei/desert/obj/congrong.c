/* congrong.c
 * from XO Lib
 * a widelife of desert
 * created by hydra 19980330
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980409
 */

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name( HIY"苁蓉"NOR,({ "cong rong","","congrong" }) );
    set_weight( 1000 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit","棵" );
        set( "long","这是一棵沙漠特有的植物，也是一种名贵的药材，被誉为“沙漠人参”。\n" );
        set( "value",100 );
        set( "food_remaining",5 );
        set( "food_supply",60 );
        set( "eat_msg","$N拿起$n咬了一口，只觉的满身充满了活力。\n" );
        set( "end_msg","$N终于把剩下$n吃的干干净净。\n" );
    }

    setup();
}

