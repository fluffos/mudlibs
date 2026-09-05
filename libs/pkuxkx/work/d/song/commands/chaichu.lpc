// chaichu.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;

#include <ansi.h>
#include "cmd_assist.h"
int help(object me);
int main(object me,string arg)
{
	object song,pl;
	string *list=({});
	if (arg=="-h")
	return help(me);
	if (!DASONG_D->identification(me,({"工部尚书"}))&&me->query("id")!="zine")
	return deny(me);
	if (!arg||arg=="")
	{
		tell_object(me,"你要拆除哪位大宋官员扩建的宅邸？\n");
		return 1;
	}
	if (time()-me->query("song/enlarge_house_command")<3600)
	{
		tell_object(me,"你刚刚下令为一位大宋官员扩建或拆除过储物间，这时候工部没人了，稍等等吧。\n");
		return 1;
	}
	song=load_object("/d/song/record/other");
	if (song->query("extra_home_list"))
	list=song->query("extra_home_list");
	if (member_array(arg,list)==-1)
	{
		tell_object(me,arg+"并没有被扩建过储物间。\n");
		return 1;
	}
	list-=({arg});
	song->set("extra_home_list",list);
	song->save();
	me->set("song/enlarge_house_command",time());
	tell_object(me,"你将"+arg+"的宅邸拆除扩建的部分！\n");
	CHANNEL_D->do_channel(this_object(), "dasong", me->query("name")+"("+capitalize(me->query("id"))+")开始拆除"+arg+"储物间的扩建部分！", -1);
	return 1;
}
int help(object me)
{
    write("
指令格式 : chaichu <id> 
让工部拆除某位大宋官员的宅邸扩建部分。
"    );
    return 1;
}
