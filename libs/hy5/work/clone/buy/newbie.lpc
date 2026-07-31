#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "openbeg");
}

void create()
{
	set_name(HIY"新手包"NOR, ({"nb bao", "nbbao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个新手包。似乎可以打开(openbeg)。\n");

set("no_put", 1);
set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	int exp,pot,score;
object corpse;
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要打开什么？\n");




message_vision(HIY "$N打开了新手包!获得了很多宝贝!\n" NOR, me);





corpse=new("/clone/money/gold");
corpse->set_amount(10000);
corpse->move(me);
tell_object(me,HIY"你找到了一万两黄金!\n"+NOR);

corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);
corpse=new("/clone/buy/neilidan");
corpse->move(me);

tell_object(me,HIY"你找到了十颗内力丹!\n"+NOR);

        if (me->query("per") < 25)
        {
                tell_object(me, HIY "你觉得似乎自己的相貌发生了变化。\n" NOR);
                me->set("per", 25);
        }


        if (me->query("kar") < 25)
        {
                tell_object(me, HIY "你觉得似乎自己的福缘发生了变化。\n" NOR);
                me->set("kar", 25);
        }

	me->add("mpgx", 8);
	destruct(this_object());
	return 1;
}