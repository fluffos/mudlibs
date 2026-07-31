// lingzhi.c 千年灵芝
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "qifu");

}
void create()
{
        set_name(HIY"北京"NOR, ({"xyanhu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","每个人只有一个，你都这么大方！\n");
    set("value", 0);
set("liwu",1);
set("no_steal",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","每个人只有一个，不要这么贪心！\n");
    set("no_drop","这么珍贵的东西你也扔？！\n");

                set("unit", "个");
                set("long", "这是一个北京（xyanhu),据说他说海洋的荣誉玩家，\n他看起来三十多岁了，有些皱纹和白发，一副受气包的模样，\n他陪着笑脸，让你觉得想欺负(qifu)他。\n");

		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
        return notify_fail("你要欺负谁？\n");
        this_player()->start_busy(20);
        this_player()->add("max_neili",10);
        this_player()->add("potential",500);
        this_player()->add("combat_exp",1000);
        message_vision("$N成功的欺负了北京，他给你献上了1000经验500潜能和10内力上限\n", this_player());
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
