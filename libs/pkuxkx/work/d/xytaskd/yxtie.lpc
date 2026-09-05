#include <ansi.h>
inherit ITEM;
void init()
{
	add_action("do_open","open");
}
void create()
{   
	set_name(HIR"英雄帖"NOR, ({"yingxiong tie", "tie"}));
    if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "张");
		set("long", 
			GRN"这是一张英雄帖，乃郭黄夫妇所发共聚襄阳的邀请函。\n从封面你就可以看出此帖写得匆忙，一定是有非同小可的事情发生，你可以打开它。(open)\n"NOR);
		set("value", 0);
		set("invitedname","    ");
	}
	setup();
	remove_call_out("des");
	call_out("des",300);
}
int des()
{
	destruct(this_object());
	return 1;
}
int do_open(string arg)
{
	object me;
	if(arg!="yingxiong tie"&&arg!="tie")
		return notify_fail("你要打开什么?\n");
	me=this_player();
	tell_object(me,HIY"你打开英雄帖，里面是郭靖给你的一封短信：\n\n"NOR);
	tell_object(me,HIR+"		英雄"+query("invitedname")+HIR"亲鉴：\n
		    蒙古今率数万之众，兴无名之师，伐我大宋，\n
		现已兵临襄阳城下，然朝廷无能，迟不见援兵来\n
		襄阳拒敌。当此国难之际，凡大宋子民当舍生取\n
		义，共拒强敌．危难之际，多说无益，望火速赶\n
		赴襄阳，共聚大义！\n
		　　　　　　　　来援为盼!\n
		                           　　　  郭靖字\n\n"NOR);
	return 1;
}



