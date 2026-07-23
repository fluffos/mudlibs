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
   set_name(HIG"粽子"NOR, ({"zong zi", "zongzi"}))
;
	if (clonep())
		set_default_object(__FILE__);
	else {
          set("unit", "个")
;
          set("long", "这是一个端午节的粽子。\n")
;
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
exp=300000+random(500)
;
pot=exp*2/3
;
             score = random(20)+10;
        me->add("max_neili", 5);
        me->add("combat_exp", exp);
        me->add("potential", pot);
tell_object(me,HIY"你被奖励了：5点内力上限\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);

    message_vision(HIY 
"今天是端午节，$N吃下一个粽子，豆沙馅的，感觉很不错，还想再吃几个!\n" NOR, me)
;

	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
