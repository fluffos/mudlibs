// kuojian.c 
// Zine 2012/10/14
#include <ansi.h>
#include "cmd_assist.h"
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int main(object me,string arg)
{
	object ming,pl;
	string *names=({}),*list=({}),msg="大明已扩建宅邸的官员列表：\n";
	int i;
	if (arg=="-h")
	return help(me);
	if (me->query("id")!="zine"&&!identifications(me,({"工部尚书","工部左侍郎","工部右侍郎",})))
	return deny(me);
	if (time()-me->query("ming/enlarge_house_command")<3600)
	{
		tell_object(me,"你刚刚为一位大明官员扩建过豪宅，这时候工部没人了，稍等等吧。\n");
		return 1;
	}
	ming=load_object("/d/yingtianfu/neicheng/shengzhi");
	ming->restore();
	if (ming->query("extra_home_list"))
	{
		list=ming->query("extra_home_list");
	}
	if (!arg||arg=="")
	{
		if (sizeof(list)==0)
		{
			msg="大明暂时尚无任何官员扩建宅邸。如需扩建某位官员宅邸，请输入kuojian <id>。\n";
			tell_object(me,msg);
			return 1;
		}
		for (i=0;i<sizeof(list);i++)
		{
			msg+=list[i]+"\t";
		}
		msg+="\n";
		tell_object(me,msg);
		return 1;
	}
	if (ming->query("all_the_daming_officers"))
	names=ming->query("all_the_daming_officers");
	if (member_array(arg,names)==-1)
	{
		tell_object(me,"你只能为大明官员扩建宅邸！\n");
		return 1;
	}
	if (sizeof(list)>=10)
	{
		tell_object(me,"已经扩建了至少十处的宅邸，再建大明财力支持不住了！\n");
		return 1;
	}
	if (member_array(arg,list)!=-1)
	{
		tell_object(me,arg+"已经被扩建过宅邸了！\n");
		return 1;
	}
	list+=({arg});
	ming->set("extra_home_list",list);
	ming->save();
	me->set("ming/enlarge_house_command",time());
	tell_object(me,"你将为"+arg+"扩建宅邸！\n");
	message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")开始扩建"+arg+"的宅邸！\n"NOR,users());
	return 1;
}
int help(object me)
{
    write("
指令格式 : kuojian <id> 
让工部扩建某位大明官员的宅邸。
"    );
    return 1;
}
