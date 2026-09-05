// randomgen.c
// Random Generator
// Created by iszt@pkuxkx, 2007-02-17

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG"随机生成器"NOR, ({"random generator", "generator", "qi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个"HIG"随机生成器"NOR"，可以用来产生随机技能(genskill)或随机天赋(gengift)。\n");
                set("value", 10000);
                set("no_get", 1);
        }

        setup();
}

void init()
{
        add_action("gen_skill", "genskill");
        add_action("gen_gift", "gengift");
}

int gen_skill(string arg)
{
	object me = this_player();
        mapping skills = me->query_skills();
        string* sname = keys(skills);
	int i = random(sizeof(skills));

	message_vision(HIG"$N闭着眼睛启动了$n"HIG"，结果显示出来了：「"+CHINESE_D->chinese(sname[i])
		+"」(" + sname[i] + ")！\n"NOR, me, this_object());
	return 1;
}

int gen_gift(string arg)
{
	object me = this_player();
        string* giftname = ({"膂力", "悟性", "根骨", "身法", "福缘", "灵性", "容貌", });
	int i = random(sizeof(giftname));

	message_vision(HIG"$N闭着眼睛启动了$n"HIG"，结果显示出来了：「"+giftname[i]
		+"」！\n"NOR, me, this_object());
	return 1;
}