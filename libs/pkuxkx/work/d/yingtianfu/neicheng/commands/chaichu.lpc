// chaichu.c 
// Zine 2012/10/14
#include <ansi.h>
#include "cmd_assist.h"
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int main(object me,string arg)
{
	object ming,pl;
	string *list=({});
	if (arg=="-h")
	return help(me);
	if (!identification(me,"工部尚书")&&me->query("id")!="zine")
	return deny(me);
	if (!arg||arg=="")
	{
		tell_object(me,"你要拆除哪位大明官员扩建的宅邸？\n");
		return 1;
	}
	if (time()-me->query("ming/enlarge_house_command")<3600)
	{
		tell_object(me,"你刚刚下令为一位大明官员扩建或拆除过宅邸，这时候工部没人了，稍等等吧。\n");
		return 1;
	}
	ming=load_object("/d/yingtianfu/neicheng/shengzhi");
	ming->restore();
	if (ming->query("extra_home_list"))
	list=ming->query("extra_home_list");
	if (member_array(arg,list)==-1)
	{
		tell_object(me,arg+"并没有被扩建过宅邸。\n");
		return 1;
	}
	list-=({arg});
	ming->set("extra_home_list",list);
	ming->save();
	me->set("ming/enlarge_house_command",time());
	tell_object(me,"你将"+arg+"的宅邸拆除扩建的部分！\n");
	message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")开始拆除"+arg+"宅邸的扩建部分！\n"NOR,users());
	return 1;
}
int help(object me)
{
    write("
指令格式 : chaichu <id> 
让工部拆除某位大明官员的宅邸扩建部分。
"    );
    return 1;
}
