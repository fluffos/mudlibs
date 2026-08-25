// Updated by stefan on 10 Jan 1997
// Updated by tset on 15 Apr 1998
/* Do not remove the headers from this file! see /USAGE for more info. */

// This command works only for admins.  -- Rust

#include <mudlib.h>
inherit CMD;

private void main()
{
    int flag;
    object user;

    flag = 0;

    if ( !check_privilege(1) )
    {
        out("对不起，这条命令只能给大神使用。\n");
        return;
    }

    foreach ( user in users() )
    {
        object ob = query_snooping(user);

        if ( ob )
        {
	    outf("%s 正在监听 %s.\n",
                   user->query_userid(),
                   ob->query_userid());
	    flag++;
        }
    }

    if ( flag == 0 )
	out("目前没有任何人被监听。\n");
}
