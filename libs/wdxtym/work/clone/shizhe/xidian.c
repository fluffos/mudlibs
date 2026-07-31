// jinsha.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "无常丹" NOR, ({ "wuchang dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一粒晶莹剔透的丹药，服了之后使人强行散去所有技能，从新投胎转世。\n");
		set("unit", "粒");
		set("value", 50000);
		set("yuanbao", 50);
		set("only_do_effect", 1);
		set("weight", 1);
	}
	setup();
}

int do_effect(object me)
{
	string family,*skills;
	int i;

	message_vision(CYN "$N" CYN "小心的服下了一"+query("unit")+"" + name() + CYN "，决定重新做人。"NOR"\n", me);

	CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"服用了一粒"+this_object()->query("name")+""HIM"，重新进入轮回！");
	me->delete("family");
	me->delete("title");
	me->delete("class");
	me->delete("startroom");
	me->delete("born");
	me->delete("born_family");
	me->delete("character");
	me->delete("type");
	log_ufile(me,"wuchang","重新投胎了。\n");
	destruct(this_object());

	return 1;
}
int query_autoload() { return 1; }