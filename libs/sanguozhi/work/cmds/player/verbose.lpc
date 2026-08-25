// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** verbose.c
**
*/

#include <playerflags.h>
#define USAGE "用法: verbose [on|off]\n"

inherit CMD;



private string query_setting()
{
    return this_body()->test_flag(F_BRIEF) ? "关闭" : "开启";
}

nomask private void main(string arg)
{
    if ( !arg || arg == "" )
    {
        out("目前 Verbose 状态是" + query_setting() +
              ".\n" + USAGE);
        return;
    }

    switch ( arg )
    {
    case "on":
        this_body()->clear_flag(F_BRIEF);
        break;

    case "off":
        this_body()->set_flag(F_BRIEF);
        break;

    default:
        out(USAGE);
        return;
    }

    out("现在" + query_setting() + " verbose 状态。\n");
}
