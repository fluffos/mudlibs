// experimental
// query or set required reputation for a post
#include <mudlib.h>
#include <sanguo.h>

inherit CMD;

private void main(string arg)
{
    string who;
    string cmd;
    int post, level;
    int repu;
    if (!arg)
    {
        write("use qsrepu post\n");
        return;
    }
// only allow one form of input
    if (sscanf(arg, "%s %d", cmd, post) != 2)
    {
        if (sscanf(arg, "%d", post) != 1)
        {
            write("use qsrepu set post\n");
            return;
        }
    }
// only can set yourself
// only for wiz
    who = this_body()->query_userid();
    if (!(wizardp(who)))
    {
        printf("only wiz can use");
        return;
    }
// query required reputation
    level = OFFICER_D->query_level(post);
    if (level > 7)
        level = 7;
    repu = pow(10, level);
    if (!cmd)
    {
        sprintf("post %d requires reputation of %d", post, repu);
        return;
    }
// set required reputation
    if (cmd == "set")
        CHAR_D->set_char(who, "reputation", repu);
    return;
}
