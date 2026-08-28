#include <message.h>

/* coder: dranil */

int
main(string str)
{
    if (!str)
    {
        p_line ("Usage: title clear/titlestring\n");
        return 1;
    }

    if (lower_case(str)=="clear")
    {
        p_line ("Title cleared.\n");
        THIS->set("title", "");
        return 1;
    }

    THIS->set("title", str);
    p_line ("You are now: "+THIS->short()+"\n");
    return 1;
}
