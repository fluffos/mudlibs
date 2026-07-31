// 百合 /clone/eat/food/bai_he.c
// by lala, 1997-12-16

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name( "百合", ({"bai he","lily"}) );
    set_weight( 30000 );
    if ( clonep() )
            set_default_object( __FILE__ );
    else {
        set( "long", @LONG
宜兴所产的百合，号称“太湖之参”，营养极为丰富，可以入药。
LONG
        );


        set( "unit", "包" );
        set( "value", 300 + random( 500 ) );
        set( "food_remaining", 2 );
        set( "food_supply", 25 );
    }
}

