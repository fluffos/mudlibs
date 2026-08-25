// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit CMD;

void main( mixed width )
{
    width = to_int(width);
    if( !intp( width ))
    {
        out( "屏幕宽度一定要设成一个整数。\n");
        return;
    }
    if( !width )
    {
        out( "你目前的屏幕宽度是：" + this_user()->query_screen_width() + "。\n" );
        return;
    }
    if( width < 20 )
    {
        out( "屏幕宽度最好是大于 20 。\n");
        return;
    }
    this_user()->set_screen_width( width );
    out( "完成屏幕宽度设定。\n");
}
