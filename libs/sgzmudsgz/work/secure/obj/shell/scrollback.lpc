// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

object query_owner();   // in SHELL

private nosave string scrollback = "";
private nosave string last_scrollback = "";

private nomask void cmd_scrollback()
{
    if(last_scrollback=="")
    {
    //write("You have no scrollback.\n");
    write("你没有保留信息可以重读。\n");
    return;
    }
    more(last_scrollback);
}


nomask void end_scrollback()
{
    last_scrollback = scrollback;
    scrollback = "";
}

nomask void add_scrollback(string s)
{
    if ( previous_object() != query_owner() )
    //error("illegal attempt at adding scrollback data\n");
    error("试图非法增加保留信息\n");
    scrollback += s;
}
