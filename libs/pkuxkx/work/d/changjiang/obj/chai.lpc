// Zine dec 7 2010 ,长江黄河偶然事件

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_fire", "fire");
}

void create()
{
	set_name("干木柴", ({ "gan muchai","muchai","chai"}));
	set_weight(1500);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一根干木柴，你可以用来点火(fire)。\n");
			set("unit", "根");
		}
	set("value",0);
}

int do_fire()
{	
	object me = this_player();
    object ob = this_object();
	object huang,fire;
    if (me->query_temp("shediaoquest/kanglong/start")!=13)
    {
		message_vision(HIR"$N点燃了$n，可不一会就燃尽了！\n"NOR,me,ob);
		destruct(ob);
		return 1;
    }
	if (environment(me)->query("shediao_place")!=3)
	{
		message_vision(HIR"$N刚点燃$n，忽然想起：坏了，和黄蓉分手的地方并不是此处。\n"NOR,me,ob);
		tell_object(me,"你看着即将变成灰的木柴，还是快回去捡一点吧。\n");
		me->set_temp("shediaoquest/kanglong/start",12);
		destruct(ob);
		return 1;
	}
	huang=me->query_temp("shediaoquest/kanglong/huang");
	if (!huang)
	{
		tell_object(me,"黄蓉竟下落不明了！\n");
		return 1;
	}
	fire=new(__DIR__"fire");
	huang->move(environment(me));
	fire->move(environment(me));
	message_vision(HIR"$N刚点燃起"+ob->query("name")+"，正烘烤着湿衣服，$n夹着一只肥鸡走了回来。\n"NOR,me,huang);
	huang->cookji(me,huang);
	destruct(ob);
	return 1;
}

