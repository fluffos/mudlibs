// verify.c
// 实名玩家认证新玩家，避免恶意注册捣乱
// modified by Zine,修正no arg 报错
#include <ansi.h>

int main(object me, string arg)
{
        object pl;
        if(!me->is_realuser())
        {
            write("只有实名玩家才可以使用这个命令。\n");
            return 1;
        }
		if (!arg)
		{
			write("你要验证哪个id？\n");
			return 1;
		}
		if (!pl = find_player(arg))
		{
			write(arg+"不存在或者不在线！\n");
			return 1;
		}
        if(!userp(pl))
        {
            write("没有这个id\n");
            return 1;
        }
        
        if(pl->query("newbie_no_chat"))
        {
            pl->delete("newbie_no_chat");
            tell_object(pl,me->name()+"为你进行了验证，你可以正常使用chat,helpme,rumor等频道了！\n");
            write("搞定！\n");
        }
        else
        {
            write("人家已经认证过啦。\n");
        }

        return 1;
}




