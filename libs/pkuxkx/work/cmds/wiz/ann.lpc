// Modified by iszt@pkuxkx, 2007-03-21, added log
// Modified by iszt@pkuxkx, 2007-05-09, removed anner

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if (!arg) {
                message("vision",HIY"【通知】"+me->name()+HIY"：......\n"NOR,users());
                return 1;
        }
        message("vision",HIY"【通知】"+arg+"\n"NOR,users());
/*
        write_file("/doc/help/ann", ctime(time())+"发布通知：\n"
                "\t"+arg+"\n", 0);
*/
        write_file("/doc/help/change", ctime(time())+"发布通知：\n"
                "\t"+arg+"\n", 0);
        return 1;
}

/*
int help(object me)
{
  write(@HELP
指令格式 : shout <讯息>
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话.
此指令暂不对玩家开放。
see also : tune
HELP
    );
    return 1;
}
*/
