#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object ob;
	mixed str;
	if( me->is_busy() )
		return notify_fail("你现在正忙着呢。\n");
	if( !arg || arg=="list" || arg=="all" )
		arg = 0;
	str = MOD_D->mod_statue(me,arg);
	if( !str || str=="" || !stringp(str) )
		return notify_fail(MUDLIB_NAME+"目前没有"+(arg?"头衔为"+arg:"可选")+"的套装。\n");
	me->start_busy(1);		
	me->start_more(str);
	return 1;
}

int help(object me)
{
	string msg = @LONG
指令格式 : mod <名称>     查看头衔为<名称>的套装属性
	   mod list	  查看泥潭中的所有套装
	   mod all	  查看泥潭中的所有套装
套装的附加属性是在装备的本身属性之外的，当装备了套装需要
的各类型的装备后，自动触发。
这里的套装是根据防具的装备头衔来的--当装备为红色或紫色后，会
有一定的几率出现装备头衔，比如：
铁拐李之八卦穿山甲(Bagua chuanshan jia)
在这里，八卦穿山甲的装备头衔就是铁拐李
	   
LONG;		
	write(msg);	
    	return 1;
}

