// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <daemons.h>

inherit CMD;

private void main(string str) {
    string rule;
    if ( !is_directory(wiz_dir(this_user())) )
    {
        out("对不起，只有全职巫师才能删除 emote。\n");
        return;
    }

    if (!str) {
        out("用法：rmemote <verb>\n");
        return;
    }
    sscanf(str, "%s %s", str, rule);
    if (SOUL_D->remove_emote(str, rule))
        out("删除成功。\n");
    else out("删除失败。\n");
}

