// edit.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
    string str;
    if( !file ) return notify_fail("指令格式：edit <档名>\n");

    if( in_edit(me) ) return notify_fail("你已经在使用编辑器了。\n");

    seteuid(geteuid(me));
    file = resolve_path(me->query("cwd"),file);
    me->set("cwf", file);
    CHANNEL_D->do_channel(me, "sys", "Editing file " + file);
    me->delete_temp("last_channel_msg");
    ed(file);
    str = me->query("name") + "(" + me->query("id") + ")编辑" + file + 
    "   " + ctime(time()) + "。\n";
    log_file("wiz/edit", str);
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : edit <档名>, edit here

利用此一指令可直接在线上编辑档案。
HELP
    );
    return 1;
}
