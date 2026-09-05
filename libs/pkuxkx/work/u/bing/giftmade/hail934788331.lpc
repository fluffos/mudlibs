// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW +"结婚礼物"+ NOR, ({ "cabbage" }));
	set("long","这是白菜送给hail的,用来纪念他和xueling的婚礼的礼物\n\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "hail");
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
	message_vision(" 只见$N拿起礼物,按下按钮,从礼物中走出一个小人,看打扮正是江湖上大名鼎鼎的\n老不死的白菜.白菜清清嗓子,说:"我白菜,今天证明法剑和雪玲结为夫妇\n今生今世永不分离.!"说完,又退了回去.\n",this_player());
	return 1;
}

