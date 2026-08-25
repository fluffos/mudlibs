// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust

#include <mudlib.h>

inherit CMD;


private void main(mixed *arg) {
    string where;
    if (!arg[0]) {
        outf("你的起始地点为: %s\n", this_body()->query_start_location() );
        return;
    }
    if( arg[0]->is_living() )
    {
        out("你在说啥呢？！\n");
        return;
    }
    where = file_name(arg[0]);
    this_body()->set_start_location( where );
    outf("你设定起始地点为: %s.\n", where );
    return;
}

