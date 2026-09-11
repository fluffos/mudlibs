// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;
inherit M_REGEX;
inherit M_GLOB;


private void main(string arg)
{
    mapping mudlist = IMUD_D->query_mudlist();
    string* muds = keys(mudlist);
    string* matches;
    string  match;
    mixed*  mudinfo;

    if(!arg || arg == "")
    {
        arg = mud_name();
    }
    matches = insensitive_regexp(muds, "^"+translate(arg));
    if(!sizeof(matches))
    {
        printf("在 %d 个 MUD 中，没有与之对应的。\n", sizeof(mudlist));
        return;
    }
    matches = sort_array(matches,1);
    foreach(match in matches)
    {
        mudinfo = mudlist[match];
       out(match + "\n");
        out("---------------------------\n");
        out(sprintf("类型: %s\n", mudinfo[8]));
        out(sprintf("网址: %s %d\n", mudinfo[1], mudinfo[2]));
        out(sprintf("目前 Mudlib: %s\n", mudinfo[5]));
        out(sprintf("基础 Mudlib: %s\n", mudinfo[6]));
        out(sprintf("Driver: %s\n", mudinfo[7]));
        out("状态:  ");
        if(mudinfo[0] == -1)
        {
            out("运行中\n");
        }
        else if(!mudinfo[0])
        {
            out("当机中\n");
        }
        else
        {
            out(sprintf("当机中 (可能在 %d 分钟内恢复运行)\n",
              (mudinfo[0]+60)/60));
        }
        out(sprintf("开放状态: %s\n", mudinfo[9]));
        out(sprintf("Admin email: %s\n", mudinfo[10]));
        out(sprintf("TCP Imud port: %d\n", mudinfo[3]));
        out(sprintf("UDP Imud port: %d\n", mudinfo[4]));
        out("提供的服务: ");
        if(!sizeof(mudinfo[11]))
            out("没有具体内容\n");
        else
            out(implode(sort_array(keys(mudinfo[11]) - ({ 0 }), 1), ", ") + "\n");
        if ( mudinfo[12] )
            out("其它数据: " + implode(keys(mudinfo[12]), ", ") + "\n");
        out("\n");
    }
}

