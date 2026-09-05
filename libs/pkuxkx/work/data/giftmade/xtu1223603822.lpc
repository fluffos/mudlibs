// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG +"八哥"+ NOR, ({ "toy" }));
	set("long","这是qianr花费数年时间训练的一只巧嘴八哥.\n经过挑染、片染、东染、西染，八哥看起来活脱脱一只肉乎乎的小兔子。\n雪の兔小朋友看着八哥就像照镜子一样。\n\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "xtu");
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
	message_vision("$N戳了八哥一下，八哥一激灵，立马抬头挺胸，大声赞道：\n小雪仙姑，德披天下，战无不胜，攻无不克。\n接着又小声嘟囔了一句，就是照qianr姐姐还差点。\n",this_player());
	return 1;
}

