// lingzhi.c 千年灵芝
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "xinshang");
}
void create()
{
        set_name(HIR"赵小曼"NOR, ({"lting"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","每个人只有一个，你都这么大方！\n");
   set("liwu",1);
    set("value", 0);
set("no_steal",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","每个人只有一个，不要这么贪心！\n");
    set("no_drop","这么珍贵的东西你也扔？！\n");

                set("unit", "位");
                set("long", "美女赵小曼 风骚艳丽 颠倒众生 大家可以来欣赏(xinshang)她\n");
                set("no_give", 1);
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{

	this_player()->add("combat_exp", 500);
	this_player()->add("potential",200);
        message_vision("$N轻轻地颓下赵小曼身上的薄纱.... 哇!!! 是男扮女装啊!!!\n", this_player());
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
