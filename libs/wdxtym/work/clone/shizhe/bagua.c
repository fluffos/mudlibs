inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIR"八卦"NOR, ({"ba gua"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100000);
//		set("yuanbao", 200);
		set("u_times",3);
		set("unit", "个");
		set("long","这是一个八卦，可以"ZJURL("cmds:use ba gua")ZJSIZE(20)"占卜"NOR"当前师门任务目标的精确位置!\n");
	}
}

void init()
{
    if (environment()==this_player())
    	add_action("on_used","use");
}

int on_used(string arg)
{
	object ob;
	object me=this_player();
	mapping q;

	if (arg!="ba gua")
      		return notify_fail("你要用什么?\n");  

	if(!mapp(q=me->query("quest")))
	{
      		return notify_fail("你现在没有任务，使用八卦打听什么?\n");  
	}
	if(q["type"]!="kill")
	{
      		return notify_fail("你现在没有师门杀人任务，无需打探。\n");  
	}
	if(ob=find_living(q["id"]))
	{
		tell_object(me,q["name"]+"目前正在"+q["place"]+"的"+environment(ob)->query("short")+"活动。\n");
		add("u_times",-1);
	tell_object(me,"这个八卦还可以使用"+query("u_times")+"次。\n");
	}

	if(query("u_times")<=0){
	tell_object(me,"奇门八卦盘因为使用次数过多而破损了。\n");
		destruct(this_object());
}

	return 1;
}
