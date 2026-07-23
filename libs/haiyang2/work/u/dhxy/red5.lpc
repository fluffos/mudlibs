// lingzhi.c 千年灵芝
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
      add_action("do_eat", "smile")
;

}
void create()
{
set_name(HIC"正气丹"NOR, ({"duu"}))
;
	if (clonep())
		set_default_object(__FILE__);
	else {
//set("no_give","每个人只有一个，你都这么大方！\n")
//d
set("value", 50000)
;
//set("liwu",1)
set("no_steal",1);
set("no_beg",1)
;
//set("no_put",1)
//
//set("no_get","每个人只有一个，不要这么贪心！\n")
    set("no_drop","这么珍贵的东西你也扔？！\n");

                set("unit", "个");
;

set("value", 50000)
;
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
      return notify_fail("你要对谁微笑？\n")
;
        this_player()->start_busy(20);
        this_player()->add("max_neili",10);
        this_player()->add("potential",500);
this_player()->add("combat_exp",1000)
;
this_player()->add("expmax",1)
;
message_vision("$N对正气丹扑哧一笑，你感到你能力大增\n", this_player())
;
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
