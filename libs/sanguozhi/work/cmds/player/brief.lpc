// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** brief.c
**
*/

#include <playerflags.h>
#define USAGE "用法: brief [on|off]\n"

inherit CMD;



private string query_setting()
{
    return this_body()->test_flag(F_BRIEF) ? "开启" : "关闭";
}

nomask private void main(string arg)
{
    if ( !arg || arg == "" )
    {
	out("短信息模式现在是" + query_setting() +
	      "着的。\n" + USAGE);
	return;
    }

    switch ( arg )
    {
    case "on":
	this_body()->set_flag(F_BRIEF);
	break;

    case "off":
	this_body()->clear_flag(F_BRIEF);
	break;

    default:
	out(USAGE);
	return;
    }

    out("短信息模式现在" + query_setting() + "。\n");
}
