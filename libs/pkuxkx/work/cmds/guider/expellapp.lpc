//MODIFIED BY　Zine 2012/1/9 修正不能离线开除的一个错误，美化一下描述。
#include <ansi.h>
inherit "/cmds/guider/guidercmd";

int get_cost(object me) {return 100;}

int exec_cmd(object me, string str)
{
	object ob;
	int i;

	if (!str)
	{
		tell_object(me,"指令格式：expellapp <学员的ID>\n");
		return 0;
	}
	if (GUIDER_D->is_app(str)!=me->query("id"))
	{
		tell_object(me,str+"不是你的学生。\n");
		return 0;
	}
    if(!me->query_temp("guider/expell") || me->query_temp("guider/expell") != str)
    {
        me->set_temp("guider/expell",str);
		tell_object(me,"你真的要将"+str+"开除出去吗？如果是，请再执行一次本命令。\n");
		return 0;
    }
    else
    {
		i=GUIDER_D->del_app(str);
        if (i==0)
		{
			tell_object(me,"暂时不能完成此操作。\n");
			return 0;
		}
		if (i==-1)
		{
			tell_object(me,str+"不是你的学生。\n");
			return 0;
		}
        write("你把"+str+"开除了。你们从此不再是师徒关系。\n");
        shout(HIY+me->name()+"将"+str+"开除了。\n"+NOR);
        me->delete_temp("guider/expell");        
        if(ob=find_player(str))
        tell_object(ob,"你被"+me->query("name")+"逐出宗派了。\n");
        return 1;

    }
    return 1;
}

int help(object me)
{
	write(@HELP
指令格式: expellapp <学员的ID>

这个指令是用来开除你的学生。注意，这将大量损耗你的导师积分。

HELP
	);
	return 1;
}

