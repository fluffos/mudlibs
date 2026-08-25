// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** Force another user to perform a command
**
** 950930, Ranma@Koko Wa: added logging
** ???: created by somebody :-)
*/

#include <mudlib.h>
#include <log.h>

inherit CMD;

void create()
{
    ::create();
    no_redirection();
}

private void main(string orig_input)
{
    int space = strsrch(orig_input, " ");
    string what = orig_input[space+1..];
    object targ_user = find_user(orig_input[0..space-1]);
    string s;

    if ( !targ_user )
    {
        printf("没有这个用户: %s\n", orig_input[0..space-1]);
        return;
    }

    //tell(targ_user, this_body()->query_name()+"强迫你做: "+what+"\n");
    write("你强迫"+targ_user->query_body()->query_name()+"做: "+what+"\n");

    s = sprintf("%s forces %s to (%s) [%s]\n",
                this_user()->query_userid(), targ_user->query_userid(),
                what, ctime(time()));
    LOG_D->log(LOG_FORCE, s);

    targ_user->force_me(what);
}
