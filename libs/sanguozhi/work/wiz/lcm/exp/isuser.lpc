// experimental
#include <mudlib.h>
#include <sanguo.h>

inherit CMD;

private void main(string arg)
{
    string uid;
    object who;
    object* u;
    int i, size;
    if (!arg)
    {
        write("use isuser userid\n");
        return;
    }
// only allow one form of input
    if (sscanf(arg, "%s", uid) != 1)
    {
        write("use isuser userid\n");
        return;
    }
    who = CHAR_D->find_char(uid);
    if (!(objectp(who)))
    {
        printf(uid + " is not an object\r\n");
//        return;
    }
    u = users();
//    if (member_array(who, u) != -1)
//    {
//        printf(uid + " is a user\r\n");
//        return;
//    }
    size = sizeof(u);
    for (i = 0; i < size; i++)
    {
        if (uid == u[i]->query_userid())
        {
            printf(uid + " is a user\r\n");
            return;
        }
    }
    printf("cannot find user " + uid + "\r\n");
    return;
}
