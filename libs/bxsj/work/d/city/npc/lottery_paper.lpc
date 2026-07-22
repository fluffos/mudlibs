// Lottery_paper.c 兑奖券

#include <ansi.h>
inherit ITEM;

string do_look();

void create()
{
        set_name(HIW"兑奖券"NOR, ({"duijiang quan", "quan"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("no_give", 1);
                set("no_get", 1);
                set("no_drop", 1);
                set("material", "paper");
	}
	set("long", (: do_look :));
	setup();
}

string do_look()
{
	object me = this_player();
	string str = me->query("lottery/number");

	if ( ! str )
		return "这是一张普普通通的兑奖券，下面有些数字，不过已经模糊不清了。\n";
	else {
		me->set_temp("lottery_look", 1);
		return "一张普通的兑奖券，在醒目的位置有着一排数字，看来就是兑奖用的号码：\n"+
			CHINESE_D->font(str)+"\n";
	}
}
