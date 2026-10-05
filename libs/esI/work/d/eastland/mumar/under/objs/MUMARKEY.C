#include <mudlib.h>
inherit OBJECT;
 
void create()
{
        set_name( "mumar key","警闭室钥匙" );
        add( "id", ({ "key" }) );
        set_short( "警闭室钥匙" );
        set_long(
                "这是牧马关警闭室的钥匙。\n"
        );
        set( "unit", "串" );
        set( "to_lock", "MUMARKEY" );
        set( "weight", 10 );
        set( "value", ({ 10, "silver" }) );
        set( "no_sale", 1 );
}
