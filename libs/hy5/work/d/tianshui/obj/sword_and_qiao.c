// sword_and_qiao.c

#include <ansi.h>
#include <weapon.h>


inherit HAMMER;
// inherit ITEM;

int no_save_in_home() { return 1; }

void create()
{
        set_name("带鞘的宝剑", ({ "qsword" }) );
        set_weight(10000);
	set("valid_number",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把带鞘的宝剑，剑把上嵌着宝石，
宽大的剑鞘上刻着密密麻麻的小字，仔
细看好象都是梵文。\n");
                set("value", 2000);
		set("material", "blacksteel");
                set("wield_msg", "$N拿出一把$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(35);
        setup();
}

void init()
{
	add_action("do_ba","ba");
}

int do_ba(string arg,object who)
{
	object sword,qiao;

	if(!arg || !id(arg) )
		return notify_fail("你要拔什么？\n");

	if( !who || who->query("id") != "youfang lama" )
		return notify_fail("你用尽全身力气猛地一拔，宝剑在剑鞘里却纹丝没动。\n");

	sword = new(__DIR__"jinghong_sword");
	sword->move(who);
	qiao = new(__DIR__"qiao");
	qiao->move(who);

	message_vision("$N双膀一较力，只听“仓啷”一声把剑拔了出来。\n",who);
	call_out("dest",1);
	return 1;
}

private void dest()
{
	destruct(this_object());
}
