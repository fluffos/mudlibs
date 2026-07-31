// lingzhi.c 千年雪莲
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"九转小金丹"NOR, ({"jin dan", "jindan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗九转金丹。\n");
    set("value", 0);
set("no_steal",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","每个人只有一个，不要这么贪心！\n");
    set("no_drop","这么珍贵的东西你也扔？！\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	int exp,pot,score;
object corpse;
        object me = this_player();
	if (!id(arg))
	return notify_fail("你要吃什么？\n");
        this_player()->start_busy(30);

	exp = 500+random(500);
	             pot = exp*2/3;
             score = random(20)+10;
        me->add("max_neili", 5);
        me->add("combat_exp", exp);
        me->add("potential", pot);
tell_object(me,HIY"你被奖励了：5点内力上限\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);

        message_vision(HIY "$N吃下一颗九转金丹，只觉得体内真力源源滋生，你好像变了一个人似的!\n" NOR, me);

	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
