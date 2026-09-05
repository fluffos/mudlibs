#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
    mapping my;
    string line, player_id, flag;
    int i;
    object player;
 
    seteuid(getuid(me));

    if (!arg) player=me;
    else player_id=arg;
    if (!player) player = present(player_id, environment(me));
    if (!player) player = find_player(arg);
    if (!player) player = find_living(arg);
    if (!player) return notify_fail("你要察看谁的状态？\n");

    line = sprintf(
            " 下面是%s(%s)的先天天赋：\n\n"
            " 膂力：[%d]  悟性：[%d]  根骨：[%d]  身法：[%d]\n"
            " 福源：[%d]  容貌：[%d]  灵性：[%d]  \n\n",
            player->query("name"),
            player->query("id"),
            player->query("str"),
            player->query("int"),
            player->query("con"),
            player->query("dex"),
            player->query("kar"),
            player->query("per"),
            player->query("spi"));
 
    write(line);
    return 1;
}


int help(object me)
{
    write(@HELP
指令格式：gift <对象名称>
 
这个指令可以显示你或指定对象的先天天赋。

see also : score
HELP
    );
    return 1;
}
