// emote.c (Mon  09-04-95)

#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string str)
{
    if (!str) {
        write(CYN"你看起来表情丰富。\n"NOR);
        tell_room(environment(me), CYN+(string)me->name()+
		"看起来表情丰富。\n" +NOR, me);
        return 1;
    }
//    write(CYN"你"+str+"\n"NOR);
    message_vision(CYN+(wizardp(me)? "":"->")+(string)me->name()+str+"\n"+NOR, me);
		if (objectp(CHANNEL_D->query("logger"))  && !me->query("no_logger"))
		{
          if ((userp(me) && userp(CHANNEL_D->query("logger"))) && (str[0..3] != me->query_temp("logger/last_tell_msg")) && (str[0..3] != me->query_temp("logger/last_tell_msg2"))|| (strsrch(str,"私人谈话")!=-1)  )
                                 tell_object(CHANNEL_D->query("logger"),sprintf(  "->%s的%s："+HIG+"%s\n" NOR,
                environment(me)->query("short"),me->name(1)+"("+me->query("id")+")", str));
			me->set_temp("logger/last_tell_msg2",me->query_temp("logger/last_tell_msg"));
			me->set_temp("logger/last_tell_msg",str[0..3]);
		}
    return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式: emote <动作词>

这个指令可以让你表达一个系统没有预设的动作词, 系统会将你所输入
的文字加上你的姓名後显示给所有在同一个地方的生物看. 为了避免造
成困扰, 玩家所输入的词句前面会加上 -> 以供区别. (巫师则不在此
限.)

范例: emote 坐了下来。
你会看见: 你坐了下来。
其他人会看到: ->包子坐了下来。

其中, 包子就是你的名字.

相关指令: semote
HELP
	);
        return 1;
}
