// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** chanlist.c -- print available channels
**
** Print out the available channels in the system/intermud.  Note that
** the system allows any number of channels, so this will only print
** out some "suggested" channels.  This command is most effective for
** printing out a list of available Intermud channels.
**
** 950629, Deathblade: Created.
*/

#include <mudlib.h>
inherit CMD;

private nomask string fmt_imud_channel(string channel_name,
                                       mixed * channel_data)
{
    string owner = channel_data[0];
    string type = ({ "无限制",
                     "限制",
                     "过滤" })[channel_data[1]];

    if ( owner == "*" )
        owner = "无主状态";

    return sprintf("%-19s Intermud: %s, %s\n",
                   channel_name, owner, type);
}

private void main(string arg)
{
    string s;
    mapping chanlist = IMUD_D->query_chanlist();

    s = "现有频道列表：\n-----------------------------\n"
        "gossip              本地\n"
        "newbie              本地\n"
        "news                本地\n"
        ;

    if ( wizardp(this_user()) )
        s +=
            "wiz                 巫师专用\n"
            "announce            巫师专用\n"
            "errors              巫师专用\n"
            ;

    if ( adminp(this_user()) )
        s +=
            "admin               大神专用\n"
            ;

    if (wizardp(this_user()) )
    s += implode(({ "" }) + keys(chanlist),
                 (: $1 + fmt_imud_channel($2, $(chanlist)[$2]) :));

    out(s);
}
