// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY +"宋词三百首"+ NOR, ({ "book" }));
	set("long","\n※※※※※\n※※\n※宋※\n※词※\n※三※\n※百※\n※首※\n※※\n※※※※※\n\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "cobra");
		set("auto_load", 1);
		set("material", "gold");
	}
	setup();
}	

void init()
{
	if (this_player()->query("id")!=query("owner"))
	{
		message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
		message_vision(query("name")+"从$N的身上掉了下来，在地上滚了滚，不见了。\n",this_player());
		destruct(this_object());
		return;
	}
	add_action("do_play","play");
}

int do_play(string arg)
{
	if (!arg || arg!=query("id"))
	{
		write("你要玩什么？\n");
		return 1;
	}
	message_vision("$N拿出一本《宋词三百首》，戴上两个啤酒瓶底，摇头晃脑的念道：$\n明月几时有？把酒问青天。\n不知天上宫阙，今夕是何年。\n我欲乘风归去，又恐琼楼玉宇，高处不胜寒。\n起舞弄清影，何似在人间。\n\n转朱阁，低绮户，照无眠。\n不应有恨，何事长像别时圆。\n人有悲欢离合，月有阴晴圆缺。\n此事古难全，但愿人长久，千里共婵娟。\n\n",this_player());
	return 1;
}

