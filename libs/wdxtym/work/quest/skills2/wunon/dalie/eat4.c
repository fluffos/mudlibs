// ∞Ÿ∫œ /clone/eat/food/bai_he.c
// by lala, 1997-12-16

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name( "÷Ì»‚", ({"liewu4"}) );
    set_weight( 50000 );
    if ( clonep() )
            set_default_object( __FILE__ );
    else {
        set( "long", @LONG
“ªøÈ÷Ì»‚°£
LONG
        );


        set( "unit", "øÈ" );
        set( "value", 400 + random( 500 ) );
        set( "food_remaining", 2 );
        set( "food_supply", 25 );
    }
}

