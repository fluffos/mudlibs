#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("假药", ({"jia yao", "yao"}));
        set_weight(300);
        set("long", "这是一颗假药，吃了不会死人，但也没什么好事。\n");
        set("unit", "颗");
		set("fake_drug",1);
		set("job_id",1);//辨别不同药师任务
		set("value",1);
}
int modify(object me)
{
	if (!me->query_temp("AlchemyJob/"+this_object()->query("job_id")+"/start")||
	!me->query_temp("AlchemyJob/"+this_object()->query("job_id")+"/name"))
	return 1;
	set_name(me->query_temp("AlchemyJob/"+this_object()->query("job_id")+"/name"),({"yao","drug"}));
	set("long","这是一颗"+me->query("name")+"精心制作的良药。\n");
	set("producer",me->query("id"));
	return 1;
}

