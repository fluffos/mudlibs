#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

int help(object me);

void create() {seteuid(getuid());}

int main(object me, string arg)
{
	if(!arg || arg=="")
	{
		if(me->query("auto_reply"))
		{
			write("你设定的自动回复内容如下：\n       "+GRN+me->query("auto_reply")+NOR+"\n");
		}
		else
		{
			write("你没有设定任何的自动回复。请用auto_reply + 自动回复内容来设定。\n");
		}
		return 1;
	}
	if(arg=="cancel")
	{
		me->delete("auto_reply");
		write("你取消了自动回复的设定。\n");
		return 1;
	}
	me->set("auto_reply",arg);
	write("你将自动回复内容设定为：\n       "+GRN+me->query("auto_reply")+NOR+"\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：auto_reply <内容|cancel>

    你可以使用这个指令来设定自动回复内容。这样，当你在遇到非正常情况
（例如：断线、编辑文件或者发呆）的时候，可以借由系统自动将你所设定的
回答发给tell或者reply你的人。
    如果使用auto_reply cancel，则会撤销关于自动回复内容的设定。
    请注意，只有当你set auto_reply 之后或者处于非正常情况的时候，
自动回复功能才会生效。

其他相关指令：tell,reply
HELP
        );
        return 1;
}