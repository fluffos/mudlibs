// kuojian.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "cmd_assist.h"
int help(object me);
int main(object me,string arg)
{
	object song,pl;
	string *names=({}),*list=({}),msg="大宋已扩建储物间的官员列表：\n";
	int i;
	if (arg=="-h")
	return help(me);
	if (me->query("id")!="zine"&&!DASONG_D->identification(me,({"工部尚书","工部侍郎"})))
	return deny(me);
	if (time()-me->query("song/enlarge_house_command")<3600)
	{
		tell_object(me,"你刚刚为一位大宋官员扩建过储物间，这时候工部没人了，稍等等吧。\n");
		return 1;
	}
	song=load_object("/d/song/record/other");
	if (song->query("extra_home_list"))
	{
		list=song->query("extra_home_list");
	}
	if (!arg||arg=="")
	{
		if (sizeof(list)==0)
		{
			msg="大宋暂时尚无任何官员扩建储物间。如需扩建某位官员储物间，请输入kuojian <id>。\n";
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
	if (song->query("all_the_dasong_officers"))
	names=song->query("all_the_dasong_officers");
	if (member_array(arg,names)==-1)
	{
		tell_object(me,"你只能为大宋官员扩建储物间！\n");
		return 1;
	}
	if (sizeof(list)>=10)
	{
		tell_object(me,"已经扩建了至少十处的储物间，再建大宋财力支持不住了！\n");
		return 1;
	}
	if (member_array(arg,list)!=-1)
	{
		tell_object(me,arg+"已经被扩建过储物间了！\n");
		return 1;
	}
	list+=({arg});
	song->set("extra_home_list",list);
	song->save();
	me->set("song/enlarge_house_command",time());
	tell_object(me,"你将为"+arg+"扩建储物间！\n");
	CHANNEL_D->do_channel(this_object(), "dasong", me->query("name")+"("+capitalize(me->query("id"))+")开始扩建"+arg+"的储物间！", -1);
	return 1;
}
int help(object me)
{
    write("
指令格式 : kuojian <id> 
让工部扩建某位大宋官员的储物间。
"    );
    return 1;
}
