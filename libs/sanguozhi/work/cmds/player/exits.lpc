// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;


private void main( string message )
{
    string * exits = environment(this_body())->query_exit_directions( 0 );
    string str = "你可以从：";
    switch( sizeof(exits))
    {
    case 0:
	out("你看不见任何出口。\n");
        return;
    case 1:
        str += exits[0];
        break;
    default:
        str += implode( exits[0..<2], ", " );
        str += "和 ";
        str += exits[<1];
    }
    str += " 方向离开这里。\n";
    out( str );
    return;
}
