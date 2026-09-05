#include <ansi.h>

inherit "/cmds/guider/guidercmd";

int get_cost(object me) {return 0;}

int exec_cmd(object me, string str)
{
        object monitor;
        
        if (!str) {
                write(CYN"你看起来表情丰富。\n"NOR);
                return 1;
        }
//替换回车，防止玩家发布假信息
        str = replace_string(str, "\n", " ");

        if ((int)me->query("chblk_on") && !wizardp(me)) 
                return notify_fail("你的频道被关闭了！\n");  

        str = F_NAME->replace_color(str);

        if( strsrch(str, "$ME$") == -1 )
                write("你输入的字串中必需含有$ME$\n");
        else{
                if( str == (string)me->query_temp("last_channel_msg") )
                {  
                        write("用交谈频道说话请不要重复相同的讯息。\n");
                        return 0;
                } 
                me->set_temp("last_channel_msg", str);
                str = replace_string(str, "$ME$", me->name());
                monitor=load_object(MONITOR_D);
                if(me->query("grobot"))
                        CHANNEL_D->do_channel(monitor, "helpme", str, -1);
                else
                        CHANNEL_D->do_channel(monitor, "chat", str, -1);
        }

        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式: cemote <动作描述>
这个指令可以让你表达一个系统没有预设的动作词, 要求动作描述中含有$ME$,
系统会将你所输入的文字中的$ME$替换为你的姓名後显示在闲聊频道中。
 
范例: cemote $ME$对着大家一抱拳，说道：“各位英雄，请了！”
你会看见: 【闲聊】包子对着大家一抱拳，说道：“各位英雄，请了！”
其中, 包子就是你的名字.
名字可以出现在动作描述中的任意位置.
 
可以加入颜色代码，颜色代码请打color查询。
如何运用颜色代码可以参考help nick获得帮助。
 
相关指令: emote semote
 
HELP
    );
    return 1;
}
